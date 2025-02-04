import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def visualize(imgData, width, height, pixelSize, colormap, filePath):
    data_reshaped = np.array(imgData, dtype=np.uint16).reshape((height, width))
    # Create the x and y coordinates
    x = np.arange(data_reshaped.shape[1])
    y = np.arange(data_reshaped.shape[0])
    x, y = np.meshgrid(x, y)

    # Define pixel size in µm (e.g., 2 µm per pixel)
    pixel_size_mm = pixelSize / 1000  # Convert pixel size to millimeters

    # Plot the 3D surface
    fig = plt.figure(figsize=(10, 8))
    ax = fig.add_subplot(111, projection='3d')
    surface = ax.plot_surface(x, y, data_reshaped, cmap=colormap)

    ax.set_xlabel("Distance [mm]")
    ax.set_ylabel("Distance [mm]")
    ax.set_zlabel("Intensity [a.u.]")

    tickSize = 5
    # Set custom tick labels in mm
    # Get default tick positions (in pixels)
    xticks_pixels = plt.xticks()[0]
    xticks_pixels = xticks_pixels[1:-1]
    xticks_pixels = xticks_pixels[:tickSize]
    for i in range(tickSize):
        xticks_pixels[i] = i * width / len(xticks_pixels)

    # print(xticks_pixels)
    yticks_pixels = plt.yticks()[0]
    yticks_pixels = yticks_pixels[1:-1]    # Convert pixel ticks to mm
    yticks_pixels = yticks_pixels[:5]
    for i in range(tickSize):
        yticks_pixels[i] = i * width / len(yticks_pixels)

    xticks_mm = xticks_pixels * pixel_size_mm
    yticks_mm = yticks_pixels * pixel_size_mm

    # Apply new tick labels
    # Set X-axis tick labels in mm
    plt.xticks(xticks_pixels, [f"{tick:.2f}" for tick in xticks_mm])
    # Set Y-axis tick labels in mm
    plt.yticks(yticks_pixels, [f"{tick:.2f}" for tick in yticks_mm])

    plt.savefig(filePath, dpi=300)

    print('Plot of 3D Image Created Successfully')
    # plt.show()


if __name__ == "__main__":
    import sys
    import json

    # Read arguments passed from C++
    data_file = sys.argv[1]  # First argument is file path
    with open(data_file, 'r') as file:
        params = json.load(file)

    imgData = params["data"]
    imgWidth = params["width"]
    imgheight = params["height"]
    colormap = params["colormap"]
    pixelSize = params["pixelSizeUM"]
    filePath = params["filePath"]

    visualize(imgData=imgData, width=imgWidth,
              height=imgheight, pixelSize=pixelSize, colormap=colormap, filePath=filePath)
