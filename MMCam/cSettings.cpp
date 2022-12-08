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
	wxPanel* motors_panel = new wxPanel(this);
#ifdef _DEBUG
	motors_panel->SetBackgroundColour(wxColor(150, 190, 180));
#else
	motors_panel->SetBackgroundColour(wxColor(255, 255, 255));
#endif // _DEBUG
	wxBoxSizer* motors_panel_sizer = new wxBoxSizer(wxVERTICAL);

	wxSizer* const motors_static_box_sizer = new wxStaticBoxSizer(wxVERTICAL, motors_panel, "&Motors");
	{
		int top_offset_static_text{ 5 };
		wxSizer* const detector_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Detector");
		{
			/* X */
			wxSizer* const det_x_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&X");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Detector[0].motors = new wxChoice(
					motors_panel, 
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
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Detector[0].ranges = new wxStaticText(
					motors_panel,
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
			wxSizer* const det_y_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Y");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Detector[1].motors = new wxChoice(
					motors_panel, 
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
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Detector[1].ranges = new wxStaticText(
					motors_panel, 
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
			wxSizer* const det_z_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Z");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Detector[2].motors = new wxChoice(
					motors_panel, 
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
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Detector[2].ranges = new wxStaticText(
					motors_panel, 
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

		wxSizer* const optics_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Optics");
		{
			/* X */
			wxSizer* const opt_x_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&X");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Optics[0].motors = new wxChoice(
					motors_panel, 
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
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Optics[0].ranges = new wxStaticText(
					motors_panel, 
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
			wxSizer* const opt_y_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Y");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Optics[1].motors = new wxChoice(
					motors_panel, 
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
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Optics[1].ranges = new wxStaticText(
					motors_panel, 
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
			wxSizer* const opt_z_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Z");
			/* Serial Number */
			{
				wxSizer* const sn_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&S/N");

				m_Motors->m_Optics[2].motors = new wxChoice(
					motors_panel, 
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
				wxSizer* const range_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Range");

				m_Motors->m_Optics[2].ranges = new wxStaticText(
					motors_panel, 
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
	motors_panel_sizer->Add(motors_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);
	motors_panel_sizer->AddSpacer(5);
	motors_panel_sizer->AddStretchSpacer();

	UpdatePreviousStatesData();

	/* Control Buttons */
	{
		m_RefreshBtn = new wxButton(motors_panel, wxID_ANY, wxT("Refresh"));

		m_OkBtn = new wxButton(motors_panel, wxID_ANY, wxT("OK"));

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

void cSettings::ReadXMLFile()
{
	auto xmlFile = std::make_unique<rapidxml::file<>>(xml_file_path.mb_str());
	auto document = std::make_unique<rapidxml::xml_document<>>();
	document->parse<0>(xmlFile->data());
	rapidxml::xml_node<>* motors_node = document->first_node("motors");

	/*
	rapidxml::file<> xmlFile(xml_file_path.mb_str());
	rapidxml::xml_document<> document;
	document.parse<0>(xmlFile.data());
	rapidxml::xml_node<>* motors_node = document.first_node("motors");
	*/
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
		m_Motors->unique_motors_map.emplace(std::make_pair(wxAtoi(note), wxAtof(m_Motors->xml_all_motors[1][count])));
		//m_Motors->unique_motors_set[0].emplace(wxAtoi(note));
		//m_Motors->unique_motors_set[1].emplace(wxAtof(m_Motors->xml_all_motors[1][count]));
		++count;
	}
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


	//for (const auto& motor : m_Motors->unique_motors_set[0])
		//m_Motors->unique_motors[0].Add(wxString::Format(wxT("%i"), (int)motor));
	//for (const auto& range : m_Motors->unique_motors_set[1])
		//m_Motors->unique_motors[1].Add(wxString::Format(wxT("%.2f"), range));
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

	/*
	rapidxml::xml_document<> document;
	// Open *.xml file
	std::ifstream xml_file(xml_file_path.mb_str());
	// Preparing buffer
	std::stringstream file_buffer;
	file_buffer << xml_file.rdbuf();
	xml_file.close();
	std::string content(file_buffer.str());
	document.parse<0 | rapidxml::parse_no_data_nodes>(&content[0]);
	rapidxml::xml_node<>* motors_node = document.first_node("motors");
	*/
	if (!motors_node)
		return;

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
	int count{};
	for (rapidxml::xml_node<>* detector = motors_node->first_node()->next_sibling()->first_node()->first_node(); detector; detector = detector->next_sibling())
	{
		xml_parser(detector, count);
		++count;
	}
	for (rapidxml::xml_node<>* optics = motors_node->first_node()->next_sibling()->first_node()->next_sibling()->first_node(); optics; optics = optics->next_sibling())
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
