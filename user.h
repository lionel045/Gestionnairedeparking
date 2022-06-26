#pragma once
#include "Auth.h"
#include "Connexionbdd.h"
#include "Senregister.h"
namespace Maco {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Description résumée de user
	/// </summary>
	public ref class user : public System::Windows::Forms::Form
	{
	public:
		user(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}
	public :
		String^ pseudo;
		
		
		String^ pass;
	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~user()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_validation;
	private: System::Windows::Forms::TextBox^ txtbox_pseudo;
	private: System::Windows::Forms::TextBox^ txtbox_pass;


	private: System::Windows::Forms::Label^ lb_pseudo;
	private: System::Windows::Forms::Label^ lb_pass;
	private: System::Windows::Forms::Label^ lb_info;
	protected:

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
			this->btn_validation = (gcnew System::Windows::Forms::Button());
			this->txtbox_pseudo = (gcnew System::Windows::Forms::TextBox());
			this->txtbox_pass = (gcnew System::Windows::Forms::TextBox());
			this->lb_pseudo = (gcnew System::Windows::Forms::Label());
			this->lb_pass = (gcnew System::Windows::Forms::Label());
			this->lb_info = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_validation
			// 
			this->btn_validation->Location = System::Drawing::Point(78, 122);
			this->btn_validation->Margin = System::Windows::Forms::Padding(2);
			this->btn_validation->Name = L"btn_validation";
			this->btn_validation->Size = System::Drawing::Size(50, 29);
			this->btn_validation->TabIndex = 0;
			this->btn_validation->Text = L"Valider";
			this->btn_validation->UseVisualStyleBackColor = true;
			this->btn_validation->Click += gcnew System::EventHandler(this, &user::btn_validation_Click);
			// 
			// txtbox_pseudo
			// 
			this->txtbox_pseudo->Location = System::Drawing::Point(71, 44);
			this->txtbox_pseudo->Margin = System::Windows::Forms::Padding(2);
			this->txtbox_pseudo->Name = L"txtbox_pseudo";
			this->txtbox_pseudo->Size = System::Drawing::Size(68, 20);
			this->txtbox_pseudo->TabIndex = 1;
			this->txtbox_pseudo->TextChanged += gcnew System::EventHandler(this, &user::textBox1_TextChanged);
			// 
			// txtbox_pass
			// 
			this->txtbox_pass->Location = System::Drawing::Point(71, 101);
			this->txtbox_pass->Margin = System::Windows::Forms::Padding(2);
			this->txtbox_pass->Name = L"txtbox_pass";
			this->txtbox_pass->Size = System::Drawing::Size(68, 20);
			this->txtbox_pass->TabIndex = 2;
			this->txtbox_pass->UseSystemPasswordChar = true;
			this->txtbox_pass->TextChanged += gcnew System::EventHandler(this, &user::txtbox_pass_TextChanged);
			// 
			// lb_pseudo
			// 
			this->lb_pseudo->AutoSize = true;
			this->lb_pseudo->Location = System::Drawing::Point(84, 16);
			this->lb_pseudo->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lb_pseudo->Name = L"lb_pseudo";
			this->lb_pseudo->Size = System::Drawing::Size(43, 13);
			this->lb_pseudo->TabIndex = 3;
			this->lb_pseudo->Text = L"Pseudo";
			// 
			// lb_pass
			// 
			this->lb_pass->AutoSize = true;
			this->lb_pass->Location = System::Drawing::Point(69, 74);
			this->lb_pass->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lb_pass->Name = L"lb_pass";
			this->lb_pass->Size = System::Drawing::Size(76, 13);
			this->lb_pass->TabIndex = 4;
			this->lb_pass->Text = L"Mots de passe";
			// 
			// lb_info
			// 
			this->lb_info->AutoSize = true;
			this->lb_info->Location = System::Drawing::Point(8, 37);
			this->lb_info->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lb_info->Name = L"lb_info";
			this->lb_info->Size = System::Drawing::Size(0, 13);
			this->lb_info->TabIndex = 5;
			// 
			// user
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(228, 159);
			this->Controls->Add(this->lb_info);
			this->Controls->Add(this->lb_pass);
			this->Controls->Add(this->lb_pseudo);
			this->Controls->Add(this->txtbox_pass);
			this->Controls->Add(this->txtbox_pseudo);
			this->Controls->Add(this->btn_validation);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"user";
			this->Text = L"user";
			this->Load += gcnew System::EventHandler(this, &user::user_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
			
			
		}
#pragma endregion
	private: System::Void user_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	



	
	}
private: System::Void txtbox_pass_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	 

}
private: System::Void btn_validation_Click(System::Object^ sender, System::EventArgs^ e) {

	Inscription ajout;
	
	
	String^ pseudo;
	String^ pass;

	pseudo = txtbox_pseudo->Text;
	pass = txtbox_pass->Text;


	 

	bool test = ajout.senregistrer(pseudo, pass);

	if (!test)
	{
		lb_info->Text = " Enregistrement reussi ";
	}
	else
	{
		lb_info->Text = "Ce pseudo existe déjà ";

	}
}
};
}
