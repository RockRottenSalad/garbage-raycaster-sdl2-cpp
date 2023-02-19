#pragma once

#include<iostream>
#include<stdlib.h>
#include<vector>
#include<SDL2/SDL.h>

#include "player.hpp"


class window
{
    private:
        SDL_Window* gameWindow;
        SDL_Renderer* renderer;
    public:
        window(const char* windowTitle, int windowWidth, int windowHeight);
        ~window();

        void clear();
        void present();
        void drawBackground(RGBA color);
        void drawRects(Colored_SDL_Rect* renderList);
        void drawRect(Colored_SDL_Rect* rect);
        void drawLines(std::vector<int>* x2, std::vector<int>* y2, player* playerArg);
        void drawPlayer2D(player* playerArg);
        void render3D(std::vector<Colored_SDL_Rect>* raycastedRects);
};
