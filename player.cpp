#include "player.h"

#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include<stdlib.h>
#include<cstdlib>

//default constuctor
Player::Player()
{
	id_no = 0;
	stipend = 0;
	age = 0;
}

//copy constructor
Player::Player(char new_name[256], int new_id, double new_stipend, int new_age)
{
	strcpy_s(new_name, 256, name);
	id_no = new_id;
	stipend = new_stipend;
	age = new_age;
}

Player Player::set_name(std::string&)
{
	return Player();
}

//output
void Player::output(std::ostream& outs)
{
	if (outs.fail() == std::cout.fail())
	{
		outs << "Name: " << name << std::endl;
		outs << "ID Number: " << id_no << std::endl;
		outs << "Stipend: " << stipend << std::endl;
		outs << "Age: " << age << std::endl;
	}
	else
	{
		outs << name << std::endl;
		outs << id_no << std::endl;
		outs << stipend << std::endl;
		outs << age << std::endl;
	}
}


//input
void Player::input(std::istream& ins)
{
	if (ins.fail() == std::cin.fail())
	{
		if (ins.peek() == '\n') ins.ignore();
		std::cout << "Name: ";
		ins >> name;
		std::cout << "Enter Id Number: ";
		ins >> id_no;
		std::cout << "Enter Stipend: ";
		ins >> stipend;
		std::cout << "Enter the age of player: ";
		ins >> age;
	}
	else
	{
		if (ins.peek() == '\n') ins.ignore();
		ins >> name;;
		ins >> id_no;
		ins >> stipend;
		ins >> age;
	}
}

std::ostream& operator << (std::ostream& outs, Player& tmp)
{
	tmp.output(outs);
	return outs;
}

std::istream& operator >> (std::istream& ins, Player& tmp)
{
	tmp.input(ins);
	return ins;
}