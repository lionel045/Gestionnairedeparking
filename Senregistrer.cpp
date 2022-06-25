#include "Senregister.h"
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace msclr::interop;



Inscription::Inscription() : db_reponse()
{

	



};



 bool Inscription::senregistrer(System::String^ pseudo,String^  pass)
 {
	

	connexion();

	bool PullReq = false;
	
	bool existe;


	String ^ verif = "SELECT pseudo FROM users WHERE pseudo = '" + pseudo + "'";

	std::string query = marshal_as <std::string>(verif);

	mysql_query(conn, query.c_str());

	

	rapport();



	if (row)
	{

	

	existe = true;
		

	}

	else
	{	
		existe = false;

			String^ insert_query{};
			String^ valeur{ "2" };

			

		insert_query = "INSERT INTO users (pseudo, password, id_type, Immac) VALUES ('" + pseudo + "', MD5('"  + pass + "') , '" + valeur + "', '')";

		std::string insert = marshal_as <std::string>(insert_query);



	mysql_query(conn, insert.c_str());

	

	}


	
	return existe;
 }