#include "graphics/mht_graphics.h"

bool end_rule(char** board);
void free_memory(char** board);

int main()
{
	// Print rules
	printf("1|2|3\n4|5|6\n7|8|9\n\n");

	// Generate empty board
	char** board = malloc(sizeof(char*) * 4);
	for (int i = 0; i < 3; ++i) {
		board[i] = malloc(sizeof(char) * 4);
		memset(board[i], ' ', 3);
		board[i][3] = '\0';
	}
	board[3] = NULL;

	// Load structures
	entity_t *entities = malloc(sizeof(entity_t) * 24);
	settings_t *settings = malloc(sizeof(settings_t));
	settings->selected = 0;
	settings->turn = 0;

	// Window generation
	sfVideoMode MOD = {300, 300, 64};
	settings->WIN = sfRenderWindow_create(MOD, "Tic Tac Toe", sfResize | sfClose, NULL);
        printf("%s\n", "status: init_window ok -> initializing sprites...");

	// Load entities
        load_entities(entities);
        printf("%s\n", "status: init_sprite ok -> setting up changes...");

	// Set entities
        set_entities(entities);
        printf("%s\n", "status: set_changes ok -> starting event_loop...");

	// Main loop
	start_game(settings, entities, board);
//	for (int turn = 0; end_rule(board) != true; ++turn)
//		board = board_write(board, turn);
	printf("Game ended\n");

	// Free memory
	free_memory(board);
	free(entities);
	free(settings);

	return 0;
}

bool end_rule(char** board)
{
	// Diagonal
	if ((board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') || (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
		printf("Player 1 wins!\n");
		return true;
	}
	if ((board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') || (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
		printf("Player 2 wins!\n");
		return true;
	}


	// Horizontal
	for (int i = 0; board[i] != NULL; ++i) {
		if (strcmp(board[i], "XXX") == 0) {
			printf("Player 1 wins!\n");
			return true;
		}
		if (strcmp(board[i], "OOO") == 0) {
			printf("Player 2 wins!\n");
			return true;
		}
	}

	// Vertical
	if ((board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') || (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') || (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')) {
		printf("Player 1 wins!\n");
		return true;
	}
	if ((board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') || (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') || (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')) {
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
