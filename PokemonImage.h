//
// Created by Dennis La on 2019-05-08.
//

#ifndef POKEDEX_POKEMONIMAGE_H
#define POKEDEX_POKEMONIMAGE_H

#include <string>

using namespace std;

class PokemonImage
{
private:
    string asciiImage;

public:
    PokemonImage();

    PokemonImage(string asciiImage);

    void setAsciiImage(string asciiImage);

    string getAsciiImage();

};


#endif //POKEDEX_POKEMONIMAGE_H
