#include <iostream>
#include <cmath>
#include "sdlwrapper.h"

const double A = 50;
const double step = 1;
const double ptor = 40;

double finalY = 0;


void drawSin(int y0)
{
    for(double x = 101; x < 530; x += step)
    {
        sdlw::drawLine(x, sin(x/ptor)*A+y0, x+step, sin((x+step)/ptor)*A+y0);
    }
}

void drawCircle(int cx, int cy, int r)
{
    //cx, cy - center coordinates; r - radius
    for (int x = 76; x < 1000; x++)
    {
        for (int y = 0; y < 1000; y++)
        {
            int distanceFromC = sqrt(pow(cy - y, 2) + pow(cx - x, 2));

            if (distanceFromC <= r)
            {
                sdlw::drawPixel(x, y);
                sdlw::updateGraphics();
            }
        }    
    }
}

int main(int argc, char* argv[])
{
    sdlw::setColor(255, 255, 255);

    // EARS
    drawSin(100);

    // BODY
    sdlw::drawLine(530, sin((530 + step) / ptor) * A + 100, 1000, 720); //right side
    sdlw::drawLine(100, sin((100 + step) / ptor) * A + 100, 0, 240); //left side

    // NOSE
    drawCircle(315, 220, 10); //top
    for (int x = 305; x < 326; x++)
    {
        sdlw::drawLine(x, 220, x, 250); //length
        sdlw::drawLine(x, 250, x + 30, 280); //right bend
        sdlw::drawLine(x, 250, x - 30, 280); //left bend
    }
    drawCircle(285, 280, 10);
    drawCircle(345, 280, 10);
    
    // EYES
    drawCircle(190, 200, 20); //left
    drawCircle(440, 200, 20); //right

    sdlw::updateGraphics();
    std::cin.get();
}