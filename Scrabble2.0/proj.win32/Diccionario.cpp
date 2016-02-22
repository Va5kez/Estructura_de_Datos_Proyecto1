#include "Diccionario.h"


Diccionario::Diccionario()
{
}


Diccionario::~Diccionario()
{
}

void Diccionario::opendiccionario(){
	ifstream file(path);
}

bool Diccionario::search(string word){
	file.seekg(0);
	string search;
	while (file >> search)
	{
		if (word == search)
		{
			cout << "WORD EXIST" << endl;
			return true;
		}
	}
	return false;
}

void Diccionario::closediccionario(){
	file.close();
}