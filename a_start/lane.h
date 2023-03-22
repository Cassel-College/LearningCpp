//
// Created by peng liu on 3/20/23.
//

#ifndef AS_LANE_H
#define AS_LANE_H


#include <string>
#include <vector>

class Lane {
public:

private:
    std::string id;
    double cost = 1;
    std::vector<std::string> next_lanes;
    std::vector<std::string> prev_lanes;
};


#endif //AS_LANE_H