#include <iostream>
#include "Texture.h"

int main()
{
	Texture wall(5, "wall.png");

	Texture copy = wall;  // it is a deleted func. 

	wall = wall;
	
	copy = wall;// it is a deleted func. 

	//çünkü = delete yaptık copy ctor ve copy assignment ctor'larını.

	return 0;
} 