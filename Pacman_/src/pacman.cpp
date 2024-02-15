//
//  pancman.cpp
//  
//
//  Created by YuYao Tu on 9/18/23.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Global.hpp"
#include "pacman.hpp"
#include "Ghost.hpp"
#include "Collision.hpp"


Pacman::Pacman(){
    position.x = 0;
    position.y = 0;
    pacmanSpeed = 5;
    direction = 0;
}
Position Pacman::getPosition(){
    return position;
}

void Pacman::setPosition(int x, int y){
    position.x = x;
    position.y = y;
}


void Pacman::draw(sf::RenderWindow& myWindow){

    if(!texture.loadFromFile("/Users/yuyaotu/Desktop/myGithubRepo/FinalProject/src/pacman.png")) {
        // 处理加载失败的情况
        // 可以选择使用默认图像或输出错误消息
    }
    sprite.setPosition(position.x, position.y);
    sprite.setTexture(texture);
    myWindow.draw(sprite);
}
void Pacman::update(std::array<std::array<Cell, 20>,21>& outputMap, Pacman& pacman){
    char pacmanSpeed = 5;
    int indicator;
    bool wall1, wall2, wall3, wall4;
    wall1 = collision(false, false, position.x, position.y - pacmanSpeed, outputMap); //Check if the cell bove is wall
    wall2 = collision(false, false, position.x, position.y + pacmanSpeed, outputMap); //Check if the cell below is wall
    wall3 = collision(false, false, position.x - pacmanSpeed, position.y, outputMap); //Check if the cell to the left is wall
    wall4 = collision(false, false, position.x + pacmanSpeed, position.y, outputMap); //Check if the cell to the right is wall
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        if(wall1 == 0){
            direction = 1;
            position.y -= pacmanSpeed;
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        if(wall2 == 0){
            direction = 2;
            position.y += pacmanSpeed;
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        if(wall3 == 0){
            direction = 3;
            position.x -= pacmanSpeed;
        }
    }
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        if (wall4 == 0){
            direction = 4;
            position.x += pacmanSpeed;
        }
    }
    
    if(position.x <= -30){ //-30 as -cell size
        position.x = 570 - pacmanSpeed; //600 as the map width
    }
    else if(position.x >= 570){
        position.x = pacmanSpeed - 30;
    }
}
    
void Pacman::initialPos(std::vector<std::string> map_script, Pacman& pacman){
    for (int a = 0; a < 21; a++)
    {
        for (int b = 0; b < 20; b++)
        {
            if (map_script[a][b] == 'P')
            {
                pacman.setPosition(30*b, 30*a);
            }
        }
    }
}
int Pacman::eatPellet(std::array<std::array<Cell, 20>,21>& outputMap, Pacman& pacman){
    char pacmanSpeed = 5;
    int indicator;
    int pelletEaten = 0;
    if (collision(true, false, position.x, position.y, outputMap) == false){
        pelletEaten += 1;
    }
    return pelletEaten;
}
void Pacman::handleGameOver(Pacman& pacman,Ghost& ghost) {
    if (pacman.getPosition().y ==  ghost.getPosition().y
        )
    {
        // 如果 Pacman 和 Ghost 位置重叠，游戏结束
        std::cout<< "Game over " << std::endl;
        return exit(1);
    }
  
}



