#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <iostream>
#include <cstdlib>

//Класс для хранения и обработки координат
class Position {
public:
	double x;
	double y;

	//Ввод
	void Input(std::istream &is);
	//void Print();

	//Переопределение вывода
	friend std::ostream& operator<<(std::ostream& os, const Position& pos);
	//Переопределение ввода
	friend std::istream& operator>>(std::istream& is, Position& obj);
};

//Модуль от числа
double Absolute(double num);


#endif /* GEOMETRY_H */
