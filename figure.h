#ifndef FIGURE_H
#define FIGURE_H

class Figure {
public:
	//Площадь
	virtual double Square() = 0;
	//virtual void Print() = 0;
	//Деструктор
	virtual ~Figure() {};
	//Вывод
	virtual std::ostream& toStream(std::ostream& os) = 0;
};

//Переопределение вывода
std::ostream& operator<<(std::ostream& os, Figure& obj);


#endif /* FIGURE_H */
