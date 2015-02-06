/*items
  name = name
  uses = number of uses
  max_uses = max uses of an item
  id = id for using purposes
  pickable = is pickable or not? short because of processing purposes
  use_type = how do you use the thing
   0 = you don't
   1 = use_id[0] into use_id[1]
   2 = unlocks room use_id[0]'s use_id[1] wall's door
   3 = turns bodypart[rand()%8] into BPList[use_id[1]*8 + rand()]
*/
#pragma once
class Item{
public:
	char* name;
	char* description;
	short pickable;
	short use_type;
	short use_id[2];
	short id;
	Item();
};