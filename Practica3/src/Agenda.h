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

		std::list<Contacto> buscar(std::string apellido);
		void insertar(const Contacto &c);

		void modificar(Contacto &c);

	};
}
#endif /* AGENDA_H_ */
