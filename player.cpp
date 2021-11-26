#include <iostream>
#include <string> 
#include "player.h"
using namespace std;

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


//output
void Player::output(ostream& outs)
{
	if (outs.fail() == cout.fail())
	{
		outs << "Name: " << name << endl;
		outs << "ID Number: " << id_no << endl;
		outs << "Stipend: " << stipend << endl;
		outs << "Age: " << age << endl;
	}
	else
	{
		outs << name << endl;
		outs << id_no << endl;
		outs << stipend << endl;
		outs << age << endl;
	}
}


//input
void Player::input(istream& ins)
{
	if (ins.fail() == cin.fail())
	{
		if (ins.peek() == '\n') ins.ignore();
		cout << "Name: ";
		ins >> name;
		cout << "Enter Id Number: ";
		ins >> id_no;
		cout << "Enter Stipend: ";
		ins >> stipend;
		cout << "Enter the age of player: ";
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

ostream& operator << (ostream& outs, Player& tmp)
{
	tmp.output(outs);
	return outs;
}

istream& operator >> (istream& ins, Player& tmp)
{
	tmp.input(ins);
	return ins;
}