typedef enum {
	VIEW_GAME_MENU,
	VIEW_GAME,
	VIEW_WORMS
} VIEW_ID;

typedef struct {
	VIEW_ID active_view;
	MenuManager* menu_manager;
} Game;

// ....................................................
#include "menus.h" // typedef enum { MENU_MAIN, MENU_ABOUT } MENU_ID;

typedef struct {
	MENU_ID active_menu;
	MenuMain* menu_main;
	MenuAbout* menu_about;
} MenuManager;

if (game->active_view == VIEW_MENU) {
	game->active_view = menu_manager_events(game->menu_manager);	
}

// may have to have singleton for music, textures, assets, etc.
// ....................................................
TTF_Init();
TTF_Font* font = TTF_OpenFont("arial.ttf", 25);
TTF_CloseFont(font);
TTF_Quit();

enum {
	MENU_MAIN_LOCAL_PLAY,
	MENU_MAIN_NETWORK_PLAY,
	MENU_MAIN_ACHEIVEMENTS,
	MENU_MAIN_HELP_AND_OPTIONS,
	MENU_MAIN__NUM
};

typedef struct {
	SDL_Texture* labels[MENU_MAIN__NUM];	
	SDL_Rect label_positions[MENU_MAIN__NUM];
	bool label_is_selected[MENU_MAIN__NUM];
	SDL_Colour label_selection_colours[2];
	SDL_Texture* background;
} MenuMain;

MenuMain* menu_main_create(const char* background_filename);

void menu_main_destroy(MenuMain* menu_main);

MENU_ID menu_main_events(MenuMain* menu_main, SDL_Event* event);

void menu_main_update(MenuMain* menu_main);

void menu_main_render(MenuMain* menu_main, SDL_Renderer* renderer);


#define IS_NOT_SELECTED 0
#define IS_SELECTED 1
MenuMain* menu_main_create(const char* background_filename, TTF_Font* font)
{
	MenuMain* menu_main = xmalloc(sizeof(MenuMain));
		
	int label_width;
	int label_height;
	int label_draw_index = 0;

	SDL_Surface* local_play_surface = TTF_RenderText_Solid(font, "LOCAL PLAY", menu_main->label_selection_colours[IS_SELECTED]);
	menu_main->labels[MENU_MAIN_LOCAL_PLAY] = SDL_CreateTextureFromSurface(local_play_surface);
	SDL_FreeSurface(local_play_surface);
	SDL_QueryTexture(menu_main->labels, NULL, NULL, &label_width, &label_height);
	menu_main->label_positions[MENU_MAIN_LOCAL_PLAY] = {
		.x = field_width / 2 - label_width / 2,
		.y = field_height / MENU_MAIN__NUM * label_draw_index++;
		.w = label_width,
		.h = label_height
	};

	menu_main->labels = {
		[MENU_MAIN_LOCAL_PLAY] = "LOCAL PLAY",
		[MENU_MAIN_NETWORK_PLAY] = "NETWORK PLAY",
		[MENU_MAIN_ACHEIVEMENTS] = "ACHEIVEMENTS",
		[MENU_MAIN_HELP_AND_OPTIONS] = "HELP AND OPTIONS"
	};

	menu_main->label_is_selected = {
		[MENU_MAIN_LOCAL_PLAY] = true,
		[MENU_MAIN_NETWORK_PLAY] = false,
		[MENU_MAIN_ACHEIVEMENTS] = false,
		[MENU_MAIN_HELP_AND_OPTIONS] = false
	};
	
	menu_main->label_selection_colours = {
		[IS_NOT_SELECTED] = {255, 255, 255},
		[IS_SELECTED] = {255, 0, 0}
	};

	SDL_Surface* background_surface = SDL_LoadBMP(background_filename);
	SDL_Texture* background_texture = SDL_CreateTextureFromSurface(background_surface);
	SDL_FreeSurface(background_surface);
	menu_main->background = background->texture;

	return menu_main;
}
#undef IS_NOT_SELECTED
#undef IS_SELECTED

void menu_main_destroy(MenuMain* menu_main)
{
	SDL_DestroyTexture(menu_main->background);
	free(menu_main);
}

int menu_main_events(MenuMain* menu_main, SDL_Event* event)
{
	if (event->type == SDL_MOUSEMOTION) {
					
	} else if (event->type == SDL_MOUSEBUTTON_DOWN) {
				
	} else if (event->type == SDL_KEYDOWN) {
		if (select_menu_option) {
			return menu_option_id;		
		}				
	} else {
		return;		
	}
}

void menu_main_render(MenuMain* menu_main, SDL_Renderer* renderer)
{
	SDL_RenderCopy(menu_main->background, NULL, NULL);
	for (size_t label_index = 0; label_index < MENU_MAIN__NUM; ++label_index) {
		SDL_RenderCopy();
	}
}
