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
	class Agenda {
	private:
		std::list<Contacto> contactos_;
		GestorDBInterfaz * GestorDB;//Revisarlo !!

	public:
		Agenda();

		std::list<Contacto> buscar(std::string apellido, std::string dni="");
		void insertar(const Contacto &c);
		void eliminar(std::string dni);
		void modificar(std::string dni,Contacto &c);
		void ordenar();

	};
}
#endif /* AGENDA_H_ */
