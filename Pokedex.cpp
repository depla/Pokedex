//
// Created by Dennis La on 2019-05-07.
//

#include "Pokedex.h"
#include "PokemonImage.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * Constructor that initializes the Pokemon Vector by calling the initializePokemonVector helper method
 */
Pokedex :: Pokedex()
{
    initializePokemonVector();
}

/**
 * Shows all pokemon by printing out all the pokemon in the vector
 */
void Pokedex :: showAllPokemon()
{
    for(Pokemon pokemon : pokemonVector)
    {
        cout << pokemon.showString() << endl;
    }
}

/**
 * Returns the pokemon associated with the number
 */
Pokemon Pokedex :: findPokemonByNumber(int number)
{
    number--;

    return search(pokemonVector, number);
}

/**
 * Template function that takes in a vector of generic type and uses a given int to search a given vector
 *
 * @tparam T generic type
 * @param vec vector of generic type
 * @param target the target index
 * @return an object of type T
 */
template<typename T>
T Pokedex :: search (vector<T> vec, int target)
{
    return vec[target];
}

/**
 * Finds Pokemon with a name that contains the given string
 *
 * @param name the name or part of the name of the pokemon
 */
void Pokedex :: findPokemonByName(string name)
{
    //make c string pointer of name
    char * cstr = const_cast<char *>(name.c_str());

    //change all the letters to lower case
    for(int i = 0; i < name.length(); i++)
    {
        *(cstr + i) = tolower(cstr[i]);
    }

    //print out all pokemon with names that contain the chars
    for(Pokemon pokemon : pokemonVector)
    {
        string pokemonName = pokemon.getName();

        //make a c string of the pokemonName
        char * firstLetter = const_cast<char *>(pokemonName.c_str());

        //switch the first letter to lower case
        *firstLetter = tolower(*firstLetter);

        //check if name is found in pokemonName
        if(pokemonName.find(name) != string :: npos)
        {
            cout << pokemon.showString() << endl;
        }
    }
}

/**
 * Finds Pokemon with a type that contains the given string
 *
 * @param type the type or part of the type of the pokemon
 */
void Pokedex :: findPokemonByType(string type)
{
    //make c string pointer of type
    char * cstr = const_cast<char *>(type.c_str());

    //change all the letters to lower case
    for(int i = 0; i < type.length(); i++)
    {
        *(cstr + i) = tolower(cstr[i]);
    }

    //print out all pokemon with names that contain the chars
    for(Pokemon pokemon : pokemonVector)
    {
        //get both types
        string pokemonPrimaryType = pokemon.getPrimaryType();
        string pokemonSecondaryType = pokemon.getSecondaryType();

        //create a char pointer
        char * firstLetter = const_cast<char *>(pokemonPrimaryType.c_str());

        //switch the first letter to lower case
        *firstLetter = tolower(*firstLetter);

        //set the char pointer to the other type
        firstLetter = const_cast<char *>(pokemonSecondaryType.c_str());

        //switch the first letter to lower case
        *firstLetter = tolower(*firstLetter);

        //check if the chars are found in both types
        if((pokemonPrimaryType.find(type) != string :: npos) || (pokemonSecondaryType.find(type) != string :: npos))
        {
            //if either are found then show the pokemon
            cout << pokemon.showString() << endl;
        }
    }
}

/**
 * Sort the pokemon by name alphabetically
 */
void Pokedex ::sortByAlphabet()
{
    //make an array from the vector
    Pokemon pokemonArray [pokemonVector.size()];
    for(int i = 0; i < pokemonVector.size(); i++)
    {
        *(pokemonArray + i) = pokemonVector.at(i);
    }

    //sort the array using recursive bubble sort
    recursiveBubbleSortName(pokemonArray, pokemonVector.size());

    //update the vector with the data from the array
    for(int i = 0; i < pokemonVector.size(); i++)
    {
        pokemonVector.at(i) = *(pokemonArray + i);
    }
}

/**
 * Sort the pokemon by number
 */
void Pokedex ::sortByNumber()
{
    //make an array from the vector
    Pokemon pokemonArray [pokemonVector.size()];
    for(int i = 0; i < pokemonVector.size(); i++)
    {
        *(pokemonArray + i) = pokemonVector.at(i);
    }

    //sort the array using recursive bubble sort
    recursiveBubbleSortNumber(pokemonArray, pokemonVector.size());

    //update the vector with the data from the array
    for(int i = 0; i < pokemonVector.size(); i++)
    {
        pokemonVector.at(i) = *(pokemonArray + i);
    }
}

/**
 * Template function that swaps items
 *
 * @tparam T generic type
 * @param first first object to swap
 * @param second second object to swap
 */
template<typename T>
void Pokedex :: swap(T * first, T * second)
{
    T temp = *first;
    *first = *second;
    *second = temp;
}

/**
 * Recursively uses bubble sort to sort a pokemon array by the name alphabetically
 *
 * @param arr the array to sort
 * @param n the number of items in the array
 */
void Pokedex :: recursiveBubbleSortName(Pokemon arr[], int n)
{
    //base case of an array of size 1
    if (n == 1)
    {
        return;
    }

    for (int i = 0; i < n-1; i++)
    {
        //swap if the first name is bigger than the second
        if (arr[i].getName().compare(arr[i+1].getName()) > 0)
        {
            swap(&arr[i], &arr[i+1]);
        }

    }

    //decrement n for the recursive case
    recursiveBubbleSortName(arr, n-1);
}

/**
 * Recursively uses bubble sort to sort a pokemon array by the number
 *
 * @param arr the array to sort
 * @param n the number of items in the array
 */
void Pokedex :: recursiveBubbleSortNumber(Pokemon arr[], int n)
{
    //base case of an array of size 1
    if (n == 1)
    {
        return;
    }

    for (int i = 0; i < n-1; i++)
    {
        //swap if the first number is bigger than the second number
        if (arr[i].getNumber() > arr[i+1].getNumber())
        {
            swap(&arr[i], &arr[i+1]);
        }

    }

    //decrement n for the recursive case
    recursiveBubbleSortNumber(arr, n-1);
}

/**
 * Reads pokemon information from text file, makes a Pokemon object and puts it into the vector pokemonVector
 */
void Pokedex :: readPokemonInfoFromText()
{
    int number;
    string name;
    string description;
    string primaryType;
    string secondaryType;
    string bio;

    ifstream inputInfo;

    string infoLine;

    string fileNameInfo = "PokemonInfo.txt";

    //open the file
    inputInfo.open(fileNameInfo.c_str());

    if(inputInfo.fail())
    {
        cout << "Error in opening PokemonInfo.txt" << endl;
        return;
    }

    //go through each line
    while (getline(inputInfo, infoLine))
    {
        vector <string> tokensOfString;

        stringstream ss(infoLine);

        string token;

        //tokenize the line
        while(getline(ss, token, '|'))
        {
            tokensOfString.push_back(token);
        }

        //extract the data into the local variables
        number = atoi(tokensOfString[0].c_str());
        name = tokensOfString[1];
        description = tokensOfString[2];
        primaryType = tokensOfString[3];
        secondaryType = tokensOfString[4];
        bio = tokensOfString[5];

        //create the pokemon
        Pokemon pokemon(number, name, description, primaryType, secondaryType, bio);

        //add it to the pokemon vector
        pokemonVector.push_back(pokemon);
    }

    //close the file
    inputInfo.close();


}

/**
 * Read the pokemon ascii images from the text file, create a PokemonImage object and push it to the pokemonImageVector
 */
void Pokedex :: readPokemonImagesFromText()
{
    ifstream inputImages;
    string image;

    string fileNameImages = "PokemonImages.txt";

    //open the file
    inputImages.open(fileNameImages.c_str());

    if(inputImages.fail())
    {
        cout << "Error in opening PokemonImages.txt" << endl;
        return;
    }

    //get each line where X is the delimiter
    while (getline(inputImages, image, 'X'))
    {
        //create a pokemon image object
        PokemonImage pokemonImage(image);

        //add image to vector
        pokemonImageVector.push_back(pokemonImage);

    }

    //close the file
    inputImages.close();

}

/**
 * Helper method that calls the readPokemonInfoFromText, readPokemonImagesFromText, combinePokemonAndImages methods
 */
void Pokedex :: initializePokemonVector()
{
    readPokemonInfoFromText();
    readPokemonImagesFromText();
    combinePokemonAndImages();
}

/**
 * Combines the pokemonVector with data from the pokemonImageVector
 */
void Pokedex :: combinePokemonAndImages()
{
    //for each pokemon in the pokemonVector
    for(int i = 0; i < pokemonVector.size(); i++)
    {
        //set the PokemonImage for each pokemon with the item in pokemonImageVector
        pokemonVector.at(i).setPokemonImage(pokemonImageVector.at(i));
    }

}

/**
 * Returns a copy of the pokemonVector
 */
vector<Pokemon> Pokedex :: getPokemonVector()
{
    return pokemonVector;
}
