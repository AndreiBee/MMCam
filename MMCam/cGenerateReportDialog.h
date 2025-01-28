#pragma once
#ifndef CGENERATEREPORTDIALOG_H
#define CGENERATEREPORTDIALOG_H

#include "wx/wx.h"
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
        // Second Tab
        ID_IMG_DATA_TYPE,
        ID_IMG_WIDTH,
        ID_IMG_HEIGHT,
        ID_LITTLE_ENDIAN_BYTE_ORDER_CHECK_BOX,
        ID_OPEN_BLACK_BTN,
        ID_OPEN_WHITE_BTN,
        ID_BLACK_PATH_TXT_CTRL,
        ID_WHITE_PATH_TXT_CTRL,
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
        double widthROIMM{};
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
    auto GetBlackImage() -> cv::Mat
    { 
        if (m_IsBlackImageLoadedSucc)
            return m_BlackImageMat;
        else
            return cv::Mat();
    };
    auto GetWhiteImage() -> cv::Mat
    {
        if (m_IsWhiteImageLoadedSucc)
            return m_WhiteImageMat;
        else
            return cv::Mat();
    };
    auto GetBlackImagePath() const -> wxString { return m_BlackImagePath; };
    auto GetWhiteImagePath() const -> wxString { return m_WhiteImagePath; };
    auto GetImagesForCalculationPaths() const -> wxArrayString { return m_ImagesForCalculationPathsArray; };

private:
    wxPanel* CreateReportVariablesPage(wxWindow* parent);
    wxPanel* CreateFlatFieldPage(wxWindow* parent);
    wxPanel* CreateInputImagesPage(wxWindow* parent);

    auto OnDataTypeChoice(wxCommandEvent& evt) -> void;
    auto OnOpenBlackImageBtn(wxCommandEvent& evt) -> void;
    auto OnOpenWhiteImageBtn(wxCommandEvent& evt) -> void;

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

protected:
    // First Tab
    std::unique_ptr<wxTextCtrl> m_OpticsSerialNumberTxtCtrl{}, m_OpticsProductNumberTxtCtrl{}, m_OpticsTypeTxtCtrl{}, m_AuthorTxtCtrl{}, m_CustomerTxtCtrl{}, m_ReportNameTxtCtrl{};
    std::unique_ptr<wxTextCtrl> m_StartPositionTxtCtrl{}, m_StepTxtCtrl{}, m_FocusExposureTxtCtrl{}, m_CircleExposureTxtCtrl{};

    // Second Tab
    std::unique_ptr<wxChoice> m_ImgDataTypeChoice{};
    std::unique_ptr<wxTextCtrl> m_ImgWidthTxtCtrl{}, m_ImgHeightTxtCtrl{};
    // Black & White
    std::unique_ptr<wxTextCtrl> m_BlackImgPathTxtCtrl{}, m_WhiteImgPathTxtCtrl{};
    std::unique_ptr<wxBitmapButton> m_OpenBlackImgBtn{}, m_OpenWhiteImgBtn{};
    bool m_IsBlackImgToggled{}, m_IsWhiteImageToggled{};

    // Third Tab
    std::unique_ptr<wxTextCtrl> m_ImagesForCalculationPaths{}, m_CircleImagesForCalculationPaths{};
    std::unique_ptr<wxBitmapButton> m_OpenImagesForCalculationBtn{}, m_OpenCircleImagesForCalculationBtn{};
    bool m_IsOpenImagesForCalculationToggled{}, m_IsOpenCircleImagesForCalculationToggled{};

    // X-ray test
    std::unique_ptr<wxTextCtrl> m_MeasuredSpectrumPath{}, m_FirstGainPath{}, m_SecondGainPath{};
    std::unique_ptr<wxBitmapButton> m_OpenMeasuredSpectrumBtn{}, m_OpenFirstGainBtn{}, m_OpenSecondGainBtn{};
    bool m_IsOpenMeasuredSpectrumToggled{}, m_IsOpenFirstGainToggled{}, m_IsOpenSecondGainToggled{};

    bool m_IsBlackImageLoadedSucc{}, m_IsWhiteImageLoadedSucc{};

    cv::Mat m_BlackImageMat{}, m_WhiteImageMat{};
    wxString m_BlackImagePath{}, m_WhiteImagePath{};
    wxArrayString m_ImagesForCalculationPathsArray{};

    wxImageList* m_imageList;

    std::unique_ptr<GenerateReportVariables::InputParameters> m_InputParameters{};


    wxDECLARE_EVENT_TABLE();

};
#endif // !CGENERATEREPORTDIALOG_H
