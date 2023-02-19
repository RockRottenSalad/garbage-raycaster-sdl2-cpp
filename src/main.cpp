
#include<SDL2/SDL.h>

#include "game.hpp"

int main()
{
    window* gameWindow = new window("test", 900, 900);
    
    Vector2D playerPos(650, 450);
    Colored_SDL_Rect playerRect;
    playerRect.rect.w = 15;
    playerRect.rect.h = 15;
    playerRect.rect.x = playerPos.x;
    playerRect.rect.y = playerPos.y;

    playerRect.color.R = 50;
    playerRect.color.G = 175;
    playerRect.color.B = 50;
    playerRect.color.A = 250;

    player* gamePlayer = new player(playerRect, playerPos);
    game* gameInstance = new game(gameWindow, gamePlayer);

    gameInstance->startGame();

    delete gameInstance;
    SDL_Quit();
    return 0;
}
