/*
 * Agenda.h
 *
 *  Created on: 03/12/2014
 *      Author: i02coprg
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include<string>
#include "Contacto.h"
#include <list>

namespace agenda{
class Agenda {
private:
	std::list<Contacto> contactos_;

public:
	Agenda();

	virtual ~Agenda();
};
}
#endif /* AGENDA_H_ */
