#include "Blouse.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

//Blouse(const std::string& garmentCode = "", const std::string& garmentColor = ""): Garment(garmentCode, garmentColor) {}
Blouse::Blouse(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
//interface implementing 
void Blouse::describe() const 
{
    std::cout << "Blouse: " << garmentCode << ", color: " << garmentColor << std::endl;
}
void Blouse::describe_reverse() const 
{
    std::cout << "Color: " << garmentColor << ", blouse: " << garmentCode << std::endl; 
}
void Blouse::garment_type() const 
{
    std::cout << "A blouse" << std::endl;
}
void Blouse::addedGarment() const 
{
    std::cout << "Blouse added successfully!" << std::endl;
}
void Blouse::removedGarment() const 
{
    std::cout << "Blouse removed successfully!" << std::endl;
}

void Blouse::setBlouse(const std::string& blouseName, const std::string& colorName) //setter
{
    garmentCode = blouseName;
    garmentColor = colorName;
}
Blouse& Blouse::operator=(const Blouse& other) //operator=
{
    if(this != &other)
    {
        garmentCode = other.garmentCode;
        garmentColor = other.garmentColor;
    }
    return *this;
}
Blouse::Blouse(const Blouse& other) : Garment(other) {} // Constructor de copiere
std::ostream& operator<<(std::ostream& os, const Blouse& b) //operator<<
{
    os << "Blouse: " << b.garmentCode << ", color: " << b.garmentColor;
    return os;
}
std::istream& operator>>(std::istream& is, Blouse& b) //operator>>
{
    std::cout << "Blouse_code: ";
    is >> b.garmentCode;
    std::cout << "color: ";
    is >> b.garmentColor;
    return is;
}
Blouse::Blouse(Blouse&& other) noexcept: Garment(std::move(other)) //move constructor
{
    other.garmentCode.clear();
    other.garmentColor.clear();
}
Blouse& Blouse::operator=(Blouse&& other) noexcept //move assignment operator for Blouse
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
Blouse::~Blouse() = default; //override {/*std::cout << "Destructor for blouse" << std::endl;*/}