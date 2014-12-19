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
	system("clear");
	//m.insertarContacto();
	m.visualizarAgenda();

	cout << "" << endl; // prints 
	return 0;
}
