//
//  Global.hpp
//  testSFML
//
//  Created by YuYao Tu on 9/20/23.
//

#ifndef Global_hpp
#define Global_hpp

#include <stdio.h>
class Global{
    
    int cellSize;
    int mapWidth;
    int mapHeight;
    
public:
    Global ();
    int getCellSize();
    int getMapWidth();
    int getMapHeight();
};

struct Position{
    int x;
    int y;
};

enum Cell{
    Wall,
    Empty,
    Pellet,
    
};
#endif /* Global_hpp */
