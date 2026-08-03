#pragma once

#include <string>

class Texture
{
private:

	int handleID;
	std::string fileName;
	
public:

	Texture(int id, const std::string& file);		 // normal ctor

	Texture(const Texture& other);					 // copy ctor — must be inside class
	
	Texture& operator=(const Texture& other);	 // copy assignment

	~Texture();									     // destructor x-x

};
