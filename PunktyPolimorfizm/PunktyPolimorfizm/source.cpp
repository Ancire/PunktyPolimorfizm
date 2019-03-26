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