//
// Created by Dennis La on 2019-05-07.
//

#ifndef POKEDEX_POKEDEX_H
#define POKEDEX_POKEDEX_H

#include <string>
#include <vector>
#include <fstream>
#include "Pokemon.h"
#include "PokemonImage.h"


using namespace std;

class Pokedex
{
private:

    vector<Pokemon> pokemonVector;
    vector<PokemonImage> pokemonImageVector;

    void readPokemonInfoFromText();
    void readPokemonImagesFromText();

    void combinePokemonAndImages();
    void initializePokemonVector();

    template<typename T>
    T search (vector<T> vec, int target);

    template<typename T>
    void swap(T * first, T * second);

    void recursiveBubbleSortName(Pokemon arr[], int n);
    void recursiveBubbleSortNumber(Pokemon arr[], int n);

public:

    Pokedex();

    void showAllPokemon();

    Pokemon findPokemonByNumber(int number);

    void findPokemonByName(string name);

    void findPokemonByType(string type);

    void sortByAlphabet();

    void sortByNumber();

    vector<Pokemon> getPokemonVector();

};


#endif //POKEDEX_POKEDEX_H
