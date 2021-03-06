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

namespace agenda{
	typedef struct{
		std::string nombre;
		std::string url;

	}RedSocial;

	typedef struct{
		std::string via;
		std::string calle;
		std::string cp;
		std::string numero;
		std::string portal;
		std::string piso;
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
		std::list<RedSocial> redesSociales_;
		int frecuencia_;

	public:
		Contacto(/*std::list<RedSocial> red, std::list<Direccion> dir,std::string dni="",std::string nom="", std::string ape="",std::string tel="",std::string mov="", std::string ema="", std::string ano=""*/){
			/*dni_=dni;
			nombre_=nom;
			apellidos_=ape;
			telefono_=tel;
			movil_=mov;
			email_=ema;
			anotaciones_=ano;
			direcciones_=dir;
			redesSociales_=red;*/
		}

	const std::string& getAnotaciones() const {
		return anotaciones_;
	}

	void setAnotaciones(const std::string& anotaciones) {
		anotaciones_ = anotaciones;
	}

	const std::string& getApellidos() const {
		return apellidos_;
	}

	void setApellidos(const std::string& apellidos) {
		apellidos_ = apellidos;
	}

	const std::list<Direccion>& getDirecciones() const {
		return direcciones_;
	}

	void setDirecciones(const std::list<Direccion>& direcciones) {
		direcciones_ = direcciones;
	}

	const std::string& getDni() const {
		return dni_;
	}

	void setDni(const std::string& dni) {
		dni_ = dni;
	}

	const std::string& getEmail() const {
		return email_;
	}

	void setEmail(const std::string& email) {
		email_ = email;
	}

	const std::string& getMovil() const {
		return movil_;
	}

	void setMovil(const std::string& movil) {
		movil_ = movil;
	}

	const std::string& getNombre() const {
		return nombre_;
	}

	void setNombre(const std::string& nombre) {
		nombre_ = nombre;
	}

	const std::string& getTelefono() const {
		return telefono_;
	}

	void setTelefono(const std::string& telefono) {
		telefono_ = telefono;
	}

	const std::list<RedSocial>& getRedesSociales() const {
		return redesSociales_;
	}

	void setRedesSociales(const std::list<RedSocial>& redesSociales) {
		redesSociales_ = redesSociales;
	}

	int getFrecuencia() const {
		return frecuencia_;
	}

	void setFrecuencia(int frecuencia) {
		this->frecuencia_ = frecuencia;
	}
	void aumentaFrecuencia(){
		this->frecuencia_=this->frecuencia_+1;
	}
};

}
#endif /* CONTACTO_H_ */
