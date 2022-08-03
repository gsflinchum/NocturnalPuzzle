// NocturnalPuzzle.h : Include file for standard system include files,
// or project specific include files

#pragma once

#include <stdio.h>
#include <stdbool.h>

// finds a word with given size in a 20x20 array and writes the starting coordinate to coords
void find_word(const char word[], const int size, char puzzle[][20], int coords[]);

// changes every letter in a 20x20 array to the next letter in the alphabet
void rotate_puzzle(char puzzle[][20]);

// reads in 2 20x20 arrays from a text file and places them in the given arrays
void read_puzzles(const char* filename, char arr1[][20], char arr2[][20]);

