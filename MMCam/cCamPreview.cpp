#include "cCamPreview.h"

BEGIN_EVENT_TABLE(cCamPreview, wxPanel)
	EVT_PAINT(cCamPreview::PaintEvent)
	EVT_SIZE(cCamPreview::OnSize)
END_EVENT_TABLE()

cCamPreview::cCamPreview(wxFrame* parent_frame, wxSizer* parent_sizer) 
	: wxPanel(parent_frame)
{
	SetDoubleBuffered(true);
#ifdef _DEBUG
	SetBackgroundColour(wxColor(210, 185, 155));
#else
	SetBackgroundColour(wxColor(255, 255, 255));
#endif // _DEBUG
	parent_sizer->Add(this, 1, wxEXPAND);
}

void cCamPreview::PaintEvent(wxPaintEvent& evt)
{
	wxBufferedPaintDC dc(this);
	Render(dc);
}

void cCamPreview::Render(wxBufferedPaintDC& dc)
{
	dc.Clear();
}

void cCamPreview::OnSize(wxSizeEvent& evt)
{
	int newWidth{ evt.GetSize().x }, newHeight{ evt.GetSize().y };
	if (newWidth != m_CanvasSize.GetWidth() || newHeight != m_CanvasSize.GetHeight())
	{
		m_CanvasSize.SetWidth(newWidth);
		m_CanvasSize.SetHeight(newHeight);
		Refresh();
	}
}

