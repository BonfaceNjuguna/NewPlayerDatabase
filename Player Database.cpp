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
        int choice = 0;
        while (choice!=8)
        {
            choice = menu();
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
                system("cls");
                string name;
                cout << "Enter the Player's name: ";
                if (cin.peek() == '\n')cin.ignore();
                getline(cin, name);
                database.search(name);
                break;
            }

            case 3:
            {
                system("cls");
                int id;
                cout << "Enter ID number: ";
                cin >> id;
                database.search_id(id);
                break;
            }

            case 4:
            {
                system("cls");
                cout << "All the Players in the database!" << endl;
                database.display_all();
                break;
            }

            case 5:
            {
                system("cls");
                string name;
                cout << "Enter the name of Player to be removed: ";
                if (cin.peek() == '\n')cin.ignore();
                getline(cin, name);
                database.remove(name);
                break;
            }

            case 6:
            {
                system("cls");
                database.sort_stipend();
                cout << "Players sorted by Stipend!" << endl;
                database.display_all();
                break;
            }

            case 7:
            {
                system("cls");
                database.sort_name();
                cout << "Players sorted by Name!" << endl;
                database.display_all();
                break;
            }

            case 8:
            {
                system("cls");
                database.sort_age();
                cout << "Players sorted by Age!" << endl;
                database.display_all();
                break;
            }

            case 9:
            {
                break;
            }
            default:
                system("cls");
                cout << "Not a valid Player!!" << endl;
                break;
            }
        }
        ofstream fout(filename.c_str());
        if (!fout.fail())
        {
            database.save(fout);
        }
        else
        {
            cout << "File could not open!" << endl;
        }
        fout.close();
        cout << "Thank you!" << endl;
    }
    else
    {
        cout << "File does not exist, creating New File!" << endl;
        ofstream new_file(filename.c_str());
        new_file.close();
        main();
    }
    return 0;
}

int menu() 
{
    int choice;
    cout << "1. Add new player." << endl;
    cout << "2. Search for player by name." << endl;
    cout << "3. Search for player by ID number." << endl;
    cout << "4. Display all current players." << endl;
    cout << "5. Remove player form database" << endl;
    cout << "6. Sort Players by highest Stipend." << endl;
    cout << "7. Sort Player by First Name" << endl;
    cout << "8. Sort Player by Age" << endl;
    cout << "9. Quit." << endl;

    cin >> choice;
    return choice;
}