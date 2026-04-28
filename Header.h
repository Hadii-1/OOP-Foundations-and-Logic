#pragma once
#include<iostream>
using namespace std;
// Function Prototypes For Question 5
void printRow(int n, int current);
void printSpaces(int n, int current);
void printHollowDiamond(int n, int original=0,int row = 1);
void printInverted(int n, int row = 0);
// Function Prototypes For Question 4
string AcompleteWord(const char* str, int start, int end);
int endOfCurrentWord(const char* str, int index);
int firstValidChar(const char* str, int index);
void printWordsReverse(const char* str, int length);
// Function Prototypes For Question 2
void inputJaggedArray(int** arr, int* colNum, int row);
void DisplayJaggedArray(int** arr, int* colNum, int row);
int** createJaggedArray(int rows, int* ColSizes);
void calculateRowSums(int** arr, int row, int* ColSizes);
void DeleteJaggedArray(int**& arr, int row);



// ============================ Q5 =========================================
void printRow(int n, int current) {
    if (current > n) return;
    cout << "*";
    printRow(n, current + 1);
}

void printSpaces(int n, int current) {
    if (current >= n) return;
    cout << " ";
    printSpaces(n, current + 1);
}

void printHollowDiamond(int n, int original, int row) {
    if (original == 0)
        original = n;
    if (row > n) {
        printInverted(original);  // bottom half
        return;
    }
    printRow(n - row, 0);
    printSpaces(2 * row - 2, 0); // we did 2*row - 2 becuz if for -1 we do not skip the first line of pyramid
    printRow(n, row);
    cout << endl;
    printHollowDiamond(n, original, row + 1);
}

void printInverted(int n, int row) {
    if (row >= n) return;
    printRow(row, 0);
    printSpaces(2 * (n - row) - 2, 0); // spaces in pyramid form but inveretd 
    printRow(row, 0);
    cout << endl;
    
    printInverted(n, row + 1);
}
//=============================================== Q4 ===============================================================
string AcompleteWord(const char* str, int start, int end) {
	if (start > end)
		return ""; // base case: no characters left
	return *(str + start) + AcompleteWord(str, start + 1, end);
}

int endOfCurrentWord(const char* str, int index) { // do it recursively
	if (index < 0 || *(str + index) == ' ') { // if index goes less than 0 meaning no character is left or when we get a space meaning the word is over
		return index;

	}
	 return endOfCurrentWord(str, index - 1); // we will move in the left direction 
}

int firstValidChar(const char* str, int index) {
	if (index < 0) // if index goes less than 0 meaning no character is left
		return -1;
	if (*(str + index) != ' ' && *(str + index) != '\0') // if we get a character that is not space and not null character
		return index;
	return firstValidChar(str, index - 1); // moving left
}

void printWordsReverse(const char* str, int length = -2) { // using recursion no loops
	if (length == -2) // to handle the default argument case
		length = strlen(str);
	int start = firstValidChar(str, length - 1);
	if (start < 0) // it means that letters index is going negative below 0 beyond the array
		return;
	int end = 0;
	if (*str == '\0')
		return;
	end = endOfCurrentWord(str, start); // now that we have the indexes of the word we can make it and store it 
	string CompleteWord = AcompleteWord(str, end + 1, start); // passing end+1 to start bcz by +1 we move right to avoid the space and start of the letter of word
	cout << CompleteWord; // printing the word
	if (end > 0) {
		cout << " ";
		printWordsReverse(str, end + 1); // calling with end +1 to avoid the space index that is being returned so we move one step to right to satrt of the word's letter

	}
	cout << endl;
}
//=====================================================================================================================

//=============================== Q2 ==============================================================
void inputJaggedArray(int** arr, int* colNum, int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colNum[i]; j++) {
			cout << "Enter the Element on index [" << i << "][" << j << "] : ";
			cin >> arr[i][j];

		}
	}
}
void DisplayJaggedArray(int** arr, int* colNum, int row) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colNum[i]; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
int** createJaggedArray(int rows, int* ColSizes) {
	int colNum;
	int** Array = new int* [rows];
	for (int i = 0; i < rows; i++) {
		cout << "Enter the number of Cols on row " << i << " : ";
		cin >> colNum;
		*(Array + i) = new int[colNum];
		*(ColSizes + i) = colNum; // storing the number of cols in each row in another array
	}
	return Array;

}
void calculateRowSums(int** arr, int row, int* ColSizes) {
	int sum = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < ColSizes[i]; j++) {
			sum += arr[i][j];

		}
		cout << "Sum of row " << i << " : " << sum;
		sum = 0;
		cout << endl;

	}
}
void DeleteJaggedArray(int**& arr, int row) {
	for (int i = 0; i < row; i++) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;

}