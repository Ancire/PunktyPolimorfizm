#include <iostream>
#include<string>
#include<vector>

#include "ramka.h"

using namespace std;
string koniec = "\\k";
void autor() {
	vector<string>dane;

	dane.push_back("Prac\251 wykona\210 Krzysztof K\210opotowski 249155");
	dane.push_back("2018 Krzysztof K\210opotowski All Rights Reserved \"copyright symbol\"");
	ramka(dane);

}

void instrukcjaObslugi() {
	printf("\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273\n");
	printf("\272    Witaj w programie kt\242ry dla podanego    \272\n");
	printf("\272  tekstu konstruj\251 ramk\251 zadanego rozmiaru  \272\n");
	printf("\272        Poprostu wpisuj dowolny tekst       \272\n");
	printf("\272 Mozesz uzywac entera w celu zmiany wiersza \272\n");
	printf("\272      Tekst wprowadzany jest do momentu     \272\n");
	printf("\272       Wyst\245pienia 2 pustych wierszy        \272\n");
	printf("\272       Po prostu kliknij enter 3 razy       \272\n");
	printf("\272       lub wprowad\253 \\k w nowym wierszu      \272\n");
	printf("\272    W celu zakonczenia wprowadzania tekstu  \272\n");
	printf("\272             aby program dzia\210a\210            \272\n");
	printf("\272        poprawnie dane wiersza musz\245        \272\n");
	printf("\272      zmiescic sie w szerokosci konsoli     \272\n");
	printf("\272         Mi\210ej zabawy uzytkowniku!          \272\n");
	printf("\310\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\274\n");


	printf("\n");
	printf("\n");
	printf("\n");
}


void wczytajDane(vector <string> &dane) {

	bool wczytaj = true;
	int licznik = 0;
	string napis;
	printf("Wprowadz dowolne dane:\n");
	getline(cin, napis);
	dane.push_back(napis);
	if (dane[0] == koniec) {
		wczytaj = false;
	}
	while (wczytaj) {
		getline(cin, napis);
		dane.push_back(napis);
		licznik++;
		if ((dane[licznik - 1] == "" && dane[licznik] == "") || (dane[licznik] == koniec)) {
			wczytaj = false;
		}
	}
	// printf("Wczytano dane! \n");

}


void obrobkaDanych(vector <string> &dane) {


	for (int i = 0; i < dane.size(); i++) {
		if ((dane[i].length() < 1) || (dane[i] == koniec)) {
			dane.erase(dane.begin() + i, dane.begin() + i + 1);
			i--;
		}
	}


}

void wyswietlVector(vector<string> &dane) {
	for (int i = 0; i < dane.size(); i++) {
		cout << "i =" << i << "  " << dane[i] << "  dlugosc =" << dane[i].length() << endl;
	}
}


void ramka(vector <string> &dane) {
	int max = 0;

	for (int i = 0; i < dane.size(); i++) {
		if (dane[i].length() > max) {
			max = dane[i].length();
		}
	}

	int x, y;
	int wysokosc;
	int licznik = 0;
	//Ten fragmend oblicza maxmalna szerokosc calkowita ramki
	int szerokosc = max + 10;
	if (szerokosc % 2 == 1) {
		szerokosc++;
	}
	//Text to zmienna zawierajaca rzeczywisty rozmiar pola tekstowego bez obramowania
	int text = szerokosc - 2;
	//Ten fragment oblicza maxywalna wysokosc calkowita ramki
	wysokosc = (dane.size() * 2) + 1;

	//Pentla ta odpowiada za pierwsza liniej ramki
	for (int i = 0; i < szerokosc; i++) {
		if (i == szerokosc - 1) {
			printf("\273");
		}
		else if (i == 0) {
			printf("\311");
		}
		else {
			printf("\315");
		}
	}
	printf("\n");
	//Ta penla wykonuje sie przez cala wysokosc pola tekstowego bez gornej i dolnej krawedzi ramki
	for (int i = 0; i < wysokosc; i++) {

		//jezeli mamy nieparzysta wartosc wysokosci ramki to oznacza ze chcemy wyswietlic tekst w polu ktestowym
		if (i % 2 == 1) {
			// jezeli dlugosc lancucha znakowego do wyswietlenia w polu tekstowym jest parzysta to obliczamy offset (ilosc spacji) z przodu i stylu wyrazenia.
			//x odpowiada offseto'owi z lewej strony y to offset z prawej strony wyrazenia
			if (dane[licznik].length() % 2 == 0) {
				x = (text - dane[licznik].length()) / 2;
				y = x;
			}
			else {
				x = (text - dane[licznik].length()) / 2;
				y = x + 1;
			}
			//Wyswietlamy krawedz ramki
			printf("\272");
			//Te petle odpowiedznio wstawiaja spacje przed wyrazenie
			for (int j = 0; j < x; j++) {
				printf(" ");
			}
			cout << dane[licznik];
			//Oraz po wypisaniu wyrazenia tak aby szerokosc ramki sie zgadzala i byl stala na calej wysokosci
			for (int j = 0; j < y; j++) {
				printf(" ");
			}
			printf("\272");

			printf("\n");
			//licznik++ odpowiada za zmiane wartosci wyrazenia wektora dane
			licznik++;
		}
		// jezeli przejscie jest parzyste to poprostu odddzielamy przyjscie pusta linija ale wyswietlamy bezgi poziome ramki
		else {
			for (int i = 0; i < szerokosc; i++) {
				if (i == 0 || i == szerokosc - 1) {
					printf("\272");
				}
				else {
					printf(" ");
				}
			}
			printf("\n");
		}

	}

	//Ta pentla rysuje dolna krawedz ramki
	for (int i = 0; i < szerokosc; i++) {
		if (i == szerokosc - 1) {
			printf("\274");
		}
		else if (i == 0) {
			printf("\310");
		}
		else {
			printf("\315");
		}
	}
	printf("\n");
}