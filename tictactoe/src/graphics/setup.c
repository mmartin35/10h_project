#include "./mht_graphics.h"

/*
int mhtlib_graphics()
{
	// Load structures
	entity_t *entities = malloc(sizeof(entity_t) * 5);
	settings_t *settings = malloc(sizeof(settings_t));

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
	start_game(settings, entities);
        printf("%s\n", "status: event_loop ok -> end of WINDOW");

	// Free memory
	free(entities);
	free(settings);
	return 0;
}
*/

void load_entities(entity_t *entities)
{
	// Number of preloaded entities
	entities->nb = 19;

	// Entities loaded
	create_sprite(entities, "./src/graphics/assets/background.png", 0, 1, 0, 0);

	// X entities
	create_sprite(entities, "./src/graphics/assets/1.png", 1, 1, 0, 0);
	create_sprite(entities, "./src/graphics/assets/1.png", 2, 1, 100, 0);
	create_sprite(entities, "./src/graphics/assets/1.png", 3, 1, 200, 0);
	create_sprite(entities, "./src/graphics/assets/1.png", 4, 1, 0, 100);
	create_sprite(entities, "./src/graphics/assets/1.png", 5, 1, 100, 100);
	create_sprite(entities, "./src/graphics/assets/1.png", 6, 1, 200, 100);
	create_sprite(entities, "./src/graphics/assets/1.png", 7, 1, 0, 200);
	create_sprite(entities, "./src/graphics/assets/1.png", 8, 1, 100, 200);
	create_sprite(entities, "./src/graphics/assets/1.png", 9, 1, 200, 200);

	// O entities
	create_sprite(entities, "./src/graphics/assets/2.png", 10, 1, 0, 0);
	create_sprite(entities, "./src/graphics/assets/2.png", 11, 1, 100, 0);
	create_sprite(entities, "./src/graphics/assets/2.png", 12, 1, 200, 0);
	create_sprite(entities, "./src/graphics/assets/2.png", 13, 1, 0, 100);
	create_sprite(entities, "./src/graphics/assets/2.png", 14, 1, 100, 100);
	create_sprite(entities, "./src/graphics/assets/2.png", 15, 1, 200, 100);
	create_sprite(entities, "./src/graphics/assets/2.png", 16, 1, 0, 200);
	create_sprite(entities, "./src/graphics/assets/2.png", 17, 1, 100, 200);
	create_sprite(entities, "./src/graphics/assets/2.png", 18, 1, 200, 200);
}

void create_sprite(entity_t *entities, char* file, int i, int scale, int pos_x, int pos_y)
{
	entities[i].texture = sfTexture_createFromFile(file, NULL);
	entities[i].sprite = sfSprite_create();
	entities[i].scale.x = scale;
	entities[i].scale.y = scale;
	entities[i].pos.x = pos_x;
	entities[i].pos.y = pos_y;
}

void set_entities(entity_t *entities)
{
	// Set entities values
	for (int i = 0; i < entities->nb; ++i) {
		sfSprite_setPosition(entities[i].sprite, entities[i].pos);
		sfSprite_setScale(entities[i].sprite, entities[i].scale);
		sfSprite_setTexture(entities[i].sprite, entities[i].texture, sfTrue);
	}
}
