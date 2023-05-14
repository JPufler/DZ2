#include "game_of_life.h"
#include <ctime>
#include <iostream>

bool game_of_life::slucajna_vrijednost()
{
	int n = rand() % 100;
	return (bool)(n>=75);
}

void game_of_life::korak()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			sljedecaGeneracija[i][j] = status(celija_zauzeta(i, j), generacija[i][j]);
		}
	}
	copy(&sljedecaGeneracija[0][0], &sljedecaGeneracija[0][0]+20*40, &generacija[0][0]);
	iscrtaj();
}

bool game_of_life::status(int brojSusjeda, bool celija)
{
	if ((brojSusjeda == 2 && celija) || brojSusjeda == 3)
	{
		return 1;
	}
	return 0;
}

int game_of_life::celija_zauzeta(int i, int j)
{
	int brojSusjeda = 0;

	if (i!=0)
	{
		brojSusjeda += generacija[i - 1][j];
	}
	if (j!=0)
	{
		brojSusjeda += generacija[i][j - 1];
	}
	if (i!=REDAKA-1)
	{
		brojSusjeda += generacija[i + 1][j];
	}
	if (j!=STUPACA-1)
	{
		brojSusjeda += generacija[i][j+1];
	}
	if (i!=0 && j!=0)
	{
		brojSusjeda += generacija[i - 1][j - 1];
	}
	if (i != REDAKA-1 && j != 0)
	{
		brojSusjeda += generacija[i + 1][j - 1];
	}
	if (i != 0 && j != STUPACA-1)
	{
		brojSusjeda += generacija[i - 1][j + 1];
	}
	if (i != REDAKA-1 && j != STUPACA-1)
	{
		brojSusjeda += generacija[i + 1][j + 1];
	}
	return brojSusjeda;
}

game_of_life::game_of_life()
{	
	srand(time(nullptr));
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::dalje()
{
	bool dalje;
	cout << "Dalje? (1/0): ";
	cin >> dalje;
	if (dalje)
	{
		korak();
	}
}

void game_of_life::iscrtaj()
{
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++)
		{
			if (generacija[i][j])
			{
				cout << '*';
			}
			else
			{
				cout << '_';
			}
		}
		cout << endl;
	}
	dalje();
}
