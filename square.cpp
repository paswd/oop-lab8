#include <iostream>
#include <cmath>
#include "geometry.h"
#include "square.h"

using namespace std;

FSquare::FSquare()
{
	/*Position empty_pos;
	empty_pos.x = 0;
	empty_pos.y = 0;
	FSquare *empty_href = new FSquare(empty_pos, 0.0);
	FSquare empty = *empty_href;
	delete empty_href;
	*this = empty;*/
}

FSquare::FSquare(Position in_pos, double length) : pos(in_pos), len(length)
{
	//cout << "FSquare created:" << endl;
	//this->Print();
}

FSquare::FSquare(std::istream &is)
{
	std::cout << "Figure: Square (Position, Length)" << std::endl;
	this->pos.Input(is);
	is >> this->len;
	std::cout << "Square created" << std::endl;
}

FSquare::FSquare(const FSquare &orig)
{
	this->pos = orig.pos;
	this->len = orig.len;
	//cout << "FSquare copy created" << std::endl;
}

double FSquare::Square()
{
	return this->len * this->len;
}

/*void FSquare::Print()
{
	cout << "Position: ";
	//this->pos.Print();
	cout << pos << endl;
	cout << "Side length: " << this->len << endl;
}*/

FSquare::~FSquare()
{
	//cout << "FSquare deleted" << std::endl;
}

std::ostream& FSquare::toStream(std::ostream& os)
{
	os << *this;
	return os;
}

double FSquare::GetLength()
{
	return this->len;
}
std::ostream& operator<<(std::ostream& os, const FSquare& obj)
{
	/*cout << "Position: ";
	this->pos.Print();
	cout << "Side length: " << this->len << endl;*/
	os << "Position: " << obj.pos << std::endl;
	os << "Side length: " << obj.len << std::endl;
	os << "Square: " << obj.len * obj.len << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, FSquare& obj)
{
	std::cout << "Figure: Square (Position, Length)" << std::endl;
	obj.pos.Input(is);
	is >> obj.len;
	std::cout << "Square created" << std::endl;
	return is;
}
