#include "./mht_graphics.h"
void game_window(settings_t *settings, entity_t *entities, char** board)
{
	int x = 0, y = 0;

	// Get player symbol
	char player = 'E';
	if (settings->turn % 2 == 0)
		player = 'X';
	else
		player = 'O';

	// Catch mouse input
	sfVector2i mse = sfMouse_getPosition((const sfWindow*) settings->WIN);
	if (mse.y >= 0 && mse.y <= 100 && settings->EVNT.type == sfEvtMouseButtonPressed) {
		if (mse.x >= 0 && mse.x <= 100) {
			x = 0; y = 0;
		}
		if (mse.x >= 100 && mse.x <= 200) {
			x = 1; y = 0;
		}
		if (mse.x >= 200 && mse.x <= 300) {
			x = 2; y = 0;
		}
		if (board[y][x] == ' ') {
			settings->turn++;
			board[y][x] = player;
		}
	}
	if (mse.y >= 100 && mse.y <= 200 && settings->EVNT.type == sfEvtMouseButtonPressed) {
		if (mse.x >= 0 && mse.x <= 100) {
			x = 0; y = 1;
		}
		if (mse.x >= 100 && mse.x <= 200) {
			x = 1; y = 1;
		}
		if (mse.x >= 200 && mse.x <= 300) {
			x = 2; y = 1;
		}
		if (board[y][x] == ' ') {
			settings->turn++;
			board[y][x] = player;
		}
	}
	if (mse.y >= 200 && mse.y <= 300 && settings->EVNT.type == sfEvtMouseButtonPressed) {
		if (mse.x >= 0 && mse.x <= 100) {
			x = 0; y = 2;
		}
		if (mse.x >= 100 && mse.x <= 200) {
			x = 1; y = 2;
		}
		if (mse.x >= 200 && mse.x <= 300) {
			x = 2; y = 2;
		}
		if (board[y][x] == ' ') {
			settings->turn++;
			board[y][x] = player;
		}
	}

	// Check if solved
	if (end_rule(board) == true)
		exit(0);

	// Print caught input
	print_results(settings, entities, board);
	return;
}

void print_results(settings_t *settings, entity_t *entities, char** board)
{
	// Transforms coordonnates from the board to the window
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 'X')
				sfRenderWindow_drawSprite(settings->WIN, entities[(i * 3) + j + 1].sprite, NULL);
			else if (board[i][j] == 'O')
				sfRenderWindow_drawSprite(settings->WIN, entities[9 + (i * 3) + j + 1].sprite, NULL);
			if (board[i][j] == ' ')
				continue;
		}
	}
	sfRenderWindow_display(settings->WIN);
}

void end_window(settings_t *settings, entity_t *entities)
{
	return;
}
