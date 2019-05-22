#include <iostream>
#include <stdio.h>      /* printf */
#include <stdlib.h>
#include "Pokemon.h"
#include "Pokedex.h"

using namespace std;

//Prototypes:
void printGreeting();
void printMenu();
void validatePokemonNum(int number, Pokedex * pokedex);

class PokedexOutofBoundsException : exception
{
public:
    /**
     * Default constructor
     */
    PokedexOutofBoundsException() = default;
};

int main()
{
    Pokedex pokedex;
    int userChoice;

    printGreeting();

    do
    {
        printMenu();

        cin >> userChoice;

        while(cin.fail() || userChoice < 1 || userChoice > 7)
        {
            cout << "Invalid choice please reenter." << endl;
            cin >> userChoice;
        }

        //switch to handle the choice from the user
        switch (userChoice)
        {
            case 1:
            {
                pokedex.showAllPokemon();

                break;
            }
            case 2:
            {
                cout << "Enter the Pokemon number." << endl;
                int pokemonNum;

                cin >> pokemonNum;

                while(cin.fail())
                {
                    cout << "Invalid input please reenter." << endl;
                    cin >> pokemonNum;
                }

                //validate the number
                try
                {
                    validatePokemonNum(pokemonNum, &pokedex);
                }
                catch (PokedexOutofBoundsException)
                {
                    cout << "Number out of bounds." << endl;
                    break;
                }

                cout << pokedex.findPokemonByNumber(pokemonNum).showString() << endl;

                break;
            }
            case 3:
            {
                cout << "Enter the Pokemon name or part of it." << endl;
                string name;

                cin.clear();
                cin.ignore();

                getline(cin, name);

                pokedex.findPokemonByName(name);

                break;
            }
            case 4:
            {
                cout << "Enter the Pokemon type or part of it." << endl;
                string type;

                cin.clear();
                cin.ignore();

                getline(cin, type);

                pokedex.findPokemonByType(type);

                break;
            }
            case 5:
            {
                cout << "Sorting by number..." << endl;

                pokedex.sortByNumber();

                cout << "Sorting by number complete..." << endl;

                break;
            }
            case 6:
            {
                cout << "Sorting by name..." << endl;

                pokedex.sortByAlphabet();

                cout << "Sorting by name complete..." << endl;

                break;
            }
            case 7:
            {
                cout << "Exiting Pokedex." << endl;

                break;
            }
            default:
            {
                break;
            }

        }

    }while(userChoice != 7);




    return 0;
}

void printGreeting()
{
    string pokemonLogo = "                                  ,'\\\n"
                         "    _.----.        ____         ,'  _\\   ___    ___     ____\n"
                         "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.\n"
                         "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |\n"
                         " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |\n"
                         "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |\n"
                         "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |\n"
                         "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |\n"
                         "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |\n"
                         "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |\n"
                         "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   |\n"
                         "                                `'                            '-._|";

    cout << pokemonLogo << endl;
    cout << "Welcome to the Pokedex!" << endl;
}

void printMenu()
{
    cout << "Pokedex Menu" << endl;
    cout << "1. Show all pokemon" << endl;
    cout << "2. Find Pokemon by number" << endl;
    cout << "3. Find Pokemon by name" << endl;
    cout << "4. Find Pokemon by type" << endl;
    cout << "5. Sort Pokemon by number" << endl;
    cout << "6. Sort Pokemon by name" << endl;
    cout << "7. Exit Pokedex" << endl;
    cout << "Enter your choice." << endl;
}

void validatePokemonNum(int number, Pokedex * pokedex)
{
    if(number < 1 || number > pokedex->getPokemonVector().size())
    {
        throw PokedexOutofBoundsException();
    }
}


