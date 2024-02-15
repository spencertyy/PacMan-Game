//
//  ProcessScript.hpp
//  testSFML
//
//  Created by YuYao Tu on 9/20/23.
//


#ifndef ProcessScript_hpp
#define ProcessScript_hpp
#include <string>
#include "Global.hpp"
#include <stdio.h>
#include "pacman.hpp"
std::array<std::array<Cell, 20>,21> ProcessScript (std::vector<std::string> map_script);

#endif /* ProcessScript_hpp */
