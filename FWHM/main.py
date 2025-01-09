import cv2
import numpy as np
import os
import matplotlib.pyplot as plt

# Configuration
input_dir = r"D:\!Dokumenty - aktualni\optika\zakazky\037 Bruker C0 (mono)\mereni VID\2024-12-20_037-054\fokus"
output_dir = input_dir
min_bw_spot_area = 20
px = 0.0022  # pixel size in mm

# Spot detection (similar to getSpotCoords)


def get_spot_coords(image, threshold=21, min_area=20):
    _, binary = cv2.threshold(image, threshold, 255, cv2.THRESH_BINARY)
    contours, _ = cv2.findContours(
        binary, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    for contour in contours:
        area = cv2.contourArea(contour)
        if area >= min_area:
            M = cv2.moments(contour)
            if M["m00"] != 0:
                cx = int(M["m10"] / M["m00"])
                cy = int(M["m01"] / M["m00"])
                return cx, cy
    return 0, 0


# Processing images
file_list = [f for f in os.listdir(input_dir) if f.endswith(".tif")]
file_list = [f for f in file_list if f not in ["tmavy.tif", "svetly.tif"]]
dark = cv2.imread(os.path.join(input_dir, "tmavy.tif"),
                  cv2.IMREAD_GRAYSCALE).astype(np.float64)
bright = cv2.imread(os.path.join(input_dir, "svetly.tif"),
                    cv2.IMREAD_GRAYSCALE).astype(np.float64)

for file_name in file_list:
    data = cv2.imread(os.path.join(input_dir, file_name),
                      cv2.IMREAD_GRAYSCALE).astype(np.float64)
    x_p, y_p = get_spot_coords(data.astype(np.uint8), 21, min_bw_spot_area)
    if x_p == 0 and y_p == 0:
        print("Program terminated")
        break

    # Calculate ROI
    n = 228  # size of the ROI
    roi = data[y_p - n//2:y_p + n//2, x_p - n//2:x_p + n//2]
    roi_dark_corrected = roi - dark[y_p - n //
                                    2:y_p + n//2, x_p - n//2:x_p + n//2]

    # Plot corrected ROI
    plt.figure()
    plt.imshow(roi_dark_corrected, cmap="gray", extent=[0, px * n, 0, px * n])
    plt.xlabel("Distance (mm)")
    plt.ylabel("Distance (mm)")
    plt.colorbar(label="Intensity (a.u.)")
    plt.title(f"ROI for {file_name}")
    plt.savefig(os.path.join(output_dir, f"{file_name}_roi.png"), dpi=600)
    plt.close()

    # Horizontal and vertical profiles
    hor_profile = roi_dark_corrected[n//2, :]
    ver_profile = roi_dark_corrected[:, n//2]

    # Plot profiles
    plt.figure()
    plt.plot(np.linspace(-px * n / 2, px * n / 2, n),
             hor_profile, label="Horizontal")
    plt.plot(np.linspace(-px * n / 2, px * n / 2, n),
             ver_profile, label="Vertical")
    plt.xlabel("Distance (mm)")
    plt.ylabel("Intensity (a.u.)")
    plt.title(f"Profiles for {file_name}")
    plt.legend()
    plt.savefig(os.path.join(output_dir, f"{file_name}_profiles.png"), dpi=600)
    plt.close()
