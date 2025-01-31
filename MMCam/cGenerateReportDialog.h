#pragma once
#ifndef CGENERATEREPORTDIALOG_H
#define CGENERATEREPORTDIALOG_H

#include "wx/wx.h"
#include "wx/dir.h"
#include "wx/propdlg.h"
#include "wx/filename.h"
#include "wx/bookctrl.h"
#include "wx/artprov.h"
#include "wx/valnum.h"
#include "wx/tglbtn.h"
#include "wx/bmpbuttn.h"
#include "wxMaterialDesignArtProvider.hpp"

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

#include <memory>
#include <fstream>

namespace GenerateReportVariables {
    enum 
    {
        // First Tab
        ID_OPTICS_SERIAL_NUMBER_TXT_CTRL,
        ID_OPTICS_PRODUCT_NUMBER_TXT_CTRL,
        ID_OPTICS_TYPE_TXT_CTRL,
        ID_REPORT_NAME_TXT_CTRL,
        ID_REPORT_AUTHOR_TXT_CTRL,
        ID_CUSTOMER_TXT_CTRL,
        ID_START_POSITION_TXT_CTRL,
        ID_STEP_TXT_CTRL,
        ID_FOCUS_EXPOSURE_TXT_CTRL,
        ID_CIRCLE_EXPOSURE_TXT_CTRL,
        ID_OPTICS_CHEME_CHOICE,
        // Second Tab
        ID_IMG_DATA_TYPE,
        ID_IMG_WIDTH,
        ID_IMG_HEIGHT,
        ID_LITTLE_ENDIAN_BYTE_ORDER_CHECK_BOX,
        ID_OPEN_ORIGINAL_BLACK_BTN,
        ID_OPEN_ORIGINAL_WHITE_BTN,
        ID_ORIGINAL_BLACK_PATH_TXT_CTRL,
        ID_ORIGINAL_WHITE_PATH_TXT_CTRL,
        ID_OPEN_CIRCLE_BLACK_BTN,
        ID_CIRCLE_BLACK_PATH_TXT_CTRL,
        // Third Tab
        ID_OPEN_IMAGES_FOR_CALCULATION_BTN,
        ID_IMAGES_FOR_CALCULATION_PATHS_TXT_CTRL,
        ID_OPEN_CIRCLE_IMAGES_FOR_CALCULATION_BTN,
        ID_CIRCLE_IMAGES_FOR_CALCULATION_PATHS_TXT_CTRL,
        ID_MEASURED_SPECTRUM_PATH_TXT_CTRL,
        ID_OPEN_MEASURED_SPECTRUM_BTN,
        ID_FIRST_GAIN_PATH_TXT_CTRL,
        ID_OPEN_FIRST_GAIN_BTN,
        ID_SECOND_GAIN_PATH_TXT_CTRL,
        ID_OPEN_SECOND_GAIN_BTN
    };

    struct InputParameters
    {
        double pixelSizeUM{};
        double widthROIMM{}, widthCircleROIMM{};
    };

    struct ReportParameters
    {
        wxString serialNumber{}, opticsProductNumber{}, opticsType{}, author{}, customer{}, reportName{};
        double start{}, step{}, focus{};
        std::unique_ptr<double[]> optimalPositionsArray{};
        int focusExposure, circleExposure{};
    };
}

class cGenerateReportDialog: public wxPropertySheetDialog
{
    wxDECLARE_CLASS(cSetFFCImgDialog);
public:
    cGenerateReportDialog
    (
        wxWindow* parent, 
        GenerateReportVariables::InputParameters inputParameters
    );

    // Getters
public:
    auto GetImageWidth() const -> int 
    {
        int imgWidth{};
        m_ImgWidthTxtCtrl->GetValue().ToInt(&imgWidth);
        return imgWidth;
    };
    auto GetImageHeight() const -> int 
    {
        int imgHeight{};
        m_ImgHeightTxtCtrl->GetValue().ToInt(&imgHeight);
        return imgHeight;
    };

    auto GetOriginalBlackImagePath() const -> wxString { return m_OriginalBlackImagePath; };
    auto GetOriginalWhiteImagePath() const -> wxString { return m_OriginalWhiteImagePath; };

    auto GetCircleBlackImagePath() const -> wxString { return m_CircleBlackImagePath; };
    
    auto GetImagesForCalculationPaths() const -> wxArrayString { return m_ImagesForCalculationPathsArray; };

    auto GetCircleImagesForCalculationPaths() const -> wxArrayString { return m_CircleImagesForCalculationPathsArray; };
    
    auto GetOpticsSchemePath() const -> wxString 
    { 
        auto currentSelection = m_OpticsSchemeChoice->GetString(m_OpticsSchemeChoice->GetSelection());
        auto outOpticsSchemePath = m_ReportGeneratorPath;
        outOpticsSchemePath += outOpticsSchemePath.EndsWith("\\") ? currentSelection : "\\" + currentSelection;
        return outOpticsSchemePath; 
    };

    auto GetReportParameters() const -> GenerateReportVariables::ReportParameters 
    { 
        GenerateReportVariables::ReportParameters reportParameters{};
        
        // String Parameters
        reportParameters.serialNumber = m_OpticsSerialNumberTxtCtrl->GetValue(); 
        reportParameters.opticsProductNumber = m_OpticsProductNumberTxtCtrl->GetValue(); 
        reportParameters.opticsType = m_OpticsTypeTxtCtrl->GetValue(); 
        reportParameters.author = m_AuthorTxtCtrl->GetValue(); 
        reportParameters.customer = m_CustomerTxtCtrl->GetValue(); 
        reportParameters.reportName = m_ReportNameTxtCtrl->GetValue(); 

        // Double Parameters
        {
            double parameter{};
            m_StartPositionTxtCtrl->GetValue().ToDouble(&parameter);
            reportParameters.start = parameter;

            m_StepTxtCtrl->GetValue().ToDouble(&parameter);
            reportParameters.step = parameter;
        }

        // Int Parameters
        {
            int parameter{};
            m_FocusExposureTxtCtrl->GetValue().ToInt(&parameter);
            reportParameters.focusExposure = parameter;

            m_CircleExposureTxtCtrl->GetValue().ToInt(&parameter);
            reportParameters.circleExposure = parameter;
        }

        return reportParameters; 
    };

private:
    wxPanel* CreateReportVariablesPage(wxWindow* parent);
    wxPanel* CreateFlatFieldPage(wxWindow* parent);
    wxPanel* CreateInputImagesPage(wxWindow* parent);

    auto OnDataTypeChoice(wxCommandEvent& evt) -> void;
    auto OnOpenOriginalBlackImageBtn(wxCommandEvent& evt) -> void;
    auto OnOpenOriginalWhiteImageBtn(wxCommandEvent& evt) -> void;

    auto OnOpenCircleBlackImageBtn(wxCommandEvent& evt) -> void;

    auto OnOpenImagesForCalculationBtn(wxCommandEvent& evt) -> void;
    auto OnOpenCircleImagesForCalculationBtn(wxCommandEvent& evt) -> void;

    auto OnOpenMeasuredSpectrumBtn(wxCommandEvent& evt) -> void;
    auto OnOpenFirstGainBtn(wxCommandEvent& evt) -> void;
    auto OnOpenSecondGainBtn(wxCommandEvent& evt) -> void;

    auto CheckIfImageIsCorrect
    (
        const std::string filePath, 
        const unsigned long long expectedSize,
        const int imageWidth,
        const int imageHeight
    ) -> bool;

    auto LoadData
    (
        const std::string filePath, 
        unsigned short* const pData, 
        const int imageWidth, 
        const int imageHeight
    ) -> bool;

    auto OnExitButtonClicked(wxCommandEvent& evt) -> void;

    auto GetPngFiles(const wxString& directory, wxArrayString& pngFiles) -> void
    {
        wxDir dir(directory);
        if (!dir.IsOpened())
        {
            wxLogError("Could not open directory: %s", directory);
            return;
        }

        wxString filename;
        bool cont = dir.GetFirst(&filename, "*.png", wxDIR_FILES);
        while (cont)
        {
            if (!filename.IsSameAs("logo.png", false)) // Exclude "logo.png" (case-insensitive)
            {
                pngFiles.Add(filename);
            }
            cont = dir.GetNext(&filename);
        }
    }

protected:
	wxString m_ReportGeneratorPath = wxGetCwd() + "\\src\\ReportGenerator\\"; // Gets current working directory
    // First Tab
    std::unique_ptr<wxTextCtrl> m_OpticsSerialNumberTxtCtrl{}, m_OpticsProductNumberTxtCtrl{}, m_OpticsTypeTxtCtrl{}, m_AuthorTxtCtrl{}, m_CustomerTxtCtrl{}, m_ReportNameTxtCtrl{};
    std::unique_ptr<wxTextCtrl> m_StartPositionTxtCtrl{}, m_StepTxtCtrl{}, m_FocusExposureTxtCtrl{}, m_CircleExposureTxtCtrl{};
    std::unique_ptr<wxChoice> m_OpticsSchemeChoice{};

    // Second Tab
    std::unique_ptr<wxChoice> m_ImgDataTypeChoice{};
    std::unique_ptr<wxTextCtrl> m_ImgWidthTxtCtrl{}, m_ImgHeightTxtCtrl{};

    // Original Black & White
    std::unique_ptr<wxTextCtrl> m_OriginalBlackImgPathTxtCtrl{}, m_OriginalWhiteImgPathTxtCtrl{};
    std::unique_ptr<wxBitmapButton> m_OpenOriginalBlackImgBtn{}, m_OpenOriginalWhiteImgBtn{};
    bool m_IsOriginalBlackImgToggled{}, m_IsOriginalWhiteImageToggled{};

    // Circle Black 
    std::unique_ptr<wxTextCtrl> m_CircleBlackImgPathTxtCtrl{};
    std::unique_ptr<wxBitmapButton> m_OpenCircleBlackImgBtn{};
    bool m_IsCircleBlackImgToggled{};

    // Third Tab
    std::unique_ptr<wxTextCtrl> m_ImagesForCalculationPaths{}, m_CircleImagesForCalculationPaths{};
    std::unique_ptr<wxBitmapButton> m_OpenImagesForCalculationBtn{}, m_OpenCircleImagesForCalculationBtn{};
    bool m_IsOpenImagesForCalculationToggled{}, m_IsOpenCircleImagesForCalculationToggled{};

    // X-ray test
    std::unique_ptr<wxTextCtrl> m_MeasuredSpectrumPath{}, m_FirstGainPath{}, m_SecondGainPath{};
    std::unique_ptr<wxBitmapButton> m_OpenMeasuredSpectrumBtn{}, m_OpenFirstGainBtn{}, m_OpenSecondGainBtn{};
    bool m_IsOpenMeasuredSpectrumToggled{}, m_IsOpenFirstGainToggled{}, m_IsOpenSecondGainToggled{};

    //bool m_IsOriginalBlackImageLoadedSucc{}, m_IsOriginalWhiteImageLoadedSucc{}, m_IsCircleBlackImageLoadedSucc{};

    //cv::Mat m_BlackImageMat{}, m_WhiteImageMat{};
    wxString m_OriginalBlackImagePath{}, m_OriginalWhiteImagePath{}, m_CircleBlackImagePath{};
    wxArrayString m_ImagesForCalculationPathsArray{}, m_CircleImagesForCalculationPathsArray{};

    wxImageList* m_imageList;

    std::unique_ptr<GenerateReportVariables::InputParameters> m_InputParameters{};


    wxDECLARE_EVENT_TABLE();

};
#endif // !CGENERATEREPORTDIALOG_H
