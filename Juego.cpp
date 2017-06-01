#include "Juego.h"
#include <fstream>
#include <iostream>

using namespace std;

Juego::Juego(){
	tablero = new Tablero();
	turnoActual = 1;

}

Juego::~Juego(){
	delete tablero;
	for (int i = 0; i < jugadores.size(); ++i){
		delete jugadores[i];
	}
	//liberar tarjetas

}

void Juego::leerJugadores(){
	ifstream fileJugadores("Jugadores.txt");

	if (fileJugadores.is_open()){
		for (int i = 0; i < 2 ; ++i){
			Jugador* jugador = new Jugador();
			fileJugadores >> *jugador;
			jugadores.push_back(jugador);
		}
		fileJugadores.close();
	}
}