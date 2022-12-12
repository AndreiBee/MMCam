#pragma once
#ifndef CMAIN_H
#define CMAIN_H

#include "wx/wx.h"
#include "wx/tglbtn.h"
#include "wx/valnum.h"

#include <string>
#include <memory>

#include "cCamPreview.h"
#include "cSettings.h"

#include "src/img/center.xpm"
#include "src/img/home.xpm"

namespace MainFrameVariables
{
	enum
	{
		ID_MENUBAR_FILE_QUIT,
		ID_MENUBAR_EDIT_SETTINGS,
		ID_MENUBAR_WINDOW_FULLSCREEN,
		ID_MENUBAR_HELP_ABOUT,
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
		/* Optics X */
		ID_RIGHT_SC_OPT_X_ABS_TE_CTL,
		ID_RIGHT_SC_OPT_X_SET_BTN,
		ID_RIGHT_SC_OPT_X_REL_TE_CTL,
		ID_RIGHT_SC_OPT_X_DEC_BTN,
		ID_RIGHT_SC_OPT_X_INC_BTN,
		ID_RIGHT_SC_OPT_X_CENTER_BTN,
		ID_RIGHT_SC_OPT_X_HOME_BTN,	
		/* Optics Y */
		ID_RIGHT_SC_OPT_Y_ABS_TE_CTL,
		ID_RIGHT_SC_OPT_Y_SET_BTN,
		ID_RIGHT_SC_OPT_Y_REL_TE_CTL,
		ID_RIGHT_SC_OPT_Y_DEC_BTN,
		ID_RIGHT_SC_OPT_Y_INC_BTN,
		ID_RIGHT_SC_OPT_Y_CENTER_BTN,
		ID_RIGHT_SC_OPT_Y_HOME_BTN,
		/* Optics Z */
		ID_RIGHT_SC_OPT_Z_ABS_TE_CTL,
		ID_RIGHT_SC_OPT_Z_SET_BTN,
		ID_RIGHT_SC_OPT_Z_REL_TE_CTL,
		ID_RIGHT_SC_OPT_Z_DEC_BTN,
		ID_RIGHT_SC_OPT_Z_INC_BTN,
		ID_RIGHT_SC_OPT_Z_CENTER_BTN,
		ID_RIGHT_SC_OPT_Z_HOME_BTN,
		/* Camera */
		ID_RIGHT_CAM_EXPOSURE_TE_CTL,
		ID_RIGHT_CAM_PREVIEW_BTN,
		/* Measurement */
		ID_RIGHT_MT_OUT_FLD_TE_CTL,
		ID_RIGHT_MT_OUT_FLD_BTN,
		ID_RIGHT_MT_FIRST_STAGE_CHOICE,
		ID_RIGHT_MT_FIRST_STAGE_START,
		ID_RIGHT_MT_FIRST_STAGE_STEP,
		ID_RIGHT_MT_FIRST_STAGE_FINISH,
		ID_RIGHT_MT_SECOND_STAGE_CHOICE,
		ID_RIGHT_MT_SECOND_STAGE_START,
		ID_RIGHT_MT_SECOND_STAGE_STEP,
		ID_RIGHT_MT_SECOND_STAGE_FINISH,
		ID_RIGHT_MT_START_MEASUREMENT
	};
	struct MenuBar
	{
		wxMenuBar* menu_bar{};
		wxMenu* menu_file{};
		wxMenu* menu_edit{};
		wxMenu* menu_window{};
		wxMenu* menu_help{};
		MenuBar() :
			menu_bar(new wxMenuBar()),
			menu_file(new wxMenu()),
			menu_edit(new wxMenu()),
			menu_window(new wxMenu()),
			menu_help(new wxMenu()) {};
	};
	struct StepperControl
	{
		wxTextCtrl* absolute_text_ctrl{}, *relative_text_ctrl{};
		wxButton* set_btn{}, * increment_btn{}, * decrement_btn{};
		wxBitmapButton* center_btn{}, * home_btn{};
		void DisableAllControls()
		{
			absolute_text_ctrl->Disable();
			relative_text_ctrl->Disable();
			set_btn->Disable();
			increment_btn->Disable();
			decrement_btn->Disable();
			center_btn->Disable();
			home_btn->Disable();
		}
		void EnableAllControls()
		{
			absolute_text_ctrl->Enable();
			relative_text_ctrl->Enable();
			set_btn->Enable();
			increment_btn->Enable();
			decrement_btn->Enable();
			center_btn->Enable();
			home_btn->Enable();
		}
	};
	struct MeasurementStage
	{
		wxChoice* stage{};
		wxTextCtrl* start{}, * step{}, * finish{};
		wxArrayString motors;

		MeasurementStage()
		{
			motors.Add("Detector X");
			motors.Add("Detector Y");
			motors.Add("Detector Z");
			motors.Add("Optics X");
			motors.Add("Optics Y");
			motors.Add("Optics Z");
		};

		void DisableAllControls()
		{
			stage->Disable();
			start->Disable();
			step->Disable();
			finish->Disable();
		}
	};
}

class cMain final : public wxFrame
{
public:
	cMain(const wxString& title_);

	~cMain();

private:
	void CreateMainFrame();
	void InitComponents();
	void InitDefaultStateWidgets();
	void CreateMenuBarOnFrame();
	void CreateLeftAndRightSide();
	void CreateLeftSide(wxSizer* left_side_sizer);
	void CreateRightSide(wxSizer* right_side_sizer);
	void CreateSteppersControl(wxPanel* right_side_panel, wxBoxSizer* right_side_panel_sizer);
	void CreateCameraControls(wxPanel* right_side_panel, wxBoxSizer* right_side_panel_sizer);
	void CreateMeasurement(wxPanel* right_side_panel, wxBoxSizer* right_side_panel_sizer);

	void OnPreviewCameraImage(wxCommandEvent& evt);
	void OnSetOutDirectoryBtn(wxCommandEvent& evt);

	void OnOpenSettings(wxCommandEvent& evt);
	void UpdateStagePositions();

	void OnFullScreen(wxCommandEvent& evt);
	void OnMaximizeButton(wxMaximizeEvent& evt);

	void OnExit(wxCloseEvent& evt);
	void OnExit(wxCommandEvent& evt);

	/* Stepper Control Functions */
	/* Detector X */
	void OnCenterDetectorX(wxCommandEvent& evt);
	void OnHomeDetectorX(wxCommandEvent& evt);
	/* Detector Y */
	void OnCenterDetectorY(wxCommandEvent& evt);
	void OnHomeDetectorY(wxCommandEvent& evt);
	/* Detector Z */
	void OnCenterDetectorZ(wxCommandEvent& evt);
	void OnHomeDetectorZ(wxCommandEvent& evt);
	/* Optics Y */
	void OnCenterOpticsY(wxCommandEvent& evt);
	void OnHomeOpticsY(wxCommandEvent& evt);

private:
	/* Settings Menu */
	cSettings* m_Settings{};
	/* Menu Bar */
	MainFrameVariables::MenuBar* m_MenuBar{};
	/* Preview Panel */
	std::unique_ptr<cCamPreview> m_CamPreview{};
	/* Steppers Control */
	std::unique_ptr<MainFrameVariables::StepperControl> m_X_Detector{}, m_Y_Detector{}, m_Z_Detector{};
	std::unique_ptr<MainFrameVariables::StepperControl> m_X_Optics{}, m_Y_Optics{}, m_Z_Optics{};

	/* Camera */
	std::unique_ptr<wxTextCtrl> m_CamExposure{};
	std::unique_ptr<wxButton> m_CamPreviewBtn{};

	/* Measurement */
	std::unique_ptr<wxTextCtrl> m_OutDirTextCtrl{};
	std::unique_ptr<wxButton> m_OutDirBtn{};
	std::unique_ptr<MainFrameVariables::MeasurementStage> m_FirstStage{}, m_SecondStage{};
	std::unique_ptr<wxButton> m_StartMeasurement{};

	wxDECLARE_EVENT_TABLE();
};

#endif // !CMAIN_H

