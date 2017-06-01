#include "Casillas.h"
#include <vector>

#ifndef TABLERO_H
#define TABLERO_H

using namespace std;

class Tablero {
	private:
		vector <Casillas*> casillas;
	public:
		Tablero();
		Casillas* getCasilla(int);
		~Tablero();
};
#endif