
#include "window.hpp"

window::window(const char* windowTitle, int windowWidth, int windowHeight)
    :gameWindow(nullptr), renderer(nullptr)
{
    gameWindow = SDL_CreateWindow(windowTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    if(gameWindow == nullptr)
    {
        std::cout << "Window creation error: " << SDL_GetError() << std::endl;
        std::exit(1); 
    }

    renderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == nullptr)
    {
        std::cout << "Renderer creation error: " << SDL_GetError() << std::endl;
        std::exit(1);
    }

}

window::~window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(gameWindow);
}

void window::clear()
{
    SDL_RenderClear(renderer);
}

void window::present()
{
    SDL_RenderPresent(renderer);
}

void window::drawBackground(RGBA color)
{
    SDL_SetRenderDrawColor(renderer, color.R, color.G, color.B, color.A);
    SDL_RenderFillRect(renderer, NULL);
}

void window::drawRects(Colored_SDL_Rect* renderList)
{
    for(int i = 0; i < 100; i++)
    {
        SDL_SetRenderDrawColor(renderer, renderList[i].color.R, renderList[i].color.G, renderList[i].color.B, renderList[i].color.A);
        SDL_RenderFillRect(renderer, &renderList[i].rect);
    }
}

void window::drawRect(Colored_SDL_Rect* rectArg)
{
    SDL_SetRenderDrawColor(renderer, rectArg->color.R, rectArg->color.G, rectArg->color.B, rectArg->color.A);
    SDL_RenderFillRect(renderer, &rectArg->rect);
}

void window::drawLines(std::vector<int>* x2, std::vector<int>* y2, player* playerArg)
{
    SDL_SetRenderDrawColor(renderer, 255, 10, 10, 255);
    int playerX = playerArg->getPos().x + (15.0f/2.0f);
    int playerY = playerArg->getPos().y + (15.0f/2.0f);
    for(int i = 0; i <= x2->size() - 1; i++)
    {
        SDL_RenderDrawLine(renderer, playerX, playerY, x2->at(i), y2->at(i));
    }
}

void window::drawPlayer2D(player* playerArg)
{
   drawRect(playerArg->getPlayerRect()); 
   float playerAngle = playerArg->getPlayerAngle().getRads();

   float x = playerArg->getPos().x + (15.0f/2.0f);
   float y = playerArg->getPos().y + (15.0f/2.0f);

   float x2 = x + (25.0f * cos(playerAngle));
   float y2 = y + (25.0f * sin(playerAngle));
   
   SDL_RenderDrawLine(renderer, x, y, x2, y2);
}

void window::render3D(std::vector<Colored_SDL_Rect>* raycastedRects)
{
    for(Colored_SDL_Rect rect3D : *raycastedRects)
    {
        drawRect(&rect3D);
    }
}


