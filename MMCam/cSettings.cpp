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

void cSettings::CreateMainFrame()
{
	InitComponents();
	ReadXMLFile();
	CreateSettings();
	BindMotorsAndRangesChoices();
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
	wxPanel* motors_panel = new wxPanel(this);
#ifdef _DEBUG
	motors_panel->SetBackgroundColour(wxColor(150, 190, 180));
#else
	motors_panel->SetBackgroundColour(wxColor(255, 255, 255));
#endif // _DEBUG
	wxBoxSizer* motors_panel_sizer = new wxBoxSizer(wxVERTICAL);

	wxSizer* const motors_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, motors_panel, "&Motors");
	{
		wxSizer* const detector_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Detector");
		{
			/* X */
			wxSizer* const det_x_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&X");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Detector[0].motors = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_DET_X_MOTOR, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors);

				m_Motors->m_Detector[0].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Detector[0].motors);

				det_x_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			det_x_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Detector[0].ranges = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_DET_X_RANGE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_ranges);
				m_Motors->m_Detector[0].ranges->SetSelection(0);
				range_static_box_sizer->Add(m_Motors->m_Detector[0].ranges);

				det_x_static_box_sizer->Add(range_static_box_sizer);
			}
			detector_static_box_sizer->Add(det_x_static_box_sizer, 0, wxEXPAND);

			detector_static_box_sizer->AddSpacer(2);
			detector_static_box_sizer->AddStretchSpacer();

			/* Y */
			wxSizer* const det_y_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Y");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Detector[1].motors = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_DET_Y_MOTOR, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors);

				m_Motors->m_Detector[1].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Detector[1].motors);

				det_y_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			det_y_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Detector[1].ranges = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_DET_Y_RANGE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_ranges);
				m_Motors->m_Detector[1].ranges->SetSelection(0);
				range_static_box_sizer->Add(m_Motors->m_Detector[1].ranges);

				det_y_static_box_sizer->Add(range_static_box_sizer);
			}
			detector_static_box_sizer->Add(det_y_static_box_sizer, 0, wxEXPAND);
			detector_static_box_sizer->AddSpacer(2);
			detector_static_box_sizer->AddStretchSpacer();

			/* Z */
			wxSizer* const det_z_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Z");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Detector[2].motors = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_DET_Z_MOTOR, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors);

				m_Motors->m_Detector[2].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Detector[2].motors);

				det_z_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			det_z_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Detector[2].ranges = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_DET_Z_RANGE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_ranges);
				m_Motors->m_Detector[2].ranges->SetSelection(0);
				range_static_box_sizer->Add(m_Motors->m_Detector[2].ranges);

				det_z_static_box_sizer->Add(range_static_box_sizer);
			}
			detector_static_box_sizer->Add(det_z_static_box_sizer, 0, wxEXPAND);
		}
		motors_static_box_sizer->Add(detector_static_box_sizer, 0, wxEXPAND);

		wxSizer* const optics_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Optics");
		{
			/* X */
			wxSizer* const opt_x_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&X");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Optics[0].motors = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_OPT_X_MOTOR, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors);

				m_Motors->m_Optics[0].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Optics[0].motors);

				opt_x_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			opt_x_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Optics[0].ranges = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_OPT_X_RANGE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_ranges);
				m_Motors->m_Optics[0].ranges->SetSelection(0);
				range_static_box_sizer->Add(m_Motors->m_Optics[0].ranges);

				opt_x_static_box_sizer->Add(range_static_box_sizer);
			}
			optics_static_box_sizer->Add(opt_x_static_box_sizer, 0, wxEXPAND);
			optics_static_box_sizer->AddSpacer(2);
			optics_static_box_sizer->AddStretchSpacer();

			/* Y */
			wxSizer* const opt_y_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Y");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Optics[1].motors = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_OPT_Y_MOTOR, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors);

				m_Motors->m_Optics[1].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Optics[1].motors);

				opt_y_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			opt_y_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Optics[1].ranges = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_OPT_Y_RANGE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_ranges);
				m_Motors->m_Optics[1].ranges->SetSelection(0);
				range_static_box_sizer->Add(m_Motors->m_Optics[1].ranges);

				opt_y_static_box_sizer->Add(range_static_box_sizer);
			}
			optics_static_box_sizer->Add(opt_y_static_box_sizer, 0, wxEXPAND);
			optics_static_box_sizer->AddSpacer(2);
			optics_static_box_sizer->AddStretchSpacer();

			/* Z */
			wxSizer* const opt_z_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Z");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Optics[2].motors = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_OPT_Z_MOTOR, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_motors);

				m_Motors->m_Optics[2].motors->SetSelection(0);

				sn_static_box_sizer->Add(m_Motors->m_Optics[2].motors);

				opt_z_static_box_sizer->Add(sn_static_box_sizer);
			}
			/* Range */
			opt_z_static_box_sizer->AddSpacer(2);
			{
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Optics[2].ranges = new wxChoice(
					motors_panel, 
					SettingsVariables::ID_MOT_OPT_Z_RANGE, 
					wxDefaultPosition, 
					wxDefaultSize, 
					m_Motors->unique_ranges);
				m_Motors->m_Optics[2].ranges->SetSelection(0);
				range_static_box_sizer->Add(m_Motors->m_Optics[2].ranges);

				opt_z_static_box_sizer->Add(range_static_box_sizer);
			}
			optics_static_box_sizer->Add(opt_z_static_box_sizer, 0, wxEXPAND);
		}
		motors_static_box_sizer->Add(optics_static_box_sizer, 0, wxEXPAND);

	}
	motors_panel_sizer->Add(motors_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);
	motors_panel_sizer->AddSpacer(5);
	motors_panel_sizer->AddStretchSpacer();

	UpdatePreviousStatesData();

	/* Control Buttons */
	{
		m_RefreshBtn = new wxButton(motors_panel, wxID_ANY, wxT("Refresh"));

		m_OkBtn = new wxButton(motors_panel, wxID_ANY, wxT("Ok"));

		m_CancelBtn = new wxButton(motors_panel, wxID_ANY, wxT("Cancel"));

		wxBoxSizer* btns_sizer = new wxBoxSizer(wxHORIZONTAL);
		btns_sizer->Add(m_RefreshBtn);
		btns_sizer->AddStretchSpacer();
		btns_sizer->Add(m_OkBtn, 0, wxRIGHT, 2);
		btns_sizer->Add(m_CancelBtn);

		motors_panel_sizer->Add(btns_sizer, 0, wxEXPAND | wxALL, 2);
	}
	motors_panel->SetSizer(motors_panel_sizer);
	panel_sizer->Add(motors_panel, 1, wxEXPAND);
}

void cSettings::InitDefaultStateWidgets()
{
	/* Disabling X and Z Optics motors choices */
	{
		m_Motors->m_Optics[0].motors->Disable();
		m_Motors->m_Optics[2].motors->Disable();
	}
	/* Disabling X and Z Optics ranges choices */
	{
		m_Motors->m_Optics[0].ranges->Disable();
		m_Motors->m_Optics[2].ranges->Disable();
	}
}

void cSettings::InitComponents()
{
	m_Motors = std::make_unique<SettingsVariables::MotorSettingsArray>();
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
	/* Binding Ranges */
	{
		/* Detector */
		m_Motors->m_Detector[0].ranges->Bind(wxEVT_CHOICE, &cSettings::OnRangesChoice, this);
		m_Motors->m_Detector[1].ranges->Bind(wxEVT_CHOICE, &cSettings::OnRangesChoice, this);
		m_Motors->m_Detector[2].ranges->Bind(wxEVT_CHOICE, &cSettings::OnRangesChoice, this);
		/* Optics */
		m_Motors->m_Optics[0].ranges->Bind(wxEVT_CHOICE, &cSettings::OnRangesChoice, this);
		m_Motors->m_Optics[1].ranges->Bind(wxEVT_CHOICE, &cSettings::OnRangesChoice, this);
		m_Motors->m_Optics[2].ranges->Bind(wxEVT_CHOICE, &cSettings::OnRangesChoice, this);
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
			m_Motors->m_Detector[motor].selected_motor = m_Motors->m_Detector[motor].motors->GetSelection();
		}
		else
		{
			m_Motors->m_Optics[motor - m_MotorsCount / 2].selected_motor = m_Motors->m_Optics[motor - m_MotorsCount / 2].motors->GetSelection();
		}
	}
}

void cSettings::OnRangesChoice(wxCommandEvent& evt)
{
	/* Set the selected range value for each motor */
	for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
	{
		if (motor < m_MotorsCount / 2)
		{
			m_Motors->m_Detector[motor].selected_range = m_Motors->m_Detector[motor].ranges->GetSelection();
		}
		else
		{
			m_Motors->m_Optics[motor - m_MotorsCount / 2].selected_range = m_Motors->m_Optics[motor - m_MotorsCount / 2].ranges->GetSelection();
		}
	}
}

void cSettings::OnRefreshBtn(wxCommandEvent& evt)
{
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
			selected_motor_number = m_Motors->m_Detector[current_motor].selected_motor;
		}
		else
		{
			selected_motor_number = m_Motors->m_Optics[current_motor - m_MotorsCount / 2].selected_motor;
		}

		for (auto comp_motor{ 0 }; comp_motor < m_MotorsCount; ++comp_motor)
		{
			if (current_motor == comp_motor) continue;

			if (comp_motor < 3)
			{
				if (selected_motor_number == m_Motors->m_Detector[comp_motor].selected_motor && selected_motor_number != 0)
				{
					raise_exception_msg();
					return true;
				}
				else
					continue;
			}
			else
			{	
				if (selected_motor_number == m_Motors->m_Optics[comp_motor - m_MotorsCount / 2].selected_motor && selected_motor_number != 0)
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
			if (m_Motors->m_Detector[comp_motor].selected_motor != 0 && m_Motors->m_Detector[comp_motor].selected_range == 0)
			{
				raise_exception_msg();
				return false;
			}
			else
				continue;
		}
		else
		{	
			if (m_Motors->m_Optics[comp_motor - m_MotorsCount / 2].selected_motor != 0 && m_Motors->m_Optics[comp_motor - m_MotorsCount / 2].selected_range == 0)
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
			if (m_Motors->m_Detector[comp_motor].selected_range != 0 && m_Motors->m_Detector[comp_motor].selected_motor == 0)
			{
				raise_exception_msg();
				return false;
			}
			else
				continue;
		}
		else
		{	
			if (m_Motors->m_Optics[comp_motor - m_MotorsCount / 2].selected_range != 0 && m_Motors->m_Optics[comp_motor - m_MotorsCount / 2].selected_motor == 0 )
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

void cSettings::ReadXMLFile()
{
	pugi::xml_document doc;

	pugi::xml_parse_result result = doc.load_file("src\\mtrs.xml");

	if (!result)
		return;

	auto xml_parser = [&](pugi::xml_node motor_array) 
	{
		auto child = motor_array.children().begin();
		m_Motors->xml_motors_list.Add(child->child_value());
		++child;
		m_Motors->xml_ranges_list.Add(child->child_value());
	};

	m_Motors->xml_motors_list.Clear();
	m_Motors->xml_ranges_list.Clear();

	for (pugi::xml_node detector : doc.child("motors").child("detector"))
	{
		xml_parser(detector);
	}
	for (pugi::xml_node optics : doc.child("motors").child("optics"))
	{
		xml_parser(optics);
	}

	/* Adding unique elements from xml_motors_list into map */
	int count{};
	for (const auto& note : m_Motors->xml_motors_list)
	{
		if (note != "None")
		{
			m_Motors->unique_motors_set.insert(note);
			m_Motors->unique_ranges_set.insert(m_Motors->xml_ranges_list[count]);
		}
		++count;
	}
	UpdateUniqueArray();
}

void cSettings::UpdateUniqueArray()
{
	m_Motors->unique_motors.Clear();
	m_Motors->unique_ranges.Clear();
	m_Motors->unique_motors.Add("None");
	m_Motors->unique_ranges.Add("None");

	for (const auto& motor : m_Motors->unique_motors_set)
		m_Motors->unique_motors.Add(motor);
	for (const auto& range : m_Motors->unique_ranges_set)
		m_Motors->unique_ranges.Add(range);
}

void cSettings::UpdatePreviousStatesData()
{
	int current_index_in_choice{};
	for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
	{
		if (motor < m_MotorsCount / 2)
		{
			current_index_in_choice = m_Motors->m_Detector[motor].motors->GetSelection();
			m_Motors->m_Detector[motor].prev_selected_motor = current_index_in_choice;
			m_Motors->prev_state_motors_list.Insert(m_Motors->m_Detector[motor].motors->GetString(current_index_in_choice),	motor);
			current_index_in_choice = m_Motors->m_Detector[motor].ranges->GetSelection();
			m_Motors->m_Detector[motor].prev_selected_range = current_index_in_choice;
			m_Motors->prev_state_ranges_list.Insert(m_Motors->m_Detector[motor].ranges->GetString(current_index_in_choice),	motor);
		}
		else
		{
			current_index_in_choice = m_Motors->m_Optics[motor - m_MotorsCount / 2].motors->GetSelection();
			m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selected_motor = current_index_in_choice;
			m_Motors->prev_state_motors_list.Insert(m_Motors->m_Optics[motor - m_MotorsCount / 2].motors->GetString(current_index_in_choice), motor);
			current_index_in_choice = m_Motors->m_Optics[motor - m_MotorsCount / 2].ranges->GetSelection();
			m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selected_range = current_index_in_choice;
			m_Motors->prev_state_ranges_list.Insert(m_Motors->m_Optics[motor - m_MotorsCount / 2].ranges->GetString(current_index_in_choice), motor);
		}
	}
}

void cSettings::SetPreviousStatesDataAsCurrentSelection()
{
	for (auto motor{ 0 }; motor < m_MotorsCount; ++motor)
	{
		if (motor < m_MotorsCount / 2)
		{
			m_Motors->m_Detector[motor].motors->SetSelection(m_Motors->m_Detector[motor].prev_selected_motor);
			m_Motors->m_Detector[motor].ranges->SetSelection(m_Motors->m_Detector[motor].prev_selected_range);
		}
		else
		{
			m_Motors->m_Optics[motor - m_MotorsCount / 2].motors->SetSelection(m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selected_motor);
			m_Motors->m_Optics[motor - m_MotorsCount / 2].ranges->SetSelection(m_Motors->m_Optics[motor - m_MotorsCount / 2].prev_selected_range);
		}
	}

}
