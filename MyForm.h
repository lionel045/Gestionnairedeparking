#pragma once
#ifndef Ma_co
#define Ma_co
#include "Auth.h"
#include <Windows.h>
#include "Parking.h"
#include "Senregister.h"
#include "Connexionbdd.h"
#include "FmyForm.h"


namespace Maco {
	//MYSQL* conn;


	
	


	//extern char choice;
	
	//extern MYSQL_ROW row = NULL;
	//extern MYSQL_RES* res, * rap = NULL;
	//extern int rapport;

	
	

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	
	public ref class MyForm : public System::Windows::Forms::Form
	{

		Form ^parking = gcnew  Parking();

	
		

	public:	System::String^ pseudo;
	public:	System::String^ password;
	public:	System::String^ recup;
	public: bool Var_Dauth;


		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtPseudo;
	private: System::Windows::Forms::Label^ lb_Pseudo;
	private: System::Windows::Forms::Label^ lb_pass;
	private: System::Windows::Forms::TextBox^ txt_Pass;
	private: System::Windows::Forms::Button^ btn_Con;
	private: System::Windows::Forms::Label^ lb_info;




	protected:


	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtPseudo = (gcnew System::Windows::Forms::TextBox());
			this->lb_Pseudo = (gcnew System::Windows::Forms::Label());
			this->lb_pass = (gcnew System::Windows::Forms::Label());
			this->txt_Pass = (gcnew System::Windows::Forms::TextBox());
			this->btn_Con = (gcnew System::Windows::Forms::Button());
			this->lb_info = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtPseudo
			// 
			this->txtPseudo->Location = System::Drawing::Point(84, 117);
			this->txtPseudo->Name = L"txtPseudo";
			this->txtPseudo->Size = System::Drawing::Size(100, 20);
			this->txtPseudo->TabIndex = 0;
			this->txtPseudo->TextChanged += gcnew System::EventHandler(this, &MyForm::txtPseudo_TextChanged);
			// 
			// lb_Pseudo
			// 
			this->lb_Pseudo->AutoSize = true;
			this->lb_Pseudo->Location = System::Drawing::Point(109, 101);
			this->lb_Pseudo->Name = L"lb_Pseudo";
			this->lb_Pseudo->Size = System::Drawing::Size(43, 13);
			this->lb_Pseudo->TabIndex = 1;
			this->lb_Pseudo->Text = L"Pseudo";
			this->lb_Pseudo->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// lb_pass
			// 
			this->lb_pass->AutoSize = true;
			this->lb_pass->Location = System::Drawing::Point(93, 162);
			this->lb_pass->Name = L"lb_pass";
			this->lb_pass->Size = System::Drawing::Size(71, 13);
			this->lb_pass->TabIndex = 2;
			this->lb_pass->Text = L"Mot de passe";
			// 
			// txt_Pass
			// 
			this->txt_Pass->Location = System::Drawing::Point(84, 178);
			this->txt_Pass->Name = L"txt_Pass";
			this->txt_Pass->Size = System::Drawing::Size(100, 20);
			this->txt_Pass->TabIndex = 3;
			this->txt_Pass->UseSystemPasswordChar = true;
			this->txt_Pass->TextChanged += gcnew System::EventHandler(this, &MyForm::txt_Pass_TextChanged);
			// 
			// btn_Con
			// 
			this->btn_Con->Location = System::Drawing::Point(96, 214);
			this->btn_Con->Name = L"btn_Con";
			this->btn_Con->Size = System::Drawing::Size(75, 23);
			this->btn_Con->TabIndex = 4;
			this->btn_Con->Text = L"Connexion";
			this->btn_Con->UseVisualStyleBackColor = true;
			this->btn_Con->Click += gcnew System::EventHandler(this, &MyForm::btn_Con_Click);
			// 
			// lb_info
			// 
			this->lb_info->AutoSize = true;
			this->lb_info->ForeColor = System::Drawing::Color::Black;
			this->lb_info->Location = System::Drawing::Point(93, 22);
			this->lb_info->Name = L"lb_info";
			this->lb_info->Size = System::Drawing::Size(0, 13);
			this->lb_info->TabIndex = 5;
			this->lb_info->Click += gcnew System::EventHandler(this, &MyForm::label1_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->lb_info);
			this->Controls->Add(this->btn_Con);
			this->Controls->Add(this->txt_Pass);
			this->Controls->Add(this->lb_pass);
			this->Controls->Add(this->lb_Pseudo);
			this->Controls->Add(this->txtPseudo);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {


		

		Authentification a;
		
	     bool con = 0;

		 bool local = true;
		 bool local2 = true;
		


		con = a.connexion();
		if (!con)
		{
			//lb_info->Text = "Ok ! ";
			
			lb_info->Text = "Vous n'avez pas pu vous connectez en base de donnee ";
		}
		

		

	
	}
	  
		 
		  
	


		 

		 





	
	private: System::Void lp_Pseudo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {


	}



	private: System::Void btn_Con_Click(System::Object^ sender, System::EventArgs^ e) {

	
	Authentification verif; // création d'un objet de type Authenfication
	pseudo = txtPseudo->Text; // La variable global pseudo prendra  la valeur la saisi de pseudo
	password = txt_Pass->Text; // La variable global password prendra la valeur de saisi du mots de passe 

	Var_Dauth = verif.seconnecter(pseudo, password);// utilisation d'une variable permettant de véfier si la requete est OK  

	bool SuperUser = verif.siUser(pseudo); // Variable qui permettra de verifier si l'utilisateur est un admin

	fmyform::premierValeur = txtPseudo->Text; // Appel d'une variable globale qu'on réeutilisera sur le formulaire de parking
		
	


		  if (Var_Dauth && !SuperUser) // Condition au cas où la requete est Ok et qu'il n'est pas admin
		  {
			
			  Parking^ parking = gcnew Parking();
				 fmyform::Admin = false; // La variable qu'on récupéra ne sera initialiser à faux
				 parking->Owner = this; // Propriete winform afin de préciser que le formulaire 
				fmyform::vide = true;					//parking appartient au formulaire  de connexion
				 // cela Cachera le formulaire lorsqu'il la condition sera respecté 
				this->Hide();
				 parking->ShowDialog();
				 
				  // Ouvre le prochain formulaire de parking 
		  }
			else  if (Var_Dauth && SuperUser) // Condition au cas où la requete est Ok et qu'il est admin
			  {
			  Parking^ parking = gcnew Parking();
			  fmyform::Admin = true; // La variable qu'on récupéra  sera initialiser à vrai
				  parking->Owner = this;
				  this->Hide();
				  parking->ShowDialog();
				
			  }
		  else 
		  {
			  lb_info->Text = "Authenfication incorrect"; // Si le mots de passe ne correspond a la condition
		  }

		  
		
 
		
		

	}
private: System::Void txtPseudo_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void txt_Pass_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
#endif
}
