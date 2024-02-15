//
//  pancman.hpp
//  
//
//  Created by YuYao Tu on 9/18/23.
//

#ifndef pacman_hpp
#define pacman_hpp

#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include "Global.hpp"
class Ghost;
class Pacman{
private:
    int pacmanSpeed;
    sf::Texture texture; // 纹理用于存储图像
    sf::Sprite sprite; // 精灵用于显示图像
    float speed = 5.0f;             // Pacman's movement speed
    int direction;
public:
    Position position;
    Pacman();
    Position getPosition();
    void setPosition(int x, int y);
    void draw(sf::RenderWindow& myWindow);
    void update(std::array<std::array<Cell, 20>,21>& outputMap,Pacman& pacman);
    int eatPellet(std::array<std::array<Cell, 20>,21>& outputMap, Pacman& pacman);
    void initialPos(std::vector<std::string> map_script, Pacman& pacman);
    void handleGameOver(Pacman& pacman,Ghost& ghost);
    int getPacmanSpeed(){
        return pacmanSpeed;
    }

};
#endif /* pancman_hpp */
