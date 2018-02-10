#include <pwch\gui\wxHeaders.h>
#include <wx\notebook.h>

class CheckForm : public wxPanel {
public:
	CheckForm(wxWindow* parent, int ID);

private:
	void OnPageChange(wxCommandEvent& evt);
	void OnSubmit(wxCommandEvent& evt);
};