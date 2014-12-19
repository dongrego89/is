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

		linea();
		cout <<"\t"<< "Nombre y Apellidos: " << c.getNombre() << " " << c.getApellidos() <<" DNI: "<< c.getDni() << endl;
		cout <<"\t"<< "Telefono: " << c.getTelefono() << " Movil: " << c.getMovil() << endl;
		cout <<"\t"<< "Email: " << c.getEmail() << endl <<"\t"<< "Anotaciones: " << endl << "\t'"<< c.getAnotaciones() << "'" << endl;

		cout <<endl<<"\t" <<"Direccion/es: " << endl;


		std::list<Direccion> ld =c.getDirecciones();

		for(d=ld.begin();d!=ld.end();d++){
			if(d->via!=""){
				cout <<endl<<"\t"<<"| "<< d->via <<" "<< d->calle <<" | Codigo postal: "<< d->cp << " | Nº"<< d->numero << " | Portal: " << d->portal << " | Piso: " << d->piso << " | Puerta:" << d->puerta <<" |";

			}

		}

		cout <<endl<< endl<<"\t"<< "Red/es Social/es: " << endl;


		std::list<RedSocial> rs =c.getRedesSociales();



		for(r=rs.begin();r!=rs.end();r++){
			if(r->nombre!=""){
				cout << endl <<"\t"<< "Red Social: " << r->nombre << " Usuario: " << r->url;
			}
		}



		linea();


	}

	void MenuTerminal::buscarContacto(){
		std::string apellido;
		cout <<"\t"<< "Introduce los apellidos del contacto a buscar:"<<endl<<"\t";
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
		cout << "\t_________________________________________________________________________________\n\n";
		cout <<"\t"<<"*******************************AGENDA DE CONTACTOS*******************************";

		for(i=auxiliar.begin();i!=auxiliar.end();i++){
			this->visualizarContacto(i);//Imprimir contacto a contacto
		}
	}

	void MenuTerminal::rellenarContacto(Contacto &c){
		int redes, direcciones,i,e;

		std::string dni,nombre,apellidos,telefono,movil,email,anotaciones;



		RedSocial RedAuxiliar;
		std::list<RedSocial> RedesAux;

		Direccion DireccionAuxiliar;
		std::list<Direccion> DireccionAux;

		cout <<"\t"<<"INSERTANDO CONTACTO: " << endl;

		linea();

		cout <<"\t"<< "¿Cuantas direcciones vas a guardar de este contacto?" << endl<<"\t";
		cin >> direcciones;
		cin.ignore(256,'\n');

		cout <<"\t"<< "¿Cuantas cuentas en redes sociales vas a guardar de este contacto?" << endl<<"\t";
		cin >> redes;
		cin.ignore(256,'\n');


		linea();

		cout <<"\t"<< "Introduce el dni del contacto: " << endl<<"\t";
		getline(cin,dni);
		c.setDni(dni);

		cout <<"\t"<< "Introduce el nombre del contacto: " << endl<<"\t";
		getline(cin,nombre);
		c.setNombre(nombre);

		cout <<"\t"<< "Introduce los apellidos del contacto: " << endl<<"\t";
		getline(cin,apellidos);
		c.setApellidos(apellidos);

		cout <<"\t"<< "Introduce el telefono del contacto: " << endl<<"\t";
		getline(cin,telefono);
		c.setTelefono(telefono);

		cout <<"\t" << "Introduce el movil del contacto: " << endl<<"\t";
		getline(cin,movil);
		c.setMovil(movil);

		cout <<"\t" << "Introduce el email del contacto: " << endl<<"\t";
		getline(cin,email);
		c.setEmail(email);

		cout <<"\t"<< "Introduce anotaciones del contacto: " << endl<<"\t";
		getline(cin,anotaciones);

		c.setAnotaciones(anotaciones);


		for(i=0;i<direcciones;i++){

			cout <<"\t"<< "Tipo de via: " << endl<<"\t";
			getline(cin,DireccionAuxiliar.via);

			cout <<"\t"<< "Nombre de la via: " << endl<<"\t";
			getline(cin,DireccionAuxiliar.calle);

			cout <<"\t"<< "CP " << endl<<"\t";
			getline(cin,DireccionAuxiliar.cp);

			cout <<"\t"<< "Numero " << endl<<"\t";
			getline(cin,DireccionAuxiliar.numero);

			cout <<"\t" << "Portal: " << endl<<"\t";
			getline(cin,DireccionAuxiliar.portal);

			cout <<"\t"<< "Piso " << endl<<"\t";
			getline(cin,DireccionAuxiliar.piso);

			cout <<"\t"<< "Puerta " << endl<<"\t";
			getline(cin,DireccionAuxiliar.puerta);

			DireccionAux.push_back(DireccionAuxiliar);

		}

		for(e=i;e<3;e++){//Añade los que faltan como vacío
			DireccionAuxiliar.via="";
			DireccionAuxiliar.calle="";
			DireccionAuxiliar.cp="";
			DireccionAuxiliar.numero="";
			DireccionAuxiliar.portal="";
			DireccionAuxiliar.piso="";
			DireccionAuxiliar.puerta="";

			cout << "Anadiendo " << DireccionAuxiliar.via << "," << DireccionAuxiliar.calle << endl;

			DireccionAux.push_back(DireccionAuxiliar);

		}

		c.setDirecciones(DireccionAux);

		for(i=0;i<redes;i++){

			cout <<"\t"<< "Nombre de la red: " << endl<<"\t";
			std::getline(cin,RedAuxiliar.nombre);

			cout <<"\t" << "Id de usuario: " << endl<<"\t";
			std::getline(cin,RedAuxiliar.url);

			RedesAux.push_back(RedAuxiliar);
		}


		for(e=i;e<5;e++){//Añade los que faltan como vacío
			RedAuxiliar.nombre="";
			RedAuxiliar.url="";
			cout << "Anadiendo " << RedAuxiliar.nombre << "," <<  RedAuxiliar.url << endl;
			RedesAux.push_back(RedAuxiliar);
		}

		c.setRedesSociales(RedesAux);

	}


void MenuTerminal::modificarContacto(){
	std::string dni;
	Contacto c;

	cout <<"\t"<< "Introduce el dni del contacto que deseas modificar:" << endl<<"\t";
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
	cout <<"\t"<< "Introduce el dni del contacto que deseas borrar:" << endl<<"\t";
	std::getline(cin,dni);

	agenda_.eliminar(dni);

}

} /* namespace agenda */
