#include "Dictionary.h"
#include <iostream>
#include <ofstream>
#include <string>

using namespace std;

Dictionary::Dictionary()
{
	string path = "sowpods.txt";
	ifstream file(path);

	if (file.is_open())
	{
		string word, flag = "yes";
		ifstream file(path);
		while (word != flag)
		{
			file.seekg(0);
			cout << "Write the word you're searching for (to exit type no):\n";
			string word;
			cin >> word;
			flag = word;
			if (flag == "no")
			{
				cout << "YOU HAVE CLOSE THE PROGRAM SUCCESSFULLY" << endl;
				file.close();
				break;
			}
			string search;
			while (file >> search)
			{
				if (word == search)
				{
					cout << "Word has been found" << endl;
					break;
				}
			}
		}
	}
}


Dictionary::~Dictionary()
{
}
