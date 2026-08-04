#include "Texture.h"
#include <iostream>

//normal ctor

Texture::Texture(int id, const std::string& file) :  handleID(id), fileName(file)
{
	std::cout << "GPU: handle " << handleID << " CREATED (" << fileName << ")" << std::endl;
}

//move ctor
Texture::Texture(Texture&& other) noexcept
    : handleID(other.handleID), fileName(std::move(other.fileName))   // (a) değerleri AL (yeni üretme, ÇAL)
{
    other.handleID = 0;                                     // (b) kaynağı other'dan koparip kendi handle'ina
    std::cout << "GPU: handle " << handleID << " MOVED (" << fileName << ")" << std::endl;
}

//move assignment
Texture& Texture::operator=(Texture&& other) noexcept
{
    if (this == &other) return *this;

    // (1) kendi eski kaynağını bırak — BU EKSİKTİ
    if (handleID != 0)
        std::cout << "GPU: handle " << handleID << " DELETED (" << fileName << ") [replaced]" << std::endl;

    // (2) other'in kaynağını devral
    handleID = other.handleID;
    fileName = std::move(other.fileName);

    // (3) other'i nötralize et
    other.handleID = 0;

    return *this;
}

//dtor
Texture::~Texture()
{
    if (handleID == 0) { std::cout << "Empty object, no deletable resources..." << std::endl; }
    else { std::cout << "GPU: handle " << handleID << " DELETED (" << fileName << ")" << std::endl; }
	
}