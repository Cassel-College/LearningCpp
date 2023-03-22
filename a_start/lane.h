//
// Created by peng liu on 3/20/23.
//

#ifndef AS_LANE_H
#define AS_LANE_H

#include <string>
#include <vector>
#include <memory>

#include "node.h"

class Lane {
public:

    Lane();

    Lane(std::string id, std::string name);

    Lane(std::string id, std::string name, Node* parent);

    Lane(std::string id, std::string name, std::vector<std::string> next_lanes, std::vector<std::string> prev_lanes);

    bool IsEmpty();

    std::string GetId();

    std::string GetName();

    std::shared_ptr<Node> GetParent();

    std::vector<std::string> GetNextLanes();

    std::vector<std::string> GetPrevLanes();

    void SetId(std::string id);

    void SetName(std::string name);

    bool SetNode(std::shared_ptr<Node> node);

    void SetNextLanes(std::vector<std::string> next_lanes);

    void SetPrevLanes(std::vector<std::string> prev_lanes);

private:
    std::shared_ptr<Node> node;
    std::string id;
    std::string name;
    std::vector<std::string> next_lanes;
    std::vector<std::string> prev_lanes;
};


#endif //AS_LANE_H