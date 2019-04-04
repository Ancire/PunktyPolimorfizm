#include "naglowek.h"

using namespace std;

//PUNKT 1D
Punkt_1D::Punkt_1D(double a)
{
	x = a;
}
void Punkt_1D::wyswietl()
{
	cout << "Punkt_1D x:" << x;
}

double Punkt_1D::dlugosc()
{
	return x;
}

void Punkt_1D::zapisz_do_pliku()
{
	fstream plik;
	plik.open("dane.txt", ios::app);

	if (!plik.good() == true) {
		cout << "Blad odczytu danych z pliku!\n";
	}
	else
	{
		plik << x << endl;
	}

	plik.close();
}

// PUNKT 2D
Punkt_2D::Punkt_2D(double a, double b)
{
	x = a;
	y = b;
}

void Punkt_2D::wyswietl()
{
	cout << "Punkt_2D x:" << x << " y:" << y;
}

double Punkt_2D::dlugosc()
{
	return sqrt(x*x + y * y);
}

void Punkt_2D::zapisz_do_pliku()
{
	fstream plik;
	plik.open("dane.txt", ios::app);

	if (!plik.good() == true) {
		cout << "Blad odczytu danych z pliku!\n";
	}
	else
	{
		plik << x << " " << y << endl;
	}

	plik.close();
}


//PUNKT 3D


Punkt_3D::Punkt_3D(double a, double b, double c)
{
	x = a;
	y = b;
	z = c;
}

void Punkt_3D::wyswietl()
{
	cout << "Punkt_3D x:" << x << " y:" << y << " z:" << z;
}

double Punkt_3D::dlugosc()
{
	return sqrt(x * x + y * y + z * z);
}

void Punkt_3D::zapisz_do_pliku()
{
	fstream plik;
	plik.open("dane.txt", ios::app);

	if (!plik.good() == true) {
		cout << "Blad odczytu danych z pliku!\n";
	}
	else
	{
		plik << x << " " << y << " " << z << endl;
	}

	plik.close();
}





//POZOSTA£E

int spacje(string napis)
{
	int ilosc_spacji = 0;
	for (int i = 0; i < napis.length(); i++)
	{
		if (napis[i] == ' ')
			ilosc_spacji++;
	}

	return ilosc_spacji;
}

vector<string> wczytajDanePlik(const string path)
{
	fstream plik;
	string linia;
	vector<string> dane;
	plik.open(path, ios::in);

	if (!plik.good() == false) {
		cout << "Blad odczytu pliku!\n";
	}

	while (!plik.eof())
	{
		getline(plik, linia);
		dane.push_back(linia);
	}

	plik.close();

	return dane;
}


vector<string> wczytajDaneUzytkownika()
{
	vector<string> dane;
	string linia;
	int ilosc_spacji = 0;
	cout << "Podaj dowolne wektory 1,2,3 wymiarowe skladowe wektorw odziel sapcja\n";
	cout << "Aby zakonczyc wczytywanie wpisz pusty wiersz >";

	while (1)
	{
		cout << "punkt >";
		getline(cin, linia);
		if (linia.length() < 1) {
			break;
		}

		ilosc_spacji = spacje(linia);

		switch (ilosc_spacji)
		{
		case 0:
		{
			cout << "Wprowadzono poprawny punkt 1 wymiarowy\n";
			dane.push_back(linia);
		}break;
		case 1:
		{
			cout << "Wprowadzono poprawny punkt 2 wymiarowy\n";
			dane.push_back(linia);
		}break;
		case 2:
		{
			cout << "Wprowadzono poprawny punkt 3 wymiarowy\n";
			dane.push_back(linia);
		}break;
		default:
		{
			cout << "Wprowadzony punkt : " << linia << " : jest niepoprawny i nie zostal wprowadzony do rejestru danych\n";
		}break;

		}

	}

	return dane;
}


vector<string> podzielNaLiczby(string napis)
{
	vector<string> liczby;
	int pomoc = 0;
	for (int i = 0; i < napis.length(); i++)
	{
		if (napis[i] == ' ')
		{
			liczby.push_back(napis.substr(pomoc, i - pomoc));
			pomoc = i + 1;
		}
	}

	liczby.push_back(napis.substr(pomoc, napis.length() - pomoc));
	return liczby;
}

vector<vector<int>> vecStrintToInt(vector<vector<string>> &napisy)
{
	vector<vector<int>> cyfry;
	vector<int> tab;
	for (int i = 0; i < napisy.size(); i++)
	{
		tab.clear();
		for (int j = 0; j < napisy[i].size(); j++)
		{
			tab.push_back(atoi(napisy[i][j].c_str()));
		}
		cyfry.push_back(tab);
	}

	return cyfry;
}