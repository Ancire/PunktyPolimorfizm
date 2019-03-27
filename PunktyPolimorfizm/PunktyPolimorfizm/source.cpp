#include "naglowek.h"

//VEC 1

Vec1::Vec1()
{
	setX(0);
}
Vec1::Vec1(double a)
{
	setX(a);
}

void Vec1::print()
{
	cout << getX() << ", ";
}

void Vec1::setX(double a)
{
	x = a;
}

double Vec1::getX()
{
	return x;
}

double Vec1::modul()
{
	return sqrt(getX()*getX());
}


//VEC 2

Vec2::Vec2()
{
	setX(0);
	setY(0);
}
Vec2::Vec2(double a, double b)
{
	setX(a);
	setY(b);
}

void Vec2::print()
{
	cout << getX() << ", " << getY() << ", ";
}

void Vec2::setY(double a)
{
	y = a;
}

double Vec2::getY()
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
	cout << endl;
	for (int i = 0; i < dane.size(); i++)
	{
		if (spacje[i]>2 || spacje[i]<1)
		{
			//cout << "dane length: " << dane[i].length() << "  spacje: " << spacje[i] << endl;
			cout << "Usunieto bledny punktu o wspolzednych: " << dane[i] << endl;
		}
		else
		{
			wynik.push_back(dane[i]);
		}
	}
	cout << endl;
	delete[] spacje;
	
	return wynik;
}

void writeData()
{
	fstream plik;
	string linia;
	plik.open("dane.txt", ios::app);
	if (!plik.good())
	{
		cout << "Blad odczytu danych z pliku \n";
	}
	cout << "aby przerwac wczytywanie wprowadz dowolny znak w nowej linii\n";
	cout << "podaj punkt >";
	while (getline(cin, linia))
	{
		if (linia[0] == '#')
			break;
		cout << "podaj punkt >";
		plik << linia<<endl;
	}

	plik.close();

}


