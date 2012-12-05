#include <stdio.h>
#include "SDL.h"

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif

char * get_executable_path();

int main(int argc, char *argv[]) {
    SDL_Surface *hello = NULL;
    SDL_Surface *screen = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);

    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

    hello = SDL_LoadBMP("hello.bmp");

    SDL_BlitSurface(hello, NULL, screen, NULL);

    SDL_Flip(screen);

    SDL_Delay(2000);

    SDL_FreeSurface(hello);

    SDL_Quit();

    char *path = get_executable_path();
    
    printf("%s\n", path);

    return 0;
}

char * get_executable_path() {
    char path[1024];
    uint32_t size = sizeof(path);
#ifdef TARGET_OS_MAC
    if (_NSGetExecutablePath(path, &size) == 0) {
        char *res = realpath(path, NULL);
        return res;
    }
#endif
    
    return NULL;
}