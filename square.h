#ifndef FSQUARE_H
#define FSQUARE_H

#include <cstdlib>
#include <iostream>
#include "figure.h"
#include "geometry.h"

class FSquare : public Figure {
public:
	FSquare();
	FSquare(std::istream &is);
	FSquare(Position in_pos, double length);
	FSquare(const FSquare &orig);
	double Square() override;
	//void Print() override;
	virtual ~FSquare();
	std::ostream& toStream(std::ostream& os) override;
	double GetLength();
	friend std::ostream& operator<<(std::ostream& os, const FSquare& obj);
	friend std::istream& operator>>(std::istream& is, FSquare& obj);
private:
	Position pos;
	double len;
};

#endif /* FSQUARE_H */
