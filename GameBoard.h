#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int** createGrid(int rows, int cols) {
	int** grid = new int* [rows];
	for (int i = 0; i < rows; i++) {
		grid[i] = new int[cols] {0}; // initialize all elements to 0
	}
	return grid;
}
void displayGrid(int** grid, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] == 1) {
				cout << "T "; // T represents the teleport
			}
			else if (grid[i][j] == 2) { // 2 for player
				cout << "P "; // . represents empty space
			}
			else {
				cout << ". "; // . represents empty space
			}
		}
		cout << endl;
	}
}
void movePlayer(int** grid, int& playerRow, int& playerCol, char direction, int rows,
	int cols) {
	grid[playerRow][playerCol] = 0; // clear old position
	if ((direction == 'w' || direction == 'W') && playerRow > 0)
		playerRow--;
	else if ((direction == 's' || direction == 'S') && playerRow < rows - 1)
		playerRow++;
	else if ((direction == 'a' || direction == 'A') && playerCol > 0)
		playerCol--;
	else if ((direction == 'd' || direction == 'D') && playerCol < cols - 1)
		playerCol++;
	grid[playerRow][playerCol] = 2; // mark new position
}
void placeTeleport(int** grid, int rows, int cols, int& teleRow, int& teleCol) {
	teleRow = rand() % (rows - 1) + 1;  
	teleCol = rand() % (cols - 1) + 1;  
	grid[teleRow][teleCol] = 1; // mark teleport position with 1
}
void updateGrid(int** grid, int rows, int cols, int playerRow, int playerCol, int
	teleRow, int teleCol) {
	grid[playerRow][playerCol] = 2; // mark player position with 2
	grid[teleRow][teleCol] = 1; // mark teleport position with 1
}
void resetGrid(int**& grid, int rows) {
	for (int i = 0; i < rows; i++) {
		delete[] grid[i];
	}
	delete[] grid;
	grid = nullptr;
}
void teleportPlayer(int& playerRow, int& playerCol, int rows, int cols, int teleportRow, int teleportCol) {
	do {
		playerRow = rand() % rows;
		playerCol = rand() % cols;
	} while (playerRow == teleportRow && playerCol == teleportCol);

}