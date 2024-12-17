#include "wx/wx.h"
#include <string>

// Creer la fenetre
class MainFrame : public wxFrame {
private:
	// Labels
	wxStaticText* labelDe;
	wxStaticText* labelA;
	// Checklist
	wxChoice* choixDe;
	wxChoice* choixA;
	wxString value;
	wxDouble result;

public:
	MainFrame(const wxString& titre)
		: wxFrame(nullptr, wxID_ANY, titre) {
		SetSize(400, 550);
		// Layout vertical
		wxBoxSizer* sizer = new wxBoxSizer(
			wxVERTICAL
		);
		SetSizer(sizer);
		// Police d'ecriture
		wxFont fontLab(
			20,
			wxFONTFAMILY_DEFAULT,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_NORMAL
		);
		// Ajouter les labels
		labelDe = new wxStaticText(
			this, wxID_ANY, "0",
			wxPoint(100, 50),
			wxSize(200, 30)
		);
		labelA = new wxStaticText(
			this, wxID_ANY, "0",
			wxPoint(100, 150),
			wxSize(200, 30)
		);
		// Ajouter la Police aux labels
		labelDe->SetFont(fontLab);
		labelA->SetFont(fontLab);
		// Creation des options
		wxArrayString optionsDe;
		optionsDe.Add("Kelvin");
		optionsDe.Add("Celcuis");
		optionsDe.Add("Fahrenheit");

		wxArrayString optionsA;
		optionsA.Add("Kelvin");
		optionsA.Add("Celcuis");
		optionsA.Add("Fahrenheit");
		// Ajouter les choix au checklist
		choixDe = new wxChoice(
			this, wxID_ANY,
			wxPoint(100, 90),
			wxSize(200, 30),
			optionsDe
		);
		// Option par defaut
		choixDe->SetSelection(0);

		choixA = new wxChoice(
			this, wxID_ANY,
			wxPoint(100, 190),
			wxSize(200, 30),
			optionsA

		);
		// Option par defaut
		choixA->SetSelection(0);

		// Police d'ecriture des boutons
		wxFont fontBouton(
			16, wxFONTFAMILY_SWISS,
			wxFONTSTYLE_NORMAL,
			wxFONTWEIGHT_NORMAL
		);
		// Clavier numerique
		wxButton* bouton_e = new wxButton(
			this, 1010, "E", wxPoint(101, 229),
			wxSize(65, 50)
		);
		wxButton* bouton_ce = new wxButton(
			this, 1011, "CE", wxPoint(167, 229), 
			wxSize(65, 50));
		wxButton* bouton_0 = new wxButton(
			this, 1000, "0", wxPoint(233, 229),
			wxSize(65, 50));
		// Ajouter la police au boutons
		bouton_0->SetFont(fontBouton);
		bouton_e->SetFont(fontBouton);
		bouton_ce->SetFont(fontBouton);

		wxButton* bouton_9 = new wxButton(
			this, 1009, "9", wxPoint(101, 280), 
			wxSize(65, 50));
		wxButton* bouton_8 = new wxButton(
			this, 1008, "8", wxPoint(167, 280), 
			wxSize(65, 50));
		wxButton* bouton_7 = new wxButton(
			this, 1007, "7", wxPoint(233, 280),
			wxSize(65, 50));
		bouton_9->SetFont(fontBouton);
		bouton_8->SetFont(fontBouton);
		bouton_7->SetFont(fontBouton);

		wxButton* bouton_6 = new wxButton(
			this, 1006, "6", wxPoint(101, 331), 
			wxSize(65, 50));
		wxButton* bouton_5 = new wxButton(
			this, 1005, "5", wxPoint(167, 331), 
			wxSize(65, 50));
		wxButton* bouton_4 = new wxButton(
			this, 1004, "4", wxPoint(233, 331), 
			wxSize(65, 50));
		bouton_6->SetFont(fontBouton);
		bouton_5->SetFont(fontBouton);
		bouton_4->SetFont(fontBouton);

		wxButton* bouton_3 = new wxButton(
			this, 1003, "3", wxPoint(101, 382), 
			wxSize(65, 50));
		wxButton* bouton_2 = new wxButton(
			this, 1002, "2", wxPoint(167, 382), 
			wxSize(65, 50));
		wxButton* bouton_1 = new wxButton(
			this, 1001, "1", wxPoint(233, 382), 
			wxSize(65, 50));
		bouton_3->SetFont(fontBouton);
		bouton_2->SetFont(fontBouton);
		bouton_1->SetFont(fontBouton);

		// Connecter les boutons aux fonctions
		bouton_e->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1010);
		bouton_ce->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1011);
		bouton_0->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1000);
		bouton_1->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1001);
		bouton_2->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1002);
		bouton_3->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1003);
		bouton_4->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1004);
		bouton_5->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1005);
		bouton_6->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1006);
		bouton_7->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1007);
		bouton_8->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1008);
		bouton_9->Bind(wxEVT_BUTTON, [this]
		(wxCommandEvent& event) {
				OnClic(event);
				checker(event);
			}, 1009);

		// Connecter les listes de choix
		choixDe->Bind(wxEVT_CHOICE, [this]
		(wxCommandEvent& event) {
				checker(event);
			}, choixDe->GetId()
		);
		choixA->Bind(wxEVT_CHOICE, [this]
		(wxCommandEvent& event) {
				checker(event);
			}, choixA->GetId());

	}
	// Fonction qui permet d'ecrire dans les label
	void OnClic(wxCommandEvent& event) {
		wxButton* bouton;
		bouton = dynamic_cast<wxButton*>(
			event.GetEventObject()
			);
		switch (bouton->GetId()) {
		case 1011:
			value = "0";
			labelDe->SetLabelText(value);
			break;
		case 1010:
			if (value.length() > 1) {
				value = value.RemoveLast();
			}
			else {
				value = "0";
			}
			labelDe->SetLabelText(value);
			break;
		default:
			if (value == "0") {
				value = "";
			}
			value = value + bouton->GetLabelText();
			labelDe->SetLabelText(value);
		}
	}
	// Fonction pour effectuer automatiquement
	// la conversion lorsqu'on change l'option
	// du wxChoice
	void checker(wxCommandEvent& event) {
		int d = choixDe->GetCurrentSelection();
		int a = choixA->GetCurrentSelection();

		wxString label_de = labelDe->GetLabel();
		wxString label_a = labelA->GetLabel();
		double value_de;
		double value_a;

		// Convertire en double les labels
		label_de.ToDouble(&value_de);
		label_a.ToDouble(&value_a);

		// Controler les conversions
		if (choixDe->GetString(d) == "Celcuis" &&
			choixA->GetString(a) == "Kelvin") {
			value_a = value_de + 273.15;
		}
		else if (choixDe->GetString(d) == "Celcuis" &&
			choixA->GetString(a) == "Fahrenheit") {
			value_a = (value_de * 1.8) + 32;
		}
		else if (choixDe->GetCurrentSelection() ==
			choixA->GetCurrentSelection()) {
			value_a = value_de;
		}
		else {
			wxString conversion = choixDe->GetString(d)
				+ " -> " + choixA->GetString(a);
			wxMessageBox("Conversion \n\n" + conversion
				+ "\npas encore disponible !",
				"Information");
		}
		result = value_a;
		labelA->SetLabelText(
			wxString::Format("%.1f", result));
	}

};

// Creer l'appli.
class App : public wxApp {
public:
	bool OnInit();
};
// Implemente OnInit()
bool App::OnInit() {
	const wxString titre = "Convertisseur";
	MainFrame* mainFrame = new MainFrame(titre);
	mainFrame->Show();
	return true;
}
// Lance l'appli
wxIMPLEMENT_APP(App);
