#pragma once
#ifndef CSETTINGS_H
#define CSETTINGS_H

#include "wx/wx.h"

#include <memory>

namespace SettingsVariables
{
	enum
	{
		ID_MOT_DET_X_MOTOR,
		ID_MOT_DET_X_RANGE,
		ID_MOT_DET_Y_MOTOR,
		ID_MOT_DET_Y_RANGE,
		ID_MOT_DET_Z_MOTOR,
		ID_MOT_DET_Z_RANGE,
		ID_MOT_OPT_X_MOTOR,
		ID_MOT_OPT_X_RANGE,
		ID_MOT_OPT_Y_MOTOR,
		ID_MOT_OPT_Y_RANGE,
		ID_MOT_OPT_Z_MOTOR,
		ID_MOT_OPT_Z_RANGE,
	};
	struct MotorSettings
	{
		wxChoice* motors{}, * ranges{};
		wxArrayString motors_list, ranges_list;

		MotorSettings()
		{
			motors_list.Add("None");
			motors_list.Add("12598");
			motors_list.Add("12596");
			motors_list.Add("12472");
			motors_list.Add("12947");
			motors_list.Add("14048");
			motors_list.Add("16890");

			ranges_list.Add("None");
			ranges_list.Add("5 mm");
			ranges_list.Add("10 mm");
			ranges_list.Add("20 mm");
			ranges_list.Add("25 mm");
			ranges_list.Add("50 mm");
			ranges_list.Add("100 mm");
		};

	};
	struct MotorSettingsArray
	{
		std::unique_ptr<MotorSettings[]> m_Detector{}, m_Optics{};
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
	void OnRangesChoice(wxCommandEvent& evt);

	void OnRefreshBtn(wxCommandEvent& evt);
	void OnOkBtn(wxCommandEvent& evt);
	void OnCancelBtn(wxCommandEvent& evt);

private:
	wxButton* m_OkBtn{}, *m_CancelBtn{}, *m_RefreshBtn{};
	//std::unique_ptr<SettingsVariables::MotorSettings> m_DetX{}, m_DetY{}, m_DetZ{}, m_OptX{}, m_OptY{}, m_OptZ{};
	std::unique_ptr<SettingsVariables::MotorSettingsArray> m_Motors{};
};

#endif // !CSETTINGS_H

