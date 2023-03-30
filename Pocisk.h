#pragma once
#include <SFML/Graphics.hpp>
#include "Gracz.h"


class Pocisk: public sf::Drawable
{
public:
	Pocisk(float x, float y, int n);
	~Pocisk() = default;
	Pocisk() = delete;

	sf::CircleShape shape;

	void ruch();

	float lewo();
	float prawo();
	float dol();
	float gora();

	sf::Vector2f pozycja();

private:

	int numer;
	float rozmiar = 10;
	float predkosc = 0.2;
	sf::Vector2f velo{ predkosc,predkosc };

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

};

