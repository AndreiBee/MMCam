#include "cSettings.h"

cSettings::cSettings(wxWindow* parent_frame) 
	: wxDialog(
		parent_frame, 
		wxID_ANY, 
		"Settings", 
		wxDefaultPosition, 
		wxDefaultSize, 
		wxDEFAULT_DIALOG_STYLE)
{
	CreateMainFrame();
	InitDefaultStateWidgets();
	CenterOnScreen();
}

bool cSettings::DetectorXHasSerialNumber() const
{
	return m_PhysicalMotors->MotorHasSerialNumber(m_Motors->m_Detector[0].current_selection[0] - 1);
}

float cSettings::GetActualDetectorXStagePos() const
{
	return m_PhysicalMotors->GetActualStagePos(m_Motors->m_Detector[0].current_selection[0] - 1);
}

bool cSettings::DetectorYHasSerialNumber() const
{
	return m_PhysicalMotors->MotorHasSerialNumber(m_Motors->m_Detector[1].current_selection[0] - 1);
}

float cSettings::GetActualDetectorYStagePos() const
{
	return m_PhysicalMotors->GetActualStagePos(m_Motors->m_Detector[1].current_selection[0] - 1);
}

bool cSettings::DetectorZHasSerialNumber() const
{
	return m_PhysicalMotors->MotorHasSerialNumber(m_Motors->m_Detector[2].current_selection[0] - 1);
}

float cSettings::GetActualDetectorZStagePos() const
{
	return m_PhysicalMotors->GetActualStagePos(m_Motors->m_Detector[2].current_selection[0] - 1);
}

bool cSettings::OpticsXHasSerialNumber() const
{
	return m_PhysicalMotors->MotorHasSerialNumber(m_Motors->m_Optics[0].current_selection[0] - 1);
}

float cSettings::GetActualOpticsXStagePos() const
{
	return m_PhysicalMotors->GetActualStagePos(m_Motors->m_Optics[0].current_selection[0] - 1);
}

bool cSettings::OpticsYHasSerialNumber() const
{
	return m_PhysicalMotors->MotorHasSerialNumber(m_Motors->m_Optics[1].current_selection[0] - 1);
}

float cSettings::GetActualOpticsYStagePos() const
{
	return m_PhysicalMotors->GetActualStagePos(m_Motors->m_Optics[1].current_selection[0] - 1);
}

bool cSettings::OpticsZHasSerialNumber() const
{
	return m_PhysicalMotors->MotorHasSerialNumber(m_Motors->m_Optics[2].current_selection[0] - 1);
}

float cSettings::GetActualOpticsZStagePos() const
{
	return m_PhysicalMotors->GetActualStagePos(m_Motors->m_Optics[2].current_selection[0] - 1);
}

bool cSettings::IsCapturingFinished() const
{
	return m_Progress->is_finished;
}

void cSettings::ProvideProgressInfo(wxString* msg, int* prgrs)
{
	*msg = "Capturing " + wxString::Format(wxT("%i"), m_Progress->current_capture + 1) + " of " + wxString::Format(wxT("%i"), m_Progress->whole_captures_num) + " images";
	*prgrs = 100.f * (float)(m_Progress->current_capture + 1) / (float)m_Progress->whole_captures_num;
}

void cSettings::ResetCapturing()
{
	m_Progress->is_finished = false;
}

float cSettings::GoToAbsDetectorX(float absolute_position)
{
	return m_PhysicalMotors->GoMotorToAbsPos
	(
		m_Motors->m_Detector[0].current_selection[0] - 1, 
		absolute_position
	);
}

float cSettings::GoOffsetDetectorX(float delta)
{
	return m_PhysicalMotors->GoMotorOffset
	(
		m_Motors->m_Detector[0].current_selection[0] - 1, 
		delta
	);
}

float cSettings::CenterDetectorX()
{
	return m_PhysicalMotors->GoMotorCenter(m_Motors->m_Detector[0].current_selection[0] - 1);
}

float cSettings::HomeDetectorX()
{
	return m_PhysicalMotors->GoMotorHome(m_Motors->m_Detector[0].current_selection[0] - 1);
}

float cSettings::GoToAbsDetectorY(float absolute_position)
{
	return m_PhysicalMotors->GoMotorToAbsPos
	(
		m_Motors->m_Detector[1].current_selection[0] - 1, 
		absolute_position
	);
}

float cSettings::GoOffsetDetectorY(float delta)
{
	return m_PhysicalMotors->GoMotorOffset
	(
		m_Motors->m_Detector[1].current_selection[0] - 1, 
		delta
	);
}

float cSettings::CenterDetectorY()
{
	return m_PhysicalMotors->GoMotorCenter(m_Motors->m_Detector[1].current_selection[0] - 1);
}

float cSettings::HomeDetectorY()
{
	return m_PhysicalMotors->GoMotorHome(m_Motors->m_Detector[1].current_selection[0] - 1);
}

float cSettings::GoToAbsDetectorZ(float absolute_position)
{
	return m_PhysicalMotors->GoMotorToAbsPos
	(
		m_Motors->m_Detector[2].current_selection[0] - 1, 
		absolute_position
	);
}

float cSettings::GoOffsetDetectorZ(float delta)
{
	return m_PhysicalMotors->GoMotorOffset
	(
		m_Motors->m_Detector[2].current_selection[0] - 1, 
		delta
	);
}

float cSettings::CenterDetectorZ()
{
	return m_PhysicalMotors->GoMotorCenter(m_Motors->m_Detector[2].current_selection[0] - 1);
}

float cSettings::HomeDetectorZ()
{
	return m_PhysicalMotors->GoMotorHome(m_Motors->m_Detector[2].current_selection[0] - 1);
}

float cSettings::GoToAbsOpticsY(float absolute_position)
{
	return m_PhysicalMotors->GoMotorToAbsPos
	(
		m_Motors->m_Optics[1].current_selection[0] - 1, 
		absolute_position
	);
}

float cSettings::GoOffsetOpticsY(float delta)
{
	return m_PhysicalMotors->GoMotorOffset
	(
		m_Motors->m_Optics[1].current_selection[0] - 1, 
		delta
	);
}

float cSettings::CenterOpticsY()
{
	return m_PhysicalMotors->GoMotorCenter(m_Motors->m_Optics[1].current_selection[0] - 1);
}

float cSettings::HomeOpticsY()
{
	return m_PhysicalMotors->GoMotorHome(m_Motors->m_Optics[1].current_selection[0] - 1);
}

void cSettings::SetCurrentProgress(const int& curr_capturing_num, const int& whole_capturing_num)
{
	m_Progress->current_capture = curr_capturing_num;
	m_Progress->whole_captures_num = whole_capturing_num;
	m_Progress->is_finished = curr_capturing_num >= whole_capturing_num ? true : false;
}

auto cSettings::GetSelectedCamera() const -> std::string
{
	return m_Cameras->selected_camera;
}

void cSettings::CreateMainFrame()
{
	InitComponents();
	ReadWorkStationFiles();
	IterateOverConnectedCameras();
	ReadXMLFile();
	CreateSettings();
	BindMotorsAndRangesChoices();
	SelectMotorsAndRangesOnWXChoice();
}

void cSettings::CreateSettings()
{
	wxBoxSizer* main_sizer = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* ms_sizer = new wxBoxSizer(wxVERTICAL);
	
	CreateMotorsSelection(ms_sizer);
	
	main_sizer->Add(ms_sizer, 1, wxEXPAND);
	SetSizerAndFit(main_sizer);
}

void cSettings::CreateMotorsSelection(wxBoxSizer* panel_sizer)
{	
	wxPanel* main_panel = new wxPanel(this);
#ifdef _DEBUG
	main_panel->SetBackgroundColour(wxColor(150, 190, 180));
#else
	main_panel->SetBackgroundColour(wxColor(255, 255, 255));
#endif // _DEBUG
	wxBoxSizer* main_panel_sizer = new wxBoxSizer(wxVERTICAL);

	/* Work Station */
	wxSizer* const work_station_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Work Station");
	{
		auto work_station_choice_size = wxSize(120, 24);
		m_WorkStations->work_station = new wxChoice
		(
			main_panel, 
			SettingsVariables::ID_WORK_STATION_CHOICE, 
			wxDefaultPosition, 
			work_station_choice_size, 
			m_WorkStations->work_stations_arr
		);

		m_WorkStations->work_station->SetSelection(0);

		work_station_static_box_sizer->AddStretchSpacer();
		work_station_static_box_sizer->Add(m_WorkStations->work_station, 0, wxEXPAND);
		work_station_static_box_sizer->AddStretchSpacer();
	}
	main_panel_sizer->Add(work_station_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);

	/* Motors */
	wxSizer* const motors_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, main_panel, "&Motors");
	{
		int top_offset_static_text{ 5 };
		wxSizer* const detector_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Detector");
		{
			/* X */
			wxSizer* const det_x_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&X");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&S/N");

				m_Motors->m_Detector[0].motors = new wxChoice(
					main_panel, 
					SettingsVariables::ID_MOT_DET_X_MOTOR_CHOICE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors[0]);

				m_Motors->m_Detector[0].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Detector[0].motors);

				det_x_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			det_x_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Range");

				m_Motors->m_Detector[0].ranges = new wxStaticText(
					main_panel,
					SettingsVariables::ID_MOT_DET_X_RANGE_ST_TEXT,
					wxT("None"), 
					wxDefaultPosition, 
					wxDefaultSize, 
					wxALIGN_CENTRE_HORIZONTAL);
				range_static_box_sizer->Add(m_Motors->m_Detector[0].ranges, 1, wxEXPAND | wxTOP, top_offset_static_text);

				det_x_static_box_sizer->Add(range_static_box_sizer, 1, wxEXPAND);
			}
			detector_static_box_sizer->Add(det_x_static_box_sizer, 0, wxEXPAND);

			detector_static_box_sizer->AddSpacer(2);
			detector_static_box_sizer->AddStretchSpacer();

			/* Y */
			wxSizer* const det_y_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Y");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&S/N");

				m_Motors->m_Detector[1].motors = new wxChoice(
					main_panel, 
					SettingsVariables::ID_MOT_DET_Y_MOTOR_CHOICE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors[0]);

				m_Motors->m_Detector[1].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Detector[1].motors);

				det_y_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			det_y_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Range");

				m_Motors->m_Detector[1].ranges = new wxStaticText(
					main_panel, 
					SettingsVariables::ID_MOT_DET_Y_RANGE_ST_TEXT, 	
					wxT("None"), 
					wxDefaultPosition, 
					wxDefaultSize,
					wxALIGN_CENTRE_HORIZONTAL);
				range_static_box_sizer->Add(m_Motors->m_Detector[1].ranges, 1, wxEXPAND | wxTOP, top_offset_static_text);

				det_y_static_box_sizer->Add(range_static_box_sizer, 1, wxEXPAND);
			}
			detector_static_box_sizer->Add(det_y_static_box_sizer, 0, wxEXPAND);
			detector_static_box_sizer->AddSpacer(2);
			detector_static_box_sizer->AddStretchSpacer();

			/* Z */
			wxSizer* const det_z_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Z");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&S/N");

				m_Motors->m_Detector[2].motors = new wxChoice(
					main_panel, 
					SettingsVariables::ID_MOT_DET_Z_MOTOR_CHOICE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors[0]);

				m_Motors->m_Detector[2].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Detector[2].motors);

				det_z_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			det_z_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Range");

				m_Motors->m_Detector[2].ranges = new wxStaticText(
					main_panel, 
					SettingsVariables::ID_MOT_DET_Z_RANGE_ST_TEXT, 	
					wxT("None"), 
					wxDefaultPosition, 
					wxDefaultSize, 
					wxALIGN_CENTRE_HORIZONTAL);
				range_static_box_sizer->Add(m_Motors->m_Detector[2].ranges, 1, wxEXPAND | wxTOP, top_offset_static_text);

				det_z_static_box_sizer->Add(range_static_box_sizer, 1, wxEXPAND);
			}
			detector_static_box_sizer->Add(det_z_static_box_sizer, 0, wxEXPAND);
		}
		motors_static_box_sizer->Add(detector_static_box_sizer, 0, wxEXPAND);

		wxSizer* const optics_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Optics");
		{
			/* X */
			wxSizer* const opt_x_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&X");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&S/N");

				m_Motors->m_Optics[0].motors = new wxChoice(
					main_panel, 
					SettingsVariables::ID_MOT_OPT_X_MOTOR_CHOICE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors[0]);

				m_Motors->m_Optics[0].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Optics[0].motors);

				opt_x_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			opt_x_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Range");

				m_Motors->m_Optics[0].ranges = new wxStaticText(
					main_panel, 
					SettingsVariables::ID_MOT_OPT_X_RANGE_ST_TEXT, 	
					wxT("None"), 
					wxDefaultPosition, 
					wxDefaultSize, 
					wxALIGN_CENTRE_HORIZONTAL);
				range_static_box_sizer->Add(m_Motors->m_Optics[0].ranges, 1, wxEXPAND | wxTOP, top_offset_static_text);

				opt_x_static_box_sizer->Add(range_static_box_sizer, 1, wxEXPAND);
			}
			optics_static_box_sizer->Add(opt_x_static_box_sizer, 0, wxEXPAND);
			optics_static_box_sizer->AddSpacer(2);
			optics_static_box_sizer->AddStretchSpacer();

			/* Y */
			wxSizer* const opt_y_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Y");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&S/N");

				m_Motors->m_Optics[1].motors = new wxChoice(
					main_panel, 
					SettingsVariables::ID_MOT_OPT_Y_MOTOR_CHOICE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors[0]);

				m_Motors->m_Optics[1].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Optics[1].motors);

				opt_y_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			opt_y_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Range");

				m_Motors->m_Optics[1].ranges = new wxStaticText(
					main_panel, 
					SettingsVariables::ID_MOT_OPT_Y_RANGE_ST_TEXT, 
					wxT("None"), 
					wxDefaultPosition, 
					wxDefaultSize, 
					wxALIGN_CENTRE_HORIZONTAL);
				range_static_box_sizer->Add(m_Motors->m_Optics[1].ranges, 1, wxEXPAND | wxTOP, top_offset_static_text);

				opt_y_static_box_sizer->Add(range_static_box_sizer, 1, wxEXPAND);
			}
			optics_static_box_sizer->Add(opt_y_static_box_sizer, 0, wxEXPAND);
			optics_static_box_sizer->AddSpacer(2);
			optics_static_box_sizer->AddStretchSpacer();

			/* Z */
			wxSizer* const opt_z_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Z");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&S/N");

				m_Motors->m_Optics[2].motors = new wxChoice(
					main_panel, 
					SettingsVariables::ID_MOT_OPT_Z_MOTOR_CHOICE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors[0]);

				m_Motors->m_Optics[2].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Optics[2].motors);

				opt_z_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			opt_z_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Range");

				m_Motors->m_Optics[2].ranges = new wxStaticText(
					main_panel, 
					SettingsVariables::ID_MOT_OPT_Z_RANGE_ST_TEXT, 
					wxT("None"), 
					wxDefaultPosition, 
					wxDefaultSize, 
					wxALIGN_CENTRE_HORIZONTAL);
				range_static_box_sizer->Add(m_Motors->m_Optics[2].ranges, 1, wxEXPAND | wxTOP, top_offset_static_text);

				opt_z_static_box_sizer->Add(range_static_box_sizer, 1, wxEXPAND);
			}
			optics_static_box_sizer->Add(opt_z_static_box_sizer, 0, wxEXPAND);
		}
		motors_static_box_sizer->Add(optics_static_box_sizer, 0, wxEXPAND);

	}
	main_panel_sizer->Add(motors_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);

	/* Camera */
	wxSizer* const cameras_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, main_panel, "&Camera");
	{
		//m_Cameras = std::make_unique<SettingsVariables::Cameras>();
		auto cam_choice_size = wxSize(80, 24);
		m_Cameras->camera = new wxChoice
		(
			main_panel, 
			SettingsVariables::ID_CAM_CHOICE, 
			wxDefaultPosition, 
			cam_choice_size, 
			m_Cameras->all_cameras_arr
		);

		m_Cameras->camera->SetSelection(0);

		cameras_static_box_sizer->AddStretchSpacer();
		cameras_static_box_sizer->Add(m_Cameras->camera, 0, wxEXPAND);
		cameras_static_box_sizer->AddStretchSpacer();
	}
	main_panel_sizer->Add(cameras_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);
	main_panel_sizer->AddSpacer(5);
	main_panel_sizer->AddStretchSpacer();

	UpdatePreviousStatesData();

	/* Control Buttons */
	{
		m_RefreshBtn = std::make_unique<wxButton>(main_panel, wxID_ANY, wxT("Refresh"));

		m_OkBtn = std::make_unique<wxButton>(main_panel, wxID_ANY, wxT("OK"));
		m_OkBtn->SetFocus();

		m_CancelBtn = std::make_unique<wxButton>(main_panel, wxID_ANY, wxT("Cancel"));

		wxBoxSizer* btns_sizer = new wxBoxSizer(wxHORIZONTAL);
		btns_sizer->Add(m_RefreshBtn.get());
		btns_sizer->AddStretchSpacer();
		btns_sizer->Add(m_OkBtn.get(), 0, wxRIGHT, 2);
		btns_sizer->Add(m_CancelBtn.get());

		main_panel_sizer->Add(btns_sizer, 0, wxEXPAND | wxALL, 2);
	}
	main_panel->SetSizer(main_panel_sizer);
	panel_sizer->Add(main_panel, 1, wxEXPAND);
}

void cSettings::InitDefaultStateWidgets()
{
	/* Disabling X and Z Optics motors choices */
	{
		m_Motors->m_Optics[0].motors->Disable();
		m_Motors->m_Optics[2].motors->Disable();
	}
}

void cSettings::InitComponents()
{
	m_WorkStations = std::make_unique<SettingsVariables::WorkStations>();
	m_Motors = std::make_unique<SettingsVariables::MotorSettingsArray>();
	m_Cameras = std::make_unique<SettingsVariables::Cameras>();
}

void cSettings::BindMotorsAndRangesChoices()
{
	/* Binding Motors */
	{
		/* Detector */
		m_Motors->m_Detector[0].motors->Bind(wxEVT_CHOICE, &cSettings::OnMotorsChoice, this);
		m_Motors->m_Detector[1].motors->Bind(wxEVT_CHOICE, &cSettings::OnMotorsChoice, this);
		m_Motors->m_Detector[2].motors->Bind(wxEVT_CHOICE, &cSettings::OnMotorsChoice, this);
		/* Optics */
		m_Motors->m_Optics[0].motors->Bind(wxEVT_CHOICE, &cSettings::OnMotorsChoice, this);
		m_Motors->m_Optics[1].motors->Bind(wxEVT_CHOICE, &cSettings::OnMotorsChoice, this);
		m_Motors->m_Optics[2].motors->Bind(wxEVT_CHOICE, &cSettings::OnMotorsChoice, this);
	}

	/* Binding Bottom Buttons */
	{
		m_RefreshBtn->Bind(wxEVT_BUTTON, &cSettings::OnRefreshBtn, this);
		m_OkBtn->Bind(wxEVT_BUTTON, &cSettings::OnOkBtn, this);
		m_CancelBtn->Bind(wxEVT_BUTTON, &cSettings::OnCancelBtn, this);
	}
}

void cSettings::OnMotorsChoice(wxCommandEvent& evt)
{
	/* Set the selected motor value for each motor */
	for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
	{
		if (motor < m_MotorsCount / 2)
		{
			m_Motors->m_Detector[motor].current_selection[0] = m_Motors->m_Detector[motor].motors->GetSelection();
		}
		else
		{
			m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[0] = m_Motors->m_Optics[motor - m_MotorsCount / 2].motors->GetSelection();
		}
	}
	UpdateRangesTextCtrls();
}

void cSettings::UpdateRangesTextCtrls()
{	
	wxString find_string{}, current_range_text{};
	uint8_t current_index{};
	/* Set the corresponding range for selected motors */
	for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
	{
		if (motor < m_MotorsCount / 2)
		{
			current_index = m_Motors->m_Detector[motor].current_selection[0];
			find_string = m_Motors->unique_motors[0][current_index];
			if (find_string == "None")
			{
				m_Motors->m_Detector[motor].ranges->SetLabel("None");
				m_Motors->m_Detector[motor].current_selection[1] = 0;
				continue;
			}
			current_index = m_Motors->xml_all_motors[0].Index(find_string);
			current_range_text = m_Motors->xml_all_motors[1].Item(current_index);

			m_Motors->m_Detector[motor].ranges->SetLabel(current_range_text);
			/* Update current_selection index of range */
			current_index = m_Motors->unique_motors[1].Index(current_range_text);
			m_Motors->m_Detector[motor].current_selection[1] = current_index;
		}
		else
		{
			current_index = m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[0];
			find_string = m_Motors->unique_motors[0][current_index];
			if (find_string == "None")
			{
				m_Motors->m_Optics[motor - m_MotorsCount / 2].ranges->SetLabel("None");
				m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[1] = 0;
				continue;
			}
			current_index = m_Motors->xml_all_motors[0].Index(find_string);
			current_range_text = m_Motors->xml_all_motors[1].Item(current_index);

			m_Motors->m_Optics[motor - m_MotorsCount / 2].ranges->SetLabel(current_range_text);
			/* Update current_selection index of range */
			current_index = m_Motors->unique_motors[1].Index(current_range_text);
			m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[1] = current_index;
		}
	}
}

void cSettings::OnRefreshBtn(wxCommandEvent& evt)
{
	wxBusyCursor busy_cursor{};
	SelectMotorsAndRangesOnWXChoice();
	for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
	{
		if (motor < m_MotorsCount / 2)
		{
			m_Motors->m_Detector[motor].current_selection[0] = 0;
			m_Motors->m_Detector[motor].current_selection[1] = 0;
			m_Motors->m_Detector[motor].motors->SetSelection(0);
			m_Motors->m_Detector[motor].ranges->SetLabel("None");
			m_Motors->m_Detector[motor].prev_selection[0] = 0;
			m_Motors->m_Detector[motor].prev_selection[1] = 0;
		}
		else
		{
			m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[0] = 0;
			m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[1] = 0;
			m_Motors->m_Optics[motor - m_MotorsCount / 2].motors->SetSelection(0);
			m_Motors->m_Optics[motor - m_MotorsCount / 2].ranges->SetLabel("None");
			m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[0] = 0;
			m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[1] = 0;
		}
	}
	ResetAllMotorsAndRangesInXMLFile();
	/*
	{
		m_PhysicalMotors = std::make_unique<MotorArray>();
		auto physical_motors = m_PhysicalMotors->GetNamesWithRanges();
		m_Motors->unique_motors_map.clear();
		for (const auto& motor : physical_motors)
		{
			m_Motors->unique_motors_map.emplace(motor);
		}
	}
	UpdateUniqueArray();
	*/
}

void cSettings::OnOkBtn(wxCommandEvent& evt)
{
	if (
		!CheckIfThereIsCollisionWithMotors() && 
		CheckIfUserSelectedAllRangesForAllSelectedMotors() && 
		CheckIfUserSelectedAllMotorsForAllSelectedRanges())
	{
		Hide();
		UpdatePreviousStatesData();
		WriteActualSelectedMotorsAndRangesIntoXMLFile();
	}
}

bool cSettings::CheckIfThereIsCollisionWithMotors()
{
	auto raise_exception_msg = []() 
	{
		wxString title = "Motor selection error";
		wxMessageBox(
			wxT
			(
				"There is a collision of motors"
				"\nYou have selected minimum 2 axis on the same motor ID"
				"\nPlease, change selection and try again"
			),
			title,
			wxICON_ERROR);
	};
	uint8_t selected_motor_number{};
	for (auto current_motor{ 0 }; current_motor < m_MotorsCount; ++current_motor)
	{
		if (current_motor < m_MotorsCount / 2)
		{
			selected_motor_number = m_Motors->m_Detector[current_motor].current_selection[0];
		}
		else
		{
			selected_motor_number = m_Motors->m_Optics[current_motor - m_MotorsCount / 2].current_selection[0];
		}

		for (auto comp_motor{ 0 }; comp_motor < m_MotorsCount; ++comp_motor)
		{
			if (current_motor == comp_motor) continue;

			if (comp_motor < 3)
			{
				if (selected_motor_number == m_Motors->m_Detector[comp_motor].current_selection[0] && selected_motor_number != 0)
				{
					raise_exception_msg();
					return true;
				}
				else
					continue;
			}
			else
			{	
				if (selected_motor_number == m_Motors->m_Optics[comp_motor - m_MotorsCount / 2].current_selection[0] && selected_motor_number != 0)
				{
					raise_exception_msg();
					return true;
				}
				else
					continue;
			}
		}
	}
	return false;
}

bool cSettings::CheckIfUserSelectedAllRangesForAllSelectedMotors()
{
	auto raise_exception_msg = []() 
	{
		wxString title = "Range selection error";
		wxMessageBox(
			wxT
			(
				"You didn't select ranges for all selected motors"
				"\nPlease, select ranges for all selected motors and try again"
			),
			title,
			wxICON_ERROR);
	};

	for (auto comp_motor{ 0 }; comp_motor < m_MotorsCount; ++comp_motor)
	{
		if (comp_motor < 3)
		{
			if (m_Motors->m_Detector[comp_motor].current_selection[0] != 0 && m_Motors->m_Detector[comp_motor].current_selection[1] == 0)
			{
				raise_exception_msg();
				return false;
			}
			else
				continue;
		}
		else
		{	
			if (m_Motors->m_Optics[comp_motor - m_MotorsCount / 2].current_selection[0] != 0 && m_Motors->m_Optics[comp_motor - m_MotorsCount / 2].current_selection[1] == 0)
			{
				raise_exception_msg();
				return false;
			}
			else
				continue;
		}
	}
	return true;
}

bool cSettings::CheckIfUserSelectedAllMotorsForAllSelectedRanges()
{	
	auto raise_exception_msg = []() 
	{
		wxString title = "Motor selection error";
		wxMessageBox(
			wxT
			(
				"You didn't select motors for all selected ranges"
				"\nPlease, select motors for all selected ranges and try again"
			),
			title,
			wxICON_ERROR);
	};

	for (auto comp_motor{ 0 }; comp_motor < m_MotorsCount; ++comp_motor)
	{
		if (comp_motor < 3)
		{
			if (m_Motors->m_Detector[comp_motor].current_selection[1] != 0 && m_Motors->m_Detector[comp_motor].current_selection[0] == 0)
			{
				raise_exception_msg();
				return false;
			}
			else
				continue;
		}
		else
		{	
			if (m_Motors->m_Optics[comp_motor - m_MotorsCount / 2].current_selection[1] != 0 && m_Motors->m_Optics[comp_motor - m_MotorsCount / 2].current_selection[0] == 0)
			{
				raise_exception_msg();
				return false;
			}
			else
				continue;
		}
	}
	return true;
}

void cSettings::OnCancelBtn(wxCommandEvent& evt)
{
	Hide();
	SetPreviousStatesDataAsCurrentSelection();
}

unsigned int cSettings::FindSerialNumber
(
	const uint8_t selection_number, 
	const SettingsVariables::MotorSettings* motor_settings
) const
{
	wxString find_string{};
	find_string = m_Motors->unique_motors[0][selection_number];
	return (unsigned int)wxAtoi(find_string);
}

auto cSettings::CompareXMLWithConnectedDevices()
{
	auto raise_exception_msg = []() 
	{
		wxString title = "Device enumeration error";
		wxMessageBox(
			wxT
			(
				"Data file is not correct!"
				"\nData from file don't correspond with connected devices"
			),
			title,
			wxICON_ERROR);
	};

	m_PhysicalMotors = std::make_unique<MotorArray>();

	auto physical_motors = m_PhysicalMotors->GetNamesWithRanges();
	unsigned short serial_numbers_in_xml = m_Motors->unique_motors_map.size();
	m_Motors->unique_motors_map.clear();
	for (const auto& motor : physical_motors)
	{
		m_Motors->unique_motors_map.emplace(motor);
	}

	auto default_state_of_motors = [&]()
	{
		m_Motors->xml_all_motors[0].Clear();
		m_Motors->xml_all_motors[1].Clear();
		m_Motors->xml_selected_motors[0].Clear();
		m_Motors->xml_selected_motors[1].Clear();

		wxString motor_sn{}, motor_range{};
		std::map<unsigned int, float>::iterator phys_mot_iter = physical_motors.begin();
		for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
		{
			if (motor < physical_motors.size())
			{
				motor_sn = wxString::Format(wxT("%i"), phys_mot_iter->first);
				motor_range = wxString::Format(wxT("%.2f"), phys_mot_iter->second);
				++phys_mot_iter;
			}
			else
			{
				motor_sn = "None";
				motor_range = "None";
			}
			m_Motors->xml_all_motors[0].Add(motor_sn);
			m_Motors->xml_all_motors[1].Add(motor_range);
		}

		for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
		{
			if (motor < m_MotorsCount / 2)
			{
				m_Motors->m_Detector[motor].prev_selection[0] = 0;
				m_Motors->m_Detector[motor].prev_selection[1] = 0;
				m_Motors->m_Detector[motor].current_selection[0] = 0;
				m_Motors->m_Detector[motor].current_selection[1] = 0;
			}
			else
			{
				m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[0] = 0;
				m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[1] = 0;
				m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[0] = 0;
				m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[1] = 0;
			}
			m_Motors->xml_selected_motors[0].Add("None");
			m_Motors->xml_selected_motors[1].Add("None");
		}
	};

	if (serial_numbers_in_xml != m_Motors->unique_motors_map.size() || serial_numbers_in_xml == 0)
	{
		m_Motors->unique_motors_map = physical_motors;
		default_state_of_motors();
		raise_exception_msg();
	}
}

auto cSettings::ReadWorkStationFiles() -> void
{
	m_WorkStations->work_stations_arr.Clear();
	m_WorkStations->work_stations_arr.Add("None");

	std::string file_name_with_path{};
	wxString work_station_name{};
	for (const auto& entry : std::filesystem::directory_iterator(work_stations_path.ToStdString())) 
	{
		if (entry.is_regular_file() && entry.path().extension() == ".xml")
		{
			file_name_with_path = work_stations_path.ToStdString() + entry.path().filename().string();
			//work_station_name = wxString(file_name_with_path);
			auto xmlFile = std::make_unique<rapidxml::file<>>(file_name_with_path.c_str());
			auto document = std::make_unique<rapidxml::xml_document<>>();
			document->parse<0>(xmlFile->data());
			rapidxml::xml_node<>* work_station_node = document->first_node("station");

			if (!work_station_node)
				return;
			m_WorkStations->work_stations_arr.Add(wxString(work_station_node->first_node()->value()));
		}
	}
}

auto cSettings::IterateOverConnectedCameras() -> void
{
	auto ximea_cameras = std::make_unique<XimeaControl>();
	ximea_cameras->InitializeAllCameras();
	m_Cameras->all_cameras_arr.Clear();
	m_Cameras->all_cameras_arr.Add("None");

	auto cameras_count = ximea_cameras->GetCamerasCount();
	for (auto i{ 0 }; i < cameras_count; ++i)
	{
		m_Cameras->all_cameras_arr.Add(wxString(ximea_cameras->GetCamerasSN()[i]));
	}
}

void cSettings::ReadXMLFile()
{
	auto xmlFile = std::make_unique<rapidxml::file<>>(xml_file_path.c_str());
	auto document = std::make_unique<rapidxml::xml_document<>>();
	document->parse<0>(xmlFile->data());
	rapidxml::xml_node<>* motors_node = document->first_node("motors");

	if (!motors_node)
		return;

	auto xml_parser = [&](rapidxml::xml_node<>* motor_array) 
	{
		auto motor = motor_array->first_node();
		auto value = motor->value();
		m_Motors->xml_selected_motors[0].Add(motor->value());
		value = motor->next_sibling()->value();
		m_Motors->xml_selected_motors[1].Add(motor->next_sibling()->value());
	};

	m_Motors->xml_all_motors[0].Clear();
	m_Motors->xml_all_motors[1].Clear();
	m_Motors->xml_selected_motors[0].Clear();
	m_Motors->xml_selected_motors[1].Clear();

	/* Filling all_motors array */
	for (rapidxml::xml_node<>* item = motors_node->first_node()->first_node(); item; item = item->next_sibling())
	{
		auto node = item->first_node();
		auto value = node->value();
		m_Motors->xml_all_motors[0].Add(node->value());
		value = node->next_sibling()->value();
		m_Motors->xml_all_motors[1].Add(node->next_sibling()->value());
	}
	/* Filling selected motors data */
	for (rapidxml::xml_node<>* detector = motors_node->first_node()->next_sibling()->first_node()->first_node(); detector; detector = detector->next_sibling())
	{
		xml_parser(detector);
	}
	for (rapidxml::xml_node<>* optics = motors_node->first_node()->next_sibling()->first_node()->next_sibling()->first_node(); optics; optics = optics->next_sibling())
	{
		xml_parser(optics);
	}

	/* Adding unique elements from xml_motors_list into std::map */
	m_Motors->unique_motors_map.clear();

	int count{};
	for (const auto& note : m_Motors->xml_all_motors[0])
	{
		if (note != "None")
		{
			m_Motors->unique_motors_map.emplace(std::make_pair(wxAtoi(note), wxAtof(m_Motors->xml_all_motors[1][count])));
			++count;
		}
	}
	CompareXMLWithConnectedDevices();
	UpdateUniqueArray();
}

void cSettings::UpdateUniqueArray()
{
	m_Motors->unique_motors[0].Clear();
	m_Motors->unique_motors[1].Clear();
	m_Motors->unique_motors[0].Add("None");
	m_Motors->unique_motors[1].Add("None");

	for (const auto& motor : m_Motors->unique_motors_map)
	{
		m_Motors->unique_motors[0].Add(wxString::Format(wxT("%i"), motor.first));
		m_Motors->unique_motors[1].Add(wxString::Format(wxT("%.2f"), motor.second));
	}
}

void cSettings::SelectMotorsAndRangesFromXMLFile()
{
	auto raise_exception_msg = []() 
	{
		wxString title = "Data file error";
		wxMessageBox(
			wxT
			(
				"Data file is not correct!"
				"\nSelected motors data don't correspond to all motors data"
			),
			title,
			wxICON_ERROR);
	};

	auto reset_all_selected_values = [&]() 
	{
		for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
		{
			if (motor < m_MotorsCount / 2)
			{
				m_Motors->m_Detector[motor].prev_selection[0] = 0;
				m_Motors->m_Detector[motor].prev_selection[1] = 0;
			}
			else
			{
				m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[0] = 0;
				m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[1] = 0;
			}
		}

	};

	auto check_index = [&](short index) -> bool
	{
		if (index == wxNOT_FOUND)
		{
			reset_all_selected_values();
			raise_exception_msg();
			return false;
		}
		return true;
	};

	wxString current_motor_text{};
	short current_motor_index{};
	for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
	{
		if (motor < m_MotorsCount / 2)
		{
			current_motor_text = m_Motors->xml_selected_motors[0][motor];
			current_motor_index = m_Motors->unique_motors[0].Index(current_motor_text);
			if (!check_index(current_motor_index)) return;
			m_Motors->m_Detector[motor].prev_selection[0] = current_motor_index;
			m_Motors->m_Detector[motor].current_selection[0] = current_motor_index;

			current_motor_text = m_Motors->xml_selected_motors[1][motor];
			current_motor_index = m_Motors->unique_motors[1].Index(current_motor_text);
			if (!check_index(current_motor_index)) return;
			m_Motors->m_Detector[motor].prev_selection[1] = current_motor_index;
			m_Motors->m_Detector[motor].current_selection[1] = current_motor_index;
		}
		else
		{
			current_motor_text = m_Motors->xml_selected_motors[0][motor];
			current_motor_index = m_Motors->unique_motors[0].Index(current_motor_text);
			if (!check_index(current_motor_index)) return;
			m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[0] = current_motor_index;
			m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[0] = current_motor_index;
			
			current_motor_text = m_Motors->xml_selected_motors[1][motor];
			current_motor_index = m_Motors->unique_motors[1].Index(current_motor_text);
			if (!check_index(current_motor_index)) return;
			m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[1] = current_motor_index;
			m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[1] = current_motor_index;
		}
	}
}

void cSettings::SelectMotorsAndRangesOnWXChoice()
{
	SelectMotorsAndRangesFromXMLFile();
	short current_index{};
	for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
	{
		if (motor < m_MotorsCount / 2)
		{
			current_index = m_Motors->m_Detector[motor].current_selection[0];
			m_Motors->m_Detector[motor].motors->SetSelection(current_index);

			current_index = m_Motors->m_Detector[motor].current_selection[1];
			m_Motors->m_Detector[motor].ranges->SetLabel(m_Motors->unique_motors[1][current_index]);
		}
		else
		{
			current_index = m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[0];
			m_Motors->m_Optics[motor - m_MotorsCount / 2].motors->SetSelection(current_index);
			
			current_index = m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[1];
			m_Motors->m_Optics[motor - m_MotorsCount / 2].ranges->SetLabel(m_Motors->unique_motors[1][current_index]);
		}
	}
}

void cSettings::UpdatePreviousStatesData()
{
	int current_index{};
	for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
	{
		if (motor < m_MotorsCount / 2)
		{
			current_index= m_Motors->m_Detector[motor].motors->GetSelection();
			m_Motors->m_Detector[motor].prev_selection[0] = current_index;

			current_index= m_Motors->m_Detector[motor].current_selection[1];
			m_Motors->m_Detector[motor].prev_selection[1] = current_index;
		}
		else
		{
			current_index= m_Motors->m_Optics[motor - m_MotorsCount / 2].motors->GetSelection();
			m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[0] = current_index;

			current_index= m_Motors->m_Optics[motor - m_MotorsCount / 2].current_selection[1];
			m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[1] = current_index;
		}
	}
	/* Check selected Camera */
	{
		auto selected_camera_num = m_Cameras->camera->GetSelection();
		if (selected_camera_num != wxNOT_FOUND)
			m_Cameras->selected_camera = m_Cameras->camera->GetString(selected_camera_num);
	}
}

void cSettings::SetPreviousStatesDataAsCurrentSelection()
{
	int current_index{};
	for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
	{
		if (motor < m_MotorsCount / 2)
		{
			m_Motors->m_Detector[motor].motors->SetSelection(m_Motors->m_Detector[motor].prev_selection[0]);
			current_index = m_Motors->m_Detector[motor].prev_selection[1];
			m_Motors->m_Detector[motor].ranges->SetLabel(m_Motors->unique_motors[1][current_index]);
		}
		else
		{
			m_Motors->m_Optics[motor - m_MotorsCount / 2].motors->SetSelection(m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[0]);
			current_index = m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selection[1];
			m_Motors->m_Optics[motor - m_MotorsCount / 2].ranges->SetLabel(m_Motors->unique_motors[1][current_index]);
		}
	}
}

void cSettings::WriteActualSelectedMotorsAndRangesIntoXMLFile()
{
	auto document = std::make_unique<rapidxml::xml_document<>>();
	// Open *.xml file
	std::ifstream xml_file(xml_file_path.mb_str());
	// Preparing buffer
	std::stringstream file_buffer;
	file_buffer << xml_file.rdbuf();
	xml_file.close();

	std::string content(file_buffer.str());
	document->parse<0 | rapidxml::parse_no_data_nodes>(&content[0]);
	rapidxml::xml_node<>* motors_node = document->first_node("motors");

	if (!motors_node)
		return;

	int count{};
	for (
		rapidxml::xml_node<>* motor = motors_node->first_node()->first_node(); 
		motor; 
		motor = motor->next_sibling()
		)
	{
		motor->first_node()->value(m_Motors->xml_all_motors[0][count]);
		motor->first_node()->next_sibling()->value(m_Motors->xml_all_motors[1][count]);
		++count;
	}


	uint8_t position_in_unique_array{};
	auto xml_parser = [&](rapidxml::xml_node<>* motor_array, const int& i) 
	{
		if (i < m_MotorsCount / 2)
		{
			position_in_unique_array = m_Motors->m_Detector[i].prev_selection[0];
			motor_array->first_node()->value(m_Motors->unique_motors[0][position_in_unique_array]);

			position_in_unique_array = m_Motors->m_Detector[i].prev_selection[1];
			motor_array->first_node()->next_sibling()->value(m_Motors->unique_motors[1][position_in_unique_array]);
		}
		else
		{
			position_in_unique_array = m_Motors->m_Optics[i - m_MotorsCount / 2].prev_selection[0];
			motor_array->first_node()->value(m_Motors->unique_motors[0][position_in_unique_array]);

			position_in_unique_array = m_Motors->m_Optics[i - m_MotorsCount / 2].prev_selection[1];
			motor_array->first_node()->next_sibling()->value(m_Motors->unique_motors[1][position_in_unique_array]);
		}
	};
	/* Changing values of selected motors data in XML file */
	count = 0;
	for (
		rapidxml::xml_node<>* detector = motors_node->first_node()->next_sibling()->first_node()->first_node(); 
		detector; 
		detector = detector->next_sibling()
		)
	{
		xml_parser(detector, count);
		++count;
	}
	for (
		rapidxml::xml_node<>* optics = motors_node->first_node()->next_sibling()->first_node()->next_sibling()->first_node(); 
		optics; 
		optics = optics->next_sibling()
		)
	{
		xml_parser(optics, count);
		++count;
	}

	// Save to file
	std::ofstream out_file(xml_file_path.mb_str());
	if (out_file.is_open())
	{
		out_file << "<?xml version=\"1.0\"?>\n";
		out_file << *document;
		out_file.close();
	}
	document->clear();
}

void cSettings::ResetAllMotorsAndRangesInXMLFile()
{
	auto document = std::make_unique<rapidxml::xml_document<>>();
	// Open *.xml file
	std::ifstream xml_file(xml_file_path.mb_str());
	// Preparing buffer
	std::stringstream file_buffer;
	file_buffer << xml_file.rdbuf();
	xml_file.close();

	std::string content(file_buffer.str());
	document->parse<0 | rapidxml::parse_no_data_nodes>(&content[0]);
	rapidxml::xml_node<>* motors_node = document->first_node("motors");

	if (!motors_node)
		return;

	int count{};
	/* Changing values in all_motors node */
	for (
		rapidxml::xml_node<>* motor = motors_node->first_node()->first_node(); 
		motor; 
		motor = motor->next_sibling()
		)
	{
		motor->first_node()->value("None");
		motor->first_node()->next_sibling()->value("None");
		++count;
	}


	auto xml_parser = [&](rapidxml::xml_node<>* motor_array, const int& i) 
	{
		if (i < m_MotorsCount / 2)
		{
			motor_array->first_node()->value("None");
			motor_array->first_node()->next_sibling()->value("None");
		}
		else
		{
			motor_array->first_node()->value("None");
			motor_array->first_node()->next_sibling()->value("None");
		}
	};
	/* Changing values in selected_motors node */
	count = 0;
	for (
		rapidxml::xml_node<>* detector = motors_node->first_node()->next_sibling()->first_node()->first_node(); 
		detector; 
		detector = detector->next_sibling()
		)
	{
		xml_parser(detector, count);
		++count;
	}
	for (
		rapidxml::xml_node<>* optics = motors_node->first_node()->next_sibling()->first_node()->next_sibling()->first_node(); 
		optics; 
		optics = optics->next_sibling()
		)
	{
		xml_parser(optics, count);
		++count;
	}

	// Save to file
	std::ofstream out_file(xml_file_path.mb_str());
	if (out_file.is_open())
	{
		out_file << "<?xml version=\"1.0\"?>\n";
		out_file << *document;
		out_file.close();
	}
	document->clear();

}
