/*
 * Contacto.h
 *
 *  Created on: 03/12/2014
 *      Author: i02coprg
 */

#ifndef CONTACTO_H_
#define CONTACTO_H_

#include<string>
#include<list>

#define

namespace agenda{

typedef struct{
	std::string nombre;
	std::string url;

}RedSocial;

typedef struct{
	std::string calle;
	int cp;
	int numero;
	std::string portal;
	int piso;
	std::string puerta;
}Direccion;

class Contacto {
private:
	std::string dni_;
	std::string nombre_;
	std::string apellidos_;
	std::string telefono_;
	std::string movil_;
	std::string email_;
	std::string anotaciones_;

	std::list<Direccion> direcciones_;
	RedSocial redesSociales_;


public:
	Contacto(std::string dni,std::string nom, std::string ape,std::string tel,std::string mov, std::string ema,RedSocial red, std::list<Direccion> dir, std::string ano=""){
		dni_=dni;
		nombre_=nom;
		apellidos_=ape;
		telefono_=tel;
		movil_=mov;
		email_=ema;
		anotaciones_=ano;
		direcciones_=dir;
		redesSociales_=red;
	}

};

}
#endif /* CONTACTO_H_ */
