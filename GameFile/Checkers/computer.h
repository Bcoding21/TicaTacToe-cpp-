#pragma once
class computer{

	struct coord {
		int x;
		int y;
	};

	char piece;
	char last_move;



public:
	 void move(char[][3]);
	 void setPiece(char);
	 bool losing(char[][3]);
	 bool diag_win(char[][3]);
	 bool vert_win(char[][3]);
	 bool hor_win(char[][3]);
	 bool corners_full(char[][3]);
	 void pick_corner(char[][3]);



	 coord diag_block(char[][3]);
	 coord vert_block(char[][3]);
	 coord hor_block(char[][3]);

	 char get_last();
};

