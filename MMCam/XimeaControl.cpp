#include "XimeaControl.h"

XimeaControl::XimeaControl()
{
}

auto XimeaControl::InitializeAllCameras() -> void
{
	{
		DWORD num_devices{};
		xiGetNumberDevices(&num_devices);
		m_CamerasCount = static_cast<unsigned short>(num_devices);
	}
	m_CamerasSN = std::make_unique<std::string[]>(m_CamerasCount);
	if (m_CamerasCount >= 1)
	{
		HANDLE cam_handler{};
		for (auto i{ 0 }; i < m_CamerasCount; ++i)
		{
			m_State = xiOpenDevice(i, &cam_handler);
			char sn[100] = "";
			xiGetParamString(cam_handler, XI_PRM_DEVICE_SN, sn, sizeof(sn));
			xiCloseDevice(cam_handler);
			cam_handler = NULL;
			m_CamerasSN[i] = std::string(sn);
		}
	}
}

auto XimeaControl::GetCamerasCount() -> unsigned short
{
	return m_CamerasCount;
}

auto XimeaControl::GetCamerasSN() -> std::string*
{
	return m_CamerasSN.get();
}

auto XimeaControl::SetExposureTime(const int exposure_us) -> void
{
	if (exposure_us) m_State = xiSetParamInt(m_CamHandler, XI_PRM_EXPOSURE, exposure_us);
}

auto XimeaControl::InitializeCameraBySN(const std::string& cam_sn) -> bool
{
	m_CurrentCameraSN = cam_sn;
	m_CamHandler = NULL;
	m_State = XI_OK;

	/* Opening Camera */
	m_State = xiOpenDeviceBy(XI_OPEN_BY_SN, cam_sn.c_str(), &m_CamHandler);
	m_IsCameraOpen = m_State == XI_OK ? true : false;

	memset(&m_Image, 0, sizeof(m_Image));
	m_Image.size = sizeof(XI_IMG);

	/* Set the data format to 12-bit */
	int format = XI_RAW16;
	m_State = xiSetParamInt(m_CamHandler, XI_PRM_IMAGE_DATA_FORMAT, format);

	return m_State == XI_OK ? true : false;
}

auto XimeaControl::GetImage(const int exposure_us) -> unsigned short*
{
	if (!m_CamHandler || !m_IsCameraOpen) return nullptr;

	m_State = xiStartAcquisition(m_CamHandler);
	if (m_State != XI_OK) return nullptr;

	DWORD timeout = (double)exposure_us / 1000.0 + 5000; // Default value = 5000
	m_State = xiGetImage(m_CamHandler, timeout, &m_Image);
	if (m_State != XI_OK) return nullptr;
	if (xiStopAcquisition(m_CamHandler) != XI_OK) return nullptr;

	return (unsigned short*)m_Image.bp;
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
	if (xiCloseDevice(m_CamHandler) != XI_OK)
	{
		m_IsCameraOpen = false;
		m_CamHandler = NULL;
		return false;
	}
	else
	{
		m_IsCameraOpen = false;
		m_CamHandler = NULL;
		return true;
	}
}

XimeaControl::~XimeaControl()
{
	if (m_IsCameraOpen)
		CloseCamera();
}
