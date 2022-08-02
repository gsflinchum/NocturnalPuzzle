// NocturnalPuzzle.cpp : Defines the entry point for the application.
//

#include "NocturnalPuzzle.h"

using namespace std;

bool find_word(const char word[], char puzzle[][20])
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (word[0] == puzzle[i][j]) {

			}
		}
	}
	return 0;
}

void rotate_puzzle(char puzzle[][20])
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (puzzle[i][j]++ == 'z') {
				puzzle[i][j] = 'a';
			}
		}
	}
}

void read_puzzles(const char* filename, char arr1[][20], char arr2[][20])
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Error in opening file %s\n", filename);
		return;
	}
	char c;
	int i = 0;
	int j = 0;
	do { c = fgetc(fp); } while (c != '[');
	while (c != EOF) {
		if ((97 <= c) && (c <= 122)) {
			arr1[i][j] = c;
			if (++j == 20) {
				j = 0;
				if (++i == 20) {
					break;
				}
			}
		}
		c = fgetc(fp);
	}
	i = 0;
	j = 0;
	do { c = fgetc(fp); } while (c != '[');
	while (c != EOF) {
		if ((97 <= c) && (c <= 122)) {
			arr2[i][j] = c;
			if (++j == 20) {
				j = 0;
				if (++i == 20) {
					break;
				}
			}
		}
		c = fgetc(fp);

	}
	fclose(fp);
	
}

int main()
{
	char puzzle1[20][20] = {{}};
	char puzzle2[20][20] = {{}};
	cout << "Hello CMake." << endl;
	
	read_puzzles("C:\\Users\\graha\\source\\repos\\NocturnalPuzzle\\NocturnalPuzzle\\puzzle.txt", puzzle1, puzzle2);
	rotate_puzzle(puzzle1);
	// Print out arrays for testing
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << puzzle1[i][j];
		}
		cout << endl;
	}
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << puzzle2[i][j];
		}
		cout << endl;
	}
	return 0;
}
