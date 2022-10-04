#include "cCamPreview.h"

BEGIN_EVENT_TABLE(cCamPreview, wxPanel)
	EVT_PAINT(cCamPreview::PaintEvent)
	EVT_SIZE(cCamPreview::OnSize)
	EVT_MOTION(cCamPreview::OnMouseMoved)
	EVT_MOUSEWHEEL(cCamPreview::OnMouseWheelMoved)
	EVT_LEFT_DOWN(cCamPreview::OnPreviewMouseLeftPressed)
	EVT_LEFT_UP(cCamPreview::OnPreviewMouseLeftReleased)
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

void cCamPreview::SetCameraCapturedImage(const uint32_t& exposure_time_us)
{
	m_ImageSize.SetWidth(2048);
	m_ImageSize.SetHeight(2048);

	uint64_t read_data_size = m_ImageSize.GetWidth() * m_ImageSize.GetHeight();
	m_ImageData = std::make_unique<uint16_t[]>(read_data_size);

#ifdef _DEBUG
	std::ifstream in_file;
	std::string raw_path = "src\\examples\\art_img_2048x2048_with_square.raw";
	in_file.open(raw_path, std::fstream::in | std::fstream::binary);
	if (in_file.is_open())
	{
		//uint16_t curr_val{};
		//in_file.read((char*)&curr_val, sizeof(uint16_t));
		in_file.seekg(0, std::ios::beg);
		in_file.read((char*)m_ImageData.get(), read_data_size * sizeof(uint16_t));
		in_file.close();
	}
#endif // _DEBUG
	
	m_Image = std::make_unique<wxImage>(m_ImageSize.GetWidth(), m_ImageSize.GetHeight());
	uint16_t current_value{}, max_uint16_t{ 65535 }, half_max_uint16_t{ 32768 }, max_char_uint16_t{ 256 };
	unsigned char red{}, green{}, blue{}, range{ 128 };
	for (auto y{ 0 }; y < m_ImageSize.GetHeight(); ++y)
	{
		for (auto x{ 0 }; x < m_ImageSize.GetWidth(); ++x)
		{
			current_value = m_ImageData[y * m_ImageSize.GetWidth() + x];
			/* Matlab implementation of JetColormap */
			CalculateMatlabJetColormapPixelRGB(current_value, red, green, blue);
			m_Image->SetRGB(x, y, red, green, blue);
		}
	}

	m_IsImageSet = true;
	m_IsGraphicsBitmapSet = false;
	m_Zoom = 1.0;
	ChangeSizeOfImageInDependenceOnCanvasSize();

	Refresh();
}

void cCamPreview::CalculateMatlabJetColormapPixelRGB(const uint16_t& value, unsigned char& r, unsigned char& g, unsigned char& b)
{
	uint16_t x0{ 7967 }, x1{ 24415 }, x2{ 40863 }, x3{ 57311 }, x4{ 65535 };
	if (value < x0)
	{
		r = 0;
		g = 0;
		b = 255 * 0.51563f + (float)value * (255.0f - 255 * 0.51563f) / (float)x0;
	}
	else if (value >= x0 && value <= x1)
	{
		r = 0;
		g = (float)(value - x0) * 255.0f / (float)(x1 - x0);
		b = 255;
	}
	else if (value > x1 && value < x2)
	{
		r = (float)(value - x1) * 255.0f / (float)(x2 - x1);
		g = 255;
		b = (float)(x2 - value) * 255.0f / (float)(x2 - x1);
	}
	else if (value >= x2 && value <= x3)
	{
		r = 255;
		g = (float)(x3 - value) * 255.0f / (float)(x3 - x2);
		b = 0;
	}
	else if (value > x3)
	{
		r = 255.0f * 0.5f + (float)(x4 - value) * (255.0f - 255.0f * 0.5f) / (float)(x4 - x3);
		g = 0;
		b = 0;
	}
}

void cCamPreview::OnMouseMoved(wxMouseEvent& evt)
{
	if (m_IsImageSet)
	{
		m_CursorPosOnCanvas.x = m_ZoomOnOriginalSizeImage * evt.GetPosition().x;
		m_CursorPosOnCanvas.y = m_ZoomOnOriginalSizeImage * evt.GetPosition().y;

		if (m_Panning)
		{
			ProcessPan(m_CursorPosOnCanvas, true);
		}
	}
}

void cCamPreview::OnMouseWheelMoved(wxMouseEvent& evt)
{
	if (m_Zoom <= 1.0 && evt.GetWheelRotation() < 0)
	{

	}
	else
	{
		//m_CursorPosOnCanvas = evt.GetPosition();
		if (evt.GetWheelRotation() > 0 && m_Zoom / m_ZoomOnOriginalSizeImage < 64.0)
		{
			AddZoom(2.0);
		}
		else if (evt.GetWheelRotation() < 0)
		{
			if (m_Zoom > 1.0)
			{
				AddZoom(0.5);
			}
		}
	}
}

void cCamPreview::AddZoom(const double& zoom, bool zoom_in_center_of_window)
{
	wxRealPoint center = zoom_in_center_of_window ?
		wxRealPoint(GetSize().x / 2.0, GetSize().y / 2.0) :
		wxRealPoint(
			m_CursorPosOnCanvas.x,
			m_CursorPosOnCanvas.y);

	SetZoom(m_Zoom * zoom, center);
}

void cCamPreview::SetZoom(const double& zoom, const wxRealPoint& center_)
{
	wxRealPoint position_on_image{};
	position_on_image.x = (center_.x - m_PanOffset.x) / m_Zoom;
	position_on_image.y = (center_.y - m_PanOffset.y) / m_Zoom;

	m_Zoom = zoom;

	m_PanOffset.x = m_Zoom > 1.0 ? center_.x - position_on_image.x * m_Zoom : 0.0;
	m_PanOffset.y = m_Zoom > 1.0 ? center_.y - position_on_image.y * m_Zoom : 0.0;

	m_StartDrawPos.x = m_PanOffset.x / m_Zoom + m_NotZoomedGraphicsBitmapOffset.x;
	m_StartDrawPos.y = m_PanOffset.y / m_Zoom + m_NotZoomedGraphicsBitmapOffset.y;
	Refresh();
}

void cCamPreview::ProcessPan(const wxRealPoint& point_, bool refresh_)
{
	m_PanDeltaPoints = m_PanStartPoint - point_;
	//LOG2F("PanStartPoint x: ", m_PanStartPoint.x, " y: ", m_PanStartPoint.y);
	m_StartDrawPos.x = m_PanOffset.x / m_Zoom - m_PanDeltaPoints.x / m_Zoom + m_NotZoomedGraphicsBitmapOffset.x;
	m_StartDrawPos.y = m_PanOffset.y / m_Zoom - m_PanDeltaPoints.y / m_Zoom + m_NotZoomedGraphicsBitmapOffset.y;
	if (refresh_) Refresh();
}

void cCamPreview::FinishPan(bool refresh)
{
	if (m_Panning)
	{
		m_PanOffset.x -= m_PanDeltaPoints.x;
		m_PanOffset.y -= m_PanDeltaPoints.y;

		m_PanDeltaPoints = { 0.0, 0.0 };

		m_Panning = false;

		if (refresh) Refresh();
	}
}

void cCamPreview::OnPreviewMouseLeftPressed(wxMouseEvent& evt)
{
	if (m_Zoom > 1.0)
	{
		m_Panning = true;
		m_PanStartPoint = m_CursorPosOnCanvas;
	}
}

void cCamPreview::OnPreviewMouseLeftReleased(wxMouseEvent& evt)
{
	if (m_Panning)
	{
		FinishPan(true);
		m_Panning = false;
	}
}

void cCamPreview::InitDefaultComponents()
{
	m_GraphicsBitmapImage = std::make_unique<wxGraphicsBitmap>();
}

void cCamPreview::PaintEvent(wxPaintEvent& evt)
{
	wxBufferedPaintDC dc(this);
	Render(dc);
}

void cCamPreview::Render(wxBufferedPaintDC& dc)
{
	dc.Clear();
	wxGraphicsContext* gc_image{};
	gc_image = wxGraphicsContext::Create(dc);
	if (gc_image)
	{
		DrawCameraCapturedImage(gc_image);
		delete gc_image;
	}
}

void cCamPreview::CreateGraphicsBitmapImage(wxGraphicsContext* gc_)
{
	if (!m_IsGraphicsBitmapSet && m_IsImageSet)
	{
		m_GraphicsBitmapImage = std::make_unique<wxGraphicsBitmap>(gc_->CreateBitmapFromImage(*m_Image));;
		m_IsGraphicsBitmapSet = true;
	}
}

void cCamPreview::DrawCameraCapturedImage(wxGraphicsContext* gc_)
{
	CreateGraphicsBitmapImage(gc_);
	
	if (m_IsGraphicsBitmapSet)
	{
		auto interpolation_quality = m_Zoom / m_ZoomOnOriginalSizeImage >= 1.0 ? wxINTERPOLATION_NONE : wxINTERPOLATION_DEFAULT;

		gc_->SetInterpolationQuality(interpolation_quality);
		gc_->Scale(m_Zoom / m_ZoomOnOriginalSizeImage, m_Zoom / m_ZoomOnOriginalSizeImage);
		gc_->DrawBitmap(*m_GraphicsBitmapImage.get(),
			m_StartDrawPos.x, m_StartDrawPos.y,
			m_ImageSize.GetWidth(), m_ImageSize.GetHeight());
	}
}

void cCamPreview::OnSize(wxSizeEvent& evt)
{
	int newWidth{ evt.GetSize().x }, newHeight{ evt.GetSize().y };
	if (newWidth != m_CanvasSize.GetWidth() || newHeight != m_CanvasSize.GetHeight())
	{
		m_CanvasSize.SetWidth(newWidth);
		m_CanvasSize.SetHeight(newHeight);
		m_Zoom = 1.0;
		m_PanOffset = {};
		ChangeSizeOfImageInDependenceOnCanvasSize();
		m_IsGraphicsBitmapSet = false;
		Refresh();
	}
}

void cCamPreview::ChangeSizeOfImageInDependenceOnCanvasSize()
{
	wxSize current_image_size{ m_ImageSize };
	wxSize canvas_size{ GetSize().GetWidth(), GetSize().GetHeight() };
	m_ZoomOnOriginalSizeImage = 1.0;
	while (canvas_size.GetWidth() < current_image_size.GetWidth() || canvas_size.GetHeight() < current_image_size.GetHeight())
	{
		current_image_size.SetWidth(current_image_size.GetWidth() / 2);
		current_image_size.SetHeight(current_image_size.GetHeight() / 2);
		m_ZoomOnOriginalSizeImage *= 2.0;
	}
	m_ImageOnCanvasSize.Set(current_image_size.GetWidth(), current_image_size.GetHeight());
	m_NotZoomedGraphicsBitmapOffset.x = (canvas_size.GetWidth() - m_ImageOnCanvasSize.GetWidth()) / 2;
	m_NotZoomedGraphicsBitmapOffset.y = (canvas_size.GetHeight() - m_ImageOnCanvasSize.GetHeight()) / 2;
	m_NotZoomedGraphicsBitmapOffset.x *= m_ZoomOnOriginalSizeImage / m_Zoom;
	m_NotZoomedGraphicsBitmapOffset.y *= m_ZoomOnOriginalSizeImage / m_Zoom;
	m_StartDrawPos = m_NotZoomedGraphicsBitmapOffset;
}

