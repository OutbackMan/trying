#ifndef __core_h__
#define __core_h__

typedef struct {
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* main_event;

	STRETCHY_BUF() event_handlers; // index based on view_id enum
	STRETCHY_BUF() update_handlers;
	STRETCHY_BUF() render_handlers;

	long frame_time;
	int min_frame_time;
	long fps_time;
	int num_of_fps;
	int fps;

	//# replace with get_keyboard_state()
	bool move_pressed;
	bool key_menu_pressed;
	bool key_s;
	bool key_w;
	bool key_a;
	bool key_d;
	bool key_shift;
	bool key_a_pressed;
	bool key_d_pressed;

	bool mouse_left_pressed;
	bool mouse_right_pressed;
	int mouse_x;
	int mouse_y;

	Music* music;
	Text* text;
	MenuManager* menu_manager;
	Img* logo;

	Map* map;

	// left and right motion
	bool first_dir;

	bool quit_game;

} Core;

#endif
