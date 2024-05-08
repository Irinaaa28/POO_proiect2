#ifndef GARMENT_H
#define GARMENT_H

#include "wardrobe.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

class Garment : virtual public Wardrobe //abstract class
{
protected:
    std::string garmentCode;
    std::string garmentColor;
public:
    Garment(const std::string& garmentCode, const std::string& garmentColor); //constructor
    //pure virtual functions
    virtual void describe() const = 0;
    virtual void describe_reverse() const = 0;
    virtual void garment_type() const = 0;
    virtual void addedGarment() const = 0;
    virtual void removedGarment() const = 0;
    //implementing some functions from interface
    std::string getCode() const override;
    std::string getColor() const override;
    // non-virtual functions
    bool isSameColor(const Garment& other) const;
    bool isSameType(const Garment& other) const;
    ~Garment();
};

#endif // GARMENT_H
