#pragma once

#include<SDL2/SDL.h>

#include "window.hpp"
#include "raycaster.hpp"

#define TARGET_FPS 1000.0/60.0

class game
{
    private:
        window* gameWindow;
        raycaster* gameRaycaster;
        player* gamePlayer;
        bool gameRunning;

        Colored_SDL_Rect* mapBuffer;

        // delta
        double fpsDelta;
        Uint64 now;
        Uint64 last;
    public:
        game(window* windowArg, player* playerArg);
        ~game();
        void deltaTick();
        void drawTick();
        void handleEvents(SDL_Event event);
        void gameLoop();
        void startGame();
};

