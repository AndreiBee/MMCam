#pragma once
#ifndef CCAM_PREVIEW_H
#define CCAM_PREVIEW_H

#include "wx/wx.h"
#include "wx/dcbuffer.h"
#include "wx/graphics.h"


class cCamPreview final : public wxPanel
{
public:
	cCamPreview(wxFrame* parent_frame, wxSizer* parent_sizer);

private:
	void PaintEvent(wxPaintEvent& evt);
	void Render(wxBufferedPaintDC& dc);

	void OnSize(wxSizeEvent& evt);


private:
	int m_Width{}, m_Height{};
	wxSize m_CanvasSize{};

	DECLARE_EVENT_TABLE();
};

#endif // !CCAM_PREVIEW_H

