
#include "player.hpp"

player::player(Colored_SDL_Rect playerRectArg, Vector2D posArg)
    :playerRect(playerRectArg), pos(posArg)
{
    direction.setDegs(360.0f);
}

player::~player()
{}

Vector2D player::getPos()
{
    return pos;
}

Colored_SDL_Rect* player::getPlayerRect()
{
    return &playerRect;
}

angle player::getPlayerAngle()
{
    return direction;
}

bool player::getRenderMode()
{
    return renderMode;
}

void player::setPos(Vector2D posArg)
{
    pos = posArg;
    playerRect.rect.x = posArg.x;
    playerRect.rect.y = posArg.y;
}

void player::setPlayerRect(Colored_SDL_Rect rectArg)
{
    playerRect = rectArg;
}

void player::setPlayerAngle(angle angleArg)
{
    direction = angleArg;
}

void player::changeRenderMode()
{
    if(getRenderMode())
    {
        renderMode = RENDER_2D;
        return;
    }
     renderMode = RENDER_3D; 
}

void player::handleKeyPress(SDL_Event event)
{
    switch(event.key.keysym.sym)
    {
        case SDLK_c:
            changeRenderMode();
            break;
        case SDLK_w:
            setPos( Vector2D(getPos().x + (5.0f * cos(direction.getRads())), getPos().y + (5.0f * sin(direction.getRads())) ));
            break;
        case SDLK_a:
            direction.setDegs(direction.getDegs() - 5.0f);
            break;
        case SDLK_d:
            direction.setDegs(direction.getDegs() + 5.0f);
            break;
        case SDLK_s:
            setPos( Vector2D(getPos().x - (5.0f * cos(direction.getRads())), getPos().y - (5.0f * sin(direction.getRads())) ));
            break;
        default:
            break;
    }
}
