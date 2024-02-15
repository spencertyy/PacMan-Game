//
//  Ghost.hpp
//  testSFML
//
//  Created by YuYao Tu on 9/19/23.
//

#ifndef Ghost_hpp
#define Ghost_hpp
#include <iostream>
#include <array>
#include "Global.hpp"
#include "Collision.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdio.h>
#include "pacman.hpp"

class Ghost{
    int direction;
    Position target;
    int ghostSpeed;
private:
    float x, y;  // Ghost 的位置
    float speed=2.0f;// 移动速度
    sf::Texture texture; // 纹理用于存储图像
    sf::Sprite sprite; // 精灵用于显示图像
public:
    Position position;
    Position getPosition();
    void setPosition(int x, int y);
    Ghost();
    float getDistance (int direction, Pacman& pacman);
    void update(std::array<std::array<Cell, 20>, 21>& outputMap, Ghost& ghost, Pacman& pacman);
    void draw(sf::RenderWindow& myWindow);
    void move(float deltaTime);
    void initialPos(std::vector<std::string> map_script, Ghost& ghost);
    
    float getX() const { return x; }
    float getY() const { return y; }
};
#endif /* Ghost_hpp */
