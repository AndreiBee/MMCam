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

#include "cPreviewTools.h"
#include "XimeaControl.h"

namespace CameraPreviewVariables
{
	enum 
	{
		MORAVIAN_INSTRUMENTS_CAM,
		XIMEA_CAM,
	};

	struct InputPreviewPanelArgs
	{
		wxTextCtrl* x_pos_crosshair{}, * y_pos_crosshair{};
		InputPreviewPanelArgs() {};
		InputPreviewPanelArgs
		(
			wxTextCtrl* par_x_pos_crosshair,
			wxTextCtrl* par_y_pos_crosshair
		) : x_pos_crosshair(par_x_pos_crosshair),
			y_pos_crosshair(par_y_pos_crosshair) {};
	};
}

class cCamPreview final : public wxPanel
{
public:
	cCamPreview
	(
		wxFrame* parent_frame, 
		wxSizer* parent_sizer, 
		std::unique_ptr<CameraPreviewVariables::InputPreviewPanelArgs> input_preview_panel_args
	);
	auto SetCrossHairButtonActive(bool activate = false) -> void;
	void SetXCrossHairPosFromParentWindow(const int& x_pos);
	void SetYCrossHairPosFromParentWindow(const int& y_pos);
	auto SetImageSize(const wxSize& img_size) -> void;
	auto GetDataPtr() const -> unsigned short*;
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
	void CalculateMatlabJetColormapPixelRGB8bit
	(
		const unsigned char& value, 
		unsigned char& r, 
		unsigned char& g, 
		unsigned char& b
	);
	void CalculateMatlabJetColormapPixelRGB12bit
	(
		const unsigned short& value, 
		unsigned char& r, 
		unsigned char& g, 
		unsigned char& b
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
	void OnMouseMoved(wxMouseEvent& evt);
	/* Zooming */
	void OnMouseWheelMoved(wxMouseEvent& evt);
	void AddZoom(const double& zoom, bool zoom_in_center_of_window = false);
	void SetZoom(const double& zoom, const wxRealPoint& center_);
	/* Panning */
	void ProcessPan(const wxRealPoint& point_, bool refresh_);
	void FinishPan(bool refresh);

	void CheckIfMouseAboveImage();
	void CalculatePositionOnImage();

	void OnPreviewMouseLeftPressed(wxMouseEvent& evt);
	void OnPreviewMouseLeftReleased(wxMouseEvent& evt);

	void ChangeCursorInDependenceOfCurrentParameters();

	/* CrossHair */
	void DrawCrossHair(wxGraphicsContext* graphics_context);

private:
	int m_Width{}, m_Height{};
	bool m_IsGraphicsBitmapSet{}, m_IsImageSet{};
	std::unique_ptr<wxGraphicsBitmap> m_GraphicsBitmapImage{};

	std::shared_ptr<wxImage> m_Image{};
	std::shared_ptr<unsigned short[]> m_ImageData{};
	
	wxSize m_ImageSize{}, m_ImageOnCanvasSize{}, m_CanvasSize{};
	wxRealPoint m_NotCheckedCursorPosOnImage{}, m_CheckedCursorPosOnImage{}, m_CursorPosOnCanvas{};
	wxRealPoint m_NotZoomedGraphicsBitmapOffset{}, m_StartDrawPos{};
	bool m_IsCursorInsideImage{};
	/* Panning */
	bool m_Panning{};
	wxRealPoint m_PanOffset{}, m_PanStartPoint{}, m_PanDeltaPoints{};

	/* Zoom */
	double m_Zoom{}, m_ZoomOnOriginalSizeImage{};

	std::unique_ptr<XimeaControl> m_XimeaCameraControl{};
	bool m_XimeaSelected{};

	bool m_MoravianInstrumentsSelected{};

	/* CrossHair Tool */
	std::unique_ptr<CrossHairTool> m_CrossHairTool{};
	wxPoint m_CrossHairPos{};
	bool m_ChangingCrossHairPosition{};

	std::unique_ptr<CameraPreviewVariables::InputPreviewPanelArgs> m_ParentArguments{};

	DECLARE_EVENT_TABLE();
};

#endif // !CCAM_PREVIEW_H

