#include "naglowek.h"

using namespace std;

void autor()
{
	cout << "\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273\n";
	cout << "\272                                                                    \272 \n";
	cout << "\272                          Prac\251 Wykona\210                             \272 \n";
	cout << "\272                      Krzysztof K\210opotowski                         \272 \n";
	cout << "\272                     Politechnika Wroc\210awska                        \272 \n";
	cout << "\272                                                                    \272 \n";
	cout << "\310\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\274\n";
}


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
	return sqrt(x*x);
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

bool liczba(string napis)
{
	bool flaga = true;
	for (int i = 0; i < napis.length(); i++)
	{
		if (napis[i] >= '0'&& napis[i] <= '9') {

		}
		else {
			flaga = false;
		}
	}

	return  flaga;
}

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

void usunSpacje(string &napis)
{
	for (int i = napis.size() - 1; i > 0; i--)
	{
		if (napis[i - 1] == ' ' && napis[i] == ' ')
		{
			napis.erase(i, 1);
		}
	}

	if (napis[0] == ' ')
	{
		napis.erase(0, 1);
	}
	if (napis[napis.size() - 1] == ' ')
	{
		napis.erase(napis.size() - 1, 1);
	}
}

bool sprawdzPoprawnoscNapisu(string napis)
{
	vector<string> liczby;
	int start = 0;
	for (int i = 0; i < napis.length(); i++)
	{
		if (napis[i] == ' ')
		{
			liczby.push_back(napis.substr(start, i - start));
			start = i + 1;
		}
	}
	liczby.push_back(napis.substr(start));


	bool flaga = true;
	for (int i = 0; i < liczby.size(); i++)
	{
		if (!liczba(liczby[i]))
		{
			flaga = false;
		}
	}
	return flaga;
}

vector<string> wczytajDanePlik(const string path)
{
	fstream plik;
	string linia;
	vector<string> dane;
	plik.open(path, ios::in);

	if (!plik.good() == true) {
		cout << "Blad odczytu pliku!\n";
	}

	while (!plik.eof())
	{
		getline(plik, linia);
		if (linia.length() > 0) {
			dane.push_back(linia);
		}
	}
	

	plik.close();
	cout << "Dane z pliku zostaly wczytane poprawnie. \n";
	return dane;
}


vector<string> wczytajDaneUzytkownika()
{
	vector<string> dane;
	string linia;
	int ilosc_spacji = 0;
	cout << endl;
	cout << "Podaj dowolne wektory 1,2,3 wymiarowe skladowe wektorw odziel sapcja\n";
	cout << "Aby zakonczyc wczytywanie wpisz pusty wiersz i wcisnij enter >\n";
	
	while (true)
	{
		cout << "punkt >";
		getline(cin, linia);
		if (linia.length() < 1) {
			break;
		}
		usunSpacje(linia);
		if (!sprawdzPoprawnoscNapisu(linia))
		{
			ilosc_spacji = -1;
		}
		else
		{
			ilosc_spacji = spacje(linia);
		}
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

void sortujPunkty(Punkt **punkty, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size-i; j++)
		{
			if (punkty[j]->dlugosc() < punkty[j - 1]->dlugosc())
			{
				swap(punkty[j], punkty[j - 1]);
			}
		}
	}
}

void wyswietlPunkty(Punkt **punkty, int size)
{
	for (int i = 0; i < size; i++)
	{
		punkty[i]->wyswietl();
		cout << "   dlugosc = ";
		cout << punkty[i]->dlugosc();
		cout << endl;
	}
}

void wyczyscPlik(const string path)
{
	fstream plik;
	plik.open(path, ios::out | ios::trunc);
	if (!plik.good() == true) {
		cout << "Blad odczytu pliku!\n";
	}
	plik.flush();
	cout << "Dane z pliku zostaly usuniete!\n";
	_getch();
	plik.close();
}
void drawMenu()
{
	cout << "\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273\n";
	cout << "\272                          MENU G\235\340WNE                               \272 \n";
	cout << "\272                                                                    \272 \n";
	cout << "\272 1.Wczytaj dane z pliku.                                            \272 \n";
	cout << "\272 2.Wczytaj dane od u\276ytkownika.                                     \272 \n";
	cout << "\272 3.Wyczy\230\206 dane z pliku.                                            \272 \n";
	cout << "\272 4.Wy\230wietl dane obecnie u\276ywane.                                   \272 \n";
	cout << "\272 5.Posortuj oraz wy\230wietl dane.                                     \272 \n";
	cout << "\272 6.Ilo\230\206 2 wymiarowych wsp\242\210liniowych punkt\242w.                      \272 \n";
	cout << "\272 7.ILo\230\206 3 wymiarowych wspolniwoych punktow.                        \272 \n";
	cout << "\272 8.Zako\344cz program.                                                 \272 \n";
	cout << "\272                                                                    \272 \n";
	cout << "\310\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\274\n";
	cout << ">";
}

void menu()
{
	bool flaga = true;
	const string path = "C:/Users/grimb/Desktop/dane.txt";
	char wybor;
	vector<string> dane;
	vector<vector<string>> napisy;
	vector<vector<int>> liczby;
	vector<Punkt_2D> punkty_2d;
	vector<Punkt_3D> punkty_3d;

	Punkt **punkty = nullptr;
	while (1)
	{
		system("cls");
		if (flaga)
		{
			autor();
			flaga = false;
		}
		drawMenu();
		wybor = getchar();

		switch (wybor)
		{
		case '1':
		{
			dane = wczytajDanePlik(path);
			for (int i = 0; i < dane.size(); i++)
			{
				napisy.push_back(podzielNaLiczby(dane[i]));
			}
			liczby = vecStrintToInt(napisy);
			punkty = new Punkt*[liczby.size()];
			inicjalizujPunkty(liczby, punkty, liczby.size(),punkty_2d,punkty_3d);
			_getch();

		}break;
		case '2':
		{
			cin.ignore();
			dane = wczytajDaneUzytkownika();

			for (int i = 0; i < dane.size(); i++)
			{
				napisy.push_back(podzielNaLiczby(dane[i]));
			}
			liczby = vecStrintToInt(napisy);
			punkty = new Punkt*[liczby.size()];
			inicjalizujPunkty(liczby, punkty, liczby.size(),punkty_2d,punkty_3d);
			_getch();
			_getch();

		}break;
		case '3':
		{
			wyczyscPlik(path);
		}break;
		case '4':
		{
			if (dane.empty())
			{
				cout << "Brak danych wprowadz dane badz wczytaj je z pliku.\n";
				_getch();

			}
			else
			{
				if (punkty != nullptr)
					wyswietlPunkty(punkty, liczby.size());
				_getch();
			}
		}break;
		case '5':
		{
			if (punkty != nullptr) {
				sortujPunkty(punkty, liczby.size());
				wyswietlPunkty(punkty, liczby.size());
			}
			else
			{
				cout << "Brak danych do srotowania wprowadz dane i sprobuj ponownie. \n";
			}
			_getch();
		}break;
		case '6':
		{
			if (punkty != nullptr) {
				cout << punkty_2d.size();
				if(punkty_2d.size()>2)
				wspolniowos_2D(punkty_2d);
				else
				{
					cout << "Brak wystarczajacej liczby danych aby przeprowadzic obliczenia. \n";
				}
			}
			else
			{
				cout << "Brak danych, wprowadz dane i sprobuj ponownie. \n";
			}
			_getch();
		}break;
		case '7':
		{

		}break;
		case '8':
		{
			char a;
			cout << "Czy na pewno chcesz zakonczyc program? T/N \n";
			cout << ">";
			cin >> a;
			if (a == 'T' || a == 't') {
				exit(0);
			}
			else
			{

			}
			
		}break;
		default:
			break;
		}
	}
}

void inicjalizujPunkty(vector<vector<int>> liczby, Punkt **punkty, int size , vector<Punkt_2D> &pkt2, vector<Punkt_3D> &pkt3)
{
	Punkt_2D p2(0,0);
	Punkt_3D p3(0,0,0);
	for (int i = 0; i < size; i++)
	{
		switch (liczby[i].size())
		{

		case 1:
		{
			punkty[i] = new Punkt_1D(liczby[i][0]);
		}break;

		case 2:
		{
			punkty[i] = new Punkt_2D(liczby[i][0], liczby[i][1]);
			p2.x = liczby[i][0];
			p2.y = liczby[i][1];
			pkt2.push_back(p2);
		}break;

		case 3:

		{
			punkty[i] = new Punkt_3D(liczby[i][0], liczby[i][1], liczby[i][2]);
			p3.x = liczby[i][0];
			p3.y = liczby[i][1];
			p3.z = liczby[i][2];
			pkt3.push_back(p3);
		}break;

		default: 
		{
			cout << "nie dzialam\n";
		}break;

		}
	}
}

bool  wyznacznik_2(Punkt_2D a, Punkt_2D b , Punkt_2D c)
{
	return ((a.y - b.y) / (a.x - b.x)) == ((a.y - c.y) / (a.x - c.x));
}

void wspolniowos_2D(vector<Punkt_2D> punkty)
{
	int count = 0;
	cout << endl;
	/*for (int i = 0; i < punkty.size(); i++)
	{
		punkty[i].wyswietl();cout << endl;
	}
	cout << punkty.size() << endl;*/
	for (int i = 0; i < punkty.size() - 2; i++)
	{
		for (int j = 1+i; j < punkty.size() - 1; j++)
		{
			for (int k = j+1; k < punkty.size(); k++)
			{
				if (wyznacznik_2(punkty[i], punkty[j], punkty[k]))
				{
					//cout << i << " " << j << " " << k << endl;
					count++;
				}
			}
		}
	}

	cout << "W danym zbiorze jest " << count << " trojek punktow wspolniowych.\n";
}