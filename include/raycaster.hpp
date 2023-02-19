#pragma once

#include<SDL2/SDL.h>
#include<vector>

#include "player.hpp"

#define mapX 900
#define mapY 900

#define xSquares 10
#define ySquares 10

#define rectWidth 900/10
#define rectHeight 900/10

class raycaster
{
    private:
        int gameMap[10][10] =
        {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
            {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
            {1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
            {1, 0, 0, 0, 1, 1, 0, 1, 1, 1},
            {1, 0, 1, 0, 1, 0, 0, 0, 0, 1},
            {1, 0, 1, 0, 0, 0, 1, 0, 0, 1},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
        };
        std::vector<int> x2;
        std::vector<int> y2;
        std::vector<Colored_SDL_Rect> raycastedRects;

    public:
        raycaster();
        ~raycaster();

        std::vector<int>* getX2();
        std::vector<int>* getY2();
        std::vector<Colored_SDL_Rect>* getRaycastedRects();
        RGBA getMapSquareColor(int y, int x);
        Colored_SDL_Rect* convertMapIntoRects2D();

        Uint8 findShadow(Vector2D rayArg);
        void raycast(player* playerArg);

};
