#pragma once
#include "Parkingbdd.h"
#include "fmyform.h"

namespace Maco {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de Creationplaceuser
	/// </summary>
	public ref class Creationplaceuser : public System::Windows::Forms::Form
	{
	public:
		Creationplaceuser(void)
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
		~Creationplaceuser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lb_libelle;
	protected:
	private: System::Windows::Forms::Button^ btn_valide;
	private: System::Windows::Forms::TextBox^ texbox_libelle;
	private: System::Windows::Forms::Label^ lb_resultat;

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
			this->lb_libelle = (gcnew System::Windows::Forms::Label());
			this->btn_valide = (gcnew System::Windows::Forms::Button());
			this->texbox_libelle = (gcnew System::Windows::Forms::TextBox());
			this->lb_resultat = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lb_libelle
			// 
			this->lb_libelle->AutoSize = true;
			this->lb_libelle->Location = System::Drawing::Point(50, 87);
			this->lb_libelle->Name = L"lb_libelle";
			this->lb_libelle->Size = System::Drawing::Size(147, 13);
			this->lb_libelle->TabIndex = 0;
			this->lb_libelle->Text = L"Saisissez un numéro de place";
			// 
			// btn_valide
			// 
			this->btn_valide->Location = System::Drawing::Point(81, 172);
			this->btn_valide->Name = L"btn_valide";
			this->btn_valide->Size = System::Drawing::Size(75, 23);
			this->btn_valide->TabIndex = 1;
			this->btn_valide->Text = L"Validez";
			this->btn_valide->UseVisualStyleBackColor = true;
			this->btn_valide->Click += gcnew System::EventHandler(this, &Creationplaceuser::btn_valide_Click);
			// 
			// texbox_libelle
			// 
			this->texbox_libelle->Location = System::Drawing::Point(69, 122);
			this->texbox_libelle->Name = L"texbox_libelle";
			this->texbox_libelle->Size = System::Drawing::Size(100, 20);
			this->texbox_libelle->TabIndex = 2;
			this->texbox_libelle->TextChanged += gcnew System::EventHandler(this, &Creationplaceuser::texbox_libelle_TextChanged);
			// 
			// lb_resultat
			// 
			this->lb_resultat->AutoSize = true;
			this->lb_resultat->Location = System::Drawing::Point(53, 22);
			this->lb_resultat->Name = L"lb_resultat";
			this->lb_resultat->Size = System::Drawing::Size(0, 13);
			this->lb_resultat->TabIndex = 3;
			// 
			// Creationplaceuser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->lb_resultat);
			this->Controls->Add(this->texbox_libelle);
			this->Controls->Add(this->btn_valide);
			this->Controls->Add(this->lb_libelle);
			this->Name = L"Creationplaceuser";
			this->Text = L"Creationplaceuser";
			this->Load += gcnew System::EventHandler(this, &Creationplaceuser::Creationplaceuser_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Creationplaceuser_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_valide_Click(System::Object^ sender, System::EventArgs^ e) {


		Parkingbdd Attribuerplace;

		fmyform::Valeurplace = texbox_libelle->Text;

		bool saisi;

		saisi = Attribuerplace.creeUneNouvelleplace(fmyform::Valeurplace);

			if (!saisi)
			{
				lb_resultat->Text = " La saisi est un succès";

				
			}
			else
			{
				lb_resultat->Text = " Place déjà existante";
			}

	}
	private: System::Void texbox_libelle_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
