#include <fstream>
#include <string>
#include <iostream>
#include "Items.h"
#include "Rooms.h"
#include "Player.h"
#pragma once
void dummy();
short atos(char* string);
std::fstream intro();
void LoadItems(Item* &I); //
void LoadRooms(Room* &R,Item* I); 
void LoadWT(char** &WT_Snacks); //
void LoadBP(Bodypart* &BP);  //
void LoadP(Player &P,Item* I,Bodypart* B);

