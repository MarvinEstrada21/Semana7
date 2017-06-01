Main:	MainMonopoly.o Casillas.o Juego.o Jugador.o Propiedad.o Tablero.o
	g++ MainMonopoly.o Casillas.o Juego.o Jugador.o Propiedad.o Tablero.o -o MainMonopoly

Main.o:	MainMonopoly.cpp Casillas.h Juego.h Jugador.h Propiedad.h Tablero.h
	g++ -c MainMonopoly.cpp

Casillas.o:	Casillas.cpp Casillas.h
	g++ -c Casillas.cpp

Juego.o:	Juego.cpp Juego.h Tablero.h Jugador.h
	g++ -c Juego.cpp

Jugador.o:	Jugador.cpp Jugador.h Casillas.h
	g++ -c Jugador.cpp

Propiedad.o:	Propiedad.cpp Propiedad.h Casillas.h
	g++ -c Propiedad.cpp

Tablero.o:	Tablero.cpp Tablero.h Casillas.h
	g++ -c Tablero.cpp


clean:	
	rm -f *.o MainMonopoly