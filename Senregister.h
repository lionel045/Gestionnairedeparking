
#include "Connexionbdd.h"
#ifndef Enregistrement_DEF
#define Enregistrement_DEF
#include <string>
using namespace System;
#include <iostream>

class Inscription : public db_reponse
{
public:

	bool senregistrer(System::String^ pseudo, String^ pass);

	

	Inscription();
private:

	

	


	


};




#endif