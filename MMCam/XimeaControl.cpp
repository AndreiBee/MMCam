#include "XimeaControl.h"

XimeaControl::XimeaControl()
{
	InitializeCamera();
}

auto XimeaControl::InitializeCamera() -> bool
{
	memset(&m_Image, 0, sizeof(m_Image));
	m_Image.size = sizeof(XI_IMG);

	m_CamHandler = NULL;
	m_State = XI_OK;

	/* Opening Camera */
	m_State = xiOpenDevice(0, &m_CamHandler);
	if (m_State == XI_OK) m_IsCameraOpen = true;

	return m_State == XI_OK ? true : false;
}

auto XimeaControl::GetImage(const int exposure_us) -> unsigned char*
{
	if (!m_CamHandler) return nullptr;
	m_State = xiSetParamInt(m_CamHandler, XI_PRM_EXPOSURE, exposure_us);
	if (m_State != XI_OK) return nullptr;
	m_State = xiStartAcquisition(m_CamHandler);
	if (m_State != XI_OK) return nullptr;

	DWORD timeout = (double)exposure_us / 1000.0 + 5000; // Default value = 5000
	m_State = xiGetImage(m_CamHandler, timeout, &m_Image);
	if (m_State != XI_OK) return nullptr;
	if (xiStopAcquisition(m_CamHandler) != XI_OK) return nullptr;

	return (unsigned char*)m_Image.bp;
}

auto XimeaControl::GetImageWidth() const -> unsigned long
{
	return m_Image.width;
}

auto XimeaControl::GetImageHeight() const -> unsigned long
{
	return m_Image.height;
}

auto XimeaControl::CloseCamera() -> bool
{
	if (xiCloseDevice(m_CamHandler) != XI_OK) return false;
	else return true;
}

XimeaControl::~XimeaControl()
{
	if (m_IsCameraOpen)
		CloseCamera();
}
