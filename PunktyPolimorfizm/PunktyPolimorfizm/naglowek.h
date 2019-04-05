#pragma once

#include<iostream>
#include<cmath>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <string>

using namespace std;

class Punkt
{
public:
	virtual void wyswietl() = 0;
	virtual double dlugosc() = 0;

	virtual void zapisz_do_pliku() = 0;
};

class Punkt_1D : public Punkt
{
public:
	double x;
	Punkt_1D();
	Punkt_1D(double a);
	void wyswietl();

	double dlugosc();

	void zapisz_do_pliku();
};

class Punkt_2D : public Punkt
{
public:
	double x, y;
	Punkt_2D();
	Punkt_2D(double a, double b);
	void wyswietl();

	double dlugosc();

	void zapisz_do_pliku();
};

class Punkt_3D : public Punkt
{
public:
	double x, y, z;
	Punkt_3D();
	Punkt_3D(double a, double b, double c);

	void wyswietl();

	double dlugosc();

	void zapisz_do_pliku();
};

bool liczba(string napis);

int spacje(string napis);

void usunSpacje(string &napis);
bool sprawdzPoprawnoscNapisu(string napis);

vector<string> wczytajDanePlik(const string path);
vector<string> wczytajDaneUzytkownika();
vector<string> podzielNaLiczby(string napis);
vector<vector<int>> vecStrintToInt(vector<vector<string>> &napisy);

void sortujPunkty(Punkt **punkty, int size);

void wyswietlPunkty(Punkt **punkty, int size);

void wyczyscPlik(const string path);
void drawMenu();

void menu();

void inicjalizujPunkty(vector<vector<int>> liczby, Punkt **punkty, int size, vector<Punkt_2D> &pkt2, vector<Punkt_3D> &pkt3);

bool wyznacznik_2(Punkt_2D a, Punkt_2D b, Punkt_2D c);

void wspolniowos_2D(vector<Punkt_2D> punkty);