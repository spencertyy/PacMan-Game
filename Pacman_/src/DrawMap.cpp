//
//  DrawMap.cpp
//  testSFML
//
//  Created by YuYao Tu on 9/20/23.
//
#include <SFML/Graphics.hpp>
#include "Global.hpp"
#include "DrawMap.hpp"
#include "pacman.hpp"
#include "ProcessScript.hpp"
#include "Ghost.hpp"
Global global = Global();


sf::RectangleShape rectangle;
sf::CircleShape pellet(3.f);
sf::RectangleShape door;


void drawMap (std::array<std::array<Cell, 20>,21> outputMap, sf::RenderWindow& window){
    int cellSize = 30;
    int dotRadius = 5;
    for(int a = 0; a < 20 ; a++){
        for(int b = 0; b < 21; b++){
            switch (outputMap[a][b]) {
                case Cell::Wall:
                {
                    rectangle.setPosition(a* global.getCellSize(), b*global.getCellSize());
                    rectangle.setSize(sf::Vector2f(global.getCellSize(), global.getCellSize()));
                    rectangle.setFillColor(sf::Color::Blue);
                    window.draw(rectangle);
                    break;
                }

                case Cell::Pellet:
                {
                    pellet.setPosition(a* global.getCellSize() + 10, b*global.getCellSize() + 10);
                    pellet.setFillColor(sf::Color::Yellow);
                    window.draw(pellet);
                    break;
                }
            }
                
            }
        }
    }
