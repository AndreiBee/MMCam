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

    auto mainPanel = CreateSettingsPage(notebook);

    notebook->AddPage(mainPanel, "Flat Field Correction", true, 0);

    LayoutDialog();

}

wxPanel* cGenerateReportDialog::CreateSettingsPage(wxWindow* parent)
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
		topSizer->Add(staticBoxSizer, wxSizerFlags(1).Expand().Border(wxALL, 5));
    }

	// Black Image
    wxStaticBox* blackStaticBox = new wxStaticBox(panel, wxID_ANY, "Black Image");
    {
        blackStaticBox->SetBackgroundColour(wxColor(90, 90, 90));

        wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(blackStaticBox, wxVERTICAL);
        {
            wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

            m_BlackImgPathTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_BLACK_PATH_TXT_CTRL,
                    wxT("Black Image Path..."),
                    wxDefaultPosition, wxDefaultSize,
					wxTE_LEFT | wxTE_READONLY
                );

            horizontalSizer->Add(m_BlackImgPathTxtCtrl.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

			auto bmp = wxMaterialDesignArtProvider::GetBitmap
			(
				wxART_TOGGLE_OFF, 
				wxART_CLIENT_AWESOME_SOLID, 
				wxSize(16, 16), 
				wxColour(255, 0, 0)
			);

            m_OpenBlackImgBtn = std::make_unique<wxBitmapButton>
                (
                    panel,
                    GenerateReportVariables::ID_OPEN_BLACK_BTN,
                    bmp
                );
			m_OpenBlackImgBtn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenBlackImageBtn, this);

            horizontalSizer->Add(m_OpenBlackImgBtn.get(), 0, wxRIGHT, 2);

            staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);
        }
		topSizer->Add(staticBoxSizer, 0, wxEXPAND | wxLEFT | wxRIGHT, 5);
    }

	// White Image
    wxStaticBox* whiteStaticBox = new wxStaticBox(panel, wxID_ANY, "White Image");
    {
        whiteStaticBox->SetBackgroundColour(wxColor(255, 255, 255));
        wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(whiteStaticBox, wxVERTICAL);
        {
            wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

            m_WhiteImgPathTxtCtrl = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_WHITE_PATH_TXT_CTRL,
                    wxT("White Image Path..."),
                    wxDefaultPosition, wxDefaultSize,
					wxTE_LEFT | wxTE_READONLY
                );

            horizontalSizer->Add(m_WhiteImgPathTxtCtrl.get(), 1, wxLEFT | wxRIGHT | wxEXPAND, 2);

			auto bmp = wxMaterialDesignArtProvider::GetBitmap
			(
				wxART_TOGGLE_OFF, 
				wxART_CLIENT_AWESOME_SOLID, 
				wxSize(16, 16), 
				wxColour(255, 0, 0)
			);

            m_OpenWhiteImgBtn = std::make_unique<wxBitmapButton>
                (
                    panel,
                    GenerateReportVariables::ID_OPEN_WHITE_BTN,
                    bmp
                );

			m_OpenWhiteImgBtn->Bind(wxEVT_BUTTON, &cGenerateReportDialog::OnOpenWhiteImageBtn, this);

            horizontalSizer->Add(m_OpenWhiteImgBtn.get(), 0, wxRIGHT, 2);
            staticBoxSizer->Add(horizontalSizer, 0, wxEXPAND);
        }
		topSizer->Add(staticBoxSizer,0, wxEXPAND | wxLEFT | wxRIGHT, 5);
    }

	// Images for Calculation
    wxStaticBox* calculatedImagesStaticBox = new wxStaticBox(panel, wxID_ANY, "Images for Calculation");
    {
        calculatedImagesStaticBox->SetBackgroundColour(wxColor(255, 255, 255));
        wxStaticBoxSizer* staticBoxSizer = new wxStaticBoxSizer(calculatedImagesStaticBox, wxVERTICAL);
        {
            wxBoxSizer* horizontalSizer = new wxBoxSizer(wxHORIZONTAL);

            m_ImagesForCalculationPaths = std::make_unique<wxTextCtrl>
                (
                    panel,
                    GenerateReportVariables::ID_IMAGES_FOR_CALCULATION_PATHS_TXT_CTRL,
                    wxT("Image Paths..."),
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

    panel->SetSizerAndFit(topSizer);
    return panel;
}

auto cGenerateReportDialog::OnOpenBlackImageBtn(wxCommandEvent& evt) -> void
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


    m_IsBlackImageLoadedSucc = false;

    if (m_IsBlackImgToggled)
    {
        m_BlackImageMat = cv::Mat();
        m_BlackImgPathTxtCtrl->ChangeValue(wxT("Black Image Path..."));
        
        m_IsBlackImgToggled = false;
		auto bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenBlackImgBtn->SetBitmap(bmp);
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

    m_BlackImageMat = cv::imread(file_path, cv::IMREAD_GRAYSCALE);
    auto imgHeight = m_BlackImageMat.rows;
    auto imgWidth = m_BlackImageMat.cols;

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

    m_BlackImagePath = file_path;

    m_BlackImgPathTxtCtrl->ChangeValue(file_path);

    m_IsBlackImageLoadedSucc = true;
    m_IsBlackImgToggled = true;

	auto bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);
	m_OpenBlackImgBtn->SetBitmap(bmp);
    //m_OpenBlackImgBtn->SetLabel(wxT("Close"));

    //m_ImgWidthTxtCtrl->Disable();
    //m_ImgHeightTxtCtrl->Disable();
}

auto cGenerateReportDialog::OnOpenWhiteImageBtn(wxCommandEvent& evt) -> void
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

    m_IsWhiteImageLoadedSucc = false;

    if (m_IsWhiteImageToggled)
    {
        m_WhiteImageMat = cv::Mat();
        m_WhiteImgPathTxtCtrl->ChangeValue(wxT("White Image Path..."));

		auto bmp = wxMaterialDesignArtProvider::GetBitmap
		(
			wxART_TOGGLE_OFF, 
			wxART_CLIENT_AWESOME_SOLID, 
			wxSize(16, 16), 
			wxColour(255, 0, 0)
		);
		m_OpenWhiteImgBtn->SetBitmap(bmp);
        m_IsWhiteImageToggled = false;
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
        "RAW Files (*.raw)|*.raw",
        wxFD_OPEN | wxFD_FILE_MUST_EXIST
    );

    if (dlg.ShowModal() != wxID_OK) return;
    file_path = std::string(dlg.GetPath().mbc_str());
#endif // _DEBUG

    m_WhiteImageMat = cv::imread(file_path, cv::IMREAD_GRAYSCALE);
    auto imgHeight = m_WhiteImageMat.rows;
    auto imgWidth = m_WhiteImageMat.cols;

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

    m_WhiteImagePath = file_path;

    m_WhiteImgPathTxtCtrl->ChangeValue(file_path);

    m_IsWhiteImageLoadedSucc = true;
    m_IsWhiteImageToggled = true;

	auto bmp = wxMaterialDesignArtProvider::GetBitmap
	(
		wxART_TOGGLE_ON, 
		wxART_CLIENT_AWESOME_SOLID, 
		wxSize(16, 16), 
		wxColour(0, 255, 0)
	);
	m_OpenWhiteImgBtn->SetBitmap(bmp);
    //m_OpenWhiteImgTglBtn->SetLabel(wxT("Close"));

    //m_ImgWidthTxtCtrl->Disable();
    //m_ImgHeightTxtCtrl->Disable();
}

auto cGenerateReportDialog::OnOpenImagesForCalculationBtn(wxCommandEvent& evt) -> void
{
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

	wxArrayString filePaths{};
#ifdef _DEBUG
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_01_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_02_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_03_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_04_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_05_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_06_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_07_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_08_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_09_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_10_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_11_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_12_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
	filePaths.Add("D:\\Data_RIGAKU\\2025\\VM\\Data\\img_13_11H_15M_09S_8000us_1A_11_280_2A_0_000.tif");
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

    if (dlg.ShowModal() != wxID_OK) return;
    dlg.GetPaths(filePaths);
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
	constexpr auto raise_image_isnt_set = []()
		{
			wxString title = "Image data error";
			wxMessageBox(
				wxT
				(
					"You hasn't selected one of the images properly.\nPlease select Black and White images properly."
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

    if (!m_IsBlackImageLoadedSucc || !m_IsWhiteImageLoadedSucc)
    {
        raise_image_isnt_set();
        return;
    }

	EndModal(buttonId);
}
