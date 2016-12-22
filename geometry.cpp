#include <iostream>
#include <cstdlib>
#include <cmath>
#include "geometry.h"

using namespace std;

void Position::Input(std::istream &is)
{
	is >> this->x;
	is >> this->y;
}

/*void Position::Print()
{
	cout << "(" << this->x << ":" << this->y << ")";
}*/

double Absolute(double num)
{
	if (num < 0)
		num = -num;

	return num;
}

std::ostream& operator<<(std::ostream& os, const Position& pos)
{
	os << "(" << pos.x << ":" << pos.y << ")";
	return os;
}
std::istream& operator>>(std::istream& is, Position& pos)
{
	is >> pos.x;
	is >> pos.y;
	return is;
}
