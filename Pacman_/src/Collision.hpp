//
//  Collision.hpp
//  testSFML
//
//  Created by YuYao Tu on 9/21/23.
//

#ifndef Collision_hpp
#define Collision_hpp
#include <array>
#include "Global.hpp"
#include <stdio.h>

bool collision (bool collectPellet, bool useDoor, int x, int y, std::array<std::array<Cell, 20>,21>& outputMap);
#endif /* Collision_hpp */
