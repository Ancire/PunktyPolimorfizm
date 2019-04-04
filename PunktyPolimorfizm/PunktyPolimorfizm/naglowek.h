#pragma once

#include<iostream>
#include<cmath>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

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

	Punkt_1D(double a);
	void wyswietl();

	double dlugosc();

	void zapisz_do_pliku();
};

class Punkt_2D : public Punkt
{
public:
	double x, y;

	Punkt_2D(double a, double b);
	void wyswietl();

	double dlugosc();

	void zapisz_do_pliku();
};

class Punkt_3D : public Punkt
{
public:
	double x, y, z;

	Punkt_3D(double a, double b, double c);

	void wyswietl();

	double dlugosc();

	void zapisz_do_pliku();
};

int spacje(string napis);

vector<string> wczytajDanePlik(const string path);
vector<string> wczytajDaneUzytkownika();
vector<string> podzielNaLiczby(string napis);

vector<vector<int>> vecStrintToInt(vector<vector<string>> &napisy);
