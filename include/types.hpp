#pragma once

#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

struct RGBA
{
    Uint8 R, G, B, A;
};

struct Colored_SDL_Rect
{
    SDL_Rect rect;
    RGBA color;
};

struct Vector2D
{
    int x, y;
    Vector2D();
    Vector2D(int xArg, int yArg) :x(xArg), y(yArg)
    {}
};

class angle
{
    private:
        double degs;
        double rads;
        void degreesToRadians() { rads = degs * (M_PI / 180.0f); }
        void radiansToDegrees() { degs = rads * (180.0f / M_PI); }
    public:
        void setDegs(double degsArg) 
        { 
            degs = fmod(degsArg, 360.0f);
            if(degs <= 0)
                degs += 360.0f;
            degreesToRadians(); 
        }

        void setRads(double radsArg)
        {
            rads = fmod(radsArg, 2*M_PI);
            if(rads <= (6*M_PI)/3)
                rads += 2*M_PI;
            radiansToDegrees();
        }

        double getDegs() { return degs; }
        double getRads() { return rads; }
};

