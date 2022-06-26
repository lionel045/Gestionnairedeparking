#include "Connexionbdd.h"
#include <vector>
using namespace System;
using namespace System::Collections::Generic;

#pragma once
#define ParkingBDD_DEF
#ifdef ParkingBDD_DEF

#include <iostream>



	class Parkingbdd : public db_reponse
	{

		


	public: 
	
		Parkingbdd();
		
		List<String^>^ Parkingbdd::RecupeRerALLPlace();

		String^ recupererplace(String^ place);
		
		bool setPlace(String^ id, String^ place);

		String^ Dejaprise(String^ id_place, String^ id_user,String^ immac);

		bool Supprimerplace(String^ idarecuperer);


		bool renitialiserplace(String^ place,String^ id_user);

		 bool creeUneNouvelleplace(String^ libelle);

		 int AjouteraHistoriqueArrive(String^ User, String^ libellePlace);
		 
	     bool AjoutHistoriqueSortie(String^ idplace);

		 List<String^>^ RecupererhistoriqueUser(String^ User);

	private : 

		

	};






#endif
