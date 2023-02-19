
#include "raycaster.hpp"

raycaster::raycaster()
{}

raycaster::~raycaster()
{}

std::vector<int>* raycaster::getX2()
{
    return &x2;
}

std::vector<int>* raycaster::getY2()
{
    return &y2;
}

std::vector<Colored_SDL_Rect>* raycaster::getRaycastedRects()
{
    return &raycastedRects;
}

RGBA raycaster::getMapSquareColor(int y, int x)
{
    RGBA colorBuffer;

    switch(gameMap[y][x])
    {
        case 1:
            colorBuffer.R = 255;
            colorBuffer.G = 255;
            colorBuffer.B = 255;
            colorBuffer.A = 255;
            break;
        case 0:
            colorBuffer.R = 25;
            colorBuffer.G = 25;
            colorBuffer.B = 25;
            colorBuffer.A = 255;
            break;
        default:
            colorBuffer.R = 0;
            colorBuffer.G = 0;
            colorBuffer.B = 0;
            colorBuffer.A = 255;
            break;
    }
    return colorBuffer;
}

Colored_SDL_Rect* raycaster::convertMapIntoRects2D()
{
    Colored_SDL_Rect* mapArray = new Colored_SDL_Rect[xSquares*ySquares]; 
    Colored_SDL_Rect bufferRect;
    std::vector<Colored_SDL_Rect> mapBuffer;

    for(int x = 0; x < xSquares; x++)
    {
        for(int y = 0; y < ySquares; y++)
        {
           bufferRect.rect.w = rectWidth - 3;
           bufferRect.rect.h = rectHeight - 3;

           bufferRect.rect.x = x * rectWidth;
           bufferRect.rect.y = y * rectHeight;
           bufferRect.color = getMapSquareColor(y, x);

           mapBuffer.push_back(bufferRect);

        }
    }

    std::copy(mapBuffer.begin(), mapBuffer.end(), mapArray);

    return mapArray;
}

Uint8 raycaster::findShadow(Vector2D rayArg)
{
    double xFloor = ceil(rayArg.x / 90.0f) * 90.0f;
    double yFloor = floor(rayArg.y / 90.0f) * 90.0f;

    if(xFloor > yFloor)
    {
        return 250;
    }
    return 205;
}

void raycaster::raycast(player* playerArg)
{
    x2.clear();
    y2.clear();
    raycastedRects.clear();

    Vector2D playerPos = Vector2D(playerArg->getPos().x + (15.0f/2.0f), playerArg->getPos().y + (15.0f/2.0f));
    Vector2D rayPos = playerPos; 
    Vector2D rayPosReset = rayPos;
    double playerAngle = playerArg->getPlayerAngle().getRads();

    Colored_SDL_Rect rect3D;
    double dist;

    int xbuffer = 0, ybuffer = 0;
    int RectX = -1;

    for(double ang = playerAngle - (30.0f*0.0175f); ang <= playerAngle + (30.0f*0.0175f); ang += 0.0175f)
    {
        double xCos = cos(ang) * 16.0f;
        double ySin = sin(ang) * 16.0f;
        rayPos = rayPosReset;
        int rectType = 0;
        RectX++;
        while(rectType == 0)
        {
            rayPos.x += (xCos);    
            rayPos.y += (ySin);
            ybuffer = static_cast<int>((floor(rayPos.y / 90.0f)));
            xbuffer = static_cast<int>((floor(rayPos.x / 90.0f)));
        
            rectType = gameMap[ybuffer][xbuffer];
        }

        x2.push_back(static_cast<int>(floor(rayPos.x)));
        y2.push_back(static_cast<int>(floor(rayPos.y)));

        dist = sqrt( pow(playerPos.x - rayPos.x,2) + pow(playerPos.y - rayPos.y, 2) );
        dist *= cos(ang - playerAngle);

        rect3D.rect.h = floor(450.0f / (dist) * 110);
        rect3D.rect.w = 15;
        rect3D.rect.x = 15 * RectX;
        rect3D.rect.y = (90 * 100) / (rect3D.rect.h) + 150;
        rect3D.color.R = 10;
        rect3D.color.G = findShadow(rayPos);
        rect3D.color.B = 10;
        rect3D.color.A = 255;
        
        raycastedRects.push_back(rect3D);

      //  std::cout << ang << std::endl;
    }
}


