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
	dinero -= ppagar;
}

void Jugador::agregarCasilla(Casillas* cas){

}

vector<Casillas*> & Jugador::getCasillas(){
	return casillas;
}

bool Jugador::hasPropertyMonopoly(Propiedad* prop){
	string color = prop -> getColor();
	int contador = 0;
	for (int i = 0; i < casillas.size(); ++i){
		Propiedad* contar = dynamic_cast<Propiedad*> (casillas[i]);
		if (contar != NULL){
			//comparar la var color el color de contar
			if (color.compare(contar -> getColor()) == 0){
				contador++;
			}
		}
	}//contar
	//completar función
	if (contador == 3){
		return true;
	} else {
		return false;
	}
}