#pragma once
#include <string>
#include <string.h>
#include <stdlib.h>
#include "cocostudio/CocoStudio.h"

using namespace std;

USING_NS_CC;

class Jugador
{
public:
	string name;
	int con = 1; 
	Sprite *letters[7];
	int points;
	int turno;
	Jugador(string n, int t);
	void setpoints(int p);
	void setletters(Sprite *s);
	int getpoints();
	~Jugador();
};

