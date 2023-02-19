
#include "game.hpp"


game::game(window* windowArg, player* playerArg)
    :gameWindow(windowArg), gameRaycaster(new raycaster()), gamePlayer(playerArg)
{
    SDL_Init(SDL_INIT_VIDEO);
    fpsDelta = 0.0;
    tickDelta = 0.0;
    now = SDL_GetPerformanceCounter();
    last = 0;
}

game::~game()
{
    delete gameWindow;
    delete gameRaycaster;
    delete mapBuffer;
    delete gamePlayer;
}

void game::deltaTick()
{
    last = now;
    now = SDL_GetPerformanceCounter();
    fpsDelta += (float)(now - last)*1000 / (float)SDL_GetPerformanceFrequency();
}

void game::drawTick()
{
    RGBA backgroundColor;
    backgroundColor.R = 50;
    backgroundColor.G = 50;
    backgroundColor.B = 50;
    backgroundColor.A = 255;
    gameWindow->clear();
    gameWindow->drawBackground(backgroundColor);
    gameRaycaster->raycast(gamePlayer);
    switch(gamePlayer->getRenderMode())
    {
        case RENDER_2D:
            gameWindow->drawRects(mapBuffer);
            gameWindow->drawLines(gameRaycaster->getX2(), gameRaycaster->getY2(), gamePlayer);
            gameWindow->drawPlayer2D(gamePlayer);
            break;
        case RENDER_3D:
            gameWindow->render3D(gameRaycaster->getRaycastedRects()); 
            break;
    }
    gameWindow->present();
}

void game::handleEvents(SDL_Event event)
{
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            gameRunning = false;
            break;
        case SDL_KEYDOWN:
            gamePlayer->handleKeyPress(event);
            break;
        default:
            break;
    }
}

void game::gameLoop()
{
    SDL_Event event;
    mapBuffer = gameRaycaster->convertMapIntoRects2D();

    while(gameRunning)
    {
        handleEvents(event);
        deltaTick();

        if(fpsDelta > TARGET_FPS)
        {
            drawTick();
            fpsDelta = 0.0;
        }

    }
}

void game::startGame()
{
    gameRunning = true;
    gameLoop();
}
