#include <pwch\gui\Utils.h>
#include <pwch\gui\PWCH_Sizing.h>
#include <pwch\gui\PWCH_Colors.h>

wxBoxSizer* Utils::createLabelBox(wxWindow* parent, const wxString& text) {
	wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* lbl = new wxStaticText(parent, wxID_ANY, text, 
		wxDefaultPosition, wxSize(PWCH_mainWidth, 40), wxTE_CENTER);
	box->Add(lbl, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 20);
	return box;
}

wxBoxSizer* Utils::createInputBox(wxWindow* parent, int ID, bool password) {
	auto validators = password ? wxTE_CENTER | wxTE_PASSWORD : wxTE_CENTER;
	wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);
	wxTextCtrl* text = new wxTextCtrl(parent, ID, wxEmptyString,
		wxDefaultPosition, wxSize(PWCH_mainWidth, 40), validators);

	box->Add(text, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 20);
	return box;
}

wxBoxSizer* Utils::createButton(wxWindow* parent, int ID, const wxString& text) {
	wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);
	wxButton* btn = new wxButton(parent, ID, text, wxDefaultPosition,
		wxSize(PWCH_mainWidth, 80));
	box->Add(btn, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 20);
	return box;
}

wxBoxSizer* Utils::createEmptyRow(wxWindow* parent, int space) {
	wxBoxSizer* box = new wxBoxSizer(wxHORIZONTAL);
	wxStaticText* empty = new wxStaticText(parent, wxID_ANY, " ");
	empty->SetFont(wxFont(space, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
	box->Add(empty, 0, wxALIGN_CENTER | wxLEFT | wxRIGHT, 20);
	return box;
}

wxWindow* Utils::GetChildById(wxWindow* window, int ID) {
	for (auto child : window->GetWindowChildren()) {
		if (ID == child->GetId()) {
			return child;
		}
	}
	return NULL;
}