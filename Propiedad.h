#include "Casillas.h"
#pragma once

using namespace std;

class Propiedad : public Casillas{
	private:
		bool libre; //indica si la casilla no tiene dueño
		double precio; //información para venderla
		//información para calcular renta
		int casas, hoteles;
		double rentaNormal;
		double rentaTodas; //todas las propiedades del mismo color
		double rentaUnaCasa;
		double rentaDosCasas;
		double rentaTresCasas;
		double rentaCuatroCasas;
		double rentaHotel;
		double precioCasa;
		double precioHotel;
		//end: información calcular renta
		string color; //color de la propiedad

	public:
		//inicializa libre
		Propiedad();
		//retornar el tipo de casilla: Propiedad
		virtual string getTipo();
		//calcular la renta en base a si el jugador tiene todas las propiedades del mismo color y cantidad de casas y hoteles
		double calcularRenta(bool);
		//marca la propiedad como que tiene dueño
		void vender();
		double getPrecio(); //Tarea
		bool libre(); //Tarea
		int getCasas(); //Tarea
		string getColor(); //Tarea
		//implementación inline
		bool agregarCasa(){
			if (casas < 4){
				casa++;
				return true;
			} else {
				return false;
			}
		}
		void agregarHotel(){
			if (casas == 4){
				hotel = 1;
				casas = 0;
				return true;
			} else {
				return false;
			}
		}
	};