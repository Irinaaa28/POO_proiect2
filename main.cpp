#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

std::string toLower(const std::string& str) 
{
    std::string result = str;
    for (char& c : result) 
        c = tolower(c);
    return result;
}

class Wardrobe //interface
{
public:
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
    //Garment() : garmentCode(""), garmentColor("") {}
    Garment(const std::string& garmentCode, const std::string& garmentColor): garmentCode(garmentCode), garmentColor(garmentColor) {} //constructor
    //pure virtual functions
    virtual void describe() const = 0;
    virtual void describe_reverse() const = 0;
    virtual void garment_type() const = 0;
    virtual void addedGarment() const = 0;
    virtual void removedGarment() const = 0;
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
    void addedGarment() const override
    {
        std::cout << "Blouse added successfully!" << std::endl;
    }
    void removedGarment() const override
    {
        std::cout << "Blouse removed successfully!" << std::endl;
    }

    void setBlouse(const std::string& blouseName, const std::string& colorName) //setter
    {
        garmentCode = blouseName;
        garmentColor = colorName;
    }
    Blouse& operator=(const Blouse& other) //operator=
    {
        if(this != &other)
        {
            garmentCode = other.garmentCode;
            garmentColor = other.garmentColor;
        }
        return *this;
    }
    Blouse(const Blouse& other) : Garment(other) {} // Constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Blouse& b) //operator<<
    {
        os << "Blouse: " << b.garmentCode << ", color: " << b.garmentColor;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Blouse& b) //operator>>
    {
        std::cout << "Blouse_code: ";
        is >> b.garmentCode;
        std::cout << "color: ";
        is >> b.garmentColor;
        return is;
    }
    Blouse(Blouse&& other) noexcept: Garment(std::move(other)) //move constructor
    {
        other.garmentCode.clear();
        other.garmentColor.clear();
    }
    Blouse& operator=(Blouse&& other) noexcept //move assignment operator for Blouse
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
    ~Blouse() = default; //{/*std::cout << "Destructor for blouse" << std::endl;*/}
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
    void addedGarment() const override
    {
        std::cout << "Dress added successfully!" << std::endl;
    }
    void removedGarment() const override
    {
        std::cout << "Dress removed successfully!" << std::endl;
    }

    void setDress(const std::string& dressName, const std::string& colorName) //setter
    {
        garmentCode = dressName;
        garmentColor = colorName;
    }
    Dress& operator=(const Dress& other) //operator=
    {
        if (this != &other)
        {
            garmentCode = other.garmentCode;
            garmentColor = other.garmentColor;
        }
        return *this;
    }
    Dress(const Dress& other): Garment(other) {} //constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Dress& d) //operator<<
    {
        os << "Dress: " << d.garmentCode << ", color: " << d.garmentColor;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Dress& d) //operator>>
    {
        std::cout << "Dress_code: ";
        is >> d.garmentCode;
        std::cout << "color: ";
        is >> d.garmentColor;
        return is;
    }
    Dress(Dress&& other) noexcept: Garment(std::move(other)) //move constructor
    {
        other.garmentCode.clear();
        other.garmentColor.clear();
    }
    Dress& operator=(Dress&& other) noexcept //move assignment operator for Dress
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
    ~Dress() = default; //{/*std::cout << "Destructor for dress" << std::endl;*/}
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
    void addedGarment() const override
    {
        std::cout << "Skirt added successfully!" << std::endl;
    }
    void removedGarment() const override
    {
        std::cout << "Skirt removed successfully!" << std::endl;
    }

    void setSkirt(const std::string& skirtName, const std::string& colorName) //setter
    {
        garmentCode = skirtName;
        garmentColor = colorName;
    }
    Skirt& operator=(const Skirt& other) //operator=
    {
        if (this != &other)
        {
            garmentCode = other.garmentCode;
            garmentColor = other.garmentColor;
        }
        return *this;
    }
    Skirt(const Skirt& other): Garment(other) {} //constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Skirt& s) //operator<<
    {
        os << "Skirt: " << s.garmentCode << ", color: " << s.garmentColor;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Skirt& s) //operator>>
    {
        std::cout << "Skirt_code: ";
        is >> s.garmentCode;
        std::cout << "color: ";
        is >> s.garmentColor;
        return is;
    }
    Skirt(Skirt&& other) noexcept: Garment(std::move(other)) //move constructor
    {
        other.garmentCode.clear();
        other.garmentColor.clear();
    }
    Skirt& operator=(Skirt&& other) noexcept //move assignment operator for Skirt
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
    ~Skirt() = default; //{/*std::cout << "Destructor for skirt" << std::endl;*/}
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
    void addedGarment() const override
    {
        std::cout << "Pants added successfully!" << std::endl;
    }
    void removedGarment() const override
    {
        std::cout << "Pants removed successfully!" << std::endl;
    }

    void setPants(const std::string& pantsName, const std::string colorName) //setter
    {
        garmentCode = pantsName;
        garmentColor = colorName;
    }
    Pants& operator=(const Pants& other) //operator=
    {
        if (this != &other)
        {
            garmentCode = other.garmentCode;
            garmentColor = other.garmentColor;
        }
        return *this;
    }
    Pants(const Pants& other): Garment(other) {} //constructor de copiere
    friend std::ostream& operator<<(std::ostream& os, const Pants& p) //operator<<
    {
        os << "Pants: " << p.garmentCode << ", color: " << p.garmentColor;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Pants& p) //operator>>
    {
        std::cout << "Pants_code: ";
        is >> p.garmentCode;
        std::cout << "color: ";
        is >> p.garmentColor;
        return is;
    }
    Pants(Pants&& other) noexcept: Garment(std::move(other)) //move constructor
    {
        other.garmentCode.clear();
        other.garmentColor.clear();
    }
    Pants& operator=(Pants&& other) noexcept //move assignment operator for Pants
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
    ~Pants() = default; //{/*std::cout << "Destructor for pants" << std::endl;*/}
};

class Barbie
{
protected:
    Blouse* currentBlouse;
    Dress* currentDress;
    Skirt* currentSkirt;
    Pants* currentPants;
    static int garmentCount;
    static int numberOfChanges;
public:
    //Barbie(const Blouse& currentBlouse, const Dress& currentDress, const Skirt& currentSkirt, const Pants& currentPants): currentBlouse(currentBlouse), currentDress(currentDress), currentSkirt(currentSkirt), currentPants(currentPants) {}
    //Barbie(const std::string& blouseCode, const std::string& dressCode, const std::string& skirtCode, const std::string& pantsCode): currentBlouse(blouseCode, ""), currentDress(dressCode, ""), currentSkirt(skirtCode, ""), currentPants(pantsCode, "") {}
    Barbie(): currentBlouse(nullptr), currentDress(nullptr), currentSkirt(nullptr), currentPants(nullptr) {}
    void addBlouse(const Blouse& blouse)
    {
        if (currentBlouse)
            delete currentBlouse;
        currentBlouse = new Blouse(blouse);
        garmentCount++;
        numberOfChanges++;
        currentBlouse->addedGarment();
    }
    void addDress(const Dress& dress)
    {
        if (currentDress)
            delete currentDress;
        currentDress = new Dress(dress);
        garmentCount++;
        numberOfChanges++;
        currentDress->addedGarment();
    }
    void addSkirt(const Skirt& skirt)
    {
        if (currentSkirt)
            delete currentSkirt;
        currentSkirt = new Skirt(skirt);
        garmentCount++;
        numberOfChanges++;
        currentSkirt->addedGarment();
    }
    void addPants(const Pants& pants)
    {
        if (currentPants)
            delete currentPants;
        currentPants = new Pants(pants);
        garmentCount++;
        numberOfChanges++;
        currentPants->addedGarment();
    }
    void removeBlouse()
    {
        if(currentBlouse)
        {
            currentBlouse->removedGarment();
            delete currentBlouse;
            currentBlouse = nullptr;
            garmentCount--;
            numberOfChanges++;
        }
        else std::cout << "Barbie is not wearing any blouse.\n";
    }
    void removeDress()
    {
        if (currentDress)
        {
            currentDress->removedGarment();
            delete currentDress;
            currentDress = nullptr;
            garmentCount--;
            numberOfChanges++;
        }
        else std::cout << "Barbie is not wearing any dress.\n";
    }
    void removeSkirt()
    {
        if (currentSkirt)
        {
            currentSkirt->removedGarment();
            delete currentSkirt;
            currentSkirt = nullptr;
            garmentCount--;
            numberOfChanges++;
        }
        else std::cout << "Barbie is not wearing any skirt.\n";
    }
    void removePants()
    {
        if (currentPants)
        {
            currentPants->removedGarment();
            delete currentPants;
            currentPants = nullptr;
            garmentCount--;
            numberOfChanges++;
        }
        else std::cout << "Barbie is not wearing any pants.\n";
    }
    static int GetGarmentCount(void)
    {
        return garmentCount;
    }
    static void ViewChanges()
    {
        if (numberOfChanges == 0)
            std::cout << "You haven't changed Barbie's look yet." << std::endl;
        else if (numberOfChanges == 1)  
            std::cout << "You've made " << numberOfChanges << " change at Barbie's look so far." << std::endl;
        else std::cout << "You've made " << numberOfChanges << " changes at Barbie's look so far." << std::endl;
    }
    ~Barbie()
    {
        delete currentBlouse;
        delete currentDress;
        delete currentSkirt;
        delete currentPants;
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
    Barbie myBarbie;

    char key;
    bool continuegame;
    std::cout << "Press any key to start dressing up Barbie: " << std::endl; 
    std::cin >> key;
    std::cout << "Do you want to change Barbie's look? \n Yes (1) \t No (0)" << std::endl;
    std::cin >> continuegame;
    if (continuegame == 1)
    {
        std::cout << "Great! So let's get started\nOpen your mind and create the best outfit for Barbie!\n";
        while (continuegame == 1)
        {
            bool addClothes;
            std::cout << "Do you want to add some clothes?\nYes(1) \t No(0)" << std::endl;
            std::cin >> addClothes;
            while (addClothes != 0)
            {
                std::string addGarmentType;
                std::cout << "What kind of clothes do you want to add?" << std::endl;
                std::cin >> addGarmentType;
                if (toLower(addGarmentType) == "blouse")
                    {
                        int numberBlouse;
                        std::cout << "Add a blouse code and a blouse color from the wardrobe:\n";
                        describe_garment(blouse1);
                        describe_garment(blouse2);
                        describe_garment(blouse3);
                        describe_garment(blouse4);
                        std::cin >> numberBlouse;
                        if (numberBlouse == 1)
                            myBarbie.addBlouse(blouse1);
                        else if (numberBlouse == 2)
                            myBarbie.addBlouse(blouse2);
                        else if (numberBlouse == 3)
                            myBarbie.addBlouse(blouse3);
                        else if (numberBlouse == 4)
                            myBarbie.addBlouse(blouse4);
                        
                    }  
                    else if (toLower(addGarmentType) == "dress")
                    {
                        int numberDress;
                        std::cout << "Add a dress code and a dress color from the wardrobe:\n";
                        describe_garment(dress1);
                        describe_garment(dress2);
                        describe_garment(dress3);
                        describe_garment(dress4);
                        std::cin >> numberDress;
                        if (numberDress == 1)
                            myBarbie.addDress(dress1);
                        else if (numberDress == 2)
                            myBarbie.addDress(dress2);
                        else if (numberDress == 3)
                            myBarbie.addDress(dress3);
                        else if (numberDress == 4)
                            myBarbie.addDress(dress4);
                    }
                    else if (toLower(addGarmentType) == "skirt")
                    {
                        int numberSkirt;
                        std::cout << "Add a skirt code and a skirt color from the wardrobe:\n";
                        describe_garment(skirt1);
                        describe_garment(skirt2);
                        describe_garment(skirt3);
                        describe_garment(skirt4);
                        std::cin >> numberSkirt;
                        if (numberSkirt == 1)
                            myBarbie.addSkirt(skirt1);
                        else if (numberSkirt == 2)
                            myBarbie.addSkirt(skirt2);
                        else if (numberSkirt == 3)
                            myBarbie.addSkirt(skirt3);
                        else if (numberSkirt == 4)
                            myBarbie.addSkirt(skirt4);
                    }
                    else if (toLower(addGarmentType) == "pants")
                    {
                        int numberPants;
                        std::cout << "Add a pants code and a pants color from the wardrobe:\n";
                        describe_garment(pants1);
                        describe_garment(pants2);
                        describe_garment(pants3);
                        describe_garment(pants4);
                        std::cin >> numberPants;
                        if (numberPants == 1)
                            myBarbie.addPants(pants1);
                        else if (numberPants == 2)
                            myBarbie.addPants(pants2);
                        else if (numberPants == 3)
                            myBarbie.addPants(pants3);
                        else if (numberPants == 4)
                            myBarbie.addPants(pants4);
                    }    
                std::cout << "Do you want to add anything else?\nYes(1) \t No(0)\n";
                std::cin >> addClothes;
            }
            bool removeClothes;
            std::cout << "Do you want to remove some clothes?\nYes(1) \t No(0)" << std::endl;
            std::cin >> removeClothes;
            while (removeClothes != 0)
            {
                std::string removeGarmentType;
                std::cout << "What kind of clothes do you want to remove?" << std::endl;
                std::cin >> removeGarmentType;
                if (toLower(removeGarmentType) == "blouse")
                    myBarbie.removeBlouse();
                else if (toLower(removeGarmentType) == "dress")
                    myBarbie.removeDress();
                else if (toLower(removeGarmentType) == "skirt")
                    myBarbie.removeSkirt();
                else if (toLower(removeGarmentType) == "pants")
                    myBarbie.removePants();  
                std::cout << "Do you want to remove anything else?\nYes(1) \t No(0)\n";
                std::cin >> removeClothes;
            }
            bool change;
            std::cout << "Do you want to see how many changes have you done so far?\nYes(1) \t No(0)\n";
            std::cin >> change;
            if (change == 1)
                myBarbie.ViewChanges();
            std::cout << "Do you want to change something at Barbie's current look?\nYes(1) \t No(0)\n";
            std::cin >> continuegame;
        }
    }
    std::cout << "That's the end of the game!" << std::endl;

/*
    //function call through reference
    Garment& b1 = blouse1;
    std::cout << b1.getColor() << std::endl;
    Garment& d1 = dress3;
    d1.garment_type();

    //VPTR through reference
    Garment& g1 = dress2;
    g1.describe();
    Display(myBarbie);
    myBarbie.ViewChanges();
*/
    return 0;
}
