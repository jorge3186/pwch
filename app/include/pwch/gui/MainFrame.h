#include "wx/wxprec.h"

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

//*************************************************
// 
// Main Frame for PWCH Application.
//
//*************************************************
class MainFrame : public wxFrame {
public:
	//constructor
	MainFrame(const wxString& title, wxPoint& point, wxSize& size);

private:
	// event functions
	void OnAbout(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);

	wxDECLARE_EVENT_TABLE();
};