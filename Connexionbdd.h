#pragma once
#ifndef Maco_DEF
#define Maco_Def

#include "Mysqlbdd.h"

#include <iostream>
#include <string>




 

	class db_reponse : public MySql

	{
	public :

	    
		db_reponse();
		bool connexion();
		

	protected :

	

		bool rapport();

	

	

	private :

	
		
		

	};















#endif // !Maco_DEF
