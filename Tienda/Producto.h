#include <mysql.h>
#include <iostream>
#include <string>

using namespace std;

class Producto {

protected:

	string producto, descripcion, fecha_ingreso;
	int existencia = 0;
	float precio_costo = 0, precio_venta = 0;

public:
	Producto() {}

	Producto(string prod, string desc, float pc, float pv, int ex, string fech){

		producto = prod;
		descripcion = desc;
		precio_costo = pc;
		precio_venta = pv;
		existencia = ex;
		fecha_ingreso = fech;
	}

};