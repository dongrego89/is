/*
 * gestorDBFichero.h
 *
 *  Created on: 10/12/2014
 *      Author: i22feloj
 */

#ifndef GESTORDBFICHERO_H_
#define GESTORDBFICHERO_H_

#include "Contacto.h"
#include <list>
#include <string>

namespace agenda {
class gestorDBFichero {

private:
	std::string nomFich_;


public:
	gestorDBFichero(std::string nomFich);
	bool guardar(std::list<Contacto> lista);
	std::list<Contacto> cargar()=0;

};
}
#endif /* GESTORDBFICHERO_H_ */

