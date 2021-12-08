#include "database.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <Bits.h>

using namespace std;

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
	copy(other.data, other.data + used, data);//copy from the begining to the end to the new
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
	copy(other.data, other.data + used, data);
}

//make the array bigger when 5
void Database::make_bigger()
{
	Player* tmp;
	tmp = new Player[capacity + 5];
	copy(data, data + used, tmp);
	delete[]data;
	data = tmp;
	capacity += 5;
}

int Database::search(int start, int length, string searchname)
{

	sort_name();
	int midpoint(length / 2);


	/*
	Guidance
	int search_id(int start, int length, string searchname)
	rewrite the search_id() code to use get_name() to check the name of each element against the search name.
	check if the name comes before or after the data[midpoint] though (you can just use searchname < get_name() and searchname > get_name() ) and adjust the startindex and length accordingly.
	If the searchname < midpoint name then we need to check the lower half of the array, length = midpoint -1
	If the searchname > midpoint name then we need to check the upper half of the array, length = length - midpoint +1 AND startindex = midpoint+1
	*/

	/*int num_found = 0;
	for (int i = 0; i < used; i++)
	{
		if (strcmp(data[i].get_name(), searchname) == 0)
		{
			cout << "Player found!" << endl;
			data[i].output(cout);
			num_found++;
		}
	}
	if (num_found == 0)
	{
		cout << "No Player by that name!" << endl;
	}*/
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
		data[i].output(cout);
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

void Database::save(ostream& outs)
{
	sort_name();
	for (int i = 0; i < used; i++)
	{
		outs.write((const char*)&data[i], sizeof(Player));
	}
}

void Database::load(istream& ins)
{
	Player tmp;
	while (ins.read((char*)&tmp, sizeof(Player)))
	{
		if (used >= capacity)
		{
			make_bigger();
		}
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