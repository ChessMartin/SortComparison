#include <visual.h>

void displayArr(window* wind, int* arr, int len, float max)
{
    SDL_SetRenderDrawColor(wind->render, 0, 0, 0, 255);
    SDL_RenderClear(wind->render);
    float stepWidth = (float) WINDWID / len;
    int maxHeight = WINDHEI * 80 / 100;
    float stepHeight = (float) maxHeight / max;
    SDL_SetRenderDrawColor(wind->render, 0, 255, 255, 255);
    int x1, y1, x2, y2;
    for (int i = 0; i < len; i++)
    {
        x1 = stepWidth * i;
        y1 = WINDHEI;
        x2 = stepWidth * i;
        y2 = WINDHEI - stepHeight * arr[i];
        SDL_RenderDrawLine(wind->render, x1, y1, x2, y2);
    }
    SDL_RenderPresent(wind->render);
}

window* initWindow(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    window* wind = SDL_malloc(sizeof(window));
    wind->window = SDL_CreateWindow("Benchmark", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDWID, WINDHEI, SDL_WINDOW_SHOWN);
    wind->render = SDL_CreateRenderer(wind->window,-1, SDL_RENDERER_ACCELERATED);
    return wind;
}

float getmax(int* arr, int len)
{
    float max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void waitEvent(window* wind)
{
    int boolean = 1;
    SDL_Event event;
    while (boolean)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
            boolean = 0;
            SDL_DestroyRenderer(wind->render);
            SDL_DestroyWindow(wind->window);
            break;
        
        default:
            break;
        }
    }
    
}