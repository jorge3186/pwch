#include <pwch/gui/PwchApp.h>
#include <pwch/gui/MainFrame.h>
#include <pwch/gui/PWCH_Sizing.h>

bool PwchApp::OnInit() {

	if (!wxApp::OnInit()) {
		return false;
	}

	MainFrame *frame = new MainFrame("Password Check Manager");
	frame->Show(true);
	return true;
};