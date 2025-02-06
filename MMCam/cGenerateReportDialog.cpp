#include "cGenerateReportDialog.h"

wxIMPLEMENT_CLASS(cGenerateReportDialog, wxPropertySheetDialog);
wxBEGIN_EVENT_TABLE(cGenerateReportDialog, wxPropertySheetDialog)
    EVT_CHOICE(GenerateReportVariables::ID_IMG_DATA_TYPE, cGenerateReportDialog::OnDataTypeChoice)
    //EVT_BUTTON(SetFFCImgVariables::ID_OPEN_BLACK_BTN, cSetFFCImgDialog::OnOpenBlackImageBtn)
    //EVT_BUTTON(SetFFCImgVariables::ID_OPEN_WHITE_BTN, cSetFFCImgDialog::OnOpenWhiteImageBtn)
wxEND_EVENT_TABLE()

cGenerateReportDialog::cGenerateReportDialog
(
    wxWindow* parent, 
	GenerateReportVariables::InputParameters inputParameters
)
{
    m_InputParameters = std::make_unique<GenerateReportVariables::InputParameters>(inputParameters);
    //SetExtraStyle(wxDIALOG_EX_CONTEXTHELP);

    //int resizeBorder = wxRESIZE_BORDER;
    int resizeBorder = 0;

    Create(parent, wxID_ANY, "Load Data", wxDefaultPosition, wxDefaultSize,
        wxDEFAULT_DIALOG_STYLE | resizeBorder);

	CreateButtons(wxOK | wxCANCEL);
    Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnExitButtonClicked, this);

    auto notebook = GetBookCtrl();
    notebook->SetImageList(m_imageList);

    auto reportVariables = CreateReportVariablesPage(notebook);
    auto flatFieldPage = CreateFlatFieldPage(notebook);
    auto inputImagesPage = CreateInputImagesPage(notebook);

    notebook->AddPage
    (
        reportVariables, 
        "Report Variables", 
#ifdef _DEBUG
        false,
#else
        true, 
#endif // _DEBUG
        0
    );
    
    notebook->AddPage
    (
        flatFieldPage, 
        "Flat Field Correction", 
        false, 
        0
    );
    
    notebook->AddPage
    (
        inputImagesPage, 
        "Input Images", 
#ifdef _DEBUG
        true,
#else
        false, 
#endif // _DEBUG
        0
    );

    LayoutDialog();

}

wxPanel* cGenerateReportDialog::CreateReportVariablesPage(wxWindow* parent)
{
    wxPanel* panel = new wxPanel(parent, wxID_ANY);
    wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticBox* reportParametersStaticBox = new wxStaticBox(panel, wxID_ANY, "Report Parameters");


    {
        wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(reportParametersStaticBox, wxVERTICAL);

        wxSizer* const settings_grid_sizer = new wxGridSizer(2);

        // Report Name
        {
            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Report Name:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            m_ReportNameTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_REPORT_NAME_TXT_CTRL,
                    wxString("TEST REPORT"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            settings_grid_sizer->Add(m_ReportNameTxtCtrl.get(), wxSizerFlags(1).Expand().Align(wxALIGN_CENTER_VERTICAL));
        }

        // Optics Scheme
        {
            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Optics Scheme:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            wxArrayString pngFiles;
            GetPngFiles(m_ReportGeneratorPath, pngFiles);

            m_OpticsSchemeChoice = std::make_unique<wxChoice>
                (
                    panel,
                    GenerateReportVariables::ID_OPTICS_CHEME_CHOICE,
                    wxDefaultPosition,
                    wxDefaultSize,
                    pngFiles
                );

            if (!pngFiles.IsEmpty())
				m_OpticsSchemeChoice->SetSelection(0);

            settings_grid_sizer->Add(m_OpticsSchemeChoice.get(), wxSizerFlags(1).Expand().Align(wxALIGN_CENTER_VERTICAL));
        }


        // Author
        {
            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Author:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            m_AuthorTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_REPORT_AUTHOR_TXT_CTRL,
#ifdef _DEBUG
                    wxString("Andrej"),
#else
                    wxString("Veronika Marsikova"),
#endif // _DEBUG
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            settings_grid_sizer->Add(m_AuthorTxtCtrl.get(), wxSizerFlags(1).Expand().Align(wxALIGN_CENTER_VERTICAL));
        }

        // Customer
        {
            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Customer:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            m_CustomerTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_CUSTOMER_TXT_CTRL,
                    wxString("BRU"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            settings_grid_sizer->Add(m_CustomerTxtCtrl.get(), wxSizerFlags(1).Expand().Align(wxALIGN_CENTER_VERTICAL));
        }

        // Optics Serial Number
        {
            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Serial Number:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            m_OpticsSerialNumberTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_OPTICS_SERIAL_NUMBER_TXT_CTRL,
                    wxString("037"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            settings_grid_sizer->Add(m_OpticsSerialNumberTxtCtrl.get(), wxSizerFlags(1).Expand().Align(wxALIGN_CENTER_VERTICAL));
        }

        // Optics Product Number
        {
            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Product Number:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            m_OpticsProductNumberTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_OPTICS_PRODUCT_NUMBER_TXT_CTRL,
                    wxString("037-066"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            settings_grid_sizer->Add(m_OpticsProductNumberTxtCtrl.get(), wxSizerFlags(1).Expand().Align(wxALIGN_CENTER_VERTICAL));
        }

        // Optics Type
        {
            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Optics Type:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            m_OpticsTypeTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_OPTICS_TYPE_TXT_CTRL,
                    wxString("C0-06-19"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            settings_grid_sizer->Add(m_OpticsTypeTxtCtrl.get(), wxSizerFlags(1).Expand().Align(wxALIGN_CENTER_VERTICAL));
        }

        // Start Position
        {
            wxBoxSizer* horSizer = new wxBoxSizer(wxHORIZONTAL);

            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Start Position:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            wxFloatingPointValidator<double> val(2, NULL, wxNUM_VAL_ZERO_AS_BLANK);
            //val.SetMin(1);
            m_StartPositionTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_START_POSITION_TXT_CTRL,
                    wxString("22.50"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            m_StartPositionTxtCtrl->SetValidator(val);

            horSizer->Add(m_StartPositionTxtCtrl.get(), 0, wxALIGN_CENTER_VERTICAL);
            horSizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "[mm]"
                ),
                0, wxLEFT | wxALIGN_CENTER_VERTICAL, 5
            );
            settings_grid_sizer->Add(horSizer, 0, wxEXPAND);
        }

        // Step
        {
            wxBoxSizer* horSizer = new wxBoxSizer(wxHORIZONTAL);

            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Step:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            wxFloatingPointValidator<double> val(3, NULL, wxNUM_VAL_ZERO_AS_BLANK);
            m_StepTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_START_POSITION_TXT_CTRL,
                    wxString("0.025"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            m_StepTxtCtrl->SetValidator(val);

            horSizer->Add(m_StepTxtCtrl.get(), 0, wxALIGN_CENTER_VERTICAL);
            horSizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "[mm]"
                ),
                0, wxLEFT | wxALIGN_CENTER_VERTICAL, 5
            );
            settings_grid_sizer->Add(horSizer, 0, wxEXPAND);
        }

        // Focus Exposure
        {
            wxBoxSizer* horSizer = new wxBoxSizer(wxHORIZONTAL);

            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Focus Exposure:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            wxIntegerValidator<unsigned int> val(NULL);
            val.SetMin(1);
            m_FocusExposureTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_FOCUS_EXPOSURE_TXT_CTRL,
                    wxString("8"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            m_FocusExposureTxtCtrl->SetValidator(val);

            horSizer->Add(m_FocusExposureTxtCtrl.get(), 0, wxALIGN_CENTER_VERTICAL);
            horSizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "[ms]"
                ),
                0, wxLEFT | wxALIGN_CENTER_VERTICAL, 5
            );
            settings_grid_sizer->Add(horSizer, 0, wxEXPAND);
        }

        // Circle Exposure
        {
            wxBoxSizer* horSizer = new wxBoxSizer(wxHORIZONTAL);

            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Circle Exposure:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            wxIntegerValidator<unsigned int> val(NULL);
            val.SetMin(1);
            m_CircleExposureTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_CIRCLE_EXPOSURE_TXT_CTRL,
                    wxString("150"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            m_CircleExposureTxtCtrl->SetValidator(val);

            horSizer->Add(m_CircleExposureTxtCtrl.get(), 0, wxALIGN_CENTER_VERTICAL);
            horSizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "[ms]"
                ),
                0, wxLEFT | wxALIGN_CENTER_VERTICAL, 5
            );
            settings_grid_sizer->Add(horSizer, 0, wxEXPAND);
        }


    //  m_FocusTimeTxtCtrl{}, m_CircleTimeTxtCtrl{};
        staticBoxSizer->Add(settings_grid_sizer, 0, wxEXPAND | wxALL, 5);
		topSizer->Add(staticBoxSizer, wxSizerFlags(1).Expand().Border(wxALL, 5));
    }


    panel->SetSizerAndFit(topSizer);
    return panel;
}

wxPanel* cGenerateReportDialog::CreateFlatFieldPage(wxWindow* parent)
{
    wxPanel* panel = new wxPanel(parent, wxID_ANY);
    wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);

    wxStaticBox* imageParametersStaticBox = new wxStaticBox(panel, wxID_ANY, "Image Parameters");
    {
        wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(imageParametersStaticBox, wxVERTICAL);

        wxSizer* const settings_grid_sizer = new wxGridSizer(2);
        // Data Type
        {
            wxArrayString dataTypeChoices;
            {
                dataTypeChoices.Add("8-bit");
                dataTypeChoices.Add("16-bit Signed");
                dataTypeChoices.Add("16-bit Unsigned");
            }

            m_ImgDataTypeChoice = std::make_unique<wxChoice>
                (
                    panel,
                    GenerateReportVariables::ID_IMG_DATA_TYPE,
                    wxDefaultPosition,
                    wxDefaultSize,
                    dataTypeChoices
                );
            m_ImgDataTypeChoice->SetSelection(2);
            m_ImgDataTypeChoice->Disable();

            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Data type:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            settings_grid_sizer->Add(m_ImgDataTypeChoice.get(), wxSizerFlags(1).Expand().Align(wxALIGN_CENTER_VERTICAL));
        }
        // Image Width
        {
            wxBoxSizer* imageWidthSizer = new wxBoxSizer(wxHORIZONTAL);


            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Width:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            wxIntegerValidator<unsigned int> val(NULL, wxNUM_VAL_THOUSANDS_SEPARATOR);
            val.SetMin(1);
            m_ImgWidthTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_IMG_WIDTH,
                    wxString("0"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            m_ImgWidthTxtCtrl->SetToolTip("Only non-zero positive values are accepted");
            m_ImgWidthTxtCtrl->SetValidator(val);
            m_ImgWidthTxtCtrl->Disable();

#ifdef _DEBUG
            //m_ImgWidthTxtCtrl->ChangeValue(wxString::Format(wxT("%i"), 2592));
#endif // _DEBUG

            imageWidthSizer->Add(m_ImgWidthTxtCtrl.get(), 0, wxALIGN_CENTER_VERTICAL);
            imageWidthSizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "[px]"
                ),
                0, wxLEFT | wxALIGN_CENTER_VERTICAL, 5
            );
            settings_grid_sizer->Add(imageWidthSizer, 0, wxEXPAND);
        }
        // Image Height
        {
            wxBoxSizer* imageHeightSizer = new wxBoxSizer(wxHORIZONTAL);

            settings_grid_sizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "&Height:"
                ),
                0, wxALL | wxALIGN_CENTER_VERTICAL, 5
            );

            wxIntegerValidator<unsigned int> val(NULL, wxNUM_VAL_THOUSANDS_SEPARATOR);
            val.SetMin(1);
            m_ImgHeightTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_IMG_HEIGHT,
                    wxString("0"),
                    wxDefaultPosition,
                    wxDefaultSize,
                    wxTE_CENTRE
                );
            m_ImgHeightTxtCtrl->SetToolTip("Only non-zero positive values are accepted");
            m_ImgHeightTxtCtrl->SetValidator(val);
            m_ImgHeightTxtCtrl->Disable();

#ifdef _DEBUG
            //m_ImgHeightTxtCtrl->ChangeValue(wxString::Format(wxT("%i"), 1944));
#endif // _DEBUG

            imageHeightSizer->Add(m_ImgHeightTxtCtrl.get(), 0, wxALIGN_CENTER_VERTICAL);

            imageHeightSizer->Add
            (
                new wxStaticText
                (
                    panel,
                    wxID_ANY,
                    "[px]"
                ),
                0, wxLEFT | wxALIGN_CENTER_VERTICAL, 5
            );
            settings_grid_sizer->Add(imageHeightSizer, 0, wxEXPAND);
        }
        staticBoxSizer->Add(settings_grid_sizer, 0, wxCENTER | wxALL, 5);
		//topSizer->Add(staticBoxSizer, wxSizerFlags(1).Expand().Border(wxALL, 5));
		topSizer->Add(staticBoxSizer, 0, wxEXPAND | wxALL, 5);
    }


	// Original Black Image
    wxStaticBox* blackStaticBox = new wxStaticBox(panel, wxID_ANY, "Original Black Image");
    {
        blackStaticBox->SetBackgroundColour(wxColor(90, 90, 90));

        wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(blackStaticBox, wxVERTICAL);
        {
            wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

            m_OriginalBlackImgPathTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_ORIGINAL_BLACK_PATH_TXT_CTRL,
                    wxT("Black Image Path..."),
                    wxDefaultPosition, wxDefaultSize,
					wxTE_LEFT | wxTE_READONLY
                );

            horizontalSizer->Add(m_OriginalBlackImgPathTxtCtrl.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

			auto bmp = wxMaterialDesignArtProvider::GetBitmap
			(
				wxART_TOGGLE_OFF, 
				wxART_CLIENT_AWESOME_SOLID, 
				wxSize(16, 16), 
				wxColour(255, 0, 0)
			);

            m_OpenOriginalBlackImgBtn = std::make_unique<wxBitmapButton>
                (
                    panel,
                    GenerateReportVariables::ID_OPEN_ORIGINAL_BLACK_BTN,
                    bmp
                );
			m_OpenOriginalBlackImgBtn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenOriginalBlackImageBtn, this);

            horizontalSizer->Add(m_OpenOriginalBlackImgBtn.get(), 0, wxRIGHT, 2);

            staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);
        }
		topSizer->Add(staticBoxSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);
    }

	// Original White Image
    wxStaticBox* whiteStaticBox = new wxStaticBox(panel, wxID_ANY, "Original White Image");
    {
        whiteStaticBox->SetBackgroundColour(wxColor(255, 255, 255));
        wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(whiteStaticBox, wxVERTICAL);
        {
            wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

            m_OriginalWhiteImgPathTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_ORIGINAL_WHITE_PATH_TXT_CTRL,
                    wxT("White Image Path..."),
                    wxDefaultPosition, wxDefaultSize,
					wxTE_LEFT | wxTE_READONLY
                );

            horizontalSizer->Add(m_OriginalWhiteImgPathTxtCtrl.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

			auto bmp = wxMaterialDesignArtProvider::GetBitmap
			(
				wxART_TOGGLE_OFF, 
				wxART_CLIENT_AWESOME_SOLID, 
				wxSize(16, 16), 
				wxColour(255, 0, 0)
			);

            m_OpenOriginalWhiteImgBtn = std::make_unique<wxBitmapButton>
                (
                    panel,
                    GenerateReportVariables::ID_OPEN_ORIGINAL_WHITE_BTN,
                    bmp
                );

			m_OpenOriginalWhiteImgBtn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenOriginalWhiteImageBtn, this);

            horizontalSizer->Add(m_OpenOriginalWhiteImgBtn.get(), 0, wxRIGHT, 2);
            staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);
        }
		topSizer->Add(staticBoxSizer,0, wxEXPAND | wxLEFT | wxRIGHT, 5);
    }

    topSizer->AddStretchSpacer();

	// Circle Black Image
    wxStaticBox* circleBlackStaticBox = new wxStaticBox(panel, wxID_ANY, "Circle Black Image");
    {
        circleBlackStaticBox->SetBackgroundColour(wxColor(90, 90, 90));

        wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(circleBlackStaticBox, wxVERTICAL);
        {
            wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

            m_CircleBlackImgPathTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_CIRCLE_BLACK_PATH_TXT_CTRL,
                    wxT("Black Image Path..."),
                    wxDefaultPosition, wxDefaultSize,
					wxTE_LEFT | wxTE_READONLY
                );

            horizontalSizer->Add(m_CircleBlackImgPathTxtCtrl.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

			auto bmp = wxMaterialDesignArtProvider::GetBitmap
			(
				wxART_TOGGLE_OFF, 
				wxART_CLIENT_AWESOME_SOLID, 
				wxSize(16, 16), 
				wxColour(255, 0, 0)
			);

            m_OpenCircleBlackImgBtn = std::make_unique<wxBitmapButton>
                (
                    panel,
                    GenerateReportVariables::ID_OPEN_CIRCLE_BLACK_BTN,
                    bmp
                );
			m_OpenCircleBlackImgBtn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenCircleBlackImageBtn, this);

            horizontalSizer->Add(m_OpenCircleBlackImgBtn.get(), 0, wxRIGHT, 2);

            staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);
        }
		topSizer->Add(staticBoxSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);
    }



    panel->SetSizerAndFit(topSizer);
    return panel;
}

wxPanel* cGenerateReportDialog::CreateInputImagesPage(wxWindow* parent)
{
    wxPanel* panel = new wxPanel(parent, wxID_ANY);
    wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);

	topSizer->AddSpacer(5);
	// Images for Calculation
    wxStaticBox* calculatedImagesStaticBox = new wxStaticBox(panel, wxID_ANY, "Images for Calculation");
    {
        calculatedImagesStaticBox->SetBackgroundColour(wxColor(34, 177, 76));
        wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(calculatedImagesStaticBox, wxVERTICAL);
        {
            wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

            m_ImagesForCalculationPaths = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_IMAGES_FOR_CALCULATION_PATHS_TXT_CTRL,
                    wxT("Images Paths..."),
                    wxDefaultPosition, wxDefaultSize,
					wxTE_LEFT | wxTE_READONLY
                );

            horizontalSizer->Add(m_ImagesForCalculationPaths.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

			auto bmp = wxMaterialDesignArtProvider::GetBitmap
			(
				wxART_TOGGLE_OFF, 
				wxART_CLIENT_AWESOME_SOLID, 
				wxSize(16, 16), 
				wxColour(255, 0, 0)
			);

            m_OpenImagesForCalculationBtn = std::make_unique<wxBitmapButton>
                (
                    panel,
                    GenerateReportVariables::ID_OPEN_IMAGES_FOR_CALCULATION_BTN,
                    bmp
                );

			m_OpenImagesForCalculationBtn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenImagesForCalculationBtn, this);

            horizontalSizer->Add(m_OpenImagesForCalculationBtn.get(), 0, wxRIGHT, 2);
            staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);
        }
		topSizer->Add(staticBoxSizer,0, wxEXPAND | wxLEFT | wxRIGHT, 5);
    }

	topSizer->AddSpacer(5);

	// Circle Images for Calculation
    wxStaticBox* circleImagesStaticBox = new wxStaticBox(panel, wxID_ANY, "Circle Images for Calculation");
    {
        circleImagesStaticBox->SetBackgroundColour(wxColor(0, 162, 232));
        wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(circleImagesStaticBox, wxVERTICAL);
        {
            wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

            m_CircleImagesForCalculationPaths = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_CIRCLE_IMAGES_FOR_CALCULATION_PATHS_TXT_CTRL,
                    wxT("Circle Images Paths..."),
                    wxDefaultPosition, wxDefaultSize,
					wxTE_LEFT | wxTE_READONLY
                );

            horizontalSizer->Add(m_CircleImagesForCalculationPaths.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

			auto bmp = wxMaterialDesignArtProvider::GetBitmap
			(
				wxART_TOGGLE_OFF, 
				wxART_CLIENT_AWESOME_SOLID, 
				wxSize(16, 16), 
				wxColour(255, 0, 0)
			);

            m_OpenCircleImagesForCalculationBtn = std::make_unique<wxBitmapButton>
                (
                    panel,
                    GenerateReportVariables::ID_OPEN_CIRCLE_IMAGES_FOR_CALCULATION_BTN,
                    bmp
                );

			m_OpenCircleImagesForCalculationBtn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenCircleImagesForCalculationBtn, this);

            horizontalSizer->Add(m_OpenCircleImagesForCalculationBtn.get(), 0, wxRIGHT, 2);
            staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);
        }
		topSizer->Add(staticBoxSizer,0, wxEXPAND | wxLEFT | wxRIGHT, 5);
    }

	topSizer->AddStretchSpacer();

    // X-Ray Test
    auto xRayTestStaticBox = new wxStaticBoxSizer(wxVERTICAL, panel, "X-Ray Test (Optional)");
    {
        // Image 1
        {
			auto staticBox = new wxStaticBox(panel, wxID_ANY, "Image 1");
            {
                staticBox->SetBackgroundColour(wxColor(255, 201, 14));
                wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(staticBox, wxVERTICAL);
                {
                    wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

                    m_XRayImage1Path = std::make_unique<wxTextCtrl>
                        (
                            panel,
                            GenerateReportVariables::ID_XRAY_IMAGE_1_PATH_TXT_CTRL,
                            wxT("X-Ray 1 Image Path..."),
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_LEFT | wxTE_READONLY
                        );

                    horizontalSizer->Add(m_XRayImage1Path.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

                    auto bmp = wxMaterialDesignArtProvider::GetBitmap
                    (
                        wxART_TOGGLE_OFF,
                        wxART_CLIENT_AWESOME_SOLID,
                        wxSize(16, 16),
                        wxColour(255, 0, 0)
                    );

                    m_OpenXRayImage1Btn = std::make_unique<wxBitmapButton>
                        (
                            panel,
                            GenerateReportVariables::ID_OPEN_XRAY_IMAGE_1_BTN,
                            bmp
                        );

                    m_OpenXRayImage1Btn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenXRayImage1Btn, this);

                    horizontalSizer->Add(m_OpenXRayImage1Btn.get(), 0, wxRIGHT, 2);

                    staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);

                    m_XRayImage1Caption = std::make_unique<wxTextCtrl>
                        (
                            panel,
                            GenerateReportVariables::ID_XRAY_IMAGE_1_CAPTION_TXT_CTRL,
                            m_InputParameters->xRayImagesDefaultCaption[0],
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_LEFT
                        );
                    m_XRayImage1Caption->Disable();
                    staticBoxSizer->AddSpacer(2);
                    staticBoxSizer->Add(m_XRayImage1Caption.get(), 0, wxEXPAND);

                }
                xRayTestStaticBox->Add(staticBoxSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);
            }
        }

        xRayTestStaticBox->AddSpacer(5);

        // Image 2
        {
            auto staticBox = new wxStaticBox(panel, wxID_ANY, "Image 2");
            {
                staticBox->SetBackgroundColour(wxColor(255, 201, 14));
                wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(staticBox, wxVERTICAL);
                {
                    wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

                    m_XRayImage2Path = std::make_unique<wxTextCtrl>
                        (
                            panel,
                            GenerateReportVariables::ID_XRAY_IMAGE_2_PATH_TXT_CTRL,
                            wxT("X-Ray 2 Image Path..."),
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_LEFT | wxTE_READONLY
                        );

                    horizontalSizer->Add(m_XRayImage2Path.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

                    auto bmp = wxMaterialDesignArtProvider::GetBitmap
                    (
                        wxART_TOGGLE_OFF,
                        wxART_CLIENT_AWESOME_SOLID,
                        wxSize(16, 16),
                        wxColour(255, 0, 0)
                    );

                    m_OpenXRayImage2Btn = std::make_unique<wxBitmapButton>
                        (
                            panel,
                            GenerateReportVariables::ID_OPEN_XRAY_IMAGE_2_BTN,
                            bmp
                        );

                    m_OpenXRayImage2Btn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenXRayImage2Btn, this);

                    horizontalSizer->Add(m_OpenXRayImage2Btn.get(), 0, wxRIGHT, 2);
                    staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);

                    m_XRayImage2Caption = std::make_unique<wxTextCtrl>
                        (
                            panel,
                            GenerateReportVariables::ID_XRAY_IMAGE_2_CAPTION_TXT_CTRL,
                            m_InputParameters->xRayImagesDefaultCaption[1],
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_LEFT
                        );
                    m_XRayImage2Caption->Disable();
                    staticBoxSizer->AddSpacer(2);
                    staticBoxSizer->Add(m_XRayImage2Caption.get(), 0, wxEXPAND);
                }
                xRayTestStaticBox->Add(staticBoxSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);
            }
        }

        xRayTestStaticBox->AddSpacer(5);

        // Image 3
        {
            auto staticBox = new wxStaticBox(panel, wxID_ANY, "Image 3");
            {
                staticBox->SetBackgroundColour(wxColor(255, 201, 14));
                wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(staticBox, wxVERTICAL);
                {
                    wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

                    m_XRayImage3Path = std::make_unique<wxTextCtrl>
                        (
                            panel,
                            GenerateReportVariables::ID_XRAY_IMAGE_3_PATH_TXT_CTRL,
                            wxT("X-Ray 3 Image Path..."),
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_LEFT | wxTE_READONLY
                        );

                    horizontalSizer->Add(m_XRayImage3Path.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

                    auto bmp = wxMaterialDesignArtProvider::GetBitmap
                    (
                        wxART_TOGGLE_OFF,
                        wxART_CLIENT_AWESOME_SOLID,
                        wxSize(16, 16),
                        wxColour(255, 0, 0)
                    );

                    m_OpenXRayImage3Btn = std::make_unique<wxBitmapButton>
                        (
                            panel,
                            GenerateReportVariables::ID_OPEN_XRAY_IMAGE_3_BTN,
                            bmp
                        );

                    m_OpenXRayImage3Btn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenXRayImage3Btn, this);

                    horizontalSizer->Add(m_OpenXRayImage3Btn.get(), 0, wxRIGHT, 2);
                    staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);

                    m_XRayImage3Caption = std::make_unique<wxTextCtrl>
                        (
                            panel,
                            GenerateReportVariables::ID_XRAY_IMAGE_3_CAPTION_TXT_CTRL,
                            m_InputParameters->xRayImagesDefaultCaption[2],
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_LEFT
                        );
                    m_XRayImage3Caption->Disable();
                    staticBoxSizer->AddSpacer(2);
                    staticBoxSizer->Add(m_XRayImage3Caption.get(), 0, wxEXPAND);
                }
                xRayTestStaticBox->Add(staticBoxSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);
            }
        }

        xRayTestStaticBox->AddSpacer(5);

        // Image 4
        {
            auto staticBox = new wxStaticBox(panel, wxID_ANY, "Image 4");
            {
                staticBox->SetBackgroundColour(wxColor(255, 201, 14));
                wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(staticBox, wxVERTICAL);
                {
                    wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

                    m_XRayImage4Path = std::make_unique<wxTextCtrl>
                        (
                            panel,
                            GenerateReportVariables::ID_XRAY_IMAGE_4_PATH_TXT_CTRL,
                            wxT("X-Ray 4 Image Path..."),
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_LEFT | wxTE_READONLY
                        );

                    horizontalSizer->Add(m_XRayImage4Path.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

                    auto bmp = wxMaterialDesignArtProvider::GetBitmap
                    (
                        wxART_TOGGLE_OFF,
                        wxART_CLIENT_AWESOME_SOLID,
                        wxSize(16, 16),
                        wxColour(255, 0, 0)
                    );

                    m_OpenXRayImage4Btn = std::make_unique<wxBitmapButton>
                        (
                            panel,
                            GenerateReportVariables::ID_OPEN_XRAY_IMAGE_4_BTN,
                            bmp
                        );

                    m_OpenXRayImage4Btn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenXRayImage4Btn, this);

                    horizontalSizer->Add(m_OpenXRayImage4Btn.get(), 0, wxRIGHT, 2);
                    staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);

                    m_XRayImage4Caption = std::make_unique<wxTextCtrl>
                        (
                            panel,
                            GenerateReportVariables::ID_XRAY_IMAGE_4_CAPTION_TXT_CTRL,
                            m_InputParameters->xRayImagesDefaultCaption[3],
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_LEFT
                        );
                    m_XRayImage4Caption->Disable();
                    staticBoxSizer->AddSpacer(2);
                    staticBoxSizer->Add(m_XRayImage4Caption.get(), 0, wxEXPAND);
                }
                xRayTestStaticBox->Add(staticBoxSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);
            }
        }

        xRayTestStaticBox->AddSpacer(5);

        // Image 5
        {
            auto staticBox = new wxStaticBox(panel, wxID_ANY, "Image 5");
            {
                staticBox->SetBackgroundColour(wxColor(255, 201, 14));
                wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(staticBox, wxVERTICAL);
                {
                    wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

                    m_XRayImage5Path = std::make_unique<wxTextCtrl>
                        (
                            panel,
                            GenerateReportVariables::ID_XRAY_IMAGE_5_PATH_TXT_CTRL,
                            wxT("X-Ray 5 Image Path..."),
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_LEFT | wxTE_READONLY
                        );

                    horizontalSizer->Add(m_XRayImage5Path.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

                    auto bmp = wxMaterialDesignArtProvider::GetBitmap
                    (
                        wxART_TOGGLE_OFF,
                        wxART_CLIENT_AWESOME_SOLID,
                        wxSize(16, 16),
                        wxColour(255, 0, 0)
                    );

                    m_OpenXRayImage5Btn = std::make_unique<wxBitmapButton>
                        (
                            panel,
                            GenerateReportVariables::ID_OPEN_XRAY_IMAGE_5_BTN,
                            bmp
                        );

                    m_OpenXRayImage5Btn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenXRayImage5Btn, this);

                    horizontalSizer->Add(m_OpenXRayImage5Btn.get(), 0, wxRIGHT, 2);
                    staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);

                    m_XRayImage5Caption = std::make_unique<wxTextCtrl>
                        (
                            panel,
                            GenerateReportVariables::ID_XRAY_IMAGE_5_CAPTION_TXT_CTRL,
                            m_InputParameters->xRayImagesDefaultCaption[4],
                            wxDefaultPosition, wxDefaultSize,
                            wxTE_LEFT
                        );
                    m_XRayImage5Caption->Disable();
                    staticBoxSizer->AddSpacer(2);
                    staticBoxSizer->Add(m_XRayImage5Caption.get(), 0, wxEXPAND);
                }
                xRayTestStaticBox->Add(staticBoxSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);
            }
        }

    }

	topSizer->Add(xRayTestStaticBox, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);

    panel->SetSizerAndFit(topSizer);
    return panel;
}

auto cGenerateReportDialog::OnOpenOriginalBlackImageBtn(wxCommandEvent& evt) -> void
{
	constexpr auto empty_field_exception_msg = [](wxString type)
	{
		wxString title = "Empty settings field";
		wxMessageBox(
			wxT
			(
				"It seems that you don't have any value inside the \"" + type.Capitalize() + "\" settings field"
				"\nPlease, enter value inside the \"" + type.Capitalize() + "\" field and try again"
			),
			title,
			wxICON_ERROR);
	};

	constexpr auto loading_image_exception_msg = []()
	{
		wxString title = "Error image reading";
		wxMessageBox(
			wxT
			(
				"The image that you've selected can't be loaded."
				"\nPlease, select another image."
			),
			title,
			wxICON_ERROR);
	};

	constexpr auto different_image_sizes_exception_msg = []()
	{
		wxString title = "Error image reading";
		wxMessageBox(
			wxT
			(
				"The image that you've selected doesn't have the same size as the previously loaded image."
				"\nPlease, select another image."
			),
			title,
			wxICON_ERROR);
	};


    //m_IsOriginalBlackImageLoadedSucc = false;

    if (m_IsOriginalBlackImgToggled)
    {
        //m_BlackImageMat = cv::Mat();
        m_OriginalBlackImgPathTxtCtrl->ChangeValue(wxT("Black Image Path..."));
        
        m_IsOriginalBlackImgToggled = false;
		auto bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenOriginalBlackImgBtn->SetBitmap(bmp);
		//m_OpenBlackImgBtn->SetLabel(wxT("Open"));

   //     if (m_IsWhiteImageToggled)
   //     {
			//m_ImgWidthTxtCtrl->Enable();
			//m_ImgHeightTxtCtrl->Enable();
   //     }
        return;
    }

	int imgWidthTxtCtrl{};
	/* Image Width */
	if (!m_ImgWidthTxtCtrl->GetValue().ToInt(&imgWidthTxtCtrl))
	{
		empty_field_exception_msg("width");
		return;
	}
	int imgHeightTxtCtrl{};
	/* Image Height */
	if (!m_ImgHeightTxtCtrl->GetValue().ToInt(&imgHeightTxtCtrl))
	{
		empty_field_exception_msg("height");
		return;
	}

	std::string file_path{};
#ifdef _DEBUG
	file_path = "D:\\Data_RIGAKU\\2025\\VM\\Data\\tmavy.tif";
#else
    wxFileDialog dlg
    (
        this,
        "Open an image",
        wxEmptyString,
        wxEmptyString,
        "TIF Files (*.tif)|*.tif",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dlg.ShowModal() != wxID_OK) return;
    file_path = std::string(dlg.GetPath().mbc_str());
#endif // _DEBUG

    auto origBlackImgMat = cv::imread(file_path, cv::IMREAD_GRAYSCALE);
    auto imgHeight = origBlackImgMat.rows;
    auto imgWidth = origBlackImgMat.cols;

    if (imgWidth <= 0 || imgHeight <= 0)
    {
        loading_image_exception_msg();
        return;
    }

    if (!imgWidthTxtCtrl && !imgHeightTxtCtrl)
    {
        m_ImgWidthTxtCtrl->SetValue(wxString::Format(wxT("%i"), imgWidth));
        m_ImgHeightTxtCtrl->SetValue(wxString::Format(wxT("%i"), imgHeight));
    }
    else
    {
        // Check if the first and the second image sizes are the same
        if (imgWidth != imgWidthTxtCtrl || imgHeight != imgHeightTxtCtrl)
        {
            different_image_sizes_exception_msg();
            return;
        }
    }

    m_OriginalBlackImagePath = file_path;

    m_OriginalBlackImgPathTxtCtrl->ChangeValue(file_path);

    //m_IsOriginalBlackImageLoadedSucc = true;
    m_IsOriginalBlackImgToggled = true;

	auto bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);
	m_OpenOriginalBlackImgBtn->SetBitmap(bmp);
    //m_OpenBlackImgBtn->SetLabel(wxT("Close"));

    //m_ImgWidthTxtCtrl->Disable();
    //m_ImgHeightTxtCtrl->Disable();
}

auto cGenerateReportDialog::OnOpenOriginalWhiteImageBtn(wxCommandEvent& evt) -> void
{
	constexpr auto empty_field_exception_msg = [](wxString type)
	{
		wxString title = "Empty settings field";
		wxMessageBox(
			wxT
			(
				"It seems that you don't have any value inside the \"" + type.Capitalize() + "\" settings field"
				"\nPlease, enter value inside the \"" + type.Capitalize() + "\" field and try again"
			),
			title,
			wxICON_ERROR);
	};

	constexpr auto loading_image_exception_msg = []()
	{
		wxString title = "Error image reading";
		wxMessageBox(
			wxT
			(
				"The image that you've selected can't be loaded."
				"\nPlease, select another image."
			),
			title,
			wxICON_ERROR);
	};

	constexpr auto different_image_sizes_exception_msg = []()
	{
		wxString title = "Error image reading";
		wxMessageBox(
			wxT
			(
				"The image that you've selected doesn't have the same size as the previously loaded image."
				"\nPlease, select another image."
			),
			title,
			wxICON_ERROR);
	};

    //m_IsOriginalWhiteImageLoadedSucc = false;

    if (m_IsOriginalWhiteImageToggled)
    {
        //m_WhiteImageMat = cv::Mat();
        m_OriginalWhiteImgPathTxtCtrl->ChangeValue(wxT("White Image Path..."));

		auto bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenOriginalWhiteImgBtn->SetBitmap(bmp);
        m_IsOriginalWhiteImageToggled = false;
		//m_OpenWhiteImgBtn->SetLabel(wxT("Open"));

   //     if (m_IsBlackImgToggled)
   //     {
			//m_ImgWidthTxtCtrl->Enable();
			//m_ImgHeightTxtCtrl->Enable();
   //     }
        return;
    }

	int imgWidthTxtCtrl{};
	/* Image Width */
	if (!m_ImgWidthTxtCtrl->GetValue().ToInt(&imgWidthTxtCtrl))
	{
		empty_field_exception_msg("width");
		return;
	}
	int imgHeightTxtCtrl{};
	/* Image Height */
	if (!m_ImgHeightTxtCtrl->GetValue().ToInt(&imgHeightTxtCtrl))
	{
		empty_field_exception_msg("height");
		return;
	}

	std::string file_path{};
#ifdef _DEBUG
	file_path = "D:\\Data_RIGAKU\\2025\\VM\\Data\\svetly.tif";
#else
    wxFileDialog dlg
    (
        this,
        "Open an image",
        wxEmptyString,
        wxEmptyString,
        "TIF Files (*.tif)|*.titif",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dlg.ShowModal() != wxID_OK) return;
    file_path = std::string(dlg.GetPath().mbc_str());
#endif // _DEBUG

    auto origImgMat = cv::imread(file_path, cv::IMREAD_GRAYSCALE);
    auto imgHeight = origImgMat.rows;
    auto imgWidth = origImgMat.cols;

    if (imgWidth <= 0 || imgHeight <= 0)
    {
        loading_image_exception_msg();
        return;
    }

    if (!imgWidthTxtCtrl && !imgHeightTxtCtrl)
    {
        m_ImgWidthTxtCtrl->SetValue(wxString::Format(wxT("%i"), imgWidth));
        m_ImgHeightTxtCtrl->SetValue(wxString::Format(wxT("%i"), imgHeight));
    }
    else
    {
        // Check if the first and the second image sizes are the same
        if (imgWidth != imgWidthTxtCtrl || imgHeight != imgHeightTxtCtrl)
        {
            different_image_sizes_exception_msg();
            return;
        }
    }

    m_OriginalWhiteImagePath = file_path;

    m_OriginalWhiteImgPathTxtCtrl->ChangeValue(file_path);

    //m_IsOriginalWhiteImageLoadedSucc = true;
    m_IsOriginalWhiteImageToggled = true;

	auto bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);
	m_OpenOriginalWhiteImgBtn->SetBitmap(bmp);
    //m_OpenWhiteImgTglBtn->SetLabel(wxT("Close"));

    //m_ImgWidthTxtCtrl->Disable();
    //m_ImgHeightTxtCtrl->Disable();
}

auto cGenerateReportDialog::OnOpenCircleBlackImageBtn(wxCommandEvent& evt) -> void
{
	constexpr auto empty_field_exception_msg = [](wxString type)
	{
		wxString title = "Empty settings field";
		wxMessageBox(
			wxT
			(
				"It seems that you don't have any value inside the \"" + type.Capitalize() + "\" settings field"
				"\nPlease, enter value inside the \"" + type.Capitalize() + "\" field and try again"
			),
			title,
			wxICON_ERROR);
	};

	constexpr auto loading_image_exception_msg = []()
	{
		wxString title = "Error image reading";
		wxMessageBox(
			wxT
			(
				"The image that you've selected can't be loaded."
				"\nPlease, select another image."
			),
			title,
			wxICON_ERROR);
	};

	constexpr auto different_image_sizes_exception_msg = []()
	{
		wxString title = "Error image reading";
		wxMessageBox(
			wxT
			(
				"The image that you've selected doesn't have the same size as the previously loaded image."
				"\nPlease, select another image."
			),
			title,
			wxICON_ERROR);
	};


    //m_IsCircleBlackImageLoadedSucc = false;

    if (m_IsCircleBlackImgToggled)
    {
        m_CircleBlackImgPathTxtCtrl->ChangeValue(wxT("Black Image Path..."));
        
        m_IsCircleBlackImgToggled = false;
		auto bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenCircleBlackImgBtn->SetBitmap(bmp);
        return;
    }

	int imgWidthTxtCtrl{};
	/* Image Width */
	if (!m_ImgWidthTxtCtrl->GetValue().ToInt(&imgWidthTxtCtrl))
	{
		empty_field_exception_msg("width");
		return;
	}
	int imgHeightTxtCtrl{};
	/* Image Height */
	if (!m_ImgHeightTxtCtrl->GetValue().ToInt(&imgHeightTxtCtrl))
	{
		empty_field_exception_msg("height");
		return;
	}

	std::string file_path{};
#ifdef _DEBUG
	file_path = "D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\tmavy.tif";
#else
    wxFileDialog dlg
    (
        this,
        "Open an image",
        wxEmptyString,
        wxEmptyString,
        "TIF Files (*.tif)|*.tif",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dlg.ShowModal() != wxID_OK) return;
    file_path = std::string(dlg.GetPath().mbc_str());
#endif // _DEBUG

    auto circleBlackImgMat = cv::imread(file_path, cv::IMREAD_GRAYSCALE);
    auto imgHeight = circleBlackImgMat.rows;
    auto imgWidth = circleBlackImgMat.cols;

    if (imgWidth <= 0 || imgHeight <= 0)
    {
        loading_image_exception_msg();
        return;
    }

    if (!imgWidthTxtCtrl && !imgHeightTxtCtrl)
    {
        m_ImgWidthTxtCtrl->SetValue(wxString::Format(wxT("%i"), imgWidth));
        m_ImgHeightTxtCtrl->SetValue(wxString::Format(wxT("%i"), imgHeight));
    }
    else
    {
        // Check if the first and the second image sizes are the same
        if (imgWidth != imgWidthTxtCtrl || imgHeight != imgHeightTxtCtrl)
        {
            different_image_sizes_exception_msg();
            return;
        }
    }

    m_CircleBlackImagePath = file_path;

    m_CircleBlackImgPathTxtCtrl->ChangeValue(file_path);

    //m_IsCircleBlackImageLoadedSucc = true;
    m_IsCircleBlackImgToggled = true;

	auto bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);
	m_OpenCircleBlackImgBtn->SetBitmap(bmp);
}

auto cGenerateReportDialog::OnOpenImagesForCalculationBtn(wxCommandEvent& evt) -> void
{
	constexpr auto selected_files_quantity_exception_msg = [](int number_of_images)
	{
		wxString title = "Error image reading";
		wxMessageBox(
			wxT
			(
				"You have to select " + wxString::Format("%d images.", number_of_images) +
				"\nPlease, try again."
			),
			title,
			wxICON_ERROR);
	};

    if (m_IsOpenImagesForCalculationToggled)
    {
        m_ImagesForCalculationPaths->ChangeValue(wxT("Image Paths..."));

		auto bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenImagesForCalculationBtn->SetBitmap(bmp);
        m_IsOpenImagesForCalculationToggled = false;
        return;
    }

    auto imagesQuantity{ 13 };
	wxArrayString filePaths{};
#ifdef _DEBUG
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_01_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_02_11H_15M_09S_8000us_1A_11_305_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_03_11H_15M_09S_8000us_1A_11_330_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_04_11H_15M_09S_8000us_1A_11_355_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_05_11H_15M_09S_8000us_1A_11_380_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_06_11H_15M_09S_8000us_1A_11_405_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_07_11H_15M_09S_8000us_1A_11_430_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_08_11H_15M_09S_8000us_1A_11_455_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_09_11H_15M_09S_8000us_1A_11_480_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_10_11H_15M_09S_8000us_1A_11_505_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_11_11H_15M_09S_8000us_1A_11_530_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_12_11H_15M_09S_8000us_1A_11_555_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_13_11H_15M_09S_8000us_1A_11_580_2A_0_000.tif");
#else
	wxFileDialog dlg
	(
		this,
		"Select all the files that you want to calculate",
		wxEmptyString,
		wxEmptyString,
		"TIF Files (*.tif)|*.tif",
		wxFD_OPEN | wxFD_MULTIPLE | wxFD_FILE_MUST_EXIST
	);

    do
    {
		if (dlg.ShowModal() != wxID_OK) return;
		dlg.GetPaths(filePaths);

        if (filePaths.GetCount() != imagesQuantity)
            selected_files_quantity_exception_msg(imagesQuantity);

    } while (filePaths.GetCount() != imagesQuantity);

#endif // _DEBUG
    m_ImagesForCalculationPathsArray = filePaths;

    wxString fileNames{};
    int i{};
    for (const auto& filePath : filePaths)
    {
        if (i) fileNames += ", ";
        wxFileName file(filePath);
        fileNames += file.GetFullName();
        ++i;
    }
    m_ImagesForCalculationPaths->ChangeValue(fileNames);

    m_IsOpenImagesForCalculationToggled = true;
	auto bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);
	m_OpenImagesForCalculationBtn->SetBitmap(bmp);
}

auto cGenerateReportDialog::OnOpenCircleImagesForCalculationBtn(wxCommandEvent& evt) -> void
{
	constexpr auto selected_files_quantity_exception_msg = [](int number_of_images)
	{
		wxString title = "Error image reading";
		wxMessageBox(
			wxT
			(
				"You have to select " + wxString::Format("%d images.", number_of_images) +
				"\nPlease, try again."
			),
			title,
			wxICON_ERROR);
	};

    if (m_IsOpenCircleImagesForCalculationToggled)
    {
        m_CircleImagesForCalculationPaths->ChangeValue(wxT("Image Paths..."));

		auto bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenCircleImagesForCalculationBtn->SetBitmap(bmp);
        m_IsOpenCircleImagesForCalculationToggled = false;
        return;
    }

    auto imagesQuantity{ 13 };
	wxArrayString filePaths{};
#ifdef _DEBUG
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_01_09H_48M_52S_150000us_1A_8_910_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_02_09H_48M_52S_150000us_1A_9_410_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_03_09H_48M_52S_150000us_1A_9_910_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_04_09H_48M_52S_150000us_1A_10_410_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_05_09H_48M_52S_150000us_1A_10_910_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_06_09H_48M_52S_150000us_1A_11_410_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_07_09H_48M_52S_150000us_1A_11_910_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_08_09H_48M_52S_150000us_1A_12_410_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_09_09H_48M_52S_150000us_1A_12_910_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_10_09H_48M_52S_150000us_1A_13_410_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_11_09H_48M_52S_150000us_1A_13_910_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_12_09H_48M_52S_150000us_1A_14_410_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\kruhy\\kruhy\\img_13_09H_48M_52S_150000us_1A_14_910_2A_0_000.tif");
#else
	wxFileDialog dlg
	(
		this,
		"Select all the circle files that you want to calculate",
		wxEmptyString,
		wxEmptyString,
		"TIF Files (*.tif)|*.tif",
		wxFD_OPEN | wxFD_MULTIPLE | wxFD_FILE_MUST_EXIST
	);

    do
    {
		if (dlg.ShowModal() != wxID_OK) return;
		dlg.GetPaths(filePaths);

        if (filePaths.GetCount() != imagesQuantity)
            selected_files_quantity_exception_msg(imagesQuantity);

    } while (filePaths.GetCount() != imagesQuantity);

#endif // _DEBUG
    m_CircleImagesForCalculationPathsArray = filePaths;

    wxString fileNames{};
    int i{};
    for (const auto& filePath : filePaths)
    {
        if (i) fileNames += ", ";
        wxFileName file(filePath);
        fileNames += file.GetFullName();
        ++i;
    }
    m_CircleImagesForCalculationPaths->ChangeValue(fileNames);

    m_IsOpenCircleImagesForCalculationToggled = true;
	auto bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);
	m_OpenCircleImagesForCalculationBtn->SetBitmap(bmp);
}

auto cGenerateReportDialog::OnOpenXRayImage1Btn(wxCommandEvent& evt) -> void
{
    auto bmp = wxBitmap();

    if (m_IsOpenXRayImage1Toggled)
    {
        m_XRayImage1Path->ChangeValue(wxT("X-Ray 1 Image Path..."));
        
        m_IsOpenXRayImage1Toggled = false;
		bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenXRayImage1Btn->SetBitmap(bmp);
		m_XRayImage1Caption->Disable();
        return;
    }

	std::string file_path{};
#ifdef _DEBUG
	file_path = "D:\\Data_RIGAKU\\2025\\VM\\037-066\\mca_graf.png";
#else
    wxFileDialog dlg
    (
        this,
        "Open an image",
        wxEmptyString,
        wxEmptyString,
        "PNG Files (*.png)|*.png",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dlg.ShowModal() != wxID_OK) return;
    file_path = std::string(dlg.GetPath().mbc_str());
#endif // _DEBUG

    m_XRayImage1Path->ChangeValue(file_path);

    m_IsOpenXRayImage1Toggled = true;

	bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);

	m_OpenXRayImage1Btn->SetBitmap(bmp);
	m_XRayImage1Caption->Enable();
}

auto cGenerateReportDialog::OnOpenXRayImage2Btn(wxCommandEvent& evt) -> void
{
    auto bmp = wxBitmap();

    if (m_IsOpenXRayImage2Toggled)
    {
        m_XRayImage2Path->ChangeValue(wxT("X-Ray 2 Image Path..."));
        
        m_IsOpenXRayImage2Toggled = false;
		bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenXRayImage2Btn->SetBitmap(bmp);
		m_XRayImage2Caption->Disable();
        return;
    }

	std::string file_path{};
#ifdef _DEBUG
	file_path = "D:\\Data_RIGAKU\\2025\\VM\\037-066\\Gain.png";
#else
    wxFileDialog dlg
    (
        this,
        "Open an image",
        wxEmptyString,
        wxEmptyString,
        "PNG Files (*.png)|*.png",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dlg.ShowModal() != wxID_OK) return;
    file_path = std::string(dlg.GetPath().mbc_str());
#endif // _DEBUG

    m_XRayImage2Path->ChangeValue(file_path);

    m_IsOpenXRayImage2Toggled = true;

	bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);

	m_OpenXRayImage2Btn->SetBitmap(bmp);
	m_XRayImage2Caption->Enable();
}

auto cGenerateReportDialog::OnOpenXRayImage3Btn(wxCommandEvent& evt) -> void
{
    auto bmp = wxBitmap();

    if (m_IsOpenXRayImage3Toggled)
    {
        m_XRayImage3Path->ChangeValue(wxT("X-Ray 3 Image Path..."));
        
        m_IsOpenXRayImage3Toggled = false;
		bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenXRayImage3Btn->SetBitmap(bmp);
		m_XRayImage3Caption->Disable();
        return;
    }

	std::string file_path{};
#ifdef _DEBUG
	file_path = "D:\\Data_RIGAKU\\2025\\VM\\037-066\\Gain_compare.png";
#else
    wxFileDialog dlg
    (
        this,
        "Open an image",
        wxEmptyString,
        wxEmptyString,
        "PNG Files (*.png)|*.png",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dlg.ShowModal() != wxID_OK) return;
    file_path = std::string(dlg.GetPath().mbc_str());
#endif // _DEBUG

    m_XRayImage3Path->ChangeValue(file_path);

    m_IsOpenXRayImage3Toggled = true;

	bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);

	m_OpenXRayImage3Btn->SetBitmap(bmp);
	m_XRayImage3Caption->Enable();
}

auto cGenerateReportDialog::OnOpenXRayImage4Btn(wxCommandEvent& evt) -> void
{
    auto bmp = wxBitmap();

    if (m_IsOpenXRayImage4Toggled)
    {
        m_XRayImage4Path->ChangeValue(wxT("X-Ray 4 Image Path..."));
        
        m_IsOpenXRayImage4Toggled = false;
		bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenXRayImage4Btn->SetBitmap(bmp);
		m_XRayImage4Caption->Disable();
        return;
    }

	std::string file_path{};
#ifdef _DEBUG
	file_path = "D:\\Data_RIGAKU\\2025\\VM\\037-066\\mca_graf.png";
#else
    wxFileDialog dlg
    (
        this,
        "Open an image",
        wxEmptyString,
        wxEmptyString,
        "PNG Files (*.png)|*.png",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dlg.ShowModal() != wxID_OK) return;
    file_path = std::string(dlg.GetPath().mbc_str());
#endif // _DEBUG

    m_XRayImage4Path->ChangeValue(file_path);

    m_IsOpenXRayImage4Toggled = true;

	bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);

	m_OpenXRayImage4Btn->SetBitmap(bmp);
	m_XRayImage4Caption->Enable();
}

auto cGenerateReportDialog::OnOpenXRayImage5Btn(wxCommandEvent& evt) -> void
{
    auto bmp = wxBitmap();

    if (m_IsOpenXRayImage5Toggled)
    {
        m_XRayImage5Path->ChangeValue(wxT("X-Ray 5 Image Path..."));
        
        m_IsOpenXRayImage5Toggled = false;
		bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenXRayImage5Btn->SetBitmap(bmp);
		m_XRayImage5Caption->Disable();
        return;
    }

	std::string file_path{};
#ifdef _DEBUG
	file_path = "D:\\Data_RIGAKU\\2025\\VM\\037-066\\mca_graf.png";
#else
    wxFileDialog dlg
    (
        this,
        "Open an image",
        wxEmptyString,
        wxEmptyString,
        "PNG Files (*.png)|*.png",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dlg.ShowModal() != wxID_OK) return;
    file_path = std::string(dlg.GetPath().mbc_str());
#endif // _DEBUG

    m_XRayImage5Path->ChangeValue(file_path);

    m_IsOpenXRayImage5Toggled = true;

	bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);

	m_OpenXRayImage5Btn->SetBitmap(bmp);
	m_XRayImage5Caption->Enable();
}

auto cGenerateReportDialog::OnDataTypeChoice(wxCommandEvent& evt) -> void
{
    wxLogDebug("Pressed");
}

auto cGenerateReportDialog::CheckIfImageIsCorrect
(
    const std::string filePath, 
    const unsigned long long expectedSize,
	const int imageWidth,
	const int imageHeight
) -> bool
{
	constexpr auto raise_file_cant_be_opened = []()
		{
			wxString title = "Input data error";
			wxMessageBox(
				wxT
				(
					"Selected RAW file can't be opened, please select another file."
				),
				title,
				wxICON_ERROR);
		};
	constexpr auto raise_unexpected_image_size = [](unsigned long long expectedBytes, size_t actualBytes)
		{
			wxString title = "Input size error";
			wxMessageBox(
				wxT
				(
					"Selected RAW file does not contain the expected amount of data.\n"
					"Expected: " + wxString::Format(wxT("%llu"), expectedBytes) + " bytes, Actual: " +  wxString::Format(wxT("%zu"), actualBytes)+ " bytes.\n"
				),
				title,
				wxICON_ERROR);
		};


    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open())
    {
        raise_file_cant_be_opened();
        return false;
    }

    // Seek to the end of the file to determine its size
    file.seekg(0, std::ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    if (fileSize != expectedSize) 
    {
        raise_unexpected_image_size(expectedSize, fileSize);
        return false;
    }

    file.close();
    return true;
}

auto cGenerateReportDialog::LoadData
(
    const std::string filePath, 
    unsigned short* const pData, 
    const int imageWidth, 
    const int imageHeight
) -> bool
{
	constexpr auto raise_file_cant_be_opened = []()
		{
			wxString title = "Input data error";
			wxMessageBox(
				wxT
				(
					"Selected RAW file can't be opened, please select another file."
				),
				title,
				wxICON_ERROR);
		};

    if (!pData) return false;

    std::ifstream file(filePath, std::ios::binary);
    if (!file.is_open())
    {
        raise_file_cant_be_opened();
        return false;
    }

    file.read((char*)&pData[0], imageWidth * imageHeight * sizeof(unsigned short));
    file.close();

    return true;
}

auto cGenerateReportDialog::OnExitButtonClicked(wxCommandEvent& evt) -> void
{
	auto raise_image_isnt_set = [&]()
		{
			wxString title = "Image data error";
            wxString trueSign = "[OK]";
            wxString falseSign = "[X]";

            wxString allImages{};
            allImages += m_IsOriginalBlackImgToggled ? trueSign : falseSign;
            allImages += " Original Black Image\n";
            allImages += m_IsOriginalWhiteImageToggled ? trueSign : falseSign;
            allImages += " Original White Image\n";
            allImages += m_IsCircleBlackImgToggled ? trueSign : falseSign;
            allImages += " Circle Black Image\n";
            allImages += m_IsOpenImagesForCalculationToggled ? trueSign : falseSign;
            allImages += " Images For Calculation\n";
            allImages += m_IsOpenCircleImagesForCalculationToggled ? trueSign : falseSign;
            allImages += " Circle Images For Calculation\n";

			wxMessageBox(
				wxT
				(
					"You hasn't selected one of the required images properly.\n" + 
                    allImages +
                    "\nPlease select required images properly."
				),
				title,
				wxICON_ERROR);
		};

    int buttonId = evt.GetId();
    if (buttonId != wxID_OK)
    {
        EndModal(buttonId);
        return;
    }

    if (!m_IsOriginalBlackImgToggled || !m_IsOriginalWhiteImageToggled || !m_IsCircleBlackImgToggled 
        || !m_IsOpenImagesForCalculationToggled || !m_IsOpenCircleImagesForCalculationToggled)
    {
        raise_image_isnt_set();
        return;
    }

	EndModal(buttonId);
}
