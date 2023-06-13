#pragma once
#ifndef XIMEA_CONTROL_H
#define XIMEA_CONTROL_H

#define WIN32

#include "xiApi.h"
#include <memory>
#include <string>
#include <fstream>

class XimeaControl final
{
public:
	XimeaControl();
	auto InitializeAllCameras() -> void;
	auto GetCamerasCount() -> unsigned short;
	auto GetCamerasSN() -> std::string*;
	auto SetExposureTime(const int exposure_us) -> void;
	auto InitializeCameraBySN(const std::string& cam_sn) -> bool;
	auto GetImage(const int exposure_us = 0) -> unsigned short*;
	auto GetImageWidth() const -> unsigned long;
	auto GetImageHeight() const -> unsigned long;
	auto IsCameraInitialized() const -> bool;
	auto CloseCamera() -> bool;
	~XimeaControl();
private:
	bool m_IsCameraOpen{};
	XI_IMG m_Image;
	HANDLE m_CamHandler{};
	XI_RETURN m_State{};
	unsigned short m_CamerasCount{};
	std::unique_ptr<std::string[]> m_CamerasSN{};
	std::string m_CurrentCameraSN{};
};

#endif // !XIMEA_CONTROL_H

