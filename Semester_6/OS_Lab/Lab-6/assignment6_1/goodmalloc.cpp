#include "goodmalloc.h"

stack<set<Element *>> occupancy;

struct Element *my_memory;
int memeory_length;
int page_count;
int max_page = 0;

set<Element *> free_pages;

void createMem(int size)
{ // size in bytes
    int length = size / sizeof(Element);
    memeory_length = length;
    page_count = (length + PAGE_SIZE - 1) / PAGE_SIZE;
    my_memory = (Element *)malloc(page_count * PAGE_SIZE * sizeof(Element));
    for (int i = 0; i < page_count; i++)
        free_pages.insert(my_memory + i * PAGE_SIZE);
}

Element *createList(int length, Element *&listName)
{
    // cout << "create" << endl;
    if (length <= 0 || free_pages.empty())
    {
        listName = nullptr;
        return nullptr;
    }
    int notAval = 0;
    Element *head, *lastPage = my_memory + (page_count - 1) * PAGE_SIZE;

    if (*free_pages.rbegin() == lastPage) // if the last page is free
        notAval = PAGE_SIZE - memeory_length % PAGE_SIZE;

    if (PAGE_SIZE * free_pages.size() - notAval < length)
    {
        listName = nullptr;
        return nullptr;
    }

    head = *free_pages.begin(); // for returning the pointer
    Element *prev = nullptr, *curr;
    while (length)
    {
        curr = *free_pages.begin();
        free_pages.erase(free_pages.begin());
        for (int i = 0; i < min(PAGE_SIZE, length); i++)
        {
            curr->prev = prev;
            if (prev)
                prev->next = curr;
            prev = curr;
            curr = curr + 1;
        }
        length -= min(PAGE_SIZE, length);
    }
    listName = head;
    occupancy.top().insert(head);
    max_page = max(max_page, page_count - (int)(free_pages.size()));
    return head;
}

int assignVal(Element *listName, int offset, int value)
{
    // cout << "assign" << endl;
    Element *elem = accessElem(listName, offset);
    if (elem == nullptr)
        return -1;
    elem->value = value;
    return 1;
}

Element *accessElem(Element *listName, int offset)
{
    // cout << "access" << endl;
    int diff = (listName - my_memory) % PAGE_SIZE;
    listName -= diff;
    offset += diff;

    if (offset == 0)
        return listName;

    while (offset >= PAGE_SIZE)
    {
        listName = (listName + PAGE_SIZE - 1)->next;
        if (listName == nullptr)
        {
            cerr << "Segmentation Fault: index out of bound" << endl;
            exit(1);
        }
        offset -= PAGE_SIZE;
    }

    listName += offset;
    if (listName->prev == NULL)
    {
        cerr << "Segmentation Fault: index out of bound" << endl;
        exit(1);
    }
    return listName;
}

void freeElem(Element *listName)
{
    // cout << "free" << endl;
    set<Element *> s;
    if (listName == nullptr && !occupancy.empty())
        s = occupancy.top();
    else
    {
        s.insert(listName);
        occupancy.top().erase(listName);
    }
    while (!s.empty())
    {
        Element *head = *s.begin();
        s.erase(s.begin());
        Element *curr = head, *next;
        int size = 0;
        while (curr)
        {
            next = curr->next;
            curr->next = nullptr;
            curr->prev = nullptr;
            curr = next;
            size++;
            if (size == PAGE_SIZE)
            {
                free_pages.insert(head);
                head = curr;
                size = 0;
            }
        }
        if (size)
            free_pages.insert(head);
    }
    if (listName == nullptr && !occupancy.empty())
        occupancy.pop();
}

void funcinit()
{
    set<Element *> s;
    occupancy.push(s);
}