#pragma once 

#ifndef parking_DEF
#define parking_DEF

#include "Senregister.h"
#include "fmyform.h"
#include "user.h"
#include "Creationplaceuser.h"
#include "Connexionbdd.h"
#include "Parkingbdd.h"	
namespace Maco {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace Data::SqlClient;
	using namespace System::Drawing;
	using namespace System::Configuration;
		/// <summary>
	/// Description résumée de Parking
	/// </summary>
     
	public ref class Parking : public System::Windows::Forms::Form
	{

	

	public:  String^ userid{  };
	public:	  String^ recupererid{};
	private: System::Windows::Forms::Button^ btn_reservation;
	private: System::Windows::Forms::LinkLabel^ LinkDeco;
	public:	System::String^ pseudoco;
	private: System::Windows::Forms::Button^ btn_Free;
	private: System::Windows::Forms::Button^ btn_Ajout;

	public: bool admin;
	private: System::Windows::Forms::Label^ lb_resultat;








	private: System::Windows::Forms::Label^ lb_row;
	private: System::Windows::Forms::ComboBox^ Placecombo;
	private: System::Windows::Forms::Label^ lb_parking;
	private: System::Windows::Forms::Label^ lb_reservation;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ lb_plaque;

	private: System::Windows::Forms::TextBox^ textbox_vehicule;










	
	public:String^ recupererIDplace;
	public:	System::String^ deco;
	public:String^ element = "";
	public:String^ check;
	private: System::Windows::Forms::Timer^ timer1;
	public:	int currentime = 0;
	private: System::Windows::Forms::Button^ btn_nouvelleplace;

	private: System::Windows::Forms::Label^ lb_infosuppPlace;
	private: System::Windows::Forms::Label^ lb_info;

	public:


	public: String^ dejareserver;
 

		Parking(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~Parking()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::GroupBox^ GB_Co;
	private: System::Windows::Forms::Label^ lb_message;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lb_pseudoCo;
	private: System::ComponentModel::IContainer^ components;








	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->GB_Co = (gcnew System::Windows::Forms::GroupBox());
			this->btn_nouvelleplace = (gcnew System::Windows::Forms::Button());
			this->btn_Ajout = (gcnew System::Windows::Forms::Button());
			this->lb_reservation = (gcnew System::Windows::Forms::Label());
			this->LinkDeco = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lb_pseudoCo = (gcnew System::Windows::Forms::Label());
			this->lb_message = (gcnew System::Windows::Forms::Label());
			this->btn_reservation = (gcnew System::Windows::Forms::Button());
			this->btn_Free = (gcnew System::Windows::Forms::Button());
			this->lb_resultat = (gcnew System::Windows::Forms::Label());
			this->lb_row = (gcnew System::Windows::Forms::Label());
			this->Placecombo = (gcnew System::Windows::Forms::ComboBox());
			this->lb_parking = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->lb_plaque = (gcnew System::Windows::Forms::Label());
			this->textbox_vehicule = (gcnew System::Windows::Forms::TextBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lb_infosuppPlace = (gcnew System::Windows::Forms::Label());
			this->lb_info = (gcnew System::Windows::Forms::Label());
			this->GB_Co->SuspendLayout();
			this->SuspendLayout();
			// 
			// GB_Co
			// 
			this->GB_Co->Controls->Add(this->btn_nouvelleplace);
			this->GB_Co->Controls->Add(this->btn_Ajout);
			this->GB_Co->Controls->Add(this->lb_reservation);
			this->GB_Co->Controls->Add(this->LinkDeco);
			this->GB_Co->Controls->Add(this->label1);
			this->GB_Co->Controls->Add(this->lb_pseudoCo);
			this->GB_Co->Controls->Add(this->lb_message);
			this->GB_Co->Location = System::Drawing::Point(18, 18);
			this->GB_Co->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->GB_Co->Name = L"GB_Co";
			this->GB_Co->Padding = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->GB_Co->Size = System::Drawing::Size(423, 363);
			this->GB_Co->TabIndex = 1;
			this->GB_Co->TabStop = false;
			this->GB_Co->Enter += gcnew System::EventHandler(this, &Parking::GB_Co_Enter);
			// 
			// btn_nouvelleplace
			// 
			this->btn_nouvelleplace->Location = System::Drawing::Point(0, 238);
			this->btn_nouvelleplace->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_nouvelleplace->Name = L"btn_nouvelleplace";
			this->btn_nouvelleplace->Size = System::Drawing::Size(190, 35);
			this->btn_nouvelleplace->TabIndex = 18;
			this->btn_nouvelleplace->Text = L"Crée de nouvelle place";
			this->btn_nouvelleplace->UseVisualStyleBackColor = true;
			this->btn_nouvelleplace->Click += gcnew System::EventHandler(this, &Parking::btn_nouvelleplace_Click);
			// 
			// btn_Ajout
			// 
			this->btn_Ajout->Location = System::Drawing::Point(231, 236);
			this->btn_Ajout->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_Ajout->Name = L"btn_Ajout";
			this->btn_Ajout->Size = System::Drawing::Size(166, 38);
			this->btn_Ajout->TabIndex = 4;
			this->btn_Ajout->Text = L"Ajouter un utilisateur";
			this->btn_Ajout->UseVisualStyleBackColor = true;
			this->btn_Ajout->Click += gcnew System::EventHandler(this, &Parking::button1_Click);
			// 
			// lb_reservation
			// 
			this->lb_reservation->AutoSize = true;
			this->lb_reservation->Location = System::Drawing::Point(9, 78);
			this->lb_reservation->Name = L"lb_reservation";
			this->lb_reservation->Size = System::Drawing::Size(0, 20);
			this->lb_reservation->TabIndex = 17;
			// 
			// LinkDeco
			// 
			this->LinkDeco->AutoSize = true;
			this->LinkDeco->Location = System::Drawing::Point(252, 25);
			this->LinkDeco->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->LinkDeco->Name = L"LinkDeco";
			this->LinkDeco->Size = System::Drawing::Size(102, 20);
			this->LinkDeco->TabIndex = 3;
			this->LinkDeco->TabStop = true;
			this->LinkDeco->Text = L"Deconnexion";
			this->LinkDeco->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Parking::LinkDeco_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(9, 103);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Vous etes connecter";
			this->label1->Click += gcnew System::EventHandler(this, &Parking::label1_Click);
			// 
			// lb_pseudoCo
			// 
			this->lb_pseudoCo->AutoSize = true;
			this->lb_pseudoCo->Location = System::Drawing::Point(130, 25);
			this->lb_pseudoCo->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lb_pseudoCo->Name = L"lb_pseudoCo";
			this->lb_pseudoCo->Size = System::Drawing::Size(63, 20);
			this->lb_pseudoCo->TabIndex = 1;
			this->lb_pseudoCo->Text = L"Pseudo";
			this->lb_pseudoCo->Click += gcnew System::EventHandler(this, &Parking::lb_pseudoCo_Click);
			// 
			// lb_message
			// 
			this->lb_message->AutoSize = true;
			this->lb_message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_message->Location = System::Drawing::Point(0, 25);
			this->lb_message->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lb_message->Name = L"lb_message";
			this->lb_message->Size = System::Drawing::Size(108, 20);
			this->lb_message->TabIndex = 0;
			this->lb_message->Tag = L"";
			this->lb_message->Text = L"Bienvenue :";
			this->lb_message->Click += gcnew System::EventHandler(this, &Parking::lb_message_Click);
			// 
			// btn_reservation
			// 
			this->btn_reservation->Location = System::Drawing::Point(470, 336);
			this->btn_reservation->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_reservation->Name = L"btn_reservation";
			this->btn_reservation->Size = System::Drawing::Size(112, 35);
			this->btn_reservation->TabIndex = 8;
			this->btn_reservation->Text = L"Reserver";
			this->btn_reservation->UseVisualStyleBackColor = true;
			this->btn_reservation->Click += gcnew System::EventHandler(this, &Parking::btn_reservation_Click);
			// 
			// btn_Free
			// 
			this->btn_Free->Location = System::Drawing::Point(630, 336);
			this->btn_Free->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btn_Free->Name = L"btn_Free";
			this->btn_Free->Size = System::Drawing::Size(120, 35);
			this->btn_Free->TabIndex = 9;
			this->btn_Free->Text = L"Liberer";
			this->btn_Free->UseVisualStyleBackColor = true;
			this->btn_Free->Click += gcnew System::EventHandler(this, &Parking::btn_Free_Click);
			// 
			// lb_resultat
			// 
			this->lb_resultat->AutoSize = true;
			this->lb_resultat->Location = System::Drawing::Point(520, 43);
			this->lb_resultat->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lb_resultat->Name = L"lb_resultat";
			this->lb_resultat->Size = System::Drawing::Size(0, 20);
			this->lb_resultat->TabIndex = 10;
			// 
			// lb_row
			// 
			this->lb_row->AutoSize = true;
			this->lb_row->Location = System::Drawing::Point(922, 106);
			this->lb_row->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lb_row->Name = L"lb_row";
			this->lb_row->Size = System::Drawing::Size(0, 20);
			this->lb_row->TabIndex = 14;
			// 
			// Placecombo
			// 
			this->Placecombo->FormattingEnabled = true;
			this->Placecombo->Location = System::Drawing::Point(470, 157);
			this->Placecombo->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Placecombo->Name = L"Placecombo";
			this->Placecombo->Size = System::Drawing::Size(180, 28);
			this->Placecombo->TabIndex = 15;
			this->Placecombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Parking::comboBox1_SelectedIndexChanged);
			// 
			// lb_parking
			// 
			this->lb_parking->AutoSize = true;
			this->lb_parking->Location = System::Drawing::Point(448, 97);
			this->lb_parking->Name = L"lb_parking";
			this->lb_parking->Size = System::Drawing::Size(252, 20);
			this->lb_parking->TabIndex = 16;
			this->lb_parking->Text = L"Selectionnez une place de parking";
			this->lb_parking->Click += gcnew System::EventHandler(this, &Parking::lb_parking_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(542, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 20);
			this->label3->TabIndex = 18;
			// 
			// lb_plaque
			// 
			this->lb_plaque->AutoSize = true;
			this->lb_plaque->Location = System::Drawing::Point(448, 219);
			this->lb_plaque->Name = L"lb_plaque";
			this->lb_plaque->Size = System::Drawing::Size(290, 20);
			this->lb_plaque->TabIndex = 19;
			this->lb_plaque->Text = L"Saisissez votre Plaque d\'immatriculation";
			this->lb_plaque->Click += gcnew System::EventHandler(this, &Parking::lb_plaque_Click);
			// 
			// textbox_vehicule
			// 
			this->textbox_vehicule->HideSelection = false;
			this->textbox_vehicule->Location = System::Drawing::Point(476, 262);
			this->textbox_vehicule->Name = L"textbox_vehicule";
			this->textbox_vehicule->Size = System::Drawing::Size(174, 26);
			this->textbox_vehicule->TabIndex = 20;
			this->textbox_vehicule->TextChanged += gcnew System::EventHandler(this, &Parking::textbox_vehicule_TextChanged);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Parking::timer1_Tick);
			// 
			// lb_infosuppPlace
			// 
			this->lb_infosuppPlace->AutoSize = true;
			this->lb_infosuppPlace->Location = System::Drawing::Point(485, 52);
			this->lb_infosuppPlace->Name = L"lb_infosuppPlace";
			this->lb_infosuppPlace->Size = System::Drawing::Size(0, 20);
			this->lb_infosuppPlace->TabIndex = 22;
			this->lb_infosuppPlace->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// lb_info
			// 
			this->lb_info->AutoSize = true;
			this->lb_info->Location = System::Drawing::Point(742, 145);
			this->lb_info->Name = L"lb_info";
			this->lb_info->Size = System::Drawing::Size(0, 20);
			this->lb_info->TabIndex = 23;
			// 
			// Parking
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(870, 446);
			this->Controls->Add(this->lb_info);
			this->Controls->Add(this->lb_infosuppPlace);
			this->Controls->Add(this->textbox_vehicule);
			this->Controls->Add(this->lb_plaque);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->lb_parking);
			this->Controls->Add(this->Placecombo);
			this->Controls->Add(this->lb_row);
			this->Controls->Add(this->lb_resultat);
			this->Controls->Add(this->btn_Free);
			this->Controls->Add(this->btn_reservation);
			this->Controls->Add(this->GB_Co);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Parking";
			this->Text = L"Parking";
			this->Load += gcnew System::EventHandler(this, &Parking::Parking_Load);
			this->GB_Co->ResumeLayout(false);
			this->GB_Co->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



			bool SIvideounon()
		{
				bool vide;

				if (String::IsNullOrEmpty(textbox_vehicule->Text))

				{			
					vide = true;
				}
				else
				{
					vide = false;
				}
			

				return vide;
		}

			

			  public: bool fermeture() 
			  {
				  Parking^ parking = gcnew Parking();
				  bool recup = true;
				 
				  this->Close();
				  return recup;
			  }

			  public: bool refresh()
			  {
				 // Parking^ parking = gcnew Parking();

				  bool recup = true;
				  this->Refresh();
				  return recup;
			  }



	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	}
	private: System::Void lb_message_Click(System::Object^ sender, System::EventArgs^ e) {

		

		
	
	}
	private: System::Void GB_Co_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lb_pseudoCo_Click(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void Parking_Load(System::Object^ sender, System::EventArgs^ e) {


		
		Parkingbdd placearecuper;

      List<String^>^ VarRecuperer = placearecuper.RecupeRerALLPlace();

	
  for (int i = 0; i < VarRecuperer->Count; i++)
	  {
			
	   Placecombo->Items->Add(VarRecuperer[i]);
  }




	

		Authentification free;
		admin = fmyform::Admin;

		lb_pseudoCo->Text = fmyform::premierValeur;
		recupererid = free.idUsers(fmyform::premierValeur);
		bool result = free.reserver(recupererid);
	
		if (result)
		{
			lb_reservation->Text = "Vous posséder déjà une place "; 
			Placecombo->Enabled = false;
			btn_reservation->Enabled = false;
			textbox_vehicule->Enabled = false;
		}	
		else
		{
			Placecombo->Enabled = true;

			textbox_vehicule->Enabled = true;
		}




		if (admin == true) // Verifie si l'utilisateur est de type administrateur si il est admin il aura plus de bouton
		{
			
			btn_Ajout->Show();
			btn_Free->Show();
		//	btn_Deleteplace->Show();
	
		}
		else // Si il est utilisateur les boutons lui seront caché
		{
			btn_nouvelleplace->Hide();
			btn_Ajout->Hide();	
			//btn_Deleteplace->Hide();
		}
	}



	private: System::Void btn_reservation_Click(System::Object^ sender, System::EventArgs^ e) { // code representant l'action de 
																								//réservation

			Parkingbdd ab;

			Authentification a;

			String^ immatriculation = textbox_vehicule->Text; // Creation d'une variable qui recupera l'immatriculation de l'utilisateur

  element = this->Placecombo->GetItemText(this->Placecombo->SelectedItem); // Constante qui récupera la valeur 
																			  //lorsque  l'utilisateur aura réserver une place
	
	recupererIDplace = ab.recupererplace(element); // Récupère l'id de place sélectionner
		

			recupererid = a.idUsers(fmyform::premierValeur); // Recupere l'id de l'utilisateur

			bool immatriculevide = SIvideounon(); // Vérifie si l'on saisi une plaque d'immatriculation
											 // n'a rentré des information en base de donnée

			check = ab.Dejaprise(recupererIDplace, recupererid,immatriculation); // Recupere les paramètre de la méthode

		if (recupererIDplace && immatriculevide == false) // Si l'a place est bien selectionner  
													  //et la plaque d'immatriculation n'est pas vide 
		{										
			if (check == "0") // Verifie si n'y pas d'utilisateur 
			{
				a.Saisiimmac(immatriculation, recupererid); // Recupère la plaque d'immatriculation en bdd

				int querystate = ab.AjouteraHistoriqueArrive(recupererid, recupererIDplace);
				if (querystate == 0)
				{

					lb_info->Text = "Ajout reussi" + recupererid;
				}
				else
				{
					lb_info->Text = "Echec de la methode" + recupererIDplace;
				}
	       	lb_reservation->Text = "Vous avez réservé la place " + element; // Récupère la place réserver

				if (Placecombo->SelectedItem == element) //Une fois qu'il la réserver l'utilisateur ne peut plus réserver de place
				{
					Placecombo->Enabled = false;
					btn_reservation->Enabled = false;
					textbox_vehicule->Enabled = false;
				}
			}
			else
			{

				MessageBox::Show("La place deja prise"); // Si check n'est pas = 0 cela signifie qu'il est déjà attribuer
			}
		}
			else
			{			
			MessageBox::Show("Veuillez saisir une valeur dans le champ d'immatriculation");
			}
		
	}
	
	  
private: System::Void LinkDeco_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	
	admin = false; // On remet le boolean à faux afin de pas generez d'erreur
	this->Owner->Show();
	lb_pseudoCo->Text = " ";
	recupererid = "0"; 

	fermeture();
	


}
private: System::Void btn_Free_Click(System::Object^ sender, System::EventArgs^ e) {

	Parkingbdd a;
	a.AjoutHistoriqueSortie(recupererIDplace);
	a.renitialiserplace(recupererIDplace,recupererid); // Renitialise la place de parking et renvoie la table à null
	recupererIDplace = "";
	Placecombo->Enabled = true; // Déverouille la selection de la place afin que l'utilisateur puisse à nous réserver une place
	textbox_vehicule->Enabled = true; 
	lb_reservation->Text = " ";
	btn_reservation->Enabled = true;
	textbox_vehicule->Text = "";
	lb_resultat->Text = " ";

}
	   
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	user a;
	
	a.Owner = this;


	a.ShowDialog();





}

private: System::Void Tablededonée_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	


	Placecombo->Items->Add("0");
}

private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void textbox_vehicule_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	
}
public: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

	
	
}
	   



private: System::Void lb_parking_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btn_nouvelleplace_Click(System::Object^ sender, System::EventArgs^ e) {

	Creationplaceuser ^creation = gcnew Creationplaceuser;

	creation->Owner = this;

	creation->ShowDialog();

	

}
private: System::Void lb_plaque_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {

	Parkingbdd Varbdd;
	String ^ element = this->Placecombo->GetItemText(this->Placecombo->SelectedItem);
	
	String^ idplace = Varbdd.recupererplace(element);
	bool verification = Varbdd.Supprimerplace(idplace);

		 if (verification == true)
		 {
			 lb_infosuppPlace->Text = "Execution reussite";
		 }
		 else
		 {
			 lb_infosuppPlace->Text = "Execution echouer" + " " + element;
		 }
	       

}
};
#endif 

}


