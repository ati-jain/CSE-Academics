import numpy as np
import csv
from sklearn.decomposition import PCA
import matplotlib.pyplot as plt

output_file = open('q1_output.txt', 'w')


def printFile(a, b=None, c='\n\n'):
    output_file.write(str(a))
    if b != None:
        output_file.write(str(b))
    if c != None:
        output_file.write(str(c))
    return


def normalise(M):
    # Normalise the data
    mu = np.mean(M, axis=0)
    sigma = np.std(M, axis=0)
    return (M - mu) / sigma


def distances(point, centroids):
    # caluclate distance from all centroids
    return np.sqrt(np.sum((point - centroids)**2, axis=1))


def kMeans(dataset, nClusters):
    # find the clusters
    centroids = dataset[np.random.choice(
        dataset.shape[0], 2, replace=False), :]
    iteration = 0
    prev_centroids = None
    while np.not_equal(centroids, prev_centroids).any() and iteration < 300:
        # Sort each data point, assigning to nearest centroid
        sorted_points = [[] for t in range(nClusters)]
        for x in dataset:
            dists = distances(x, centroids)
            centroid_idx = np.argmin(dists)
            sorted_points[centroid_idx].append(x)
        prev_centroids = centroids
        for i in range(nClusters):
            # Catch any np.nans, resulting from a centroid having no points
            if (len(sorted_points[i]) > 0):
                centroids[i] = np.mean(sorted_points[i], axis=0)
        iteration += 1

    rcentroid_idxs = []
    for x in dataset:
        dists = distances(x, centroids)
        centroid_idx = np.argmin(dists)
        rcentroid_idxs.append(centroid_idx)
    # returning the ids of clusters
    return rcentroid_idxs


def normalizedMutualInfo(x, y):
    # find the normalised mutual information score
    x = np.asarray(x, dtype=np.int64)
    y = np.asarray(y, dtype=np.int64)
    x_value_list = np.unique(x)
    y_value_list = np.unique(y)
    # calculate probability for each x
    Px = np.array([len(x[x == xval])/float(len(x))
                  for xval in x_value_list])  # P(x)
    # calculate probability for each y
    Py = np.array([len(y[y == yval])/float(len(y))
                  for yval in y_value_list])  # P(y)
    Hx = -sum(Px * np.log2(Px))
    Hy = -sum(Py * np.log2(Py))
    PXY = 0.0
    for i in range(len(x_value_list)):
        sy = y[x == x_value_list[i]]
        Pxy = np.array([len(sy[sy == yval])/float(len(y))
                       for yval in y_value_list])  # p(x,y)
        t = Pxy[Py > 0.]/(Py[Py > 0.] * Px[i])  # log(P(x,y)/(P(x)*P(y))
        # sum (P(x,y)* log(P(x,y)/(P(x)*P(y)))
        PXY += sum(Pxy[t > 0]*np.log2(t[t > 0]))
    return (2 * PXY) / (Hx + Hy)


if __name__ == "__main__":
    # reading the csv file
    info = csv.reader('abalone.data')
    data = []
    with open('abalone.data') as file:
        info = csv.reader(file)
        for row in info:
            # converting {M, F, I} to integer
            if row[0] == 'M':
                row[0] = 0
            elif row[0] == 'F':
                row[0] = 1
            else:
                row[0] = 2
            data.append(row)
    # data = ndarray of type float
    data = np.asarray(data, dtype=np.float32)
    # all but last columns are the attriutes
    X = data[:, 0:-1]
    # last column is the value to be clustered
    y = data[:, -1]
    # nSamples = no. of rows in the dataset
    nSamples = y.shape[0]
    nAttr = X.shape[1]
    printFile("Size of dataset =", nSamples)
    printFile("No. of attributes =", nAttr)

    # poltting the Scree Graph
    # pca = PCA()
    # # P is the projected matrix
    # Nrm = normalise(X)
    # P = pca.fit_transform(Nrm)
    # # plot the graph
    # varRatio = pca.explained_variance_ratio_
    # print(varRatio)
    # plt.bar(range(1, nAttr + 1), varRatio,
    #         alpha=0.5,
    #         align='center')
    # plt.plot(range(1, nAttr + 1), varRatio, marker='o', color='red')
    # plt.title("Scree Plot")
    # plt.ylabel('Explained variance ratio')
    # plt.xlabel('Principal Components')
    # plt.savefig("Scree Plot")
    # plt.show()

    # applying the Principal Components Analysis such that the variance is >= 0.95
    pca = PCA(n_components=0.95, svd_solver='full')
    # P is the projected matrix
    Nrm = normalise(X)
    P = pca.fit_transform(Nrm)
    printFile(
        "Share in variance by each of the selected Principal Component axes is : ", "", "")
    printFile(pca.explained_variance_ratio_)

    nPCs = P.shape[1]
    printFile(
        "We need atleast {} principal components to preserve the variance by 95%".format(nPCs))

    # plot the graph
    fig = plt.figure()
    if (nPCs == 1):
        ax = plt.axes()
        ax.scatter(P[:, 0],  c=y)
        ax.set_xlabel('PC1')
    elif (nPCs == 2):
        ax = plt.axes()
        ax.scatter(P[:, 0], P[:, 1], c=y)
        ax.set_xlabel('PC1')
        ax.set_ylabel('PC2')
    elif (nPCs == 3):
        ax = plt.axes(projection='3d')
        ax.scatter(P[:, 0], P[:, 1], P[:, 2], c=y)
        ax.set_xlabel('PC1')
        ax.set_ylabel('PC2')
        ax.set_zlabel('PC3')
    else:
        printFile("{} PCs can not plotted".format(nPCs))

    ax.set_title('Principal Component Analysis of Abalone dataset')
    plt.savefig("PCA Plot")
    plt.show()

    nmis = []
    # calculating the normalised mutual information score for k clusters
    printFile("Applying K-means clustering with random initial centroids")
    for i in range(2, 9):
        nmis.append(normalizedMutualInfo(kMeans(X, i), y))

    maxK = nmis.index(max(nmis)) + 2
    printFile("No. of clusters for which Normalised Mutual Inforamtion(NMI) is maximum = ",
              maxK)

    # plot the graph of K vs NMI
    plt.title("K vs NMI")
    plt.xlabel("K")
    plt.ylabel("NMI")
    plt.plot(range(2, 9), nmis, "ob")
    plt.plot([maxK], [nmis[maxK - 2]], marker=".", markersize=30, color='red')
    plt.savefig("K vs MNI")
    plt.show()

    print("See q1_output.txt")

output_file.close()
