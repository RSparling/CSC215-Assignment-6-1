/*
Russell Sparling
Assignment 6.1
Professor: Tony Hinton
Due: September 24. 2024

Disclaimer to Professor:
This project is based on the earlier 3.1 assignment though the primary thing that was reused was the 3 player resources
and the text for the scenarios. Other than that the way this is made makes it much more extensible and includes a builder pattern
for the creation of each encounter which have been named Scenes.
*/

/*TODO for continued work:
- Make a json serializer/deserializer
- Write a progam to create encounters in a much easier manner by serializing them into a form this can deserialize
- Refine codebase to reduce coupling
- Clean up Game.cpp to better comparmentalize*/
#include<iostream>
#include "Game.h"

int main() {
	Game game;
	game.Begin();
	return 0;
}