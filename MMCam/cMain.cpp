#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_CLOSE(cMain::OnExit)
	EVT_MENU(MainFrameVariables::ID_MENUBAR_FILE_QUIT, cMain::OnExit)
	EVT_MENU(MainFrameVariables::ID_RIGHT_CAM_SINGLE_SHOT_BTN, cMain::OnSingleShotCameraImage)
	EVT_MENU(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, cMain::OnStartStopLiveCapturingMenu)
	EVT_MENU(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_DARK_MODE, cMain::OnEnableDarkMode)
	EVT_MENU(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_FWHM_DISPLAYING, cMain::OnEnableFWHMDisplaying)
	EVT_MENU(MainFrameVariables::ID_MENUBAR_EDIT_SETTINGS, cMain::OnOpenSettings)
	EVT_MENU(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, cMain::OnCrossHairButton)
	EVT_MENU(MainFrameVariables::ID_MENUBAR_TOOLS_VALUE_DISPLAYING, cMain::OnValueDisplayingCheck)
	EVT_MENU(MainFrameVariables::ID_MENUBAR_WINDOW_FULLSCREEN, cMain::OnFullScreen)
	EVT_MAXIMIZE(cMain::OnMaximizeButton)
	/* Detector X */
	EVT_TEXT_ENTER(MainFrameVariables::ID_RIGHT_SC_DET_X_ABS_TE_CTL, cMain::OnEnterTextCtrlDetectorXAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_X_SET_BTN, cMain::OnSetDetectorXAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_X_DEC_BTN, cMain::OnDecrementDetectorXAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_X_INC_BTN, cMain::OnIncrementDetectorXAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_X_CENTER_BTN, cMain::OnCenterDetectorX)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_X_HOME_BTN, cMain::OnHomeDetectorX)
	/* Detector Y */
	EVT_TEXT_ENTER(MainFrameVariables::ID_RIGHT_SC_DET_Y_ABS_TE_CTL, cMain::OnEnterTextCtrlDetectorYAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Y_SET_BTN, cMain::OnSetDetectorYAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Y_DEC_BTN, cMain::OnDecrementDetectorYAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Y_INC_BTN, cMain::OnIncrementDetectorYAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Y_CENTER_BTN, cMain::OnCenterDetectorY)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Y_HOME_BTN, cMain::OnHomeDetectorY)
	/* Detector Z */
	EVT_TEXT_ENTER(MainFrameVariables::ID_RIGHT_SC_DET_Z_ABS_TE_CTL, cMain::OnEnterTextCtrlDetectorZAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Z_SET_BTN, cMain::OnSetDetectorZAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Z_DEC_BTN, cMain::OnDecrementDetectorZAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Z_INC_BTN, cMain::OnIncrementDetectorZAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Z_CENTER_BTN, cMain::OnCenterDetectorZ)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_DET_Z_HOME_BTN, cMain::OnHomeDetectorZ)
	/* Optics X */
	EVT_TEXT_ENTER(MainFrameVariables::ID_RIGHT_SC_OPT_X_ABS_TE_CTL, cMain::OnEnterTextCtrlOpticsXAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_X_SET_BTN, cMain::OnSetOpticsXAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_X_DEC_BTN, cMain::OnDecrementOpticsXAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_X_INC_BTN, cMain::OnIncrementOpticsXAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_X_CENTER_BTN, cMain::OnCenterOpticsX)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_X_HOME_BTN, cMain::OnHomeOpticsX)
	/* Optics Y */
	EVT_TEXT_ENTER(MainFrameVariables::ID_RIGHT_SC_OPT_Y_ABS_TE_CTL, cMain::OnEnterTextCtrlOpticsYAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Y_SET_BTN, cMain::OnSetOpticsYAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Y_DEC_BTN, cMain::OnDecrementOpticsYAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Y_INC_BTN, cMain::OnIncrementOpticsYAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Y_CENTER_BTN, cMain::OnCenterOpticsY)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Y_HOME_BTN, cMain::OnHomeOpticsY)
	/* Optics Z */
	EVT_TEXT_ENTER(MainFrameVariables::ID_RIGHT_SC_OPT_Z_ABS_TE_CTL, cMain::OnEnterTextCtrlOpticsZAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Z_SET_BTN, cMain::OnSetOpticsZAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Z_DEC_BTN, cMain::OnDecrementOpticsZAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Z_INC_BTN, cMain::OnIncrementOpticsZAbsPos)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Z_CENTER_BTN, cMain::OnCenterOpticsZ)
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_SC_OPT_Z_HOME_BTN, cMain::OnHomeOpticsZ)
	/* Camera */
	EVT_CHOICE(MainFrameVariables::ID_RIGHT_CAM_MANUFACTURER_CHOICE, cMain::ChangeCameraManufacturerChoice)
	EVT_TEXT_ENTER(MainFrameVariables::ID_RIGHT_CAM_EXPOSURE_TE_CTL, cMain::ExposureValueChanged)

	EVT_BUTTON(MainFrameVariables::ID_RIGHT_CAM_SINGLE_SHOT_BTN, cMain::OnSingleShotCameraImage)

	EVT_TEXT(MainFrameVariables::ID_RIGHT_CAM_CROSS_HAIR_POS_X_TXT_CTRL, cMain::OnXPosCrossHairTextCtrl)
	EVT_TEXT(MainFrameVariables::ID_RIGHT_CAM_CROSS_HAIR_POS_Y_TXT_CTRL, cMain::OnYPosCrossHairTextCtrl)
	EVT_TOGGLEBUTTON(MainFrameVariables::ID_RIGHT_CAM_CROSS_HAIR_SET_POS_TGL_BTN, cMain::OnSetPosCrossHairTglBtn)
	/* Set Out Folder */
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_MT_OUT_FLD_BTN, cMain::OnSetOutDirectoryBtn)
	/* First Stage */
	EVT_CHOICE(MainFrameVariables::ID_RIGHT_MT_FIRST_STAGE_CHOICE, cMain::OnFirstStageChoice)
	/* Second Stage */
	EVT_CHOICE(MainFrameVariables::ID_RIGHT_MT_SECOND_STAGE_CHOICE, cMain::OnSecondStageChoice)
	/* Generate Report */
	EVT_BUTTON(MainFrameVariables::ID_RIGHT_MY_GENERATE_REPORT_BTN, cMain::OnGenerateReportBtn)
	/* Start Capturing */
	EVT_TOGGLEBUTTON(MainFrameVariables::ID_RIGHT_MT_START_STOP_MEASUREMENT, cMain::OnStartStopCapturingTglButton)
	/* Start\Stop Live Capturing */
	EVT_TOGGLEBUTTON(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, cMain::OnStartStopLiveCapturingTglBtn)

	/* Live Capturing */
	EVT_THREAD(MainFrameVariables::ID_THREAD_LIVE_CAPTURING, cMain::LiveCapturingThread)
	/* Progress */
	EVT_THREAD(MainFrameVariables::ID_THREAD_PROGRESS_CAPTURING, cMain::UpdateProgress)

wxEND_EVENT_TABLE()

cMain::cMain(const wxString& title_) 
	: wxFrame(NULL, wxID_ANY, title_)
{
#ifndef _DEBUG
	wxBusyCursor busy;
#endif // !_DEBUG

	wxArtProvider::Push(new wxMaterialDesignArtProvider);
	CreateMainFrame();
	InitDefaultStateWidgets();
	SetIcon(logo_xpm);

	/* Creating, but not showing ProgressBar */
	CreateProgressBar();
	m_ProgressBar->SetIcon(logo_xpm);

	CenterOnScreen();
	// Maximize application's window
	Maximize();
	Show();

	// Enable Dark Mode
	{
		m_MenuBar->menu_edit->Check(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_DARK_MODE, true);
		wxCommandEvent artEvt(wxEVT_MENU, MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_DARK_MODE);
		ProcessEvent(artEvt);
	}

	// Open Settings Menu
	{
		wxCommandEvent artEvt(wxEVT_MENU, MainFrameVariables::ID_MENUBAR_EDIT_SETTINGS);
		ProcessEvent(artEvt);
	}

#ifdef _DEBUG
	// Press Set Out Dir Button
	{
		wxCommandEvent artEvt(wxEVT_BUTTON, MainFrameVariables::ID_RIGHT_MT_OUT_FLD_BTN);
		ProcessEvent(artEvt);
	}
	// Press Generate Button
	//{
	//	wxCommandEvent artEvt(wxEVT_BUTTON, MainFrameVariables::ID_RIGHT_MY_GENERATE_REPORT_BTN);
	//	ProcessEvent(artEvt);
	//}
#endif // _DEBUG
	{
		//m_StartStopLiveCapturingTglBtn->SetValue(true);
		//wxCommandEvent art_start_live_capturing(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN);
		//ProcessEvent(art_start_live_capturing);
	}
}

//auto cMain::StopLiveCapturing() -> bool
//{
	//return m_StopLiveCapturing;
//}

void cMain::CreateMainFrame()
{
	InitComponents();
	CreateMenuBarOnFrame();
	CreateVerticalToolBar();
	CreateLeftAndRightSide();
}

void cMain::InitComponents()
{
	/* Settings Frame */
	m_Settings = std::make_unique<cSettings>(this);
	m_Settings->SetIcon(logo_xpm);
	/* Measurement */
	m_FirstStage = std::make_unique<MainFrameVariables::MeasurementStage>();
	//m_SecondStage = std::make_unique<MainFrameVariables::MeasurementStage>();
}

void cMain::CreateMenuBarOnFrame()
{
	m_MenuBar = std::make_unique<MainFrameVariables::MenuBar>();
	this->SetMenuBar(m_MenuBar->menu_bar);

	// File Menu
	m_MenuBar->menu_file->Append(MainFrameVariables::ID_MENUBAR_FILE_QUIT, wxT("Quit\tCtrl+Q"));
	// Append File Menu to the Menu Bar
	m_MenuBar->menu_bar->Append(m_MenuBar->menu_file, wxT("&File"));

	// Edit Menu
	m_MenuBar->menu_edit->Append(MainFrameVariables::ID_RIGHT_CAM_SINGLE_SHOT_BTN, wxT("Single Shot\tS"));
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_RIGHT_CAM_SINGLE_SHOT_BTN, false);
	m_MenuBar->menu_edit->AppendCheckItem(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, wxT("Start Live\tL"));
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, false);
	m_MenuBar->menu_edit->AppendCheckItem(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_DARK_MODE, wxT("Dark Mode"));
	m_MenuBar->menu_edit->AppendCheckItem(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_FWHM_DISPLAYING, wxT("FWHM Displaying\tF"));
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_FWHM_DISPLAYING, false);
	m_MenuBar->menu_edit->Append(MainFrameVariables::ID_MENUBAR_EDIT_SETTINGS, wxT("Settings\tCtrl+S"));
	// Append Edit Menu to the Menu Bar
	m_MenuBar->menu_bar->Append(m_MenuBar->menu_edit, wxT("&Edit"));

	// Intensity Profile SubMenu
	m_MenuBar->submenu_intensity_profile->AppendCheckItem(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, wxT("Crosshair\tC"));
	m_MenuBar->submenu_intensity_profile->Enable(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, false);
	// Append Submenu Selection Tools to the Tools Menu
	m_MenuBar->menu_tools->Append(wxID_ANY, wxT("&Intensity Profile"), m_MenuBar->submenu_intensity_profile);
	// Append Value Displaying Check
	m_MenuBar->menu_tools->Append(MainFrameVariables::ID_MENUBAR_TOOLS_VALUE_DISPLAYING, wxT("Value Displaying\tV"), wxEmptyString, wxITEM_CHECK);
	// Append Tools Menu to the Menu Bar
	m_MenuBar->menu_bar->Append(m_MenuBar->menu_tools, wxT("&Tools"));
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
	m_MenuBar->menu_tools->Check(MainFrameVariables::ID_MENUBAR_TOOLS_VALUE_DISPLAYING, true);
	m_CamPreview->SetValueDisplayingActive(true);
	m_IsValueDisplayingChecked = true;

	float default_absolute_value{ 0.0f }, default_relative_value{ 1.0f };
	/* Disabling Detector Widgets */
	{
		/* X */
		{
			m_Detector[0].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_Detector[0].relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			//m_X_Detector->DisableAllControls();
		}
		/* Y */
		{
			m_Detector[1].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_Detector[1].relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			//m_Y_Detector->DisableAllControls();
		}
		/* Z */
		{
			m_Detector[2].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_Detector[2].relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			//m_Z_Detector->DisableAllControls();
		}
	}
	/* Disabling Optics Widgets */
	{
		/* X */
		{
			m_Optics[0].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_Optics[0].relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			//m_X_Optics->DisableAllControls();
		}
		/* Y */
		{
			m_Optics[1].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_Optics[1].relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			//m_Y_Optics->DisableAllControls();
		}
		/* Z */
		{
			m_Optics[2].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_absolute_value));
			m_Optics[2].relative_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), default_relative_value));
			//m_Z_Optics->DisableAllControls();
		}
	}

	/* Disabling Measurement Controls */
	{
		//m_OutDirTextCtrl->Disable();
		//m_OutDirBtn->Disable();

		float default_start{ 0.0f }, default_step{ 0.1f }, default_finish{ 24.0f };

		/* First Stage */
		{
			m_FirstStage->start->ChangeValue(wxString::Format(wxT("%.3f"), default_start));
			m_FirstStage->step->ChangeValue(wxString::Format(wxT("%.3f"), default_step));
			m_FirstStage->finish->ChangeValue(wxString::Format(wxT("%.3f"), default_finish));
			m_FirstStage->DisableAllControls();
		}
		/* Second Stage */
		{
			//m_SecondStage->start->ChangeValue(wxString::Format(wxT("%.3f"), default_start));
			//m_SecondStage->step->ChangeValue(wxString::Format(wxT("%.3f"), default_step));
			//m_SecondStage->finish->ChangeValue(wxString::Format(wxT("%.3f"), default_finish));
			//m_SecondStage->DisableAllControls();
		}
		/* Start Capturing */
		m_StartStopMeasurementTglBtn->Disable();
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
	left_side_sizer->Add(m_VerticalToolBar->tool_bar, 0, wxEXPAND);
	auto input_args = std::make_unique<CameraPreviewVariables::InputPreviewPanelArgs>
		(
			m_CrossHairPosXTxtCtrl.get(),
			m_CrossHairPosYTxtCtrl.get(),
			m_SetCrossHairPosTglBtn.get()
			);

	m_CamPreview = std::make_unique<cCamPreview>
		(
		this, 
		left_side_sizer, 
		std::move(input_args)
		);
}

void cMain::CreateRightSide(wxSizer* right_side_sizer)
{
	m_RightSidePanel = new wxPanel(this);
#ifdef _DEBUG
	m_RightSidePanel->SetBackgroundColour(wxColor(150, 100, 180));
#else
	m_RightSidePanel->SetBackgroundColour(wxColor(255, 255, 255));
#endif // _DEBUG

	wxBoxSizer* right_side_panel_sizer = new wxBoxSizer(wxVERTICAL);

	CreateSteppersControl(m_RightSidePanel, right_side_panel_sizer);
	CreateCameraControls(m_RightSidePanel, right_side_panel_sizer);
	CreateMeasurement(m_RightSidePanel, right_side_panel_sizer);

	m_RightSidePanel->SetSizer(right_side_panel_sizer);
	right_side_sizer->Add(m_RightSidePanel, 1, wxEXPAND);
}

void cMain::CreateSteppersControl(wxPanel* right_side_panel, wxBoxSizer* right_side_panel_sizer)
{
	wxSizer* const sc_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, right_side_panel, "&Steppers Constrol");

	wxSize absolute_text_ctrl_size = { 54, 20 }, relative_text_ctrl_size = {absolute_text_ctrl_size};
	wxSize set_btn_size = { 35, 20 };
	wxSize inc_dec_size = { 20, 20 };

	/* Center bitmap */
	wxBitmap centerBitmap{};
	{
		auto bitmap = wxART_CENTER_HORIZONTAL;
		auto client = wxART_CLIENT_FLUENTUI_FILLED;
		auto color = wxColour(255, 128, 0);
		auto size = wxSize(16, 16);
		centerBitmap = wxMaterialDesignArtProvider::GetBitmap
		(
			bitmap,
			client,
			size,
			color
		);
	}

	/* Home bitmap */
	wxBitmap homeBitmap{};
	{
		auto bitmap = wxART_HOME;
		auto client = wxART_CLIENT_MATERIAL_FILLED;
		auto color = wxColour(0, 255, 128);
		auto size = wxSize(16, 16);
		homeBitmap = wxMaterialDesignArtProvider::GetBitmap
		(
			bitmap,
			client,
			size,
			color
		);
	}

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
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_DEFAULT);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_Detector[0].absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
						abs_val
					);

					m_Detector[0].set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_Detector[0].set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_Detector[0].absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_Detector[0].set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					x_detector->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_Detector[0].decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[0].decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_DEFAULT);
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
					m_Detector[0].relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_DET_X_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_Detector[0].increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[0].increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_Detector[0].decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_Detector[0].relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_Detector[0].increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					x_detector->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}


				/* Global positioning controls */
				{
					m_Detector[0].center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[0].center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_Detector[0].home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_X_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[0].home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_Detector[0].center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_Detector[0].home_btn, 0, wxALIGN_CENTER);

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
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_DEFAULT);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_Detector[1].absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
						abs_val
					);

					m_Detector[1].set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_Detector[1].set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_Detector[1].absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_Detector[1].set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					y_detector->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_Detector[1].decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[1].decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_DEFAULT);
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
					m_Detector[1].relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_DET_Y_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_Detector[1].increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[1].increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_Detector[1].decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_Detector[1].relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_Detector[1].increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					y_detector->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}


				/* Global positioning controls */
				{
					m_Detector[1].center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[1].center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_Detector[1].home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Y_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[1].home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_Detector[1].center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_Detector[1].home_btn, 0, wxALIGN_CENTER);

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
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_DEFAULT);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_Detector[2].absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
						abs_val
					);

					m_Detector[2].set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_Detector[2].set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_Detector[2].absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_Detector[2].set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					z_detector->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_Detector[2].decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[2].decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_DEFAULT);
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
					m_Detector[2].relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_DET_Z_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_Detector[2].increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[2].increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_Detector[2].decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_Detector[2].relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_Detector[2].increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					z_detector->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}


				/* Global positioning controls */
				{
					m_Detector[2].center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[2].center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_Detector[2].home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_DET_Z_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Detector[2].home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_Detector[2].center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_Detector[2].home_btn, 0, wxALIGN_CENTER);

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
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_DEFAULT);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_Optics[0].absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
						abs_val
					);

					m_Optics[0].set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_Optics[0].set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_Optics[0].absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_Optics[0].set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					x_optics->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_Optics[0].decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);

					m_Optics[0].decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_DEFAULT);
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);

					m_Optics[0].relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_OPT_X_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_Optics[0].increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[0].increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_Optics[0].decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_Optics[0].relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_Optics[0].increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					x_optics->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}

				/* Global positioning controls */
				{
					m_Optics[0].center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[0].center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_Optics[0].home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_X_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[0].home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_Optics[0].center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_Optics[0].home_btn, 0, wxALIGN_CENTER);

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
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_DEFAULT);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);

					m_Optics[1].absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
						abs_val
					);

					m_Optics[1].set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_Optics[1].set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_Optics[1].absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_Optics[1].set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					y_optics->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_Optics[1].decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[1].decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_DEFAULT);
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
					m_Optics[1].relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_Optics[1].increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[1].increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_Optics[1].decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_Optics[1].relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_Optics[1].increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					y_optics->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}

				/* Global positioning controls */
				{
					m_Optics[1].center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[1].center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_Optics[1].home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Y_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[1].home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_Optics[1].center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_Optics[1].home_btn, 0, wxALIGN_CENTER);

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
					wxFloatingPointValidator<float>	abs_val(3, NULL, wxNUM_VAL_DEFAULT);
					abs_val.SetMin(-1000.f);
					abs_val.SetMax(1000.f);
					m_Optics[2].absolute_text_ctrl = new wxTextCtrl(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_ABS_TE_CTL, 
						wxT("123.456"), 
						wxDefaultPosition, 
						absolute_text_ctrl_size, 
						wxTE_CENTRE | wxTE_PROCESS_ENTER, 
						abs_val
					);

					m_Optics[2].set_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_SET_BTN, 
						wxT("Set"), 
						wxDefaultPosition, 
						set_btn_size);
					m_Optics[2].set_btn->SetToolTip(wxT("Set the absolute motor position"));

					abs_sizer->Add(m_Optics[2].absolute_text_ctrl, 0, wxALIGN_CENTER);
					abs_sizer->Add(m_Optics[2].set_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					z_optics->Add(abs_sizer, 0, wxALIGN_CENTER);
				}

				/* Relative */
				{
					m_Optics[2].decrement_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_DEC_BTN, 
						wxT("-"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[2].decrement_btn->SetToolTip(wxT("Decrement distance"));
					wxFloatingPointValidator<float>	rel_val(3, NULL, wxNUM_VAL_DEFAULT);
					rel_val.SetMin(-1000.f);
					rel_val.SetMax(1000.f);
					m_Optics[2].relative_text_ctrl = new wxTextCtrl(
						right_side_panel,
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_REL_TE_CTL, 
						wxT("789.123"), 
						wxDefaultPosition, 
						relative_text_ctrl_size, 
						wxTE_CENTRE, 
						rel_val
					);
					m_Optics[2].increment_btn = new wxButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_INC_BTN, 
						wxT("+"), 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[2].increment_btn->SetToolTip(wxT("Increment distance"));

					wxSizer* const rel_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Relative [mm]");
					rel_sizer->Add(m_Optics[2].decrement_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					rel_sizer->Add(m_Optics[2].relative_text_ctrl, 0, wxALIGN_CENTER);
					rel_sizer->Add(m_Optics[2].increment_btn, 0, wxALIGN_CENTER | wxLEFT, 2);
					z_optics->Add(rel_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
				}

				/* Global positioning controls */
				{
					m_Optics[2].center_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_CENTER_BTN, 
						centerBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[2].center_btn->SetToolTip(wxT("Go to the center position of motor"));
					m_Optics[2].home_btn = new wxBitmapButton(
						right_side_panel, 
						MainFrameVariables::ID_RIGHT_SC_OPT_Z_HOME_BTN, 
						homeBitmap, 
						wxDefaultPosition, 
						inc_dec_size);
					m_Optics[2].home_btn->SetToolTip(wxT("Go to the home position of motor"));

					wxSizer* const jump_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Jump");
					jump_sizer->Add(m_Optics[2].center_btn, 0, wxALIGN_CENTER | wxRIGHT, 2);
					jump_sizer->Add(m_Optics[2].home_btn, 0, wxALIGN_CENTER);

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
	wxSizer* const cam_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, right_side_panel, "&Camera");
	wxSizer* const first_row_sizer = new wxBoxSizer(wxHORIZONTAL);
	{
		wxSizer* const selected_camera_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Selected Camera");
		{
			m_SelectedCameraStaticTXT = std::make_unique<wxStaticText>(right_side_panel, wxID_ANY, wxT("None"));
			selected_camera_box_sizer->AddStretchSpacer();
			selected_camera_box_sizer->Add(m_SelectedCameraStaticTXT.get(), 0, wxCENTER);
			selected_camera_box_sizer->AddStretchSpacer();
		}
		first_row_sizer->Add(selected_camera_box_sizer, 0, wxEXPAND);

		wxSizer* const settings_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Settings");
		{
			wxSizer* const exposure_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Exposure [ms]");

			wxIntegerValidator<int>	exposure_val(NULL, wxNUM_VAL_ZERO_AS_BLANK);
			exposure_val.SetMin(1);
			exposure_val.SetMax(1000000);

			wxSize exposure_size = { 64, 20 };

			m_CamExposure = std::make_unique<wxTextCtrl>
				(
					right_side_panel, 
					MainFrameVariables::ID_RIGHT_CAM_EXPOSURE_TE_CTL, 
#ifdef _DEBUG
					wxT("10"), 
#else
					wxT("10"), 
#endif // _DEBUG
					wxDefaultPosition, 
					exposure_size, 
					wxTE_CENTRE | wxTE_PROCESS_ENTER, 
					exposure_val
				);
			m_CamExposure->Disable();

			exposure_static_box_sizer->AddStretchSpacer();
			exposure_static_box_sizer->Add(m_CamExposure.get(), 0, wxEXPAND);
			exposure_static_box_sizer->AddStretchSpacer();

			settings_static_box_sizer->Add(exposure_static_box_sizer, 0, wxEXPAND);
		}
		first_row_sizer->Add(settings_static_box_sizer, 0, wxEXPAND | wxLEFT, 2);

		/* Preview And Start\Stop Live Capturing */
		{
			wxSizer* const ss_and_start_stop_box_sizer = new wxBoxSizer(wxVERTICAL);
			
			m_SingleShotBtn = std::make_unique<wxButton>(
				right_side_panel,
				MainFrameVariables::ID_RIGHT_CAM_SINGLE_SHOT_BTN,
				wxT("Single Shot (S)"), 
				wxDefaultPosition, 
				wxDefaultSize);
			m_SingleShotBtn->Disable();
			ss_and_start_stop_box_sizer->Add(m_SingleShotBtn.get(), 0, wxEXPAND);

			m_StartStopLiveCapturingTglBtn = std::make_unique<wxToggleButton>
				(
					right_side_panel,
					MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, 
					wxT("Start Live (L)")
				);
			m_StartStopLiveCapturingTglBtn->Disable();
			ss_and_start_stop_box_sizer->Add(m_StartStopLiveCapturingTglBtn.get(), 0, wxEXPAND | wxTOP, 5);

			first_row_sizer->AddStretchSpacer();
			first_row_sizer->Add(ss_and_start_stop_box_sizer, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 2);
		}
	}
	cam_static_box_sizer->Add(first_row_sizer, 0, wxEXPAND);

	wxSizer* const second_row_sizer = new wxBoxSizer(wxHORIZONTAL);
	{
		wxSize txt_ctrl_size = { 64, 20 };
		wxSize btn_size = { 36, 20 };
		wxSizer* const cross_hair_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&CrossHair");
		/* X Position */
		{
			wxSizer* const x_pos_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&X");
			wxIntegerValidator<int>	x_pos_validator(NULL, wxNUM_VAL_ZERO_AS_BLANK);
			x_pos_validator.SetMin(1);
			x_pos_validator.SetMax(10000);

			m_CrossHairPosXTxtCtrl = std::make_unique<wxTextCtrl>
				(
					right_side_panel,
					MainFrameVariables::ID_RIGHT_CAM_CROSS_HAIR_POS_X_TXT_CTRL,
					wxT("1"), 
					wxDefaultPosition, 
					txt_ctrl_size, 
					wxTE_CENTRE
					);
			m_CrossHairPosXTxtCtrl->Disable();
			x_pos_sizer->Add(m_CrossHairPosXTxtCtrl.get(), 0, wxEXPAND);
			cross_hair_sizer->Add(x_pos_sizer, 0, wxEXPAND | wxRIGHT, 2);
		}

		/* Y Position */
		{
			wxSizer* const y_pos_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Y");
			wxIntegerValidator<int>	y_pos_validator(NULL, wxNUM_VAL_ZERO_AS_BLANK);
			y_pos_validator.SetMin(1);
			y_pos_validator.SetMax(10000);

			m_CrossHairPosYTxtCtrl = std::make_unique<wxTextCtrl>
				(
					right_side_panel,
					MainFrameVariables::ID_RIGHT_CAM_CROSS_HAIR_POS_Y_TXT_CTRL,
					wxT("1"), 
					wxDefaultPosition, 
					txt_ctrl_size, 
					wxTE_CENTRE
					);
			m_CrossHairPosYTxtCtrl->Disable();
			y_pos_sizer->Add(m_CrossHairPosYTxtCtrl.get(), 0, wxEXPAND);
			cross_hair_sizer->Add(y_pos_sizer, 0, wxEXPAND);
		}

		/* Set Postion */
		{
			m_SetCrossHairPosTglBtn = std::make_unique<wxToggleButton>
				(
					right_side_panel,
					MainFrameVariables::ID_RIGHT_CAM_CROSS_HAIR_SET_POS_TGL_BTN,
					wxT("Set"),
					wxDefaultPosition,
					btn_size
				);
			m_SetCrossHairPosTglBtn->Disable();

			cross_hair_sizer->AddSpacer(5);
			cross_hair_sizer->Add(m_SetCrossHairPosTglBtn.get(), 0, wxALIGN_CENTER);
		}
		second_row_sizer->Add(cross_hair_sizer, 0, wxALIGN_CENTER);
	}
	cam_static_box_sizer->Add(second_row_sizer, 0, wxALIGN_CENTER);

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

				wxFloatingPointValidator<float>	start_val(3, NULL, wxNUM_VAL_DEFAULT);
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

				wxFloatingPointValidator<float>	step_val(3, NULL, wxNUM_VAL_DEFAULT);
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

				wxFloatingPointValidator<float>	finish_val(3, NULL, wxNUM_VAL_DEFAULT);
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
		//{
		//	wxSizer* const second_axis_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Second axis");

		//	/* Stage */
		//	{
		//		wxSizer* const stage_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Stage");
		//		m_SecondStage->stage = new wxChoice(
		//			right_side_panel, 
		//			MainFrameVariables::ID_RIGHT_MT_SECOND_STAGE_CHOICE, 
		//			wxDefaultPosition, 
		//			wxDefaultSize, 
		//			m_SecondStage->motors);
		//		m_SecondStage->stage->SetSelection(0);
		//		stage_static_box_sizer->Add(m_SecondStage->stage, 0, wxEXPAND);
		//		second_axis_static_box_sizer->Add(stage_static_box_sizer, 0, wxEXPAND);
		//	}

		//	/* Start */
		//	{
		//		wxSizer* const start_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Start");

		//		wxFloatingPointValidator<float>	start_val(3, NULL, wxNUM_VAL_DEFAULT);
		//		start_val.SetMin(-1000.0);
		//		start_val.SetMax(1000.0);

		//		m_SecondStage->start = new wxTextCtrl(
		//			right_side_panel,
		//			MainFrameVariables::ID_RIGHT_MT_SECOND_STAGE_START,
		//			wxT("123.456"), 
		//			wxDefaultPosition, 
		//			start_text_ctrl_size, 
		//			wxTE_CENTRE, 
		//			start_val);

		//		start_static_box_sizer->Add(m_SecondStage->start, 0, wxEXPAND);

		//		second_axis_static_box_sizer->Add(start_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);
		//	}

		//	/* Step */
		//	{
		//		wxSizer* const step_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Step");

		//		wxFloatingPointValidator<float>	step_val(3, NULL, wxNUM_VAL_DEFAULT);
		//		step_val.SetMin(-1000.0);
		//		step_val.SetMax(1000.0);

		//		m_SecondStage->step = new wxTextCtrl(
		//			right_side_panel, 
		//			MainFrameVariables::ID_RIGHT_MT_SECOND_STAGE_STEP,
		//			wxT("123.456"), 
		//			wxDefaultPosition, 
		//			step_text_ctrl_size, 
		//			wxTE_CENTRE, 
		//			step_val);
		//		
		//		step_static_box_sizer->Add(m_SecondStage->step, 0, wxEXPAND);
		//		second_axis_static_box_sizer->Add(step_static_box_sizer, 0, wxEXPAND | wxRIGHT, 2);
		//	}

		//	/* Finish */
		//	{
		//		wxSizer* const finish_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Finish");

		//		wxFloatingPointValidator<float>	finish_val(3, NULL, wxNUM_VAL_DEFAULT);
		//		finish_val.SetMin(-1000.0);
		//		finish_val.SetMax(1000.0);

		//		m_SecondStage->finish = new wxTextCtrl(
		//			right_side_panel, 
		//			MainFrameVariables::ID_RIGHT_MT_SECOND_STAGE_FINISH,
		//			wxT("123.456"), 
		//			wxDefaultPosition, 
		//			finish_text_ctrl_size, 
		//			wxTE_CENTRE, 
		//			finish_val);

		//		finish_static_box_sizer->Add(m_SecondStage->finish, 0, wxEXPAND);
		//		second_axis_static_box_sizer->Add(finish_static_box_sizer, 0, wxEXPAND);
		//	}

		//	directions_static_box_sizer->Add(second_axis_static_box_sizer, 0, wxEXPAND);
		//}

		mmt_static_box_sizer->Add(directions_static_box_sizer, 0, wxEXPAND);
	}

	{
		wxSizer* const horizontal_sizer = new wxBoxSizer(wxHORIZONTAL);

		/* Report Generation */
		wxSizer* const report_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Report");
		m_GenerateReportBtn = std::make_unique<wxButton>
			(
				right_side_panel,
				MainFrameVariables::ID_RIGHT_MY_GENERATE_REPORT_BTN,
				wxT("Generate")					
			);
		report_sizer->Add(m_GenerateReportBtn.get());
		horizontal_sizer->Add(report_sizer);

		/* Start/Stop Capturing */
		wxSizer* const capturing_sizer = new wxStaticBoxSizer(wxHORIZONTAL, right_side_panel, "&Capturing");
		m_StartStopMeasurementTglBtn = std::make_unique<wxToggleButton>
			(
				right_side_panel,
				MainFrameVariables::ID_RIGHT_MT_START_STOP_MEASUREMENT,
				wxT("Start Capturing")					
			);
		horizontal_sizer->AddStretchSpacer();
		horizontal_sizer->Add(capturing_sizer);
		capturing_sizer->Add(m_StartStopMeasurementTglBtn.get());
		mmt_static_box_sizer->AddStretchSpacer();
		mmt_static_box_sizer->Add(horizontal_sizer, 0, wxEXPAND);
	}

	right_side_panel_sizer->Add(mmt_static_box_sizer, 1, wxEXPAND | wxLEFT | wxRIGHT, 2);
}

auto cMain::OnEnableDarkMode(wxCommandEvent& evt) -> void
{
	if (m_MenuBar->menu_edit->IsChecked(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_DARK_MODE))
	{
		m_CamPreview->SetBackgroundColor(m_BlackAppearenceColor);
		wxColour normalized_black = wxColour(100, 100, 100);
		m_VerticalToolBar->tool_bar->SetBackgroundColour(normalized_black);
		wxColour nb_color = wxColour(normalized_black.Red() + 40, normalized_black.Green() + 40, normalized_black.Blue() + 40);
		m_RightSidePanel->SetBackgroundColour(nb_color);
	}
	else
	{
		m_CamPreview->SetBackgroundColor(m_DefaultAppearenceColor);

		m_VerticalToolBar->tool_bar->SetBackgroundColour(m_DefaultAppearenceColor);
		m_RightSidePanel->SetBackgroundColour(m_DefaultAppearenceColor);
	}
	Refresh();
}

auto cMain::OnEnableFWHMDisplaying(wxCommandEvent& evt) -> void
{
	m_CamPreview->ActivateFWHMDisplaying
	(
		m_MenuBar->menu_edit->IsChecked(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_FWHM_DISPLAYING)
	);
}

void cMain::CreateProgressBar()
{
	wxSize size_of_progress_bar{ 400, 190 };
	wxPoint start_point_progress_bar
	{ 
		this->GetPosition().x + this->GetSize().x - size_of_progress_bar.x, 
		this->GetPosition().y + this->GetSize().y - size_of_progress_bar.y 
	};
	m_ProgressBar = std::make_unique<ProgressBar>(this, start_point_progress_bar, size_of_progress_bar);
	//m_ProgressBar = new ProgressBar(this, start_point_progress_bar, size_of_progress_bar);
	//m_ProgressBar->SetIcon(logo_xpm);
}

void cMain::OnSingleShotCameraImage(wxCommandEvent& evt)
{
	constexpr auto raise_exception_msg = []() 
	{
		wxString title = "Connection error";
		wxMessageBox(
			wxT
			(
				"Current camera can't provide a single shot."
				"\nPlease, check if the camera is connected properly and restart the program."
			),
			title,
			wxICON_ERROR);
	};

	LOG("Started: " + wxString(__FUNCSIG__));

	wxBusyCursor busy_cursor{};
	wxString exposure_time_str = m_CamExposure->GetValue().IsEmpty() 
		? wxString("1") 
		: m_CamExposure->GetValue();
	int exposure_time = abs(wxAtoi(exposure_time_str)) * 1000; // Because user input is in [ms], we need to recalculate exposure time to [us]

	auto start_live_capturing_after_ss = m_StartStopLiveCapturingTglBtn->GetValue();

	wxCommandEvent artStartStopLiveCapturing(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN);
	if (start_live_capturing_after_ss)
	{
		m_StartStopLiveCapturingTglBtn->SetValue(!m_StartStopLiveCapturingTglBtn->GetValue());
		// Start/Stop the acquisition
		ProcessEvent(artStartStopLiveCapturing);
	}
	{
		auto now = std::chrono::system_clock::now();
		auto cur_time = std::chrono::system_clock::to_time_t(now);
		auto str_time = std::string(std::ctime(&cur_time)).substr(11, 8);
		auto cur_hours = str_time.substr(0, 2);
		auto cur_mins = str_time.substr(3, 2);
		auto cur_secs = str_time.substr(6, 2);

		auto out_dir = m_OutDirTextCtrl->GetValue();
		const std::string file_name = std::string(out_dir.mb_str()) + std::string("\\") +
			std::string("ss_") + 
			cur_hours + std::string("H_") + 
			cur_mins + std::string("M_") + 
			cur_secs + std::string("S_") + 
			std::to_string(exposure_time) + std::string("us") 
			+ std::string(".tif");

		/* Camera */
		{
			m_XimeaControl->SetExposureTime(exposure_time);
			auto imageSize = wxSize{ (int)m_XimeaControl->GetImageWidth(), (int)m_XimeaControl->GetImageHeight() };

			auto dataPtr = std::make_unique<unsigned short[]>(imageSize.GetWidth() * imageSize.GetHeight());

			auto imgPtr = m_XimeaControl->GetImage();
			if (!imgPtr)
			{
				raise_exception_msg();
				return;
			}

			memcpy
			(
				dataPtr.get(),
				imgPtr, 
				sizeof(unsigned short) * imageSize.GetWidth() * imageSize.GetHeight()
			);

			cv::Mat cv_img
			(
				cv::Size(imageSize.GetWidth(), imageSize.GetHeight()),
				CV_16U,
				dataPtr.get(),
				cv::Mat::AUTO_STEP
			);
			cv::imwrite(file_name, cv_img);

			m_CamPreview->SetCameraCapturedImage
			(
				imgPtr
			);
		}
	}

	/* Only if user has already started Live Capturing, continue Live Capturing */
	if (start_live_capturing_after_ss)
	{
		LOG("Start Live Capturing");
		m_StartStopLiveCapturingTglBtn->SetValue(!m_StartStopLiveCapturingTglBtn->GetValue());
		// Start/Stop the acquisition
		ProcessEvent(artStartStopLiveCapturing);
	}

	LOG("Finished: " + wxString(__FUNCSIG__));
}

void cMain::OnSetOutDirectoryBtn(wxCommandEvent& evt)
{
	wxString outDirPath{};
#ifdef _DEBUG
	outDirPath = "D:\\Projects\\RIGAKU\\MMCam\\MMCam\\src\\dbg_fld";
#else
	wxDirDialog save_dialog(NULL, "Choose save directory", "",
		wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);

	if (save_dialog.ShowModal() == wxID_CANCEL)
		return;
	outDirPath = save_dialog.GetPath();
#endif // _DEBUG


	if (!m_XimeaControl || !m_XimeaControl->IsCameraConnected()) return;

	m_OutDirTextCtrl->SetValue(outDirPath);
	m_FirstStage->EnableAllControls();
	//m_SecondStage->EnableAllControls();
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_RIGHT_CAM_SINGLE_SHOT_BTN, true);
	m_SingleShotBtn->Enable();
	m_StartStopMeasurementTglBtn->Enable();
}

void cMain::OnOpenSettings(wxCommandEvent& evt)
{
	m_CamPreview->SetFocus();
#ifndef _DEBUG
	m_Settings->ShowModal();
#endif // !_DEBUG

	if (!m_Settings->IsActive())
	{
		m_CamPreview->SetPixelSizeUM(m_Settings->GetPixelSizeUM());
		m_CamPreview->SetCropSizeMM(m_Settings->GetCropSizeMM());
		InitializeSelectedCamera();
		UpdateStagePositions();
		EnableUsedAndDisableNonUsedMotors();	
	}
}

auto cMain::InitializeSelectedCamera() -> void
{
	// We don't need to initialize camera twice!
	if (m_XimeaControl) return;

	auto curr_camera = m_Settings->GetSelectedCamera();
	if (curr_camera == "None") return;

	m_XimeaControl = std::make_unique<XimeaControl>();
	m_XimeaControl->InitializeCameraBySN(curr_camera.ToStdString());
	if (!m_XimeaControl->IsCameraConnected()) return;

	m_SelectedCameraStaticTXT->SetLabel(curr_camera);	

	// Successful initialization of the camera
	// Enabling controls
	{
		m_CamExposure->Enable();
		m_StartStopLiveCapturingTglBtn->Enable();
		m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, true);
		m_MenuBar->submenu_intensity_profile->Enable(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, true);
		m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_FWHM_DISPLAYING, true);
		m_VerticalToolBar->tool_bar->Enable();
	}

	//m_MenuBar->menu_edit->Check(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_FWHM_DISPLAYING, true);
	//wxCommandEvent art_fwhm_displaying(wxEVT_MENU, MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_FWHM_DISPLAYING);
	//ProcessEvent(art_fwhm_displaying);

	m_StartStopLiveCapturingTglBtn->SetValue(true);
	wxCommandEvent art_start_live_capturing(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN);
	ProcessEvent(art_start_live_capturing);
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
	if (m_XimeaControl->IsCameraConnected())
	{
		if (m_StartStopLiveCapturingTglBtn->GetValue())
		{
			m_StartStopLiveCapturingTglBtn->SetValue(!m_StartStopLiveCapturingTglBtn->GetValue());
			wxCommandEvent artStopLiveCapturing(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN);
			ProcessEvent(artStopLiveCapturing);
		}

		if (m_StartStopMeasurementTglBtn->GetValue())
		{

			m_StartStopMeasurementTglBtn->SetValue(!m_StartStopMeasurementTglBtn->GetValue());
			wxCommandEvent artStopMeasurement(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_MT_START_STOP_MEASUREMENT);
			ProcessEvent(artStopMeasurement);
		}
	}

	Destroy();  // you may also do:  event.Skip();
	evt.Skip();
	// since the default event handler does call Destroy(), too
}

auto cMain::UpdateStagePositions() -> void
{
	// Detector
	{
		m_Detector[0].absolute_text_ctrl->SetValue(
			wxString::Format(wxT("%.3f"),
				m_Settings->GetActualMotorPosition(SettingsVariables::DETECTOR_X))
		);

		m_Detector[2].absolute_text_ctrl->SetValue(
			wxString::Format(wxT("%.3f"),
				m_Settings->GetActualMotorPosition(SettingsVariables::DETECTOR_Y))
		);

		m_Detector[2].absolute_text_ctrl->SetValue(
			wxString::Format(wxT("%.3f"),
				m_Settings->GetActualMotorPosition(SettingsVariables::DETECTOR_Z))
		);
	}

	// Optics
	{
		m_Optics[0].absolute_text_ctrl->SetValue(
			wxString::Format(wxT("%.3f"),
				m_Settings->GetActualMotorPosition(SettingsVariables::OPTICS_X))
		);

		m_Optics[1].absolute_text_ctrl->SetValue(
			wxString::Format(wxT("%.3f"),
				m_Settings->GetActualMotorPosition(SettingsVariables::OPTICS_Y))
		);

		m_Optics[2].absolute_text_ctrl->SetValue(
			wxString::Format(wxT("%.3f"),
				m_Settings->GetActualMotorPosition(SettingsVariables::OPTICS_Z))
		);
	}
}

void cMain::OnExit(wxCommandEvent& evt)
{
	wxCloseEvent artificialExit(wxEVT_CLOSE_WINDOW);
	ProcessEvent(artificialExit);
}

void cMain::EnableUsedAndDisableNonUsedMotors()
{
	// Detector 
	{
		/* X */
		if (m_Settings->MotorHasSerialNumber(SettingsVariables::DETECTOR_X)) m_Detector[0].EnableAllControls();
		else m_Detector[0].DisableAllControls();
		/* Y */
		if (m_Settings->MotorHasSerialNumber(SettingsVariables::DETECTOR_Y)) m_Detector[1].EnableAllControls();
		else m_Detector[1].DisableAllControls();
		/* Z */
		if (m_Settings->MotorHasSerialNumber(SettingsVariables::DETECTOR_Z)) m_Detector[2].EnableAllControls();
		else m_Detector[2].DisableAllControls();
	}
	// Optics
	{
		/* X */
		if (m_Settings->MotorHasSerialNumber(SettingsVariables::OPTICS_X)) m_Optics[0].EnableAllControls();
		else m_Optics[0].DisableAllControls();
		/* Y */
		if (m_Settings->MotorHasSerialNumber(SettingsVariables::OPTICS_Y)) m_Optics[1].EnableAllControls();
		else m_Optics[1].DisableAllControls();
		/* Z */
		if (m_Settings->MotorHasSerialNumber(SettingsVariables::OPTICS_Z)) m_Optics[2].EnableAllControls();
		else m_Optics[2].DisableAllControls();
	}
}

void cMain::CreateVerticalToolBar()
{
	m_VerticalToolBar = std::make_unique<MainFrameVariables::ToolBar>();
	m_VerticalToolBar->tool_bar = new wxToolBar
	(
		this, 
		wxID_ANY, 
		wxDefaultPosition, 
		wxDefaultSize, 
		wxTB_VERTICAL
	);

	/* CrossHair bitmap */
	wxBitmap crosshairToolBitmap{};
	{
		auto bitmap = wxART_ARROW_TRENDING_LINES;
		auto client = wxART_CLIENT_FLUENTUI_FILLED;
		auto color = wxColour(128, 128, 255);
		auto size = wxSize(32, 32);
		crosshairToolBitmap = wxMaterialDesignArtProvider::GetBitmap
		(
			bitmap,
			client,
			size,
			color
		);
	}

	m_VerticalToolBar->tool_bar->AddCheckTool(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, _("Crosshair"), crosshairToolBitmap);
	m_VerticalToolBar->tool_bar->SetToolShortHelp(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, wxT("Crosshair (C)"));

	m_VerticalToolBar->tool_bar->SetToolBitmapSize(wxSize(30, 30));
	m_VerticalToolBar->tool_bar->Disable();
	m_VerticalToolBar->tool_bar->Realize();
}


auto cMain::LiveCapturingFinishedCapturingAndDrawing(bool is_finished) -> void
{
	//m_LiveCapturingEndedDrawingOnCamPreview = is_finished;
}

auto cMain::WorkerThreadFinished(bool is_finished) -> void
{
	if (!is_finished) return;

	wxCommandEvent live_capturing_evt(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN);
	ProcessEvent(live_capturing_evt);
}

void cMain::UnCheckAllTools()
{
	/* Unchecking CrossHair Button */
	m_VerticalToolBar->tool_bar->ToggleTool(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, false);
	m_MenuBar->menu_tools->Check(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, false);
	m_CamPreview->SetCrossHairButtonActive(false);
	m_CrossHairPosXTxtCtrl->Disable();
	m_CrossHairPosYTxtCtrl->Disable();
	m_SetCrossHairPosTglBtn->Disable();
}

void cMain::OnFirstStageChoice(wxCommandEvent& evt)
{
	auto first_stage_selection = m_FirstStage->stage->GetCurrentSelection() - 1;
	double start_stage_value{}, step_stage_value{}, finish_stage_value{};
	switch (first_stage_selection)
	{
	/* Detector */
	case 0:
		if (!m_Detector[0].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
		break;
	case 1:
		if (!m_Detector[1].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
		break;
	case 2:
		if (!m_Detector[2].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
		break;
	/* Optics */
	case 3:
		if (!m_Optics[0].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
		break;
	case 4:
		if (!m_Optics[1].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
		break;
	case 5:
		if (!m_Optics[2].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
		break;
	default:
		break;
	}
	/* Set Start To Current position of motor */
	m_FirstStage->start->SetValue
	(
		wxString::Format
		(
			wxT("%.3f"), 
			(float)start_stage_value
		)
	);
	/* Set Finish To Current position of motor + Step */
	if (!m_FirstStage->step->GetValue().ToDouble(&step_stage_value)) return;
	finish_stage_value = start_stage_value + 1.0;
	m_FirstStage->finish->SetValue
	(
		wxString::Format
		(
			wxT("%.3f"), 
			(float)finish_stage_value
		)
	);
}

void cMain::OnSecondStageChoice(wxCommandEvent& evt)
{
	//auto second_stage_selection = m_SecondStage->stage->GetCurrentSelection() - 1;
	//double start_stage_value{}, step_stage_value{}, finish_stage_value{};
	//switch (second_stage_selection)
	//{
	///* Detector */
	//case 0:
	//	if (!m_Detector[0].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
	//	break;
	//case 1:
	//	if (!m_Detector[1].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
	//	break;
	//case 2:
	//	if (!m_Detector[2].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
	//	break;
	///* Optics */
	//case 3:
	//	if (!m_Optics[0].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
	//	break;
	//case 4:
	//	if (!m_Optics[1].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
	//	break;
	//case 5:
	//	if (!m_Optics[2].absolute_text_ctrl->GetValue().ToDouble(&start_stage_value)) return;
	//	break;
	//default:
	//	break;
	//}
	///* Set Start To Current position of motor */
	//m_SecondStage->start->SetValue
	//(
	//	wxString::Format
	//	(
	//		wxT("%.3f"), 
	//		(float)start_stage_value
	//	)
	//);
	///* Set Finish To Current position of motor + Step */
	//if (!m_SecondStage->step->GetValue().ToDouble(&step_stage_value)) return;
	//finish_stage_value = start_stage_value + step_stage_value;
	//m_SecondStage->finish->SetValue
	//(
	//	wxString::Format
	//	(
	//		wxT("%.3f"), 
	//		(float)finish_stage_value
	//	)
	//);
}

void cMain::OnStartStopCapturingTglButton(wxCommandEvent& evt)
{
	constexpr auto raise_exception_msg = [](wxString axis) 
	{
		wxString title = "Finish position error";
		wxMessageBox(
			wxT
			(
				"Finish position of " + axis + " axis is not correct!"
				"\nPlease, check if STEP and FINISH values are correct!"
			),
			title,
			wxICON_ERROR);
	};

	auto timePointToWxString = []()
		{
			auto now = std::chrono::system_clock::now().time_since_epoch().count();
			wxString formattedTime = wxString::Format(wxT("%lld"), now);
			return formattedTime;
		};


	if (!m_StartStopMeasurementTglBtn->GetValue())
	{
		if (m_StartedThreads.size())
		{
			LOGI("StartedThreads.size(): ", (int)m_StartedThreads.size());
			m_StartedThreads.back().second = false;
			LOG("StartedThreads.back(): " + m_StartedThreads.back().first);

			{
				m_StartStopLiveCapturingTglBtn->Disable();
				m_StartStopMeasurementTglBtn->Disable();
				m_CamExposure->Disable();
				m_SingleShotBtn->Disable();
			}

			while (!m_StartedThreads.back().first.empty())
				wxThread::This()->Sleep(100);

			m_StartedThreads.pop_back();

			{
				m_StartStopLiveCapturingTglBtn->Enable();
				m_StartStopMeasurementTglBtn->Enable();
				m_CamExposure->Enable();
				m_SingleShotBtn->Enable();
			}
		}

		m_ProgressBar->Hide();
		m_ProgressBar->UpdateProgressWithMessage("", 0);
		m_ProgressBar->UpdateElapsedTime(0);
		m_ProgressBar->UpdateEstimatedTime(0, 0);
		//if (m_AppProgressIndicator) m_AppProgressIndicator->~wxAppProgressIndicator();
		//UpdateAllAxisGlobalPositions();

		EnableControlsAfterCapturing();
		m_StartStopMeasurementTglBtn->SetLabel("Start Capturing");
		return;
	}

	if (m_StartStopLiveCapturingTglBtn->GetValue())
	{
		m_StartStopLiveCapturingTglBtn->SetValue(false);
		wxCommandEvent untoggleLiveCapturingBtn(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN);
		ProcessEvent(untoggleLiveCapturingBtn);
	}

	DisableControlsBeforeCapturing();
	m_StartStopMeasurementTglBtn->SetLabel("Stop Capturing");

	auto first_axis = std::make_unique<MainFrameVariables::AxisMeasurement>();
	auto second_axis = std::make_unique<MainFrameVariables::AxisMeasurement>();
	double start_first_stage_value{}, step_first_stage_value{}, finish_first_stage_value{};
	double start_second_stage_value{}, step_second_stage_value{}, finish_second_stage_value{};
	int first_stage_step_count{}, second_stage_step_count{};
	/* Checking if user selected None as a stage */
	{
		/* Checking first stage */
		{
			if (m_FirstStage->stage->GetCurrentSelection() == 0) return;
			else first_axis->axis_number = m_FirstStage->stage->GetCurrentSelection() - 1;
		}
		/* Checking Start, Step and Finish values */
		{
			if (!m_FirstStage->start->GetValue().ToDouble(&start_first_stage_value)) return;
			first_axis->start = (int)(start_first_stage_value * 1000.0) / 1000.f;
			if (!m_FirstStage->step->GetValue().ToDouble(&step_first_stage_value)) return;
			first_axis->step = (int)(step_first_stage_value * 1000.0) / 1000.f;
			if (!m_FirstStage->finish->GetValue().ToDouble(&finish_first_stage_value)) return;
			first_axis->finish = (int)(finish_first_stage_value * 1000.0) / 1000.f;
			if (
				(finish_first_stage_value - start_first_stage_value < 0.0 && step_first_stage_value > 0.0)
				|| (finish_first_stage_value - start_first_stage_value > 0.0 && step_first_stage_value < 0.0)
				) 
				raise_exception_msg("first");
			first_axis->step_number = ((int)(finish_first_stage_value * 1000.0) - 
				(int)(start_first_stage_value * 1000.0)) / 
				(int)(step_first_stage_value * 1000.0) + 1;
		}
		/* Checking second stage */
		//if (m_SecondStage->stage->GetCurrentSelection() - 1 == first_axis->axis_number) return;
		/* 
		if (m_SecondStage->stage->GetCurrentSelection() == 0) return;
		else selected_second_stage = m_SecondStage->stage->GetCurrentSelection() - 1;		
		*/
	}
	{
		CreateMetadataFile();
		m_StartCalculationTime = std::chrono::steady_clock::now();
		wxPoint start_point_progress_bar
		{ 
			GetPosition().x, 
			GetPosition().y
			//this->GetPosition().x + this->GetSize().x - m_ProgressBar->GetSize().x, 
			//this->GetPosition().y + this->GetSize().y - m_ProgressBar->GetSize().y 
		};
		m_ProgressBar->SetPosition(start_point_progress_bar);
		m_Settings->ResetCapturing();
		m_ProgressBar->Show();

		//m_AppProgressIndicator = std::make_unique<wxAppProgressIndicator>(this, 100);

		//this->Disable();
		//m_StartMeasurement->Disable();
	}

	auto currThreadTimeStamp = timePointToWxString();
	m_StartedThreads.push_back(std::make_pair(currThreadTimeStamp, true));

	/* Worker and Progress Threads */
	{
		auto out_dir = m_OutDirTextCtrl->GetValue();

		wxString exposure_time_str = m_CamExposure->GetValue().IsEmpty() 
			? wxString("0") 
			: m_CamExposure->GetValue();
		unsigned long exposure_time = abs(wxAtoi(exposure_time_str)) * 1000; // Because user input is in [ms], we need to recalculate the value to [us]

		WorkerThread* worker_thread = new WorkerThread
		(
			this,
			&m_StartedThreads.back().first,
			&m_StartedThreads.back().second,
			m_Settings.get(),
			m_CamPreview.get(),
			m_XimeaControl.get(),
			out_dir,
			exposure_time,
			first_axis.release(), 
			second_axis.release(),
			m_Settings->GetPixelSizeUM()
		);
		ProgressThread* progress_thread = new ProgressThread(m_Settings.get(), this);

		if (worker_thread->CreateThread() != wxTHREAD_NO_ERROR)
		{
			delete worker_thread;
			worker_thread = nullptr;
			return;
		}
		if (progress_thread->CreateThread() != wxTHREAD_NO_ERROR)
		{
			delete progress_thread;
			progress_thread = nullptr;
			return;
		}
		if (progress_thread->GetThread()->Run() != wxTHREAD_NO_ERROR)
		{
			delete progress_thread;
			progress_thread = nullptr;
			return;
		}
		if (worker_thread->GetThread()->Run() != wxTHREAD_NO_ERROR)
		{
			delete progress_thread;
			progress_thread = nullptr;
			delete worker_thread;
			worker_thread = nullptr;
			return;
		}
	}
}

void cMain::StartLiveCapturing()
{
	auto timePointToWxString = []()
		{
			auto now = std::chrono::system_clock::now().time_since_epoch().count();
			wxString formattedTime = wxString::Format(wxT("%lld"), now);
			return formattedTime;
		};

	wxString exposure_time_str = m_CamExposure->GetValue().IsEmpty() 
		? wxString("0") 
		: m_CamExposure->GetValue();
	unsigned long exposure_time = abs(wxAtoi(exposure_time_str)) * 1000; // Because user input is in [ms], we need to recalculate the value to [us]

	auto currThreadTimeStamp = timePointToWxString();
	m_StartedThreads.push_back(std::make_pair(currThreadTimeStamp, true));
	//m_XimeaControl->SetExposureTime(exposure_time);

	//auto curr_camera = m_Settings->GetSelectedCamera();

	LiveCapturing* live_capturing = new LiveCapturing
	(
		this, 
		&m_StartedThreads.back().first,
		&m_StartedThreads.back().second,
		m_CamPreview.get(), 
		m_XimeaControl.get(),
		//curr_camera.ToStdString(),
		exposure_time
	);

	if (live_capturing->CreateThread() != wxTHREAD_NO_ERROR)
	{
		delete live_capturing;
		live_capturing = nullptr;
		return;
	}
	if (live_capturing->GetThread()->Run() != wxTHREAD_NO_ERROR)
	{
		delete live_capturing;
		live_capturing = nullptr;
		return;
	}
}

void cMain::ChangeCameraManufacturerChoice(wxCommandEvent& evt)
{
	wxCommandEvent simulate_change_exposure_value(wxEVT_TEXT_ENTER, MainFrameVariables::ID_RIGHT_CAM_EXPOSURE_TE_CTL);
	ProcessEvent(simulate_change_exposure_value);
}

void cMain::OnCrossHairButton(wxCommandEvent& evt)
{
	UnCheckAllTools();
	if (!m_IsCrossHairChecked)
	{
		m_MenuBar->menu_tools->Check(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, true);
		m_VerticalToolBar->tool_bar->ToggleTool(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, true);
		m_IsCrossHairChecked = true;
		m_CamPreview->SetCrossHairButtonActive(true);
		m_CrossHairPosXTxtCtrl->Enable();
		m_CrossHairPosYTxtCtrl->Enable();
		m_SetCrossHairPosTglBtn->Enable();
		{
			auto img_size = m_CamPreview->GetImageSize();
			//m_CamPreview->SetXCrossHairPosFromParentWindow(img_size.GetWidth() / 2);
			//m_CamPreview->SetYCrossHairPosFromParentWindow(img_size.GetHeight() / 2);
			m_CrossHairPosXTxtCtrl->SetValue(wxString::Format(wxT("%i"), img_size.GetWidth() / 2));
			m_CrossHairPosYTxtCtrl->SetValue(wxString::Format(wxT("%i"), img_size.GetHeight() / 2));
		}
	}
	else
	{
		m_IsCrossHairChecked = false;
	}
}

auto cMain::LiveCapturingThread(wxThreadEvent& evt) -> void
{
	auto curr_code = evt.GetInt();

	// 0 == Camera is Connected and everything is fine
	if (curr_code == 0)
	{
		auto imgPtr = evt.GetPayload<unsigned short*>();
		if (!imgPtr) return;
		LOG("Set camera captured image");

		if (*m_CamPreview->GetExecutionFinishedPtr())
			m_CamPreview->SetCameraCapturedImage
			(
				imgPtr
			);

		delete[] imgPtr;
	}
	// -1 == Camera is disconnected
	else if (curr_code == -1)
	{
		m_StartStopLiveCapturingTglBtn->SetValue(false);
		wxCommandEvent live_capturing_evt(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN);
		ProcessEvent(live_capturing_evt);
	}
}

void cMain::UpdateProgress(wxThreadEvent& evt)
{
	int progress = evt.GetInt();
	wxString msg = evt.GetString();
	unsigned long long elapsed_seconds{};

	if (progress >= 0)
	{
		auto current_time = std::chrono::steady_clock::now();
		elapsed_seconds = std::chrono::duration_cast<std::chrono::seconds>(current_time - m_StartCalculationTime).count();
		m_ProgressBar->UpdateProgressWithMessage(msg, progress);
		LOGI("Progress: ", progress);
		//m_AppProgressIndicator->SetValue(progress <= 100 ? progress : 100);
		m_ProgressBar->UpdateElapsedTime(elapsed_seconds);
		m_ProgressBar->UpdateEstimatedTime(progress, elapsed_seconds);
	}
	// Finished
	else if (progress == -1)
	{
		m_StartStopMeasurementTglBtn->SetValue(false);
		wxCommandEvent art_evt(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_MT_START_STOP_MEASUREMENT);
		ProcessEvent(art_evt);
	}
	// Interrupted
	else if (progress == -2)
	{
		//m_StartStopMeasurementTglBtn->SetValue(false);
		//wxCommandEvent art_evt(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_MT_START_MEASUREMENT);
		//ProcessEvent(art_evt);
		//this->Enable();
	}

}

auto cMain::CreateMetadataFile() -> void
{
	wxString exposure_time_str = m_CamExposure->GetValue().IsEmpty() 
		? wxString("0") 
		: m_CamExposure->GetValue();
	unsigned long exposure_time = abs(wxAtoi(exposure_time_str)) * 1000; // Because user input is in [ms], we need to recalculate the value to [us]

	double det_x_pos{}, det_y_pos{}, det_z_pos{};
	double opt_x_pos{}, opt_y_pos{}, opt_z_pos{};

	{
		/* Detector */
		if (!m_Detector[0].absolute_text_ctrl->GetValue().ToDouble(&det_x_pos)) return;
		if (!m_Detector[1].absolute_text_ctrl->GetValue().ToDouble(&det_y_pos)) return;
		if (!m_Detector[2].absolute_text_ctrl->GetValue().ToDouble(&det_z_pos)) return;
		/* Optics */
		if (!m_Optics[0].absolute_text_ctrl->GetValue().ToDouble(&opt_x_pos)) return;
		if (!m_Optics[1].absolute_text_ctrl->GetValue().ToDouble(&opt_y_pos)) return;
		if (!m_Optics[2].absolute_text_ctrl->GetValue().ToDouble(&opt_z_pos)) return;
	}

	std::string selected_axis{};
	switch (m_FirstStage->stage->GetCurrentSelection() - 1)
	{
	/* Detector */
	case 0:
		selected_axis = std::string("detector_x");
		break;
	case 1:
		selected_axis = std::string("detector_y");
		break;
	case 2:
		selected_axis = std::string("detector_z");
		break;
	/* Optics */
	case 3:
		selected_axis = std::string("optics_x");
		break;
	case 4:
		selected_axis = std::string("optics_y");
		break;
	case 5:
		selected_axis = std::string("optics_z");
		break;
	default:
		break;
	}

	double start_first_stage_value{}, step_first_stage_value{}, finish_first_stage_value{};
	{
		if (!m_FirstStage->start->GetValue().ToDouble(&start_first_stage_value)) return;
		if (!m_FirstStage->step->GetValue().ToDouble(&step_first_stage_value)) return;
		if (!m_FirstStage->finish->GetValue().ToDouble(&finish_first_stage_value)) return;
	}
	auto now = std::chrono::system_clock::now();
	auto cur_time = std::chrono::system_clock::to_time_t(now);
	std::string time_metadata_filename{};
	std::string cur_date_and_time{};
	{
		std::string cur_date(30, '\0');
		std::strftime(&cur_date[0], cur_date.size(), "%Y%m%d", std::localtime(&cur_time));
		cur_date_and_time = cur_date.substr(0, 8); 
		auto str_time = std::string(std::ctime(&cur_time)).substr(11, 8); // Cut date in format: 20230223
		auto cur_hours = str_time.substr(0, 2);
		auto cur_mins = str_time.substr(3, 2);
		auto cur_secs = str_time.substr(6, 2);
		time_metadata_filename = cur_hours + std::string("H_") + cur_mins + std::string("M_") + cur_secs + std::string("S");
		cur_date_and_time += std::string("_") + cur_hours + cur_mins + cur_secs;
	}

	nlohmann::json main_table{};
	main_table = 
	{
		{"units", "mm"},
		{"pos_source", 0.000},
		{"pos_optics", 123.456},
		{"pos_detector", 234.567},
		{"first_stage", 
			{
				{"title", "detector_x"}, 
				{"position", det_x_pos}
			}
		},
		{"second_stage", 
			{
				{"title", "detector_y"}, 
				{"position", det_y_pos}
			}
		},
		{"third_stage", 
			{
				{"title", "detector_z"}, 
				{"position", det_z_pos}
			}
		},
		{"fourth_stage", 
			{
				{"title", "optics_x"}, 
				{"position", opt_x_pos}
			}
		},
		{"fifth_stage", 
			{
				{"title", "optics_y"}, 
				{"position", opt_y_pos}
			}
		},
		{"sixth_stage", 
			{
				{"title", "optics_z"}, 
				{"position", opt_z_pos}
			}
		},
		{"measurement", 
			{
				{"stage", selected_axis}, 
				{"start", start_first_stage_value},
				{"step", step_first_stage_value},
				{"finish", finish_first_stage_value},
				{"exposure", 
					{
						{"units", "us"}, 
						{"time", exposure_time}, 
						{"gain", 1}
					}
				},
				{"date_time", cur_date_and_time}
			}
		},
		{"message", ""}
	};
	
	auto out_dir_with_filename = 
		m_OutDirTextCtrl->GetValue() + 
		wxString("\\metadata_") + 
		wxString(time_metadata_filename) + 
		wxString(".json");
	std::ofstream out_file(out_dir_with_filename.ToStdString());
	if (out_file.is_open())
	{
		out_file << main_table;
		out_file.close();
	}
}

auto cMain::FindSpotCenterCoordinates
(
	const cv::Mat& signal, 
	int* bestX, 
	int* bestY
) -> void
{
	auto findCenterFWHM = []
	(
		const cv::Mat& data1D, 
		const int maxI, 
		const double hMax, 
		int* left, 
		int* right
		) 
		{
			auto leftFWHM = -1, rightFWHM = -1;

			// Looking for the left FWHM value
			for (auto i = 0; i <= maxI; ++i) 
			{
				auto value = data1D.at<float>(i);
				if (leftFWHM == -1 && value >= hMax)
				{
					leftFWHM = i;
					break;
				}
			}

			// Looking for the right FWHM value
			for (auto i = data1D.total() - 1; i > maxI; --i) 
			{
				auto value = data1D.at<float>(i);
				if (leftFWHM != -1 && value >= hMax)
				{
					rightFWHM = i + 1;
					break;
				}
			}

			*left = leftFWHM;
			*right = rightFWHM;
		};

	// Rows
	{
		double minVal{}, maxVal{};
		cv::Point maxPoint{};
		// 1D array for row sums
		cv::Mat rowSums;
		cv::reduce(signal, rowSums, 1, cv::REDUCE_SUM, CV_32F); // Reduce along columns (dim=1)
		cv::minMaxLoc(rowSums, &minVal, &maxVal, nullptr, &maxPoint);

		auto halfMax = (maxVal - minVal) / 2.0 + minVal;
		auto threshold = (maxVal - minVal) * 0.1 + minVal;
		int maxIndex = maxPoint.y; // x is used for 1D row data

		auto leftFWHM = -1, rightFWHM = -1;

		findCenterFWHM
		(
			rowSums, 
			maxIndex, 
			halfMax, 
			&leftFWHM, 
			&rightFWHM
		);

		*bestY = (rightFWHM - leftFWHM) / 2 + leftFWHM;
	}

	// Columns
	{
		double minVal{}, maxVal{};
		cv::Point maxPoint{};
		// 1D array for column sums
		cv::Mat colSums;
		cv::reduce(signal, colSums, 0, cv::REDUCE_SUM, CV_32F); // Reduce along rows (dim=0)
		cv::minMaxLoc(colSums, &minVal, &maxVal, nullptr, &maxPoint);

		auto halfMax = (maxVal - minVal) / 2.0 + minVal;
		int maxIndex = maxPoint.x; // x is used for 1D row data

		auto leftFWHM = -1, rightFWHM = -1;

		findCenterFWHM
		(
			colSums, 
			maxIndex, 
			halfMax, 
			&leftFWHM, 
			&rightFWHM
		);

		*bestX = (rightFWHM - leftFWHM) / 2 + leftFWHM;
	}

}

auto cMain::CropDataIntoArray
(
	const cv::Mat& inData, 
	const int startX, 
	const int startY, 
	const int windowWidth, 
	unsigned short* const outData
) -> void
{
	for (auto y = startY; y < startY + windowWidth; ++y)
	{
		for (auto x = startX; x < startX + windowWidth; ++x)
		{
			outData[(y - startY) * windowWidth + (x - startX)] = inData.at<unsigned short>(y * inData.cols + x);
		}
	}
}

auto cMain::CropDataIntoArray
(
	unsigned short* const inData, 
	const int origDataWidth,
	const int startX, 
	const int startY, 
	const int windowWidth, 
	unsigned short* const outData
) -> void
{	
	for (auto y = startY; y < startY + windowWidth; ++y)
	{
		for (auto x = startX; x < startX + windowWidth; ++x)
		{
			outData[(y - startY) * windowWidth + (x - startX)] = inData[y * origDataWidth + x];
		}
	}

}

auto cMain::ApplyFFCOnData
(
	unsigned short* const inRawData, 
	unsigned short* const inBlackData, 
	unsigned short* const inWhiteData, 
	const int imgWidth
) -> void
{
	for (auto i{ 0 }; i < imgWidth * imgWidth; ++i)
	{
		double numerator = (double)inRawData[i] - (double)inBlackData[i];
		//double denominator = std::max(1.0, (double)inWhiteData[i] - (double)inBlackData[i]);
		//auto outValue = std::max(0.0, numerator / denominator);
		auto outValue = std::max(0.0, numerator);
		outValue = std::min(outValue, (double)USHRT_MAX);
		inRawData[i] = static_cast<unsigned short>(outValue);
	}
}


auto cMain::RemoveBackgroundFromTheImage(wxString imagePath) -> void
{
	wxImage image;

	// Load the PNG image
	if (!image.LoadFile(imagePath))
	{
		wxLogError("Failed to load image.");
		return;
	}

	// Convert wxImage to wxBitmap for processing
	wxBitmap bitmap(image);

	int minX = image.GetWidth();
	int minY = image.GetHeight();
	int maxX = 0;
	int maxY = 0;

	// Scan the image to find the non-white border
	for (int y = 0; y < image.GetHeight(); ++y)
	{
		for (int x = 0; x < image.GetWidth(); ++x)
		{
			auto red = image.GetRed(x, y);
			auto green = image.GetGreen(x, y);
			auto blue = image.GetBlue(x, y);

			// Check if the pixel is non-white (you can adjust the tolerance if necessary)
			if (red < 255 || green < 255 || blue < 255)
			{
				minX = std::min(minX, x);
				minY = std::min(minY, y);
				maxX = std::max(maxX, x);
				maxY = std::max(maxY, y);
			}
		}
	}

	// Now, crop the image to remove the white border
	wxImage croppedImage = image.GetSubImage(wxRect(minX, minY, maxX - minX + 1, maxY - minY + 1));
	if (!croppedImage.SaveFile(imagePath, wxBITMAP_TYPE_PNG)) return;
}

auto cMain::Create2DImageInGrayscale(unsigned short* const inData, const int imgWidth) -> wxBitmap
{
	auto scaleFactor = 2500 / imgWidth;
	scaleFactor = scaleFactor < 1 ? 1 : scaleFactor;
	wxImage colormapImage(scaleFactor * imgWidth, scaleFactor * imgWidth);

	//auto outImageSize = wxSize(1.2 * colormapImage.GetWidth(), 1.2 * colormapImage.GetHeight());
	auto outImageSize = wxSize(colormapImage.GetWidth(), colormapImage.GetHeight());

	wxBitmap bitmap(outImageSize.GetWidth(), outImageSize.GetHeight());
	wxMemoryDC dc(bitmap);

	// Clear the bitmap
	dc.SetBackground(*wxWHITE_BRUSH);
	dc.Clear();

	{
		auto maxValue = *std::max_element(inData, inData + imgWidth * imgWidth);
		unsigned short current_value{};
		unsigned char red{}, green{}, blue{};
		unsigned long long position_in_data_pointer{};

		for (auto y{ 0 }; y < colormapImage.GetHeight(); y += scaleFactor)
		{
			for (auto x{ 0 }; x < colormapImage.GetWidth(); x += scaleFactor)
			{
				current_value = inData[position_in_data_pointer];
				red = static_cast<unsigned char>((maxValue - current_value) * UCHAR_MAX / maxValue);
				//colormapImage.SetRGB(x, y, red, red, red);
				//m_CamPreview->CalculateMatlabJetColormapPixelRGB12bit(current_value, red, green, blue);
				for (auto yInside{ y }; yInside < y + scaleFactor; ++yInside)
				{
					for (auto xInside{ x }; xInside < x + scaleFactor; ++xInside)
					{
						colormapImage.SetRGB(xInside, yInside, red, red, red);
					}
				}
				++position_in_data_pointer;
			}
		}
	}
	wxBitmap imageBitmap(colormapImage);
	//wxBitmap imageBitmap(colormapImage.Scale(imgWidth * 4, imgWidth * 4, wxIMAGE_QUALITY_HIGH));
	dc.DrawBitmap
	(
		imageBitmap, 
		(outImageSize.GetWidth() - colormapImage.GetWidth()) / 2, 
		(outImageSize.GetHeight() - colormapImage.GetHeight()) / 2,
		true
	);

	dc.SelectObject(wxNullBitmap);
	return bitmap;
}

auto cMain::GeneratePDFReportUsingLatex
(
	wxString folderContainingTEXFile, 
	wxString folderWithData,
	wxString pdfFileName,
	const MainFrameVariables::ImagesFilePaths& imageFilePaths,
	const GenerateReportVariables::ReportParameters& reportParameters,
	const wxString timeStamp
) -> wxString
{
	constexpr auto raise_exception_msg = [](int code) 
	{
		wxString title = "CMD execution error";
		wxMessageBox(
			wxT
			(
				"Failed to run CMD script. Error code: " + wxString::Format(wxT("%i"), code)
			),
			title,
			wxICON_ERROR);
	};

	wxString filename, sourceFilePath, destinationFilePath;

	// Copy the TEX Template file
	{
		wxDir dir(folderContainingTEXFile);
		if (!dir.IsOpened())
		{
			wxPuts("Failed to open source directory.");
			return "";
		}

		bool found = dir.GetFirst(&filename, "*.tex", wxDIR_FILES); // Find first .tex file

		if (!found) return "";

		sourceFilePath = folderContainingTEXFile;
		sourceFilePath += folderContainingTEXFile.EndsWith("\\") ? filename : "\\" + filename;

		destinationFilePath = folderWithData;
		destinationFilePath += folderWithData.EndsWith("\\") ? filename : "\\" + filename;

		wxFileName file(destinationFilePath);
		file.SetName(wxString("Report_") + timeStamp);
		destinationFilePath = file.GetFullPath();

		if (!wxCopyFile(sourceFilePath, destinationFilePath, true)) return ""; // Overwrite if exists
	}

	// Replace Content inside the TEX file
	wxString placeholder = "{#ReportName}";
	ReplacePlaceholderInTexFile(destinationFilePath, placeholder, reportParameters.reportName);
	placeholder = "{#Customer}";
	ReplacePlaceholderInTexFile(destinationFilePath, placeholder, reportParameters.customer);
	placeholder = "{#Author}";
	ReplacePlaceholderInTexFile(destinationFilePath, placeholder, reportParameters.author);
	placeholder = "{#SerialNumber}";
	ReplacePlaceholderInTexFile(destinationFilePath, placeholder, reportParameters.serialNumber);
	placeholder = "{#OpticsProductNumber}";
	ReplacePlaceholderInTexFile(destinationFilePath, placeholder, reportParameters.opticsProductNumber);
	placeholder = "{#OpticsType}";
	ReplacePlaceholderInTexFile(destinationFilePath, placeholder, reportParameters.opticsType);

	// Double Parameters
	{
		placeholder = "{#Focus}";
		ReplacePlaceholderInTexFile
		(
			destinationFilePath,
			placeholder,
			wxString::Format(wxT("%.2f"), reportParameters.focus)
		);
		placeholder = "{#Step}";
		ReplacePlaceholderInTexFile
		(
			destinationFilePath,
			placeholder,
			wxString::Format(wxT("%.3f"), reportParameters.step)
		);
	}

	// Int Parameters
	{
		placeholder = "{#FocusExposure}";
		ReplacePlaceholderInTexFile
		(
			destinationFilePath,
			placeholder,
			wxString::Format(wxT("%i"), reportParameters.focusExposure)
		);

		placeholder = "{#CircleExposure}";
		ReplacePlaceholderInTexFile
		(
			destinationFilePath,
			placeholder,
			wxString::Format(wxT("%i"), reportParameters.circleExposure)
		);
	}

	// Paths
	placeholder = "{#LogoImage}";
	ReplacePlaceholderInTexFile(destinationFilePath, placeholder, ConvertToForwardSlashes(imageFilePaths.logoPath));
	placeholder = "{#OpticsScheme}";
	ReplacePlaceholderInTexFile(destinationFilePath, placeholder, ConvertToForwardSlashes(imageFilePaths.opticsScheme));
	placeholder = "{#FWHMDiagram}";
	ReplacePlaceholderInTexFile(destinationFilePath, placeholder, ConvertToForwardSlashes(imageFilePaths.fwhmPath));
	placeholder = "{#GainDiagram}";
	ReplacePlaceholderInTexFile(destinationFilePath, placeholder, ConvertToForwardSlashes(imageFilePaths.gainPath));

	{
		wxArrayString texBlocks;
		int generateBlockCalls{};
		// Optimal Position Images
		for (auto i{ 0 }; i < imageFilePaths.optimalPositionArray.GetCount(); ++i)
		{
			auto isPositiveNumber = reportParameters.optimalPositionsArray[i] > 0.0 ? true : false;
			auto outSign = reportParameters.optimalPositionsArray[i] == reportParameters.focus ? wxString("= ") : (isPositiveNumber ? wxString("+") : wxString(""));

			texBlocks.Add(GenerateLatexSmallImageBlock
			(
				ConvertToForwardSlashes(imageFilePaths.optimalPositionArray[i]),
				outSign + FormatNumber(reportParameters.optimalPositionsArray[i]),
				reportParameters.optimalPositionsArray[i] == reportParameters.focus || generateBlockCalls == 2
			));

			generateBlockCalls = generateBlockCalls == 2 || reportParameters.optimalPositionsArray[i] == reportParameters.focus ? 0 : ++generateBlockCalls;
		}
		wxString marker = "% BEGIN_FOCUSIMAGES";
		InsertLatexAtMarker(destinationFilePath, marker, texBlocks);
	}

	// Best Position
	placeholder = "{#Best2DImage}";
	ReplacePlaceholderInTexFile
	(
		destinationFilePath, 
		placeholder, 
		ConvertToForwardSlashes(imageFilePaths.best2DImage)
	);

	placeholder = "{#Best3DImage}";
	ReplacePlaceholderInTexFile
	(
		destinationFilePath, 
		placeholder, 
		ConvertToForwardSlashes(imageFilePaths.best3DImage)
	);

	placeholder = "{#BestHorizontalProfile}";
	ReplacePlaceholderInTexFile
	(
		destinationFilePath, 
		placeholder, 
		ConvertToForwardSlashes(imageFilePaths.bestHorizontalProfile)
	);

	placeholder = "{#BestVerticalProfile}";
	ReplacePlaceholderInTexFile
	(
		destinationFilePath, 
		placeholder, 
		ConvertToForwardSlashes(imageFilePaths.bestVerticalProfile)
	);

	placeholder = "{#BestGreyscaleImage}";
	ReplacePlaceholderInTexFile
	(
		destinationFilePath, 
		placeholder, 
		ConvertToForwardSlashes(imageFilePaths.bestGreyscaleImage)
	);

	// Circle Position
	for (auto i{ 0 }; i < imageFilePaths.circleArray.GetCount(); ++i)
	{
		placeholder = "{#CirclePosition" + wxString::Format(wxT("%i"), i + 1) + "}";
		ReplacePlaceholderInTexFile
		(
			destinationFilePath, 
			placeholder, 
			ConvertToForwardSlashes(imageFilePaths.circleArray[i])
		);
	}

	// X-Ray Images
	bool isXRayArrayEmpty{ true };

	for (const auto& str : imageFilePaths.xRayArray)
		isXRayArrayEmpty = str.IsEmpty();

	if (!isXRayArrayEmpty)
	{
		wxArrayString texBlocks;
		wxString latex{};
		latex << "\\newpage" << "\n";
		latex << "\\section{X-Ray Test}" << "\n";
		texBlocks.Add(latex);

		for (auto i{ 0 }; i < imageFilePaths.xRayArray.GetCount(); ++i)
		{
			//if (i % 3 == 0)
				//texBlocks.Add("\\newpage");

			texBlocks.Add(GenerateLatexBigImageBlock
			(
				ConvertToForwardSlashes(imageFilePaths.xRayArray[i]), 
				reportParameters.xRayImagesCaption[i]
			));
		}
		wxString marker = "% BEGIN_XRAYIMAGES";
		InsertLatexAtMarker(destinationFilePath, marker, texBlocks);
	}

	//if (isXRayArrayEmpty)
	//{
	//	RemoveSectionFromFile(destinationFilePath, "% START_REMOVE", "% END_REMOVE");
	//}
	//else
	//{
	//	for (auto i{ 0 }; i < imageFilePaths.xRayArray.GetCount(); ++i)
	//	{
	//		placeholder = "{#XRayImage" + wxString::Format(wxT("%i"), i + 1) + "}";
	//		ReplacePlaceholderInTexFile
	//		(
	//			destinationFilePath, 
	//			placeholder, 
	//			ConvertToForwardSlashes(imageFilePaths.xRayArray[i])
	//		);
	//	}
	//}

	ExecuteLatex(destinationFilePath);

	wxFileName file(destinationFilePath);
	// Replacing *.tex extension to *.pdf
	file.SetExt("pdf");

	wxRenameFile(file.GetFullPath(), pdfFileName, true);

	wxLaunchDefaultApplication(pdfFileName);

	return pdfFileName;
}

auto cMain::RemoveAllUnnecessaryFilesFromFolder(const wxString& folder, wxArrayString removeExtensions) -> void
{
	if (!wxDir::Exists(folder)) {
		wxLogError("Folder does not exist: %s", folder);
		return;
	}

	wxDir dir(folder);
	if (!dir.IsOpened()) {
		wxLogError("Failed to open directory: %s", folder);
		return;
	}

	wxString filename;
	bool cont = dir.GetFirst(&filename, wxEmptyString, wxDIR_FILES);

	while (cont) 
	{
		wxFileName filePath(folder, filename);
		wxString ext = filePath.GetExt().Lower();

		if (removeExtensions.Index(ext, /*caseSensitive=*/false) != wxNOT_FOUND) 
		{
			if (!wxRemoveFile(filePath.GetFullPath())) 
			{
				wxLogError("Failed to delete: %s", filePath.GetFullPath());
			}
		}

		cont = dir.GetNext(&filename);
	}
}

bool cMain::Cancelled()
{
	wxCriticalSectionLocker lock(m_CSCancelled);
	return m_Cancelled;
}

void cMain::OnValueDisplayingCheck(wxCommandEvent& evt)
{
	m_IsValueDisplayingChecked = m_MenuBar->menu_tools->IsChecked(MainFrameVariables::ID_MENUBAR_TOOLS_VALUE_DISPLAYING);
	m_CamPreview->SetValueDisplayingActive(m_IsValueDisplayingChecked);
}

void cMain::UpdateAllAxisGlobalPositions()
{
	/* Detectors */
	m_Detector[0].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), m_Settings->GetActualMotorPosition(SettingsVariables::DETECTOR_X)));
	m_Detector[1].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), m_Settings->GetActualMotorPosition(SettingsVariables::DETECTOR_Y)));
	m_Detector[2].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), m_Settings->GetActualMotorPosition(SettingsVariables::DETECTOR_Z)));
	/* Optics */
	m_Optics[0].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), m_Settings->GetActualMotorPosition(SettingsVariables::OPTICS_X)));
	m_Optics[1].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), m_Settings->GetActualMotorPosition(SettingsVariables::OPTICS_Y)));
	m_Optics[2].absolute_text_ctrl->ChangeValue(wxString::Format(wxT("%.3f"), m_Settings->GetActualMotorPosition(SettingsVariables::OPTICS_Z)));
}

void cMain::ExposureValueChanged(wxCommandEvent& evt)
{
	if (!m_StartStopLiveCapturingTglBtn->GetValue()) return;

	// Stop acquisition
	m_StartStopLiveCapturingTglBtn->SetValue(!m_StartStopLiveCapturingTglBtn->GetValue());
	wxCommandEvent artStartStopLiveCapturingPressed(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN);
	ProcessEvent(artStartStopLiveCapturingPressed);

	// Start acquisition
	m_StartStopLiveCapturingTglBtn->SetValue(!m_StartStopLiveCapturingTglBtn->GetValue());
	ProcessEvent(artStartStopLiveCapturingPressed);
}

auto cMain::OnGenerateReportBtn(wxCommandEvent& evt) -> void
{
	wxString venvFolderName = ".venv";
	wxString reportGeneratorPath = wxGetCwd();
	auto reportGeneratorPathName = wxString("src\\ReportGenerator");
	reportGeneratorPath += reportGeneratorPath.EndsWith("\\") ? reportGeneratorPathName : wxString("\\") + reportGeneratorPathName;
	auto requirementsFileName = wxString("requirements.txt");
	wxString requirementsPath = reportGeneratorPath;
	requirementsPath += requirementsPath.EndsWith("\\") ? requirementsFileName : wxString("\\") + requirementsFileName;
	wxString venvPath = reportGeneratorPath;
	venvPath += venvPath.EndsWith("\\") ? venvFolderName : wxString("\\") + venvFolderName;

	if (!IsVirtualEnvironmentAlreadyCreated(venvPath))
	{
		if (!IsPythonInstalledOnTheCurrentMachine()) return;
		if (!CreateVirtualEnvironment(venvPath, requirementsPath)) return;
		if (!CheckLatexPresence()) return;
	}

	auto inputParameters = GenerateReportVariables::InputParameters();
	inputParameters.pixelSizeUM = m_Settings->GetPixelSizeUM();
	inputParameters.widthROIMM = m_Settings->GetCropSizeMM();
	inputParameters.widthCircleROIMM = m_Settings->GetCropCircleSizeMM();
	inputParameters.xRayImagesDefaultCaption = m_Settings->GetXRayImagesDefaultCaption();
	auto uploadReportFolder = m_Settings->GetUploadReportFolder();

	auto cropWindowSize = static_cast<int>(std::ceil(inputParameters.widthROIMM / (inputParameters.pixelSizeUM / 1000.0)));
	auto cropCircleWindowSize = static_cast<int>(std::ceil(inputParameters.widthCircleROIMM / (inputParameters.pixelSizeUM / 1000.0)));

	cGenerateReportDialog dialog
	(
		this,
		inputParameters
	);

	auto retCode = dialog.ShowModal();
	if (retCode == wxID_CANCEL) return;

	auto reportParameters = dialog.GetReportParameters();

	//auto startPositionMM = 22.5;
	//auto stepMM = 0.025;

	wxString outDirName{}, outFileName{};;
	wxString outDirWithFileName{};

#ifndef _DEBUG
	wxBusyCursor busy;
#endif // !_DEBUG

#ifdef _DEBUG
	outDirName = wxString("D:\\Projects\\RIGAKU\\MMCam\\MMCam\\src\\dbg_fld");
	outFileName = wxString("Test.pdf");
	outDirWithFileName = outDirName;
	outDirWithFileName += outDirName.EndsWith("\\") ? outFileName : wxString("\\") + outFileName;
#else
	wxFileDialog save_dialog
	(
		NULL,
		"Set output file name",
		"",
		outFileName,
		"PDF files (*.pdf)|*.pdf",
		wxFD_SAVE | wxFD_OVERWRITE_PROMPT
	);

	if (save_dialog.ShowModal() == wxID_CANCEL)
		return;
	outDirWithFileName = save_dialog.GetPath();
	wxFileName fileName(outDirWithFileName);
	outDirName = fileName.GetPath();
#endif // _DEBUG

	MainFrameVariables::ImagesFilePaths imageFilePaths{};

	// Logo Path
	{
		auto logoPath = reportGeneratorPath;
		auto logoName = wxString("logo.png");
		logoPath += reportGeneratorPath.EndsWith("\\") ? logoName : wxString("\\") + logoName;
		wxFileName file(logoPath);
		imageFilePaths.logoPath = file.GetFullPath();
	}

	// Optics Scheme
	imageFilePaths.opticsScheme = dialog.GetOpticsSchemePath();
	imageFilePaths.xRayArray = dialog.GetXRayImagesPaths();

	// Create outputImages folder
	wxDateTime nowDateTime = wxDateTime::Now();
	wxString timestamp = nowDateTime.Format(wxT("%d_%m_%Y_%H_%M_%S"));
	auto outTempDirName = wxString("ReportGeneration_" + timestamp + "\\");

	// Format the date and time
	auto tempFolderPath = outDirName;
	tempFolderPath += outDirName.EndsWith("\\") ? outTempDirName : wxString("\\") + outTempDirName;
	wxFileName tempFolder(tempFolderPath);

	// Check if the folder exists
	if (!tempFolder.DirExists()) 
	{
		// Try to create the folder
		if (!wxFileName::Mkdir(tempFolderPath, wxS_DIR_DEFAULT, wxPATH_MKDIR_FULL)) 
			return;
	}

	auto origBlackImagePath = dialog.GetOriginalBlackImagePath();
	auto origWhiteImagePath = dialog.GetOriginalWhiteImagePath();
	auto imagesForCalculationPath = dialog.GetImagesForCalculationPaths();

	auto circleBlackImagePath = dialog.GetCircleBlackImagePath();
	auto circleImagesForCalculationPath = dialog.GetCircleImagesForCalculationPaths();

	cv::Mat originalWhiteImage = cv::imread(origWhiteImagePath.ToStdString(), cv::IMREAD_UNCHANGED);
	cv::Mat originalBlackImage = cv::imread(origBlackImagePath.ToStdString(), cv::IMREAD_UNCHANGED);

	cv::Mat circleBlackImage = cv::imread(circleBlackImagePath.ToStdString(), cv::IMREAD_UNCHANGED);

	auto croppedRAWData = std::make_unique<unsigned short[]>(cropWindowSize * cropWindowSize);
	auto croppedBlackRAWData = std::make_unique<unsigned short[]>(cropWindowSize * cropWindowSize);
	auto croppedWhiteRAWData = std::make_unique<unsigned short[]>(cropWindowSize * cropWindowSize);
	auto bestCroppedRAWData = std::make_unique<unsigned short[]>(cropWindowSize * cropWindowSize);

	auto horizontalFWHM = std::make_unique<double[]>(imagesForCalculationPath.GetCount());
	auto verticalFWHM = std::make_unique<double[]>(imagesForCalculationPath.GetCount());

	auto gainMax = std::make_unique<double[]>(imagesForCalculationPath.GetCount());
	auto gainFWHM = std::make_unique<double[]>(imagesForCalculationPath.GetCount());

	auto bestHorizontalIntensityProfile = std::make_unique<unsigned short[]>(cropWindowSize);
	auto bestVerticalIntensityProfile = std::make_unique<unsigned short[]>(cropWindowSize);

	int bestXPos{}, bestYPos{};
	int i{};
	wxArrayString originalImagesPathArray{}, circleImagesPathArray{};
	double bestGainMax{};
	int bestPosInGain{};
	auto bestFocusPos{ reportParameters.start };
	auto bestI{ i };
	int lineProfileX{}, lineProfileY{};
	double bestHorizontalFWHM{}, bestVerticalFWHM{};

    for (const auto& filePath : imagesForCalculationPath)
    {
		if (!wxFileName::FileExists(filePath)) continue;
		cv::Mat rawImage = cv::imread(filePath.ToStdString(), cv::IMREAD_UNCHANGED);
		if (rawImage.size() != originalBlackImage.size() || rawImage.type() != originalBlackImage.type()) continue;

		FindSpotCenterCoordinates(rawImage, &bestXPos, &bestYPos);
		if (bestXPos - cropWindowSize / 2 < 0 || bestXPos + cropWindowSize / 2 >= rawImage.cols
			|| bestYPos - cropWindowSize / 2 < 0 || bestYPos + cropWindowSize / 2 >= rawImage.rows) continue;

		auto startX = bestXPos - cropWindowSize / 2;
		auto startY = bestYPos - cropWindowSize / 2;

		// RAW Data
		CropDataIntoArray
		(
			rawImage, 
			startX, 
			startY, 
			cropWindowSize, 
			croppedRAWData.get()
		);

		// Black FFC RAW Data
		CropDataIntoArray
		(
			originalBlackImage, 
			startX, 
			startY, 
			cropWindowSize, 
			croppedBlackRAWData.get()
		);

		// White FFC RAW Data
		CropDataIntoArray
		(
			originalWhiteImage, 
			startX, 
			startY, 
			cropWindowSize, 
			croppedWhiteRAWData.get()
		);

		gainMax[i] = FindGainMaxInArrayData
		(
			croppedRAWData.get(), 
			croppedWhiteRAWData.get(), 
			cropWindowSize
		);

		ApplyFFCOnData
		(
			croppedRAWData.get(), 
			croppedBlackRAWData.get(), 
			croppedWhiteRAWData.get(), 
			cropWindowSize
		);


		auto horizontalSumArray = std::make_unique<unsigned int[]>(cropWindowSize);
		auto verticalSumArray = std::make_unique<unsigned int[]>(cropWindowSize);

		FWHM::CalculateSumVertically(croppedRAWData.get(), cropWindowSize, cropWindowSize, horizontalSumArray.get());
		horizontalFWHM[i] = FWHM::CalculateFWHM
			(
				horizontalSumArray.get(), 
				cropWindowSize
			);
		horizontalFWHM[i] = horizontalFWHM[i] == - 1.0 ? 0.0 : horizontalFWHM[i];
		horizontalFWHM[i] *= inputParameters.pixelSizeUM;

		FWHM::CalculateSumHorizontally(croppedRAWData.get(), cropWindowSize, cropWindowSize, verticalSumArray.get());
		verticalFWHM[i] = FWHM::CalculateFWHM
			(
				verticalSumArray.get(), 
				cropWindowSize
			);
		verticalFWHM[i] = verticalFWHM[i] == - 1.0 ? 0.0 : verticalFWHM[i];
		verticalFWHM[i] *= inputParameters.pixelSizeUM;

		if (gainMax[i] > bestGainMax)
		{
			bestGainMax = gainMax[i];
			bestPosInGain = i;
			bestFocusPos = reportParameters.start + i * reportParameters.step;
			lineProfileX = bestXPos - startX;
			lineProfileY = bestYPos - startY;
			bestHorizontalFWHM = horizontalFWHM[i];
			bestVerticalFWHM = verticalFWHM[i];

			reportParameters.focus = reportParameters.start + i * reportParameters.step;
			bestI = i;

			memcpy(bestCroppedRAWData.get(), croppedRAWData.get(), sizeof(unsigned short) * cropWindowSize * cropWindowSize);

			// Copying Horizontal Intensity Profile
			memcpy(bestHorizontalIntensityProfile.get(), croppedRAWData.get() + cropWindowSize * lineProfileY, sizeof(unsigned short) * cropWindowSize);

			// Copying Vertical Intensity Profile
			for (auto y{0}; y < cropWindowSize; ++y)
				bestVerticalIntensityProfile[y] = croppedRAWData[y * cropWindowSize + lineProfileX];
		}

		gainFWHM[i] = FindGainFWHMInArrayData
		(
			croppedRAWData.get(), 
			croppedWhiteRAWData.get(), 
			cropWindowSize
		);

        wxFileName file(filePath);
		file.SetExt("png");
        auto correctedFileName = wxString("ffc_") + file.GetFullName();
		auto correctedFileNameWithPath = tempFolderPath + correctedFileName;
		originalImagesPathArray.Add(correctedFileNameWithPath);
		imageFilePaths.optimalPositionArray.Add(correctedFileNameWithPath);

		WriteTempJSONImageDataToTXTFile
		(
			croppedRAWData.get(), 
			cropWindowSize, 
			cropWindowSize, 
			"plasma",
			inputParameters.pixelSizeUM,
			correctedFileNameWithPath
		);

		++i;
    }

//#ifndef _DEBUG
	if (!Invoke2DPlotsCreation(originalImagesPathArray)) return;
	for (const auto& imagePath : originalImagesPathArray)
	{
		wxFileName file(imagePath);
		file.SetExt("png");
		RemoveBackgroundFromTheImage(file.GetFullPath());
	}
//#endif // DEBUG

//#ifndef _DEBUG
	// Best Position Plots Creation
	{
		auto best2DFileNameWithPath = tempFolderPath + "best2D.png";
		wxFileName file(best2DFileNameWithPath);
		imageFilePaths.best2DImage = file.GetFullPath();
		
		// 2D Image
		{
			WriteTempJSONImageDataToTXTFile
			(
				bestCroppedRAWData.get(),
				cropWindowSize,
				cropWindowSize,
				"plasma",
				inputParameters.pixelSizeUM,
				file.GetFullPath()
			);

			file.SetExt("txt");
			wxArrayString arrStr{};
			arrStr.Add(file.GetFullPath());
			if (!Invoke2DPlotsCreation(arrStr)) return;
			file.SetExt("png");
			RemoveBackgroundFromTheImage(file.GetFullPath());
		}

		// 3D Image
		{
			file.SetFullName("best3D.png");
			imageFilePaths.best3DImage = file.GetFullPath();

			WriteTempJSONImageDataToTXTFile
			(
				bestCroppedRAWData.get(),
				cropWindowSize,
				cropWindowSize,
				"plasma",
				inputParameters.pixelSizeUM,
				file.GetFullPath()
			);

			file.SetExt("txt");
			if (!InvokePlotGraphCreation("plot3DGraph", file.GetFullPath())) return;
			file.SetExt("png");
			RemoveBackgroundFromTheImage(file.GetFullPath());
		}

		// Horizontal Intensity Profile
		{
			file.SetFullName("bestHorizontalProfile.png");
			imageFilePaths.bestHorizontalProfile = file.GetFullPath();

			// Generating Horizontal (X) array
			auto bestHorizontalIntensityProfileX = std::make_unique<double[]>(cropWindowSize);
			{
				for (auto i{ 0 }; i < cropWindowSize; ++i)
					bestHorizontalIntensityProfileX[i] = (i - lineProfileX) * (inputParameters.pixelSizeUM / 1000.0);
			}

			auto title = wxString("Horizontal FWHM = ");
			title += wxString::Format(wxT("%.2f"), bestHorizontalFWHM);
			title += " [um]";
			WriteTempJSONLineProfileDataToTXTFile
			(
				bestHorizontalIntensityProfile.get(),
				bestHorizontalIntensityProfileX.get(),
				cropWindowSize,
				title.ToStdString(),
				"Distance [mm]",
				"Intensity [a.u.]",
				"#ed1c24",
				file.GetFullPath()
			);

			file.SetExt("txt");
			if (!InvokePlotGraphCreation("plotLineProfileGraph", file.GetFullPath())) return;

			file.SetExt("png");
			RemoveBackgroundFromTheImage(file.GetFullPath());
		}

		// Vertical Intensity Profile
		{
			file.SetFullName("bestVerticalProfile.png");
			imageFilePaths.bestVerticalProfile = file.GetFullPath();

			// Generating Horizontal (X) array
			auto bestVerticalIntensityProfileX = std::make_unique<double[]>(cropWindowSize);
			{
				for (auto i{ 0 }; i < cropWindowSize; ++i)
					bestVerticalIntensityProfileX[i] = (i - lineProfileY) * (inputParameters.pixelSizeUM / 1000.0);
			}

			auto title = wxString("Vertical FWHM = ");
			title += wxString::Format(wxT("%.2f"), bestVerticalFWHM);
			title += " [um]";
			WriteTempJSONLineProfileDataToTXTFile
			(
				bestVerticalIntensityProfile.get(),
				bestVerticalIntensityProfileX.get(),
				cropWindowSize,
				title.ToStdString(),
				"Distance [mm]",
				"Intensity [a.u.]",
				"#ed1c24",
				file.GetFullPath()
			);

			file.SetExt("txt");
			if (!InvokePlotGraphCreation("plotLineProfileGraph", file.GetFullPath())) return;

			file.SetExt("png");
			RemoveBackgroundFromTheImage(file.GetFullPath());
		}

		// Grayscale Image
		{
			file.SetFullName("bestGreyscale.png");
			imageFilePaths.bestGreyscaleImage = file.GetFullPath();

			auto croppGreyscaleImageWidth = static_cast<int>(std::max(bestHorizontalFWHM, bestVerticalFWHM));
			croppGreyscaleImageWidth *= 2;

			auto startX = lineProfileX - croppGreyscaleImageWidth / 2;
			auto startY = lineProfileY - croppGreyscaleImageWidth / 2;
			
			auto croppedGreyscaleImageData = std::make_unique<unsigned short[]>(croppGreyscaleImageWidth * croppGreyscaleImageWidth);

			CropDataIntoArray
			(
				bestCroppedRAWData.get(), 
				cropWindowSize, 
				startX, 
				startY, 
				croppGreyscaleImageWidth, 
				croppedGreyscaleImageData.get()
			);

			WriteTempJSONImageDataToTXTFile
			(
				croppedGreyscaleImageData.get(),
				croppGreyscaleImageWidth,
				croppGreyscaleImageWidth,
				"gist_yarg",
				inputParameters.pixelSizeUM,
				file.GetFullPath()
			);

			file.SetExt("txt");
			wxArrayString arrStr{};
			arrStr.Add(file.GetFullPath());
			if (!Invoke2DPlotsCreation(arrStr)) return;

			file.SetExt("png");
			RemoveBackgroundFromTheImage(file.GetFullPath());

			//auto bmp = Create2DImageInGrayscale(croppedRAWData.get(), cropWindowSize);
			//if (!bmp.SaveFile(file.GetFullPath(), wxBITMAP_TYPE_PNG)) return;
		}

	}
//#endif // !_DEBUG

//#ifndef _DEBUG
	// FWHM Plot Creation
	{
		auto fwhmFileName = tempFolderPath + "fwhm_data.png";
		wxFileName file(fwhmFileName);

		imageFilePaths.fwhmPath = file.GetFullPath();

		WriteTempJSONDataToTXTFile
		(
			horizontalFWHM.get(),
			"Horizontal",
			"b",
			"Focal length [mm]",
			verticalFWHM.get(),
			"Vertical",
			"g",
			"FWHM [um]",
			imagesForCalculationPath.GetCount(),
			reportParameters.start,
			reportParameters.step,
			bestPosInGain,
			file.GetFullPath()
		);


		//file.SetExt("bmp");
		file.SetExt("txt");
		if (!InvokePlotGraphCreation("plotGraph", file.GetFullPath()));

		file.SetExt("png");
		RemoveBackgroundFromTheImage(file.GetFullPath());
	}

	// Gain Plot Creation
	{
		auto gainFileName = tempFolderPath + "gain_data.png";
		wxFileName file(gainFileName);

		imageFilePaths.gainPath = file.GetFullPath();

		WriteTempJSONDataToTXTFile
		(
			gainMax.get(),
			"Gain MAX",
			"c",
			"Focal length [mm]",
			gainFWHM.get(),
			"Gain FWHM",
			"m",
			"Gain [a.u.]",
			imagesForCalculationPath.GetCount(),
			reportParameters.start,
			reportParameters.step,
			bestPosInGain,
			file.GetFullPath()
		);


		//file.SetExt("bmp");
		file.SetExt("txt");
		if (!InvokePlotGraphCreation("plotGraph", file.GetFullPath()));

		file.SetExt("png");
		RemoveBackgroundFromTheImage(file.GetFullPath());
	}
//#endif // _DEBUG

//#ifndef _DEBUG
	// Circles
	i = 0;

	croppedRAWData = std::make_unique<unsigned short[]>(cropCircleWindowSize * cropCircleWindowSize);
	croppedBlackRAWData = std::make_unique<unsigned short[]>(cropCircleWindowSize * cropCircleWindowSize);
	croppedWhiteRAWData  = std::make_unique<unsigned short[]>(cropCircleWindowSize * cropCircleWindowSize);

    for (const auto& filePath : circleImagesForCalculationPath)
    {
		if (!wxFileName::FileExists(filePath)) continue;
		cv::Mat rawImage = cv::imread(filePath.ToStdString(), cv::IMREAD_UNCHANGED);
		if (rawImage.size() != circleBlackImage.size() || rawImage.type() != circleBlackImage.type()) continue;

		FindSpotCenterCoordinates(rawImage, &bestXPos, &bestYPos);
		if (bestXPos - cropCircleWindowSize / 2 < 0 || bestXPos + cropCircleWindowSize / 2 >= rawImage.cols
			|| bestYPos - cropCircleWindowSize / 2 < 0 || bestYPos + cropCircleWindowSize / 2 >= rawImage.rows) continue;

		auto startX = bestXPos - cropCircleWindowSize / 2;
		auto startY = bestYPos - cropCircleWindowSize / 2;

		// RAW Data
		CropDataIntoArray
		(
			rawImage, 
			startX, 
			startY, 
			cropCircleWindowSize, 
			croppedRAWData.get()
		);

		// Black FFC RAW Data
		CropDataIntoArray
		(
			circleBlackImage, 
			startX, 
			startY, 
			cropCircleWindowSize, 
			croppedBlackRAWData.get()
		);

		ApplyFFCOnData
		(
			croppedRAWData.get(), 
			croppedBlackRAWData.get(), 
			croppedWhiteRAWData.get(), 
			cropCircleWindowSize
		);

        wxFileName file(filePath);
		file.SetExt("png");
        auto correctedFileName = wxString("ffc_circle_") + file.GetFullName();
		auto correctedFileNameWithPath = tempFolderPath + correctedFileName;
		circleImagesPathArray.Add(correctedFileNameWithPath);
		imageFilePaths.circleArray.Add(correctedFileNameWithPath);

		WriteTempJSONImageDataToTXTFile
		(
			croppedRAWData.get(), 
			cropCircleWindowSize, 
			cropCircleWindowSize, 
			"plasma",
			inputParameters.pixelSizeUM,
			correctedFileNameWithPath
		);

		++i;
    }

	// Replace the seventh image for the original one
	imageFilePaths.circleArray[6] = imageFilePaths.best2DImage;
//#endif // _DEBUG

//#ifndef _DEBUG
	if (!Invoke2DPlotsCreation(circleImagesPathArray)) return;
	for (const auto& imagePath : circleImagesPathArray)
	{
		wxFileName file(imagePath);
		file.SetExt("png");
		RemoveBackgroundFromTheImage(file.GetFullPath());
	}
//#endif // DEBUG

	// Fill Optimal Positions Array
	reportParameters.optimalPositionsArray = std::make_unique<double[]>(imagesForCalculationPath.GetCount());
	for (i = 0; i < imagesForCalculationPath.GetCount(); ++i)
	{
		reportParameters.optimalPositionsArray[i] = (i - bestI) * reportParameters.step;
		if (i == bestI)
			reportParameters.optimalPositionsArray[i] = reportParameters.focus;
	}

	auto reportFilePath = GeneratePDFReportUsingLatex
	(
		reportGeneratorPath, 
		tempFolder.GetFullPath(),
		outDirWithFileName,
		imageFilePaths,
		reportParameters,
		timestamp
	);

	// Remove all unnecessary files from the destination folder
	{
		wxArrayString extensionsToRemove{};
		extensionsToRemove.Add("txt");
		extensionsToRemove.Add("aux");
		extensionsToRemove.Add("log");

		RemoveAllUnnecessaryFilesFromFolder(tempFolder.GetFullPath(), extensionsToRemove);
	}

	if (!uploadReportFolder.IsEmpty())
	{
		wxString targetFolder{};
		if (EnsureFolderHierarchy(uploadReportFolder, targetFolder))
			UploadReportToDestinationFolder(reportFilePath, targetFolder);
	}
}

auto cMain::IsPythonInstalledOnTheCurrentMachine() -> bool
{
	constexpr auto raise_exception_msg = [](wxString pythonVersion) 
	{
		wxString title = "Python installation was not found";
		wxMessageBox(
			wxT
			(
				"Python installation was not found. At least Python " + pythonVersion + " has to be installed for the correct working of the application!"
				"\nPlease, install Python of version " + pythonVersion + " and try again."
			),
			title,
			wxICON_ERROR);
	};

	auto pythonMinorVer = 12;
	wxArrayString output, errors;
	long exitCode = wxExecute("py --list", output, errors, wxEXEC_SYNC);

	std::vector<wxString> versions;
	std::regex versionPattern(R"(-V:3\.(\d+))");  // Extracts only the minor version (e.g., "12")
	std::smatch match;

	if (exitCode == 0) 
	{
		for (const auto& line : output) 
		{
			std::string lineStr = line.ToStdString();
			if (std::regex_search(lineStr, match, versionPattern)) 
			{
				wxString version = wxString(match[1]);  // Extract version number (e.g., "3.12")
				versions.push_back(version);
			}
		}
	}

	// Sort and return the highest version
	if (!versions.empty()) 
	{
		std::sort(versions.begin(), versions.end(), std::greater<>());
		long verInt = 1;
		versions.front().ToLong(&verInt);  // Latest version
		if (verInt < pythonMinorVer)
		{
			raise_exception_msg("3." + wxString::Format(wxT("%i"), pythonMinorVer));
			return false;
		}
		return true;
	}
	raise_exception_msg("3." + wxString::Format(wxT("%i"), pythonMinorVer));
	return false;
}

auto cMain::IsVirtualEnvironmentAlreadyCreated(wxString pathToVenv) -> bool
{
	auto activateFile = pathToVenv + "\\Scripts\\activate";
	if (wxFileExists(activateFile)) 
	{
		//wxPuts("File exists!");
		return true;
	}

	return false;
}

auto cMain::CreateVirtualEnvironment(wxString pathToVenv, wxString pathToRequirements) -> bool
{
	std::string command = "cmd /c \"py.exe -m venv \"" + pathToVenv.ToStdString() + " && ";
	command += "src\\ReportGenerator\\.venv\\Scripts\\activate && ";
	command += "pip install -r " + pathToRequirements + " && ";
	command += "deactivate\"";

	// Execute the Python script
	int result{};

	result = std::system(command.c_str());
	if (result != 0)
	{
		RaisePythonExceptionMSG(command, result);
		return false;
	}

	return true;
}

auto cMain::EnableControlsAfterCapturing() -> void
{
	EnableUsedAndDisableNonUsedMotors();
	//for (auto i = 0; i < 3; ++i)
	//{
	//	m_Detector[i].EnableAllControls();
	//	m_Optics[i].EnableAllControls();
	//}

	m_CamExposure->Enable();
	if (m_OutDirTextCtrl->GetValue() != "Save directory...")
		m_SingleShotBtn->Enable();
	m_StartStopLiveCapturingTglBtn->Enable();

	m_VerticalToolBar->tool_bar->EnableTool(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, true);
	m_MenuBar->submenu_intensity_profile->Enable(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, true);
	if (m_MenuBar->submenu_intensity_profile->IsChecked(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR))
	{
		m_CrossHairPosXTxtCtrl->Enable();
		m_CrossHairPosYTxtCtrl->Enable();
	}
	m_SetCrossHairPosTglBtn->Enable();

	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_RIGHT_CAM_SINGLE_SHOT_BTN, true);
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, true);
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_DARK_MODE, true);
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_FWHM_DISPLAYING, true);
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_MENUBAR_EDIT_SETTINGS, true);

	m_MenuBar->menu_tools->Enable(MainFrameVariables::ID_MENUBAR_TOOLS_VALUE_DISPLAYING, true);

	m_OutDirBtn->Enable();
	m_FirstStage->EnableAllControls();
}

auto cMain::DisableControlsBeforeCapturing() -> void
{
	for (auto i = 0; i < 3; ++i)
	{
		m_Detector[i].DisableAllControls();
		m_Optics[i].DisableAllControls();
	}

	m_CamExposure->Disable();
	m_SingleShotBtn->Disable();
	m_StartStopLiveCapturingTglBtn->Disable();

	m_VerticalToolBar->tool_bar->EnableTool(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, false);
	m_CrossHairPosXTxtCtrl->Disable();
	m_CrossHairPosYTxtCtrl->Disable();
	m_SetCrossHairPosTglBtn->Disable();

	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_RIGHT_CAM_SINGLE_SHOT_BTN, false);
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, false);
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_DARK_MODE, false);
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_MENUBAR_EDIT_ENABLE_FWHM_DISPLAYING, false);
	m_MenuBar->menu_edit->Enable(MainFrameVariables::ID_MENUBAR_EDIT_SETTINGS, false);
	m_MenuBar->submenu_intensity_profile->Enable(MainFrameVariables::ID_MENUBAR_TOOLS_CROSSHAIR, false);

	m_MenuBar->menu_tools->Enable(MainFrameVariables::ID_MENUBAR_TOOLS_VALUE_DISPLAYING, false);

	m_OutDirBtn->Disable();
	m_FirstStage->DisableAllControls();
}

void cMain::OnStartStopLiveCapturingMenu(wxCommandEvent& evt)
{
	if (m_MenuBar->menu_edit->IsChecked(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN))
	{
		m_StartStopLiveCapturingTglBtn->SetValue(true);
	}
	else
	{
		m_StartStopLiveCapturingTglBtn->SetValue(false);
	}
	wxCommandEvent art_start_live_pressed(wxEVT_TOGGLEBUTTON, MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN);
	ProcessEvent(art_start_live_pressed);
}

void cMain::OnStartStopLiveCapturingTglBtn(wxCommandEvent& evt)
{
	if (m_StartStopLiveCapturingTglBtn->GetValue())
	{
		if (!m_XimeaControl || !m_XimeaControl->IsCameraConnected())
		{
			m_StartStopLiveCapturingTglBtn->SetValue(false);
			m_StartStopLiveCapturingTglBtn->SetLabel(wxT("Start Live (L)"));
			if (m_MenuBar->menu_edit->IsChecked(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN))
				m_MenuBar->menu_edit->Check(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, false);
			return;
		}

		StartLiveCapturing();

		m_StartStopLiveCapturingTglBtn->SetLabel(wxT("Stop Live (L)"));
		if (!m_MenuBar->menu_edit->IsChecked(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN))
			m_MenuBar->menu_edit->Check(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, true);
	}
	else
	{	
		if (m_StartedThreads.size())
		{
			LOGI("StartedThreads.size(): ", (int)m_StartedThreads.size());
			m_StartedThreads.back().second = false;
			LOG("StartedThreads.back(): " + m_StartedThreads.back().first);

			{
				m_StartStopLiveCapturingTglBtn->Disable();
				m_StartStopMeasurementTglBtn->Disable();
				m_CamExposure->Disable();
				m_SingleShotBtn->Disable();
			}

			while (!m_StartedThreads.back().first.empty())
				wxThread::This()->Sleep(100);

			m_StartedThreads.pop_back();

			{
				m_StartStopLiveCapturingTglBtn->Enable();
				m_StartStopMeasurementTglBtn->Enable();
				m_CamExposure->Enable();
				m_SingleShotBtn->Enable();
			}
		}

		m_StartStopLiveCapturingTglBtn->SetLabel(wxT("Start Live (L)"));
		if (m_MenuBar->menu_edit->IsChecked(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN))
			m_MenuBar->menu_edit->Check(MainFrameVariables::ID_RIGHT_CAM_START_STOP_LIVE_CAPTURING_TGL_BTN, false);
	}
}

void cMain::OnXPosCrossHairTextCtrl(wxCommandEvent& evt)
{
	wxString str_x_pos = m_CrossHairPosXTxtCtrl->IsEmpty() ? wxString("1") : m_CrossHairPosXTxtCtrl->GetValue();
	int x_pos = wxAtoi(str_x_pos);
	m_CamPreview->SetXCrossHairPosFromParentWindow(x_pos);
}

void cMain::OnYPosCrossHairTextCtrl(wxCommandEvent& evt)
{
	wxString str_y_pos = m_CrossHairPosYTxtCtrl->IsEmpty() ? wxString("1") : m_CrossHairPosYTxtCtrl->GetValue();
	int y_pos = wxAtoi(str_y_pos);
	m_CamPreview->SetYCrossHairPosFromParentWindow(y_pos);
}

auto cMain::OnSetPosCrossHairTglBtn(wxCommandEvent& evt) -> void
{
	if (m_SetCrossHairPosTglBtn->GetValue())
	{
		m_CamPreview->SettingCrossHairPosFromParentWindow(true);
	}
	else
	{	
		m_CamPreview->SettingCrossHairPosFromParentWindow(false);
	}
}

/* ___ Start Live Capturing Thread ___ */
LiveCapturing::LiveCapturing
(
	cMain* main_frame,
	wxString* uniqueThreadKey,
	bool* aliveOrDeadThread,
	cCamPreview* cam_preview_window,
	XimeaControl* ximea_control,
	const int exposure_us
) 
	: m_MainFrame(main_frame), 
	m_UniqueThreadKey(uniqueThreadKey),
	m_AliveOrDeadThread(aliveOrDeadThread),
	m_CamPreviewWindow(cam_preview_window), 
	m_XimeaControl(ximea_control),
	m_ExposureUS(exposure_us) {}

wxThread::ExitCode LiveCapturing::Entry()
{
	constexpr auto raise_exception_msg = []() 
	{
		wxString title = "Connection error";
		wxMessageBox(
			wxT
			(
				"Current camera can't capture an image."
				"\nPlease, check if the camera is connected properly and restart the program."
			),
			title,
			wxICON_ERROR);
	};

	auto exit_thread = [&]()
	{
		*m_UniqueThreadKey = "";
		//m_XimeaCameraControl.release();
		m_XimeaControl = nullptr;
		//m_MainFrame->LiveCapturingFinishedCapturingAndDrawing(true);
	};	
	
	wxThreadEvent evt(wxEVT_THREAD, MainFrameVariables::ID_THREAD_LIVE_CAPTURING);

	//evt.SetInt(0);
	//wxQueueEvent(m_MainFrame, evt.Clone());

	//m_ThreadID = m_XimeaControl->AppendThread();
	auto text_id = "LiveCapturing ID: " + *m_UniqueThreadKey;
	LOG(text_id);

	if (!m_XimeaControl->IsCameraConnected())
	{	
		if (!m_XimeaControl->TryToReconnectLastSelectedCamera())
		{
			raise_exception_msg();
			evt.SetInt(0);
			wxQueueEvent(m_MainFrame, evt.Clone());
			exit_thread();
			return (wxThread::ExitCode)0;
		}
	}

	m_XimeaControl->SetExposureTime(m_ExposureUS);
	m_ImageSize.Set(m_XimeaControl->GetImageWidth(), m_XimeaControl->GetImageHeight());

	if (m_CamPreviewWindow->GetImageSize() != m_ImageSize)
		m_CamPreviewWindow->SetImageSize(m_ImageSize);
	//auto image_ptr = m_CamPreviewWindow->GetImagePtr();
	//auto short_data_ptr = m_CamPreviewWindow->GetDataPtr();

	auto drawingExecutionFinishedPtr = m_CamPreviewWindow->GetExecutionFinishedPtr();

	const auto checkingInterval = m_ExposureUS / 3;
	const auto interval = std::chrono::microseconds(checkingInterval);  

	m_MainFrame->LiveCapturingFinishedCapturingAndDrawing(false);

	while (m_MainFrame && *m_AliveOrDeadThread)
	{
		if (m_XimeaControl->IsCameraInitialized())
		{
			if (!m_XimeaControl->IsCameraConnected())
			{
				//raise_exception_msg();
				evt.SetInt(-1);
				wxQueueEvent(m_MainFrame, evt.Clone());
				exit_thread();
				return (wxThread::ExitCode)0;
			}

			auto dataPtr = std::make_unique<unsigned short[]>(m_ImageSize.GetWidth() * m_ImageSize.GetHeight());
			if (CaptureImage(dataPtr.get()))
			{
				while (*m_AliveOrDeadThread && !*drawingExecutionFinishedPtr)
				{
					LOG("Waiting for the Execution finishing.");
					std::this_thread::sleep_for(interval);
				}

				evt.SetInt(0);
				evt.SetPayload(dataPtr.release());
				wxQueueEvent(m_MainFrame, evt.Clone());
			}
			else
			{
				//raise_exception_msg();
				evt.SetInt(-1);
				wxQueueEvent(m_MainFrame, evt.Clone());
				//raise_exception_msg();
				exit_thread();
				return (wxThread::ExitCode)0;
			}

		}
		else
			wxThread::This()->Sleep(500);
	}
	exit_thread();
	return (wxThread::ExitCode)0;
}

auto LiveCapturing::CaptureImage
(
	unsigned short* dataPtr
) -> bool
{
	if (!dataPtr) return false;

	auto imgPtr = m_XimeaControl->GetImage();
	if (!imgPtr) return false;

	memcpy
	(
		dataPtr, 
		imgPtr, 
		sizeof(unsigned short) * m_ImageSize.GetWidth() * m_ImageSize.GetHeight()
	);

	return true;
}

auto LiveCapturing::UpdatePixelsMultithread
(
	unsigned short* short_data_ptr, 
	wxImage* image_ptr
) -> void
{
	auto numThreads = std::thread::hardware_concurrency();
	auto tileSize = m_ImageSize.GetHeight() % numThreads > 0 ? m_ImageSize.GetHeight() / numThreads + 1 : m_ImageSize.GetHeight() / numThreads;

	std::vector<std::thread> threads;
	threads.reserve(numThreads);

	for (auto i{ 0 }; i < numThreads; ++i)
	{
		auto start_x = 0;
		auto start_y = i * tileSize;
		auto finish_x = m_ImageSize.GetWidth();
		auto finish_y = (i + 1) * tileSize > m_ImageSize.GetHeight() ? m_ImageSize.GetHeight() : (i + 1) * tileSize;

		threads.emplace_back
		(
			std::thread
			(
			&LiveCapturing::AdjustImageParts, 
			this, 
			&short_data_ptr[start_y * m_ImageSize.GetWidth() + start_x], 
			image_ptr, 
			start_x, 
			start_y, 
			finish_x, 
			finish_y
			)
		);
	}

	for (auto& thread : threads)
	{
		thread.join();
	}
}

auto LiveCapturing::AdjustImageParts
(
	const unsigned short* data_ptr, 
	wxImage* image_ptr,
	const unsigned int start_x, 
	const unsigned int start_y, 
	const unsigned int finish_x, 
	const unsigned int finish_y
) -> void
{
	if (!data_ptr) return;
	if (!image_ptr->IsOk()) return;
	unsigned short current_value{};
	unsigned char red{}, green{}, blue{};
	unsigned long long position_in_data_pointer{};

	for (auto y{ start_y }; y < finish_y; ++y)
	{
		for (auto x{ start_x }; x < finish_x; ++x)
		{
			current_value = data_ptr[position_in_data_pointer];
			/* Matlab implementation of JetColormap */
			/* Because XIMEA camera can produce 12-bit per pixel maximum, we use RGB12bit converter */
			m_CamPreviewWindow->CalculateMatlabJetColormapPixelRGB12bit(current_value, red, green, blue);
			image_ptr->SetRGB(x, y, red, green, blue);
			++position_in_data_pointer;
		}
	}
}

LiveCapturing::~LiveCapturing()
{
	m_MainFrame = nullptr;
	m_CamPreviewWindow = nullptr;
}
/* ___ End Live Capturing Thread ___ */

/* ___ Start Worker Thread ___ */
WorkerThread::WorkerThread
(
	cMain* main_frame,
	wxString* uniqueThreadKey,
	bool* aliveOrDeadThread,
	cSettings* settings, 
	cCamPreview* camera_preview_panel,
	XimeaControl* ximea_control,
	const wxString& path, 
	const unsigned long& exp_time_us,
	MainFrameVariables::AxisMeasurement* first_axis, 
	MainFrameVariables::AxisMeasurement* second_axis,
	const double pixelSizeUM
) 
	: 
	m_MainFrame(main_frame),
	m_UniqueThreadKey(uniqueThreadKey),
	m_AliveOrDeadThread(aliveOrDeadThread),
	m_Settings(settings), 
	m_CameraPreview(camera_preview_panel), 
	m_XimeaControl(ximea_control),
	m_ImagePath(path), 
	m_ExposureTimeUS(exp_time_us),
	m_FirstAxis(first_axis), 
	m_SecondAxis(second_axis),
	m_PixelSizeUM(pixelSizeUM)
{}

WorkerThread::~WorkerThread()
{
	m_MainFrame = nullptr;
	m_Settings = nullptr;
	m_CameraPreview = nullptr;
	m_XimeaControl = nullptr;
	delete m_FirstAxis;
	m_FirstAxis = nullptr;
	delete m_SecondAxis;
	m_SecondAxis = nullptr;
}

wxThread::ExitCode WorkerThread::Entry()
{
	constexpr auto raise_exception_msg = [](wxString camera_name) 
	{
		wxString title = "Connection error";
		wxMessageBox(
			wxT
			(
				"The " + camera_name + " camera can't capture an image."
				"\nPlease, check if the " + camera_name + " camera is connected properly and restart the program."
			),
			title,
			wxICON_ERROR);
	};
	auto exit_thread = [&]()
	{
		*m_UniqueThreadKey = "";
		m_Settings->SetCurrentProgress(1, 1);
		//cam_control = nullptr;
		//m_MainFrame->WorkerThreadFinished(true);
	};

	wxThreadEvent evt(wxEVT_THREAD, MainFrameVariables::ID_THREAD_LIVE_CAPTURING);

	m_MainFrame->WorkerThreadFinished(false);
	m_Settings->SetCurrentProgress(0, m_FirstAxis->step_number);

	auto now = std::chrono::system_clock::now();
	auto cur_time = std::chrono::system_clock::to_time_t(now);
	auto str_time = std::string(std::ctime(&cur_time)).substr(11, 8);
	auto cur_hours = str_time.substr(0, 2);
	auto cur_mins = str_time.substr(3, 2);
	auto cur_secs = str_time.substr(6, 2);

	auto graphFileName = m_ImagePath + wxString("\\") + wxString("ximea_measurement_result_") + cur_hours + wxString("H_") + cur_mins + wxString("M_") + cur_secs + wxString("S");

	auto measurementGraphFilePath = graphFileName + wxString(".bmp");
	//m_MeasurementGraphTxtFilePath = graphFileName + wxString(".txt");

	auto dataSize = m_XimeaControl->GetImageWidth() * m_XimeaControl->GetImageHeight();
	//auto cam_preview_data_ptr = m_CameraPreview->GetDataPtr();
	//auto cam_preview_image_ptr = m_CameraPreview->GetImagePtr();

	if (!m_XimeaControl->IsCameraConnected())
	{
		exit_thread();
		return (wxThread::ExitCode)0;
	}

	m_XimeaControl->SetExposureTime(m_ExposureTimeUS);
	m_HorizontalFWHMData = std::make_unique<double[]>(m_FirstAxis->step_number);
	m_VerticalFWHMData = std::make_unique<double[]>(m_FirstAxis->step_number);
	m_FirstAxisPositionsData = std::make_unique<float[]>(m_FirstAxis->step_number);

	float first_axis_rounded_go_to{};
	float first_axis_position{}, second_axis_position{};
	for (auto i{ 0 }; i < m_FirstAxis->step_number; ++i)
	{
		if (!*m_AliveOrDeadThread)
		{
			exit_thread();
			return (wxThread::ExitCode)0;
		}

		m_Settings->SetCurrentProgress(i, m_FirstAxis->step_number);
		/* Here we need to round values, for the correct positioning of motors */
		auto correctedStart = static_cast<int>(m_FirstAxis->start * 1000.f + .5f);
		auto correctedStep = static_cast<int>(m_FirstAxis->step * 1000.f + .5f);
		auto correctedPos = static_cast<float>(correctedStart + i * correctedStep);
		first_axis_rounded_go_to = correctedPos / 1000.f;

		first_axis_position = MoveFirstStage(first_axis_rounded_go_to);
		m_FirstAxisPositionsData[i] = first_axis_rounded_go_to;

		auto fileName = PrepareFileName
		(
			i + 1, 
			first_axis_rounded_go_to, 
			second_axis_position, 
			cur_hours, cur_mins, cur_secs
		);

		auto dataPtr = std::make_unique<unsigned short[]>(dataSize);

		/* Capture Image */
		if (
			CaptureImage
			(
			dataPtr.get(),
			wxSize
			(
				m_XimeaControl->GetImageWidth(), 
				m_XimeaControl->GetImageHeight()
			)
			) 
			&& SaveImage
			(
				dataPtr.get(), 
				m_XimeaControl->GetImageWidth(), 
				m_XimeaControl->GetImageHeight(), 
				fileName
			) 
			&& CalculateFWHM
			(
				dataPtr.get(), 
				m_XimeaControl->GetImageWidth(), 
				m_XimeaControl->GetImageHeight(),
				i
			)
			)
		{
			evt.SetInt(0);
			evt.SetPayload(dataPtr.release());
			wxQueueEvent(m_MainFrame, evt.Clone());
		}
		else
		{
			//raise_exception_msg("XIMEA");
			exit_thread();
			return (wxThread::ExitCode)0;
		}

		/* Update Current Progress */
		//m_Settings->SetCurrentProgress(i, m_FirstAxis->step_number);
	}

#ifdef ENABLE_SECOND_AXIS
	switch (m_SecondAxis->axis_number)
	{
	/* Detector */
	case 0:
		m_Settings->GoToAbsDetectorX(m_FirstAxis->start);
		break;
	case 1:
		m_Settings->GoToAbsDetectorY(m_FirstAxis->start);
		break;
	case 2:
		m_Settings->GoToAbsDetectorZ(m_FirstAxis->start);
		break;
	/* Optics */
	case 3:
		break;
	case 4:
		m_Settings->GoToAbsOpticsY(m_FirstAxis->start);
		break;
	case 5:
		break;
	default:
		break;
	}
#endif // FALSE

	// Go to the best captured position
#ifndef _DEBUG
	if (m_HorizontalFWHMData && m_VerticalFWHMData)
	{
#endif // !_DEBUG
		//auto message = wxString(
		//	"The maximum sum value was: " + wxString::Format(wxT("%ld"), m_MaxSumDuringCapturing) + '\n'
		//	+ "at position: " + wxString::Format(wxT("%.3f"), m_BestFirstAxisPosition) + '\n'
		//	+ "measurement number: " + wxString::Format(wxT("%i"), (int)m_BestMeasurementNumber + 1)
		//);
		//message += "\nDo you want to move stage to the best position?";

		wxDateTime nowDateTime = wxDateTime::Now();
		// Format the date and time
		wxString timestamp = nowDateTime.Format(wxT("%d-%m-%Y, %H:%M:%S"));

		auto bmpSize = wxSize(1920, 1080);

		auto bmp = CreateGraph
		(
			m_HorizontalFWHMData.get(),
			m_VerticalFWHMData.get(),
			m_FirstAxisPositionsData.get(),
			m_FirstAxis->step_number,
			bmpSize.GetWidth(), bmpSize.GetHeight(),
			"Measurement Number [-]",
			"FWHM [um]",
			timestamp
		);

		SaveGraph(bmp, measurementGraphFilePath);

		// Open the image with the default application
		if (!wxLaunchDefaultApplication(measurementGraphFilePath))
			wxLogError("Could not open file '%s' with the default application.", measurementGraphFilePath);

		m_MainFrame->UpdateStagePositions();

		//if (wxMessageBox
		//(
		//	message,
		//	"Move stage?",
		//	wxICON_QUESTION | wxYES_NO
		//) == wxYES)
		//{
		//	MoveFirstStage(m_BestFirstAxisPosition);
		//}
#ifndef _DEBUG
	}
#endif // !_DEBUG
	exit_thread();
	return (wxThread::ExitCode)0;
}

auto WorkerThread::MoveFirstStage(const float position) -> float
{
	float firstAxisPos{};
	switch (m_FirstAxis->axis_number)
	{
		/* Detector */
	case 0:
		firstAxisPos = m_Settings->GoToAbsPos(SettingsVariables::DETECTOR_X, position);
		break;
	case 1:
		firstAxisPos = m_Settings->GoToAbsPos(SettingsVariables::DETECTOR_Y, position);
		break;
	case 2:
		firstAxisPos = m_Settings->GoToAbsPos(SettingsVariables::DETECTOR_Z, position);
		break;
		/* Optics */
	case 3:
		firstAxisPos = m_Settings->GoToAbsPos(SettingsVariables::OPTICS_X, position);
		break;
	case 4:
		firstAxisPos = m_Settings->GoToAbsPos(SettingsVariables::OPTICS_Y, position);
		break;
	case 5:
		firstAxisPos = m_Settings->GoToAbsPos(SettingsVariables::OPTICS_Z, position);
		break;
	default:
		break;
	}

	return firstAxisPos;
}

auto WorkerThread::CaptureImage(unsigned short* const dataPtr, const wxSize& imageSize) -> bool
{
	if (!*m_AliveOrDeadThread) return false;
	auto imgPtr = m_XimeaControl->GetImage();
	if (!imgPtr) return false;

	if (!*m_AliveOrDeadThread) return false;

	LOG("MEMCPY Start");
	memcpy
	(
		dataPtr, 
		imgPtr, 
		sizeof(unsigned short) * imageSize.GetWidth() * imageSize.GetHeight()
	);
	LOG("MEMCPY Finish");

	return true;
}

auto WorkerThread::SaveImage
(
	unsigned short* dataPtr, 
	const int& imgWidth,
	const int& imgHeight,
	const std::string& fileName
) -> bool
{
	if (!*m_AliveOrDeadThread) return false;
	cv::Mat cv_img
	(
		cv::Size(imgWidth, imgHeight),
		CV_16U, 
		dataPtr, 
		cv::Mat::AUTO_STEP
	);

	if (!cv::imwrite(fileName, cv_img)) return false;

	return true;
}

auto WorkerThread::CalculateFWHM
(
	unsigned short* dataPtr, 
	const int& imgWidth,
	const int& imgHeight,
	const int& stepNumber
) -> bool
{
	if (!m_AliveOrDeadThread) return false;
	auto horizontalSumArray = std::make_unique<unsigned int[]>(imgWidth);
	auto verticalSumArray = std::make_unique<unsigned int[]>(imgHeight);

	FWHM::CalculateSumVertically(dataPtr, imgWidth, imgHeight, horizontalSumArray.get());
	m_HorizontalFWHMData[stepNumber] = FWHM::CalculateFWHM
		(
			horizontalSumArray.get(), 
			imgWidth
		);
	m_HorizontalFWHMData[stepNumber] = m_HorizontalFWHMData[stepNumber] == - 1.0 ? 0.0 : m_HorizontalFWHMData[stepNumber];
	m_HorizontalFWHMData[stepNumber] *= m_PixelSizeUM;

	FWHM::CalculateSumHorizontally(dataPtr, imgWidth, imgHeight, verticalSumArray.get());
	m_VerticalFWHMData[stepNumber] = FWHM::CalculateFWHM
		(
			verticalSumArray.get(), 
			imgHeight
		);
	m_VerticalFWHMData[stepNumber] = m_VerticalFWHMData[stepNumber] == - 1.0 ? 0.0 : m_VerticalFWHMData[stepNumber];
	m_VerticalFWHMData[stepNumber] *= m_PixelSizeUM;

	return true;
}

wxBitmap WorkerThread::CreateGraph
(
	const double* const horizontalFWHMData,
	const double* const verticalFWHMData,
	const float* const positionsData,
	unsigned int dataSize,
	int width,
	int height,
	const wxString& xAxisLabel,
	const wxString& leftYAxisLabel,
	const wxString& timestamp
)
{
	wxBitmap bitmap(width, height);
	wxMemoryDC dc(bitmap);

	// Clear the bitmap
	dc.SetBackground(*wxWHITE_BRUSH);
	//dc.SetBackground(*wxBLACK_BRUSH);
	dc.Clear();

	if (dataSize <= 1 || !horizontalFWHMData || !verticalFWHMData)
	{
		dc.SelectObject(wxNullBitmap);
		return bitmap;
	}

	wxFont font = wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	wxFont axisFont = wxFont(164, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
	dc.SetFont(font);

	wxColour leftAxisColour = wxColour(163, 73, 164);
	wxColour rightAxisColour = wxColour(255, 127, 39);
	wxColour horizontalAxisColour = wxColour(0, 0, 0);
	wxColour cellColour = wxColour(90, 90, 90, 80);
	//wxColour gaussianCurveColour = wxColour(181, 230, 29, 100);
	//wxColour highlightingBestMeasurementColour = wxColour(255, 0, 0, 230);
	wxColour axisColour = wxColour(0, 162, 232, 64);

	auto graphRect = wxRect
	(
		100,
		20,
		width - 100 - 100,
		height - 80 - 20
	);

	wxString currTextValue{};
	// Draw Axis Name
	{
		// Draw text to a temporary wxImage
		currTextValue = wxString(AxisNameToString(m_FirstAxis->axis_number));
		dc.SetFont(axisFont);
		wxSize textSize = dc.GetTextExtent(currTextValue);
		wxBitmap tempBitmap(textSize.GetWidth(), textSize.GetHeight());
		wxMemoryDC tempDC;
		tempDC.SelectObject(tempBitmap);

		// Clear temporary DC
		tempDC.SetBackground(wxBrush(*wxWHITE));
		tempDC.Clear();

		// Set color and draw text onto the temporary DC
		tempDC.SetTextForeground(axisColour);
		tempDC.SetFont(axisFont);
		tempDC.DrawText(currTextValue, 0, 0);

		// Copy temporary bitmap to the main bitmap with alpha blending
		wxImage tempImage = tempBitmap.ConvertToImage();
		tempImage.InitAlpha(); // Ensure alpha channel is initialized
		// Set the alpha channel for the text color
		auto alpha = 16;
		for (int y = 0; y < tempImage.GetHeight(); ++y) {
			for (int x = 0; x < tempImage.GetWidth(); ++x) {
				tempImage.SetAlpha(x, y, alpha);
			}
		}
		wxBitmap finalBitmap = wxBitmap(tempImage);

		dc.DrawBitmap(finalBitmap,
			graphRect.GetLeft() + graphRect.GetWidth() / 2 - textSize.GetWidth() / 2,
			graphRect.GetBottom() - graphRect.GetHeight() / 2 - textSize.GetHeight() / 2
		); // Draw final bitmap on memory DC
	}

	dc.SetFont(font);
	wxDouble widthText{}, heightText{};
	// Draw the axes
	// X - Axis
	{
		auto verticalLineHeight = 4;
		auto horizontalStep = (wxDouble)graphRect.GetWidth() / (dataSize - 1);

		// Draw Cell
		// Vertical Lines
		{
			dc.SetPen(wxPen(cellColour, 1, wxPENSTYLE_LONG_DASH));
			dc.SetTextForeground(cellColour);
			for (auto i{ 0 }; i <= dataSize; ++i)
			{

				currTextValue = wxString::Format(wxT("%.3f"), positionsData[i]);
				auto textSize = dc.GetTextExtent(currTextValue);

				if (dataSize < 80 || i == 0 || (i + 1) % 10 == 0)
					dc.DrawRotatedText
					(
						currTextValue,
						i == dataSize - 1 ? graphRect.GetRight() - textSize.GetHeight() + 12
						: graphRect.GetLeft() + i * horizontalStep + textSize.GetHeight() + 2,
						graphRect.GetBottom() - textSize.GetWidth() - 15,
						270
					);

				if (!i) continue;

				dc.DrawLine
				(
					graphRect.GetLeft() + i * horizontalStep,
					graphRect.GetTop(),
					graphRect.GetLeft() + i * horizontalStep,
					graphRect.GetBottom()
				);
			}
		}

		dc.SetPen(wxPen(horizontalAxisColour));
		dc.DrawLine
		(
			graphRect.GetLeft(),
			graphRect.GetBottom(),
			graphRect.GetRight(),
			graphRect.GetBottom()
		); // X-axis

		dc.SetTextForeground(horizontalAxisColour);

		// Draw vertical lines
		for (auto i{ 0 }; i <= dataSize; ++i)
		{
			currTextValue = wxString::Format(wxT("%i"), i + 1);
			auto textSize = dc.GetTextExtent(currTextValue);

			dc.DrawLine
			(
				i == dataSize - 1 ? graphRect.GetRight() : graphRect.GetLeft() + i * horizontalStep,
				graphRect.GetBottom(),
				i == dataSize - 1 ? graphRect.GetRight() : graphRect.GetLeft() + i * horizontalStep,
				graphRect.GetBottom() + verticalLineHeight
			);

			if (dataSize < 80 || i == 0 || (i + 1) % 10 == 0)
				dc.DrawText
				(
					currTextValue,
					i == dataSize - 1 ? graphRect.GetRight() - textSize.GetWidth() / 2 : graphRect.GetLeft() + i * horizontalStep - textSize.GetWidth() / 2,
					graphRect.GetBottom() + verticalLineHeight + 4
				);
		}

	}

	dc.SetPen(wxPen(leftAxisColour));
	dc.DrawLine(graphRect.GetLeft(), graphRect.GetBottom(), graphRect.GetLeft(), graphRect.GetTop()); // Left Y-axis

	//dc.SetPen(wxPen(sumColour));
	//dc.DrawLine(graphRect.GetRight(), graphRect.GetBottom(), graphRect.GetRight(), graphRect.GetTop()); // Right Y-axis

	// Label the axes
	{
		dc.SetFont(font);
		dc.SetTextForeground(horizontalAxisColour);
		dc.DrawText
		(
			xAxisLabel,
			(width / 2) - (dc.GetTextExtent(xAxisLabel).GetWidth() / 2),
			height - 40
		);

		dc.SetTextForeground(leftAxisColour);
		dc.DrawRotatedText
		(
			leftYAxisLabel,
			10,
			(height / 2) + (dc.GetTextExtent(leftYAxisLabel).GetWidth() / 2),
			90
		);
	}



	// Draw the data curves
	double minGlobalValue{}, maxGlobalValue{};
	auto minmaxHorizontalValues = std::minmax_element(horizontalFWHMData, horizontalFWHMData + dataSize);
	auto minmaxVerticalValues = std::minmax_element(verticalFWHMData, verticalFWHMData + dataSize);
	
	minGlobalValue = std::min(*minmaxHorizontalValues.first, *minmaxVerticalValues.first);
	maxGlobalValue = std::max(*minmaxHorizontalValues.second, *minmaxVerticalValues.second);

	// Scaling minmaxGlobalValues
	minGlobalValue = std::floor((minGlobalValue - 0.1 * (maxGlobalValue - minGlobalValue)) * 10.0) / 10.0;
	maxGlobalValue = std::ceil((maxGlobalValue + 0.1 * (maxGlobalValue - minGlobalValue)) * 10.0) / 10.0;
	
	// Draw the Left Axis Ruler
	{
		auto verticalAxisHorizontalLinesCount = 10;
		auto verticalStep = graphRect.GetHeight() / verticalAxisHorizontalLinesCount;
		auto widthHorizontalLine = 8;

		// Draw Cell
		// Horizontal Lines
		{
			dc.SetPen(wxPen(cellColour, 1, wxPENSTYLE_LONG_DASH));
			for (auto i{ 0 }; i <= verticalAxisHorizontalLinesCount; ++i)
			{
				if (!i) continue;

				dc.DrawLine
				(
					graphRect.GetLeft(),
					graphRect.GetBottom() - i * verticalStep,
					graphRect.GetRight(),
					graphRect.GetBottom() - i * verticalStep
				);
			}
		}

		dc.SetPen(wxPen(leftAxisColour));
		dc.SetTextForeground(leftAxisColour);

		for (auto i{ 0 }; i <= verticalAxisHorizontalLinesCount; ++i)
		{
			currTextValue = wxString::Format(wxT("%.2f"), (maxGlobalValue - minGlobalValue) / verticalAxisHorizontalLinesCount * i + minGlobalValue);
			auto textSize = dc.GetTextExtent(currTextValue);
			dc.DrawText
			(
				currTextValue,
				graphRect.GetLeft() - textSize.GetWidth() - widthHorizontalLine / 2 - 2,
				graphRect.GetBottom() - textSize.GetHeight() / 2 - verticalStep * i
			);

			if (!i) continue;

			dc.DrawLine
			(
				graphRect.GetLeft() - widthHorizontalLine / 2,
				graphRect.GetBottom() - i * verticalStep,
				graphRect.GetLeft() + widthHorizontalLine / 2,
				graphRect.GetBottom() - i * verticalStep
			); // Left Y-axis
		}
	}

#ifdef DRAW_NORMALDISTRIBUTION
	// Calculation the Normal Distribution from sumData and Draw them
	{
		// Calculate mean
		double mean = std::accumulate(sumData, sumData + dataSize, 0.0) / dataSize;
		// Calculate standard deviation
		double sum_squared_diff = 0.0;
		for (auto i{ 0 }; i < dataSize; ++i)
		{
			auto value = sumData[i];
			sum_squared_diff += (value - mean) * (value - mean);
		}
		double stddev = std::sqrt(sum_squared_diff / dataSize);

		auto pdfArray = std::make_unique<double[]>(dataSize);
		// Calculating the normal distribution for a value
		for (auto i{ 0 }; i < dataSize; ++i)
		{
			auto x = (double)sumData[i];
			// Probability Density Function
			double pdf = (1.0 / (stddev * std::sqrt(2 * M_PI))) * std::exp(-0.5 * std::pow((x - mean) / stddev, 2));
			pdfArray[i] = pdf;
		}

		// Draw Gaussian curve
		dc.SetPen(wxPen(gaussianCurveColour, 2));
		for (auto i{ 1 }; i < dataSize; ++i)
		{
			int x1 = graphRect.GetLeft() + (i - 1) * graphRect.GetWidth() / (dataSize - 1);
			//int x1 = 50 + (i - 1) * (width - 100) / (dataSize - 1);
			int y1 = graphRect.GetBottom() - (pdfArray[i - 1] - minSumValue) * graphRect.GetHeight() / (maxSumValue - minSumValue);
			//int y1 = height - 50 - sumData[i - 1] * (height - 60) / maxSumValue;
			int x2 = graphRect.GetLeft() + i * graphRect.GetWidth() / (dataSize - 1);
			//int x2 = 50 + i * (width - 100) / (dataSize - 1);
			int y2 = graphRect.GetBottom() - (pdfArray[i] - minSumValue) * graphRect.GetHeight() / (maxSumValue - minSumValue);
			//int y2 = height - 50 - sumData[i] * (height - 60) / maxSumValue;
			dc.DrawLine(x1, y1, x2, y2);
		}
	}
#endif // DRAW_NORMALDISTRIBUTION

	// Checking if data are all zeroes
	auto horDataSum = std::accumulate(horizontalFWHMData, &horizontalFWHMData[dataSize - 1], 0.0);
	if (horDataSum == 0.0)
	{
		dc.SelectObject(wxNullBitmap);
		return bitmap;
	}

	auto curveSize = 4;
	// Draw the actual data
	for (auto i = 0; i < dataSize - 1; ++i)
	{
		// Draw horizontal data curve
		dc.SetPen(wxPen(leftAxisColour, curveSize));
		auto x1 = graphRect.GetLeft() + i * graphRect.GetWidth() / (dataSize - 1);
		auto y1 = graphRect.GetBottom() - (horizontalFWHMData[i] - minGlobalValue) * graphRect.GetHeight() / (maxGlobalValue - minGlobalValue);
		auto x2 = graphRect.GetLeft() + (i + 1) * graphRect.GetWidth() / (dataSize - 1);
		auto y2 = graphRect.GetBottom() - (horizontalFWHMData[i + 1] - minGlobalValue) * graphRect.GetHeight() / (maxGlobalValue - minGlobalValue);
		dc.DrawLine(x1, y1, x2, y2);

		// Highlighting the best Sum value
		//if (m_MaxSumDuringCapturing == sumData[i])
		//{
		//	dc.SetPen(wxPen(highlightingBestMeasurementColour, 2));
		//	dc.DrawCircle(wxPoint(x2, y2), 5);
		//}

		// Draw vertical data curve
		dc.SetPen(wxPen(rightAxisColour, curveSize));
		y1 = graphRect.GetBottom() - (verticalFWHMData[i] - minGlobalValue) * graphRect.GetHeight() / (maxGlobalValue - minGlobalValue);
		y2 = graphRect.GetBottom() - (verticalFWHMData[i + 1] - minGlobalValue) * graphRect.GetHeight() / (maxGlobalValue - minGlobalValue);
		dc.DrawLine(x1, y1, x2, y2);

		//// Highlighting the best value
		//if (m_MaxElementDuringCapturing == countData[i])
		//{
		//	dc.SetPen(wxPen(highlightingBestMeasurementColour, 2));
		//	dc.DrawCircle(wxPoint(x2, y2), 5);
		//}
	}

	// Placing a Legend
	{
		// Horizontal 
		dc.SetTextForeground(leftAxisColour);
		currTextValue = wxString("Horizontal");
		widthText = dc.GetTextExtent(currTextValue).GetWidth();
		heightText = dc.GetTextExtent(currTextValue).GetHeight();

		auto finishDrawTextY = graphRect.GetBottom() + (dc.GetSize().GetHeight() - graphRect.GetBottom()) / 3;
		dc.DrawText
		(
			currTextValue,
			graphRect.GetRight() - widthText - 5,
			finishDrawTextY
		);
		finishDrawTextY += heightText;

		// Vertical 
		dc.SetTextForeground(rightAxisColour);
		currTextValue = wxString("Vertical");
		widthText = dc.GetTextExtent(currTextValue).GetWidth();
		heightText = dc.GetTextExtent(currTextValue).GetHeight();

		dc.DrawText
		(
			currTextValue,
			graphRect.GetRight() - widthText - 5,
			finishDrawTextY + 5
		);
	}

	// Placing an Exposure value
	auto exposureFinishX = 0;
	{
		dc.SetTextForeground(wxColour(0, 0, 0));
		auto exposureStr = wxString::Format(wxT("%i"), (int)m_ExposureTimeUS / 1000);
		exposureStr += " [us]";
		auto textSize = dc.GetTextExtent(exposureStr);
		auto startExposureTextX = 5;
		exposureFinishX = startExposureTextX + textSize.GetWidth();

		dc.DrawText
		(
			exposureStr,
			startExposureTextX,
			height - textSize.GetHeight() - 5
		);
	}

	// Placing a time stamp
	{
		dc.SetTextForeground(wxColour(255, 0, 0));

		auto textSize = dc.GetTextExtent(timestamp);
		dc.DrawText
		(
			timestamp,
			exposureFinishX + 15,
			height - textSize.GetHeight() - 5
		);
	}

	// Placing an application name
	{
		dc.SetTextForeground(wxColour(0, 0, 0));
		currTextValue = wxString("MMCam");

		widthText = dc.GetTextExtent(currTextValue).GetWidth();
		heightText = dc.GetTextExtent(currTextValue).GetHeight();
		dc.DrawText
		(
			currTextValue,
			dc.GetSize().GetWidth() - widthText - 5,
			graphRect.GetTop() / 2 - heightText / 2
		);
	}

	// Release the device context
	dc.SelectObject(wxNullBitmap);
	return bitmap;
}
auto WorkerThread::SaveGraph
(
	const wxBitmap& bitmap, 
	const wxString filePath
) -> void
{
	if (!bitmap.IsOk()) return;

	// Save the bitmap as a BMP file
	if (!bitmap.SaveFile(filePath, wxBITMAP_TYPE_BMP)) return;
}
/* ___ End Worker Thread ___ */

/* ___ Start Progress Thread ___ */
ProgressThread::ProgressThread(
	cSettings* settings,
	cMain* main_frame)
	: m_Frame(main_frame), m_Settings(settings)
{}

wxThread::ExitCode ProgressThread::Entry()
{
	m_Progress = 0;
	m_ProgressMsg = "";
	wxThreadEvent evt(wxEVT_THREAD, MainFrameVariables::ID_THREAD_PROGRESS_CAPTURING);
	while (!m_Settings->IsCapturingFinished())
	{
		//m_Settings->ProvideProgressInfo(&m_ProgressMsg, &m_Progress);

		evt.SetInt(m_Settings->ProvideProgressValue());
		evt.SetString(m_Settings->ProvideProgressMessage());

		wxQueueEvent(m_Frame, evt.Clone());

		wxThread::This()->Sleep(100);
	}
	evt.SetInt(-1);
	wxQueueEvent(m_Frame, evt.Clone());

	return (wxThread::ExitCode)0;
}

ProgressThread::~ProgressThread()
{
	m_Frame = nullptr;
	m_Settings = nullptr;
}
/* ___ End Progress Thread ___ */

/* ___ Start ProgressBar ___ */
BEGIN_EVENT_TABLE(ProgressBar, wxFrame)
END_EVENT_TABLE()

ProgressBar::ProgressBar(wxWindow* parent, const wxPoint& pos, const wxSize& size)
	: wxFrame(parent, wxID_ANY, wxT("Progress"), pos, size, wxFRAME_FLOAT_ON_PARENT), m_MainSize(size)
{
	CreateProgressBar();
}

void ProgressBar::UpdateProgressWithMessage(const wxString& msg, const int& progress)
{
	m_ProgressPanel->SetProgress(progress);
	m_ProgressPanel->SetComment(msg);
}

void ProgressBar::UpdateElapsedTime(const uint64_t& elapsed_seconds)
{
	m_ProgressPanel->SetElapsedTime(elapsed_seconds);
}

void ProgressBar::UpdateEstimatedTime(const int& prgs, const uint64_t& elapsed_seconds)
{
	m_ProgressPanel->SetEstimatedTime(prgs, elapsed_seconds);
}

void ProgressBar::CreateProgressBar()
{
	wxSizer* const main_sizer = new wxBoxSizer(wxVERTICAL);
	m_ProgressPanel = new ProgressPanel(this, m_MainSize);
	main_sizer->Add(m_ProgressPanel, wxSizerFlags(1).Expand().Border());
	this->SetBackgroundColour(wxColour(255, 255, 255));
	SetSizerAndFit(main_sizer);
}

ProgressBar::~ProgressBar()
{
	//m_ProgressPanel->Destroy();
}
/* ___ End ProgressBar ___ */

/* ___ Start ProgressPanel ___ */
BEGIN_EVENT_TABLE(ProgressPanel, wxPanel)
EVT_PAINT(ProgressPanel::PaintEvent)
EVT_SIZE(ProgressPanel::OnSize)
END_EVENT_TABLE()

ProgressPanel::ProgressPanel(
	wxFrame* parent, const wxSize& size)
	: wxPanel(parent)
{
	this->SetDoubleBuffered(true);
	this->SetBackgroundColour(wxColour(*wxWHITE));

	this->SetMinSize(size);
	//SetSize(size);
	//Refresh();
}

void ProgressPanel::SetSize(const wxSize& new_size)
{
	m_Width = new_size.x;
	m_Height = new_size.y;
	Refresh();
}

void ProgressPanel::SetProgress(const int& progress)
{
	m_Progress = progress <= 100 && progress >= 0 ? progress : 100;
}

void ProgressPanel::SetElapsedTime(const int& elapsed_time)
{
	m_ElapsedTime = elapsed_time;

	m_ElapsedHours = elapsed_time / 3600;
	m_ElapsedMinutes = elapsed_time / 60 - m_ElapsedHours * 60;
	m_ElapsedSeconds = elapsed_time - m_ElapsedHours * 3600 - m_ElapsedMinutes * 60;
}

void ProgressPanel::SetEstimatedTime(const int& progress, const int& elapsed_time)
{
	if (progress > 0 && progress != m_PreviousEstimateProgress)
	{
		m_EstimatedTime = (double)elapsed_time / (double)progress * 100.0 - elapsed_time;
		m_PreviousEstimateProgress = progress;
	}
	else if (progress == 0)
	{
		/* Reset Estimated time variables */
		m_EstimatedTime = 0;
		m_PreviousEstimateProgress = 0;
	}

	Refresh();
}

void ProgressPanel::SetComment(const wxString& progress_comment)
{
	m_ProgressComment = progress_comment;
}

void ProgressPanel::PaintEvent(wxPaintEvent& evt)
{
	wxBufferedPaintDC dc(this);
	Render(dc);
}

void ProgressPanel::Render(wxBufferedPaintDC& dc)
{
	dc.Clear();
	wxGraphicsContext* gc{};
	gc = wxGraphicsContext::Create(dc);
	if (gc)
	{
		int borderWidthProgressRectangle{ 1 };
		gc->SetPen(wxPen(wxColour(0, 0, 0), borderWidthProgressRectangle));
		wxFont font = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
		gc->SetFont(font, *wxBLACK);
		wxGraphicsPath path = gc->CreatePath();

		wxDouble widthText{}, heightText{};
		wxString text_01("Progress");
		gc->GetTextExtent(text_01, &widthText, &heightText);

		wxDouble drawPointXText = this->GetSize().x / 2 - widthText / 2;
		wxDouble offsetYText{ 10 };
		wxDouble drawPointYText = offsetYText;
		gc->DrawText(text_01, drawPointXText, drawPointYText);

		// Progress in percents
		drawPointYText += heightText + offsetYText;
		wxString text_progress = wxString::Format(wxT("%i"), m_Progress) + "%";
		gc->GetTextExtent(text_progress, &widthText, &heightText);
		drawPointXText = this->GetSize().x / 2 - widthText / 2;
		gc->DrawText(text_progress, drawPointXText, drawPointYText);

		int leftAndRightOffsetRectangle{ 10 }; // [%]
		wxPoint startUpperLeftBorderRectangle{ this->GetSize().x * leftAndRightOffsetRectangle / 100, (int)(drawPointYText + heightText + offsetYText) };
		wxSize sizeBorderRectangle{ this->GetSize().x - this->GetSize().x * leftAndRightOffsetRectangle / 100 * 2, 40 };

		unsigned char red{}, green{}, blue{};
		green = (unsigned char)(255 * (int)m_Progress / 100);
		red = 255 - green;
		wxColour currentRectangleColour{ red, green, blue };

		gc->SetBrush(wxBrush(currentRectangleColour));
		wxDouble widthProgress = (100 - (wxDouble)m_Progress) * (wxDouble)sizeBorderRectangle.x / 100.0;
		path.AddRectangle(
			(wxDouble)startUpperLeftBorderRectangle.x + (wxDouble)sizeBorderRectangle.x - widthProgress,
			startUpperLeftBorderRectangle.y,
			widthProgress,
			(wxDouble)sizeBorderRectangle.y);
		//gc->FillPath(path);

		path.AddRectangle(
			startUpperLeftBorderRectangle.x,
			startUpperLeftBorderRectangle.y,
			sizeBorderRectangle.x,
			sizeBorderRectangle.y);
		// Drawing buffered path
		gc->DrawPath(path);

		// Progress comment
		gc->GetTextExtent(m_ProgressComment, &widthText, &heightText);
		drawPointXText = (wxDouble)startUpperLeftBorderRectangle.x + 5.0;
		drawPointYText = (wxDouble)startUpperLeftBorderRectangle.y + (wxDouble)sizeBorderRectangle.y + offsetYText;
		gc->DrawText(m_ProgressComment, drawPointXText, drawPointYText);

		// Elapsed time
		{
			wxString elapsed_text("Elapsed time: ");
			wxString elapsed_hours = m_ElapsedHours >= 10 ? wxString::Format(wxT("%i"), m_ElapsedHours) : wxString::Format(wxT("0%i"), m_ElapsedHours);
			wxString elapsed_minutes = m_ElapsedMinutes >= 10 ? wxString::Format(wxT("%i"), m_ElapsedMinutes) : wxString::Format(wxT("0%i"), m_ElapsedMinutes);
			wxString elapsed_seconds = m_ElapsedSeconds >= 10 ? wxString::Format(wxT("%i"), m_ElapsedSeconds) : wxString::Format(wxT("0%i"), m_ElapsedSeconds);
			elapsed_text += elapsed_hours + ":" + elapsed_minutes + ":" + elapsed_seconds;

			drawPointYText += heightText + offsetYText;
			gc->GetTextExtent(elapsed_text, &widthText, &heightText);
			drawPointXText = (wxDouble)startUpperLeftBorderRectangle.x + 5.0;
			gc->DrawText(elapsed_text, drawPointXText, drawPointYText);
		}

		delete gc;
	}
}

void ProgressPanel::OnSize(wxSizeEvent& evt)
{
	int newWidth{ evt.GetSize().x }, newHeight{ evt.GetSize().y };
	if (newWidth != m_Width || newHeight != m_Height)
	{
		m_Width = newWidth;
		m_Height = newHeight;
		Refresh();
	}
}
/* ___ End ProgressPanel ___ */

