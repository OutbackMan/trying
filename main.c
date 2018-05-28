#include <stdlib.h>

#include "sdl-headers.h"
#include "core.h"

int main(int argc, char** argv)
{
	Core* core = core_create();	

	core_main_loop(core);

	return EXIT_SUCCESS;
}
