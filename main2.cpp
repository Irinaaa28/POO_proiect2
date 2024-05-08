#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cctype>
#include <cstring>

#include "wardrobe.h"
#include "Garment.h"
#include "Blouse.h"
#include "Dress.h"
#include "Skirt.h"
#include "Pants.h"
#include "AlreadyAddedGarment.h"
#include "NonExistentGarment.h"
#include "NothingToRemove.h"
#include "Barbie.h"
#include "OtherFunctions.h"

int main()
{
    Blouse blouse1("#BT1CR", "Red"), blouse2("#BT1CB", "Blue"), blouse3("#BT1CG", "Green"), blouse4("#BT1CY", "Yellow");
    Dress dress1("#DT1CR", "Red"), dress2("#DT1CB", "Blue"), dress3("#DT1CG", "Green"), dress4("#DT1CY", "Yellow");
    Skirt skirt1("#ST1CR", "Red"), skirt2("#ST1CB", "Blue"), skirt3("#ST1CG", "Green"), skirt4("#ST1CY", "Yellow");
    Pants pants1("#PT1CR", "Red"), pants2("#PT1CB", "Blue"), pants3("#PT1CG", "Green"), pants4("#PT1CY", "Yellow");

    std::vector<Garment*> outfit;

    /*Garment* garmentPtr = new Blouse("#BT1CR", "Red");
    Blouse* blousePtr = static_cast<Blouse*>(garmentPtr);*/

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
                try
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
                            try
                            {
                                checkNumber(numberBlouse);
                            }
                            catch(const NonExistentGarment& e)
                            {
                                std::cerr << e.what() << '\n';
                            }
                            if (numberBlouse == 1)
                            {
                                myBarbie.addBlouse(blouse1);
                                outfit.push_back(new Blouse(blouse1.getCode(), blouse1.getColor()));
                            }
                            else if (numberBlouse == 2)
                            {
                                myBarbie.addBlouse(blouse2);
                                outfit.push_back(new Blouse(blouse2.getCode(), blouse2.getColor()));
                            }
                            else if (numberBlouse == 3)
                            {
                                myBarbie.addBlouse(blouse3);
                                outfit.push_back(new Blouse(blouse3.getCode(), blouse3.getColor()));
                            }
                            else if (numberBlouse == 4)
                            {
                                myBarbie.addBlouse(blouse4);
                                outfit.push_back(new Blouse(blouse4.getCode(), blouse4.getColor()));
                            }  
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
                        try
                        {
                            checkNumber(numberDress);
                        }
                        catch(const NonExistentGarment& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                        if (numberDress == 1)
                        {
                            myBarbie.addDress(dress1);
                            outfit.push_back(new Dress(dress1.getCode(), dress1.getColor()));
                        }
                        else if (numberDress == 2)
                        {
                            myBarbie.addDress(dress2);
                            outfit.push_back(new Dress(dress2.getCode(), dress2.getColor()));
                        }
                        else if (numberDress == 3)
                        {
                            myBarbie.addDress(dress3);
                            outfit.push_back(new Dress(dress3.getCode(), dress3.getColor()));
                        }
                        else if (numberDress == 4)
                        {
                            myBarbie.addDress(dress4);
                            outfit.push_back(new Dress(dress4.getCode(), dress4.getColor()));
                        }
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
                        try
                        {
                           checkNumber(numberSkirt);
                        }
                        catch(const NonExistentGarment& e)
                        {
                           std::cerr << e.what() << '\n';
                        }
                        if (numberSkirt == 1)
                        {
                            myBarbie.addSkirt(skirt1);
                            outfit.push_back(new Skirt(skirt1.getCode(), skirt1.getColor()));
                        }
                        else if (numberSkirt == 2)
                        {
                            myBarbie.addSkirt(skirt2);
                            outfit.push_back(new Skirt(skirt2.getCode(), skirt2.getColor()));
                        }
                        else if (numberSkirt == 3)
                        {
                            myBarbie.addSkirt(skirt3);
                            outfit.push_back(new Skirt(skirt3.getCode(), skirt3.getColor()));
                        }
                        else if (numberSkirt == 4)
                        {
                            myBarbie.addSkirt(skirt4);
                            outfit.push_back(new Skirt(skirt4.getCode(), skirt4.getColor()));
                        }
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
                        try
                        {
                            checkNumber(numberPants);
                        }
                        catch(const NonExistentGarment& e)
                        {
                            std::cerr << e.what() << '\n';
                        }
                        if (numberPants == 1)
                        {
                            myBarbie.addPants(pants1);
                            outfit.push_back(new Pants(pants1.getCode(), pants1.getColor()));
                        }
                        else if (numberPants == 2)
                        {
                            myBarbie.addPants(pants2);
                            outfit.push_back(new Pants(pants2.getCode(), pants2.getColor()));
                        }
                        else if (numberPants == 3)
                        {
                            myBarbie.addPants(pants3);
                            outfit.push_back(new Pants(pants3.getCode(), pants3.getColor()));
                        }
                        else if (numberPants == 4)
                        {
                            myBarbie.addPants(pants4);
                            outfit.push_back(new Pants(pants4.getCode(), pants4.getColor()));
                        }
                    }    
                }
                catch(const AlreadyAddedGarment& e)
                {
                    std::cerr << "Error: " <<  e.what() << '\n';
                }
                std::cout << "Do you want to add anything else?\nYes(1) \t No(0)\n";
                std::cin >> addClothes;
            }
            bool removeClothes;
            std::cout << "Do you want to remove some clothes?\nYes(1) \t No(0)" << std::endl;
            std::cin >> removeClothes;
            while (removeClothes != 0)
            {
                try
                {
                    std::string removeGarmentType;
                    std::cout << "What kind of clothes do you want to remove?" << std::endl;
                    std::cin >> removeGarmentType;
                    if (toLower(removeGarmentType) == "blouse")
                    {
                        myBarbie.removeBlouse();
                        removeBlouseFromOutfit(outfit);
                    }
                    else if (toLower(removeGarmentType) == "dress")
                    {
                        myBarbie.removeDress();
                        removeDressFromOutfit(outfit);
                    }
                    else if (toLower(removeGarmentType) == "skirt")
                    {
                        myBarbie.removeSkirt();
                        removeSkirtFromOutfit(outfit);
                    }
                    else if (toLower(removeGarmentType) == "pants")
                    {
                        myBarbie.removePants();  
                        removePantsFromOutfit(outfit);
                    }
                }
                catch(const NothingToRemove& e)
                {
                    std::cerr << "Error: " << e.what() << '\n';
                }
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
    Display(myBarbie);
    for (Garment *cloth : outfit)
    {
        if (Blouse* blouse = dynamic_cast<Blouse*>(cloth))
        {
            //blouse->garment_type();
            blouse->describe();
        }
        else if (Dress* dress = dynamic_cast<Dress*>(cloth))
        {
            //dress->garment_type();
            dress->describe();
        }
        else if (Skirt* skirt = dynamic_cast<Skirt*>(cloth))
        {
            //skirt->garment_type();
            skirt->describe();
        }
        else if (Pants* pants = dynamic_cast<Pants*>(cloth))
        {
            //pants->garment_type();
            pants->describe();
        }
        delete cloth;
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