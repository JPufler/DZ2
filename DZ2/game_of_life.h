#ifndef _GAME_OF_LIFE_H_
#define _GAME_OF_LIFE_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class game_of_life {
private:
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool generacija [REDAKA][STUPACA];
	bool sljedecaGeneracija[REDAKA][STUPACA] = { 0 };
	bool slucajna_vrijednost();
	void korak();
	bool status(int brojSusjeda, bool celija);
	int celija_zauzeta(int i, int j);

public:
	game_of_life();
	void dalje();
	void iscrtaj();
};

#endif
