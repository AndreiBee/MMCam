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
	auto InitializeCamera() -> bool;
	auto GetImage(const int exposure_us) -> unsigned char*;
	auto GetImageWidth() const -> unsigned long;
	auto GetImageHeight() const -> unsigned long;
	auto CloseCamera() -> bool;
	~XimeaControl();
private:
	bool m_IsCameraOpen{};
	XI_IMG m_Image{};
	HANDLE m_CamHandler{};
	XI_RETURN m_State{};
};

#endif // !XIMEA_CONTROL_H

