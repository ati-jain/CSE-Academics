import os
import shutil

# Source directory containing subfolders
src_dir = "AID"

# Destination directory to copy items
dst_dir = "Dataset"

# Number of items to copy from each subfolder
num_items_per_subfolder = 10

# Iterate over all subfolders in the source directory
for root, dirs, files in os.walk(src_dir):
    for subdir in dirs:
        subfolder_path = os.path.join(root, subdir)
        subfolder_files = os.listdir(subfolder_path)
        
        # Copy specified number of items from the subfolder to the destination directory
        for i in range(min(num_items_per_subfolder, len(subfolder_files))):
            src_file = os.path.join(subfolder_path, subfolder_files[i])
            dst_file = os.path.join(dst_dir, subfolder_files[i])
            shutil.copy2(src_file, dst_file)
            print(f"Copied {subfolder_files[i]} from {subfolder_path} to {dst_file}")
