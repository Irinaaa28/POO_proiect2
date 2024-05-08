#ifndef BARBIE_H
#define BARBIE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

#include "Blouse.h"
#include "Dress.h"
#include "Skirt.h"
#include "Pants.h"
#include "AlreadyAddedGarment.h"
#include "NothingToRemove.h"

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
    Barbie();
    void addBlouse(const Blouse& blouse);
    void addDress(const Dress& dress);
    void addSkirt(const Skirt& skirt);
    void addPants(const Pants& pants);
    void removeBlouse();
    void removeDress();
    void removeSkirt();
    void removePants();
    static int GetGarmentCount();
    static void ViewChanges();
    ~Barbie();
};

#endif // BARBIE_H
