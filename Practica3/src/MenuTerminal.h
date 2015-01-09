/*
 * MenuTerminal.h
 *
 *  Created on: 17/12/2014
 *      Author: i02coprg
 */

#ifndef MENUTERMINAL_H_
#define MENUTERMINAL_H_

#include "Agenda.h"
#include "Contacto.h"
#include <iostream>

namespace agenda {

class MenuTerminal {
private:
	Agenda agenda_;
public:
	MenuTerminal(Agenda a):agenda_(a){};
	void visualizarContacto(Contacto_it iterador);//Visualizará los datos de un contacto

	void buscarContacto();//Pide el apellido para el usuario a buscar y crea una lista de contactos encontrados para imprimir uno a uno

	void visualizarAgenda();//Visualizar la agenda completa, y llamar a visualizar contacto para imprimirlos uno a uno

	void visualizarFrecuentes();

	void rellenarContacto(Contacto &c);//Rellena un objeto de tipo contacto

	void modificarContacto();//Pide un dni para modificar sus datos, y uno a uno sus datos para rellenar un objeto ficticio
	//que reemplazará al original en la agenda

	void borrarContacto();//Pide un dni para borrar el contacto usando el método de la agenda

	void insertarContacto();//Pide un objeto a rellenar campo a campo con los datos del contacto y llama al metodo correspondiente en agenda

	void copiaSeguridad();

	inline void linea(){
		std::cout << "\n\t\t\t---------------------------------------------------------------------------------\n";

	}

	void imprimeFormato(){agenda_.imprimirHTML();}
};

} /* namespace agenda */
#endif /* MENUTERMINAL_H_ */
