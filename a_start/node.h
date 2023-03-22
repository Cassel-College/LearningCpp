//
// Created by peng liu on 3/20/23.
//

#ifndef AS_NODE_H
#define AS_NODE_H
#include <string>

class Node {

public:

    Node();
    Node(std::string name);
    Node(std::string name, Node* parent);
    Node(std::string id, std::string name, int g_cost, int h_cost, int f_cost);

    std::string GetId();

    std::string GetName();

    double GetGCost();

    double GetHCost();

    double GetFCost();

    void SetId(std::string id);

    void SetName(std::string name);

    void SetGCost(double g_cost);

    void SetHCost(double h_cost);

    void SetFCost(double f_cost);

private:

    std::string id;
    std::string info;
    double g_cost;
    double h_cost;
    double f_cost;
};




#endif //AS_NODE_H