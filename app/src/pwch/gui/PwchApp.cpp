#include "pwch\gui\PwchApp.h"
#include "pwch\gui\MainFrame.h"

bool PwchApp::OnInit() {

	if (!wxApp::OnInit()) {
		return false;
	}

	MainFrame *frame = new MainFrame("Password Check Manager", wxPoint(50, 50), wxSize(750, 500));
	frame->Show(true);

	return true;
};