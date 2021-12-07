#include "database.h"
#include "Player.h" 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int menu();
int main()
{
	Database database;

	std::ifstream fin("student.dat", std::ios::out | std::ios::binary);

	if (!fin.fail())
	{
		database.load(fin);
		fin.close();
	}
	else {
		std::cout << "File does not exist, creating New File!" << std::endl;
		std::ifstream new_file("student.dat", std::ios::out | std::ios::binary);
		new_file.close();
	}

	for (auto choice(menu()); choice != 9; choice = menu())
	{
		switch (choice)
		{
		case 1:
		{
			Player plr;
			std::cin >> plr;
			database.add(plr);
			break;
		}

		case 2:
		{
			system("cls");
			char name[256];
			std::cout << "Enter the Player's name: ";
			if (std::cin.peek() == '\n')std::cin.ignore();
			std::cin >> name;
			database.search(name);
			break;
		}

		case 3:
		{
			system("cls");
			int id[] = {};
			std::cout << "Enter ID number: ";
			std::cin >> id;
			database.search_id(id);
			break;
		}

		case 4:
		{
			system("cls");
			std::cout << "All the Players in the database!" << std::endl;
			database.display_all();
			break;
		}

		case 5:
		{
			system("cls");
			char name[256];
			std::cout << "Enter the name of Player to be removed: ";
			if (std::cin.peek() == '\n')std::cin.ignore();
			std::cin >> name;
			database.remove(name);
			std::cout << "Player removed! \n";
			break;
		}

		case 6:
		{
			system("cls");
			database.sort_stipend();
			std::cout << "Players sorted by Stipend!" << std::endl;
			database.display_all();
			break;
		}

		case 7:
		{
			system("cls");
			database.sort_name();
			std::cout << "Players sorted by Name!" << std::endl;
			database.display_all();
			break;
		}

		case 8:
		{
			system("cls");
			database.sort_age();
			std::cout << "Players sorted by Age!" << std::endl;
			database.display_all();
			break;
		}
		}
	}

	std::ofstream fout("student.dat", std::ios::out | std::ios::binary);
	if (!fout.fail())
	{
		database.save(fout);

		fout.close();
	}
	else
	{
		std::cout << "File could not open!" << std::endl;
	}
	std::cout << "Thank you!" << std::endl;


	return 0;
}

int menu()
{
	std::cout << " \n1. Add new player." << std::endl;
	std::cout << "2. Search for player by name." << std::endl;
	std::cout << "3. Search for player by ID number." << std::endl;
	std::cout << "4. Display all current players." << std::endl;
	std::cout << "5. Remove player form database" << std::endl;
	std::cout << "6. Sort Players by highest Stipend." << std::endl;
	std::cout << "7. Sort Player by First Name" << std::endl;
	std::cout << "8. Sort Player by Age" << std::endl;
	std::cout << "9. Quit." << std::endl;


	int choice;
	while (true) {
		std::cin >> choice;
		if (std::cin.bad()) {
			std::cin.ignore(std::cin.rdbuf()->in_avail());
			std::cout << "Bad input" << std::endl;
		}
		else break;
	}
	return choice;
}