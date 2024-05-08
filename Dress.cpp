#include "Dress.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

//Dress(const std::string& garmentCode = "", const std::string& garmentColor = ""): Garment(garmentCode, garmentColor) {}
Dress::Dress(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
//interface implementing 
void Dress::describe() const 
{
    std::cout << "Dress: " << garmentCode << ", color: " << garmentColor << std::endl;
}
void Dress::describe_reverse() const 
{
    std::cout << "Color: " << garmentColor << ", dress: " << garmentCode << std::endl; 
}
void Dress::garment_type() const 
{
    std::cout << "A dress" << std::endl;
}
void Dress::addedGarment() const 
{
    std::cout << "Dress added successfully!" << std::endl;
}
void Dress::removedGarment() const 
{
    std::cout << "Dress removed successfully!" << std::endl;
}

void Dress::setDress(const std::string& dressName, const std::string& colorName) //setter
{
    garmentCode = dressName;
    garmentColor = colorName;
}
Dress& Dress::operator=(const Dress& other) //operator=
{
    if(this != &other)
    {
        garmentCode = other.garmentCode;
        garmentColor = other.garmentColor;
    }
    return *this;
}
Dress::Dress(const Dress& other) : Garment(other) {} // Constructor de copiere
std::ostream& operator<<(std::ostream& os, const Dress& d) //operator<<
{
    os << "Dress: " << d.garmentCode << ", color: " << d.garmentColor;
    return os;
}
std::istream& operator>>(std::istream& is, Dress& d) //operator>>
{
    std::cout << "Dress_code: ";
    is >> d.garmentCode;
    std::cout << "color: ";
    is >> d.garmentColor;
    return is;
}
Dress::Dress(Dress&& other) noexcept: Garment(std::move(other)) //move constructor
{
    other.garmentCode.clear();
    other.garmentColor.clear();
}
Dress& Dress::operator=(Dress&& other) noexcept //move assignment operator for Dress
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
Dress::~Dress() = default; //override {/*std::cout << "Destructor for dress" << std::endl;*/}