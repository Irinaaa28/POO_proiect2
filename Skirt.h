#ifndef SKIRT_H
#define SKIRT_H

#include "Garment.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

class Skirt : public Garment 
{
public:
    Skirt(const std::string& garmentCode, const std::string& garmentColor);
    //interface implementing
    void describe() const override;
    void describe_reverse() const override;
    void garment_type() const override;
    void addedGarment() const override;
    void removedGarment() const override;
    // other member functions
    void setSkirt(const std::string& skirtName, const std::string& colorName); //setter
    Skirt& operator=(const Skirt& other); //operator=
    Skirt(const Skirt& other); // Constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Skirt& s); //operator<<
    friend std::istream& operator>>(std::istream& is, Skirt& s); //operator>>
    Skirt(Skirt&& other) noexcept; //move constructor
    Skirt& operator=(Skirt&& other) noexcept; //move assignment operator
    ~Skirt();
};

#endif // SKIRT_H
