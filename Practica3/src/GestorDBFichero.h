/*
 * gestorDBFichero.h
 *
 *  Created on: 10/12/2014
 *      Author: i22feloj
 */

#ifndef GESTORDBFICHERO_H_
#define GESTORDBFICHERO_H_

#include "GestorDBInterfaz.h"
#include "Contacto.h"
#include <list>
#include <string>

//#include "GestorDBInterfaz.h"

namespace agenda {
	class GestorDBFichero : public GestorDBInterfaz{

	private:
		std::string nomFich_;


	public:
		GestorDBFichero(std::string nomFich) : GestorDBInterfaz(), nomFich_(nomFich){}

		bool guardar(std::list<Contacto> lista);
		std::list<Contacto> cargar();

	};
}
#endif /* GESTORDBFICHERO_H_ */

