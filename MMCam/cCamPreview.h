#pragma once
#ifndef CCAM_PREVIEW_H
#define CCAM_PREVIEW_H

#include "wx/wx.h"
#include "wx/dcbuffer.h"
#include "wx/graphics.h"

#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <algorithm>

#include <opencv2/opencv.hpp>

#include "XimeaControl.h"

namespace CameraPreviewVariables
{
	enum 
	{
		XIMEA_CAM,
		MORAVIAN_INSTRUMENTS_CAM,
	};
}

class cCamPreview final : public wxPanel
{
public:
	cCamPreview(wxFrame* parent_frame, wxSizer* parent_sizer);
	auto SetImageSize(const wxSize& img_size) -> void;
	auto GetImagePtr() const -> wxImage*;
	auto GetImageSize() const->wxSize;
	auto SetXIMEAAsCurrentCamera() -> void;
	auto SetMoravianInstrumentsAsCurrentCamera() -> void;
	auto SetCameraCapturedImage() -> void;
	void CaptureAndSaveDataFromCamera
	(
		const unsigned long& exposure_time_us, 
		const wxString& path, 
		const std::string& start_hours,
		const std::string& start_minutes,
		const std::string& start_seconds,
		const int& frame_number, 
		const float& first_axis_position, 
		const float& second_axis_position = 0.f
	);

private:
	void InitDefaultComponents();
	void PaintEvent(wxPaintEvent& evt);
	void Render(wxBufferedPaintDC& dc);
	void DrawImage(wxGraphicsContext* gc);
	void CreateGraphicsBitmapImage(wxGraphicsContext* gc_);
	void DrawCameraCapturedImage(wxGraphicsContext* gc_);
	void OnSize(wxSizeEvent& evt);
	void ChangeSizeOfImageInDependenceOnCanvasSize();
	void CalculateMatlabJetColormapPixelRGB16bit(const uint16_t& value, unsigned char& r, unsigned char& g, unsigned char& b);
	void CalculateMatlabJetColormapPixelRGB8bit(const unsigned char& value, unsigned char& r, unsigned char& g, unsigned char& b);
	void OnMouseMoved(wxMouseEvent& evt);
	/* Zooming */
	void OnMouseWheelMoved(wxMouseEvent& evt);
	void AddZoom(const double& zoom, bool zoom_in_center_of_window = false);
	void SetZoom(const double& zoom, const wxRealPoint& center_);
	/* Panning */
	void ProcessPan(const wxRealPoint& point_, bool refresh_);
	void FinishPan(bool refresh);

	void OnPreviewMouseLeftPressed(wxMouseEvent& evt);
	void OnPreviewMouseLeftReleased(wxMouseEvent& evt);

private:
	int m_Width{}, m_Height{};
	bool m_IsGraphicsBitmapSet{}, m_IsImageSet{};
	std::unique_ptr<wxGraphicsBitmap> m_GraphicsBitmapImage{};
	std::shared_ptr<wxImage> m_Image{};
	std::unique_ptr<unsigned char[]> m_ImageData{};
	wxSize m_ImageSize{}, m_ImageOnCanvasSize{}, m_CanvasSize{};
	wxRealPoint m_NotZoomedGraphicsBitmapOffset{}, m_StartDrawPos{};
	wxRealPoint m_CursorPosOnCanvas{};
	/* Panning */
	bool m_Panning{};
	wxRealPoint m_PanOffset{}, m_PanStartPoint{}, m_PanDeltaPoints{};

	/* Zoom */
	double m_Zoom{}, m_ZoomOnOriginalSizeImage{};

	std::unique_ptr<XimeaControl> m_XimeaCameraControl{};
	bool m_XimeaSelected{};

	bool m_MoravianInstrumentsSelected{};

	DECLARE_EVENT_TABLE();
};

#endif // !CCAM_PREVIEW_H

