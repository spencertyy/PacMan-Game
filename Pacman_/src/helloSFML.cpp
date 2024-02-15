#include <SFML/Graphics.hpp>
#include <array>
#include <chrono>
#include <ctime>
#include "Global.hpp"
#include "pacman.hpp"
#include "ProcessScript.hpp"
#include "DrawMap.hpp"
#include "Ghost.hpp"
#include "Collision.hpp"
#include <iostream>
#include <chrono>
#include <thread>


int main()
{
    
    // create the window
    sf::RenderWindow window(sf::VideoMode(600 , 630), "PacMan");
    sf::Vector2f pacmanPosition; // Pacman 的位置
    sf::Vector2f ghostPosition;  // Ghost 的位置
    bool gameOver = false;

    // run the program as long as the window is open
    std::vector<std::string> map_script={
    
    "####################",
    "#..................#",
    "#.#...#.####.###...#",
    "#.##.##.#....#  #..#",
    "#.#####.#....#   #.#",
    "#.#.#.#.#....#   #.#",
    "#.#.#.#.####.#   #.#",
    "#.#.#.#....#.#   #.#",
    "#.#...#..G.#.#  #..#",
    "#.#...#.####.###...#",
    "....................",
    "#.####.####.#.####.#",
    "#.#....#  #.#.#  #.#",
    "#.#....#  #.#.#  #.#",
    "#.####.#  #.#.#  #.#",
    "#.#  #.#  #.#.#  #.#",
    "#.#  #.#  #.#.#  #.#",
    "#.#  #.#  #.#.#  #.#",
    "#.####.####.#.####.#",
    "#........P.........#",
    "####################"};
    
    Pacman pacman;
    Ghost ghost;
    pacman.initialPos(map_script, pacman);
    ghost.initialPos(map_script, ghost);
    std::array<std::array<Cell, 20>, 21> map;
    map = ProcessScript(map_script);


    window.setFramerateLimit(60);
   while (window.isOpen())
   {
       sf::Event event;
       while (window.pollEvent(event))
       {
           if (event.type == sf::Event::Closed)
               window.close();
       }
       
       ghost.update(map, ghost,pacman);
       pacman.update(map, pacman);
       int pelletEaten = pacman.eatPellet(map, pacman);
       
       
       // Clear the window
       window.clear();
       
       drawMap(map, window);
       
       
       
       pacman.setPosition(pacman.getPosition().x, pacman.getPosition().y);
       std::cout << "the current y position of pacman : " << pacman.getPosition().x << "and "<<ghost.getX()<< "\n";
       pacman.draw(window);
       
       ghost.setPosition(ghost.position.x, ghost.position.y);
       std::cout << "the current y position of ghost : " << ghost.position.x << "\n";
       ghost.draw(window);
       
       if (ghost.position.x > pacman.getPosition().x - 30 && ghost.position.x < pacman.getPosition().x + 30){
           if (ghost.position.y > pacman.getPosition().y - 30 && ghost.position.y < pacman.getPosition().y + 30){
               gameOver = true;
           }
       }
       
       if (gameOver) {
           sf::Texture gameOverTexture;
           if (!gameOverTexture.loadFromFile("/Users/yuyaotu/Desktop/myGithubRepo/FinalProject/src/gameover.png")) {
               // 处理加载失败的情况
           }
           sf::Sprite gameOverSprite;
           gameOverSprite.setTexture(gameOverTexture);
           window.draw(gameOverSprite);
           window.display();
           std::this_thread::sleep_for(std::chrono::seconds(5));
           exit(1);
       }
       
       window.display();
       bool winGame = true;
       if(winGame){
           for(int a = 0; a < 20 ; a++){
               for(int b = 0; b < 21; b++){
                   if(map[a][b] == Cell::Pellet){
                       winGame = false;
                       break;
                   }
               }
               if (winGame == false)
               {
                   break;
               }
           }
           if (winGame == true)
           {
               sf::Texture gameOverTexture;
               if (!gameOverTexture.loadFromFile("/Users/yuyaotu/Desktop/myGithubRepo/FinalProject/src/youwin.png")) {
                   // 处理加载失败的情况
               }
               
               sf::Sprite gameOverSprite;
               gameOverSprite.setTexture(gameOverTexture);
               gameOverSprite.setPosition(0, 100);
               window.draw(gameOverSprite);
               window.display();
               std::this_thread::sleep_for(std::chrono::seconds(8));
               exit(1);
           }
               
           }
       
   }
   return 0;
}
           





