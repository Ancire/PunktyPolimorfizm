#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>


using namespace std;

class Vec2
{
protected:
	int x,y;

public:

	Vec2();
	Vec2(int a, int b);


	void print();
	void setX(int a);
	void setY(int a);

	int getX();
	int getY();
	double modul();
};

class Vec3 : public Vec2
{
protected:
	int z;

public:

	Vec3();
	Vec3(int a, int b, int c);


	void print();
	void setZ();

	int getZ();

	double dlugosc();
};


vector<string> getRawData();
vector<string> correctData(vector<string> &dane);