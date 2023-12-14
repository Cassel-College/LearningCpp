//
// Created by peng liu on 3/20/23.
//

#ifndef AS_MAP_H
#define AS_MAP_H

#include <map>
#include "lane.h"

class Map {

public:
    Map();

    bool CreateByMapFile(std::string &file_path);

    bool AddLane(Lane &lane);

    Lane GetLane(std::string lane_id);

private:
    std::map<std::string, Lane> maps;
};


#endif //AS_MAP_H
