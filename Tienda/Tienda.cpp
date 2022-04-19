#include <mysql.h>
#include <iostream>
#include <string>
#include "Bodega.h"

using namespace std;

int main()
{


	int op = 0, menu_p = 0, menu = 0, id = 0, ex = 0, busca=0;
	float pc = 0, pv = 0;
	string marca, prod, desc, fech;

	do {
		system("cls");
		cout << "\n _______________________________________________" << endl;
		cout << "           **** MENU PRINCIPAL ****" << endl;
		cout << " _______________________________________________\n" << endl;
		cout << "   1. MARACAS" << endl;
		cout << "   2. PRODUCTOS" << endl;
		cout << "   0. SALIR" << endl << endl;
		cout << " ELIJA UNA OPCION: ";
		cin >> menu_p;
		cin.ignore();
		if (menu_p == 1) {

			do {
				system("cls");
				cout << "\n _______________________________________________" << endl;
				cout << "           **** MENU MARCAS ****" << endl;
				cout << " _______________________________________________\n" << endl;
				cout << "   1. INGRESAR NUEVA MARCA" << endl;
				cout << "   2. MODIFICAR MARCA" << endl;
				cout << "   3. VER MARCAS GUARDADAS" << endl;
				cout << "   4. ELIMINAR MARCA" << endl;
				cout << "   0. SALIR" << endl << endl;
				cout << " ELIJA UNA OPCION: ";
				cin >> menu;
				cin.ignore();

				if (menu == 1) {
					system("cls");
					char opp = 's';
					do {
						cout << "INGRESE EL NOMBRE DE LA MARCA: ";
						getline(cin, marca);

						Bodega bod = Bodega(prod, marca, id, desc, pc, pv, ex, fech, busca); 
						bod.crear_Marca();
						cout << "INGRESER OTRA MARCA (s/n): ";
						cin >> opp;
						cin.ignore();
					} while (opp == 's' || opp == 'S');
					system("pause");
				}
				else if (menu == 2) {
					system("cls");
					cout << "INGRESE EL ID DE LA MARCA QUE DESEA ACTUALIZAR: ";
					cin >> id;
					cin.ignore();
					cout << "INGRESE NOMBRE DE LA MARCA QUE DESEA ACTUALIZAR: ";
					getline(cin, marca);

					Bodega bod = Bodega(prod, marca, id, desc, pc, pv, ex, fech, busca);
					bod.actualizar_marca();
					system("pause");
				}
				else if (menu == 3) {
					system("cls");
					Bodega bod = Bodega();
					bod.leer_Marca();
					system("pause");
				}
				else if (menu == 4) {
					system("cls");
					cout << "INGRESE EL ID DE LA MARCA QUE DESEA ELIMINAR: ";
					cin >> id;
					cin.ignore();

					Bodega bod = Bodega(prod, marca, id, desc, pc, pv, ex, fech, busca);
					bod.eliminar_marca();
					system("pause");
				}




			} while (menu != 0);

		}

		else if (menu_p == 2) {

			do {
				system("cls");
				cout << "\n _______________________________________________" << endl;
				cout << "           **** MENU PRODUCTOS ****" << endl;
				cout << " _______________________________________________\n" << endl;
				cout << "   1. INGRESAR NUEVO PRODUCTO" << endl;
				cout << "   2. MODIFICAR PRODUCTO" << endl;
				cout << "   3. VER PRODCUTOS GUARDADOS" << endl;
				cout << "   4. ELIMINAR PRODUCTOS" << endl;
				cout << "   0. SALIR" << endl << endl;
				cout << " ELIJA UNA OPCION: ";
				cin >> menu;
				cin.ignore();

				if (menu == 1) {
					system("cls");
					char opp = 's';
					do {
						cout << "INGRESE EL NOMBRE DEL PRODUCTO: ";
						getline(cin, prod);
						cout << "INGRESE ID DE LA MARCA: ";
						cin >> id;
						cin.ignore();
						cout << "INGRESE DESCRIPCION DEL PRODUCTO: ";
						getline(cin, desc);
						cout << "INGRESE PRECIO COMPRA: Q.";
						cin >> pc;
						cin.ignore();
						cout << "INGRESE PRECIO VENTA: Q.";
						cin >> pv;
						cin.ignore();
						cout << "INGRESE LA CANTIDAD DE PRODUCTO: ";
						cin >> ex;
						cin.ignore();
						cout << "INGRESE FECHA Y HORA DE INGRESO DEL PRODUCTO ( AAAA-MM-DD HH:MM:SS ): "; 
						getline(cin, fech);


						Bodega bod = Bodega(prod,marca,id,desc,pc,pv,ex,fech,busca);

						bod.crear_Producto();

						cout << "INGRESER OTRA MARCA (s/n): ";
						cin >> opp;
						cin.ignore();
					} while (opp == 's' || opp == 'S');
					system("pause");
				}
				else if (menu == 2) {
					char b='s';

					system("cls");
					do {
						cout << "INGRESE EL ID DE LA MARCA QUE DESEA ACTUALIZAR: ";
						cin >> busca;
						cin.ignore();


						Bodega bod = Bodega(prod, marca, id, desc, pc, pv, ex, fech, busca);
						bod.actualizar_Producto();

						cout << "INGRESER OTRA MARCA (s/n): ";
						cin >> b;
						cin.ignore(); 

					} while (b == 's' || b == 'S');
				}
				else if (menu == 3) {
					system("cls");
					Bodega bod = Bodega();
					bod.leer_Producto();
					system("pause");
				}
				else if (menu == 4) {
					system("cls");
					cout << "INGRESE EL ID DE LA MARCA QUE DESEA ELIMINAR: ";
					cin >> busca;
					cin.ignore();

					Bodega bod = Bodega(prod, marca, id, desc, pc, pv, ex, fech, busca); 
					bod.eliminar_Producto();
					system("pause");
				}

				


			} while (menu != 0);

		}



	} while (menu_p != 0);

	system("pause");
	return 0;

}
