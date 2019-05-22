//
// Created by Dennis La on 2019-05-07.
//

#ifndef POKEDEX_POKEMON_H
#define POKEDEX_POKEMON_H

#include <string>
#include "PokemonImage.h"

using namespace std;

class Pokemon
{

private:
    int number;

    string name;

    string description;

    string primaryType;

    string secondaryType;

    string bio;

    PokemonImage pokemonImage;

public:
    Pokemon();

    Pokemon(int number, string name, string description, string primaryType,
            string secondaryType, string bio);

    Pokemon(int number, string name, string description, string primaryType,
            string secondaryType, string bio, PokemonImage pokemonImage);

    void setNumber(int number);

    void setName(string name);

    void setDescription(string description);

    void setPrimaryType(string primaryType);

    void setSecondaryType(string secondaryType);

    void setBio(string bio);

    void setPokemonImage(PokemonImage pokemonImage);


    int getNumber();

    string getName();

    string getDescription();

    string getPrimaryType();

    string getSecondaryType();

    string getBio();


    PokemonImage getPokemonImage();


    string showString();

};


#endif //POKEDEX_POKEMON_H
