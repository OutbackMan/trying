#ifndef __img_h__
#define __img_h__

typedef struct {
	SDL_Texture* img;
	SDL_Rect rect;
} Img;

Img* img_create(const char* file_name, SDL_Renderer* renderer)
{
	SDL_Surface* loaded_surface = SDL_LoadBMP(file_name);	
	// set_color_key()
	img->img = SDL_CreateTextureFromSurface(renderer, loaded_surface);
	
	int width, height;
	SDL_QueryTexture(img->img, NULL, NULL, &width, &height);

	img->rect = {
		.x = 0,
		.y = 0,
		.w = width,
		.h = height
	}

	SDL_FreeSurface(loaded_surface);
}

void img_destroy(Img* img)
{
	
}

void img_draw(Img* img, SDL_Renderer* renderer, int x_offset, int y_offset, bool rotate)
{
	img->rect.x = x_offset;	
	img->rect.y = y_offset;	
	// rendercopy / rendercopyex
}

void img_draw_rotate()

#endif
