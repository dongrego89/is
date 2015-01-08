/*
 * MenuTerminal.cpp
 *
 *  Created on: 17/12/2014
 *      Author: i02coprg
 */

#include "MenuTerminal.h"
#include "Agenda.h"
#include "Contacto.h"
#include <list>
#include <cstring>
#include <iostream>
#include <cstdlib>

using namespace std;

namespace agenda {

void MenuTerminal::visualizarContacto(Contacto_it iterador)
{

		Contacto c=*iterador;
		std::list<Direccion>::iterator d;
		std::list<RedSocial>::iterator r;

		linea();

		cout <<"\t\t\t"<< "Nombre y Apellidos: " << c.getNombre() << " " << c.getApellidos() <<" DNI: "<< c.getDni() << endl;
		cout <<"\t\t\t"<< "Telefono: " << c.getTelefono() << " Movil: " << c.getMovil() << endl;
		cout <<"\t\t\t"<< "Email: " << c.getEmail() << endl <<"\t\t\t"<< "Anotaciones: " << endl << "\t\t\t'"<< c.getAnotaciones() << "'" << endl;
		cout <<endl<<"\t\t\t" <<"Direccion/es: " << endl;


		std::list<Direccion> ld =c.getDirecciones();

		for(d=ld.begin();d!=ld.end();d++)
		{
			if(d->via!="")
			{
				cout <<"\t\t\t"<<"| Codigo postal: "<< d->cp<<" | "<< d->via <<" "<< d->calle  << " |"<<"\n\t\t\t| Nº"<< d->numero << " | Portal: " << d->portal << " | Piso: " << d->piso << " | Puerta:" << d->puerta <<" |"<<endl;

			}

		}

		cout << endl<<"\t\t\t"<< "Red/es Social/es: "<<endl;


		std::list<RedSocial> rs =c.getRedesSociales();



		for(r=rs.begin();r!=rs.end();r++)
		{
			if(r->nombre!="")
			{
				cout<<"\t\t\t"<< "Nombre de red social: " << r->nombre << " Usuario: " << r->url<<endl;
			}
		}

		cout << "\t\t\t---------------------------------------------------------------------------------\n";
}

void MenuTerminal::visualizarAgenda()
{
	std::list<Contacto>auxiliar;
	auxiliar=agenda_.mostrarAgenda();
	Contacto_it i;

	cout << "\t\t\t---------------------------------------------------------------------------------\n";
	cout <<"\t\t\t"<<"*******************************AGENDA DE CONTACTOS*******************************";
	cout << "\n\t\t\t---------------------------------------------------------------------------------\n\n";
	if(!auxiliar.empty())
	{
		for(i=auxiliar.begin();i!=auxiliar.end();i++)
		{
			this->visualizarContacto(i);//Imprimir contacto a contacto
		}
	}
	else
	{
		linea();
		cout <<"\n\t\t\t\t\t" <<"*Actualmente no hay contactos en la agenda.\n";
		linea();
	}
}

	void MenuTerminal::rellenarContacto(Contacto &c){
		int redes, direcciones,i,e;

		std::string dni,nombre,apellidos,telefono,movil,email,anotaciones,dire,red;



		RedSocial RedAuxiliar;
		std::list<RedSocial> RedesAux;

		Direccion DireccionAuxiliar;
		std::list<Direccion> DireccionAux;

		linea();

		cout <<"\t\t\t"<< "¿Cuantas direcciones vas a guardar de este contacto? (Máximo 3)" << endl<<"\t\t\t";
		getline(cin,dire);

		direcciones=atoi(dire.c_str());//Si meto una letra atoi() la convierte a 0, por lo tanto si hay equivocacion
										//metiendo una letra se guardarán 0 direcciones, ni te las pide que las metas.

		//es un problema que atoi devuelva 0 si meto una letra, porque si meto 0 por teclado
		//no puedo diferenciar esos dos casos
		if((direcciones>3) || (direcciones<0)) //Si he metido un numero de direcciones que no se puede meter, direcciones=0
		{
			direcciones=0;
		}

		cout <<"\t\t\t"<< "¿Cuantas cuentas en redes sociales vas a guardar de este contacto? (Máximo 5)" << endl<<"\t\t\t";
		getline(cin,red);

		redes=atoi(red.c_str()); //Si meto una letra atoi() la convierte a 0, por lo tanto si hay equivocacion
								//metiendo una letra se guardarán 0 redes, ni te las pide que las metas.

		cout<<"\nredes antes:"<<redes;
		if((redes>3) || (redes<0)) //Si he metido un numero de redes que no se puede meter, redes=0
		{
			cout<<"\nredes if:"<<redes;
			redes=0;
		}
		cout<<"\nredes dspues if:"<<redes;

		linea();

		cout <<"\t\t\t"<< "Introduce el dni del contacto: " << endl<<"\t\t\t";
		getline(cin,dni);
		c.setDni(dni);

		cout <<"\t\t\t"<< "Introduce el nombre del contacto: " << endl<<"\t\t\t";
		getline(cin,nombre);
		c.setNombre(nombre);

		cout <<"\t\t\t"<< "Introduce los apellidos del contacto: " << endl<<"\t\t\t";
		getline(cin,apellidos);
		c.setApellidos(apellidos);

		cout <<"\t\t\t"<< "Introduce el telefono del contacto: " << endl<<"\t\t\t";
		getline(cin,telefono);
		c.setTelefono(telefono);

		cout <<"\t\t\t" << "Introduce el movil del contacto: " << endl<<"\t\t\t";
		getline(cin,movil);
		c.setMovil(movil);

		cout <<"\t\t\t" << "Introduce el email del contacto: " << endl<<"\t\t\t";
		getline(cin,email);
		c.setEmail(email);

		cout <<"\t\t\t"<< "Introduce anotaciones del contacto: " << endl<<"\t\t\t";
		getline(cin,anotaciones);

		c.setAnotaciones(anotaciones);


		for(i=0;i<direcciones;i++){

			cout <<"\t\t\t"<< "Código postal: " << endl<<"\t\t\t";
			getline(cin,DireccionAuxiliar.cp);

			cout <<"\t\t\t"<< "Tipo de via: " << endl<<"\t\t\t";
			getline(cin,DireccionAuxiliar.via);

			cout <<"\t\t\t"<< "Nombre de la via: " << endl<<"\t\t\t";
			getline(cin,DireccionAuxiliar.calle);

			cout <<"\t\t\t"<< "Numero " << endl<<"\t\t\t";
			getline(cin,DireccionAuxiliar.numero);

			cout <<"\t\t\t" << "Portal: " << endl<<"\t\t\t";
			getline(cin,DireccionAuxiliar.portal);

			cout <<"\t\t\t"<< "Piso " << endl<<"\t\t\t";
			getline(cin,DireccionAuxiliar.piso);

			cout <<"\t\t\t"<< "Puerta " << endl<<"\t\t\t";
			getline(cin,DireccionAuxiliar.puerta);

			DireccionAux.push_back(DireccionAuxiliar);

		}

		for(e=i;e<3;e++){//Añade los que faltan como vacío
			DireccionAuxiliar.via="";
			DireccionAuxiliar.calle="";
			DireccionAuxiliar.cp="";
			DireccionAuxiliar.numero="";
			DireccionAuxiliar.portal="";
			DireccionAuxiliar.piso="";
			DireccionAuxiliar.puerta="";

			DireccionAux.push_back(DireccionAuxiliar);

		}

		c.setDirecciones(DireccionAux);

		for(i=0;i<redes;i++)
		{

			cout <<"\t\t\t"<< "Nombre de la red social: " << endl<<"\t\t\t";
			std::getline(cin,RedAuxiliar.nombre);

			cout <<"\t\t\t" << "Id de usuario: " << endl<<"\t\t\t";
			std::getline(cin,RedAuxiliar.url);

			RedesAux.push_back(RedAuxiliar);
		}


		for(e=i;e<5;e++) //Añade los que faltan como vacío
		{
			RedAuxiliar.nombre="";
			RedAuxiliar.url="";
			RedesAux.push_back(RedAuxiliar);
		}

		c.setRedesSociales(RedesAux);
		linea();
}

void MenuTerminal::buscarContacto(){
		std::string apellido;
		linea();
		cout <<"\t\t\t"<< "Introduce el/los apellido/s del contacto que desea buscar:"<<endl<<"\t\t\t";
		std::getline(cin,apellido);

		std::list<Contacto>auxiliar;

		auxiliar=agenda_.buscarApellido(apellido);

		if(auxiliar.empty())
		{
			linea();
			cout <<"\n\t\t\t\t\t" <<"*No se han encontrado resultados en la búsqueda.\n";
			linea();
		}

		Contacto_it i;

		for(i=auxiliar.begin();i!=auxiliar.end();i++)
		{
			this->visualizarContacto(i);//Imprimir contacto a contacto
		}

	}




void MenuTerminal::modificarContacto(){

	Contacto c;
	std::string apellido,dni,coin,opcion;
	std::list<Contacto> auxiliar;
	std::list<Contacto>::iterator i,j;
	int contador=1,aux,k,var;
	linea();
	cout <<"\t\t\t"<< "Introduce el/los apellido/s para buscar al contacto que desea modificar:"<<endl<<"\t\t\t";
	std::getline(cin,apellido);
	cout <<"\n";

	auxiliar=agenda_.buscarApellido(apellido);


	if(!auxiliar.empty())
	{
		linea();
		cout <<"\t\t\tCoincidencias: ("<<auxiliar.size()<<")\n";

		for(i=auxiliar.begin();i!=auxiliar.end();i++)
		{	cout<<"\t\t\t\t\t\t\t\t|"<<contador<<"|";
			this->visualizarContacto(i);
			contador++;
		}

		j=auxiliar.begin();

		var=auxiliar.size();

		if(auxiliar.size()>1)
		{
			cout <<"\n\t\t\t"<< "Ahora introduce el número de coincidencia que deseas modificar:"<<endl<<"\t\t\t";
			std::getline(cin,coin);
			cout <<"\n";

			aux=atoi(coin.c_str());
			if((aux>=1) && (aux<=var) )//si el numero introducido está en el rango que debe estar..
			{
				for(k=1;k<aux;k++)
				{
					j++;
				}


				if(agenda_.buscarDni(j->getDni()))
				{
					this->rellenarContacto(c);
					if(agenda_.modificar(j->getDni(),c))
					{
						linea();
						cout <<"\n\t\t\t\t\t\t" <<"*Modificado con éxito.\n";
						linea();
					}
				}
			}
			else
			{
				linea();
				cout <<"\n\t\t\t\t" <<"*Error, el número de coincidencia introducido no es válido.\n";
				linea();
			}
		}
		else
		{
			cout <<"\n\t\t\t"<< "¿Está seguro de que desea modificar este contacto? (s/n)"<<endl<<"\t\t\t";
			std::getline(cin,opcion);


			if(opcion=="s")
			{

					if(agenda_.buscarDni(j->getDni()))
					{

						this->rellenarContacto(c);
						if(agenda_.modificar(j->getDni(),c))
						{
							linea();
							cout <<"\n\t\t\t\t\t\t" <<"*Modificado con éxito.\n";
							linea();
						}
					}

			}
			else
			{
				linea();
				cout <<"\n\t\t\t\t\t\t" <<"*Contacto no modificado.\n";
				linea();
			}

		}

	}//if auxiliar.empty()
	else
	{
		linea();
		cout <<"\n\t\t\t\t\t" <<"*No se han encontrado resultados en la búsqueda.\n";
		linea();
	}
}





void MenuTerminal::insertarContacto(){
	Contacto c;
	this->rellenarContacto(c);
	if(agenda_.insertar(c))
	{
		cout <<"\n\t\t\t\t\t" <<"*Nuevo contacto guardado correctamente.\n";
		linea();
	}

}

void  MenuTerminal::borrarContacto(){

	std::string dni,apellido,coin,opcion;
	int contador=1,aux,k,var;
	std::list<Contacto> auxiliar;
	std::list<Contacto>::iterator i,j;

	linea();
	cout <<"\t\t\t"<< "Introduce el/los apellido/s para buscar al contacto que desea borrar:"<<endl<<"\t\t\t";
	std::getline(cin,apellido);
	cout <<"\n";



	auxiliar=agenda_.buscarApellido(apellido);

	if(!auxiliar.empty())
	{
		linea();
		cout <<"\t\t\tCoincidencias: ("<<auxiliar.size()<<")\n";
		for(i=auxiliar.begin();i!=auxiliar.end();i++)
		{
			cout<<"\t\t\t\t\t\t\t\t|"<<contador<<"|";
			this->visualizarContacto(i);
			contador++;
		}

		j=auxiliar.begin();

		var=auxiliar.size();

		if(auxiliar.size()>1) //Si hay mas de una coincidencia, pedir que coincidencia quiere borrar.
		{
			cout <<"\n\t\t\t"<< "Ahora introduce el número de coincidencia que deseas borrar:"<<endl<<"\t\t\t";
			std::getline(cin,coin);
			cout <<"\n";

			aux=atoi(coin.c_str());
			if((aux>=1) && (aux<=var) )//si el numero introducido está en el rango que debe estar..
			{

				for(k=1;k<aux;k++) //si queremos borrar la coincidencia número 1 no entraría aquí
				{                 //y la j que cogería sería la que ya está inicializada fuera j=auxiliar.begin()
					j++;
				}

				if(agenda_.eliminar(j->getDni()))
				{
					linea();
					cout <<"\n\t\t\t\t\t\t" <<"*Borrado con éxito.\n";
					linea();
				}
				else
				{
					linea();
					cout <<"\n\t\t\t\t\t\t" <<"*Error eliminando.\n";
					linea();
				}
			}
			else
			{
				linea();
				cout <<"\n\t\t\t\t\t" <<"*Error, el número de coincidencia introducido no es válido.\n";
				linea();
			}
		}
		else
		{
			cout <<"\n\t\t\t"<< "¿Está seguro de borrar este contacto? (s/n)"<<endl<<"\t\t\t";
			std::getline(cin,opcion);

			if(opcion=="s")
			{
					if(agenda_.eliminar(j->getDni()))
					{
						linea();
						cout <<"\n\t\t\t\t\t\t" <<"*Borrado con éxito.\n";
						linea();
					}
					else
					{
						linea();
						cout <<"\n\t\t\t\t\t\t" <<"*Error eliminando.\n";
						linea();
					}
			}
			else
			{
				linea();
				cout <<"\n\t\t\t\t\t\t" <<"*Contacto no borrado.\n";
				linea();

			}
		}// else del if de auxiliar.size()

	}//fin del if auxiliar.empty()
	else
	{
		linea();
		cout <<"\n\t\t\t\t\t" <<"*No se han encontrado resultados en la búsqueda.\n";
		linea();
	}
}//fin de la funcion borrar

} /* namespace agenda */
