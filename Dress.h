#ifndef DRESS_H
#define DRESS_H

#include "Garment.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

class Dress : public Garment 
{
public:
    Dress(const std::string& garmentCode, const std::string& garmentColor);
    //interface implementing
    void describe() const override;
    void describe_reverse() const override;
    void garment_type() const override;
    void addedGarment() const override;
    void removedGarment() const override;
    // other member functions
    void setDress(const std::string& dressName, const std::string& colorName); //setter
    Dress& operator=(const Dress& other); //operator=
    Dress(const Dress& other); // Constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Dress& d); //operator<<
    friend std::istream& operator>>(std::istream& is, Dress& d); //operator>>
    Dress(Dress&& other) noexcept; //move constructor
    Dress& operator=(Dress&& other) noexcept; //move assignment operator
    ~Dress();
};

#endif // DRESS_H