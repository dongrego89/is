//============================================================================
// Name        : Practica3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Agenda.h"
#include "MenuTerminal.h"
#include "GestorDBFichero.h"
#include <cstdlib>

using namespace std;
using namespace agenda;

int main() {
	GestorDBFichero *mi_gestor = new GestorDBFichero("fichero.txt");

	Agenda a = Agenda(mi_gestor);

	MenuTerminal m(a);

	int menu;

	system("clear");

	do{
	cout<<"\t"<<"OPCIONES DE LA AGENDA:"<<endl;
	cout<<"\t"<<"Pulsa (1) para visualizar la agenda completa."<<endl;
	cout<<"\t"<<"Pulsa (2) para insertar un nuevo contacto en la agenda."<<endl;
	cout<<"\t"<<"Pulsa (3) buscar un contacto en la agenda."<<endl;
	cout<<"\t"<<"Pulsa (4) para modificar un contacto de la agenda."<<endl;
	cout<<"\t"<<"Pulsa (5) para borrar un contacto de la agenda."<<endl;
	cout<<"\t"<<"Pulsa (0) para salir."<<endl;
	cin >>menu;
	cin.ignore(256,'\n');
	switch(menu){
	case 1:
		m.visualizarAgenda();
		break;
	case 2:
		m.insertarContacto();
		break;
	case 3:
		m.buscarContacto();
		break;
	case 4:
		m.modificarContacto();
		break;
	case 5:
		m.borrarContacto();
		break;
	}


	}while(menu!=0);



	cout << "" << endl; // prints 
	return 0;
}
