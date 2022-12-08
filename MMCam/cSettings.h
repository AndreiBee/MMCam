#pragma once
#ifndef CSETTINGS_H
#define CSETTINGS_H

#include "wx/wx.h"

#include <memory>
#include <map>
#include <set>
#include <sstream>
#include <fstream>

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_print.hpp"

#include "Motor.h"

namespace SettingsVariables
{
	enum
	{
		/* Detector X */
		ID_MOT_DET_X_MOTOR_CHOICE,
		ID_MOT_DET_X_RANGE_ST_TEXT,
		/* Detector Y */
		ID_MOT_DET_Y_MOTOR_CHOICE,
		ID_MOT_DET_Y_RANGE_ST_TEXT,
		/* Detector Z */
		ID_MOT_DET_Z_MOTOR_CHOICE,
		ID_MOT_DET_Z_RANGE_ST_TEXT,
		/* Optics X */
		ID_MOT_OPT_X_MOTOR_CHOICE,
		ID_MOT_OPT_X_RANGE_ST_TEXT,
		/* Optics Y */
		ID_MOT_OPT_Y_MOTOR_CHOICE,
		ID_MOT_OPT_Y_RANGE_ST_TEXT,
		/* Optics Z */
		ID_MOT_OPT_Z_MOTOR_CHOICE,
		ID_MOT_OPT_Z_RANGE_ST_TEXT,
	};

	struct MotorSettings
	{
		wxChoice* motors{}; 
		wxStaticText* ranges{};
		uint8_t current_selection[2], prev_selection[2];
	};

	struct MotorSettingsArray
	{
		std::unique_ptr<MotorSettings[]> m_Detector{}, m_Optics{};

		wxArrayString xml_all_motors[2];
		wxArrayString xml_selected_motors[2];

		std::map<int, float> unique_motors_map;
		//std::set<float> unique_motors_set[2];
		wxArrayString unique_motors[2];

		MotorSettingsArray()
		{
			m_Detector = std::make_unique<MotorSettings[]>(3);
			m_Optics = std::make_unique<MotorSettings[]>(3);
		}
	};
}

class cSettings final : public wxDialog
{
public:
	cSettings(wxWindow* parent_frame);

private:
	void CreateMainFrame();
	void CreateSettings();
	void CreateMotorsSelection(wxBoxSizer* panel_sizer);
	void InitDefaultStateWidgets();
	void InitComponents();

	void BindMotorsAndRangesChoices();
	void OnMotorsChoice(wxCommandEvent& evt);
	void UpdateRangesTextCtrls();

	void OnRefreshBtn(wxCommandEvent& evt);
	void OnOkBtn(wxCommandEvent& evt);
	bool CheckIfThereIsCollisionWithMotors();
	bool CheckIfUserSelectedAllRangesForAllSelectedMotors();
	bool CheckIfUserSelectedAllMotorsForAllSelectedRanges();
	void OnCancelBtn(wxCommandEvent& evt);

	/* Working with XML data and operating with m_Motors variables */
	void ReadXMLFile();
	void UpdateUniqueArray();
	void SelectMotorsAndRangesFromXMLFile();
	void SelectMotorsAndRangesOnWXChoice();
	void UpdatePreviousStatesData();
	void SetPreviousStatesDataAsCurrentSelection();
	void WriteActualSelectedMotorsAndRangesIntoXMLFile();

private:
	const wxString xml_file_path = "src\\mtrs.xml";
	wxButton* m_OkBtn{}, *m_CancelBtn{}, *m_RefreshBtn{};
	std::unique_ptr<SettingsVariables::MotorSettingsArray> m_Motors{};
	const int m_MotorsCount{ 6 };
};

#endif // !CSETTINGS_H

