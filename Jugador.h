#include "Casillas.h"
#include "Propiedad.h"
#include "Print.h"

#include <string>
#include <vector>
#include <iostream>

#ifndef JUGADOR_H
#define JUGADOR_H

using namespace std;

class Jugador{
	friend class Print;
	private:
		string pieza;
		vector <Casillas*> casillas;
		double dinero;
		int turno;
	public:
		Jugador(); //inicializar
		
		int getTurno(); //Tarea
		void setTurno(int); //Tarea
		
		string getPieza(); //Tarea
		void setPieza(string);
		
		void agregarCasilla(Casillas*); //Tarea pb
		vector <Casillas*> & getCasillas();
		
		double getDinero(); //Tarea
		double recibirDinero(double); //Tarea
		void pagar(double); //Tarea

		bool hasPropertyMonopoly(Propiedad*);

		friend istream& operator >> (istream& in, Jugador& jugador){
			in >> jugador.pieza;
			in >> jugador.dinero;
			in >> jugador.turno;
			return in;
		}
};
#endif