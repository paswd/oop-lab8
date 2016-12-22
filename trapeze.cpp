#include <iostream>
#include <cmath>
#include "geometry.h"
#include "trapeze.h"

using namespace std;

Trapeze::Trapeze()
{
	/*Position empty_pos;
	empty_pos.x = 0;
	empty_pos.y = 0;
	Trapeze *empty_href = new Trapeze(empty_pos, empty_pos, 0.0, 0.0);
	Trapeze empty = *empty_href;
	delete empty_href;
	*this = empty;*/
}

Trapeze::Trapeze(Position in_pos1, Position in_pos2, double len_a, double len_b) : pos1(in_pos1), pos2(in_pos2), LenA(len_a), LenB(len_b) {
	//cout << "Trapeze created:" << endl;
	//this->Print();
}
Trapeze::Trapeze(std::istream &is) {
	std::cout << "Figure: Trapeze (Position1, Position2, Length1, Length2)" << std::endl;
	this->pos1.Input(is);
	this->pos2.Input(is);
	is >> this->LenA;
	is >> this->LenB;
	std::cout << "Trapeze created" << std::endl;
}
Trapeze::Trapeze(const Trapeze &orig) {
	this->pos1 = orig.pos1;
	this->pos2 = orig.pos2;
	this->LenA = orig.LenA;
	this->LenB = orig.LenB;
	//cout << "Trapeze copy created" << std::endl;
}
double Trapeze::Square() {
	return (this->LenA + this->LenB) * Absolute(this->pos1.y - this->pos2.y) / 2;
}
/*void Trapeze::Print() {
	cout << "Positions: ";
	this->pos1.Print();
	this->pos2.Print();
	cout << "Side lengths: " << endl;
	cout << "A: " << this->LenA << endl;
	cout << "B: " << this->LenB << endl;
}*/
Trapeze::~Trapeze() {
	//cout << "Trapeze deleted" << std::endl;
}

std::ostream& Trapeze::toStream(std::ostream& os)
{
	os << *this;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Trapeze& obj)
{
	os << "Positions: ";
	//obj.pos1.Print();
	//obj.pos2.Print();
	os << obj.pos1 << endl;;
	os << obj.pos2 << endl;
	os << "Side lengths: " << endl;
	os << "A: " << obj.LenA << endl;
	os << "B: " << obj.LenB << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Trapeze& obj)
{
	std::cout << "Figure: Trapeze (Position1, Position2, Length1, Length2)" << std::endl;
	obj.pos1.Input(is);
	obj.pos2.Input(is);
	is >> obj.LenA;
	is >> obj.LenB;
	std::cout << "Trapeze created" << std::endl;
	return is;
}
