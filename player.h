#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

class Player
{
public:
	Player();

	Player(char new_name[256], int new_id, double new_stipend, int new_age);
	char* get_name() { return name; }
	int get_id_number() { return id_no; }
	double get_stipend() { return stipend; }
	int get_age() { return age; }
	int index;
	void set_name(std::string& newname);

	void output(std::ostream& outs);
	void input(std::istream& ins);

private:
	char name[256];
	int id_no;
	double stipend;
	int age;

};

//overload
std::ostream& operator << (std::ostream&, Player& temp);
std::istream& operator >> (std::istream&, Player& temp);


#endif // !PLAYER_H