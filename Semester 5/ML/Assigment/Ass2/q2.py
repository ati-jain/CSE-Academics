# import all required modules
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.svm import SVC
from sklearn.neural_network import MLPClassifier
from math import sqrt
import warnings
warnings.filterwarnings('ignore')


# load the data set
columns = ['Sex', 'Length', 'Diameter', 'Height', 'Whole weight', 'Shucked weight', 'Viscera Weight', 'Shell weight', 'Rings']
data=pd.read_csv('abalone.data', sep=',', header=None, names=columns)
data_size = len(data) 

output_file = open('q2_output.txt', 'w')

# name of the target attribute
target_attr = 'Rings'



# function that prints on output file
def prnt(a, b=None, c=None):
    output_file.write(str(a))
    if b!=None:
        output_file.write(str(b))
    if c!=None:
        output_file.write(str(c))
    return




# function for encoding categorical variable 'Sex'
def encode():
    #drop categorical column
    li = list(data['Sex'])
    enc_data = data.drop('Sex', axis=1)  
    
    # insert new columns named Sex_encoded
    enc_data['Sex_encoded']=[0]*data_size
    
    # Modify values of the newly inserted columns
    for i in range(data_size):
        if li[i]=='I':
            enc_data.loc[i, 'Sex_encoded']=0
        elif li[i]=='M':
            enc_data.loc[i, 'Sex_encoded']=1
        else:
            enc_data.loc[i, 'Sex_encoded']=2    
    return enc_data

enc_data = encode()                                     # encoded data


X = enc_data.drop(target_attr, axis = 'columns')        # contains the non-target columns data
y = enc_data[target_attr]                               # contains the target column data


# Function to normalize non-target variables
def normalize(data):
    for col in data.columns:
        ar = np.array(data[col])
        mean = ar.mean()
        var = ar.var()
        std_dev = sqrt(var)
        data[col] = data[col]-mean
        data[col] = data[col]/std_dev
    return data
X = normalize(X)


# SAMPLING ( dividing data set into 80% for training and 20% for testing)
all_rows = np.arange(data_size)
training_data_size = (data_size*80)//100        # size of training data set (80%)

np.random.shuffle(all_rows)
training_rows = all_rows[:training_data_size]   # rows used for training the model
testing_rows = all_rows[training_data_size:]    # rows used for testing the model
X_train, X_test = [], []                        # non_target columns data training and testing splits
y_train, y_test = [], []                        # target column data training and testing splits

for i in training_rows:
    X_train.append(X.iloc[i])
    y_train.append(y[i])                


for i in testing_rows:
    X_test.append(X.iloc[i])
    y_test.append(y[i])  

X_train = pd.DataFrame(X_train, columns=X.columns)
X_test = pd.DataFrame(X_test, columns=X.columns)




###  SVM Classifiers  ###
print("\n\n.......[ Trainning and Testing SVM classifiers ].......\n", flush = True)
prnt("##### SVM classifiers #####\n")

# SVM classifier  KERNEL: Linear
model_1 = SVC(kernel='linear')
model_1.fit(X_train, y_train)

print(f"Accuracy for SVM with Linear Kernel = {model_1.score(X_test, y_test)*100}%")
prnt(f"Accuracy for SVM with Linear Kernel = {model_1.score(X_test, y_test)*100}%\n")

# SVM classifier  KERNEL: Quadratic 
model_2 = SVC(kernel='poly', degree=2)
model_2.fit(X_train, y_train)
print(f"Accuracy for SVM with Quadratic Kernel = {model_2.score(X_test, y_test)*100}%")
prnt(f"Accuracy for SVM with Quadratic Kernel = {model_2.score(X_test, y_test)*100}%\n")

# SVM classifier  KERNEL: Radial Basis Function
model_3 = SVC(kernel='rbf')
model_3.fit(X_train, y_train)
print(f"Accuracy for SVM with RBF Kernel = {model_3.score(X_test, y_test)*100}%", flush = True)
prnt(f"Accuracy for SVM with RBF Kernel = {model_3.score(X_test, y_test)*100}%\n\n\n")
print("\n.....[ Done ].....\n\n", flush = True)





###   MLP Classifiers   ###
print(".......[ Trainning and Testing MLP classifiers ].......\n", flush = True)
prnt("##### MLP classifiers #####\n")

mlp_1  = MLPClassifier(solver='sgd', learning_rate='constant', learning_rate_init=0.001, batch_size=32, hidden_layer_sizes=(16))
mlp_2  = MLPClassifier(solver='sgd', learning_rate='constant', learning_rate_init=0.001, batch_size=32, hidden_layer_sizes=(256, 16))

# Train and test MLP-1
mlp_1.fit(X_train, y_train)
mlp_1_accuracy = mlp_1.score(X_test, y_test)*100
print(f"Accuracy for MLP-1 (1 hidden layer with 16 nodes) = {mlp_1_accuracy}%", flush = True)
prnt(f"Accuracy for MLP-1 (1 hidden layer with 16 nodes) = {mlp_1_accuracy}%\n")


# Train and test MLP-2
mlp_2.fit(X_train, y_train)
mlp_2_accuracy = mlp_2.score(X_test, y_test)*100
print(f"Accuracy for MLP-2 (2 hidden layers with 256 and 16 nodes) = {mlp_2_accuracy}%", flush = True)
prnt(f"Accuracy for MLP-2 (2 hidden layers with 256 and 16 nodes) = {mlp_2_accuracy}%\n\n\n")

print("\n.....[ Done ].....\n\n", flush = True)


# Choose the best MLP Classifier
best_mlp = None
if mlp_1_accuracy > mlp_2_accuracy:
    best_mlp = mlp_1
else:
    best_mlp = mlp_2





# Finding Accuracy corresponding to different Learning Rates
print(".......[Calculating Learning Rate vs Accuracy and Plotting the graph].......")
learning_rates = [0.1, 0.01, 0.001, 0.0001, 0.00001]
accuracies=[]
for x in learning_rates:
    best_mlp.learning_rate_init = x
    best_mlp.fit(X_train, y_train)
    accuracies.append(best_mlp.score(X_test, y_test)*100)

# plot of Learning Rate vs Accuracy
plt.title('Learning Rate vs Accuracy')
plt.xlabel('Learning Rate')
plt.ylabel('Accuracy (in %)')

plt.plot(learning_rates, accuracies)
plt.xscale('log')
plt.savefig('Learning_Rate_vs_Accuracy.png')

print("\n.....[ Done ].....\n\n", flush = True)

# Restore best_mlp
best_mlp.learning_rate_init = 0.001
best_mlp.fit(X_train, y_train)




# Function to perform Backward Elimination
def backward_elimination(X_train, X_test, y_train, y_test, count):
    # is only 1 feature left in data return it
    if len(X_train.columns)==1:
        best_mlp.fit(X_train, y_train)
        return X_train.columns, best_mlp.score(X_test, y_test)*100
    
    max_accuracy_after_drop = 0
    feature_to_drop = ""
    
    # find feature which when dropped results in highest accuracy for the model
    for feature in X_train.columns:
        X_train_mod = X_train.drop(feature, axis=1)
        X_test_mod = X_test.drop(feature, axis=1)
        best_mlp.fit(X_train_mod, y_train)
        accuracy = best_mlp.score(X_test_mod, y_test)*100
        
        if accuracy>max_accuracy_after_drop:
            max_accuracy_after_drop = accuracy
            feature_to_drop = feature
    
    best_mlp.fit(X_train, y_train)
    current_accuracy = best_mlp.score(X_test, y_test)*100
    
    # if max accuracy after dropping a column > current accuracy then drop that column
    if max_accuracy_after_drop>current_accuracy:
        X_train = X_train.drop(feature_to_drop, axis=1)
        X_test = X_test.drop(feature_to_drop, axis=1)
        print(f"..........[Removed {count+1} features].........", flush = True)
        return backward_elimination(X_train, X_test, y_train, y_test, count+1)
    else:
        return X_train.columns, current_accuracy
      
# Perform Backward eliminaltion and print best set of features
print(".......[Starting Backward Eliminaltion].......", flush = True)
prnt("##### Backward Eliminaltion  #####\n")
best_features, corresponding_accuracy = backward_elimination(X_train.copy(), X_test.copy(), y_train.copy(), y_test.copy(), 0)

print("Best set of features =",list(best_features), flush = True)
prnt("Best set of features = ", ', '.join(list(best_features)), '\n\n\n')



print("\n.....[ Done ].....\n\n", flush = True)


# Class for Ensemble Learning model using max-voting technique
print(".......[ Trainning and Testing Ensemble  classifier ].......\n", flush = True)
prnt("##### Ensemble classifier  #####\n")
class EnsembleClassifier:
    
    def __init__(self, m1, m2, m3):
        self.model_1 = m1
        self.model_2 = m2
        self.model_3 = m3
        
        
    def predict(self, attr):
        predictions=[]
        predictions.append(model_1.predict([attr])[0])
        predictions.append(model_2.predict([attr])[0])
        predictions.append(model_3.predict([attr])[0])
        
        
        # predict the value with maximum votes
        
        if predictions.count(predictions[0])>=2: # As there are 3 predictions, count >=2 implies it has max votes
            return predictions[0]
        elif predictions.count(predictions[1])>=2:
            return predictions[1]
        elif predictions.count(predictions[2])>=2:
            return predictions[2]
        else:                                    # is there are 3 unique predictions then return the median
            predictions.sort()
            return predictions[1]

    def accuracy(self, X_test, y_test):
    
        test_size = len(X_test)
        misclassifications = 0
        
        for i in range(test_size):
            if y_test[i] != self.predict(X_test.iloc[i]):
                misclassifications += 1
        
        accuracy = (1- (misclassifications/test_size))*100
        
        return accuracy

# create an object of the Ensemble Learning class and print its accuracy
# model_2 = SVM with quadratic kernel,      model_3 = SVM with rbf kernel,      best_mlp = best model from part 3
ensmModel = EnsembleClassifier(model_2, model_3, best_mlp) 
print(f"Accuracy of Ensemble Classifier = {ensmModel.accuracy(X_test, y_test)}%", flush = True)
prnt(f"Accuracy of Ensemble Classifier = {ensmModel.accuracy(X_test, y_test)}%\n")
print("\n.....[ Done ].....\n\n", flush = True)

output_file.close()