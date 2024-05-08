#ifndef WARDROBE_H
#define WARDROBE_H
#include <iostream>
#include <string>

class Wardrobe //interface
{
public:
    //pure virtual functions
    virtual void describe() const = 0;
    virtual void describe_reverse() const = 0;
    virtual void garment_type() const = 0;
    virtual std::string getCode() const  = 0; //getter code
    virtual std::string getColor() const  = 0; //getter color
};

#endif // WARDROBE_H

