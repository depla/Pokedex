//
// Created by Dennis La on 2019-05-07.
//

#include "Pokemon.h"
#include "PokemonImage.h"
#include <iostream>

using namespace std;

/**
 * Default constructor for Pokemon, sets everything to a dummy value
 */
Pokemon :: Pokemon()
{
    this->number = -1;
    this->name = "N/A";
    this->description = "N/A";
    this->primaryType = "N/A";
    this->secondaryType = "N/A";
    this->bio = "N/A";
    pokemonImage.setAsciiImage("N/A");
}

/**
 * Constructor without the Pokemon Image
 *
 * @param number the number of the Pokemon
 * @param name the name of the Pokemon
 * @param description the description of the Pokemon
 * @param primaryType the primary type of the Pokemon
 * @param secondaryType the secondary type of the Pokemon
 * @param bio the bio of the Pokemon
 */
Pokemon :: Pokemon(int number, string name, string description, string primaryType,
                   string secondaryType, string bio)
{
    this->number = number;
    this->name = name;
    this->description = description;
    this->primaryType = primaryType;
    this->secondaryType = secondaryType;
    this->bio = bio;
    pokemonImage.setAsciiImage("N/A");
}

/**
 * Full constructor that takes in all data
 *
 * @param number the number of the Pokemon
 * @param name the name of the Pokemon
 * @param description the description of the Pokemon
 * @param primaryType the primary type of the Pokemon
 * @param secondaryType the secondary type of the Pokemon
 * @param bio the bio of the Pokemon
 * @param pokemonImage the ascii image of the Pokemon
 */
Pokemon :: Pokemon(int number, string name, string description, string primaryType,
        string secondaryType, string bio, PokemonImage pokemonImage)
{
    this->number = number;
    this->name = name;
    this->description = description;
    this->primaryType = primaryType;
    this->secondaryType = secondaryType;
    this->bio = bio;
    this->pokemonImage = pokemonImage;
}

/**
 * Sets the Pokemon number
 */
void Pokemon :: setNumber(int number)
{
    this->number = number;
}

/**
 * Sets the Pokemon name
 */
void Pokemon :: setName(string name)
{
    this->name = name;
}

/**
 * Sets the Pokemon description
 */
void Pokemon :: setDescription(string description)
{
    this->description = description;
}

/**
 * Sets the Pokemon primary type
 */
void Pokemon :: setPrimaryType(string primaryType)
{
    this->primaryType = primaryType;
}

/**
 * Sets the Pokemon secondary type
 */
void Pokemon :: setSecondaryType(string secondaryType)
{
    this->secondaryType = secondaryType;
}

/**
 * Sets the Pokemon bio
 */
void Pokemon :: setBio(string bio)
{
    this->bio = bio;
}

/**
 * Sets the Pokemon image
 */
void Pokemon ::setPokemonImage(PokemonImage pokemonImage)
{
    this->pokemonImage = pokemonImage;
}


/**
 * Gets the Pokemon number
 */
int Pokemon :: getNumber()
{
    return number;
}

/**
 * Gets the Pokemon name
 */
string Pokemon :: getName()
{
    return name;
}

/**
 * Gets the Pokemon description
 */
string Pokemon :: getDescription()
{
    return description;
}

/**
 * Gets the Pokemon primary type
 */
string Pokemon :: getPrimaryType()
{
    return primaryType;
}

/**
 * Gets the Pokemon secondary type
 */
string Pokemon :: getSecondaryType()
{
    return secondaryType;
}

/**
 * Gets the Pokemon bio
 */
string Pokemon :: getBio()
{
    return bio;
}

/**
 * Gets the Pokemon image
 */
PokemonImage Pokemon :: getPokemonImage()
{
    return pokemonImage;
}

/**
 * String of the Pokemon's data
 */
string Pokemon :: showString()
{
    string pokeString;

    pokeString += "Number: " + to_string(number) + '\n';
    pokeString += "Name: " + name + '\n';
    pokeString += "Description: " + description + '\n';
    pokeString += "Primary Type: " + primaryType + '\n';
    pokeString += "Secondary Type: " + secondaryType + '\n';
    pokeString += "Bio: " + bio + '\n';
    pokeString += this->getPokemonImage().getAsciiImage();

    return pokeString;

}
