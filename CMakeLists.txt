cmake_minimum_required(VERSION 3.13)
project(Pokedex)

set(CMAKE_CXX_STANDARD 11)

add_executable(Pokedex main.cpp Pokemon.cpp Pokemon.h Pokedex.cpp Pokedex.h PokemonImage.cpp PokemonImage.h)