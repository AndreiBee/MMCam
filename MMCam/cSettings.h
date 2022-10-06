#pragma once
#ifndef CSETTINGS_H
#define CSETTINGS_H

#include "wx/wx.h"

#include <memory>

#define PUGIXML_HEADER_ONLY
#include "src/third_libs/pugixml.hpp"

namespace SettingsVariables
{
	enum
	{
		/* Detector X */
		ID_MOT_DET_X_MOTOR,
		ID_MOT_DET_X_RANGE,
		/* Detector Y */
		ID_MOT_DET_Y_MOTOR,
		ID_MOT_DET_Y_RANGE,
		/* Detector Z */
		ID_MOT_DET_Z_MOTOR,
		ID_MOT_DET_Z_RANGE,
		/* Optics X */
		ID_MOT_OPT_X_MOTOR,
		ID_MOT_OPT_X_RANGE,
		/* Optics Y */
		ID_MOT_OPT_Y_MOTOR,
		ID_MOT_OPT_Y_RANGE,
		/* Optics Z */
		ID_MOT_OPT_Z_MOTOR,
		ID_MOT_OPT_Z_RANGE,
	};

	struct MotorSettings
	{
		wxChoice* motors{}, * ranges{};
		uint8_t selected_motor{}, selected_range{};
	};

	struct MotorSettingsArray
	{
		std::unique_ptr<MotorSettings[]> m_Detector{}, m_Optics{};
		wxArrayString xml_motors_list, xml_ranges_list;
		wxArrayString unique_motors_list, unique_ranges_list;
		MotorSettingsArray()
		{
			m_Detector = std::make_unique<MotorSettings[]>(3);
			m_Optics = std::make_unique<MotorSettings[]>(3);

			unique_motors_list.Add("None");
			unique_ranges_list.Add("None");
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
	void OnRangesChoice(wxCommandEvent& evt);

	void OnRefreshBtn(wxCommandEvent& evt);
	void OnOkBtn(wxCommandEvent& evt);
	bool CheckIfThereIsCollisionWithMotors();
	bool CheckIfUserSelectedAllRangesForAllSelectedMotors();
	void OnCancelBtn(wxCommandEvent& evt);

	/* Reading XML data from mtrs.xml file */
	void ReadXMLFile();

private:
	wxButton* m_OkBtn{}, *m_CancelBtn{}, *m_RefreshBtn{};
	std::unique_ptr<SettingsVariables::MotorSettingsArray> m_Motors{};
	const int m_MotorsCount{ 6 };
};

#endif // !CSETTINGS_H

