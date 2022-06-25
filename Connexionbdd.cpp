#include "Connexionbdd.h"
//#include <iostream>




db_reponse::db_reponse()
	{
     	MySql();
		

		

	};

	bool db_reponse::rapport()
	{
		
		

		res = mysql_use_result(conn);

		row = mysql_fetch_row(res);

		return row;
	}

	


	bool db_reponse::connexion()
	{

	
		
	

				conn = mysql_init(NULL);
				
				conn = mysql_real_connect(conn, "localhost", "root", "", "mabase", 3306, NULL, 0);

				bool result{ 0 };

				if (conn)

				{


					result = true;


				}


				else
					result = false;



				return result;



		


  }
		