#include <iostream>
#include <string>

class Garment
{
protected:
    std::string garmentCode;
    std::string garmentColor;
public:
    Garment(const std::string& garmentCode, const std::string& garmentColor): garmentCode(garmentCode), garmentColor(garmentColor) {}
    virtual void show() const
    {
        std::cout << "Garment " << garmentCode << ", color " << garmentColor << std::endl;
    }
    std::string getCode() const //getter code
    {
        return garmentCode;
    }
    std::string getColor() const //getter color
    {
        return garmentColor;
    }
};

class Blouse : public Garment
{
public:
    //Blouse(const std::string& garmentCode = "", const std::string& garmentColor = ""): Garment(garmentCode, garmentColor) {}
    Blouse(const std::string& garmentCode, const std::string& garmentColor): Garment(garmentCode, garmentColor) {}
    void show() const override
    {
        std::cout << "Blouse: " << garmentCode << ", color: " << garmentColor << std::endl;
    }
};


int main()
{
    Blouse g("#BT1CR", "Red");
    Garment& blouse1 = g;
    blouse1.show();
    return 0;
}
