#include "board.h"


board::board() {
	game_board[0][0] = '1';
	game_board[0][1] = '2';
	game_board[0][2] = '3';
	game_board[1][0] = '4';
	game_board[1][1] = '5';
	game_board[1][2] = '6';
	game_board[2][0] = '7';
	game_board[2][1] = '8';
	game_board[2][2] = '9';
}

void board::display() const {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << game_board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void board::reset() {
	game_board[0][0] = '1';
	game_board[0][1] = '2';
	game_board[0][2] = '3';
	game_board[1][0] = '4';
	game_board[1][1] = '5';
	game_board[1][2] = '6';
	game_board[2][0] = '7';
	game_board[2][1] = '8';
	game_board[2][2] = '9';
}

void board::makeMove(const char& location, const char& piece) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (location == game_board[i][j]) {
				game_board[i][j] = piece;
				break;
			}
		}
	}
}

bool board::diagonal_win() const {
	if (game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2]) {
		return true;
	}
	else if (game_board[2][0] == game_board[1][1] && game_board[1][1] == game_board[0][2]) {
		return true;
	}
	else {
		return false;
	}
}

const bool& board::horizontal_win() const {
	for (int i = 0; i < 3; i++) {
		if (game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2]) {
			return true;
		}
	}
	return false;
}

const bool& board::vertical_win() const {
	for (int i = 0; i < 3; i++) {
		if (game_board[0][i] == game_board[1][i] && game_board[1][i] == game_board[2][i]) {
			return true;
		}
	}
	return false;
}

bool board::has_won() const {
	return (diagonal_win() || vertical_win() || horizontal_win()) ? true : false;
}

const bool& board::spot_taken(const char& location) const {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game_board[i][j] == location) {
				return false;
			}
		}
	}
	return true;
}

bool board::is_Draw() const {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (game_board[i][j] != 'O' && game_board[i][j] != 'X') {
				return false;
			}
		}
	}
	return true;
}