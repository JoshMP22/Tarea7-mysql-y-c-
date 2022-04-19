#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

class Marca {

public: string marca;
	  int idMarca = 0;

public:
	Marca() {}

	Marca(string mr, int id) {
		marca = mr;
		idMarca = id;
	}
	
};

