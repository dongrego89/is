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
#include <cstring>

using namespace std;
using namespace agenda;

void enter();

int main() {
	GestorDBFichero *mi_gestor = new GestorDBFichero("agendaContactos.txt");

	Agenda a = Agenda(mi_gestor);

	MenuTerminal m(a);

	int menu;
	string nomFich;
	char ruta[50]="cp agendaContactos.txt ";
	string ruta2;
	system("clear");

	do{
	cout<<"\n"<<"\t\t\t\t"<<"********************OPCIONES DE LA AGENDA********************"<<endl;
	cout<<"\t\t\t\t"<<"Pulsa (1) para visualizar la agenda completa."<<endl;
	cout<<"\t\t\t\t"<<"Pulsa (2) para insertar un nuevo contacto en la agenda."<<endl;
	cout<<"\t\t\t\t"<<"Pulsa (3) buscar un contacto en la agenda."<<endl;
	cout<<"\t\t\t\t"<<"Pulsa (4) para modificar un contacto de la agenda."<<endl;
	cout<<"\t\t\t\t"<<"Pulsa (5) para borrar un contacto de la agenda."<<endl;
	cout<<"\t\t\t\t"<<"Pulsa (6) para mostrar la agenda en firefox."<<endl;
	cout<<"\t\t\t\t"<<"Pulsa (7) para visualizar los contactos mas frecuentes."<<endl;
	cout<<"\t\t\t\t"<<"Pulsa (8) para hacer una copia de seguridad de la agenda."<<endl;
	cout<<"\t\t\t\t"<<"Pulsa (0) para salir."<<endl;
	cout<<"\t\t\t\t"<<"*************************************************************"<<endl<<"\t\t\t\t";
	cin >>menu;
	cout<<"\n";
	cin.ignore(256,'\n');
	switch(menu){

	case 1:
		system("clear");
		m.visualizarAgenda();
		enter();
		system("clear");
		break;
	case 2:
		system("clear");
		m.insertarContacto();
		enter();
		system("clear");

		break;
	case 3:
		system("clear");
		m.buscarContacto();
		enter();
		system("clear");
		break;
	case 4:
		system("clear");
		m.modificarContacto();
		enter();
		system("clear");
		break;
	case 5:
		system("clear");
		m.borrarContacto();
		enter();
		system("clear");
		break;
	case 6:
		m.imprimeFormato();
		system("clear");
		break;
	case 7:
		system("clear");
		m.visualizarFrecuentes();
		enter();
		system("clear");
		break;

	case 8:
		system("clear");
		cout << "\n\t\t\t---------------------------------------------------------------------------------\n";
		cout <<"\t\t\t"<< "Introduce el nombre de fichero en el que se va a guardar la copia de seguridad:"<<endl<<"\t\t\t";
		getline(cin,nomFich);

		ruta2=nomFich+".txt";

		strcat(ruta,ruta2.c_str());

		system(ruta);

		enter();
		system("clear");
		break;

	}


	}while(menu!=0);



	cout << "" << endl; // prints 
	return 0;
}

void enter()
{
	string enter;
	std::cout << "\n\n\t\t\t---------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t   ***PRESIONA ENTER PARA VOLVER A LAS OPCIONES DE LA AGENDA***";
	std::cout << "\n\t\t\t---------------------------------------------------------------------------------\n\t\t\t";
	getline(cin,enter);
}
