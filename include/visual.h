#ifndef CHECK
#define CHECK

#include <SDL2/SDL.h>

#define RANGE   1000000
#define LENGTH  1550
#define WINDWID 1550
#define WINDHEI 820

typedef struct window window;

struct window
{
    SDL_Window* window;
    SDL_Renderer* render;
};

window* initWindow(void);

void displayArr(window* wind, int* arr, int len, float max);

float getmax(int* arr, int len);

void waitEvent(window* wind);

void refreshWindow(window* wind);

#endif