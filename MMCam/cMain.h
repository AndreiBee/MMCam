#pragma once
#ifndef CMAIN_H
#define CMAIN_H

#include "wx/wx.h"

#include <string>

class cMain final : public wxFrame
{
public:
	cMain(const wxString& title_);

private:

	wxDECLARE_EVENT_TABLE();
};

#endif // !CMAIN_H

