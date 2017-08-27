#include "board.h"
#include "computer.h"
#include <Windows.h>

int main() {

	board game_board;
	computer skynet;
	char p2_piece = 'O';
	char p1_piece = 'X';
	char player_move;
	char play_again = 'y';
	char oppo;
	skynet.setPiece(p2_piece);



	std::cout << "Welcome to TIC-TAC-TOE" << std::endl;

	while (play_again == 'y') {

		std::cout << "Do you want to play against another player or the computer(p -- player, c -- computer): ";
		std::cin >> oppo;

		while (true) {

			if (oppo == 'p') {
				game_board.display();

				std::cout << std::endl;
				std::cout << "Player 1 enter postiion: ";
				std::cin >> player_move;
				game_board.makeMove(player_move, p1_piece);
				if (game_board.has_won()) {
					game_board.display();
					std::cout << "Congradulations! Player 1 has won the game!!" << std::endl;
					break;
				}
				else if (game_board.is_Draw()) {
					game_board.display();
					std::cout << "Game is a CAT!" << std::endl;
					break;
				}

				std::cout << std::endl << std::endl;

				game_board.display();

				std::cout << std::endl;
				std::cout << "Player 2 enter postiion: ";
				std::cin >> player_move;
				game_board.makeMove(player_move, p2_piece);
				if (game_board.has_won()) {
					game_board.display();
					std::cout << "Congradulations! Player 2 has won the game!!" << std::endl;
					break;
				}
				else if (game_board.is_Draw()) {
					game_board.display();
					std::cout << "Game is a CAT!" << std::endl;
					break;
				}
			}
			else if (oppo == 'c') {

				game_board.display();
				std::cout << "Player 1, enter position: ";
				std::cin >> player_move;
				
				game_board.makeMove(player_move, p1_piece);

				if (game_board.has_won()) {
					game_board.display();
					std::cout << "Congradulations! Player 1 has won the game!!" << std::endl;
					break;
				}
				else if (game_board.is_Draw()) {
					game_board.display();
					std::cout << "game is a CAT!" << std::endl;
					break;
				}

			
				skynet.move(game_board.game_board);
				game_board.display();
				std::cout << "The computer has move to position " << skynet.get_last() << std::endl;
				if (game_board.has_won()) {
					game_board.display();
					std::cout << "The computer has beaten you!" << std::endl;
					break;
				}
				else if (game_board.is_Draw()) {
					game_board.display();
					std::cout << "game is a CAT" << std::endl;
					break;
				}
			}
			std::cout << std::endl;
		}

		std::cout << "Do you want to play again?(y/n): ";
		std::cin >> play_again;

		if (play_again != 'y' && play_again != 'n') {
			do {
				std::cout << "Do you want to play again? Enter \"y\" or \"n\": " << std::endl;
				std::cin >> play_again;
			} while (play_again != 'y' && play_again != 'n');
		}

		if (play_again == 'n') {
			std::cout << "Have a nice day!" << std::endl;
			break;
		}

		game_board.reset();
	}
	


	std::cin.ignore();
	std::cin.get();

}