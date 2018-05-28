#include "core.h"

void core_input(Core* core)
{
	switch (core->menu_manager->view_id) {
	case 2:	
	case 7:	
		if (!map_get_in_event(core->map)) {
			core_input_player(core);				
		} else {
			core_reset_move(core); // when player is not moving
		}
		break;
	default:
		core_input_menu(core);
		break;
	}	
}

void core_mouse_input(Core* core)
void core_input_player(Core* core)
{
	if (core->main_event->type == SDL_WINDOWEVENT) {
		switch (core->main_event.window.event) {
		case SDL_WINDOWEVENT_FOCUS_LOST:
			menu_manager->view_id = PAUSE;
			music_play_chunk(PAUSE);
			music_pause();
			break;
		}		
	}

	if (core->main_event->type == SDL_KEYDOWN) {
		if (core->main_event->key.keysym.sym == PLAYER_SQUAT_KEY) {
			core->map->player.is_squatting = true;		
		}

		if (core->main_event->key.keysym.sym == PLAYER_JUMP_KEY) {
			core->map->player.is_jumping = true;		
		}
	}
			
}

void core_input_menu(Core* core)
{
	if (core->main_event->type == SDL_KEYDOWN) {
		switch(core->main_event->key.keysym.sym) {
		case SDLK_s:
		case SDLK_DOWN:
			if (core->key_menu_pressed = true) {
				core->menu_manager->key_pressed = 2;
				core->key_menu_pressed = true;
			}
			break;
		}
		// ...
	}

	if (core->main_event->type == SDL_KEYUP) {
		core->key_menu_pressed = false;		
	}
}

void core_update(Core* core)
{
	menu_manager_update(core->menu_manager);	
}
void core_draw(Core* core)
{
	menu_manager_draw(core->menu_manager);	
}
void core_reset_move(Core* core)
void core_reset_keys(Core* core)

void core_main_loop(Core* core)
{
	core->fps_time = SDL_GetTicks();
	
	while (!core->quit_game && core->main_event->type != SDL_QUIT) {
		core->frame_time = SDL_GetTicks();			
		SDL_PollEvent(core->main_event);
		SDL_RenderClear(core->renderer);

		menu_manager_set_background_colour(core->menu_manager, core->renderer);
		SDL_RenderFillRect(core->renderer, NULL);

		core_input(core);
		core_mouse_input(core);
		core_update(core);
		core_draw(core);

		if (SDL_GetTicks() - core->frame_time < core->min_frame_time) {
			SDL_Delay(core->min_frame_time - (SDL_GetTicks() - core->frame_time));	
		}
	}
}

Core* core_create(unsigned width, unsigned height)
{
	Core* core = xmalloc(sizeof(Core));

	SDL_Init(SDL_VIDEO | SDL_AUDIO | SDL_TIMER);

	core->window = SDL_CreateWindow(
							"game", 
							SDL_WINDOWPOS_CENTERED,
							SDL_WINDOWPOS_CENTERED,
							width,
							height,
							SDL_WINDOW_SHOWN
					);

	SDL_Surface* window_icon_surface = SDL_LoadBMP("assets/icon.bmp");
	SDL_SetWindowIcon(core->window, window_icon_surface);
	SDL_FreeSurface(window_icon_surface);
	
	core->renderer = SDL_CreateRenderer(
							core->window, 
							-1, 
							SDL_RENDERER_ACCELERATED
					);

	core->main_event = NULL;

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	core->map = map_create(core->renderer);

	core->menu_manager = menu_manager_create(); // TODO
	menu_manager_set_active_option(menu_manager, core->renderer);
		
	core->logo = img_create(core->renderer, "assets/logo.bmp");

	core->music = music_create(); // TODO
	music_play_music(core->music);	

	core->frame_time = 0;
	core->min_frame_time = 0;
	core->fps_time = 0;
	core->num_of_fps = 0;
	core->fps = 0;

	core->move_pressed = false;
	core->key_menu_pressed = false;
	core->key_s = false;
	core->key_w = false;
	core->key_a = false;
	core->key_d = false;
	core->key_shift = false;
	core->key_a_pressed = false;
	core->key_d_pressed = false;
	core->mouse_left_pressed = false;
	core->mouse_right_pressed = false;

	core->mouse_x = 0;
	core->mouse_y = 0;

	core->first_dir = false;
	core->quit_game = false;

	return core;
}

void core_destroy(Core* core)
{
	music_destroy(core->music);
	menu_manager_destroy(core->menu_manager);
	img_destroy(core->logo);
	map_destroy(core->map);
	Mix_CloseAudio();

	SDL_DestroyRenderer(core->renderer);
	SDL_DestroyWindow(core->renderer);
	SDL_Quit();
}


