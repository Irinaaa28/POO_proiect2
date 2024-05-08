#include "Barbie.h"

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

int Barbie::garmentCount = 0;
int Barbie::numberOfChanges = 0;
   
//Barbie(const Blouse& currentBlouse, const Dress& currentDress, const Skirt& currentSkirt, const Pants& currentPants): currentBlouse(currentBlouse), currentDress(currentDress), currentSkirt(currentSkirt), currentPants(currentPants) {}
//Barbie(const std::string& blouseCode, const std::string& dressCode, const std::string& skirtCode, const std::string& pantsCode): currentBlouse(blouseCode, ""), currentDress(dressCode, ""), currentSkirt(skirtCode, ""), currentPants(pantsCode, "") {}
Barbie::Barbie(): currentBlouse(nullptr), currentDress(nullptr), currentSkirt(nullptr), currentPants(nullptr) {}
void Barbie::addBlouse(const Blouse& blouse)
{
    /*if (currentBlouse)
        delete currentBlouse;*/
    if (currentBlouse)
        throw AlreadyAddedGarment("blouse already added!");
    currentBlouse = new Blouse(blouse);
    garmentCount++;
    numberOfChanges++;
    currentBlouse->addedGarment();
}
void Barbie::addDress(const Dress& dress)
{
    if (currentDress)
        //delete currentDress;
        throw AlreadyAddedGarment("dress already added!");
    currentDress = new Dress(dress);
    garmentCount++;
    numberOfChanges++;
    currentDress->addedGarment();
}
void Barbie::addSkirt(const Skirt& skirt)
{
    if (currentSkirt)
        //delete currentSkirt;
        throw AlreadyAddedGarment("skirt already added!");
    currentSkirt = new Skirt(skirt);
    garmentCount++;
    numberOfChanges++;
    currentSkirt->addedGarment();
}
void Barbie::addPants(const Pants& pants)
{
    if (currentPants)
        //delete currentPants;
        throw AlreadyAddedGarment("pants already added!");
    currentPants = new Pants(pants);
    garmentCount++;
    numberOfChanges++;
    currentPants->addedGarment();
}
void Barbie::removeBlouse()
{
    if(!currentBlouse)
        throw NothingToRemove("There is no blouse to remove!");
    else
    {
        currentBlouse->removedGarment();
        delete currentBlouse;
        currentBlouse = nullptr;
        garmentCount--;
        numberOfChanges++;
    }
    //else std::cout << "Barbie is not wearing any blouse.\n";
}
void Barbie::removeDress()
{
    if (!currentDress)
        throw NothingToRemove("There is no dress to remove!");
    else
    {
        currentDress->removedGarment();
        delete currentDress;
        currentDress = nullptr;
        garmentCount--;
        numberOfChanges++;
    }
    //else std::cout << "Barbie is not wearing any dress.\n";
}
void Barbie::removeSkirt()
{
    if (!currentSkirt)
        throw NothingToRemove("There is no skirt to remove!");
    else
    {
        currentSkirt->removedGarment();
        delete currentSkirt;
        currentSkirt = nullptr;
        garmentCount--;
        numberOfChanges++;
    }
    //else std::cout << "Barbie is not wearing any skirt.\n";
}
void Barbie::removePants()
{
    if (!currentPants)
        throw NothingToRemove("There are no pants to remove!");
    else
    {
        currentPants->removedGarment();
        delete currentPants;
        currentPants = nullptr;
        garmentCount--;
        numberOfChanges++;
    }
    //else std::cout << "Barbie is not wearing any pants.\n";
}
int Barbie::GetGarmentCount(void)
{
    return garmentCount;
}
void Barbie::ViewChanges()
{
    if (numberOfChanges == 0)
        std::cout << "You haven't changed Barbie's look yet." << std::endl;
    else if (numberOfChanges == 1)  
        std::cout << "You've made " << numberOfChanges << " change at Barbie's look so far." << std::endl;
    else std::cout << "You've made " << numberOfChanges << " changes at Barbie's look so far." << std::endl;
}
Barbie::~Barbie()
{
    delete currentBlouse;
    delete currentDress;
    delete currentSkirt;
    delete currentPants;
}
