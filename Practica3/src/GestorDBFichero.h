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

namespace agenda {
	class GestorDBFichero : public GestorDBInterfaz{

	private:
		std::string nomFich_;


	public:
		GestorDBFichero(std::string nomFich) : nomFich_(nomFich){};
		virtual ~GestorDBFichero() {};
		bool guardar(std::list<Contacto> lista);
		std::list<Contacto> cargar();
		std::string getNomFich()const{return nomFich_;}

	};
}
#endif /* GESTORDBFICHERO_H_ */

