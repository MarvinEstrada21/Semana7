#include "Juego.h"
#include "Propiedad.h"
#include "Print.h"
#include "TirarDados.h"

#include <fstream>
#include <iostream>
#include <typeinfo>

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

int Juego::jugar(){
	bool esDelJugadorActual;
	//inicializar todo
	leerJugadores(); //leer jugadores

	//inicializar posiciones jugadores
	for (int i = 0; i < jugadores.size(); ++i){
		posiciones.push_back(0);
	}

	Print print;
	TirarDados tirar;

	//loop
	while (true){
		//determimar a quien le toca jugar
		Jugador* jugadorActual = NULL;
		int posicionJugadorActual; //posicion en el vector de posiciones
		for (int i = 0; i < jugadores.size(); ++i){
			if (jugadores[i] -> getTurno() == turnoActual){
				posicionJugadorActual = i;
				jugadorActual = jugadores[i];
				//mover el turnoActual hacia adelante
				(turnoActual + 1 > jugadores.size()) ? turnoActual = 1 : turnoActual++;
				break;
			}
		}

		cout << "Turno de: " << endl;
		print.printJugador(jugadorActual);

		//tirar dados
		int resultadoDados;
		resultadoDados = tirar.tirada();
		cout << "---Resultado de tirar Dados--------" << endl << resultadoDados << endl << "-------------------" << endl;

		//mover el jugador de caasillas
		int nuevaCasilla = posiciones[posicionJugadorActual] + resultadoDados;
		if (nuevaCasilla >= tablero -> getCantidadCasillas()){
			//regresar al inicio del tablero
			nuevaCasilla -= tablero -> getCantidadCasillas();
		}
		posiciones[posicionJugadorActual] = nuevaCasilla;

		Casillas* casillaActual = NULL;
		try {
			print.printCasilla(casillaActual);
		} catch (int e) {
			cout << "Casilla fuera de rango" << endl;
			cin.get();
		}
		
		//obtener la casilla actual
		try {
			casillaActual = tablero -> getCasilla(nuevaCasilla);
			if (casillaActual != NULL){
				cout << "EL jugador cayó en: " << endl;
				print.printCasilla(casillaActual);
				
				//determinar tipo de casilla
				if (typeid(*casillaActual) == typeid(Propiedad)){
					Propiedad* propiedad = dynamic_cast<Propiedad*>(casillaActual);
					if (propiedad -> estaLibre()){ //si está libre el jugador compra
						double precio = propiedad -> getPrecio();
						if (jugadorActual -> getDinero() > precio){ // si tiene dinero compra
							jugadorActual -> agregarCasilla(casillaActual);
							jugadorActual -> pagar(precio);
							propiedad -> vender();
						} //si tiene dinero
					} //si está libre
				} else { //si no está libre
					//determinar si es el jugador actual
					esDelJugadorActual = false;
					for (int i = 0; i < jugadorActual -> getCasillas().size(); ++i){
						if (jugadorActual -> getCasillas()[i] == casillaActual){
							esDelJugadorActual = true;
						}
					}
				}
				if (esDelJugadorActual){
					//acciones de comprar casas/hoteles
				} else {
					//determinar de quien es
					//determinar la renta
					//pagar la renta
				} // no está libre
			} //es propiedad
		} catch (...) {

		}
			//acciones por casillas
		
	}
	return 0;
}