#include <pwch\gui\wxHeaders.h>

class LoginForm : public wxPanel {
public:
	LoginForm(wxWindow* parent, int ID);
	virtual ~LoginForm();

private:
	void OnSubmit(wxCommandEvent& evt);
};