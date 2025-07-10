#pragma once

#include "point2D.h"

class vector2D: public point2D 
{
public: 
	vector2D() = default;
	vector2D(const point2D& vecP);

	void operator=(vector2D const& vecPoint);
	vector2D operator+(vector2D const& vecP1);
	

private:
	point2D _vec1;
	
};