#include <iostream>
#include "figure.h"

std::ostream& operator<<(std::ostream& os, Figure& obj)
{
	return obj.toStream(os);
}
/*bool Figure::operator==(const Figure& other) {
	return this->Square() == other.Square();
}
bool Figure::operator<(const Figure& other) {
	return this->Square() < other.Square();
}
bool Figure::operator>(const Figure& other) {
	return this->Square() > other.Square();
}
bool Figure::operator<=(const Figure& other) {
	return this->Square() <= other.Square();
}
bool Figure::operator>=(const Figure& other) {
	return this->Square() >= other.Square();
}*/
