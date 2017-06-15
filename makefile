Main:	MainMonopoly.o Casillas.o Juego.o Jugador.o Print.o Propiedad.o Tablero.o Tarjetas.o TirarDados.o
	g++ MainMonopoly.o Casillas.o Juego.o Jugador.o Print.o Propiedad.o Tablero.o Tarjetas.o TirarDados.o -o MainMonopoly

Main.o:	MainMonopoly.cpp Casillas.h Juego.h Jugador.h Propiedad.h Tablero.h Tarjetas.h
	g++ -c MainMonopoly.cpp

Casillas.o:	Casillas.cpp Casillas.h
	g++ -c Casillas.cpp

Juego.o:	Juego.cpp Juego.h Tablero.h Jugador.h
	g++ -c Juego.cpp

Jugador.o:	Jugador.cpp Jugador.h Casillas.h
	g++ -c Jugador.cpp

Print.o:	Print.cpp Print.h
	g++ -c Print.cpp

Propiedad.o:	Propiedad.cpp Propiedad.h Casillas.h
	g++ -c Propiedad.cpp

Tablero.o:	Tablero.cpp Tablero.h Casillas.h
	g++ -c Tablero.cpp

Tarjetas.o:	Tarjetas.cpp Tarjetas.h
	g++ -c Tarjetas.cpp

TirarDados.o:	TirarDados.cpp TirarDados.h
	g++ -c TirarDados.cpp

clean:	
	rm -f *.o MainMonopoly