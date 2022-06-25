#ifndef My_Sql
#define My_Sql
#include <mysql.h>

#include <iostream>
class MySql {

	public :
		MySql();
	MYSQL_RES* res;
	MYSQL_ROW row;

     
	protected :
    MYSQL *conn = 0;
	


	};

	
	
#endif


