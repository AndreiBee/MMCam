import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def visualize(horizontalData, verticalData, startX, step, dataSize, filePath):
    # Reshape data to 2D array
    horizontalArray = np.array(horizontalData, dtype=np.double)
    print(horizontalArray)
    verticalArray = np.array(verticalData, dtype=np.double)
    print(verticalArray)

    npStart = float(startX)
    npStep = float(step)
    npFinish = npStart + float(dataSize) * npStep

    x = np.linspace(npStart, npFinish, int(dataSize))

    plt.plot(x, horizontalArray, color='b', label='Horizontal')
    plt.plot(x, verticalArray, color='g', label='Vertical')

    # Adding labels to the axes
    plt.xlabel('Focal length [mm]', fontsize=12)
    plt.ylabel('FWHM [mm]', fontsize=12)
    plt.legend()

    plt.savefig(filePath, dpi=300)  # Save image as a file
    print('FWHM Plot Image Created Successfully')
    # plt.show()


if __name__ == "__main__":
    import sys
    import json

    # Read arguments passed from C++
    data_file = sys.argv[1]  # First argument is file path
    with open(data_file, 'r') as file:
        params = json.load(file)

    horizontalData = params["horizontalData"]
    verticalData = params["verticalData"]
    dataSize = params["dataSize"]
    startX = params["startX"]
    step = params["step"]
    filePath = params["filePath"]

    visualize(horizontalData, verticalData, startX, step, dataSize, filePath)
