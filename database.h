#pragma once
#ifndef DATABASE_H
#define DATABASE_H
#include "player.h"


class Database
{
public:
	Database();
	~Database();
	Database(const Database& other);
	void operator = (const Database& other);
	//void search(char* name);
	Player search(int start, std::string searchname);
	void add(const Player& plr);
	void display_all();
	void remove(char* name); 
	void save(std::ostream& outs);
	void load(std::istream& ins);
	void sort_name();
	void sort_stipend();
	void sort_age();

private:
	void make_bigger();
	int binarySearch(int startindex, int length, std::string searchitem);
	int capacity;
	Player* data;
	int used;

};

#endif // !DATABASE_H
