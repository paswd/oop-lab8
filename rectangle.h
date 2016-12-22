#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cstdlib>
#include <iostream>
#include "figure.h"
#include "geometry.h"

class Rectangle : public Figure {
public:
	//Конструкторы
	Rectangle();
	Rectangle(std::istream &is);
	Rectangle(Position in_pos, double len_a, double len_b);
	Rectangle(const Rectangle &orig);
	//Площадь
	double Square() override;
	//void Print() override;
	//Деструктор
	virtual ~Rectangle();
	//Вывод
	std::ostream& toStream(std::ostream& os) override;
	//Переопределение вывода
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& obj);
	//Переопределение ввода
	friend std::istream& operator>>(std::istream& is, Rectangle& obj);
private:
	Position pos;
	double LenA;
	double LenB;
};

#endif /* RECTANGLE_H */
