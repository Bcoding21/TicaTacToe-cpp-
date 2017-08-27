#ifndef board_h
#define board_h
#include <iostream>

class board {
public:
	board();
	bool is_Draw() const;
	void display() const;
	void reset();
	void makeMove(const char&, const char&);
	bool diagonal_win() const;
	const bool& horizontal_win() const;
	const bool& vertical_win() const;
	bool has_won() const;
	const bool& spot_taken(const char&) const;
	char game_board[3][3];
};

#endif
