#include <SDL.h>

#include <cstdlib>

constexpr int window_width = 1280;
constexpr int window_height = 720;

int main(int, char**)
{
    if (SDL_Init(SDL_INIT_VIDEO))
    {
        // TODO: logging
        return 1;
    }

    if (std::atexit(SDL_Quit))
    {
        // TODO: logging

        SDL_Quit();
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
        "Sample SDL project",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_width,
        window_height,
        0
    );

    if (!window)
    {
        // TODO: logging
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        // TODO: logging
        return 1;
    }

    while (true)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                goto end;
        }

        SDL_SetRenderDrawColor(renderer, 0xaa, 0xaa, 0xaa, 0xff);
        SDL_RenderClear(renderer);

        SDL_RenderPresent(renderer);
    }

end:
    return 0;
}