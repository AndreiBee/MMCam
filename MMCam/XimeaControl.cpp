#include "XimeaControl.h"

XimeaControl::XimeaControl()
{
	InitializeCamera();
}

XimeaControl::XimeaControl(const int exposure_us)
{
	InitializeCamera();
	if (exposure_us) m_State = xiSetParamInt(m_CamHandler, XI_PRM_EXPOSURE, exposure_us);
}

auto XimeaControl::InitializeCamera() -> bool
{
	memset(&m_Image, 0, sizeof(m_Image));
	m_Image.size = sizeof(XI_IMG);

	m_CamHandler = NULL;
	m_State = XI_OK;

	/* Opening Camera */
	m_State = xiOpenDevice(0, &m_CamHandler);
	m_IsCameraOpen = m_State == XI_OK ? true : false;

	return m_State == XI_OK ? true : false;
}

auto XimeaControl::GetImage(const int exposure_us) -> unsigned char*
{
	if (!m_CamHandler || !m_IsCameraOpen) return nullptr;

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
	int img_width{};
	xiGetParamInt(m_CamHandler, XI_PRM_AEAG_ROI_WIDTH, &img_width);
	return img_width;
}

auto XimeaControl::GetImageHeight() const -> unsigned long
{
	int img_height{};
	xiGetParamInt(m_CamHandler, XI_PRM_AEAG_ROI_HEIGHT, &img_height);
	return img_height;
}

auto XimeaControl::IsCameraInitialized() const -> bool
{
	return m_IsCameraOpen;
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
