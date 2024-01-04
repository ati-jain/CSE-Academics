import csv
import numpy as np

output_file = open('Q2_output_5_fold.txt', 'w')


def prnt(a, b=None, c=None):
    output_file.write(str(a))
    if b != None:
        output_file.write(str(b))
    if c != None:
        output_file.write(str(c))
    return


def p(test):
    Y = test[12]
    X = test[0:12]
    py = []
    for y in range(2):
        prob = pi[y]
        for i in range(len(X)):
            mean = theta[i][y][0]
            var = theta[i][y][1]
            prob = prob * np.exp(-0.5*(((X[i] - mean) / var) ** 2))
            prob = prob / (((2 * np.pi) ** 0.5) * var)
        py.append(prob)
    if (py[0] > py[1] and Y == 1):
        return 1
    elif (py[0] < py[1] and Y == 0):
        return 1
    else:
        return 0


def read(Address):
    data = []
    with open(Address) as f:
        reader = csv.reader(f)
        first = 1
        for row in reader:
            if (first):
                names = row
            else:
                data.append(row)
            first = 0
    names = np.asarray(names)
    for i in range(len(data)):
        data[i][12] = 0 if data[i][12] == 'Abnormal' else 1
    data = np.asarray(data, dtype=np.float32)
    np.random.shuffle(data)
    return names, data


cols, data = read("Train_D_Bayesian.csv")

size = len(data)
k_size = (int)(size / 5)
for i in range(5):
    prnt("Fold ", i, ":\n")
    training_data = np.concatenate(
        (data[: i*k_size], data[(i+1)*k_size: size]), axis=0)
    testing_data = data[i*k_size:(i+1)*k_size]
    values = []

    prnt("Size of training data-set: ")
    prnt(len(training_data), "\n\n")

    col_mean = np.mean(training_data, axis=0)
    col_var = np.var(training_data, axis=0)

    col_mean = col_mean[:-1]
    col_var = col_var[:-1]

    new_train_data = []
    for row in training_data:
        truth_val = row[:-1] < 2*col_mean + 5*col_var
        if truth_val.sum() == 12:
            new_train_data.append(row)
    training_data = np.array(new_train_data)  # training data without outliers

    prnt("Size of the new training data-set without outliers: ")
    prnt(len(training_data), "\n\n")

    for row in training_data:
        values.append(row[12])

    values = np.unique(values)
    counts = []
    for val in values:
        counts.append(np.count_nonzero(training_data[:, 12] == val))

    counts = np.asarray(counts)

    pi = [count / size for count in counts]

    training = [[], []]

    for train in training_data:
        if (train[12] == 0):
            training[0].append(train)
        else:
            training[1].append(train)

    training = np.asarray(training, dtype=object)
    training[0] = np.asarray(training[0])
    training[1] = np.asarray(training[1])

    theta = []

    for i in range(len(cols) - 1):
        tmp = []
        for v in range(2):
            tmp.append([np.mean(training[v][:, i]),
                        (np.var(training[v][:, i]))*(size-1)/size])  # laplace smoothing by changing the variance
        theta.append(tmp)

    theta = np.asarray(theta)

    prnt("Size of the testing data-set: ")
    prnt(len(testing_data), "\n\n")

    acc = 0
    for t in testing_data:
        acc += p(t)

    n = len(testing_data)

    prnt("Accuracy of the model: ", "")
    prnt(100 * acc / n, "")
    prnt("%", "\n\n\n\n")
