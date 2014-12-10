/*
 * Agenda.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i02coprg
 */
#include<list>
#include<string>

#include "Contacto.h"
#include "Agenda.h"

namespace agenda{


	std::list<Contacto> Agenda::buscar(std::string apellido){
		//cargar del fichero
		std::list<Contacto>auxiliar;//fichero completo hecho lista
		auxiliar=GestorDB->cargar();


		std::list<Contacto>retorno;//lista

		std::list<Contacto>::iterator i;
		for(i=auxiliar.begin();i!=auxiliar.end();i++){
				if(i->getApellidos()==apellido){
					retorno.push_back(*i);//iterator i es un puntero, por tanto para pasar su valor es necesario el operador *
				}
		}

		return retorno;
	}



	void Agenda::insertar(const Contacto &c) {//Comprobar que se ha insertado? Guardar devuelve un bool , podriamos usarlo?
			std::list<Contacto>auxiliar;
			auxiliar=GestorDB->cargar();
			auxiliar.push_back(c);
			GestorDB->guardar(auxiliar);

	}

}
