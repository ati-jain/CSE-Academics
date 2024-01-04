from rtree import index
from PIL import Image
import numpy as np
from scipy.spatial.distance import cdist
import torchvision.transforms as transforms
import torch

# Define the R-tree index
p = index.Property()
p.dimension = 2  # 2-dimensional points
p.variant = index.RT_Star  # Use the R*-tree variant

# Create an R-tree index
idx = index.Index(properties=p)

# Load images and insert their bounding boxes into the R-tree index
image_list = ['image1.jpg', 'image2.jpg', 'image3.jpg']  # List of image filenames

for i, image_file in enumerate(image_list):
    # Load the image
    image = Image.open(image_file)
    width, height = image.size

    # Insert the bounding box into the R-tree index
    bbox = (0, 0, width, height)  # Assume the entire image as the bounding box
    idx.insert(i, bbox)

# Choose a query image from the dataset
query_image_index = 1  # Example query image index

# Load and preprocess the query image
query_image_file = image_list[query_image_index]
query_image = Image.open(query_image_file)
query_image = query_image.convert('RGB')
transform = transforms.Compose([
    transforms.Resize(256),
    transforms.CenterCrop(224),
    transforms.ToTensor(),
    transforms.Normalize((0.485, 0.456, 0.406), (0.229, 0.224, 0.225))
])
query_image = transform(query_image)

# Extract features from the query image using a pre-trained CNN
model = torch.hub.load('pytorch/vision', 'resnet18', pretrained=True)
model.eval()
with torch.no_grad():
    query_image_feature = model(query_image.unsqueeze(0)).numpy().flatten()

# Search for similar images based on feature distance
query_bbox = (0, 0, width, height)  # Use the bounding box of the query image
result_ids = list(idx.intersection(query_bbox))
result_features = [query_image_feature if i == query_image_index else np.random.rand(512) for i in result_ids]  # Replace query image feature with actual query feature
distances = cdist([query_image_feature], result_features, metric='euclidean')[0]
similar_image_indices = np.argsort(distances)[:5]  # Get the indices of top 5 similar images

# Retrieve the image filenames from the similar image indices
similar_images = [image_list[result_ids[index]] for index in similar_image_indices]

# Print the list of similar image filenames
print("Similar images:")
print(similar_images)
