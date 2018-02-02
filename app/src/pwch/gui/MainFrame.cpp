#include "pwch\gui\MainFrame.h"
#include "pwch\gui\PWCH_IDS.h"

// constructor
MainFrame::MainFrame(const wxString& title, wxPoint& point, wxSize& size) 
	: wxFrame(NULL, wxID_ANY, title) {
	
#if wxUSE_MENUS

	wxMenu* fileM = new wxMenu;
	fileM->Append(MainFrame_fileM_About, "&About");
	fileM->Append(MainFrame_fileM_Quit, "&Quit\t Ctrl+Q");

	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(fileM, "&File");
	SetMenuBar(menuBar);

#endif
}

//**********************************************
//
// Event Handlers
//
//**********************************************
void MainFrame::OnAbout(wxCommandEvent& event) {
	wxString aboutMsg = "Password Check Manager - 2018";
	wxMessageBox(aboutMsg);
};

void MainFrame::OnQuit(wxCommandEvent& event) {
};