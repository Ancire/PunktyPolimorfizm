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

	for (int i = 0; i < dane.size(); i++)
	{
		if (dane[i].length() < 1 || dane[i].length() > 2)
		{
			cout << "Usunieto bledny punktu o wspolzednych: " << dane[i] << endl;
		}
		else
		{
			wynik.push_back(dane[i]);
		}
	}

	return wynik;
}