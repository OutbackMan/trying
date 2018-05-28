#ifndef __map_h__
#define __map_h__

#endif

typedef struct {
	
} Block;

typedef struct {
	STRETCHY_BUF(Block*) blocks;
	bool in_event;
	int spawn_id;
	Player* player;
	// ... minions
	u32 map_time; // control music
} Map;

typedef struct {
	STRETCHY_BUF(Sprite*) sprites;
	int sprite_id;
	bool move_direction;
	int move_animation_time;
	int x, y;
	bool is_jumping; // sprite states
	bool is_squatting;
	float current_falling_speed;
	float current_jump_speed;
	int scale_x; // when drawing alter this value to increase scale
	int scale_y;
	// also use for collision detection

	// player_power_up_animation(), move_animation(), etc.
	// start_jump(), reset_jump(), start_run)(), reset_run(). etc.
} Player;

typedef struct {
	int current_block_id;	
	// mouse presses place blocks which are selected by their sprite
} LevelEditor;

// SDL_SetHint(SDL_RENDER_SCALE_QUALITY, "0"); for nearest neighbour
// SDL_RenderSetLogicalSize();
