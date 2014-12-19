/*
 * Agenda.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i02coprg
 */
#include<list>
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>//Para system
#include<locale>//Para usar tolower

#include "Contacto.h"
#include "Agenda.h"

namespace agenda {

std::string Agenda::minuscula(std::string cadena){
	std::locale loc;
	std::string str=cadena;
	for (std::string::size_type i=0; i<str.length(); ++i)
	   str[i] = std::tolower(str[i],loc);
	return str;
}

std::list<Contacto> Agenda::buscarApellido(std::string apellido) {
	//cargar del fichero
	std::list<Contacto> auxiliar; //fichero completo hecho lista
	auxiliar = GestorDB->cargar();
	std::string apellidos;

	std::list<Contacto> retorno; //lista

	std::list<Contacto>::iterator i;
	for (i = auxiliar.begin(); i != auxiliar.end(); i++) {
		//if (i->getApellidos() == apellido) {

		apellidos=minuscula(i->getApellidos());//pasamos a minuscula los apellidos

		std::size_t encontrado=apellidos.find(minuscula(apellido));//Buscamos el apellido en minuscula en los apellidos del contacto

		if(encontrado!=std::string::npos){//Si hay resultado se añadirá a la lista de retorno
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
void Agenda::imprimirHTML(){

	std::list<Contacto> auxiliar = GestorDB->cargar();
	std::list<Contacto>::iterator c;

	std::list<Direccion>::iterator d;
	std::list<Direccion> direccion;

	std::list<RedSocial>::iterator r;
	std::list<RedSocial>red;



	std::ofstream archivo("agenda.html");

	if(archivo.is_open()){
		archivo << "<html><head><title>UCO AGENDA | Grupo I22</title><link rel='stylesheet' href='estilo.css' /></head><body>";
		for(c=auxiliar.begin();c!=auxiliar.end();c++){
			archivo << "<div class='contacto'><h1>"<< c->getNombre() << " " << c->getApellidos() << "</h1>";
			archivo << "<div class='campo'>DNI: " << c->getDni() << "</div>";
			archivo << "<div class='campo'>Telefono: " << c->getTelefono() << " Movil: " << c->getMovil() << "</div>";
			archivo << "<div class='campo'>Email: " << c->getEmail() << "</div>";
			archivo << "<div class='campo'>Anotaciones: <br> <textarea> " << c->getAnotaciones() << "</textarea></div>";

			direccion=c->getDirecciones();

			for(d=direccion.begin();d!=direccion.end();d++){
				if(d->calle!="")
				archivo << "<div class='direccion'> CP " << d->cp << ". " << d->via << " " << d->calle << ", N&ordm; " << d->numero << ", Portal " << d->portal << d->piso << "&ordm;" << d->puerta << "</div>";

			}

			red=c->getRedesSociales();
			for(r=red.begin();r!=red.end();r++){

				if(r->nombre != "")
					archivo << "<div class='red'><img src='src/imagenes/" << r->nombre << ".png'> " << r->url << "</div>";
			}

			archivo << "</div>";
		}
		archivo << "</body></html>";
	archivo.close();

	std::system("firefox agenda.html");
	}
}
}
