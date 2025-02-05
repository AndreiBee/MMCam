import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import os


def visualize(lineProfileData, horizontalAxisData, title, xLabel, yLabel, lineColour, filePath):
    lpData = np.array(lineProfileData, dtype=np.uint16)
    horData = np.array(horizontalAxisData, dtype=np.double)

    plt.plot(horData, lpData, color=lineColour)

    plt.title(title)
    plt.xlabel(xLabel, fontsize=12)
    plt.ylabel(yLabel, fontsize=12)

    plt.savefig(filePath, dpi=300)

    filename_with_ext = os.path.basename(filePath)  # example.txt
    print(f'{filename_with_ext} Created Successfully')
    # plt.show()


if __name__ == "__main__":
    import sys
    import json

    # Read arguments passed from C++
    data_file = sys.argv[1]  # First argument is file path
    with open(data_file, 'r') as file:
        params = json.load(file)

    lineProfileData = params["lineProfileData"]
    horizontalAxisData = params["horizontalAxisData"]
    dataWidth = params["width"]
    title = params["title"]
    xLabel = params["xLabel"]
    yLabel = params["yLabel"]
    lineColour = params["lineColour"]
    filePath = params["filePath"]

    visualize(lineProfileData=lineProfileData, horizontalAxisData=horizontalAxisData,
              title=title, xLabel=xLabel, yLabel=yLabel, lineColour=lineColour, filePath=filePath)
