#ifndef BLOUSE_H
#define BLOUSE_H

#include "Garment.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

class Blouse : public Garment 
{
public:
    Blouse(const std::string& garmentCode, const std::string& garmentColor);
    //interface implementing
    void describe() const override;
    void describe_reverse() const override;
    void garment_type() const override;
    void addedGarment() const override;
    void removedGarment() const override;
    // other member functions
    void setBlouse(const std::string& blouseName, const std::string& colorName); //setter
    Blouse& operator=(const Blouse& other); //operator=
    Blouse(const Blouse& other); // Constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Blouse& b); //operator<<
    friend std::istream& operator>>(std::istream& is, Blouse& b); //operator>>
    Blouse(Blouse&& other) noexcept; //move constructor
    Blouse& operator=(Blouse&& other) noexcept; //move assignment operator
    ~Blouse();
};

#endif // BLOUSE_H
