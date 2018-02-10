#include <pwch\gui\CheckForm.h>
#include <pwch\gui\PWCH_Sizing.h>
#include <pwch\gui\Utils.h>
#include <pwch\gui\PWCH_IDS.h>

CheckForm::CheckForm(wxWindow* parent, int ID)
	: wxPanel(parent, ID,
		wxPoint(PWCH_centerX, PWCH_centerY),
		wxSize(PWCH_mainWidth, PWCH_mainHeight)) {

	wxBoxSizer* vBox = new wxBoxSizer(wxVERTICAL);
	wxBoxSizer* hBox = new wxBoxSizer(wxHORIZONTAL);

	auto nb = new wxNotebook(this, Check_panel, GetPosition(), GetSize());

	wxPanel* tab1 = new wxPanel(nb, Check_tab1, wxDefaultPosition, this->GetSize());
	auto vBox_tab1 = new wxBoxSizer(wxVERTICAL);
	vBox_tab1->Add(Utils::createLabelBox(tab1, "Tab1 Text"));
	tab1->SetSizer(vBox_tab1);
	nb->AddPage(tab1, "Check");

	wxPanel* tab2 = new wxPanel(nb, Check_tab2, wxDefaultPosition, this->GetSize());
	auto vBox_tab2 = new wxBoxSizer(wxVERTICAL);
	vBox_tab2->Add(Utils::createLabelBox(tab2, "Tab2 Hello"));
	tab2->SetSizer(vBox_tab2);
	nb->AddPage(tab2, "Insert");

	hBox->Add(nb, 0, wxEXPAND, 20);
	vBox->Add(nb, 0, wxEXPAND, 20);
	SetSizer(hBox);
	Center();
}