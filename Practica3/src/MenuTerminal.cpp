/*
 * MenuTerminal.cpp
 *
 *  Created on: 17/12/2014
 *      Author: i02coprg
 */

#include "MenuTerminal.h"
#include "Agenda.h"
#include "Contacto.h"
#include <list>
#include <string>
#include <iostream>

using namespace std;

namespace agenda {

	void MenuTerminal::visualizarContacto(Contacto_it iterador){
		Contacto c=*iterador;
		std::list<Direccion>::iterator d;
		std::list<RedSocial>::iterator r;

		cout << "Nombre y Apellidos: " << c.getNombre() << " " << c.getApellidos() << endl;
		cout << "Telefono: " << c.getTelefono() << "Movil: " << c.getMovil() << endl;
		cout << "Email: " << c.getEmail() << endl << "Anotaciones: " << endl << "'" << c.getAnotaciones() << "'" << endl;

		cout << "Direcciones: " << endl;


		std::list<Direccion> ld =c.getDirecciones();

		for(d=ld.begin();d!=ld.end();d++){//revisar enum numerico para el tipo de la via
			cout << d->via << d->calle << ", Nº " << d->numero << " Portal " << d->portal << " Piso: " << d->piso << " Puerta" << d->puerta;

		}

		cout << "Redes Sociales: " << endl;


		std::list<RedSocial> rs =c.getRedesSociales();

		for(r=rs.begin();r!=rs.end();r++){//Revisar enum numerico para la red social
			cout << "Red Social: " << r->nombre << " Usuario: " << r->url;
		}

		linea();


	}

	void MenuTerminal::buscarContacto(){
		std::string apellido;
		cout << "Introduce el apellido del contacto a buscar:";
		std::getline(cin,apellido);

		std::list<Contacto>auxiliar;

		auxiliar=agenda_.buscarApellido(apellido);

		Contacto_it i;
		for(i=auxiliar.begin();i!=auxiliar.end();i++){
			this->visualizarContacto(i);//Imprimir contacto a contacto
		}

	}

	void MenuTerminal::visualizarAgenda(){
		std::list<Contacto>auxiliar;
		auxiliar=agenda_.mostrarAgenda();

		Contacto_it i;

		for(i=auxiliar.begin();i!=auxiliar.end();i++){
			this->visualizarContacto(i);//Imprimir contacto a contacto
		}
	}

	void MenuTerminal::rellenarContacto(Contacto &c){
		int redes, direcciones,i;

		std::string dni,nombre,apellidos,telefono,movil,email,anotaciones;



		RedSocial RedAuxiliar;
		std::list<RedSocial> RedesAux;

		Direccion DireccionAuxiliar;
		std::list<Direccion> DireccionAux;

		cout << "Rellenando Contacto: " << endl;

		linea();

		cout << "¿Cuantas direcciones postales tiene el contacto?" << endl;
		cin >> direcciones;
		cin.ignore(256,'\n');

		cout << "¿Cuantas cuentas en redes sociales vas a guardar de este contacto?" << endl;
		cin >> redes;
		cin.ignore(256,'\n');


		linea();

		cout << "Introduce el dni del contacto: " << endl;
		getline(cin,dni);
		c.setDni(dni);

		cout << "Introduce el nombre del contacto: " << endl;
		getline(cin,nombre);
		c.setNombre(nombre);

		cout << "Introduce los apellidos del contacto: " << endl;
		getline(cin,apellidos);
		c.setApellidos(apellidos);

		cout << "Introduce el telefono del contacto: " << endl;
		getline(cin,telefono);
		c.setTelefono(telefono);

		cout << "Introduce el movil del contacto: " << endl;
		getline(cin,movil);
		c.setMovil(movil);

		cout << "Introduce el email del contacto: " << endl;
		getline(cin,email);
		c.setEmail(email);

		cout << "Introduce anotaciones del contacto: " << endl;
		getline(cin,anotaciones);
		c.setAnotaciones(anotaciones);


		for(i=0;i<direcciones;i++){

			cout << "Tipo de via: " << endl;
			getline(cin,DireccionAuxiliar.via);

			cout << "Nombre de calle: " << endl;
			getline(cin,DireccionAuxiliar.calle);

			cout << "CP " << endl;
			cin >> DireccionAuxiliar.cp;
			cin.ignore(256,'\n');



			cout << "Numero " << endl;
			cin >> DireccionAuxiliar.numero;
			cin.ignore(256,'\n');


			cout << "Portal: " << endl;
			std::getline(cin,DireccionAuxiliar.portal);

			cout << "Piso " << endl;
			cin >> DireccionAuxiliar.piso;
			cin.ignore(256,'\n');

			cout << "Puerta " << endl;
			getline(cin,DireccionAuxiliar.puerta);

			DireccionAux.push_back(DireccionAuxiliar);

		}

		c.setDirecciones(DireccionAux);

		for(i=0;i<redes;i++){

			cout << "Nombre de la red: " << endl;
			std::getline(cin,RedAuxiliar.nombre);

			cout << "Id de usuario: " << endl;
			std::getline(cin,RedAuxiliar.url);

			RedesAux.push_back(RedAuxiliar);
		}

		c.setRedesSociales(RedesAux);

	}

void MenuTerminal::modificarContacto(){
	std::string dni;
	Contacto c;

	cout << "Introduce el dni del contacto que deseas modificar:" << endl;

	getline(cin,dni);

	this->rellenarContacto(c);

	agenda_.modificar(dni,c);

}

void MenuTerminal::insertarContacto(){
	Contacto c;
	this->rellenarContacto(c);
	agenda_.insertar(c);

}

void  MenuTerminal::borrarContacto(){

	std::string dni;
	cout << "Introduce el dni del contacto que deseas borrar:" << endl;

	std::getline(cin,dni);

	agenda_.eliminar(dni);

}

} /* namespace agenda */
