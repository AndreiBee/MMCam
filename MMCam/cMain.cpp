#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_CLOSE(cMain::OnExit)
	EVT_MENU(MainFrameVariables::ID_MENUBAR_FILE_QUIT, cMain::OnExit)
	EVT_MENU(MainFrameVariables::ID_MENUBAR_EDIT_SETTINGS, cMain::OnOpenSettings)
	EVT_MENU(MainFrameVariables::ID_MENUBAR_WINDOW_FULLSCREEN, cMain::OnFullScreen)
	EVT_MAXIMIZE(cMain::OnMaximizeButton)
	/* Detector X */
	EVT_TEXT_ENTER(MainFrameVariables::ID_RIGHT_SC_DET_X_ABS_TE_CTL, cMain::OnEnterTextCtrlDetectorXAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_X_SET_BTN, cMain::OnSetDetectorXAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_X_CENTER_BTN, cMain::OnCenterDetectorX)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_X_HOME_BTN, cMain::OnHomeDetectorX)
	/* Detector Y */
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Y_SET_BTN, cMain::OnSetDetectorYAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Y_CENTER_BTN, cMain::OnCenterDetectorY)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Y_HOME_BTN, cMain::OnHomeDetectorY)
	/* Detector Z */
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Z_SET_BTN, cMain::OnSetDetectorZAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Z_CENTER_BTN, cMain::OnCenterDetectorZ)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Z_HOME_BTN, cMain::OnHomeDetectorZ)
	/* Optics Y */
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Y_SET_BTN, cMain::OnSetOpticsYAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Y_CENTER_BTN, cMain::OnCenterOpticsY)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Y_HOME_BTN, cMain::OnHomeOpticsY)
	/* Camera */
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_CAM_PREVIEW_BTN, cMain::OnPreviewCameraImage)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_MT_OUT_FLD_BTN, cMain::OnSetOutDirectoryBtn)
wxEND_EVENT_TABLE()

cMain::cMain(const wxString& title_) 
	: wxFrame(NULL, wxID_ANY, title_)
{
	CreateMainFrame();
	InitDefaultStateWidgets();
	CenterOnScreen();

	Show();
#ifdef _DEBUG
	wxCommandEvent art_evt(wxEVT_MENU, MainFrameVariables::ID_MENUBAR_EDIT_SETTINGS);
	ProcessEvent(art_evt);
#endif // _DEBUG
}

void cMain::CreateMainFrame()
{
	InitComponents();
	CreateMenuBarOnFrame();
	CreateLeftAndRightSide();
}

void cMain::InitComponents()
{
	/* Settings Frame */
	m_Settings = new cSettings(this);
	/* Detector */
	m_X_Detector = std::make_unique<MainFrameVariables::StepperControl>();
	m_Y_Detector = std::make_unique<MainFrameVariables::StepperControl>();
	m_Z_Detector = std::make_unique<MainFrameVariables::StepperControl>();
	/* Optics */
	m_X_Optics = std::make_unique<MainFrameVariables::StepperControl>();
	m_Y_Optics = std::make_unique<MainFrameVariables::StepperControl>();
	m_Z_Optics = std::make_unique<MainFrameVariables::StepperControl>();
	/* Measurement */
	m_FirstStage = std::make_unique<MainFrameVariables::MeasurementStage>();
	m_SecondStage = std::make_unique<MainFrameVariables::MeasurementStage>();
}

void cMain::CreateMenuBarOnFrame()
{
	m_MenuBar = new MainFrameVariables::MenuBar();
	this->SetMenuBar(m_MenuBar->menu_bar);

	// File Menu
	m_MenuBar->menu_file->Append(MainFrameVariables::ID_MENUBAR_FILE_QUIT, wxT("Quit\tCtrl+Q"));
	m_MenuBar->menu_bar->Append(m_MenuBar->menu_file, wxT("&File"));

	// Edit Menu
	m_MenuBar->menu_edit->Append(MainFrameVariables::ID_MENUBAR_EDIT_SETTINGS, wxT("Settings\tCtrl+S"));
	// Append Edit Menu to the Menu Bar
	m_MenuBar->menu_bar->Append(m_MenuBar->menu_edit, wxT("&Edit"));

	// Window Menu
	m_MenuBar->menu_window->Append(MainFrameVariables::ID_MENUBAR_WINDOW_FULLSCREEN, wxT("Full screen mode\tF11"), wxEmptyString, wxITEM_CHECK);
	// Append Window Menu to the Menu Bar
	m_MenuBar->menu_bar->Append(m_MenuBar->menu_window, wxT("&Window"));

	// Help Menu
	m_MenuBar->menu_help->Append(MainFrameVariables::ID_MENUBAR_HELP_ABOUT, wxT("About MMCam\tF1"));
	m_MenuBar->menu_bar->Append(m_MenuBar->menu_help, wxT("&Help"));
}

void cMain::InitDefaultStateWidgets()
{
	float default_absolute_value{ 0.0f }, default_relative_value{ 1.0f };
	/* Disabling Detector Widgets */
	{
		/* X */
		{
			m_X_Detector->absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_X_Detector->relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			//m_X_Detector->DisableAllControls();
		}
		/* Y */
		{
			m_Y_Detector->absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_Y_Detector->relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			//m_Y_Detector->DisableAllControls();
		}
		/* Z */
		{
			m_Z_Detector->absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_Z_Detector->relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			//m_Z_Detector->DisableAllControls();
		}
	}
	/* Disabling Optics Widgets */
	{
		/* X */
		{
			m_X_Optics->absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_X_Optics->relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			m_X_Optics->DisableAllControls();
		}
		/* Y */
		{
			m_Y_Optics->absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_Y_Optics->relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			//m_Y_Optics->DisableAllControls();
		}
		/* Z */
		{
			m_Z_Optics->absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_Z_Optics->relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			m_Z_Optics->DisableAllControls();
		}
	}
	/* Disabling Measurement Controls */
	{
		//m_OutDirTextCtrl->Disable();
		//m_OutDirBtn->Disable();

		float default_start{ 0.0f }, default_step{ 1.0f }, default_finish{ 24.0f };

		/* First Stage */
		{
			m_FirstStage->start->ChangeValue(wxString::Format(wxT("%.3f"), default_start));
			m_FirstStage->step->ChangeValue(wxString::Format(wxT("%.3f"), default_step));
			m_FirstStage->finish->ChangeValue(wxString::Format(wxT("%.3f"), default_finish));
			m_FirstStage->DisableAllControls();
		}
		/* Second Stage */
		{
			m_SecondStage->start->ChangeValue(wxString::Format(wxT("%.3f"), default_start));
			m_SecondStage->step->ChangeValue(wxString::Format(wxT("%.3f"), default_step));
			m_SecondStage->finish->ChangeValue(wxString::Format(wxT("%.3f"), default_finish));
			m_SecondStage->DisableAllControls();
		}
	}
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
	m_CamPreview = std::make_unique<cCamPreview>(this, left_side_sizer);
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
	CreateCameraControls(right_side_panel, right_side_panel_sizer);
	CreateMeasurement(right_side_panel, right_side_panel_sizer);

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
			x_detector->AddStretchSpacer();
			{
				/* Absolute */
				{
					wxSizer* const abs_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Absolute [mm]");
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_X_Detector->absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
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
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
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
			x_detector->AddStretchSpacer();
			detector_static_box_sizer->Add(x_detector, 0, wxEXPAND);

			/* Detector Y */
			wxSizer* const y_detector = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Y");
			y_detector->AddStretchSpacer();
			{
				/* Absolute */
				{
					wxSizer* const abs_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Absolute [mm]");
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_Y_Detector->absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
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
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
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
			y_detector->AddStretchSpacer();
			detector_static_box_sizer->Add(y_detector, 0, wxEXPAND);

			/* Detector Z */
			wxSizer* const z_detector = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Z");
			z_detector->AddStretchSpacer();
			{
				/* Absolute */
				{
					wxSizer* const abs_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Absolute [mm]");
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_Z_Detector->absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
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
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
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
			z_detector->AddStretchSpacer();
			detector_static_box_sizer->Add(z_detector, 0, wxEXPAND);
		}
		sc_static_box_sizer->Add(detector_static_box_sizer, 0, wxEXPAND);

		wxSizer* const optics_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, right_side_panel, "&Optics");
		{
			/* Optics X */
			wxSizer* const x_optics = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&X");
			x_optics->AddStretchSpacer();
			{
				/* Absolute */
				{
					wxSizer* const abs_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Absolute [mm]");
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_X_Optics->absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
						abs_val
					);

					m_X_Optics->set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_X_Optics->set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_X_Optics->absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_X_Optics->set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					x_optics->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_X_Optics->decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_X_Optics->decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
					m_X_Optics->relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_OPT_X_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_X_Optics->increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_X_Optics->increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_X_Optics->decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_X_Optics->relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_X_Optics->increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					x_optics->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}

				/* Global positioning controls */
				{
					m_X_Optics->center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_X_Optics->center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_X_Optics->home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_X_Optics->home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_X_Optics->center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_X_Optics->home_btn, 0, wxALIGN_CENTER);

					x_optics->Add(jump_sizer, 0, wxALIGN_CENTER);
				}
			}
			x_optics->AddStretchSpacer();
			optics_static_box_sizer->Add(x_optics, 0, wxEXPAND);

			/* Optics Y */
			wxSizer* const y_optics = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Y");
			y_optics->AddStretchSpacer();
			{
				/* Absolute */
				{
					wxSizer* const abs_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Absolute [mm]");
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_Y_Optics->absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
						abs_val
					);

					m_Y_Optics->set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_Y_Optics->set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_Y_Optics->absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_Y_Optics->set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					y_optics->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_Y_Optics->decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Y_Optics->decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
					m_Y_Optics->relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_Y_Optics->increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Y_Optics->increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_Y_Optics->decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_Y_Optics->relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_Y_Optics->increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					y_optics->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}

				/* Global positioning controls */
				{
					m_Y_Optics->center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Y_Optics->center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_Y_Optics->home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Y_Optics->home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_Y_Optics->center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_Y_Optics->home_btn, 0, wxALIGN_CENTER);

					y_optics->Add(jump_sizer, 0, wxALIGN_CENTER);
				}
			}
			y_optics->AddStretchSpacer();
			optics_static_box_sizer->Add(y_optics, 0, wxEXPAND);

			/* Optics Z */
			wxSizer* const z_optics = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Z");
			z_optics->AddStretchSpacer();
			{
				/* Absolute */
				{
					wxSizer* const abs_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Absolute [mm]");
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_Z_Optics->absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
						abs_val
					);

					m_Z_Optics->set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_Z_Optics->set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_Z_Optics->absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_Z_Optics->set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					z_optics->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_Z_Optics->decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Z_Optics->decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
					m_Z_Optics->relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_Z_Optics->increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Z_Optics->increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_Z_Optics->decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_Z_Optics->relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_Z_Optics->increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					z_optics->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}

				/* Global positioning controls */
				{
					m_Z_Optics->center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Z_Optics->center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_Z_Optics->home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Z_Optics->home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_Z_Optics->center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_Z_Optics->home_btn, 0, wxALIGN_CENTER);

					z_optics->Add(jump_sizer, 0, wxALIGN_CENTER);
				}
			}
			z_optics->AddStretchSpacer();
			optics_static_box_sizer->Add(z_optics, 0, wxEXPAND);
		}
		sc_static_box_sizer->Add(optics_static_box_sizer, 0, wxEXPAND);
	}
	right_side_panel_sizer->Add(sc_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);
}

void cMain::CreateCameraControls(wxPanel* right_side_panel, wxBoxSizer* right_side_panel_sizer)
{
	wxSizer* const cam_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Camera");

	{
		wxSizer* const settings_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Settings");
		{
			wxSizer* const exposure_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Exposure [us]");

			wxIntegerValidator<int>	exposure_val(NULL, wxNUM_VAL_ZERO_AS_BLANK);
			exposure_val.SetMin(1);
			exposure_val.SetMax(10000000);

			wxSize exposure_size = { 64, 20 };

			m_CamExposure = std::make_unique<wxTextCtrl>(
				right_side_panel, 
				MainFrameVariables::ID_RIGHT_CAM_EXPOSURE_TE_CTL, 
				wxT("10000000"), 
				wxDefaultPosition, 
				exposure_size, 
				wxTE_CENTRE, 
				exposure_val);

			exposure_static_box_sizer->AddStretchSpacer();
			exposure_static_box_sizer->Add(m_CamExposure.get(), 0, wxEXPAND);
			exposure_static_box_sizer->AddStretchSpacer();

			settings_static_box_sizer->Add(exposure_static_box_sizer, 0, wxEXPAND);
		}
		cam_static_box_sizer->Add(settings_static_box_sizer, 0, wxEXPAND);

		/* Preview */
		{
			m_CamPreviewBtn = std::make_unique<wxButton>(
				right_side_panel,
				MainFrameVariables::ID_RIGHT_CAM_PREVIEW_BTN,
				wxT("Preview"), 
				wxDefaultPosition, 
				wxDefaultSize);
			cam_static_box_sizer->AddStretchSpacer();
			cam_static_box_sizer->Add(m_CamPreviewBtn.get(), 0, wxALIGN_CENTER | wxRIGHT, 2);
		}
	}

	right_side_panel_sizer->Add(cam_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);
}

void cMain::CreateMeasurement(wxPanel* right_side_panel, wxBoxSizer* right_side_panel_sizer)
{
	wxSizer* const mmt_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, right_side_panel, "&Measurement");

	/* Output directory */
	{
		wxSizer* const out_dir_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Output directory");
		
		m_OutDirTextCtrl = std::make_unique<wxTextCtrl>(
			right_side_panel, 
			MainFrameVariables::ID_RIGHT_MT_OUT_FLD_TE_CTL, 
			wxT("Save directory..."), 
			wxDefaultPosition, 
			wxDefaultSize, 
			wxTE_LEFT | wxTE_READONLY
			);

		m_OutDirBtn = std::make_unique<wxButton>(
			right_side_panel, 
			MainFrameVariables::ID_RIGHT_MT_OUT_FLD_BTN, 
			wxT("Select folder"));
		m_OutDirBtn->SetToolTip(wxT("Set the output directory"));

		out_dir_static_box_sizer->Add(m_OutDirTextCtrl.get(), 1, wxEXPAND | wxRIGHT, 4);
		//out_dir_static_box_sizer->AddStretchSpacer();
		out_dir_static_box_sizer->Add(m_OutDirBtn.get(), 0, wxALIGN_CENTER);

		mmt_static_box_sizer->Add(out_dir_static_box_sizer, 0, wxEXPAND);
	}

	wxSize start_text_ctrl_size = { 54, 20 }, step_text_ctrl_size = {start_text_ctrl_size}, finish_text_ctrl_size{start_text_ctrl_size};

	{
		wxSizer* const directions_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, right_side_panel, "&Directions");

		/* First axis */
		{
			wxSizer* const first_axis_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&First axis");

			/* Stage */
			{
				wxSizer* const stage_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Stage");
				m_FirstStage->stage = new wxChoice(
					right_side_panel, 
					MainFrameVariables::ID_RIGHT_MT_FIRST_STAGE_CHOICE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_FirstStage->motors);
				m_FirstStage->stage->SetSelection(0);
				stage_static_box_sizer->Add(m_FirstStage->stage, 0, wxEXPAND);
				first_axis_static_box_sizer->Add(stage_static_box_sizer, 0, wxEXPAND);
			}

			/* Start */
			{
				wxSizer* const start_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Start");

				wxFloatingPointValidator<float>	start_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
				start_val.SetMin(-1000.0);
				start_val.SetMax(1000.0);

				m_FirstStage->start = new wxTextCtrl(
					right_side_panel,
					MainFrameVariables::ID_RIGHT_MT_FIRST_STAGE_START,
					wxT("123.456"), 
					wxDefaultPosition, 
					start_text_ctrl_size, 
					wxTE_CENTRE, 
					start_val);

				start_static_box_sizer->Add(m_FirstStage->start, 0, wxEXPAND);

				first_axis_static_box_sizer->Add(start_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);
			}

			/* Step */
			{
				wxSizer* const step_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Step");

				wxFloatingPointValidator<float>	step_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
				step_val.SetMin(-1000.0);
				step_val.SetMax(1000.0);

				m_FirstStage->step = new wxTextCtrl(
					right_side_panel, 
					MainFrameVariables::ID_RIGHT_MT_FIRST_STAGE_STEP,
					wxT("123.456"), 
					wxDefaultPosition, 
					step_text_ctrl_size, 
					wxTE_CENTRE, 
					step_val);
				
				step_static_box_sizer->Add(m_FirstStage->step, 0, wxEXPAND);
				first_axis_static_box_sizer->Add(step_static_box_sizer, 0, wxEXPAND | wxRIGHT, 2);
			}

			/* Finish */
			{
				wxSizer* const finish_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Finish");

				wxFloatingPointValidator<float>	finish_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
				finish_val.SetMin(-1000.0);
				finish_val.SetMax(1000.0);

				m_FirstStage->finish = new wxTextCtrl(
					right_side_panel, 
					MainFrameVariables::ID_RIGHT_MT_FIRST_STAGE_FINISH,
					wxT("123.456"), 
					wxDefaultPosition, 
					finish_text_ctrl_size, 
					wxTE_CENTRE, 
					finish_val);

				finish_static_box_sizer->Add(m_FirstStage->finish, 0, wxEXPAND);
				first_axis_static_box_sizer->Add(finish_static_box_sizer, 0, wxEXPAND);
			}

			directions_static_box_sizer->Add(first_axis_static_box_sizer, 0, wxEXPAND);
		}

		/* Second axis */
		{
			wxSizer* const second_axis_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Second axis");

			/* Stage */
			{
				wxSizer* const stage_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Stage");
				m_SecondStage->stage = new wxChoice(
					right_side_panel, 
					MainFrameVariables::ID_RIGHT_MT_SECOND_STAGE_CHOICE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_SecondStage->motors);
				m_SecondStage->stage->SetSelection(1);
				stage_static_box_sizer->Add(m_SecondStage->stage, 0, wxEXPAND);
				second_axis_static_box_sizer->Add(stage_static_box_sizer, 0, wxEXPAND);
			}

			/* Start */
			{
				wxSizer* const start_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Start");

				wxFloatingPointValidator<float>	start_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
				start_val.SetMin(-1000.0);
				start_val.SetMax(1000.0);

				m_SecondStage->start = new wxTextCtrl(
					right_side_panel,
					MainFrameVariables::ID_RIGHT_MT_SECOND_STAGE_START,
					wxT("123.456"), 
					wxDefaultPosition, 
					start_text_ctrl_size, 
					wxTE_CENTRE, 
					start_val);

				start_static_box_sizer->Add(m_SecondStage->start, 0, wxEXPAND);

				second_axis_static_box_sizer->Add(start_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);
			}

			/* Step */
			{
				wxSizer* const step_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Step");

				wxFloatingPointValidator<float>	step_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
				step_val.SetMin(-1000.0);
				step_val.SetMax(1000.0);

				m_SecondStage->step = new wxTextCtrl(
					right_side_panel, 
					MainFrameVariables::ID_RIGHT_MT_SECOND_STAGE_STEP,
					wxT("123.456"), 
					wxDefaultPosition, 
					step_text_ctrl_size, 
					wxTE_CENTRE, 
					step_val);
				
				step_static_box_sizer->Add(m_SecondStage->step, 0, wxEXPAND);
				second_axis_static_box_sizer->Add(step_static_box_sizer, 0, wxEXPAND | wxRIGHT, 2);
			}

			/* Finish */
			{
				wxSizer* const finish_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Finish");

				wxFloatingPointValidator<float>	finish_val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
				finish_val.SetMin(-1000.0);
				finish_val.SetMax(1000.0);

				m_SecondStage->finish = new wxTextCtrl(
					right_side_panel, 
					MainFrameVariables::ID_RIGHT_MT_SECOND_STAGE_FINISH,
					wxT("123.456"), 
					wxDefaultPosition, 
					finish_text_ctrl_size, 
					wxTE_CENTRE, 
					finish_val);

				finish_static_box_sizer->Add(m_SecondStage->finish, 0, wxEXPAND);
				second_axis_static_box_sizer->Add(finish_static_box_sizer, 0, wxEXPAND);
			}

			directions_static_box_sizer->Add(second_axis_static_box_sizer, 0, wxEXPAND);
		}

		mmt_static_box_sizer->Add(directions_static_box_sizer, 0, wxEXPAND);
	}

	right_side_panel_sizer->Add(mmt_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);
}

void cMain::OnPreviewCameraImage(wxCommandEvent& evt)
{
	wxString exposure_time_str = m_CamExposure->GetValue().IsEmpty() ? wxString("0") : m_CamExposure->GetValue();
	int exposure_time = abs(wxAtoi(exposure_time_str));
	m_CamPreview->SetCameraCapturedImage(exposure_time);
}

void cMain::OnSetOutDirectoryBtn(wxCommandEvent& evt)
{
	wxDirDialog save_dialog(NULL, "Choose save directory", "",
		wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

	if (save_dialog.ShowModal() == wxID_CANCEL)
		return;

	m_OutDirTextCtrl->SetValue(save_dialog.GetPath());
}

void cMain::OnOpenSettings(wxCommandEvent& evt)
{
	m_CamPreview->SetFocus();
	m_Settings->ShowModal();
	if (!m_Settings->IsActive())
	{
		UpdateStagePositions();
		EnableUsedAndDisableNonUsedMotors();
	}
}

void cMain::OnFullScreen(wxCommandEvent& evt)
{
	if (!IsMaximized())
	{
		Maximize(true);
		m_MenuBar->menu_window->Check(MainFrameVariables::ID_MENUBAR_WINDOW_FULLSCREEN, true);
	}
	else
	{
		Maximize(false);
		m_MenuBar->menu_window->Check(MainFrameVariables::ID_MENUBAR_WINDOW_FULLSCREEN, false);
	}
}

void cMain::OnMaximizeButton(wxMaximizeEvent& evt)
{
	if (m_MenuBar->menu_window->IsChecked(MainFrameVariables::ID_MENUBAR_WINDOW_FULLSCREEN))
	{
		m_MenuBar->menu_window->Check(MainFrameVariables::ID_MENUBAR_WINDOW_FULLSCREEN, false);
	}
	else
	{
		m_MenuBar->menu_window->Check(MainFrameVariables::ID_MENUBAR_WINDOW_FULLSCREEN, true);
	}
}

void cMain::OnExit(wxCloseEvent& evt)
{
#ifndef _DEBUG
	if (evt.CanVeto())
	{
		if (wxMessageBox("Are you sure?",
			"Exit application",
			wxICON_QUESTION | wxYES_NO) != wxYES)
		{
			evt.Veto();
			return;
		}
	}
#endif // !_DEBUG

	Destroy();  // you may also do:  event.Skip();
	evt.Skip();
	// since the default event handler does call Destroy(), too
}

void cMain::UpdateStagePositions()
{
	m_X_Detector->absolute_text_ctrl->SetValue(wxString::Format(wxT("%.3f"), m_Settings->GetActualDetectorXStagePos()));
	m_Y_Detector->absolute_text_ctrl->SetValue(wxString::Format(wxT("%.3f"), m_Settings->GetActualDetectorYStagePos()));
	m_Z_Detector->absolute_text_ctrl->SetValue(wxString::Format(wxT("%.3f"), m_Settings->GetActualDetectorZStagePos()));

	m_Y_Optics->absolute_text_ctrl->SetValue(wxString::Format(wxT("%.3f"), m_Settings->GetActualOpticsYStagePos()));
}

void cMain::OnExit(wxCommandEvent& evt)
{
	wxCloseEvent artificialExit(wxEVT_CLOSE_WINDOW);
	ProcessEvent(artificialExit);
}

void cMain::EnableUsedAndDisableNonUsedMotors()
{
	/* Detector X */
	if (m_Settings->DetectorXHasSerialNumber()) m_X_Detector->EnableAllControls();
	else m_X_Detector->DisableAllControls();
	/* Detector Y */
	if (m_Settings->DetectorYHasSerialNumber()) m_Y_Detector->EnableAllControls();
	else m_Y_Detector->DisableAllControls();
	/* Detector Z */
	if (m_Settings->DetectorZHasSerialNumber()) m_Z_Detector->EnableAllControls();
	else m_Z_Detector->DisableAllControls();
	/* Optics X */
	if (m_Settings->OpticsXHasSerialNumber()) m_X_Optics->EnableAllControls();
	else m_X_Optics->DisableAllControls();
	/* Optics Y */
	if (m_Settings->OpticsYHasSerialNumber()) m_Y_Optics->EnableAllControls();
	else m_Y_Optics->DisableAllControls();
	/* Optics Z */
	if (m_Settings->OpticsZHasSerialNumber()) m_Z_Optics->EnableAllControls();
	else m_Z_Optics->DisableAllControls();
}

void cMain::OnEnterTextCtrlDetectorXAbsPos(wxCommandEvent& evt)
{
	wxCommandEvent enter_evt(wxEVT_BUTTON, MainFrameVariables::ID_RIGHT_SC_DET_X_ABS_TE_CTL);
	ProcessEvent(enter_evt);
}

void cMain::OnSetDetectorXAbsPos(wxCommandEvent& evt)
{
	double absolute_position{};
	if (!m_X_Detector->absolute_text_ctrl->GetValue().ToDouble(&absolute_position)) return;
	m_Settings->GoToAbsDetectorX((float)absolute_position);
}

void cMain::OnCenterDetectorX(wxCommandEvent& evt)
{
	m_X_Detector->absolute_text_ctrl->SetValue(
		wxString::Format(
			wxT("%.3f"), 
			m_Settings->CenterDetectorX()
		));
}

void cMain::OnHomeDetectorX(wxCommandEvent& evt)
{	
	m_X_Detector->absolute_text_ctrl->ChangeValue(
		wxString::Format(
			wxT("%.3f"), 
			m_Settings->HomeDetectorX()
		));
}

void cMain::OnSetDetectorYAbsPos(wxCommandEvent& evt)
{	
	double absolute_position{};
	if (!m_Y_Detector->absolute_text_ctrl->GetValue().ToDouble(&absolute_position)) return;
	m_Settings->GoToAbsDetectorY((float)absolute_position);
}

void cMain::OnCenterDetectorY(wxCommandEvent& evt)
{
	m_Y_Detector->absolute_text_ctrl->SetValue(
		wxString::Format(
			wxT("%.3f"), 
			m_Settings->CenterDetectorY()
		));
}

void cMain::OnHomeDetectorY(wxCommandEvent& evt)
{
	m_Y_Detector->absolute_text_ctrl->SetValue(
		wxString::Format(
			wxT("%.3f"), 
			m_Settings->HomeDetectorY()
		));
}

void cMain::OnSetDetectorZAbsPos(wxCommandEvent& evt)
{	
	double absolute_position{};
	if (!m_Z_Detector->absolute_text_ctrl->GetValue().ToDouble(&absolute_position)) return;
	m_Settings->GoToAbsDetectorZ((float)absolute_position);
}

void cMain::OnCenterDetectorZ(wxCommandEvent& evt)
{
	m_Z_Detector->absolute_text_ctrl->SetValue(
		wxString::Format(
			wxT("%.3f"), 
			m_Settings->CenterDetectorZ()
		));
}

void cMain::OnHomeDetectorZ(wxCommandEvent& evt)
{
	m_Z_Detector->absolute_text_ctrl->SetValue(
		wxString::Format(
			wxT("%.3f"), 
			m_Settings->HomeDetectorZ()
		));
}

void cMain::OnSetOpticsYAbsPos(wxCommandEvent& evt)
{
	double absolute_position{};
	if (!m_Y_Optics->absolute_text_ctrl->GetValue().ToDouble(&absolute_position)) return;
	m_Settings->GoToAbsOpticsY((float)absolute_position);
}

void cMain::OnCenterOpticsY(wxCommandEvent& evt)
{
	m_Y_Optics->absolute_text_ctrl->SetValue(
		wxString::Format(
			wxT("%.3f"), 
			m_Settings->CenterOpticsY()
		));
}

void cMain::OnHomeOpticsY(wxCommandEvent& evt)
{
	m_Y_Optics->absolute_text_ctrl->SetValue(
		wxString::Format(
			wxT("%.3f"), 
			m_Settings->HomeOpticsY()
		));
}

cMain::~cMain()
{
	delete m_MenuBar;
}
