#pragma once
#ifndef Auth_DEF
#define Auth_DEF
#include "Connexionbdd.h"
using namespace System;
#include <string>
class Authentification : public db_reponse

{

public:

	Authentification();

	bool seconnecter(System::String^ pseudo, System::String^ pass);

	bool siUser(System::String^ pseudo);

	String ^ idUsers(System::String^ pseudo);

	bool Saisiimmac(System::String^ imac, String^ id);

	bool reserver(String^ id);

	private:

	std::string pseudo, mdp;

	

	};






#endif 