#pragma once

#include "types.hpp"

#define RENDER_3D true
#define RENDER_2D false

class player
{
    private:
        Colored_SDL_Rect playerRect;
        Vector2D pos;
        angle direction;
        bool renderMode;
    public:
    player(Colored_SDL_Rect playerRectArg, Vector2D posArg);
    ~player();

    Vector2D getPos();
    Colored_SDL_Rect* getPlayerRect();
    angle getPlayerAngle();
    bool getRenderMode();

    void setPos(Vector2D posArg);
    void setPlayerRect(Colored_SDL_Rect rectArg);
    void setPlayerAngle(angle angleArg);
    void changeRenderMode();

    void handleKeyPress(SDL_Event event);
};

