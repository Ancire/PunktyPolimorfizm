#include "naglowek.h"

//VEC 1


//VEC 2

Vec2::Vec2()
{
	setX(0);
	setY(0);
}
Vec2::Vec2(int a, int b)
{
	setX(a);
	setY(b);
}

void Vec2::print()
{
	cout << getX() << ", " << getY() << ", ";
}

void Vec2::setX(int a)
{
	x = a;
}

void Vec2::setY(int a)
{
	y = a;
}

int Vec2::getX()
{
	return x;
}

int Vec2::getY()
{
	return y;
}

double Vec2::modul()
{
	return sqrt(getX()*getX() + getY()*getY());
}


vector<string> getRawData()
{
	fstream plik;
	string linia;
	vector<string> punkty;
	plik.open("dane.txt",ios::in);
	if (!plik.good()) {
		cout << "Blad odczytu danych!\n";
	}
	else
	{
		while (getline(plik,linia))
		{
			punkty.push_back(linia);
		}
	}
	plik.close();
	return punkty;
}



vector<string> correctData(vector<string> &dane)
{
	vector<string> wynik;
	int *spacje = new int[dane.size()+1];
	for (int i = 0; i < dane.size(); i++) 
	{
		spacje[i] = 0;
	}
	for (int i = 0; i < dane.size(); i++)
	{
		for (int j = 0; j < dane[i].length(); j++)
		{
			if (dane[i][j] == ' ') {
				spacje[i]+=1;
			}
		}
	}
	cout << dane.size() << endl;
	for (int i = 0; i < dane.size(); i++)
	{
		if (spacje[i]>2 || spacje[i]<1)
		{
			cout << "dane length: " << dane[i].length() << "  spacje: " << spacje[i] << endl;
			cout << "Usunieto bledny punktu o wspolzednych: " << dane[i] << endl;
		}
		else
		{
			wynik.push_back(dane[i]);
		}
	}

	delete[] spacje;
	
	return wynik;
}