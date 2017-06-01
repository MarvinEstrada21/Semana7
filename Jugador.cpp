#include "Jugador.h"

using namespace std;

Jugador::Jugador(){
	pieza = "";
	dinero = 0;
	turno = 0;
}

int Jugador::getTurno(){
	return turno;
}

void Jugador::setTurno(int sturno){
	turno = sturno;
}

string Jugador::getPieza(){
	return pieza;
}

void Jugador::setPieza(string spieza){
	pieza = spieza;
}

double Jugador::getDinero(){
	return dinero;
}

double Jugador::recibirDinero(double rdinero){
	dinero = rdinero;
	return rdinero;
}

void Jugador::pagar(double ppagar){
	dinero - ppagar;
}