#include "OtherFunctions.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

std::string toLower(const std::string& str) 
{
    std::string result = str;
    for (char& c : result) 
        c = tolower(c);
    return result;
}
//using interface
void describe_garment(const Garment& clothing)
{
    clothing.describe();
}
void checkNumber(int x)
{
    if (x != 1 and x != 2 and x != 3 and x != 4)
    throw NonExistentGarment("Non-existent item!");
}
void removeBlouseFromOutfit(std::vector<Garment*>& outfit)
{
    for (auto it = outfit.begin(); it != outfit.end(); ++it)
        if (dynamic_cast<Blouse*>(*it) != nullptr)
        {
            delete *it; 
            outfit.erase(it);
            return; 
        }
}
void removeDressFromOutfit(std::vector<Garment*>& outfit)
{
    for (auto it = outfit.begin(); it != outfit.end(); ++it)
        if (dynamic_cast<Dress*>(*it) != nullptr)
        {
            delete *it; 
            outfit.erase(it);
            return; 
        }
}
void removeSkirtFromOutfit(std::vector<Garment*>& outfit)
{
    for (auto it = outfit.begin(); it != outfit.end(); ++it)
        if (dynamic_cast<Skirt*>(*it) != nullptr)
        {
            delete *it; 
            outfit.erase(it);
            return; 
        }
}
void removePantsFromOutfit(std::vector<Garment*>& outfit)
{
    for (auto it = outfit.begin(); it != outfit.end(); ++it)
        if (dynamic_cast<Pants*>(*it) != nullptr)
        {
            delete *it; 
            outfit.erase(it);
            return; 
        }
}
void Display(const Barbie& myBarbie)
{
    const int numberOfClothes = Barbie::GetGarmentCount();
    if (numberOfClothes == 0)
        std::cout << "Barbie isn' wearing anything at the moment." << std::endl;
    else if (numberOfClothes == 1)
        std::cout << "Barbie is wearing 1 piece of clothing at the moment." << std::endl;
    else std::cout << "Barbie is wearing " << numberOfClothes << " pieces of clothing at the moment." << std::endl;
    if (numberOfClothes != 0)
        std::cout << "Barbie is wearing:\n";
}