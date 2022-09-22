#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)

wxEND_EVENT_TABLE()

cMain::cMain(const wxString& title_) 
	: wxFrame(NULL, wxID_ANY, title_)
{
	CreateMainFrame();
	CenterOnScreen();
}

void cMain::CreateMainFrame()
{
	InitComponents();
	CreateLeftAndRightSide();
}

void cMain::InitComponents()
{
	m_X_Detector = std::make_unique<MainFrameVariables::StepperControl>();
}

void cMain::CreateLeftAndRightSide()
{
	wxBoxSizer* main_sizer = new wxBoxSizer(wxHORIZONTAL);


	int height_left_and_right_panels{ 600 };
	wxBoxSizer* right_sizer = new wxBoxSizer(wxVERTICAL);
	wxSize sizeOfRightSide = { 300, height_left_and_right_panels };
	right_sizer->SetMinSize(sizeOfRightSide);
	CreateRightSide(right_sizer);

	wxBoxSizer* left_sizer = new wxBoxSizer(wxHORIZONTAL);
	wxSize sizeOfPreviewWindow = { 600, height_left_and_right_panels };
	left_sizer->SetMinSize(sizeOfPreviewWindow);
	CreateLeftSide(left_sizer);

	main_sizer->Add(left_sizer, 1, wxEXPAND);
	main_sizer->Add(right_sizer, 0, wxEXPAND);

	SetSizerAndFit(main_sizer);
}

void cMain::CreateLeftSide(wxSizer* left_side_sizer)
{
	wxPanel* left_side_panel = new wxPanel(this);
#ifdef _DEBUG
	left_side_panel->SetBackgroundColour(wxColor(120, 200, 80));
#else
	left_side_panel->SetBackgroundColour(wxColor(255, 255, 255));
#endif // _DEBUG

	wxBoxSizer* left_side_panel_sizer = new wxBoxSizer(wxVERTICAL);

	left_side_panel->SetSizer(left_side_panel_sizer);
	left_side_sizer->Add(left_side_panel, 1, wxEXPAND);

}

void cMain::CreateRightSide(wxSizer* right_side_sizer)
{
	wxPanel* right_side_panel = new wxPanel(this);
#ifdef _DEBUG
	right_side_panel->SetBackgroundColour(wxColor(150, 100, 180));
#else
	right_side_panel->SetBackgroundColour(wxColor(255, 255, 255));
#endif // _DEBUG

	wxBoxSizer* right_side_panel_sizer = new wxBoxSizer(wxVERTICAL);

	CreateSteppersControl(right_side_panel, right_side_panel_sizer);

	right_side_panel->SetSizer(right_side_panel_sizer);
	right_side_sizer->Add(right_side_panel, 1, wxEXPAND);
}

void cMain::CreateSteppersControl(wxPanel* right_side_panel, wxBoxSizer* right_side_panel_sizer)
{


	wxSizer* const sc_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, right_side_panel, "&Steppers Constrol");

	{
		wxSizer* const detector_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, right_side_panel, "&Detector");
		{
			/* Detector X */
			wxSizer* const x_detector = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&X");
			{
				/* Absolute */
				x_detector->Add(new wxStaticText(right_side_panel, wxID_ANY, wxT("Absolute:")), 0, wxALIGN_CENTER | wxRIGHT, 2);
				m_X_Detector->absolute_text_ctrl = new wxTextCtrl(right_side_panel, MainFrameVariables::ID_RIGHT_SC_DET_X_ABS);
				x_detector->Add(m_X_Detector->absolute_text_ctrl, 0, wxALIGN_CENTER);

				/* Relative */
				wxSize inc_dec_size = { 25, 25 };
				m_X_Detector->decrement_btn = new wxButton(right_side_panel, MainFrameVariables::ID_RIGHT_SC_DET_X_DEC, wxT("-"));
				m_X_Detector->decrement_btn->SetMaxSize(inc_dec_size);
				m_X_Detector->relative_text_ctrl = new wxTextCtrl(right_side_panel, MainFrameVariables::ID_RIGHT_SC_DET_X_REL);
				m_X_Detector->increment_btn = new wxButton(right_side_panel, MainFrameVariables::ID_RIGHT_SC_DET_X_INC, wxT("+"));
				m_X_Detector->increment_btn->SetMaxSize(inc_dec_size);

				x_detector->Add(new wxStaticText(right_side_panel, wxID_ANY, wxT("Relative:")), 0, wxALIGN_CENTER | wxLEFT, 5);
				x_detector->Add(m_X_Detector->decrement_btn, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				x_detector->Add(m_X_Detector->relative_text_ctrl, 0, wxALIGN_CENTER);
				x_detector->Add(m_X_Detector->increment_btn, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);

				/* Remaining controls */
				wxImage centerImage = wxImage(center_xpm);
				wxBitmap centerBitmap = wxBitmap(centerImage);
				m_X_Detector->center_btn = new wxBitmapButton(right_side_panel, MainFrameVariables::ID_RIGHT_SC_DET_X_CENTER, centerBitmap);
				wxImage homeImage = wxImage(home_xpm);
				wxBitmap homeBitmap = wxBitmap(homeImage);
				m_X_Detector->home_btn = new wxBitmapButton(right_side_panel, MainFrameVariables::ID_RIGHT_SC_DET_X_HOME, homeBitmap);

				x_detector->Add(m_X_Detector->center_btn, 0, wxALIGN_CENTER | wxLEFT, 5);
				x_detector->Add(m_X_Detector->home_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
			}
			detector_static_box_sizer->Add(x_detector, 0, wxEXPAND);

			/* Detector Y */
			wxSizer* const y_detector = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Y");
			detector_static_box_sizer->Add(y_detector, 0, wxEXPAND);

			/* Detector Z */
			wxSizer* const z_detector = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Z");
			detector_static_box_sizer->Add(z_detector, 0, wxEXPAND);
		}
		sc_static_box_sizer->Add(detector_static_box_sizer, 0, wxEXPAND);

		wxSizer* const optics_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, right_side_panel, "&Optics");
		{
			/* Optics X */
			wxSizer* const x_optics = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&X");
			optics_static_box_sizer->Add(x_optics, 0, wxEXPAND);

			/* Optics Y */
			wxSizer* const y_optics = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Y");
			optics_static_box_sizer->Add(y_optics, 0, wxEXPAND);

			/* Optics Z */
			wxSizer* const z_optics = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Z");
			optics_static_box_sizer->Add(z_optics, 0, wxEXPAND);
		}
		sc_static_box_sizer->Add(optics_static_box_sizer, 0, wxEXPAND);
	}
	right_side_panel_sizer->Add(sc_static_box_sizer, 1, wxEXPAND | wxLEFT | wxRIGHT, 2);
}
