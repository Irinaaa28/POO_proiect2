#ifndef PANTS_H
#define PANTS_H

#include "Garment.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

class Pants : public Garment 
{
public:
    Pants(const std::string& garmentCode, const std::string& garmentColor);
    //interface implementing
    void describe() const override;
    void describe_reverse() const override;
    void garment_type() const override;
    void addedGarment() const override;
    void removedGarment() const override;
    // other member functions
    void setPants(const std::string& pantsName, const std::string& colorName); //setter
    Pants& operator=(const Pants& other); //operator=
    Pants(const Pants& other); // Constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Pants& p); //operator<<
    friend std::istream& operator>>(std::istream& is, Pants& p); //operator>>
    Pants(Pants&& other) noexcept; //move constructor
    Pants& operator=(Pants&& other) noexcept; //move assignment operator
    ~Pants();
};

#endif // Pants_H
