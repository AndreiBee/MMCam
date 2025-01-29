import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def visualize(imgData, width, height, filePath):
    data_reshaped = np.array(imgData, dtype=np.uint16).reshape((height, width))
    # Create the x and y coordinates
    x = np.arange(data_reshaped.shape[1])
    y = np.arange(data_reshaped.shape[0])
    x, y = np.meshgrid(x, y)

    # Plot the 3D surface
    fig = plt.figure(figsize=(10, 8))
    ax = fig.add_subplot(111, projection='3d')
    surface = ax.plot_surface(x, y, data_reshaped, cmap='plasma')

    ax.set_xlabel("Distance [mm]")
    ax.set_ylabel("Distance [mm]")
    ax.set_zlabel("Intensity [a.u.]")

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
    filePath = params["filePath"]

    visualize(imgData=imgData, width=imgWidth,
              height=imgheight, filePath=filePath)
