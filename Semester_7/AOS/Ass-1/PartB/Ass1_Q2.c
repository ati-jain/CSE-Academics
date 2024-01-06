/*
Advances in Operating Systems
Assignment 1
Group Members:
Atishay Jain - 20CS30008
Gaurav Malakar - 20CS10029
*/

#include <linux/errno.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/mutex.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Atishay Jain and Gaurav Malakar");
MODULE_DESCRIPTION("Loadable kernel module implementing dequeue");
MODULE_VERSION("0.1");

#define PROCFS_NAME "partb_1_20CS30008_20CS10029"
#define PROCFS_MAX_SIZE 1024

struct element
{
    int val;
    int insertTime;
    struct element *next;
};

struct deque
{
    struct element *first, *last;
    int size;
    int capacity;
    int timer;
};

// Linked list of processes
struct processNode
{
    pid_t pid;
    struct deque *procDq;
    struct processNode *next;
};

// Global variables
static struct proc_dir_entry *procFile;
static char procfBuf[PROCFS_MAX_SIZE];
static size_t procfBufSize = 0;
static struct processNode *procList = NULL;

DEFINE_MUTEX(mutex);

// Create the Dequeue
static struct deque *createDq(int capacity)
{
    struct deque *dq = kmalloc(sizeof(struct deque), GFP_KERNEL);
    if (dq == NULL)
    {
        printk(KERN_ALERT "Error: could not allocate memory for dequeue\n");
        return NULL;
    }
    dq->first = NULL;
    dq->last = NULL;
    dq->size = 0;
    dq->capacity = capacity;
    dq->timer = 0;
    return dq;
}

// Insert element into dequeue
static int insertDq(struct deque *dq, int val)
{
    struct element *newE = kmalloc(sizeof(struct element), GFP_KERNEL);
    if (dq->size == dq->capacity)
    {
        printk(KERN_ALERT "Error: dequeue is full\n");
        kfree(newE);
        return -EACCES;
    }
    if (newE == NULL)
    {
        return -ENOMEM;
    }
    newE->val = val;
    newE->next = NULL;
    newE->insertTime = dq->timer;
    if (val % 2) // odd no.; insert to left
    {
        newE->next = dq->first;
        dq->first = newE;
        if (dq->last == NULL)
            dq->last = newE;
    }
    else // even no.; insert to right
    {
        if (dq->last == NULL)
        {
            dq->first = newE;
            dq->last = newE;
        }
        else
        {
            dq->last->next = newE;
            dq->last = newE;
        }
    }
    dq->timer++;
    dq->size++;
    return 0;
}

// Extract leftmost elemnt from dequeue
static int extractDq(struct deque *dq)
{
    int retVal = dq->first->val;
    if (dq->size == 0)
    {
        printk(KERN_ALERT "Error: dequeue is empty\n");
        return -EACCES;
    }
    if (dq->first == dq->last)
    {
        kfree(dq->first);
        dq->first = NULL;
        dq->last = NULL;
    }
    else
    {
        struct element *t = dq->first;
        dq->first = dq->first->next;
        kfree(t);
    }
    dq->size--;
    return retVal;
}

// Print dequeue
static void printDq(struct deque *dq)
{
#ifdef DEBUG
    printk(KERN_INFO "Dequeue for process %d:\n", current->pid);
    printk(KERN_INFO "Size: %d\n", dq->size);
    printk(KERN_INFO "Capacity: %d\n", dq->capacity);
    struct element *t = dq->first;
    while (t != NULL)
    {
        printk(KERN_INFO "Value: %d, Insert-Time: %d", t->val, t->insertTime);
        t = t->next;
    }
#endif
    return;
}

// Free the memory allocated to the dequeue
static void deleteDq(struct deque *dq)
{
    if (dq != NULL)
    {
        struct element *t = dq->first;
        while (t != NULL)
        {
            struct element *temp = t;
            t = t->next;
            kfree(temp);
        }
        kfree(dq);
    }
    return;
}

// Find the process node with the given pid
static struct processNode *findProc(pid_t pid)
{
    struct processNode *curr = procList;
    while (curr != NULL)
    {
        if (curr->pid == pid)
        {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

// Insert a process node with the given pid
static struct processNode *insertPorc(pid_t pid)
{
    struct processNode *node = kmalloc(sizeof(struct processNode), GFP_KERNEL);
    if (node == NULL)
    {
        return NULL;
    }
    node->pid = pid;
    node->procDq = NULL;
    node->next = procList;
    procList = node;
    return node;
}

// Free the memory allocated to a process node
static void delProcNode(struct processNode *node)
{
    if (node != NULL)
    {
        deleteDq(node->procDq);
        kfree(node);
    }
}

// Delete a process node with the given pid
static int delProc(pid_t pid)
{
    struct processNode *prev = NULL;
    struct processNode *curr = procList;
    while (curr != NULL)
    {
        if (curr->pid == pid)
        {
            if (prev == NULL)
            {
                procList = curr->next;
            }
            else
            {
                prev->next = curr->next;
            }
            delProcNode(curr);
            return 0;
        }
        prev = curr;
        curr = curr->next;
    }
    return -EACCES;
}

// Free the memory allocated to all process nodes
static void delProcList(void)
{
    struct processNode *curr = procList;
    while (curr != NULL)
    {
        struct processNode *temp = curr;
        curr = curr->next;
        delProcNode(temp);
    }
}

// Open handler function for proc file
static int procFileOpen(struct inode *inode, struct file *file)
{
    pid_t pid;
    int ret;
    struct processNode *curr;

    mutex_lock(&mutex);

    pid = current->pid;
    printk(KERN_INFO "procFileOpen() invoked by process %d\n", pid);
    ret = 0;

    curr = findProc(pid);
    if (curr == NULL)
    {
        curr = insertPorc(pid);
        if (curr == NULL)
        {
            printk(KERN_ALERT "Error: could not allocate memory for process node\n");
            ret = -ENOMEM;
        }
        else
        {
            printk(KERN_INFO "Process %d has been added to the process list\n", pid);
        }
    }
    else
    {
        printk(KERN_ALERT "Error: process %d has the proc file already open\n", pid);
        ret = -EACCES;
    }

    mutex_unlock(&mutex);
    return ret;
}

// Close handler for proc file
static int procFileClose(struct inode *inode, struct file *file)
{
    pid_t pid;
    int ret;
    struct processNode *curr;

    mutex_lock(&mutex);

    pid = current->pid;
    printk(KERN_INFO "procFileClose() invoked by process %d\n", pid);
    ret = 0;

    curr = findProc(pid);
    if (curr == NULL)
    {
        printk(KERN_ALERT "Error: process %d does not have the proc file open\n", pid);
        ret = -EACCES;
    }
    else
    {
        delProc(pid);
        printk(KERN_INFO "Process %d has been removed from the process list\n", pid);
    }

    mutex_unlock(&mutex);
    return ret;
}

// Helper function to handle reads
static ssize_t handleRead(struct processNode *curr)
{
    int retVal;
    if (curr->procDq == NULL)
    {
        printk(KERN_ALERT "Error: process %d has not yet written anything to the proc file\n", curr->pid);
        return -EACCES;
    }
    if (curr->procDq->size == 0)
    {
        printk(KERN_ALERT "Error: dequeue is empty\n");
        return -EACCES;
    }
    retVal = extractDq(curr->procDq);
    memcpy(procfBuf, (const char *)&retVal, sizeof(int));
    printk(KERN_INFO "Value %d has been read from the proc file for process %d\n", retVal, curr->pid);
    procfBufSize = sizeof(int);
    return procfBufSize;
}

// Read handler for proc file
static ssize_t procFileRead(struct file *filep, char __user *buffer, size_t length, loff_t *offset)
{
    pid_t pid;
    int ret;
    struct processNode *curr;

    mutex_lock(&mutex);

    pid = current->pid;
    printk(KERN_INFO "procFileRead() invoked by process %d\n", pid);
    ret = 0;

    curr = findProc(pid);
    if (curr == NULL)
    {
        printk(KERN_ALERT "Error: process %d does not have the proc file open\n", pid);
        ret = -EACCES;
    }
    else
    {
        procfBufSize = min(length, (size_t)PROCFS_MAX_SIZE);
        ret = handleRead(curr);
        if (ret >= 0)
        {
            if (copy_to_user(buffer, procfBuf, procfBufSize))
            {
                printk(KERN_ALERT "Error: could not copy data to user space\n");
                ret = -EACCES;
            }
            else
            {
                ret = procfBufSize;
            }
        }
        printDq(curr->procDq);
    }
    mutex_unlock(&mutex);
    return ret;
}

// Helper function to handle writes
static ssize_t handleWrite(struct processNode *curr)
{
    size_t capacity;
    int value, ret;

    if (curr->procDq == NULL)
    {
        if (procfBufSize > 1) // 1 byte
        {
            printk(KERN_ALERT "Error: Buffer size for capacity must be 1 byte\n");
            return -EINVAL;
        }
        capacity = (size_t)procfBuf[0];
        if (capacity < 1 || capacity > 100)
        {
            printk(KERN_ALERT "Error: Capacity must be between 1 and 100\n");
            return -EINVAL;
        }
        curr->procDq = createDq(capacity);
        if (curr->procDq == NULL)
        {
            printk(KERN_ALERT "Error: dequeue initialization failed\n");
            return -ENOMEM;
        }
        printk(KERN_INFO "Dequeue with capacity %zu has been intialized for process %d\n", capacity, curr->pid);
    }
    else
    {
        if (procfBufSize != sizeof(int)) // sizeof(int)
        {
            printk(KERN_ALERT "Error: Buffer size for value must be <= 4 bytes\n");
            return -EINVAL;
        }
        if (curr->procDq->size == curr->procDq->capacity)
        {
            printk(KERN_ALERT "Error: dequeue is full\n");
            return -EACCES;
        }
        value = *((int *)procfBuf);
        printk(KERN_INFO "Value %d has been written to the proc file for process %d\n", value, curr->pid);
        ret = insertDq(curr->procDq, value);
        if (ret < 0)
        {
            printk(KERN_ALERT "Error: Failed to insert new element in the dequeue\n");
            return -EACCES;
        }
        printk(KERN_INFO "%d value element has been inserted into the dequeue for process %d\n", value, curr->pid);
    }
    return procfBufSize;
}

// Write handler for proc file
static ssize_t procFileWrite(struct file *filep, const char __user *buffer, size_t length, loff_t *offset)
{
    pid_t pid;
    int ret;
    struct processNode *curr;

    mutex_lock(&mutex);

    pid = current->pid;
    printk(KERN_INFO "procFileWrite() invoked by process %d\n", pid);
    ret = 0;

    curr = findProc(pid);
    if (curr == NULL)
    {
        printk(KERN_ALERT "Error: process %d does not have the proc file open\n", pid);
        ret = -EACCES;
    }
    else
    {
        if (buffer == NULL || length == 0)
        {
            printk(KERN_ALERT "Error: empty write\n");
            ret = -EINVAL;
        }
        else
        {
            procfBufSize = min(length, (size_t)PROCFS_MAX_SIZE);
            if (copy_from_user(procfBuf, buffer, procfBufSize))
            {
                printk(KERN_ALERT "Error: could not copy from user\n");
                ret = -EFAULT;
            }
            else
            {
                ret = handleWrite(curr);
            }
        }
        printDq(curr->procDq);
    }
    mutex_unlock(&mutex);
    return ret;
}

static const struct proc_ops proc_fops = {
    .proc_open = procFileOpen,
    .proc_read = procFileRead,
    .proc_write = procFileWrite,
    .proc_release = procFileClose,
};

// Module initialization
static int __init m_init(void)
{
    printk(KERN_INFO "LKM for %s loaded\n", PROCFS_NAME);

    procFile = proc_create(PROCFS_NAME, 0666, NULL, &proc_fops);
    if (procFile == NULL)
    {
        printk(KERN_ALERT "Error: could not create proc file\n");
        return -ENOENT;
    }
    printk(KERN_INFO "/proc/%s created\n", PROCFS_NAME);
    return 0;
}

// Module cleanup
static void __exit m_exit(void)
{
    delProcList();
    remove_proc_entry(PROCFS_NAME, NULL);
    printk(KERN_INFO "/proc/%s removed\n", PROCFS_NAME);
    printk(KERN_INFO "LKM for partb_1_3 unloaded\n");
}

module_init(m_init);
module_exit(m_exit);
