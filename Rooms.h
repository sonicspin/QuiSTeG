#include "Items.h"
#pragma once
/*wall class
  description = description of the wall
  has_door= different number are different doors, defined in door_types
  connects_to = connects to which room
  items = items of a room
*/
class Wall{
public:
	char* description;
	short has_door;
	unsigned short connects_to;
	Item items[5];
	Wall();
};
/*Room class
  name
*/
class Room{
public:
	char* name;
	char* description;
	Wall walls[4];
	Room();
};