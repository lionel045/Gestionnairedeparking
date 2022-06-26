#include "Parkingbdd.h"
//using namespace std;
using namespace System;
#include <vector>
#include <sstream>

#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;
Parkingbdd::Parkingbdd()
{};






List<String^>^ Parkingbdd::RecupeRerALLPlace()
{
	connexion();
	String^ place("");
	String^ dejaselectionner("");
	String^ request{""};
	List<String^>^ Tableauaretourner = gcnew List<String^>();
	request = "SELECT * FROM parking";
	std::string conversion = marshal_as <std::string>(request);

	mysql_query(conn, conversion.c_str());

	res = mysql_use_result(conn);

	  

	
	while ((row = mysql_fetch_row(res)))
	
	{

         
			if(row)
			{
		      
				 
				place = marshal_as<String^>(row[1]);
				dejaselectionner = marshal_as<String^>(row[3]);
				
				if (dejaselectionner != "1")
				{
					  Tableauaretourner->Add(place);


				}
			  //   Tableauaretourner->Add(place);
		
			}
			else
			{
				Tableauaretourner->Add("Error");
			}	
			
	}
	return Tableauaretourner;
	
}




String ^ Parkingbdd::recupererplace(String ^place)
{
	connexion();
	

	String ^ valu;
	System::String^ reg{};
	
	reg = "SELECT id FROM parking WHERE libelle = '"+place+"'";
	std::string rep = marshal_as <std::string>(reg);

	mysql_query(conn, rep.c_str());

	rapport();
	const char* test;

	if (row)
	{

		test = row[0];
		valu = marshal_as<String^>(test);
	}

	else
	{
		valu = "Erreur";
	}


	return valu;

}

bool Parkingbdd::Supprimerplace(String^ idarecuperer)
{
	connexion();


	String ^ request = {};
	bool Requeststate = false;
	request = ("DELETE FROM parking WHERE id = '" + idarecuperer +"'");
	std::string ReqConvertie;
	ReqConvertie = marshal_as <std::string>(request);
	int querystate = mysql_query(conn, ReqConvertie.c_str());


	//rapport(); // On peut pas génerez de ligne vu la ligne est supprimé

	if (!querystate)
	{

		Requeststate = true;

	}
	
	else
	{
		Requeststate = false;
	}

	return Requeststate;

}

	bool Parkingbdd::setPlace(String^ id, String ^place)
	{
		connexion();

		bool valu;

		System::String^ reg{};

		int query_state;

		reg = ("UPDATE parking SET id_users = '"+ id + "',EstReserver = 1 WHERE id = '" +place+"'");

		std::string rep = marshal_as <std::string>(reg);

		query_state = mysql_query(conn, rep.c_str());

		//rapport();


		if (!query_state)
		{

			valu = true;

		}

		else
		{
			valu = false;
		}


		return valu;



  }

	bool Parkingbdd::renitialiserplace(String^ place, String ^ id_user)
	{

		connexion();

		bool valu;

		

		String^ Zero = "NULL";

		int query_state;
		
		String ^reg;

		reg = " UPDATE parking SET parking.id_users = NULL,EstReserver = 0 WHERE id = '"+place+"'";

		std::string rep = marshal_as <std::string>(reg);

		query_state = mysql_query(conn, rep.c_str());

		//rapport();


		if (!query_state)
		{

			valu = true;

			String^ Upd{};
			String^ valeur{ "2" };

			Upd = "UPDATE parking SET parking.id_users = NULL, EstReserver = 0 WHERE id_users = '" + id_user + "'";
			std::string Update = marshal_as <std::string>(Upd);

			mysql_query(conn, Update.c_str());
		
		}

		else
		{
			valu = false;
		}


		return valu;





	}

    String^ Parkingbdd::Dejaprise(String^ id_place, String^ id_user, String^ immac)
	{

		connexion();


		String^ compare;


		String^ req = "SELECT * FROM parking WHERE id ='"+id_place+ "'";

		std::string rep = marshal_as <std::string>(req);
		mysql_query(conn, rep.c_str());

		rapport();
		
	
		const char* ligne = "1";

		String^ convertion{ "" };
		if (row)
		{
				
				compare = "0";
			     
				ligne = row[3];

				  convertion = marshal_as<String^>(ligne);

				if (convertion == "1")
				{
					compare = "1";
				}

			
			else if  (convertion == "0" && immac != "")
			{
				
					compare = "0";
					setPlace(id_user, id_place);
				
				
			}
			else
			{
				compare = "error";
			}
		}

		else
		{
			compare = " non";
			
		}

			return compare;
	}
	
	int Parkingbdd::AjouteraHistoriqueArrive(String^ User, String^ id_place)
	{

		connexion();

		bool AddHistorique = false;

		String^ InsertHistorique = "INSERT INTO historique (id, Datedarrive, Datedesortie, id_users, id_place) VALUES(NULL, NOW(), NULL,'"+User+"', '"+id_place+"')";

		std::string Convertis = marshal_as <std::string>(InsertHistorique);
		 int queryState = mysql_query(conn, Convertis.c_str());
		//rapport();

		if (queryState  == 0)
		{


			AddHistorique = true;

		}
		else
		{
			AddHistorique = false;
		}

		return queryState;
	}
	bool Parkingbdd::AjoutHistoriqueSortie(String ^idplace)
	{
		connexion();

		bool pointeSortie;

		String^ update = "UPDATE historique SET Datedesortie = NOW() WHERE id_place = '"+ idplace + "'";

		std::string request = marshal_as <std::string>(update);
		int querystate = mysql_query(conn, request.c_str());
		

		if (querystate)
		{

			pointeSortie = true;

		}

		else
		{
			pointeSortie = false;
		}

		return querystate;
	}


	List<String^>^ Parkingbdd::RecupererhistoriqueUser(String^ User)
	{
		connexion();

		String ^ dateArrive{ "" }, ^dateSortie{ "" }, ^id_users{ "" }, ^id_place{ "" };

		List<String^>^ ligne = gcnew  List<String^>();

	
		String^ selectionne = " Select * FROM parking WHERE id_users = '" + User + "'";


		std::string convertion = marshal_as <std::string>(selectionne);

		mysql_query(conn, convertion.c_str());
		res = mysql_use_result(conn);


		while (row = mysql_fetch_row(res))
		{
		  
			dateArrive = marshal_as<String^>(row[1]);

			dateSortie = marshal_as<String^>(row[2]);

			id_users = marshal_as<String^>(row[3]);

			id_place = marshal_as<String^>(row[4]);

			if (row)
			{
				
					ligne->Add(dateArrive);
					ligne->Add(dateSortie);	
				    ligne->Add(id_users);
					ligne->Add(id_place);		
				
				
	
			}

		}

		
		return ligne;
	}


	 bool Parkingbdd::creeUneNouvelleplace(String^ libelle)
	{
		connexion();
	
		bool sidejapris;
		
		 String ^ selectionne = "SELECT libelle FROM parking WHERE libelle = '"+libelle+"'";
		

		std::string rep = marshal_as <std::string>(selectionne);
		mysql_query(conn, rep.c_str());
		rapport();
		if (row)
		{

			sidejapris = true;

		}
		else
		{
			
			sidejapris = false;
			String ^ insert_query = "INSERT INTO parking(id, libelle, id_users, EstReserver) VALUES(NULL, '" + libelle + "', NULL, '0')";

			std::string insert = marshal_as <std::string>(insert_query);
			mysql_query(conn, insert.c_str());
		}
		return sidejapris;
	
	
	}

		
	