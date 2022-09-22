#pragma once
#ifndef CMAIN_H
#define CMAIN_H

#include "wx/wx.h"

#include <string>
#include <memory>

#include "src/img/center.xpm"
#include "src/img/home.xpm"

namespace MainFrameVariables
{
	enum
	{
		ID_RIGHT_SC_DET_X_ABS,
		ID_RIGHT_SC_DET_X_REL,
		ID_RIGHT_SC_DET_X_DEC,
		ID_RIGHT_SC_DET_X_INC,
		ID_RIGHT_SC_DET_X_CENTER,
		ID_RIGHT_SC_DET_X_HOME,
	};
	struct StepperControl
	{
		wxTextCtrl* absolute_text_ctrl{}, *relative_text_ctrl{};
		wxButton* increment_btn{}, * decrement_btn{};
		wxBitmapButton* center_btn{}, * home_btn{};
	};
}

class cMain final : public wxFrame
{
public:
	cMain(const wxString& title_);

private:
	void CreateMainFrame();
	void InitComponents();
	void CreateLeftAndRightSide();
	void CreateLeftSide(wxSizer* left_side_sizer);
	void CreateRightSide(wxSizer* right_side_sizer);
	void CreateSteppersControl(wxPanel* right_side_panel, wxBoxSizer* right_side_panel_sizer);

private:
	std::unique_ptr<MainFrameVariables::StepperControl> m_X_Detector{}, m_Y_Detector{}, m_Z_Detector{};
	std::unique_ptr<MainFrameVariables::StepperControl> m_X_Optics{}, m_Y_Optics{}, m_Z_Optics{};

	wxDECLARE_EVENT_TABLE();
};

#endif // !CMAIN_H

