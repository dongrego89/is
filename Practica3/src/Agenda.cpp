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

void Agenda::insertar(const Contacto &c) { //Comprobar que se ha insertado? Guardar devuelve un bool , podriamos usarlo?
	std::list<Contacto> auxiliar;
	auxiliar = GestorDB->cargar();
	auxiliar.push_back(c);
	GestorDB->guardar(auxiliar);
	this->ordenar();

}

void Agenda::eliminar(std::string dni) {
	std::list<Contacto> auxiliar;
	std::list<Contacto>::iterator i,j;

	auxiliar = GestorDB->cargar();

	for (i = auxiliar.begin(); i != auxiliar.end(); i++) {
		if (i->getDni() == dni) {
			j=i;

		}
	}
	auxiliar.erase(j);
	ordenar();
	GestorDB->guardar(auxiliar);

}

void Agenda::modificar(std::string dni, Contacto &c) {
	std::list<Contacto> auxiliar;
	auxiliar = GestorDB->cargar();

	std::list<Contacto>::iterator i;


		for (i = auxiliar.begin(); i != auxiliar.end(); i++) {

				if (i->getDni() == dni) {
					*i=c; //iterator i es un puntero, por tanto para pasar su valor es necesario el operador *
				}

			}
		ordenar();
		GestorDB->guardar(auxiliar);


}

bool funcion_compara_apellidos(const Contacto &c1, const Contacto &c2) {
				return c1.getApellidos() < c2.getApellidos();
			}

void Agenda::ordenar() {
	std::list<Contacto> auxiliar;
	auxiliar = GestorDB->cargar();

	auxiliar.sort(funcion_compara_apellidos);

	GestorDB->guardar(auxiliar);
}
}
