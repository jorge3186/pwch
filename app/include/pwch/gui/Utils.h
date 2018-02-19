#include <pwch/gui/wxHeaders.h>

class Utils {
public:
	static wxBoxSizer* createLabelBox(wxWindow* parent, const wxString& text);
	static wxBoxSizer* createInputBox(wxWindow* parent, int ID = wxID_ANY, bool password = false);
	static wxBoxSizer* createButton(wxWindow* parent, int ID, const wxString& text);
	static wxBoxSizer* createEmptyRow(wxWindow* parent, int space=40);

	static wxWindow* GetChildById(wxWindow* window, int ID);
};