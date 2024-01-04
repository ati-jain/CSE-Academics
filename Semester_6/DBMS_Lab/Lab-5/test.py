import glob

folder_path = "./"  # Replace with the path to your folder

# Use glob to get a list of all JPG files in the folder
jpg_files = glob.glob("*.jpg")

# Iterate over the JPG files
for jpg_file in jpg_files:
    # Do something with each JPG file, e.g. print the filename
    print("Processing file:", jpg_file)
    # Add your code here to perform the desired operations on each JPG file
