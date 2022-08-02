// NocturnalPuzzle.cpp : Defines the entry point for the application.
//

#include "NocturnalPuzzle.h"

using namespace std;

void find_word(const char word[], const int size, char puzzle[][20], int coords[])
{
	bool match = false;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (word[0] == puzzle[i][j]) {
				// check if horizontal length is possible
				if ((20 - j) >= size) {
					// check for horizontal match
					for (int k = 1; k < size; k++) {
						if (word[k] != puzzle[i][j + k]) {
							// letter isn't a match, break and check vertically
							break;
						}
						else if (k == size - 1) {
							match = true;
							coords[0] = i;
							coords[1] = j;
							return;
						}
					}
				}
				// check if vertical length is possible
				if ((20 - i) >= size) {
					// check for vertical match
					for (int k = 1; k < size; k++) {
						if (word[k] != puzzle[i + k][j]) {
							// letter isn't a match, break and continue searching
							break;
						}
						else if (k == size - 1) {
							match = true;
							coords[0] = i;
							coords[1] = j;
							return;
						}
					}
				}
				
			}
		}
	}
	return;
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
	char puzzle1[20][20] = { {} };
	char puzzle2[20][20] = { {} };
	char word1[] = "nocturnal";
	char word2[] = "defibrillator";
	int coords1[2] = {21,21};
	int coords2[2] = {21,21};
	
	read_puzzles("C:\\Users\\graha\\source\\repos\\NocturnalPuzzle\\NocturnalPuzzle\\puzzle.txt", puzzle1, puzzle2);
	for (int rot1 = 0; rot1 < 26; rot1++) {
		find_word(word1, 9, puzzle1, coords1);
		if (coords1[0] == 21) {
			rotate_puzzle(puzzle1);
		}
		else {
			printf("x=%d, y=%d, count=%d\n", coords1[0], coords1[1], rot1);
			break;
		}
	}

	for (int rot2 = 0; rot2 < 26; rot2++) {
		find_word(word2, 13, puzzle2, coords2);
		if (coords2[0] == 21){
			rotate_puzzle(puzzle2);
		}
		else {
			printf("x=%d, y=%d, count=%d\n", coords2[0], coords2[1], rot2);
			break;
		}
	}



	// Print out arrays for testing
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << puzzle1[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			cout << puzzle2[i][j];
		}
		cout << endl;
	}
	return 0;
}
