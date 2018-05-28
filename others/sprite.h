#ifndef __sprite_h__
#define __sprite_h__

#define STRETCHY_BUF(x) x*

typedef struct {
	STRETCHY_BUF(Img*) sprite;
	STRETCHY_BUF(unsigned int) delays;
	bool rotate;
	int current_frame;
	int start_frame;
	int end_frame;
	unsigned long time_passed;
} Sprite;

Sprite* sprite_create(SDL_Renderer*, STRETCHY_BUF(const char*) sprite_files)
{
	sprite->end_frame = STRETCHY_BUF_LEN(sprite_files) - 1;
	for (int i = 0; i < sprite->end_frame + 1; ++i) {
		STRETCHY_BUF_PUSH(sprite->sprite, sprite_create(sprite_files[i]));
	}

}

#endif
