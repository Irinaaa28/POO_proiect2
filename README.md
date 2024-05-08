# Barbie Dress Up Minigame Concept

## Introduction
I have adopted and implemented the concept of "Barbie Dress Up" games, a very popular game among browser users, which has brought happiness to many girls during their childhood. 
## How does the code behind this minigame look like?
Long story short, I used plenty of classes to distinguish every piece of clothing, to represent the Barbie doll and to face possible errors. Here are the steps:
* I created an interface called "Wardrobe" where to start the whole code;
* I created an abstract class called "Garment", which represents a general piece of clothing. Each variable in the "Garment" class consists of a code and a color; 
* Using the principle of inheritance, I created four derived classes from the "Garment" class, representing different types of clothing: "Blouse", "Dress", "Pants" and "Skirt".
* In order to prevent the game from ending due to an eventual error, I considered and implemented some classes for all possible errors;
* Then, I created a class called "Barbie", which represents the Barbie doll itself. Through the "Barbie" class, we upgrade her physical appearance by repeatedly adding and removing various clothes.
Within these classes I implemented:
  
##
