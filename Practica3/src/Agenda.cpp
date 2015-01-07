/*
 * Agenda.cpp
 *
 *  Created on: 03/12/2014
 *      Author: i02coprg
 */
#include<list>
#include<string>
#include<iostream>
#include<fstream>
#include<cstdlib>//Para system
#include<locale>//Para usar tolower

#include "Contacto.h"
#include "Agenda.h"

namespace agenda {

std::string Agenda::minuscula(std::string cadena){
	std::locale loc;
	std::string str=cadena;
	for (std::string::size_type i=0; i<str.length(); ++i)
	   str[i] = std::tolower(str[i],loc);
	return str;
}

std::list<Contacto> Agenda::buscarApellido(std::string apellido) {
	//cargar del fichero
	std::list<Contacto> auxiliar; //fichero completo hecho lista
	auxiliar = GestorDB->cargar();
	std::string apellidos;

	std::list<Contacto> retorno; //lista

	std::list<Contacto>::iterator i;
	for (i = auxiliar.begin(); i != auxiliar.end(); i++) {
		//if (i->getApellidos() == apellido) {

		apellidos=minuscula(i->getApellidos());//pasamos a minuscula los apellidos

		std::size_t encontrado=apellidos.find(minuscula(apellido));//Buscamos el apellido en minuscula en los apellidos del contacto

		if(encontrado!=std::string::npos){//Si hay resultado se añadirá a la lista de retorno
			retorno.push_back(*i); //iterator i es un puntero, por tanto para pasar su valor es necesario el operador *
			// COMENTARIOS: Para añadir funcionalidad de más frecuentes i->incrementarFrecuente();
		}
	}

	return retorno;
}

bool Agenda::buscarDni(std::string dni){
	std::list<Contacto> auxiliar;
	auxiliar = GestorDB->cargar();

	std::list<Contacto>::iterator i;
	bool encontrado = false;

		for (i = auxiliar.begin(); i != auxiliar.end(); i++) {

				if (i->getDni() == dni) {
					encontrado=true;
					/* COMENTARIO: incluso se puede hacer el return aquí para no
					 * seguir recorriendo la lista
					 * return encontrado;
					 */
				}

			}

		/* COMENTARIOS
		if (encontrado==1){
			return true;
		}
		else{
			return false;
		}
		*/

	/* COMENTARIOS No hace falta y además estaba después de return */
	/*GestorDB->guardar(auxiliar); */

	return encontrado;



}







void Agenda::insertar(const Contacto &c) { //Comprobar que se ha insertado? Guardar devuelve un bool , podriamos usarlo?
	std::list<Contacto> auxiliar;
	auxiliar = GestorDB->cargar();
	auxiliar.push_back(c);
	GestorDB->guardar(auxiliar);


}

bool Agenda::eliminar(std::string dni) {
	std::list<Contacto> auxiliar;
	std::list<Contacto>::iterator i,j;
	int encontrado;
	auxiliar = GestorDB->cargar();

	for (i = auxiliar.begin(); i != auxiliar.end(); i++) {
		if (i->getDni() == dni) {
			j=i;
			encontrado=1;
		}
	}

	if(encontrado==1){
		auxiliar.erase(j);
		GestorDB->guardar(auxiliar);
		return true;
	}
	else {
		return false;
	}
}

void Agenda::modificar(std::string dni, Contacto &c) {
	std::list<Contacto> auxiliar;
	auxiliar = GestorDB->cargar();
	std::list<Contacto>::iterator i;


		for (i = auxiliar.begin(); i != auxiliar.end(); i++) {

				if (i->getDni() == dni) {
					*i=c; //iterator i es un puntero, por tanto para pasar su valor es necesario el operador *

				}

			}


		GestorDB->guardar(auxiliar);


}



void Agenda::imprimirHTML(){

	int i=0;

	std::list<Contacto> auxiliar = GestorDB->cargar();
	std::list<Contacto>::iterator c;

	std::list<Direccion>::iterator d;
	std::list<Direccion> direccion;

	std::list<RedSocial>::iterator r;
	std::list<RedSocial>red;



	std::ofstream archivo("agenda.html");

	if(archivo.is_open()){
		archivo << "<!DOCTYPE html><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><meta name='description' content=''><meta name='author' content=''><link rel='icon' href='bootstrap/favicon.ico'><title>Agenda de Pacientes | Grupo i22 | Ingenier&iacute;a del Software</title><!-- Bootstrap core CSS --><link href='bootstrap/css/bootstrap.min.css' rel='stylesheet'><link href='jumbotron-narrow.css' rel='stylesheet'><script src='bootstrap/js/ie-emulation-modes-warning.js'></script><link href='bootstrap/css/plugins/metisMenu/metisMenu.min.css' rel='stylesheet'><link href='bootstrap/css/plugins/social-buttons.css' rel='stylesheet'><link href='bootstrap/css/sb-admin-2.css' rel='stylesheet'><link href='bootstrap/font-awesome/css/font-awesome.min.css' rel='stylesheet' type='text/css'><script src='https://oss.maxcdn.com/respond/1.4.2/respond.min.js'></script></head><body><div class='container'><div class='jumbotron'><h1 style='text-align:center;'>Agenda de Pacientes</h1><h2 style='text-align:center;margin-left:40%;'>Grupo i22 | <small>Ingenería del software</small></h2></div>";
//Cabecera html



		for(c=auxiliar.begin();c!=auxiliar.end();c++){


			archivo << "<div class='row marketing'><div class='panel panel-default'><div class='panel-heading'><h3>" << c->getNombre() << " " << c->getApellidos() << "</h3></div><div class='panel-body'><ul class='nav nav-pills'><li class='active'><a href='#datos"<< i << "-pills' data-toggle='tab'>Datos Personales</a></li><li><a href='#direcciones"<< i << "-pills' data-toggle='tab'>Direcciones</a></li><li><a href='#redes" << i << "-pills' data-toggle='tab'>Redes Sociales</a></li></ul><div class='tab-content'><div class='tab-pane fade in active' id='datos"<<i<<"-pills'><hr></hr>";
				                                    archivo << "<p><strong>Nombre y Apellidos: </strong>"<< c->getNombre() << " " << c->getApellidos() << " <br>";
				                                    archivo << "<strong>DNI: </strong>" << c->getDni() << "<br>";
				                                    archivo << "<strong>Telefono: </strong>" << c->getTelefono() << "<br>";
				                                   archivo << "<strong>Móvil: </strong> " << c->getMovil() << "<br>";
				                                    archivo << "<strong>Correo electrónico: </strong>" << c->getEmail() << "<br>";
				                                    archivo << "<strong>Anotaciones: </strong><p>" << c->getAnotaciones() << "</p></p></div>";

				                                    archivo << "<div class='tab-pane fade' id='direcciones"<<i<<"-pills'>";


				                                    direccion=c->getDirecciones();

				                                    			for(d=direccion.begin();d!=direccion.end();d++){
				                                    				if(d->calle!=""){
				                                    				archivo << "<hr></hr>";

				                                    				archivo << "<p><strong>" << d->via << "</strong> " << d->calle << "<br>";
				                                    				archivo << 	"<strong>Código Postal: </strong> "<< d->cp <<"<br>";
				                                    				archivo << 	"<strong>Nº: </strong>" << d->numero << " <strong>Portal: </strong>" << d->portal << "<br>";
				                                    				archivo << "<strong>Piso: </strong>" << d->piso << " <strong>Puerta: </strong>" << d->puerta << "</p>";
				                                    				}
				                                    			}






				                                    			archivo << "</div> <div class='tab-pane fade' id='redes"<<i<<"-pills'><hr></hr><div class='col-lg-3'>";
				                                    			red=c->getRedesSociales();
				                                    						for(r=red.begin();r!=red.end();r++){

				                                    							if(r->nombre != ""){
				                                    								//archivo << "<div class='red'><img src='src/imagenes/" << r->nombre << ".png'> " << r->url << "</div>";
				                                    								archivo << "<a class='btn btn-block btn-social btn-" << r->nombre << "'>";
				                                    								archivo << "<i class='fa fa-" << r->nombre << "'></i>" << r->url << "</a>";
				                                    							}
				                                    						}


				                    			                          archivo << "<br></div>";



				                                archivo << "</div></div></div></div></div><hr></hr>";
		i++;
		}

		archivo << " <footer class='footer'><p>&copy; i22 Corp. 2014</p> </footer></div> <!-- /container --><!-- jQuery --><script src='bootstrap/js/jquery.js'></script><!-- Bootstrap Core JavaScript --><script src='bootstrap/js/bootstrap.min.js'></script> <!-- Metis Menu Plugin JavaScript --><script src='bootstrap/js/plugins/metisMenu/metisMenu.min.js'></script><!-- Custom Theme JavaScript --><script src='bootstrap/js/sb-admin-2.js'></script><!-- IE10 viewport hack for Surface/desktop Windows 8 bug --><script src='bootstrap/js/ie10-viewport-bug-workaround.js'></script></body></html>";

		archivo.close();

	std::system("firefox file://$PWD/agenda.html");
	}
}
}
