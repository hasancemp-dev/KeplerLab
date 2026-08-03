#include "Texture.h"
#include <iostream>

//normal ctor

Texture::Texture(int id, const std::string& file) :  handleID(id), fileName(file)
{
	std::cout << "GPU: handle " << handleID << " CREATED (" << fileName << ")" << std::endl;
}

//copy ctor
Texture::Texture(const Texture& other) : handleID(other.handleID + 100), fileName(other.fileName)
{
	std::cout << "GPU: handle " << handleID << " COPIED (" << fileName << ")" << std::endl;
}




//copy assignment
Texture& Texture::operator=(const Texture& other)

{
	
	std::cout << "[COPY ASSIGN]  started" << std::endl;

	// (1) KENDINE ATAMA KORUMASI
	if (this == &other)
	{
		std::cout << "caught while assigning, leaving without touching" << std::endl;
		return *this;
	}

	// (2) ESKI KAYNAGI BIRAK
	std::cout << "previous variables are deleted" << std::endl;

	// (3) YENI KAYNAGI AL ve kopyala
	handleID = other.handleID;
	fileName = other.fileName;

	// (4) KENDINI DONDUR
	return *this;
	
}


Texture::~Texture()
{
	std::cout << "GPU: handle " << handleID << " DELETED (" << fileName << ")" << std::endl;
}