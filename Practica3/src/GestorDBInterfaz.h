/*
 * GestorDBInterfaz.h
 *
 *  Created on: 10/12/2014
 *      Author: i22feloj
 */

#ifndef GESTORDBINTERFAZ_H_
#define GESTORDBINTERFAZ_H_

#include "Contacto.h"
#include <list>

namespace agenda {

class GestorDBInterfaz {

	public:
	GestorDBInterfaz();
	virtual bool guardar(std::list<Contacto> lista)=0;
	virtual std::list<Contacto> cargar()=0;
	virtual ~GestorDBInterfaz();
};

}
#endif /* GESTORDBINTERFAZ_H_ */
