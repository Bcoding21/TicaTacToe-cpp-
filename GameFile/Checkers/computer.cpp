#include "computer.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

void computer::setPiece(char piece) {
	this->piece = piece;
}

void computer::move(char board[][3]) {
	if (losing(board)) {
		coord next_move;
		if (diag_win(board)) {
			std::cout << "DECTECTING DIAGNOL WIN" << std::endl;
			next_move = diag_block(board);
			last_move = board[next_move.x][next_move.y];
			board[next_move.x][next_move.y] = piece;
			
			
		}
		else if (vert_win(board)) {
			std::cout << "DETECTING VERTICAL WIN" << std::endl;
			next_move = vert_block(board);
			last_move = board[next_move.x][next_move.y];
			board[next_move.x][next_move.y] = piece;
		}
		else {
			std::cout << "DETECTING HORIZONTAL WIN" << std::endl;
			next_move = hor_block(board);
			last_move = board[next_move.x][next_move.y];
			board[next_move.x][next_move.y] = piece;
		}
	}

	else if (!corners_full(board)) {
		pick_corner(board);
	}

}

bool computer::diag_win(char board[][3]) {
	int count = 0;
	if (piece == 'X') {
		for (int i = 0; i < 3; i++) {
			if (board[i][i] == 'O') {
				count++;
			}
		}
		if (count > 1) {
			return true;
		}
		
		count = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 2; j > -1; j--) {
				if (board[i][j] == 'O') {
					count++;
				}
			}
		}
		return (count > 1) ? true : false;
	}
	
	else {
		for (int i = 0; i < 3; i++) {
			if (board[i][i] == 'X') {
				count++;
			}
			else if (board[i][i] == 'O') {
				count--;
			}
		}
		
		if (count > 1) {
			return true;
		}

		count = 0;
		int j = 2;

		for (int i = 0; i < 3; i++) {
				if (board[j][i] == 'X') {
					count++;
				}
				else if (board[j][i] == 'O') {
					count--;
				}
				j--;
			}
		return (count > 1) ? true : false;
	}
}

computer::coord computer::diag_block(char board[][3]) {
	coord points;

	for (int i = 0; i < 3; i++) {
		if (board[i][i] != 'O' && board[i][i] != 'X') {
			points.x = i;
			points.y = i;
			last_move = board[points.x][points.y];
			return points;
		}
	}


	for (int i = 0; i < 3; i++) {
		for (int j = 2; j > -1; j++) {
			if (board[i][j] != 'O' && board[i][j] != 'X') {
				points.x = i;
				points.y = j;
				last_move = board[i][i];
				return points;
			}
		}
	}
}

bool computer::vert_win(char board[][3]) {
	int count = 0;
	if (piece == 'X') {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[j][i] == 'O') {
					count++;
				}
				if (count > 1) {
					return true;
				}
			}
			count = 0;
		}
	}

	else {
		count = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[j][i] == 'X') {
					count++;
				}
				else if (board[j][i] == 'O') {
					count--;
				}
				if (count > 1) {
					return true;
				}
			}
			count = 0;
		}
	}

	return false;
}

computer::coord computer::vert_block(char board[][3]) {
	coord points;
	int count = 0;

	if (piece == 'X') {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[j][i] == 'O') {
					count++;
				}
			}
			if (count > 1) {
				points.y = i;
				break;
			}
			count = 0;
		}

		for (int i = 0; i < 3; i++) {
			if (board[i][points.y] != 'O') {
				points.x = i;
				last_move = board[points.x][points.y];
				return points;
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[j][i] == 'X') {
					count++;
				}
			}
			if (count > 1) {
				points.y = i;
				break;
			}
			count = 0;
		}

		for (int i = 0; i < 3; i++) {
			if (board[i][points.y] != 'X') {
				points.x = i;
				return points;
			}
		}
	}
}

bool computer::hor_win(char board[][3]) {
	int count = 0;
	if (piece == 'X') {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == 'O') {
					count++;
				}
			}
			if (count > 1) {
				return true;
			}
			count = 0;
		}
		return false;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == 'X') {
					count++;
				}
				else if (board[i][j] == 'O') {
					count--;
				}
			}
			if (count > 1) {
				return true;
			}
			count = 0;
		}
	}
	return false;
}

computer::coord computer::hor_block(char board[][3]) {
	coord points;
	int count = 0;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {  // finds the row to block
			if (board[i][j] == 'X') {
				count++;
				if (count > 1) {
					points.x = i;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		if (board[points.x][i] != 'O' && board[points.x][i] != 'X') {   // finds the spot in that row to block
			points.y = i;
			break;
		}
	}

	return points;
	
}

bool computer::corners_full(char board[][3]) {
	if ((board[0][0] != 'O' && board[0][0] != 'Y') ||
		(board[0][2] != 'O' && board[0][2] != 'Y') ||
		(board[2][0] != 'O' && board[2][0] != 'Y') ||
		(board[2][2] != 'O' && board[2][2] != 'Y'))
	{
		return false;
	}
	else { return true; }
}

void computer::pick_corner(char board[][3]) {
	srand(time(0));
	char corners[4] = { '1', '3', '7', '9' };
	bool not_done = true;

	while (not_done) {

		int decision = rand() % 4;
		char move = corners[decision];

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (board[i][j] == move) {
					board[i][j] = piece;
					not_done = false;
					last_move = move;
				}
			}
		}
	}
}

bool computer::losing(char board[][3]) {
	return (diag_win(board) || vert_win(board) || hor_win(board)) ? true : false;
}

char computer::get_last() {
	return last_move;
}

