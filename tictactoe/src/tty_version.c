#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

void handle_sigint();

char** board_generation();
char** board_write(char** board, int turn);

bool end_rule(char** board);
void free_memory(char** board);

int main()
{
	// Print rules
	printf("1|2|3\n4|5|6\n7|8|9\n\n");

	// Main loop
	signal(SIGINT, handle_sigint);
	char** board = board_generation();
	for (int turn = 0; end_rule(board) != true; ++turn) {
		board = board_write(board, turn);
		for (int i = 0; board[i] != NULL; ++i)
			printf("%s\n", board[i]);
	}
	printf("Game ended\n");

	// Free memory
	free_memory(board);

	return 0;
}

void handle_sigint()
{
	return;
}

char** board_generation()
{
	// Generate empty board
	char** board = malloc(sizeof(char*) * 6);
	for (int i = 0; i < 5; ++i) {
		board[i] = malloc(sizeof(char) * 6);
		if (i % 2 == 0) strcpy(board[i], " | | ");
		else board[i] = strcpy(board[i], "-----");
	}
	board[5] = NULL;
	return board;
}

char** board_write(char** board, int turn)
{
	// Get user input
	char* args = "DF";
	size_t var = 0;
	int y = 0, x = 0;
	while (args[0] < '0' || args[0] > '9') {
		if (turn % 2 == 0)
			printf("Player 1: ");
		else
			printf("Player 2: ");
		if (getline(&args, &var, stdin) == -1) {
			free(args);
			free_memory(board);
			exit(84);
		}
	}

	// Convert input in coordonates
	char player;
	if (turn % 2 == 0)
		player = 'X';
	else
		player = 'O';

	switch (args[0]) {
		case '1':y = 0; x = 0;
			break;
		case '2':y = 0; x = 2;
			break;
		case '3':y = 0; x = 4;
			break;
		case '4':y = 2; x = 0;
			break;
		case '5':y = 2; x = 2;
			break;
		case '6':y = 2; x = 4;
			break;
		case '7':y = 4; x = 0;
			break;
		case '8':y = 4; x = 2;
			break;
		case '9':y = 4; x = 4;
			break;
		default:board = board_write(board, turn);
			break;
	}

	// Check if position is available
	if (board[y][x] != ' ')
		board = board_write(board, turn);
	else
		board[y][x] = player;
	free(args);
	return board;
}

bool end_rule(char** board)
{
	// Diagonal
	if ((board[0][0] == 'X' && board[2][2] == 'X' && board[4][4] == 'X') || (board[0][4] == 'X' && board[2][2] == 'X' && board[4][0] == 'X')) {
		printf("Player 1 wins!\n");
		return true;
	}
	if ((board[0][0] == 'O' && board[2][2] == 'O' && board[4][4] == 'O') || (board[0][4] == 'O' && board[2][2] == 'O' && board[4][0] == 'O')) {
		printf("Player 2 wins!\n");
		return true;
	}


	// Horizontal
	for (int i = 0; board[i] != NULL; ++i) {
		if (strcmp(board[i], "X|X|X") == 0) {
			printf("Player 1 wins!\n");
			return true;
		}
		if (strcmp(board[i], "O|O|O") == 0) {
			printf("Player 2 wins!\n");
			return true;
		}
	}

	// Vertical
	if ((board[0][0] == 'X' && board[2][0] == 'X' && board[4][0] == 'X') || (board[0][2] == 'X' && board[2][2] == 'X' && board[4][2] == 'X') || (board[0][4] == 'X' && board[2][4] == 'X' && board[4][4] == 'X')) {
		printf("Player 1 wins!\n");
		return true;
	}
	if ((board[0][0] == 'O' && board[2][0] == 'O' && board[4][0] == 'O') || (board[0][2] == 'O' && board[2][2] == 'O' && board[4][2] == 'O') || (board[0][4] == 'O' && board[2][4] == 'O' && board[4][4] == 'O')) {
		printf("Player 2 wins!\n");
		return true;
	}

	// Draw
	for (int i = 0; board[i] != NULL; ++i) {
		for (int j = 0; board[i][j]; ++j) {
			if (board[i][j] == ' ')
				return false;
		}
	}
	printf("Draw.\n");
	return true;
}

void free_memory(char** board)
{
	for (int i = 0; board[i] != NULL; ++i)
		free(board[i]);
	free(board);
}
