#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Pocisk.h"
#include <vector>
Pocisk::Pocisk(float x, float y, int n)
{
    numer = n;
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Red);
    shape.setRadius(this->rozmiar);
    shape.setOrigin(this->rozmiar, this->rozmiar);

}

void Pocisk::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
    target.draw(this->shape, state);
}

float Pocisk::lewo()
{
	return this->shape.getPosition().x - shape.getRadius();
}

float Pocisk::prawo()
{
	return this->shape.getPosition().x + shape.getRadius();
}

float Pocisk::dol()
{
	return this->shape.getPosition().y + shape.getRadius();
}

float Pocisk::gora()
{
	return this->shape.getPosition().y - shape.getRadius();
}

sf::Vector2f Pocisk::pozycja()
{
    return shape.getPosition();
}

void Pocisk::ruch()
{
    if (numer == 1)
        shape.move(0, predkosc);
    else if(numer == 2)
        shape.move(0, -predkosc);

}