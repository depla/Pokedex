//
// Created by Dennis La on 2019-05-08.
//

#include "PokemonImage.h"
#include <iostream>

using namespace std;

/**
 * Default constructor for PokemonImage, sets image to dummy value
 */
PokemonImage ::PokemonImage()
{
    this->asciiImage = "N/A";
}

/**
 * Creates an image from a string of ascii chars
 */
PokemonImage ::PokemonImage(string asciiImage)
{
    this->asciiImage = asciiImage;
}

/**
 * Sets the Pokemon ascii image
 */
void PokemonImage :: setAsciiImage(string asciiImage)
{
    this->asciiImage = asciiImage;
}

/**
 * Gets the Pokemon ascii image
 */
string PokemonImage ::getAsciiImage()
{
    return asciiImage;
}