#include <iostream>
#include <fstream>
#include <string>
#include "database.h"
#include "Player.h"
using namespace std;

int menu();
int main()
{
    Database database;
    Player plr;
    string filename;
    cout << "Enter the name of the file: ";
    getline(cin, filename);
    filename + ".txt";
    ifstream fin(filename.c_str());
    if (!fin.fail())
    {
        database.load(fin);
        fin.close();
        while (choice!=8)
        {
            int choice = menu();
            switch (choice)
            {
            case 1: 
            {
                cin >> plr;
                database.add(plr);
                break;
            }

            case 2:
            {

            }

            case 3:
            {

            }

            case 4:
            {

            }

            case 5:
            {

            }

            case 6:
            {

            }

            case 7:
            {

            }

            case 8:
            {

            }
            default:
                break;
            }
        }
    }
}

int menu() 
{
    int choice;
    cout << "1. Add new player." << endl;
    cout << "2. Search for player by name." << endl;
    cout << "3. Search for player by ID number." << endl;
    cout << "4. Display all current players." << endl;
    cout << "5. Remove player form database" << endl;
    cout << "6. Sort Players by highest salary." << endl;
    cout << "7. Sort Player by First Name" << endl;
    cout << "8. Quit." << endl;

    cin >> choice;
    return choice;
}