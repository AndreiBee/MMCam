#pragma once
#ifndef CMAIN_H
#define CMAIN_H

#include "wx/wx.h"
#include "wx/valnum.h"

#include <string>
#include <memory>

#include "src/img/center.xpm"
#include "src/img/home.xpm"

namespace MainFrameVariables
{
	enum
	{
		/* Detector X */
		ID_RIGHT_SC_DET_X_ABS_TE_CTL,
		ID_RIGHT_SC_DET_X_SET_BTN,
		ID_RIGHT_SC_DET_X_REL_TE_CTL,
		ID_RIGHT_SC_DET_X_DEC_BTN,
		ID_RIGHT_SC_DET_X_INC_BTN,
		ID_RIGHT_SC_DET_X_CENTER_BTN,
		ID_RIGHT_SC_DET_X_HOME_BTN,
		/* Detector Y */
		ID_RIGHT_SC_DET_Y_ABS_TE_CTL,
		ID_RIGHT_SC_DET_Y_SET_BTN,
		ID_RIGHT_SC_DET_Y_REL_TE_CTL,
		ID_RIGHT_SC_DET_Y_DEC_BTN,
		ID_RIGHT_SC_DET_Y_INC_BTN,
		ID_RIGHT_SC_DET_Y_CENTER_BTN,
		ID_RIGHT_SC_DET_Y_HOME_BTN,
		/* Detector Z */
		ID_RIGHT_SC_DET_Z_ABS_TE_CTL,
		ID_RIGHT_SC_DET_Z_SET_BTN,
		ID_RIGHT_SC_DET_Z_REL_TE_CTL,
		ID_RIGHT_SC_DET_Z_DEC_BTN,
		ID_RIGHT_SC_DET_Z_INC_BTN,
		ID_RIGHT_SC_DET_Z_CENTER_BTN,
		ID_RIGHT_SC_DET_Z_HOME_BTN,
	};
	struct StepperControl
	{
		wxTextCtrl* absolute_text_ctrl{}, *relative_text_ctrl{};
		wxButton* set_btn{}, * increment_btn{}, * decrement_btn{};
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

