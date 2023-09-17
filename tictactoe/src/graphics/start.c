#include "./mht_graphics.h"
void start_game(settings_t *settings, entity_t *entities, char** board)
{
	// Display background
	sfRenderWindow_drawSprite(settings->WIN, entities[0].sprite, NULL);
	sfRenderWindow_display(settings->WIN);

	// Main loop event
	while (sfRenderWindow_isOpen(settings->WIN)) {
		while (sfRenderWindow_pollEvent(settings->WIN, &settings->EVNT))
			close_game(settings);
		mouse_detection(settings, entities, board);
	}
}

void close_game(settings_t *settings)
{
	// Detect window interruption
	if (settings->EVNT.type == sfEvtClosed)
		sfRenderWindow_close(settings->WIN);
}

void mouse_detection(settings_t *settings, entity_t *entities, char** board)
{
	// Printing the right window
	if (settings->selected == 0)
		game_window(settings, entities, board);
	else if (settings->selected == 1)
		end_window(settings, entities);
	else {
		printf("%s\n", "Error while loading the window");
		exit(84);
	}
}
