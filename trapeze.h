#ifndef TRAPEZE_H
#define TRAPEZE_H

#include <cstdlib>
#include <iostream>
#include "figure.h"
#include "geometry.h"

class Trapeze : public Figure {
public:
	Trapeze();
	Trapeze(std::istream &is);
	Trapeze(Position in_pos1, Position in_pos2, double len_a, double len_b);
	Trapeze(const Trapeze &orig);
	double Square() override;
	//void Print() override;
	virtual ~Trapeze();
	std::ostream& toStream(std::ostream& os) override;
	friend std::ostream& operator<<(std::ostream& os, const Trapeze& obj);
	friend std::istream& operator>>(std::istream& is, Trapeze& obj);
private:
	Position pos1;
	Position pos2;
	double LenA;
	double LenB;
};

#endif /* TRAPEZE_H */
