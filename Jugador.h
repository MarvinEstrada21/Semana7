#include <string>
#pragma once
#include "Casillas.h"
#include <vector>
using namespace std;

class Jugador(){
	private:
		string pieza;
		vactor <Casillas*> casillas;
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
}