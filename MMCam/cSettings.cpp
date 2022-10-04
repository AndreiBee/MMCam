#include "cSettings.h"

cSettings::cSettings(wxWindow* parent_frame) 
	: wxDialog(
		parent_frame, 
		wxID_ANY, 
		"Settings", 
		wxDefaultPosition, 
		wxDefaultSize, 
		wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
{
	CreateMainFrame();
	InitDefaultStateWidgets();
	CenterOnScreen();
}

void cSettings::CreateMainFrame()
{
	CreateSettings();
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
			detector_static_box_sizer->Add(det_x_static_box_sizer, 0, wxEXPAND);
			detector_static_box_sizer->AddStretchSpacer();

			/* Y */
			wxSizer* const det_y_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Y");
			detector_static_box_sizer->Add(det_y_static_box_sizer, 0, wxEXPAND);
			detector_static_box_sizer->AddStretchSpacer();

			/* Z */
			wxSizer* const det_z_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Z");
			detector_static_box_sizer->Add(det_z_static_box_sizer, 0, wxEXPAND);
		}
		motors_static_box_sizer->Add(detector_static_box_sizer, 0, wxEXPAND);

		wxSizer* const optics_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Optics");
		{
			/* X */
			wxSizer* const opt_x_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&X");
			optics_static_box_sizer->Add(opt_x_static_box_sizer, 0, wxEXPAND);
			optics_static_box_sizer->AddStretchSpacer();

			/* Y */
			wxSizer* const opt_y_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Y");
			optics_static_box_sizer->Add(opt_y_static_box_sizer, 0, wxEXPAND);
			optics_static_box_sizer->AddStretchSpacer();

			/* Z */
			wxSizer* const opt_z_static_box_sizer = new wxStaticBoxSizer(wxHORIZONTAL, motors_panel, "&Z");
			optics_static_box_sizer->Add(opt_z_static_box_sizer, 0, wxEXPAND);
		}
		motors_static_box_sizer->Add(optics_static_box_sizer, 0, wxEXPAND);

	}
	motors_panel_sizer->Add(motors_static_box_sizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 2);
	
	motors_panel_sizer->AddStretchSpacer();

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

}

