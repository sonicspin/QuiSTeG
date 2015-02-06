#pragma once
#include "Rooms.h"
Wall::Wall(){
   has_door = false;
   connects_to = 0;
   description = "NULL";
}
Room::Room(){
    name = "NULL";
    description = "NULL";
}