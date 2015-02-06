#include "Loader.h"
#pragma once
//convenience 
// ?: forces me to have a statement
void dummy(){};
std::fstream intro(char** names){	
	std::fstream file;
	std::string filename;
	std::cout << "enter the name of the"<< *(names + 0) <<"file (default 'Item.txt')" << std::endl;
	std::getline(std::cin,filename);
	filename.empty()?filename = *(names + 1):dummy();
	file.open(filename);
	file.seekg(0);
	return file;
};
short atos(char* string){
	short turner;
    turner = (std::atoi(string) & 0xFF);
	return turner;
}
void LoadItems(Item* &I){
	char* string[3] = {"Items","Item.txt",nullptr};
	std::fstream file = intro(string);
	std::streampos nes = 1024;
	for (int i = 0; !file.eof(); i++){
		file.getline((I + i)->name,nes,'//');
		file.getline((I + i)->description,nes,'//');
		file.getline(string[2],nes,'//');(I + i)->pickable = atos(string[2]);
		file.getline(string[2],nes,'//');(I + i)->use_type = atos(string[2]);
		file.getline(string[2],nes,'//');(I + i)->use_id[0] = atos(string[2]);
		file.getline(string[2],nes,'//');(I + i)->use_id[1] = atos(string[2]);
		file.getline(string[2],nes,'//');(I + i)->id = atos(string[2]);
	}
	file.close();  
};
void LoadRooms(Room* &R,Item* I){
	char* string[3] = {"Room","Rooms.txt",nullptr};
	std::fstream file = intro(string);
	std::streampos nes = 1024;
	for (int i = 0; !file.eof(); i++){
		file.getline((R + i)->name,nes,'//');
		file.getline((R + i)->description,nes,'//');
		for (int j = 0; j < 4; j++){
			file.getline((((R + i)->walls)+j)->description,nes,'//');
			file.getline(string[2],nes,'//');(((R + i)->walls)+j)->has_door = atos(string[2]);
			file.getline(string[2],nes,'//');(((R + i)->walls)+j)->connects_to = atos(string[2]);
			for (int k = 0; k < 5; k++){
				file.getline(string[2],nes,'//');*(((((R + i)->walls)+ j)->items)+ k) = *(I + atos(string[2]));
			}
		}
	}
	file.close();  
};
void LoadWT(char** &WT_Snacks){
	std::fstream file;
	std::string filename;
	std::cout << "enter the name of the wall_type file (default 'WT_Snacks.txt')" << std::endl;
	getline(std::cin,filename);
	filename.empty()?filename = "WT_Snacks.txt":dummy();
	file.open(filename);
	file.seekg(0);
	std::streampos nes = 1024;
	for (int i = 0; !file.eof(); i++){
		file.getline(*(WT_Snacks + i),nes,'//');
	}
	file.close();  
};
void LoadBP(Bodypart* &BP){
	std::fstream file;
	std::string filename;
	char* string = nullptr;
	std::cout << "enter the name of the BPart file (default 'BP.txt')" << std::endl;
	getline(std::cin,filename);
	filename.empty()?filename = "BP.txt":dummy();
	file.open(filename);
	file.seekg(0);
	std::streampos nes = 1024;
	for (int i = 0; !file.eof(); i++){
		file.getline((BP + i)->name,nes,'//');
		file.getline(string,nes,'//');(BP + i)->part_of_set = atos(string);
	}
	file.close();  
};
void LoadP(Player &P,Item* I,Bodypart* B){
		std::fstream file;
	std::string filename;
	char* string = nullptr;
	std::cout << "enter the name of the savefile (default 'Player.txt')" << std::endl;
	getline(std::cin,filename);
	filename.empty()?filename = "Player.txt":dummy();
	file.open(filename);
	file.seekg(0);
	std::streampos nes = 1024;
	for (int j = 0; j < 9; j++){
			file.getline(string,nes,'//');*((P.BP)+j) = *(B + atos(string));
		}for (int j = 0; j < 5; j++){
			file.getline(string,nes,'//');*((P.inventory)+j) = *(I + atos(string));
		}
		file.getline(string,nes,'//');P.actual_room = atos(string);
     file.close();   
};