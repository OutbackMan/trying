typedef struct {
	MenuManager* menu_manager;
	Text* text;
	Img* logo;
	Music* music;
} Cfg;

// mm
typedef struct {
	MainMenu* main_menu;
	OptionsMenu* options_menu;
} MenuManager;

typedef enum {
	MAIN_MENU,
	LOADING,
	GAME,
	ABOUT,
	OPTIONS,
	PAUSE
} GAME_STATE;
