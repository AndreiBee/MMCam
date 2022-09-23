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
	m_Y_Detector = std::make_unique<MainFrameVariables::StepperControl>();
	m_Z_Detector = std::make_unique<MainFrameVariables::StepperControl>();
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

	wxSize absolute_text_ctrl_size = { 54, 20 }, relative_text_ctrl_size = {absolute_text_ctrl_size};
	wxSize set_btn_size = { 35, 20 };
	wxSize inc_dec_size = { 20, 20 };

	/* Center bitmap */
	wxImage centerImage = wxImage(center_xpm);
	wxBitmap centerBitmap = wxBitmap(centerImage);
	/* Home bitmap */
	wxImage homeImage = wxImage(home_xpm);
	wxBitmap homeBitmap = wxBitmap(homeImage);
	{
		wxSizer* const detector_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, right_side_panel, "&Detector");
		{
			/* Detector X */
			wxSizer* const x_detector = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&X");
			{
				/* Absolute */
				{
					wxSizer* const abs_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Absolute [mm]");
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					abs_val.SetMin(-1000.0);
					abs_val.SetMax(1000.0);
					m_X_Detector->absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE, 
						abs_val
					);

					m_X_Detector->set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_X_Detector->set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_X_Detector->absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_X_Detector->set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					x_detector->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_X_Detector->decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_X_Detector->decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					rel_val.SetMin(-1000.0);
					rel_val.SetMax(1000.0);
					m_X_Detector->relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_DET_X_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_X_Detector->increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_X_Detector->increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_X_Detector->decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_X_Detector->relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_X_Detector->increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					x_detector->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}


				/* Global positioning controls */
				{
					m_X_Detector->center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_X_Detector->center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_X_Detector->home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_X_Detector->home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_X_Detector->center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_X_Detector->home_btn, 0, wxALIGN_CENTER);

					x_detector->Add(jump_sizer, 0, wxALIGN_CENTER);

				}
			}
			detector_static_box_sizer->Add(x_detector, 0, wxEXPAND);

			/* Detector Y */
			wxSizer* const y_detector = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Y");
			{
				/* Absolute */
				{
					wxSizer* const abs_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Absolute [mm]");
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					abs_val.SetMin(-1000.0);
					abs_val.SetMax(1000.0);
					m_Y_Detector->absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE, 
						abs_val
					);

					m_Y_Detector->set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_Y_Detector->set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_Y_Detector->absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_Y_Detector->set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					y_detector->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_Y_Detector->decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Y_Detector->decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					rel_val.SetMin(-1000.0);
					rel_val.SetMax(1000.0);
					m_Y_Detector->relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_DET_Y_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_Y_Detector->increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Y_Detector->increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_Y_Detector->decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_Y_Detector->relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_Y_Detector->increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					y_detector->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}


				/* Global positioning controls */
				{
					m_Y_Detector->center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Y_Detector->center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_Y_Detector->home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Y_Detector->home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_Y_Detector->center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_Y_Detector->home_btn, 0, wxALIGN_CENTER);

					y_detector->Add(jump_sizer, 0, wxALIGN_CENTER);

				}
			}
			detector_static_box_sizer->Add(y_detector, 0, wxEXPAND);

			/* Detector Z */
			wxSizer* const z_detector = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Z");
			{
				/* Absolute */
				{
					wxSizer* const abs_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Absolute [mm]");
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					abs_val.SetMin(-1000.0);
					abs_val.SetMax(1000.0);
					m_Z_Detector->absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE, 
						abs_val
					);

					m_Z_Detector->set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_Z_Detector->set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_Z_Detector->absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_Z_Detector->set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					z_detector->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_Z_Detector->decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Z_Detector->decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					rel_val.SetMin(-1000.0);
					rel_val.SetMax(1000.0);
					m_Z_Detector->relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_DET_Z_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_Z_Detector->increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Z_Detector->increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_Z_Detector->decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_Z_Detector->relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_Z_Detector->increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					z_detector->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}


				/* Global positioning controls */
				{
					m_Z_Detector->center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Z_Detector->center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_Z_Detector->home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Z_Detector->home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_Z_Detector->center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_Z_Detector->home_btn, 0, wxALIGN_CENTER);

					z_detector->Add(jump_sizer, 0, wxALIGN_CENTER);
				}
			}

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
