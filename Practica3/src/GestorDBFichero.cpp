/*
 * gestorDBFichero.cpp

 *
 *  Created on: 10/12/2014
 *      Author: i22feloj
 */

#include "Contacto.h"
#include<list>
#include<fstream>
#include<cstdlib>

#include <cstring>
//#include<iostream>//solo por depuracion para cout, quitarlo luego
#include "GestorDBFichero.h"

using namespace std;

namespace agenda{

	bool GestorDBFichero::guardar(std::list<Contacto> lista) {

		std::list<Contacto>::iterator c;
		std::list<Direccion>:: iterator d;
		std::list<RedSocial>:: iterator r;


		std::ofstream archivo;
		archivo.open(getNomFich().c_str());
		if(archivo.is_open()){


			for(c=lista.begin();c!=lista.end();c++){//Lista de contactos


				archivo << c->getDni() << ",";
				archivo << c->getNombre() << ",";
				archivo << c->getApellidos() << ",";
				archivo << c->getTelefono() << ",";
				archivo << c->getMovil() << ",";
				archivo << c->getEmail() << ",";
				archivo << c->getAnotaciones() << "\n";


				std::list<Direccion> dir = (*c).getDirecciones();


				for(d=dir.begin();d!=dir.end();d++){//Lista de direcciones
					archivo << d->via << ",";
					archivo << d->calle << ",";
					archivo << d->cp << ",";
					archivo << d->numero << ",";
					archivo << d->portal << ",";
					archivo << d->piso << ",";
					archivo << d->puerta << "\n";
				}



				std::list<RedSocial> red = (*c).getRedesSociales();



				for(r=red.begin();r!=red.end();r++){//Lista de redes sociales
					archivo << r->nombre << ",";
					archivo << r->url << "\n";

				}

			}
		archivo.close();
		return true;//Guardado en fichero con exito
		}

		return false;//Error en apertura de fichero
	}

	std::list<Contacto> GestorDBFichero::cargar() {

		//Variables auxiliares del getline
		char dni[9],nombre[30],apellidos[60],telefono[12],movil[12],email[20],anotaciones[300];//D.Personales
		char via[20],calle[60],cp[10],numero[4],portal[2],piso[2],puerta[2];//D.Direccion
		char red[20],url[40];//D.Red social
		int i;

		std::list<Direccion> auxDirecciones;
		Direccion auxDireccion;

		std::list<RedSocial> auxRedesSociales;
		RedSocial auxRed;

		std::list<Contacto> auxContactos;
		Contacto auxContacto;

		std::ifstream archivo;
		archivo.open(getNomFich().c_str());

		if(archivo.is_open()){


					while(archivo.getline(dni,200,',')){ //Datos personales
					archivo.getline(nombre,200,',');
					archivo.getline(apellidos,200,',');
					archivo.getline(telefono,200,',');
					archivo.getline(movil,200,',');
					archivo.getline(email,200,',');
					archivo.getline(anotaciones,200,'\n');

					auxContacto.setDni(dni);
					auxContacto.setNombre(nombre);
					auxContacto.setApellidos(apellidos);
					auxContacto.setTelefono(telefono);
					auxContacto.setMovil(movil);
					auxContacto.setEmail(email);
					auxContacto.setAnotaciones(anotaciones);


					auxDirecciones.clear();//limpiamos lista de direcciones

				for(i=0;i<3;i++){
					archivo.getline(via,200,',');
					archivo.getline(calle,200,',');
					archivo.getline(cp,200,',');
					archivo.getline(numero,200,',');
					archivo.getline(portal,200,',');
					archivo.getline(piso,200,',');
					archivo.getline(puerta,200,'\n');

					auxDireccion.via =via;
					auxDireccion.calle=calle;
					auxDireccion.cp=cp;
					auxDireccion.numero=numero;
					auxDireccion.portal=portal;
					auxDireccion.piso=piso;
					auxDireccion.puerta=puerta;


					auxDirecciones.push_back(auxDireccion);//Añadimos nuevo elemento de direccion a la lista
				}

					auxContacto.setDirecciones(auxDirecciones);//Añadimos esta lista de direcciones al contacto

					auxRedesSociales.clear();


					for(i=0;i<5;i++){
						archivo.getline(red,200,',');
						archivo.getline(url,200,'\n');

						auxRed.nombre=red;
						auxRed.url=url;
						auxRedesSociales.push_back(auxRed);
					}
					auxContacto.setRedesSociales(auxRedesSociales);

				auxContactos.push_back(auxContacto);

			}

			archivo.close();
		}
		return auxContactos;//Al colocarlo aqui en caso de no haber nada en el fichero devuelve lista vacia
	}
}
