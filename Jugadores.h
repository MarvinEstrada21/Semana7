#include <iostream>
#ifndef CASILLAS_H
#define CASILLAS_H

using namespace std;

class Casillas{
	protected:
		int posicion;
		string nombre;
	public:
		string getNombre();
		void setNombre(string);
		int getPosicion();
		void setPosicion(int);
		//determinar si se puede comprar la casilla
		//determinar el tipo de casilla en forma de un string
		//Propiedad, Ferrocarril, Salida, Cárcel, Impuestos, Arca, Casualidad, Libre, Servicios
		virtual string getTipo() = 0;
		//dueño
		//precio
};
#endif