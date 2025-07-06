// point2D.h
//
//

#pragma once

struct point2D{
	int _x;
	int _y;

	// Default Constructor
	point2D() : _x(0), _y(0){
		
	}

	point2D(const int& x, const int& y)
	:_x(x), _y(y)
	{	
	}

};
