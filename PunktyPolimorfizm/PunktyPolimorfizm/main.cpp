#include "naglowek.h"


using namespace std;

const string filePath = "C:/Users/grimb/Desktop/dane.txt";

int main()
{

	//TODO poprawic wprowadzanie danych aby usuwalo sie wielokrotnosci spacji wprowadzonych przez uzytkownika

	//vector<string> dane;
	//vector<vector<string>> liczby;
	//vector<vector<int>> cyfry;


	////dane = wczytajDaneUzytkownika();
	//dane = wczytajDanePlik(filePath);

	//for (int i = 0; i < dane.size(); i++)
	//{
	//	liczby.push_back(podzielNaLiczby(dane[i]));
	//}

	//cyfry = vecStrintToInt(liczby);
	//
	//Punkt **punkt = new Punkt*[liczby.size()];

	//for (int i = 0; i < cyfry.size(); i++)
	//{
	//	switch (cyfry[i].size())
	//	{

	//	case 1:
	//	{
	//		punkt[i] = new Punkt_1D(cyfry[i][0]);
	//	}break;

	//	case 2:
	//	{
	//		punkt[i] = new Punkt_2D(cyfry[i][0], cyfry[i][1]);
	//	}break;

	//	case 3:

	//	{
	//		punkt[i] = new Punkt_3D(cyfry[i][0], cyfry[i][1], cyfry[i][2]);
	//	}break;

	//	default: 
	//	{
	//		cout << "nie dzialam";
	//	}break;

	//	}
	//}

	//for (int i = 0; i < cyfry.size(); i++)
	//{
	//	punkt[i]->wyswietl();
	//	//punkt[i]->zapisz_do_pliku();
	//	cout << "   dlugosc =";
	//	cout << punkt[i]->dlugosc();
	//	cout << endl;
	//}

	//int *index = new int[cyfry.size()];
	//
	//sortujPunkty(punkt,cyfry.size());
	//cout << "Po sortowaniu\n";
	//wyswietlPunkty(punkt,cyfry.size());


	drawMenu();



	system("pause");
	return 0;
}
