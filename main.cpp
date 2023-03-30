#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <vector>
#include "Gracz.h"
#include "Pocisk.h"
#include "funkcje2.h"
#include <deque>
int main()
{ 
        start:
        sf::RenderWindow window(sf::VideoMode(800, 800), "Dominik Pindych 21.03.2023");

        sf::Font font;
        sf::Text text;
        sf::Texture serce;
        serce.loadFromFile("hp.png");
        font.loadFromFile("arial.ttf");
        
        text.setString("Restart");
        text.setFont(font);
        text.setCharacterSize(50);
        text.setPosition(315, 400);

        sf::Sprite hp(serce);
        

        Gracz g1(200, 200,1);
        Gracz g2(200, 600,2);
        sf::RectangleShape granica;
        granica.setFillColor(sf::Color::Yellow);
        granica.setPosition(400, 400);
        granica.setSize({800, 20});
        granica.setOrigin(400, 10);

        std::vector<Pocisk>p1 = {};
        std::vector<Pocisk>p2 = {};
        std::deque<sf::Sprite>h1 = {};
        std::deque<sf::Sprite>h2 = {};
        
        for (int i = 0; i < 5; i++)
        {
            hp.setPosition(55 * i, 0);
            h1.push_back(hp);
            hp.setPosition(55 * i+525, 745);
            h2.push_back(hp);
        }

        while (window.isOpen())
        {
            window.clear();

            sf::Vector2i pos = sf::Mouse::getPosition(window); //ALBO BEZ WINDOW
            auto translated_pos = window.mapPixelToCoords(pos);
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space && !(g1.czy_koniec() || g2.czy_koniec()) && p1.size() < 3)
                    p1.emplace_back(g1.pozycja().x, g1.pozycja().y, 1);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(g1.czy_koniec() || g2.czy_koniec()) && p2.size() < 3)
                    p2.emplace_back(g2.pozycja().x, g2.pozycja().y, 2);
            }

                      
            g1.ruch();
            g2.ruch();

            if (g1.czy_koniec() || g2.czy_koniec())
            {     
                window.clear();
                window.draw(text);
                window.draw(granica);
                window.draw(g1);
                window.draw(g2);
                window.display();

                    if(text.getGlobalBounds().contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
                        goto start;
            }

            else if (!(g1.czy_koniec() || g2.czy_koniec()))
            {
                for (int i = 0; i < p1.size(); i++)
                {
                    window.draw(p1[i]);
                        p1[i].ruch();
                        czy_kolizja(g2, p1[i],h1,h2);
                        if (p1[i].gora() > 800)
                            p1.erase(p1.begin() + i);
                }

                for (int i = 0; i < p2.size(); i++)
                {
                    window.draw(p2[i]);
                    p2[i].ruch();
                    czy_kolizja(g1, p2[i],h1,h2);
                    if (p2[i].dol() < 0)
                        p2.erase(p2.begin() + i);
                }

                for (auto i : h1)
                    window.draw(i);
                for (auto i : h2)
                    window.draw(i);

                window.draw(granica);
                window.draw(g1);
                window.draw(g2);
                window.display();
            }
        }

}