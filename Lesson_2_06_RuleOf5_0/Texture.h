#pragma once

#include <string>

class Texture
{
private:

	int handleID;
	std::string fileName;
	
public:

	Texture(int id, const std::string& file);		 // normal ctor

	Texture(const Texture& other) = delete;					 // copy ctor — must be inside class
	
	Texture& operator=(const Texture& other) = delete;	 // copy assignment

	Texture(Texture&& other) noexcept;					//move ctor

	Texture& operator=(Texture&& other) noexcept;		//move assignment

	~Texture();									     // destructor x-x

};
