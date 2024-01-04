import numpy as np
import pandas as pd
# from tqdm import tqdm
from PIL import Image

from rtree import index

# load the data
points = np.load("Data/features.npy")
insert_count = min(1000, len(points))
dim = points.shape[2]  ##
print(f"Dimension: {dim}")

img_files = pd.read_csv("Data/mapping.csv")

# Create the rtree index for dim-dimensional data
idx = index.Index(properties=index.Property(dimension=dim))

# Insert some points into the index
for i in range(insert_count):
    idx.insert(i, tuple(points[i][0]))

# Find the M nearest point to a given point
M = 4
while True:
    query_indx = int(input("Enter a index: "))
    if query_indx == -1:
        print("Bye!")
        break
    query_point = points[query_indx][0]
    nearest = list(idx.nearest(tuple(query_point), M))

    img_name = img_files.iloc[query_indx]["filename"]
    print("Query image: ", img_name)
    Image.open("./Data/Images/" + img_name).show()

    for i in range(M):
        print(f"Match-{i+1}:     ", img_name)
        img_name = img_files.iloc[nearest[i]]["filename"]
        Image.open("./Data/Images/" + img_name).show()

    print("\n")