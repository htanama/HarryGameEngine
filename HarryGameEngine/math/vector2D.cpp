#include "vector2D.h"

//vector2D::vector2D()
//{	
//}

vector2D::vector2D(const point2D& vecP)
	:point2D(vecP.x, vecP.y)
{
	this->_vec1 = vecP;
}

void vector2D::operator=(vector2D const& vecPoint)
{
	this->_vec1.x = vecPoint.x;
	this->_vec1.y = vecPoint.y;
}

vector2D vector2D::operator+(vector2D const& vecP1)
{
	vector2D result;
	result.x = this->_vec1.x + vecP1.x;
	result.y = this->_vec1.y + vecP1.y;

	return result;
	
}

