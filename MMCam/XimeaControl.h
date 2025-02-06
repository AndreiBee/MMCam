#pragma once
#ifndef XIMEA_CONTROL_H
#define XIMEA_CONTROL_H

#define WIN32

#include "xiApi.h"
#include <memory>
#include <string>
#include <fstream>
#include <vector>

class XimeaControl final
{
public:
	XimeaControl();
	auto InitializeAllCameras() -> void;
	auto GetCamerasCount() -> unsigned short;
	auto GetCamerasSN() -> std::string*;
	auto SetExposureTime(const int exposure_us) -> void;
	auto InitializeCameraBySN(std::string cam_sn) -> bool;
	auto GetImage() -> unsigned short*;
	auto GetImageWidth() const -> unsigned long;
	auto GetImageHeight() const -> unsigned long;
	auto IsCameraInitialized() const -> bool;
	auto CloseCamera() -> bool;
	auto StopAcquisition() -> bool;
	auto WasAcquisitionStopped() -> bool;
	auto IsCameraConnected() -> bool;
	auto TryToReconnectLastSelectedCamera() -> bool;

	//auto AppendThread() -> int; // Returns the ID
	//auto GetThreadState(int id) -> bool;
	//auto TurnOffLastThread() -> bool;
	//auto ClearAllThreads() -> void;
	~XimeaControl();
private:
	bool m_IsCameraOpen{};
	XI_IMG m_Image;
	HANDLE m_CamHandler{};
	XI_RETURN m_State{};
	unsigned short m_CamerasCount{};
	std::unique_ptr<std::string[]> m_CamerasSN{};
	std::string m_CurrentCameraSN{};
	unsigned int m_Exposure{};
	bool m_WasAcquisitionStopped{};

	// Threads
	//std::vector<bool> m_Threads{};
};

#endif // !XIMEA_CONTROL_H

