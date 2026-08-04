#include <iostream>
#include "Texture.h"
#include <vector>

int main()
{ 
	/*std::vector<Texture> atlas;
	atlas.push_back(Texture(1, "floor.png"));*/

	/*Texture target(9, "temp.png");
	Texture resource(7, "resource.png");
	target = std::move(resource);*/

	std::vector<Texture> atlas;
	atlas.reserve(3);						// "3 eleman geleceğini biliyorum, yeri şimdiden ayır"
	atlas.push_back(Texture(1, "a.png"));
	atlas.push_back(Texture(2, "b.png"));
	atlas.push_back(Texture(3, "c.png"));
	return 0;
} 