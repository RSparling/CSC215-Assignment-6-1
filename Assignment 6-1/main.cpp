/*TODO for continued work:
- Make a JSON serializer/deserializer
- Write a program to create encounters in a much easier manner by serializing them into a form that can deserialize
- Refine codebase to reduce coupling
- Clean up Game.cpp to better compartmentalize*/

#include<iostream>
#include "Game.h"

int main() {
	Game game;
	game.Begin();
	return 0;
}
