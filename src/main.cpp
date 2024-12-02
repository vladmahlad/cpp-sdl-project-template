#include <SDL.h>

int main(int, char**)
{
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Message box", "Hello, World!", nullptr);
    return 0;
}