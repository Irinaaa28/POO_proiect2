#include <iostream>
#include <string>

class Wardrobe //interface
{
    //pure virtual functions
    virtual void describe() const = 0;
    virtual void describe_reverse() const = 0;
    virtual void garment_type() const = 0;
    virtual std::string getCode() const  = 0;//getter code
    virtual std::string getColor() const  = 0;//getter color
};


class Garment : virtual public Wardrobe //abstract class
{
protected:
    std::string garmentCode;
    std::string garmentColor;
public:
    Garment(const std::string& garmentCode, const std::string& garmentColor): garmentCode(garmentCode), garmentColor(garmentColor) {}
    //pure virtual functions
    virtual void describe() const = 0;
    virtual void describe_reverse() const = 0;
    virtual void garment_type() const = 0;
    //implementing some functions from interface
    std::string getCode() const override
    {
        return garmentCode;
    }
    std::string getColor() const override
    {
        return garmentColor;
    }
    ~Garment() {}
    // non-virtual function which verifies if the pieces of clothing have the same color
    bool isSameColor(const Garment& other) const
    {
        return garmentColor == other.garmentColor;
    }

    // non-virtual function which verifies if the pieces of clothing are the same type
    bool isSameType(const Garment& other) const
    {
        return typeid(*this) == typeid(other);
    }
};

class Blouse : public Garment
{
public:
    //Blouse(const std::string& garmentCode = "", const std::string& garmentColor = ""): Garment(garmentCode, garmentColor) {}
    Blouse(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
    //interface implementing 
    void describe() const override
    {
        std::cout << "Blouse: " << garmentCode << ", color: " << garmentColor << std::endl;
    }
    void describe_reverse() const override
    {
        std::cout << "Color: " << garmentColor << ", blouse: " << garmentCode << std::endl;
    }
    void garment_type() const override
    {
        std::cout << "This is a blouse" << std::endl;
    }
    ~Blouse() {}
};

class Dress : public Garment
{
public:
    //Dress(const std::string& garmentCode = "", const std::string& garmentColor = ""): Garment(garmentCode, garmentColor) {}
    Dress(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
    //interface implementing
    void describe() const override
    {
        std::cout << "Dress: " << garmentCode << ", color: " << garmentColor << std::endl;
    }
    void describe_reverse() const override
    {
        std::cout << "Color: " << garmentColor << ", dress: " << garmentCode << std::endl;
    }
    void garment_type() const override
    {
        std::cout << "This is a dress" << std::endl;
    }
    ~Dress() {}
};

class Skirt : public Garment
{
public:
    //Skirt(const std::string& garmentCode = "", const std::string& garmentColor = ""): Garment(garmentCode, garmentColor) {}
    Skirt(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
    //interface implementing
    void describe() const override
    {
        std::cout << "Skirt: " << garmentCode << ", color: " << garmentColor << std::endl;
    }
    void describe_reverse() const override
    {
        std::cout << "Color: " << garmentColor << ", skirt: " << garmentCode << std::endl;
    }
    void garment_type() const override
    {
        std::cout << "This is a skirt" << std::endl;
    }
    ~Skirt() {}
};

class Pants : public Garment
{
public:
    //Pants(const std::string& garmentCode = "", const std::string& garmentColor = ""): Garment(garmentCode, garmentColor) {}
    Pants(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
    //interface implementing
    void describe() const override 
    {
        std::cout << "Pants: " << garmentCode << ", color: " << garmentColor << std::endl;
    }
    void describe_reverse() const override
    {
        std::cout << "Color: " << garmentColor << ", pants: " << garmentCode << std::endl;
    }
    void garment_type() const override
    {
        std::cout << "These are pants" << std::endl;
    }
    ~Pants() {}
};

//using interface
void describe_garment(const Garment& clothing)
{
    clothing.describe();
}

int main()
{
    Blouse blouse1("#BT1CR", "Red"), blouse2("#BT1CB", "Blue"), blouse3("#BT1CG", "Green"), blouse4("#BT1CY", "Yellow");
    Dress dress1("#DT1CR", "Red"), dress2("#DT1CB", "Blue"), dress3("#DT1CG", "Green"), dress4("#DT1CY", "Yellow");
    Skirt skirt1("#ST1CR", "Red"), skirt2("#ST1CB", "Blue"), skirt3("#ST1CG", "Green"), skirt4("#ST1CY", "Yellow");
    Pants pants1("#PT1CR", "Red"), pants2("#PT1CB", "Blue"), pants3("#PT1CG", "Green"), pants4("#PT1CY", "Yellow");
    Blouse noneB("none", "none");
    Dress noneD("none", "none");
    Skirt noneS("none", "none");
    Pants noneP("none", "none");

    //function call through reference
    Garment& b1 = blouse1;
    b1.describe();
    b1.describe_reverse();
    std::cout << b1.getColor() << std::endl;
    Garment& d1 = dress3;
    d1.garment_type();

    //VPTR through reference
    Garment& g1 = dress2;
    g1.describe();
    std::cout << g1.getCode() << std::endl;

    describe_garment(pants2);
    return 0;
}
