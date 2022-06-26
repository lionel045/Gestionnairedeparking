#pragma once
#ifndef fmyform_def
#define fmyform_def

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


ref class fmyform

{
public: 
	fmyform();
	static String^ premierValeur = { "" };
	static String^ secondeValeur;
	static	bool Admin;
	static	bool vide;
	static String^ Valeurplace;
};


#endif // !fmyform_def