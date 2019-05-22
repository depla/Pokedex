//
// Created by Dennis La on 2019-05-07.
//

#include "Pokedex.h"
#include "PokemonImage.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Pokedex :: Pokedex()
{
    initializePokemonVector();
}

void Pokedex :: showAllPokemon()
{
    for(Pokemon pokemon : pokemonVector)
    {
        cout << pokemon.showString() << endl;
    }
}

Pokemon Pokedex :: findPokemonByNumber(int number)
{
    number--;

    return search(pokemonVector, number);
}

template<typename T>
T Pokedex :: search (vector<T> vec, int target)
{
    return vec[target];
}

void Pokedex :: findPokemonByName(string name)
{
    char * cstr = const_cast<char *>(name.c_str());

    for(int i = 0; i < name.length(); i++)
    {
        *(cstr + i) = tolower(cstr[i]);
    }

    for(Pokemon pokemon : pokemonVector)
    {
        string pokemonName = pokemon.getName();
        char * firstLetter = const_cast<char *>(pokemonName.c_str());

        //switch the first letter to lower case
        *firstLetter = tolower(*firstLetter);

        if(pokemonName.find(name) != string :: npos)
        {
            cout << pokemon.showString() << endl;
        }
    }
}

void Pokedex :: findPokemonByType(string type)
{
    char * cstr = const_cast<char *>(type.c_str());

    for(int i = 0; i < type.length(); i++)
    {
        *(cstr + i) = tolower(cstr[i]);
    }

    for(Pokemon pokemon : pokemonVector)
    {
        string pokemonPrimaryType = pokemon.getPrimaryType();
        string pokemonSecondaryType = pokemon.getSecondaryType();

        char * firstLetter = const_cast<char *>(pokemonPrimaryType.c_str());

        //switch the first letter to lower case
        *firstLetter = tolower(*firstLetter);

        firstLetter = const_cast<char *>(pokemonSecondaryType.c_str());

        //switch the first letter to lower case
        *firstLetter = tolower(*firstLetter);


        if((pokemonPrimaryType.find(type) != string :: npos) || (pokemonSecondaryType.find(type) != string :: npos))
        {
            cout << pokemon.showString() << endl;
        }
    }
}


//**************************************************************************************************************
void Pokedex ::sortByAlphabet()
{
    Pokemon pokemonArray [pokemonVector.size()];
    for(int i = 0; i < pokemonVector.size(); i++)
    {
        *(pokemonArray + i) = pokemonVector.at(i);
    }

    recursiveBubbleSortName(pokemonArray, pokemonVector.size());

    for(int i = 0; i < pokemonVector.size(); i++)
    {
        pokemonVector.at(i) = *(pokemonArray + i);
    }
}

void Pokedex ::sortByNumber()
{
    Pokemon pokemonArray [pokemonVector.size()];
    for(int i = 0; i < pokemonVector.size(); i++)
    {
        *(pokemonArray + i) = pokemonVector.at(i);
    }

    recursiveBubbleSortNumber(pokemonArray, pokemonVector.size());

    for(int i = 0; i < pokemonVector.size(); i++)
    {
        pokemonVector.at(i) = *(pokemonArray + i);
    }
}

template<typename T>
void Pokedex :: swap(T * first, T * second)
{
    T temp = *first;
    *first = *second;
    *second = temp;
}

void Pokedex :: recursiveBubbleSortName(Pokemon arr[], int n)
{
    if (n == 1)
    {
        return;
    }

    for (int i = 0; i < n-1; i++)
    {
        if (arr[i].getName().compare(arr[i+1].getName()) > 0)
        {
            swap(&arr[i], &arr[i+1]);
        }

    }

    recursiveBubbleSortName(arr, n-1);
}

void Pokedex :: recursiveBubbleSortNumber(Pokemon arr[], int n)
{
    if (n == 1)
    {
        return;
    }

    for (int i = 0; i < n-1; i++)
    {
        if (arr[i].getNumber() > arr[i+1].getNumber())
        {
            swap(&arr[i], &arr[i+1]);
        }

    }

    recursiveBubbleSortNumber(arr, n-1);
}


//**************************************************************************************************************

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

    while (getline(inputInfo, infoLine))
    {
        //cout << infoLine << endl;

        vector <string> tokensOfString;

        stringstream ss(infoLine);

        string token;

        while(getline(ss, token, '|'))
        {
            tokensOfString.push_back(token);
        }

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

    inputInfo.close();


}

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

    while (getline(inputImages, image, 'X'))
    {
        //create a pokemon image object
        PokemonImage pokemonImage(image);

        //add image to vector
        pokemonImageVector.push_back(pokemonImage);

    }

    inputImages.close();

}

void Pokedex :: initializePokemonVector()
{
    readPokemonInfoFromText();
    readPokemonImagesFromText();
    combinePokemonAndImages();
}

void Pokedex :: combinePokemonAndImages()
{

    for(int i = 0; i < pokemonVector.size(); i++)
    {
        pokemonVector.at(i).setPokemonImage(pokemonImageVector.at(i));
    }

}


vector<Pokemon> Pokedex :: getPokemonVector()
{
    return pokemonVector;
}
