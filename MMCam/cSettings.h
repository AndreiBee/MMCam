#pragma once
#ifndef CSETTINGS_H
#define CSETTINGS_H

#include "wx/wx.h"

#include <memory>

namespace SettingsVariables
{
	struct MotorSettings
	{
		wxChoice* motors{}, * ranges{};
		wxArrayString motors_list, ranges_list;

		MotorSettings()
		{
			motors_list.Add("12598");
			motors_list.Add("12596");
			motors_list.Add("12472");
			motors_list.Add("12947");
			motors_list.Add("14048");
			motors_list.Add("16890");

			ranges_list.Add("5 mm");
			ranges_list.Add("10 mm");
			ranges_list.Add("20 mm");
			ranges_list.Add("25 mm");
			ranges_list.Add("50 mm");
			ranges_list.Add("100 mm");
		};

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

private:
	wxButton* m_OkBtn{}, *m_CancelBtn{}, *m_RefreshBtn{};
	std::unique_ptr<SettingsVariables::MotorSettings> m_DetX{}, m_DetY{}, m_DetZ{}, m_OptX{}, m_OptY{}, m_OptZ{};
};

#endif // !CSETTINGS_H

