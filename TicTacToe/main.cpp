#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void runGame();
void printBoard(string arr[3][3]);

void checkWinner(string arr[3][3]);
bool isBoardFull(string arr[3][3]);
bool isGameOn = true;

int main() {

	runGame();

	return 0;
}

void runGame() {
	string userStart;

	string board[3][3] = {
		{ "-","-","-" },
		{ "-","-","-" },
		{ "-","-","-" }
	};

	cout << "Welcome to Tic-Tac-Toe! \nby Talal Shreidi" << endl;

	cout << "Type 'start' to start the game: ";
	cin >> userStart;



	if (userStart == "start") {
		bool playerTurnX = true;
		int userRow;
		int userCol;
		cout << "Great! Let's start with X's turn." << endl;
		cout << "Please enter the row THEN the column, each from 0, 1, or 2, seperated by spaces." << endl;
		printBoard(board);
		cin >> userRow >> userCol;
		board[userRow][userCol] = "X";
		playerTurnX = false;
		while (isGameOn) {
			if (playerTurnX) {
				cout << "It's X's turn!" << endl;
				cout << "Please enter the row THEN the column, each from 0, 1, or 2, seperated by spaces." << endl;
				printBoard(board);
				cin >> userRow >> userCol;
				if (board[userRow][userCol] == "X" || board[userRow][userCol] == "O") {
					cout << "The slot is already taken, please enter a different one: ";
				}
				else {
					board[userRow][userCol] = "X";
					playerTurnX = false;
				}
				if (isBoardFull(board)) {
					isGameOn = false;
					cout << "You tied!" << endl;
				}
				checkWinner(board);
			}
			else {
				cout << "It's O's turn!" << endl;
				cout << "Please enter the row THEN the column, each from 0, 1, or 2, seperated by spaces." << endl;
				printBoard(board);
				cin >> userRow >> userCol;
				if (board[userRow][userCol] == "X" || board[userRow][userCol] == "O") {
					cout << "The slot is already taken, please enter a different one: ";
				}
				else {
					board[userRow][userCol] = "O";
					playerTurnX = true;
				}
				if (isBoardFull(board)) {
					isGameOn = false;
					cout << "You tied!" << endl;
				}
				checkWinner(board);

			}
		}





	}
	else {
		cout << "Invalid Option! Please enter 'start' to start the game." << endl;
	}
}


void printBoard(string arr[3][3]) {
	for (int row = 0; row <= 2; row++) {
		for (int col = 0; col <= 2; col++) {
				cout << arr[row][col];
				if (col < 2) {
					cout << " | ";
				}
		}
		cout << "\n";
		if (row < 2) {
			cout << "- - - - -";
		}
		
		cout << endl;
		
	}
}

void checkWinner(string arr[3][3]) {

	for (int i = 0; i < 2; i++) {
		// Rows
		if (arr[i][0] != "-" && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) {
			isGameOn = false;
			cout << "The winner is: " << arr[i][0] << endl;
			return;
		}
		// Columns
		if (arr[0][i] != "-" && arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) {
			isGameOn = false;
			cout << "The winner is: " << arr[0][i] << endl;
			return;
		}

	}
	// Diagnal
	if (arr[0][0] != "-" && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) {
		isGameOn = false;
		cout << "The winner is: " << arr[0][0] << endl;
		return;
	}
	if (arr[0][2] != "-" && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) {
		isGameOn = false;
		cout << "The winner is: " << arr[0][2] << endl;
		return;
	}

}

bool isBoardFull(string arr[3][3]) {
	for (int i = 0; i <= 2; i++) {
		if (arr[i][0] == "-" && arr[i][1] == "-" && arr[i][2] == "-") {
			
			return false;
		}
	}
	return true;
}