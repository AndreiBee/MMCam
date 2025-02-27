import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import os


def visualize(data, width, height, pixelSize, colormap, filePath):
    # Reshape data to 2D array
    array = np.array(data, dtype=np.uint16).reshape((height, width))
    # print(width)

    # Define pixel size in µm (e.g., 2 µm per pixel)
    pixel_size_mm = pixelSize / 1000  # Convert pixel size to millimeters

    # Calculate image dimensions in mm
    image_width_mm = width * pixel_size_mm
    image_height_mm = height * pixel_size_mm

    # fig, ax = plt.subplots()
    # 2D Colormap Graph
    plt.figure()
    plt.imshow(array, cmap=colormap)
    # plt.colorbar()
    # Adding labels to the axes
    plt.xlabel('Distance [mm]', fontsize=12)
    plt.ylabel('Distance [mm]', fontsize=12)

    tickSize = 5

    xticks_pixels = plt.xticks()[0]
    xticks_pixels = xticks_pixels[1:-1]
    xticks_pixels = xticks_pixels[:tickSize]
    # print(xticks_pixels)
    for i in range(tickSize):
        xticks_pixels[i] = i * width / len(xticks_pixels)

    # print(xticks_pixels)
    yticks_pixels = plt.yticks()[0]
    yticks_pixels = yticks_pixels[1:-1]
    yticks_pixels = yticks_pixels[:tickSize]
    for i in range(tickSize):
        yticks_pixels[i] = i * width / len(yticks_pixels)

    # Convert pixel ticks to mm
    xticks_mm = xticks_pixels * pixel_size_mm
    yticks_mm = yticks_pixels * pixel_size_mm

    # Apply new tick labels
    # Set X-axis tick labels in mm
    plt.xticks(xticks_pixels, [
               f"{tick:.2f}" for tick in xticks_mm])
    # Set Y-axis tick labels in mm
    plt.yticks(yticks_pixels, [
               f"{tick:.2f}" for tick in yticks_mm])

    plt.savefig(filePath, dpi=300)  # Save image as a file

    filename_with_ext = os.path.basename(filePath)  # example.txt
    print(f'{filename_with_ext} Created Successfully')


if __name__ == "__main__":
    import sys
    import json

    # Read arguments passed from C++
    # First argument is file path
    data_file = os.fsdecode(sys.argv[1])
    # Verify if file exists
    if not os.path.exists(data_file):
        print(f"Error: File '{data_file}' not found.")
        sys.exit(1)

    with open(data_file, 'r', encoding='utf-8') as file:
        params = json.load(file)

    data = params["data"]
    width = params["width"]
    height = params["height"]
    colormap = params["colormap"]
    pixelSize = params["pixelSizeUM"]
    filePath = os.fsdecode(params["filePath"])

    visualize(data=data, width=width, height=height,
              pixelSize=pixelSize, colormap=colormap, filePath=filePath)
