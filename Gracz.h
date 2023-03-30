#pragma once
#include <SFML/Graphics.hpp>

class Gracz : public sf::Drawable
{
public:
	Gracz(float x, float y, int n);
	~Gracz() = default;
	Gracz() = delete;
	int numer;

	void ruch();
	void atak();

	float lewo();
	float prawo();
	float dol();
	float gora();

	bool czy_koniec();
	sf::RectangleShape shape;
	sf::Vector2f pozycja();

private: 

	int hp = 5;
	float wys = 50;
	float szer = 50;
	float predkosc = 0.15;
	sf::Vector2f velo{ predkosc,predkosc };

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;

};

