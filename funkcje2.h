#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Gracz.h"
#include "Pocisk.h"
#include <deque>
inline void czy_kolizja(Gracz& a, Pocisk& b, std::deque<sf::Sprite>& h1, std::deque<sf::Sprite>&h2)
{
    if (a.shape.getGlobalBounds().intersects(b.shape.getGlobalBounds()))
    {
        b.shape.setPosition(1000, 1000);
        a.atak();
        if (a.numer == 1)
            h1.pop_back();
        else if (a.numer == 2)
            h2.pop_front();
    }
}
