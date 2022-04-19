#include <mysql.h>
#include <iostream>
#include <string>
#include <sstream> 
#include "Marca.h"
#include "Conector.h"
#include "Producto.h"

using namespace std;

class Bodega:Producto,Marca{

protected: 
	int buscador=0; 

public:
	Bodega() {}

	Bodega(string prod, string mr, int id, string desc, float pc, float pv, int ex, string fech,int busca) : Producto(prod,desc,pc,pv,ex,fech),Marca(mr, id) {
		buscador = busca;
	}
	void setProducto(string prod) { producto = prod; }
	void setMarca(string mr) { marca = mr; }
	void setidMarca(int id) { idMarca = id; }
	void setDescripcio(string desc) { descripcion = desc; }
	void setPrecio_C(float pc) { precio_costo = pc; }
	void setPrecio_V(float pv) { precio_venta = pv; }
	void setExistencia(int ex) { existencia = ex; }
	void setFecha_ingr(string fech) { fecha_ingreso = fech; }
	void setBuscador(int busca) { buscador = busca; }

	string getProducto() { return producto; }
	string getMarca() { return marca; }
	int getidMarca() { return idMarca; }
	string getDescripcion() { return descripcion; }
	float getPrecio_C() { return precio_costo; }
	float getPrecio_V() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getFecha_ingr() { return fecha_ingreso; }
	int getBuscador() { return buscador; }

	//VOID MARCAS

	//crear
	void crear_Marca() {
		int q_estado;
		Conector cn = Conector();

		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string insert = "INSERT INTO `tienda`.`marcas` (`marca`) VALUES('" + marca + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "INGRESADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccin();
	}

	//leer
	void leer_Marca() {
		int q_estado;
		Conector cn = Conector();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM tienda.marcas";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "         ********* PRODUCTOS ******" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " --> " << fila[1] << endl;
				}
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccin();
	}



	//actualizar
	void actualizar_marca() {
		int q_estado;
		Conector cn = Conector();

		cn.abrir_coneccion();
		string id = to_string(idMarca);
		if (cn.getConectar()) {

			string update = "UPDATE `tienda`.`marcas` SET `marca` = '" + marca + "' WHERE (`idMarca` = " + id + ")";

			const char* i = update.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "INGRESADO CON EXITO .... \n";

			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccin();
	}

	//Eliminar
	void eliminar_marca() {
		int q_estado, q_stado; 
		int c=1, r=0, im=0;
		Conector cn = Conector();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;

		cn.abrir_coneccion();
		string id = to_string(idMarca);
		if (cn.getConectar()) {

			string delite = "DELETE FROM tienda.marcas WHERE idMarca= " + id + "";

			const char* i = delite.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				cout << "ELIMINADO CON EXITO .... \n";

					}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccin();
	}


	//VOID PRODUCTOS

	//crear
	void crear_Producto() {
		int q_estado;
		Conector cn = Conector();

		cn.abrir_coneccion();

		string idM = to_string(idMarca);  
		string pco = to_string(precio_costo);  
		string pve = to_string(precio_venta);  
		string exi = to_string(existencia);  

		if (cn.getConectar()) {

			string insert = "INSERT INTO tienda.productos (`Producto`, `idMarca`, `descripcion`, `precio_costo`, `precio_venta`, `existencia`, `fecha_ingreso`) VALUES('"+producto+"', "+idM+", '"+descripcion+"', "+pco+", "+pve+", "+exi+", '"+fecha_ingreso+"')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "INGRESADO CON EXITO .... \n";
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccin();
	}


	//leer
	void leer_Producto() {
		int q_estado;
		Conector cn = Conector();
		MYSQL_ROW fila = 0;
		MYSQL_RES* resultado = 0;
		cn.abrir_coneccion();

		if (cn.getConectar()) {

			string consulta = "SELECT * FROM tienda.productos";
			const char* i = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), i);

			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "         ********* PRODUCTOS ******" << endl;
				cout << " ID   |  PRODUCTO  |  ID MARCA | DESCRIPCION       |  PRECIO COSTO  | PRECIO VENTA | EXISTENCIA|FECHA INGRESO" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " | " << fila[1] << " | " << fila[2] << " | " << fila[3] << " | " << fila[4] << " | " << fila[5] << " | " << fila[6] << " | " << fila[7] << endl;
				}
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccin();
	}

	//Actualizar
	void actualizar_Producto() { 
		int q_estado;
		int men=0;
		Conector cn = Conector();

		cn.abrir_coneccion();
		string bus = to_string(buscador);

		if (cn.getConectar()) {
			system("cls");
			cout << "   ********** MENU ACTUALIZAR ********** "<<endl;
			cout << " 1. NOMBRE DEL PRODUCTO" << endl;
			cout << " 2. ID DE LA MARCA DEL PRODUCTO" << endl;
			cout << " 3. DESCRIPCION DEL PRODUCTO" << endl;
			cout << " 4. PRECIO COSTO DEL PRODUCTO" << endl;
			cout << " 5. PRECIO VENTA DEL PRODUCTO" << endl;
			cout << " 6. CANTIDAD EN EXISTENCIA DEL PRODUCTO" << endl;
			cout << " 7. FECHA DE INGRESO" << endl;
			cout << " 8. MODIFICAR TODOS LOS CAMPOS" << endl;
			cout << " QUE CAMPO DESEA MODIFICAR:  ";
			cin >> men;
			cin.ignore();

			if (men == 1) {

				cout <<endl <<" INGRESE NOMBRE DEL PRODUCTO:   ";
				getline(cin, producto);

				string update= "UPDATE tienda.productos SET `Producto` = '"+producto+"' WHERE(`idProducto` = "+bus+")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}

			else if (men == 2) {

				cout <<endl<< " INGRESE ID DE LA MARCA DEL PRODUCTO:   "; 
				cin >> idMarca;
				cin.ignore();
				string id = to_string(idMarca);

				string update = "UPDATE tienda.productos SET `idMarca` = " + id + " WHERE(`idProducto` = " + bus + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}

			else if (men == 3) {

				cout << endl << " INGRESE LAS DESCRIPCION DEL PRODUCTO:   ";
				getline(cin, descripcion);

				string update = "UPDATE tienda.productos SET `descripcion` = '" + descripcion + "' WHERE(`idProducto` = " + bus + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}

			else if (men == 4) {

				cout << endl << " INGRESE PRECIO COSTO DEL PRODUCTO:   ";
				cin >> precio_costo;
				cin.ignore();
				string pc = to_string(precio_costo);

				string update = "UPDATE tienda.productos SET `precio_costo` = " + pc + " WHERE(`idProducto` = " + bus + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}

			else if (men == 5) {

				cout << endl << " INGRESE PRECIO VENTA DEL PRODUCTO:   ";
				cin >> precio_venta;
				cin.ignore();
				string pv = to_string(precio_venta);

				string update = "UPDATE tienda.productos SET `precio_venta` = " + pv + " WHERE(`idProducto` = " + bus + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}

			else if (men == 6) {

				cout << endl << " INGRESE CANTIDAD EN EXISTENCIA DE PRODUCTO:   ";
				cin >> existencia;
				cin.ignore();
				string ex = to_string(existencia);

				string update = "UPDATE tienda.productos SET `existencia` = " + ex + " WHERE(`idProducto` = " + bus + ")";
				const char* i = update.c_str();
				q_estado = mysql_query(cn.getConectar(), i);
				if (!q_estado) {
					cout << "MODIFICADO CON EXITO .... \n";
				}
				else {
					cout << "ERROR DE CONECCION.... \n";
				}
			}

			else if (men == 7) {

				cout << endl << " INGRESE FECHA Y HORA DE INGRESO DEL PRODUCTO ( AAAA-MM-DD HH:MM:SS ):   ";
				getline(cin, fecha_ingreso);

			string update = "UPDATE tienda.productos SET `fecha_ingreso` = '" + fecha_ingreso + "' WHERE(`idProducto` = " + bus + ")";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "MODIFICADO CON EXITO .... \n";
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
			}

			else if (men == 8) {
			cout << endl;
			cout << "INGRESE EL NOMBRE DEL PRODUCTO: ";
			getline(cin, producto);
			cout << "INGRESE ID DE LA MARCA: ";
			cin >> idMarca;
			cin.ignore();
			cout << "INGRESE DESCRIPCION DEL PRODUCTO: ";
			getline(cin, descripcion);
			cout << "INGRESE PRECIO COMPRA: Q.";
			cin >> precio_costo;
			cin.ignore();
			cout << "INGRESE PRECIO VENTA: Q.";
			cin >> precio_venta;
			cin.ignore();
			cout << "INGRESE LA CANTIDAD DE PRODUCTO: ";
			cin >> existencia;
			cin.ignore();
			cout << "INGRESE FECHA Y HORA DE INGRESO DEL PRODUCTO ( AAAA-MM-DD HH:MM:SS ): ";
			getline(cin, fecha_ingreso);

			string idM = to_string(idMarca);
			string pco = to_string(precio_costo);
			string pve = to_string(precio_venta);
			string exi = to_string(existencia); 


			string update = "UPDATE tienda.productos SET `Producto` = '"+producto+"', `idMarca` = "+idM+", `descripcion` = '"+descripcion+"', `precio_costo` = "+pco+", `precio_venta` = "+pve+", `existencia` = "+exi+", `fecha_ingreso` = '"+fecha_ingreso+"' WHERE(`idProducto` = "+bus+")";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "MODIFICADO CON EXITO .... \n";
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
			}


		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		system("pause");
		cn.cerrar_coneccin();
	}
	
	//Eliminar
	void eliminar_Producto() { 
		int q_estado;
		Conector cn = Conector();
		
		cn.abrir_coneccion();
		string bus = to_string(buscador);
		if (cn.getConectar()) {

			string delite = "DELETE FROM tienda.productos WHERE idProducto= " + bus + "";
			const char* i = delite.c_str();

			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {

				cout << "ELIMINADO CON EXITO .... \n";
				/*int cont = 0;
				string cc = to_string(cont);
				string contador ="select count(*) from tienda.marcas";
				const char* ee = contador.c_str();

				stringstream(cc) >> cont;


				cout << cc<<endl;
				cout << cont <<endl;
				for(int c=idMarca; c<=cont; c++ ){

					string idd = to_string(idMarca + 1);
					string conta = to_string(idMarca - 1);

					string auto_cont="UPDATE `tienda`.`marcas` SET `idMarca` = "+idd+" WHERE(`idMarca` = "+conta+")";
					const char* j = auto_cont.c_str();
					cout << idd << endl;
					cout << conta << endl;
					idMarca++;

				}
				string final = to_string(idMarca + 1);
				string recuperador = "alter table marcas auto_increment = "+final+"";
				const char* r = recuperador.c_str();
				*/
			}
			else {
				cout << "ERROR DE CONECCION.... \n";
			}
		}
		else {
			cout << "ERROR DE CONECCION.... \n";
		}
		cn.cerrar_coneccin();
	}



};
