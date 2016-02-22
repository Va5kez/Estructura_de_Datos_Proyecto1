#include "Jugador.h"


Jugador::Jugador(string n, int t)
{
	name = n;
	points = 0;
	turno = t;
}


Jugador::~Jugador()
{
}

void Jugador::setletters(Sprite *s){
	if (letters[0] = NULL){
		letters[0] = s;
	}
	letters[con] = s;
	con++;
}

void Jugador::setpoints(int p){
	points+=p;
}

int Jugador::getpoints(){
	return points;
}