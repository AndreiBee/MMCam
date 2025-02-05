import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import os


def visualize(firstData, firstSmallLabel, firstColor, xLabel, secondData, secondSmallLabel, secondColor, yLabel, startX, step, dataSize, bestInGain, filePath):
    # Reshape data to 2D array
    firstArray = np.array(firstData, dtype=np.double)
    max_index_in_first_array = np.argmax(firstArray)
    # print(firstArray)

    secondArray = np.array(secondData, dtype=np.double)
    max_index_in_second_array = np.argmax(secondArray)
    # print(secondArray)

    npStart = float(startX)
    npStep = float(step)
    npFinish = npStart + float(dataSize - 1) * npStep

    x = np.linspace(npStart, npFinish, int(dataSize))
    # print(x)

    plt.plot(x, firstArray, color=firstColor, label=firstSmallLabel)
    plt.plot(x, secondArray, color=secondColor, label=secondSmallLabel)

    if bestInGain < dataSize:
        plt.axvline(x=x[bestInGain], color='red',
                    linestyle='--', linewidth=2, label='Best Focus')

    # Adding labels to the axes
    plt.xlabel(xLabel, fontsize=12)
    plt.ylabel(yLabel, fontsize=12)
    plt.legend()

    plt.savefig(filePath, dpi=300)  # Save image as a file

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

    firstData = params["firstData"]
    firstSmallLabel = params["firstSmallLabel"]
    firstColor = params["firstColor"]
    xLabel = params["xLabel"]
    secondData = params["secondData"]
    secondSmallLabel = params["secondSmallLabel"]
    secondColor = params["secondColor"]
    yLabel = params["yLabel"]
    dataSize = params["dataSize"]
    startX = params["startX"]
    step = params["step"]
    bestInGain = params["bestInGain"]
    filePath = params["filePath"]

    visualize(firstData=firstData, firstSmallLabel=firstSmallLabel, firstColor=firstColor, xLabel=xLabel, secondData=secondData,
              secondSmallLabel=secondSmallLabel, secondColor=secondColor, yLabel=yLabel, startX=startX, step=step, dataSize=dataSize, bestInGain=bestInGain, filePath=filePath)
