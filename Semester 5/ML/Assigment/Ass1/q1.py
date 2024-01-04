import numpy as np
import pandas as pd

data = pd.read_csv('Train_D_Tree.csv')

output_file = open('Q1_output.txt', 'w')

# name of the target attribute
target_attr = 'Price'

def prnt(a, b=None, c=None):
    output_file.write(str(a))
    if b!=None:
        output_file.write(str(b))
    if c!=None:
        output_file.write(str(c))
    return

class Node:
    def __init__(self, val=None):
        self.left=None
        self.right=None
        self.attr=""
        self.partitionVal=0
        self.result=val

# checks if an attribute is numeric
def is_numeric(attr):
    val = data[attr][0]
    val = str(val)
    for ch in val:
        if ch>'9' or ch<'0':
            return False
    return True

# returns average value of target attribute for all row in rows
def average(rows):
    if len(rows)==0:
        return 0
    arr = []
    for row in rows:
        arr.append(data[target_attr][row])
    
    npar = np.array(arr)
    avg = npar.mean()
    return avg

# returns sum of squared error of all elements in arr
def sum_of_squared_error(arr):         
    if len(arr)==0:
        return 0
    avg = arr.mean()
    err_list = arr - avg
    squared_err_list = np.square(err_list)
    sum_of_squared_err = sum(squared_err_list)
    return sum_of_squared_err

# partitions the set of rows according to a certain attribute
def partition(rows, attr, partition_val=None):
    left=[]
    right=[]

    if is_numeric(attr):
        for row in rows:
            if data[attr][row]<partition_val:
                left.append(row)
            else:
                right.append(row)
    else:
        for row in rows:
            if data[attr][row]=='yes':
                left.append(row)
            else:
                right.append(row)
    return left, right

def error_numeric(rows, attr):
    li = []
    for row in rows:
        li.append(data[attr][row])
    li.sort()
    n = len(li)
    
    partition_val=li[0]
    min_error=10**17  # used as infinity
    
    for i in range(n-1):
        val=(li[i]+li[i+1])/2
        left=[]
        right=[]
        
        for row in rows:
            if data[attr][row]<val:
                left.append(data[target_attr][row])
            else:
                right.append(data[target_attr][row])
                
        curr_error = sum_of_squared_error(np.array(left))+sum_of_squared_error(np.array(right))
        
        if curr_error<min_error:
            min_error=curr_error
            partition_val=val

    return min_error, partition_val

def error_boolean(rows, attr):
    left=[]
    right=[]
    for row in rows:
        if data[attr][row]=='yes':
            left.append(data[target_attr][row])
        else:
            right.append(data[target_attr][row])
    err = sum_of_squared_error(np.array(left))+sum_of_squared_error(np.array(right))
    return err, None

def best_attribute(rows, attributes):
    min_error = 10**18    # used as infinity
    best_attr = None
    partition_val=None
    
    for attr in attributes:
        if is_numeric(attr):
            err, val = error_numeric(rows, attr)
        else:
            err, val = error_boolean(rows, attr)  
            
        if(err<min_error):
            min_error = err
            best_attr = attr
            partition_val=val
    return best_attr, partition_val
    



def build_tree(rows, attributes):

    if len(attributes)==0:
        return Node(average(rows))
    root = Node()
    root.attr, root.partitionVal=best_attribute(rows, attributes) # partitionVal is None for boolen attributes
    
    if(is_numeric(root.attr)):
        # if all values of the root.attr in the current rows are equal then remove root.attr from attributes

        left_rows, right_rows = partition(rows, root.attr, root.partitionVal)
        if len(left_rows)==0 or len(right_rows)==0:
            attributes.remove(root.attr)
    else:
        left_rows, right_rows = partition(rows, root.attr)
        attributes.remove(root.attr)
        
    if len(left_rows)>0:
        root.left = build_tree(left_rows, attributes.copy())
    else:
        root.left=Node(average(rows))
        
    if len(right_rows)>0:
        root.right = build_tree(right_rows, attributes.copy())
    else:
        root.right=Node(average(rows))
    
    return root


def predicted_value(root, instance):
    if root.left == None or root.right == None:
        return root.result
    if is_numeric(root.attr):
        if instance[root.attr]<root.partitionVal:
            return predicted_value(root.left, instance)
        else:
            return predicted_value(root.right, instance)
    else:
        if instance[root.attr]=='yes':
            return predicted_value(root.left, instance)
        else:
            return predicted_value(root.right, instance)


# returns the mean squared error in predicted values
def mean_squared_error(root, test_rows): 
    
    total_squared_error=0
    n = len(test_rows)
    
    if n==0:
        return 0
    
    predicted_values = np.zeros(n)
    actual_values = np.zeros(n)
    

    for i in range(n):
        instance = data.iloc[test_rows[i]]
        predicted_values[i] = predicted_value(root, instance)
        actual_values[i] = instance[target_attr]
 
        
    errors = actual_values - predicted_values
    
    squared_errors=np.square(errors)
        
    Mean_squared_error = sum(squared_errors)/n
    
    return Mean_squared_error
 

# finds depth of a tree
def depth(root):
    if root==None:
        return -1
    return 1+max(depth(root.left), depth(root.right))

data_size = len(data)
all_rows = np.arange(data_size)
training_data_size = (data_size*70)//100        # size of training data set (70%)

attributes = list(data.columns)
attributes.remove(target_attr)
attributes.remove('Restaurant')        # target_attr and Restaurant are not part of testing attributes

best_root=None
test_rows=np.array([])
train_rows=np.array([])
min_err=10**18

for i in range(10):    # Testing for 10 random splits
    np.random.shuffle(all_rows)
    training_rows = all_rows[:training_data_size]   # rows used for training the model
    testing_rows = all_rows[training_data_size:]    # rows used for testing the model
    
    root = build_tree(training_rows, attributes)
    
    err = mean_squared_error(root, testing_rows)
    if err<min_err:
        best_root = root
        min_err = err
        test_rows = testing_rows.copy()
        train_rows = training_rows.copy()

depth_best = depth(best_root)
prnt(f'Best achievable test error = {round(min_err,4)}\n')
prnt(f'Depth corresponding to this error = {depth_best}\n')
error_at_depth =[-1]*(depth_best+1)
error_at_depth[depth_best]=min_err

def prune(root, rows):
    if root.left == root.right == None:
        return

    
    Left = root.left
    Right = root.right
    

    
    root.left = root.right = None
    root.result = average(rows)
    pruned_error = mean_squared_error(best_root, test_rows)

    
    root.left = Left
    root.right = Right
    actual_error = mean_squared_error(best_root, test_rows)
    

    
    if pruned_error <= actual_error:
        root.left = root.right = None
        d = depth(best_root)
        if d!=depth_best:
            error_at_depth[d]=pruned_error
    else:
        if is_numeric(root.attr):
            left_rows, right_rows = partition(rows, root.attr, root.partitionVal)
        else:
            left_rows, right_rows = partition(rows, root.attr)

        prune(root.left, left_rows)
        prune(root.right, right_rows)
    return

prune(best_root, train_rows)

new_depth=depth(best_root)

prnt('\n\n\n')
prnt('Variation in error with depth while pruning:-\n')
prnt('DEPTH        ERROR\n')
overfitting_depths=[]
for d in range(depth_best, 0, -1):
    if error_at_depth[d]>=0:
        prnt(f'  {d}          {round(error_at_depth[d],4)}\n')
        if d!=new_depth:
            overfitting_depths.append(str(d))

prnt('\n\n\n')
if len(overfitting_depths)>0:
    prnt('The depths for which the model overfits are: ', ' '.join(overfitting_depths), '\n')
else:
    prnt('The model doesn\'t overfits for any depth', '\n')

prnt('\n\n\n')
prnt('The pruned tree looks like:-')
from queue import Queue
def print_tree():
    q = Queue()
    q.put((best_root, 0))
    prev=-1
    while not q.empty():
        root, lvl = q.get()
        if lvl>prev:
            prev=lvl
            prnt('\n')
            prnt(f'Level {lvl}:-    ')
        
        if root.left==root.right==None:
            prnt(f'Leaf Node,Result={round(root.result,3)}','    ')
        else:
            if is_numeric(root.attr):
                prnt(f'{root.attr.strip()}<{root.partitionVal}?','    ')
            else:
                prnt(f'{root.attr.strip()}?','    ')
            q.put((root.left, lvl+1))
            q.put((root.right, lvl+1))
    return
print_tree()
        
def plot_tree(space, root):
    if root.left==root.right==None:
        prnt(space+target_attr+' = ',root.result,'\n')
        return
    
    if is_numeric(root.attr):
        prnt(space,f'if{root.attr}<{root.partitionVal}\n')
    else:
        prnt(space,f'if {root.attr} == True\n')
    
    plot_tree(space+'   ',root.left)
    
    prnt(space,'else\n')
    
    plot_tree(space+'   ',root.right)
    
    return       

prnt('\n\n\n')
prnt('Representation of the pruned tree in If-Else form:-\n')
plot_tree('  ', best_root)

output_file.close()
