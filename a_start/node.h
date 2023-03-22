//
// Created by peng liu on 3/20/23.
//

#ifndef AS_NODE_H
#define AS_NODE_H
#include <string>

class Node {


public:

    std::string id;
    double g_cost;
    double h_cost;

    double f_cost;
};




#endif //AS_NODE_H