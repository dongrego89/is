/*
 * Agenda.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i02coprg
 */
#include<list>
#include<string>
#include<iostream>

#include "Contacto.h"
#include "Agenda.h"

namespace agenda {

std::list<Contacto> Agenda::buscarApellido(std::string apellido) {
	//cargar del fichero
	std::list<Contacto> auxiliar; //fichero completo hecho lista
	auxiliar = GestorDB->cargar();

	std::list<Contacto> retorno; //lista

	std::list<Contacto>::iterator i;
	for (i = auxiliar.begin(); i != auxiliar.end(); i++) {
		if (i->getApellidos() == apellido) {
			retorno.push_back(*i); //iterator i es un puntero, por tanto para pasar su valor es necesario el operador *
		}
	}

	return retorno;
}

Contacto_it Agenda::buscarDni(std::string dni) {
	//cargar del fichero
	std::list<Contacto> auxiliar; //fichero completo hecho lista
	auxiliar = GestorDB->cargar();

	//Contacto retorno; //objeto a devolver

	Contacto_it i;
	Contacto_it j;

	for (i = auxiliar.begin(); i != auxiliar.end(); i++) {

			if (i->getDni() == dni) {
				j=i; //iterator i es un puntero, por tanto para pasar su valor es necesario el operador *
			}

		}
	return j;
	}








void Agenda::insertar(const Contacto &c) { //Comprobar que se ha insertado? Guardar devuelve un bool , podriamos usarlo?
	std::list<Contacto> auxiliar;
	auxiliar = GestorDB->cargar();
	auxiliar.push_back(c);
	GestorDB->guardar(auxiliar);
	//this->ordenar();

}

void Agenda::eliminar(std::string dni) {
	std::list<Contacto> auxiliar;
	std::list<Contacto>::iterator i;

	auxiliar = GestorDB->cargar();

	for (i = auxiliar.begin(); i != auxiliar.end(); i++) {
		if (i->getDni() == dni) {
			auxiliar.erase(i);
		}
	}
	GestorDB->guardar(auxiliar);

}

void Agenda::modificar(std::string dni, Contacto &c) {
	Contacto_it encontrado;
	std::list<Contacto> auxiliar;
	encontrado = buscarDni(dni);

	*encontrado = c;

}

void Agenda::ordenar() {
	std::list<Contacto> auxiliar;
	auxiliar = GestorDB->cargar();



	//auxiliar.sort([](const Contacto & a, const Contacto & b) { return a.getApellidos() < b.getApellidos(); });


	//auxiliar.sort(LastNameComp());
	GestorDB->guardar(auxiliar);
}
}
