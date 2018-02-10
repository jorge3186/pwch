#include <pwch\gui\MainFrame.h>
#include <pwch\gui\PWCH_Sizing.h>
#include <pwch\gui\PWCH_IDS.h>
#include <pwch\gui\LoginForm.h>
#include <pwch\gui\PWCH_Colors.h>

// constructor
MainFrame::MainFrame(const wxString& title) 
	: wxFrame(NULL, wxID_ANY, title,
		wxPoint(PWCH_centerX, PWCH_centerY),
		wxSize(PWCH_mainWidth, PWCH_mainHeight)) {
	
#if wxUSE_MENUS
	wxMenu* fileM = new wxMenu;
	fileM->Append(MainFrame_fileM_About, ("About\tCtrl-A"));
	Connect(MainFrame_fileM_About, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(MainFrame::OnAbout));

	fileM->Append(MainFrame_fileM_Quit, _("Quit\tCtrl-Q"));
	Connect(MainFrame_fileM_Quit, wxEVT_COMMAND_MENU_SELECTED,
		wxCommandEventHandler(MainFrame::OnQuit));

	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(fileM, "&File");
	SetMenuBar(menuBar);
#endif

	// Login Form
	LoginForm* loginForm = new LoginForm(this, Auth_panel);
}

//**********************************************
// MainFrame - 
// Event Handlers
//
//**********************************************
void MainFrame::OnAbout(wxCommandEvent& WXUNUSED(event)) {
	wxString aboutMsg = "Password Check Manager\n Another J-Dawg Productions - 2018";
	wxMessageBox(aboutMsg);
};

void MainFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
	Close(true);
};