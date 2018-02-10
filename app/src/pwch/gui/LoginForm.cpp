#include <pwch\gui\LoginForm.h>
#include <pwch\gui\PWCH_IDS.h>
#include <pwch\gui\PWCH_Sizing.h>
#include <pwch\gui\Utils.h>
#include <pwch\gui\PWCH_Colors.h>
#include <pwch\gui\CheckForm.h>

LoginForm::LoginForm(wxWindow* parent, int ID) 
	: wxPanel(parent, ID,
		wxPoint(PWCH_centerX, PWCH_centerY),
		wxSize(PWCH_mainWidth, PWCH_mainHeight)) {

	wxBoxSizer* vBox = new wxBoxSizer(wxVERTICAL);

	vBox->Add(Utils::createEmptyRow(this, 10));
	vBox->Add(Utils::createLabelBox(this, "username"));
	vBox->Add(Utils::createInputBox(this, Auth_username_input));
	vBox->Add(Utils::createEmptyRow(this, 10));
	vBox->Add(Utils::createLabelBox(this, "password"));
	vBox->Add(Utils::createInputBox(this, Auth_password_input, true));
	vBox->Add(Utils::createEmptyRow(this, 10));
	vBox->Add(Utils::createButton(this, Auth_loginBtn, "submit"));
	SetSizer(vBox);

	Connect(Auth_loginBtn, wxEVT_COMMAND_BUTTON_CLICKED, 
		wxCommandEventHandler(LoginForm::OnSubmit));
};

void LoginForm::OnSubmit(wxCommandEvent& WXUNUSED(evt)) {
	wxTextCtrl* userBox = (wxTextCtrl*)Utils::GetChildById(this, Auth_username_input);
	wxTextCtrl* pwBox = (wxTextCtrl*)Utils::GetChildById(this, Auth_password_input);

	if ("admin" != userBox->GetValue()) {
		wxMessageBox(wxString("Unknown user: ").Append(userBox->GetValue()));
	}
	else if ("admin" != pwBox->GetValue()) {
		wxMessageBox(wxString("Invalid credentials for user: ").Append(userBox->GetValue()));
	}
	else {
		Show(false);
		CheckForm* mainForm = new CheckForm(GetParent(), Check_panel);
	}
};

LoginForm::~LoginForm() {};