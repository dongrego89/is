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


	std::list<Contacto> Agenda::buscar(std::string apellido,std::string dni){
		//cargar del fichero
		std::list<Contacto>auxiliar;//fichero completo hecho lista
		auxiliar=GestorDB->cargar();


		std::list<Contacto>retorno;//lista

		std::list<Contacto>::iterator i;
		for(i=auxiliar.begin();i!=auxiliar.end();i++){
			if(dni.length()==0){
				if(i->getApellidos()==apellido){
					retorno.push_back(*i);//iterator i es un puntero, por tanto para pasar su valor es necesario el operador *
				}
			}
			else{
				if(i->getDni()==dni){
									retorno.push_back(*i);//iterator i es un puntero, por tanto para pasar su valor es necesario el operador *
								}
			}
		}

		return retorno;
	}



	void Agenda::insertar(const Contacto &c) {//Comprobar que se ha insertado? Guardar devuelve un bool , podriamos usarlo?
			std::list<Contacto>auxiliar;
			auxiliar=GestorDB->cargar();
			auxiliar.push_back(c);
			GestorDB->guardar(auxiliar);
			this->ordenar();

	}

	void Agenda::eliminar(std::string dni){
		std::list<Contacto> auxiliar;
		std::list<Contacto>::iterator i;

		auxiliar=GestorDB->cargar();

		for(i=auxiliar.begin();i!=auxiliar.end();i++){
			if(i->getDni()==dni){
				auxiliar.erase(i);
			}
		}
		GestorDB->guardar(auxiliar);

	}

	void Agenda::modificar(std::string dni,Contacto &c){
		std::list<Contacto> encontrado;
		std::list<Contacto> auxiliar;
		encontrado=buscar("",dni);

		auxiliar=GestorDB->cargar();//cargar la lista

		//combinar contacto antiguo con el nuevo aplicando cambios en un objeto

		if(c.getNombre().length()==0){//Si esta vacío conservamos el nombre del objeto de la lista
			c.setNombre(encontrado.begin()->getNombre());
		}

		if(c.getApellidos().length()==0){
					c.setApellidos(encontrado.begin()->getApellidos());
				}

		if(c.getTelefono().length()==0){
					c.setTelefono(encontrado.begin()->getTelefono());
				}

		if(c.getMovil().length()==0){
					c.setMovil(encontrado.begin()->getMovil());
				}

		if(c.getEmail().length()==0){
					c.setEmail(encontrado.begin()->getEmail());
				}

		if(c.getAnotaciones().length()==0){
					c.setAnotaciones(encontrado.begin()->getAnotaciones());
				}


		//Falta la modificacion de Redes Sociales y Direcciones, ya que son multivaluados !!!!!

		this->eliminar(dni);//borrar contacto antiguo de la lista
		this->insertar(c);//insertar contacto nuevo en la lista




	}

	void Agenda::ordenar(){
		std::list<Contacto> auxiliar;
		auxiliar=GestorDB->cargar();

		auxiliar.sort();
		GestorDB->guardar(auxiliar);
	}
}
