#include "Loader.h"
int main(){
	Item* ItemList = nullptr;
	LoadItems(ItemList);
	char** WallTypes = nullptr;
	LoadWT(WallTypes);
	Bodypart* BPList = nullptr;
	LoadBP(BPList);
}
