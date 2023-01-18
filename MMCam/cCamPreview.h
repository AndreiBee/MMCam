#pragma once
#ifndef CCAM_PREVIEW_H
#define CCAM_PREVIEW_H

#include "wx/wx.h"
#include "wx/dcbuffer.h"
#include "wx/graphics.h"

#include <iostream>
#include <fstream>
#include <string>

#include "XimeaControl.h"

class cCamPreview final : public wxPanel
{
public:
	cCamPreview(wxFrame* parent_frame, wxSizer* parent_sizer);
	void SetCameraCapturedImage(const uint32_t& exposure_time_us);

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
	std::unique_ptr<wxImage> m_Image{};
	std::unique_ptr<uint16_t[]> m_ImageData{};
	wxSize m_ImageSize{}, m_ImageOnCanvasSize{}, m_CanvasSize{};
	wxRealPoint m_NotZoomedGraphicsBitmapOffset{}, m_StartDrawPos{};
	wxRealPoint m_CursorPosOnCanvas{};
	/* Panning */
	bool m_Panning{};
	wxRealPoint m_PanOffset{}, m_PanStartPoint{}, m_PanDeltaPoints{};

	/* Zoom */
	double m_Zoom{}, m_ZoomOnOriginalSizeImage{};

	std::unique_ptr<XimeaControl> m_XimeaCameraControl{};

	DECLARE_EVENT_TABLE();
};

#endif // !CCAM_PREVIEW_H

