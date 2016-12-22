#include <iostream>
#include <cmath>
#include "geometry.h"
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle()
{
	/*Position empty_pos;
	empty_pos.x = 0;
	empty_pos.y = 0;
	Rectangle *empty_href = new Rectangle(empty_pos, 0.0, 0.0);
	Rectangle empty = *empty_href;
	delete empty_href;
	*this = empty;*/
}

Rectangle::Rectangle(Position in_pos, double len_a, double len_b) : pos(in_pos), LenA(len_a), LenB(len_b) {
	//cout << "Rectangle created:" << endl;
	//this->Print();
}
Rectangle::Rectangle(std::istream &is) {
	std::cout << "Figure: Rectangle (Position, Length1, Length2)" << std::endl;
	this->pos.Input(is);
	is >> this->LenA;
	is >> this->LenB;
	std::cout << "Rectangle created" << std::endl;
}
Rectangle::Rectangle(const Rectangle &orig) {
	this->pos = orig.pos;
	this->LenA = orig.LenA;
	this->LenB = orig.LenB;
	//cout << "Rectangle copy created" << std::endl;
}
double Rectangle::Square() {
	return this->LenA * this->LenB;
}
/*void Rectangle::Print() {
	cout << "Position: ";
	this->pos.Print();
	cout << "Side lengths: " << endl;
	cout << "A: " << this->LenA << endl;
	cout << "B: " << this->LenB << endl;
}*/
Rectangle::~Rectangle() {
	//cout << "Rectangle deleted" << std::endl;
}

std::ostream& Rectangle::toStream(std::ostream& os)
{
	os << *this;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj)
{
	os << "Position: ";
	//obj.pos.Print();
	os << obj.pos << endl;
	os << "Side lengths: " << endl;
	os << "A: " << obj.LenA << endl;
	os << "B: " << obj.LenB << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& obj)
{
	std::cout << "Figure: Rectangle (Position, Length1, Length2)" << std::endl;
	obj.pos.Input(is);
	is >> obj.LenA;
	is >> obj.LenB;
	std::cout << "Rectangle created" << std::endl;
	return is;
}
