// point2D.h
//
//

#pragma once

#include "../core/datatype.h"

struct point2D{
	i32 x;
	i32 y;

	// Default Constructor
	point2D() : x(0), y(0){
		
	}

	point2D(const i32& x, const i32& y)
	:x(x), y(y)
	{	
	}

};
