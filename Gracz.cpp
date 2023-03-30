#include "Gracz.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Pocisk.h"
#include <vector>
Gracz::Gracz(float x, float y, int n)
{
	numer = n;
	shape.setPosition(x, y);
	shape.setFillColor(sf::Color::White);
	shape.setSize(sf::Vector2f(this->szer, this->wys));
	shape.setOrigin(this->szer / 2, this->wys / 2);
}

void Gracz::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->shape, state);
}

void Gracz::ruch()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && lewo() > 0 && numer == 1)
        shape.move({ -predkosc,0 });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && prawo() < 800 && numer == 1)
        shape.move({ predkosc,0 });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && gora() > 0 && numer == 1)
        shape.move({ 0,-predkosc });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dol() < 390 && numer == 1)
        shape.move({ 0,predkosc });

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && lewo() > 0 && numer == 2)
        shape.move({ -predkosc,0 });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && prawo() < 800 && numer == 2)
        shape.move({ predkosc,0 });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && gora() > 410 && numer == 2)
        shape.move({ 0,-predkosc });
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dol() < 800 && numer == 2)
        shape.move({ 0,predkosc });
}

float Gracz::lewo()
{
	return this->shape.getPosition().x - shape.getSize().x/2;
}

float Gracz::prawo()
{
	return this->shape.getPosition().x + shape.getSize().x / 2;
}

float Gracz::dol()
{
	return this->shape.getPosition().y + shape.getSize().y / 2;
}

float Gracz::gora()
{
	return this->shape.getPosition().y - shape.getSize().y / 2;
}

sf::Vector2f Gracz::pozycja()
{
	return shape.getPosition();
}

void Gracz::atak()
{
    hp--;
    if (hp == 0)
    {
        if (numer == 1)
        {
            system("cls");
            std::cout << "\nKoniec, wygral gracz: " << 2;
            
        }
        else if (numer == 2)
        {
            system("cls");
            std::cout << "\nKoniec, wygral gracz: " << 1;
        }
        shape.setFillColor(sf::Color::Red);
    }
}

bool Gracz::czy_koniec()
{
    if (hp == 0)
        return true;
    else return false;
}
