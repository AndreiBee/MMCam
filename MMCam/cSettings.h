#pragma once
#ifndef CSETTINGS_H
#define CSETTINGS_H

#include "wx/wx.h"

#include <memory>

class cSettings final : public wxDialog
{
public:
	cSettings(wxWindow* parent_frame);

private:
	void CreateMainFrame();
	void CreateSettings();
	void CreateMotorsSelection(wxBoxSizer* panel_sizer);
	void InitDefaultStateWidgets();

private:
	wxButton* m_OkBtn{}, *m_CancelBtn{}, *m_RefreshBtn{};
};

#endif // !CSETTINGS_H

