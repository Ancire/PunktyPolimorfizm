#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Vec {
public:
	virtual void print() = 0;
	virtual double modul() = 0;
};

class Vec1 : public Vec
{

protected:
	double x;


public:

	Vec1();
	Vec1(double a);


	void print();
	void setX(double a);


	double getX();
	double modul();
};

class Vec2 : public Vec1
{
protected:
	double y;

public:

	Vec2();
	Vec2(double a, double b);


	void print();
	void setY(double a);

	double getY();
	double modul();
};


vector<string> getRawData();
vector<string> correctData(vector<string> &dane);

void writeData();
