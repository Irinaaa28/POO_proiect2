#include "Pants.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

//Pants(const std::string& garmentCode = "", const std::string& garmentColor = ""): Garment(garmentCode, garmentColor) {}
Pants::Pants(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
//interface implementing 
void Pants::describe() const 
{
    std::cout << "Pants: " << garmentCode << ", color: " << garmentColor << std::endl;
}
void Pants::describe_reverse() const 
{
    std::cout << "Color: " << garmentColor << ", pants: " << garmentCode << std::endl; 
}
void Pants::garment_type() const 
{
    std::cout << "Pants" << std::endl;
}
void Pants::addedGarment() const 
{
    std::cout << "Pants added successfully!" << std::endl;
}
void Pants::removedGarment() const 
{
    std::cout << "Pants removed successfully!" << std::endl;
}

void Pants::setPants(const std::string& pantsName, const std::string& colorName) //setter
{
    garmentCode = pantsName;
    garmentColor = colorName;
}
Pants& Pants::operator=(const Pants& other) //operator=
{
    if(this != &other)
    {
        garmentCode = other.garmentCode;
        garmentColor = other.garmentColor;
    }
    return *this;
}
Pants::Pants(const Pants& other) : Garment(other) {} // Constructor de copiere
std::ostream& operator<<(std::ostream& os, const Pants& p) //operator<<
{
    os << "Pants: " << p.garmentCode << ", color: " << p.garmentColor;
    return os;
}
std::istream& operator>>(std::istream& is, Pants& p) //operator>>
{
    std::cout << "Pants_code: ";
    is >> p.garmentCode;
    std::cout << "color: ";
    is >> p.garmentColor;
    return is;
}
Pants::Pants(Pants&& other) noexcept: Garment(std::move(other)) //move constructor
{
    other.garmentCode.clear();
    other.garmentColor.clear();
}
Pants& Pants::operator=(Pants&& other) noexcept //move assignment operator for Pants
{
    if (this != &other)
    {
        /*garmentCode = std::move(other.garmentCode);
        garmentColor = std::move(other.garmentColor);
        other.garmentCode.clear();
        other.garmentColor.clear();*/
        Garment::operator=(std::move(other));
    }
    return *this;
}
Pants::~Pants() = default; //override {/*std::cout << "Destructor for pants" << std::endl;*/}