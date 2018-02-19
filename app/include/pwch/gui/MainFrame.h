#include <pwch/gui/wxHeaders.h>

//*************************************************
// 
// Main Frame for PWCH Application.
//
//*************************************************
class MainFrame : public wxFrame {
public:
	//constructor
	MainFrame(const wxString& title);

private:
	// event functions
	void OnAbout(wxCommandEvent& event);
	void OnQuit(wxCommandEvent& event);
};