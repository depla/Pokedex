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
 * 1. Create a Pokedex object and a integer variable to hold the user input. The Pokedex object initializes a
 * vector of Pokemon objects. This is done by reading the data from PokemonInfo.txt and pushing the data into
 * the vector. The Pokemon ascii images are also read from PokemonImages.txt which is full of ascii images
 * of different pokemon separated by a 'X' character as a delimiter. Each image (string of ascii characters) is used
 * to create a PokemonImage object which is then pushed into another vector of PokemonImage. For each pokemon object in
 * the Pokemon vector, we set all the PokemonImages for each Pokemon to the corresponding PokemonImage in the
 * PokemonImage vector. We close the files after each is read. To read from PokemonInfo, the program tokenizes
 * the each lines into strings that are delimited by a '|' symbol. It then sets the pokemon's data to the
 * appropriate string. To read from PokemonImage, each image is read as a string dilimited by a 'X' symbol.
 * 
 * 2. Print out the greeting for the Pokedex
 * 
 * 3. Within a do while loop, print out the Pokdex menu and ask the user for input on what they want to do with
 * the Pokedex
 * 
 * 4. Validate the input by checking if cin failed, if the number is less than 1 or greater than 7. If so ask them
 * to reenter.
 * 
 * 5. There are 7 choices (1-7):
 *      1. Show all pokemon
 *      2. Find Pokemon by number
 *      3. Find Pokemon by name
 *      4. Find Pokemon by type
 *      5. Sort Pokemon by number
 *      6. Sort Pokemon by name
 *      7. Exit Pokedex
 *
 * 6. The user enters their choice and a switch case is used to handle each choice
 *
 * 7. If the user enters 1: Call the showAllPokemon method from the pokedex which prints out the showString
 * for all Pokemon objects in the vector in the Pokedex class.
 *
 * 8. If the user enters 2: We get the number from the user which is first validated by checking if it is a number
 * and then checking if it is within the range of total pokemon in the vector. If it is not, a
 * PokedexOutofBoundsException is thrown and the search is unsuccessful. If it is successful, the number is passed
 * to the findPokemonByNumber method which returns a pokemon object. The object then calls the showString method
 * to show its data. The findPokemonByNumber calls a template function that searches a generic vector of any type
 * and returns the object. The findPokemonByNumber decrements the number entered by the user to adjust for the
 * indexing that starts at 0 for vectors. The range of pokemon is 1 to the size of the vector.
 *
 * 9. If the user enters 3: Ask the user to enter a string name or part of the name of a pokemon. We then call the
 * findPokemonByName method by passing in the name. This method turns the string into a cstring and changes all of
 * its letters to lower case so that case does not matter. For each pokemon in the pokemon vector, we grab its
 * name into a local string variable using the getName method and make a char pointer point at the first char. We
 * then switch that first char to lower case to make sure case does not matter. We then check if the pokemon's name
 * contains the characters that were entered by the user using the find method from string. If it does contain the
 * characters, then print out the pokemon's showString method.
 *
 * 10. If the user enters 4: Ask the user to enter a string type or part of the type of a pokemon. We then call the
 * findPokemonByType method by passing in the type. This method turns the string into a cstring and changes all of
 * its letters to lower case so that case does not matter. For each pokemon in the pokemon vector, we grab its
 * primary type and secondary type into a local string variables using the getPrimaryType and getSecondaryType methods.
 * We make a char pointer point at the first char of the primary type and then switch that first char to lower case to
 * make sure case does not matter. The same is done for the secondary type as well. We then check if the either of the
 * pokemon's primary or secondary types contains the characters that were entered by the user using the find method
 * from string. If it does contain the characters, then print out the pokemon's showString method.
 *
 * 11. If the user enters 5: This will call the sortByNumber method of the pokedex. This method creates an array copy
 * of the vector by copying each element in the pokemonVector using a for loop. The method
 * then calls a recursiveBubbleSortNumber method that uses bubble sort to recursively sort the array of pokemon.
 * The array and size of the array is passed into the recursive method. The base case of the recursive method is when
 * the array is size 1 which means it is already sorted. Otherwise, it performs one run of bubble sort which
 * guarantees the that biggest value is at the end of the array. The recursive case decrements the size and passes that
 * and the array into the next call which will ultimately reach the base case when the size gets to 1. The bubble sort
 * compares the pokemon's numbers using the getNumber method. If the first pokemon is bigger than the second, then
 * the helper template function swap is called. This method swaps items of type T. After the recursion is done, the
 * array is sorted and the pokemonVector is updated to the array values by using a for loop that
 * iterates through each index and copies the values from the sorted array in to the vector.
 *
 * 12. If the user enters 6: This will call the sortByAlphabet method of the pokedex. This method creates an array copy
 * of the vector by copying each element in the pokemonVector using a for loop. The method
 * then calls a recursiveBubbleSortName method that uses bubble sort to recursively sort the array of pokemon.
 * The array and size of the array is passed into the recursive method. The base case of the recursive method is when
 * the array is size 1 which means it is already sorted. Otherwise, it performs one run of bubble sort which
 * guarantees the that biggest value is at the end of the array. The recursive case decrements the size and passes that
 * and the array into the next call which will ultimately reach the base case when the size gets to 1. The bubble sort
 * compares the pokemon's names using the getName method. If the first pokemon is bigger than the second, then
 * the helper template function swap is called. This method swaps items of type T. This comparison is done by using
 * the string compare method and seeing if a positive value is returned. After the recursion is done, the
 * array is sorted and the pokemonVector is updated to the array values by using a for loop that
 * iterates through each index and copies the values from the sorted array in to the vector.
 *
 * 13. If the user enter 7: The program ends
 *
 * 14. Otherwise, do nothing and go back to the beginning of the do while loop
 *
 * ---------------------------------------------------------------------------------------------------
 *
 * IMPORTED PACKAGES:
 * #include <iostream> //needed to work with io
 * #include "Pokemon.h" //needed to work with Pokemon class
 * #include "Pokedex.h" //needed to work with Pokedex class
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


