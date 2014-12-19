/*
 * Agenda.h
 *
 *  Created on: 03/12/2014
 *      Author: i02coprg
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include<string>
#include <list>

#include "Contacto.h"
#include "GestorDBInterfaz.h"



namespace agenda{

typedef std::list<Contacto>::iterator Contacto_it;

	class Agenda {
	private:
		std::list<Contacto> contactos_;
		GestorDBInterfaz *GestorDB;

	public:
		Agenda(GestorDBInterfaz * p): GestorDB(p){};

		std::list<Contacto> buscarApellido(std::string apellido);

		Contacto buscarDni(std::string dni);//metodo auxiliar de modificar

		void insertar(const Contacto &c);
		void eliminar(std::string dni);
		void modificar(std::string dni,Contacto &c);
		void ordenar();
		std::list<Contacto> mostrarAgenda(){
			return GestorDB->cargar();
		}




	};
}
#endif /* AGENDA_H_ */
