#include "Items.h"
#pragma once
enum BPart{
	EARS,
	FACE,
	HANDS,
	FEET,
	ARMS,
	LEGS,
	CHEST,
	FUR,
	TAIL
};
class Bodypart{
public:
   char* name;
   char* change_desc;
   short part_of_set;
   Bodypart();
};
class Player{
public:
	Bodypart BP[9];
	Item inventory[5]; 
	short actual_room;
};