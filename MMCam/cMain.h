#pragma once
#ifndef CMAIN_H
#define CMAIN_H

#include "wx/wx.h"
#include "wx/tglbtn.h"
#include "wx/valnum.h"
#include "wx/thread.h"
#include "wx/appprogress.h"

#include <string>
#include <memory>
#include <chrono>

#include "cCamPreview.h"
#include "cSettings.h"

#include "src/img/center.xpm"
#include "src/img/home.xpm"

#include "src/img/logo.xpm"

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
		ID_RIGHT_CAM_CAPTURE_BTN,
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
		ID_RIGHT_MT_START_MEASUREMENT,
		/* Progress */
		ID_PROGRESS_CAPTURING,
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
			motors.Add("None");
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
		void EnableAllControls()
		{
			stage->Enable();
			start->Enable();
			step->Enable();
			finish->Enable();
		}
	};
	/* Struct to transfer axis data to WorkerThread */
	struct AxisMeasurement
	{
		int axis_number{ -1 };
		float start{}, step{}, finish{};
		int step_number{};
	};
}

class ProgressBar;
class ProgressPanel;
class WorkerThread;
class ProgressThread;

/* ___Start cMain___ */
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

	/* ProgressBar */
	void CreateProgressBar();

	void OnPreviewCameraImage(wxCommandEvent& evt);
	void OnSetOutDirectoryBtn(wxCommandEvent& evt);

	void OnOpenSettings(wxCommandEvent& evt);
	void UpdateStagePositions();
	void EnableUsedAndDisableNonUsedMotors();

	void OnFullScreen(wxCommandEvent& evt);
	void OnMaximizeButton(wxMaximizeEvent& evt);

	void OnExit(wxCloseEvent& evt);
	void OnExit(wxCommandEvent& evt);

	/* Stepper Control Functions */
	/* Detector X */
	void OnEnterTextCtrlDetectorXAbsPos(wxCommandEvent& evt);
	void OnSetDetectorXAbsPos(wxCommandEvent& evt);
	void OnDecrementDetectorXAbsPos(wxCommandEvent& evt);
	void OnIncrementDetectorXAbsPos(wxCommandEvent& evt);
	void OnCenterDetectorX(wxCommandEvent& evt);
	void OnHomeDetectorX(wxCommandEvent& evt);
	/* Detector Y */
	void OnEnterTextCtrlDetectorYAbsPos(wxCommandEvent& evt);
	void OnSetDetectorYAbsPos(wxCommandEvent& evt);
	void OnDecrementDetectorYAbsPos(wxCommandEvent& evt);
	void OnIncrementDetectorYAbsPos(wxCommandEvent& evt);
	void OnCenterDetectorY(wxCommandEvent& evt);
	void OnHomeDetectorY(wxCommandEvent& evt);
	/* Detector Z */
	void OnEnterTextCtrlDetectorZAbsPos(wxCommandEvent& evt);
	void OnSetDetectorZAbsPos(wxCommandEvent& evt);
	void OnDecrementDetectorZAbsPos(wxCommandEvent& evt);
	void OnIncrementDetectorZAbsPos(wxCommandEvent& evt);
	void OnCenterDetectorZ(wxCommandEvent& evt);
	void OnHomeDetectorZ(wxCommandEvent& evt);
	/* Optics Y */
	void OnEnterTextCtrlOpticsYAbsPos(wxCommandEvent& evt);
	void OnSetOpticsYAbsPos(wxCommandEvent& evt);
	void OnDecrementOpticsYAbsPos(wxCommandEvent& evt);
	void OnIncrementOpticsYAbsPos(wxCommandEvent& evt);
	void OnCenterOpticsY(wxCommandEvent& evt);
	void OnHomeOpticsY(wxCommandEvent& evt);

	/* First Stage */
	void OnFirstStageChoice(wxCommandEvent& evt);
	/* Second Stage */
	void OnSecondStageChoice(wxCommandEvent& evt);
	/* Start Capturing */
	void OnStartCapturingButton(wxCommandEvent& evt);
	/* Progress */
	void UpdateProgress(wxThreadEvent& evt);
	bool Cancelled();

	void UpdateAllAxisGlobalPositions();

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

	/* Progress */
	bool m_Cancelled{}, m_DataCalculatedInThisApp{};
	wxCriticalSection m_CSCancelled{};
	std::unique_ptr<ProgressBar> m_ProgressBar{};
	std::chrono::steady_clock::time_point m_StartCalculationTime;
	std::unique_ptr<wxAppProgressIndicator> m_AppProgressIndicator{};

	int m_Progress{};
	wxString m_ProgressMsg{};

	wxDECLARE_EVENT_TABLE();
};
/* ___End cMain___ */

/* ___Start Worker Theread___ */
class WorkerThread final: public wxThreadHelper
{
public:
	WorkerThread
	(
		cSettings* settings, 
		cCamPreview* camera_preview_panel,
		const wxString& path, 
		const unsigned long& exp_time_us,
		MainFrameVariables::AxisMeasurement* first_axis, 
		MainFrameVariables::AxisMeasurement* second_axis
	);
	~WorkerThread();

	virtual void* Entry();

private:
	cSettings* m_Settings{};
	cCamPreview* m_CameraPreview{};
	wxString m_ImagePath{};
	unsigned long m_ExposureTimeUS{};
	MainFrameVariables::AxisMeasurement* m_FirstAxis{}, * m_SecondAxis{};
};
/* ___End Worker Thread___ */

/* ___Start Progress Thread___ */
class ProgressThread final : public wxThreadHelper
{
public:
	ProgressThread(cSettings* settings, cMain* main_frame);
	virtual void* Entry();
	~ProgressThread();

private:
	cSettings* m_Settings{};
	cMain* m_Frame{};
	int m_Progress{};
	wxString m_ProgressMsg{};
};
/* ___End  Progress Thread___ */

/* ___Start ProgressBar___ */
class ProgressBar final : public wxFrame
{
public:
	ProgressBar(wxWindow* parent, const wxPoint& pos, const wxSize& size);
	void UpdateProgressWithMessage(const wxString& msg, const int& progress);
	void UpdateElapsedTime(const uint64_t& elapsed_seconds);
	void UpdateEstimatedTime(const int& prgs, const uint64_t& estimated_seconds);
	~ProgressBar();
private:
	void CreateProgressBar();

private:
	ProgressPanel* m_ProgressPanel{};
	wxSize m_MainSize{};

	DECLARE_EVENT_TABLE()
};
/* ___End ProgressBar___ */

/* ___Start ProgressPanel___ */
class ProgressPanel final : public wxPanel
{
public:
	ProgressPanel(wxFrame* parent, const wxSize& size);
	void SetSize(const wxSize& new_size);
	void SetProgress(const int& progress);
	void SetElapsedTime(const int& elapsed_time);
	void SetEstimatedTime(const int& progress, const int& estimated_time);
	void SetComment(const wxString& progress_comment);

private:
	void PaintEvent(wxPaintEvent& evt);
	void Render(wxBufferedPaintDC& dc);
	void OnSize(wxSizeEvent& evt);

private:
	int m_Width{}, m_Height{};
	int m_Progress{}, m_PreviousEstimateProgress{};
	int m_ElapsedTime{}, m_EstimatedTime{}; // Time in seconds
	int m_ElapsedHours{}, m_ElapsedMinutes{}, m_ElapsedSeconds{};
	wxString m_ProgressComment{ "Moving to start position" };

	DECLARE_EVENT_TABLE()
};
/* ___End ProgressPanel___ */

#endif // !CMAIN_H
