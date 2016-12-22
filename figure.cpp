#include <iostream>
#include "figure.h"

std::ostream& operator<<(std::ostream& os, Figure& obj)
{
	return obj.toStream(os);
}
