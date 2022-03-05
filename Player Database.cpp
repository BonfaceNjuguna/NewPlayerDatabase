#include "database.h"
#include "Player.h" 

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


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
			std::string searchName;
			std::cout << "Enter the Player's name: ";
			if (std::cin.peek() == '\n')std::cin.ignore();
			std::cin >> searchName;
			auto player = database.search(0, searchName);
			if (player != nullptr)
				std::cout << "Player " << searchName << " found! " << std::endl;
			else
				std::cout << "Player not found!" << std::endl;
			break;
		}
		case 3:
		{
			system("cls");
			std::string searchName;
			std::cout << "Enter the Player's name: ";
			if (std::cin.peek() == '\n')std::cin.ignore();
			std::cin >> searchName;
			auto player = database.search(0, searchName);
			if (player != nullptr) 
			{
				std::cout << "Player " << searchName << " found! " << std::endl;
				std::cout << "Enter new player name:" << std::endl;
				std::string inpt;
				std::cin >> inpt;

				std::string i = inpt;


				fin.open("student.dat", std::ios::in | std::ios::out, std::ios::binary);

				Player splr;

				fin.seekg(sizeof(Player), sizeof(i));
				fin.read((char*)&splr, sizeof(Player));

				Player newPlr;

				std::string newName;
				std::cin >> newName;

				newPlr.get_name() == newName;
				splr = Player(newPlr);

				/*fin.seekp(sizeof(Player), sizeof(i) + sizeof(int));
				fin.write((const char*)&ioplr, sizeof(Player));*/

				std::cout << "Player edited successfully!!" << std::endl;

				fin.close();
			}				
			else
				std::cout << "Player not found!" << std::endl;
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
			std::cout << "Search Player Name: ";
			if (std::cin.peek() == '\n')std::cin.ignore();
			std::cin >> name;
			auto player = database.search(0, name);

			if (player != nullptr) 
			{
				database.remove(name);
				std::cout << "Player deleted successfully!" << std::endl;				
			}	
			else
				std::cout << "Player not found!" << std::endl;
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
	std::cout << "3. Edit Player Name." << std::endl;
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