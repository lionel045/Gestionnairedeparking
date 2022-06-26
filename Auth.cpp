#include "Auth.h"


#include <msclr\marshal_cppstd.h>


using namespace msclr::interop;
Authentification::Authentification() : db_reponse(), pseudo{ 0 }, mdp{ 0 }
{};


bool Authentification::seconnecter(System::String^ pseudo, System::String^ pass)
	// Nom de la methode ainsi que les paramètre quel prendra le pseudo et le mots de passe
{
	System::String^ req{}; //création du variable de type String ou l'on ecrira notre requete

	
	connexion(); // Communicartion avec la base de donnée
	



	req = "SELECT * FROM users WHERE pseudo = '" + pseudo + "' AND password = MD5('" + pass + "')" ;
	// Requete Sql pour recuperer la table User ainsi que les valeurs de pseudo et mots de passe correspondant 
	std::string rep = marshal_as <std::string>(req); // convertis la variable de type String en string
													// afin de pouvoir executer la requête 

	mysql_query(conn,  rep.c_str()); // Methode permetant l'execution de la requête

	rapport();
	bool result ; // Variable permettant de voir si la requete a pu s'executer

	if (row) // si les information inserer sont en base de donnée le rapport sera vrai
			// donc l'authentification aura lieu
	{
		result = true; // On retournera ainsi vrai
	}

	else // Les infos sont incorrect donc on retourne faux
	{ 
		result = false;	
	}

	return result;
 }

bool Authentification::siUser(System::String^ pseudo)
{
	connexion();



	bool valu = false;
	System::String^ reg{};
	System::String^ valeur{"1"};
	reg = "SELECT pseudo FROM users WHERE id_type = 1";
	std::string rep = marshal_as <std::string>(reg);

	mysql_query(conn, rep.c_str());

	rapport();

	String ^ checkAdmin;
;
	if (row)
	{	
		
		checkAdmin = marshal_as<String^>(row[0]);

		if (checkAdmin == pseudo)
		{
			valu = true;
		}
		
		
		
	}

	else
	{
		valu = false;
	}

	
	return valu;

}

String ^Authentification::idUsers(System::String^ pseudo)
{
	connexion();



	String ^valu;

	System::String^ reg{};
	System::String^ valeur{ "1" };
	reg = "SELECT id FROM users where pseudo = '"+pseudo+"'";
	
	
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
		valu = " Erreur";
	}
	return valu;

}
	
bool Authentification::Saisiimmac(System::String^ imac,String^ id)
{
	connexion();
	bool get;
	String^ UPD{};
	UPD	= "UPDATE users SET Immac = '" + imac + "'  WHERE users.id = '" +id+ "'";

	std::string rep = marshal_as <std::string>(UPD);
	int mysqlstate = mysql_query(conn, rep.c_str());

	//rapport();
	if (!mysqlstate)
	{
		get = true;
	}
	else
	{
		get = false;
	}
	return get;
	}
	
bool Authentification::reserver(String^ id)
{
	connexion();
	bool result = false;
	String^ verif = "SELECT libelle FROM parking WHERE id_users =  '" +id+ "'";


	std::string req = marshal_as <std::string>(verif);

	mysql_query(conn, req.c_str());


	rapport();
		
		if (row)
		{
		  result = true;
		}

		else
		{
		 result = false;
		}
		



	

		return result;
	}




