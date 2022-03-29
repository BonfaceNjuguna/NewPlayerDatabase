#include "database.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <Bits.h>


Database::Database()
{
	used = 0;
	capacity = 5;
	data = new Player[capacity];
}

Database::Database(const Database& other)
{
	used = other.used;
	capacity = other.capacity;
	data = new Player[capacity];
	std::copy(other.data, other.data + used, data);//copy from the begining to the end to the new
}

Database::~Database()
{
	delete[]data;
}

//overloaded equality operator
void Database::operator=(const Database& other)
{
	//checks if player exist in the database
	if (&other == this)
	{
		return;
	}
	delete[]data;
	capacity = other.capacity;
	used = other.used;
	data = new Player[capacity];
	std::copy(other.data, other.data + used, data);
}

//make the array bigger when 5
void Database::make_bigger()
{
	Player* tmp;
	tmp = new Player[capacity + 5];
	std::copy(data, data + used, tmp);
	delete[]data;
	data = tmp;
	capacity += 5;
}

int Database::binarySearch(int startindex, int length, std::string searchitem)
{
	int midpoint(length / 2);
	if (strcmp(data[startindex + midpoint].get_name(), searchitem.c_str()) == 0) return startindex + midpoint;
	if (length == 0) return -1;

	auto answer(binarySearch(startindex, length - midpoint, searchitem));
	if (answer != -1) return answer;
	return binarySearch(startindex + midpoint + 1, length - midpoint, searchitem);
}

Player* Database::search(std::string searchname)
{

	sort_name();

	auto foundPosition(binarySearch(0, used, searchname));

	if (foundPosition != -1)
		return &data[foundPosition];
	else
		return nullptr;
}


void Database::add(const Player& plr)
{
	//check if above capacity then add to the end
	if (used >= capacity)
	{
		make_bigger();
	}
	data[used] = plr;
	used++;
}

void Database::display_all()
{
	for (int i = 0; i < used; i++)
	{
		data[i].output(std::cout);
	}
}

void Database::remove(char* name)
{
	for (int i = 0; i < used; i++)
	{
		if (strcmp(data[i].get_name(), name) == 0)
		{
			data[i] = data[used - 1];
			used--;
		}
	}
}

void Database::save(std::ostream& outs)
{
	sort_name();
	for (int i = 0; i < used; i++)
	{
		outs.write((const char*)&data[i], sizeof(Player));
	}
}

void Database::load(std::istream& ins)
{
	Player tmp;

	while (ins.read((char*)&tmp, sizeof(Player)))
	{
		if (used >= capacity)
		{
			make_bigger();
		}
		tmp.index = used;
		data[used] = tmp;
		used++;
	}
}


//sort by name
void Database::sort_name()
{
	bool done = false;
	Player tmp;
	while (!done)
	{
		done = true;
		for (int i = 0; i < used - 1; i++)
		{
			if (strcmp(data[i].get_name(), data[i + 1].get_name()) > 0)
			{
				done = false;
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}
}

//sort by stipend
void Database::sort_stipend()
{
	bool done = false;
	Player tmp;
	while (!done)
	{
		done = true;
		for (int i = 0; i < used - 1; i++)
		{
			if (data[i].get_stipend() > data[i + 1].get_stipend())
			{
				done = false;
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}
}


//sort by age
void Database::sort_age()
{
	bool done = false;
	Player tmp;
	while (!done)
	{
		done = true;
		for (int i = 0; i < used - 1; i++)
		{
			if (data[i].get_age() > data[i + 1].get_age())
			{
				done = false;
				tmp = data[i];
				data[i] = data[i + 1];
				data[i + 1] = tmp;
			}
		}
	}
}