/**
 * ---------------------------------------------------------------------------------------------------
 *
 * Course: CS151       Days & Time: Thurs, 5:30pm-9:20pm
 *
 * Chapter Number: N/A  Project Number or Group Project Name: Final Project (Pokedex)
 *
 * Programmer(s): Dennis La
 *
 * Date created or Last Modified: Last modified on 21 May 2019
 *
 * ---------------------------------------------------------------------------------------------------
 *
 * Program Title: Pokedex
 *
 * Program description: Lets the user find Pokemon entries in the Pokedex through searching and sorting methods.
 *
 * The purpose of this program is to: Provide the user a way to look up Pokemon data in a program that incorporates
 * CS topics learned in advanced C++
 *
 * ---------------------------------------------------------------------------------------------------
 *
 * ALGORITHM:
 * 1.
 *
 * ---------------------------------------------------------------------------------------------------
 *
 * IMPORTED PACKAGES:
 * #include <iostream> //needed to work with io
 * #include "Pokemon.h"
 * #include "Pokedex.h"
 *
 * ---------------------------------------------------------------------------------------------------
 */

#include <iostream>
#include "Pokemon.h"
#include "Pokedex.h"

using namespace std;

//Prototypes:
void printGreeting();
void printMenu();
void validatePokemonNum(int number, Pokedex * pokedex);

/**
 * PokedexOutofBoundsException class the extends exception. Thrown when the user enters a number that is out of
 * bounds of the Pokemon numbers range
 */
class PokedexOutofBoundsException : exception
{
public:
    /**
     * Default constructor
     */
    PokedexOutofBoundsException() = default;
};

/**
 * Driver that lts the user interact with the Pokedex menu. Lets the user view, search and sort the Pokemon.
 *
 * @return 0
 */
int main()
{
    //make a pokdex object
    Pokedex pokedex;

    //variable to hold users choice for the menu
    int userChoice;

    //print the greeting
    printGreeting();

    do
    {
        //print the menu
        printMenu();

        //get input from user
        cin >> userChoice;

        //validate
        while(cin.fail() || userChoice < 1 || userChoice > 7)
        {
            cin.clear();
            cin.ignore();

            cout << "Invalid choice please reenter." << endl;
            cin >> userChoice;
        }

        //switch to handle the choice from the user
        switch (userChoice)
        {
            //show all pokemon case
            case 1:
            {
                pokedex.showAllPokemon();

                break;
            }
            //search by pokemon number
            case 2:
            {
                //get number from user
                cout << "Enter the Pokemon number." << endl;
                int pokemonNum;

                cin >> pokemonNum;

                //validate
                while(cin.fail())
                {
                    cin.clear();
                    cin.ignore();

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

                //show the pokemon
                cout << pokedex.findPokemonByNumber(pokemonNum).showString() << endl;

                break;
            }
            //search by name
            case 3:
            {
                //get name from user
                cout << "Enter the Pokemon name or part of it." << endl;
                string name;

                cin.clear();
                cin.ignore();

                getline(cin, name);

                //show pokemon that match the entered string
                pokedex.findPokemonByName(name);

                break;
            }
            //search by type
            case 4:
            {
                //get the type from the user
                cout << "Enter the Pokemon type or part of it." << endl;
                string type;

                cin.clear();
                cin.ignore();

                getline(cin, type);

                //show pokemon that match the type
                pokedex.findPokemonByType(type);

                break;
            }
            //sort the pokemon by number
            case 5:
            {
                cout << "Sorting by number..." << endl;

                pokedex.sortByNumber();

                cout << "Sorting by number complete..." << endl;

                break;
            }
            //sort the pokemon by name
            case 6:
            {
                cout << "Sorting by name..." << endl;

                pokedex.sortByAlphabet();

                cout << "Sorting by name complete..." << endl;

                break;
            }
            //exit the program
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

/**
 * Print out the greeting
 */
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

/**
 * Print out the menu
 */
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

/**
 * Validates the pokemon number entered by the user by throwing an exception if it is out of bounds
 *
 * @param number the number they entered
 * @param pokedex the pokedex
 */
void validatePokemonNum(int number, Pokedex * pokedex)
{
    if(number < 1 || number > pokedex->getPokemonVector().size())
    {
        throw PokedexOutofBoundsException();
    }
}


