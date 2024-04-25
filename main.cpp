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
    ~Blouse() {/*std::cout << "Destructor for blouse" << std::endl;*/}
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
    ~Dress() {/*std::cout << "Destructor for dress" << std::endl;*/}
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
    ~Skirt() {/*std::cout << "Destructor for skirt" << std::endl;*/}
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
    ~Pants() {/*std::cout << "Destructor for pants" << std::endl;*/}
};

class Barbie
{
protected:
    Blouse currentBlouse;
    Dress currentDress;
    Skirt currentSkirt;
    Pants currentPants;
    static int garmentCount;
    static int numberOfChanges;
public:
    Barbie(const Blouse& currentBlouse, const Dress& currentDress, const Skirt& currentSkirt, const Pants& currentPants): currentBlouse(currentBlouse), currentDress(currentDress), currentSkirt(currentSkirt), currentPants(currentPants) {}
    //Barbie(const std::string& blouseCode, const std::string& dressCode, const std::string& skirtCode, const std::string& pantsCode): currentBlouse(blouseCode, ""), currentDress(dressCode, ""), currentSkirt(skirtCode, ""), currentPants(pantsCode, "") {}
    void addBlouse(const Blouse& blouse)
    {
        currentBlouse = blouse;
        garmentCount++;
        numberOfChanges++;
    }
    void addDress(const Dress& dress)
    {
        currentDress = dress;
        garmentCount++;
        numberOfChanges++;
    }
    void addSkirt(const Skirt& skirt)
    {
        currentSkirt = skirt;
        garmentCount++;
        numberOfChanges++;
    }
    void addPants(const Pants& pants)
    {
        currentPants = pants;
        garmentCount++;
        numberOfChanges++;
    }
    static int GetGarmentCount(void)
    {
        return garmentCount;
    }
    static void ViewChanges()
    {
        if (numberOfChanges == 0)
            std::cout << "You haven't changed Barbie's look yet" << std::endl;
        else if (numberOfChanges == 1)  
            std::cout << "You've made " << numberOfChanges << " change at Barbie's look so far." << std::endl;
        else std::cout << "You've made " << numberOfChanges << " changes at Barbie's look so far." << std::endl;
    }
};

int Barbie::garmentCount = 0;
int Barbie::numberOfChanges = 0;

//using interface
void describe_garment(const Garment& clothing)
{
    clothing.describe();
}
void Display(const Barbie& myBarbie)
{
    const int numberOfClothes = Barbie::GetGarmentCount();
    if (numberOfClothes == 0)
        std::cout << "Barbie isn' wearing anything at the moment." << std::endl;
    else if (numberOfClothes == 1)
        std::cout << "Barbie is wearing 1 piece of clothing at the moment." << std::endl;
    else std::cout << "Barbie is wearing " << numberOfClothes << " pieces of clothing at the moment." << std::endl;
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

    Barbie myBarbie(noneB, noneD, noneS, noneP);

    myBarbie.addBlouse(blouse2);
    Display(myBarbie);
    myBarbie.ViewChanges();
    return 0;
}
