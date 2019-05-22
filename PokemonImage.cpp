//
// Created by Dennis La on 2019-05-08.
//

#include "PokemonImage.h"
#include <iostream>

using namespace std;

PokemonImage ::PokemonImage()
{
    this->asciiImage = "N/A";
}

PokemonImage ::PokemonImage(string asciiImage)
{
    this->asciiImage = asciiImage;
}

void PokemonImage :: setAsciiImage(string asciiImage)
{
    this->asciiImage = asciiImage;
}

string PokemonImage ::getAsciiImage()
{
    return asciiImage;
}