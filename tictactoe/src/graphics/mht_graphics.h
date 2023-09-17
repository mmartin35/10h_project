#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>
// Structures
typedef struct entity_s {
	int nb;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f scale;
        sfVector2f pos;
	sfVector2f size;
} entity_t;

typedef struct settings_s {
	sfRenderWindow *WIN;
	sfEvent EVNT;
	int selected;
	int turn;
} settings_t;

// Functions

// int mhtlib_graphics();

//	Pregame
void load_entities(entity_t *entities);
void create_sprite(entity_t *entities, char* file, int i, int scale, int pos_x, int pos_y);
void set_entities(entity_t *entities);

//	Game
void start_game(settings_t *settings, entity_t *entities, char** board);
void mouse_detection(settings_t *settings, entity_t *entities, char** board);

void game_window(settings_t *settings, entity_t *entities, char** board);
void print_results(settings_t *settings, entity_t *entities, char** board);
void end_window(settings_t *settings, entity_t *entities);

//	Endgame
void close_game(settings_t *settings);
