#pragma once
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
	Player();

	Player(std::string new_name, int new_id, double new_stipend, int new_age);
	std::string get_name() { return name; }
	int get_id_number() { return id_no; }
	double get_stipend() { return stipend; }
	int get_age() { return age; }

	void output(std::ostream& outs);
	void input(std::istream& ins);

private:
	std::string name;
	int id_no;
	double stipend;
	int age;

};

//overload
std::ostream& operator << (std::ostream, Player& temp);
std::istream& operator >> (std::istream, Player& temp);


#endif // !PLAYER_H