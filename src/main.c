#include <stdio.h>
#include "SDL.h"

#ifdef __APPLE__
#include <TargetConditionals.h>
#endif

#ifdef _WIN32
#include <windows.h>
#endif

void get_executable_path(char *path);

int main(int argc, const char * argv[]) {
	char path[1024];

	get_executable_path(path);

	printf("My SDL App");

    printf("Path: %s\n", path);

    return 0;
}

void get_executable_path(char *path) {
    int size = sizeof(path);

#ifdef TARGET_OS_MAC
    if (_NSGetExecutablePath(path, &size) == 0) {
        path = realpath(path, NULL);
    }
#endif

#ifdef _WIN32
    HMODULE hModule = GetModuleHandle(NULL);
    if (hModule != NULL) {
        GetModuleFileName(hModule, path, (sizeof(path)));
    }
#endif
}