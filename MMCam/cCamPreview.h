#pragma once
#ifndef CCAM_PREVIEW_H
#define CCAM_PREVIEW_H

#include "wx/wx.h"
#include "wx/dcbuffer.h"
#include "wx/graphics.h"
#include "wx/tglbtn.h"

#include <iostream>
#include <fstream>
#include <string>
#include <format>
#include <algorithm>

#include <opencv2/opencv.hpp>

#include "FWHMCalculation.h"

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
		wxToggleButton* set_pos_tgl_btn{};
		InputPreviewPanelArgs() {};
		InputPreviewPanelArgs
		(
			wxTextCtrl* par_x_pos_crosshair,
			wxTextCtrl* par_y_pos_crosshair,
			wxToggleButton* par_pos_crosshair_tgl_btn
		) : x_pos_crosshair(par_x_pos_crosshair),
			y_pos_crosshair(par_y_pos_crosshair), 
			set_pos_tgl_btn(par_pos_crosshair_tgl_btn) {};
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
	auto SetBackgroundColor(wxColour bckg_colour) -> void;
	auto SetCrossHairButtonActive(bool activate = false) -> void;
	auto SetValueDisplayingActive(bool activate = false) -> void;
	auto ActivateFWHMDisplaying(bool activate = false) -> void;
	void SetXCrossHairPosFromParentWindow(const int& x_pos);
	void SetYCrossHairPosFromParentWindow(const int& y_pos);
	auto SettingCrossHairPosFromParentWindow(bool set = false) -> void;
	auto SetImageSize(const wxSize& img_size) -> void;
	auto GetDataPtr() const -> unsigned short*;
	//auto GetImagePtr() const->wxImage*;
	auto GetImageSize() const->wxSize;
	auto InitializeSelectedCamera(const std::string& camera_sn) -> void;
	auto UpdateImageParameters() -> void;

	auto SetCameraCapturedImage
	(
		unsigned short* data_ptr
	) -> void;

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

	// FWHM
	auto SetPixelSizeUM(const double pixel_sizeUM) 
	{ 
		m_PixelSizeUM = pixel_sizeUM > 0.0 ? pixel_sizeUM : 1.0;
		if (m_CropSizeMM != 0.0)
			m_ROIWindowWidth = static_cast<int>(std::ceil(m_CropSizeMM / (m_PixelSizeUM / 1000.0)));
	};
	auto SetCropSizeMM(const double crop_sizeMM) 
	{ 
		m_CropSizeMM = crop_sizeMM > 0.0 ? crop_sizeMM : 0.0; 
		if (m_PixelSizeUM != 0.0)
			m_ROIWindowWidth = static_cast<int>(std::ceil(m_CropSizeMM / (m_PixelSizeUM / 1000.0)));
	};


private:
	void InitDefaultComponents();
	void PaintEvent(wxPaintEvent& evt);
	void Render(wxBufferedPaintDC& dc);
	void DrawImage(wxGraphicsContext* gc);
	
	auto UpdateWXImage() -> void;
	auto AdjustImageParts
	(
		const unsigned short* data_ptr,
		const unsigned int start_x,
		const unsigned int start_y,
		const unsigned int finish_x,
		const unsigned int finish_y
	) -> void;


	void CreateGraphicsBitmapImage(wxGraphicsContext* gc_);
	void DrawCameraCapturedImage(wxGraphicsContext* gc_);
	auto DrawFWHMValues(wxGraphicsContext* gc_) -> void;
	auto DrawSpotCroppedWindow(wxGraphicsContext* gc_) -> void;
	auto DrawSumLines(wxGraphicsContext* gc_) -> void;
	auto DrawHorizontalSumLine(wxGraphicsContext* gc_) -> void;
	auto DrawVerticalSumLine(wxGraphicsContext* gc_) -> void;
	void OnSize(wxSizeEvent& evt);
	void ChangeSizeOfImageInDependenceOnCanvasSize();
	auto UpdateCrossHairOnSize() -> void;
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
	wxGraphicsBitmap m_GraphicsBitmapImage{};

	wxImage m_Image{};
	std::unique_ptr<unsigned short[]> m_ImageData{};
	
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
	std::string m_SelectedCameraSN{};

	/* CrossHair Tool */
	std::unique_ptr<CrossHairTool> m_CrossHairTool{};
	wxPoint m_CrossHairPos{};
	bool m_ChangingCrossHairPosition{};
	//bool m_SettingCrossHairPos{};

	bool m_DisplayPixelValues{};

	bool m_DisplayFWHM{};
	std::unique_ptr<unsigned int[]> m_HorizontalSumArray{}, m_VerticalSumArray{};
	double m_HorizontalFWHM_PX{}, m_VerticalFWHM_PX{};
	std::pair<int, unsigned int> m_HorizontalWorstPosSum{}, m_HorizonalBestPosSum{};
	std::pair<int, unsigned int> m_VerticalWorstPosSum{}, m_VerticalBestPosSum{};
	double m_PixelSizeUM{}, m_CropSizeMM{};
	int m_ROIWindowWidth{};

	std::unique_ptr<CameraPreviewVariables::InputPreviewPanelArgs> m_ParentArguments{};

	DECLARE_EVENT_TABLE();
};

#endif // !CCAM_PREVIEW_H

