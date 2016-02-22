#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

class Diccionario
{
public:
	string path = "sowpods.txt";
	ifstream file;
	virtual void opendiccionario() = 0;
	virtual bool search(string word) = 0;
	virtual void closediccionario() = 0;
	Diccionario();
	~Diccionario();
};

