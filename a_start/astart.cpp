
#include <algorithm>
#include <future>
#include <iostream>
#include <fstream>
#include <memory>
#include <math.h>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

class Node {
public:
    Node() {};
    int x;
    int y;
    int xFarther;
    int yFarther;
    double g_cost;
    double h_cost;
    double f_cost;

    void showNode() {
        std::cout << "x: " << x << " y: " << y << " g_cost: " << g_cost << " h_cost: " << h_cost << " f_cost: " << f_cost << std::endl;
    }
};

class AStart {

public:
    AStart() {}

    AStart(std::string map_file_path) {
        this->map_file_path = map_file_path;
    }

    ~AStart() {
        this->map.clear();
    }

    void loadMap() {
        if ("" == this->map_file_path) {
            this->map_file_path = "map.txt";
        }
        std::ifstream file(this->map_file_path);
        std::vector< std::vector<int> > map = {};
        int num;
        if (file.is_open()) {
            std::string infos;
            while (std::getline(file, infos)) {
                std::istringstream lineStream(infos);

                std::vector<int> row;
                while (lineStream >> num) {
                    row.push_back(num);
                }

                if (!row.empty()) {
                    this->map.push_back(row);
                }
            }
            file.close();
        } else {
            std::cout << "Unable to open file" << std::endl;
        }
    }

    void showMap() {
        if (0 == this->map.size()) {
            std::cout << "The map is empty." << std::endl;
        } else {
            for (const auto& row : this->map) {
                for (int num : row) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
            }
        }
        this->showMapSize();
    }

    void showMapSize() {
        std::pair<int, int> sizeInfo = this->getMapSzie();
        std::cout << "The map size is " << sizeInfo.first << " * " << sizeInfo.second << std::endl;
    }

    bool setTargetNode(int x, int y, int target) {
        if (this->isEmpty()) {
            return false;
        } else {
            if (x < 0 || x > this->map.size() || y < 0 || y > this->map[0].size()) {
                return false;
            }
        }
        this->map[x][y] = target;
        this->targetX = x;
        this->targetY = y;
        return true;
    }

    bool setStartNode(int x, int y, int target) {
        if (this->isEmpty()) {
            return false;
        } else {
            if (x < 0 || x > this->map.size() - 1 || y < 0 || y > this->map[0].size() - 1) {
                return false;
            }
        }
        this->startX = x;
        this->startY = y;
        return true;
    }

    bool setType(int type) {
        this->type = type;
        return true;
    }

    std::pair<int, int> getMapSzie() {
        return std::make_pair(this->map.size(), this->map[0].size());
    }
    
    bool isEmpty() {
        if (0 == this->map.size()) {
            return true;
        } else {
            if (0 == this->map[0].size()) {
                return true;
            }
        }
        return false;
    }

    std::vector<std::shared_ptr<Node>> getNowNodeNextNodes(std::shared_ptr<Node> nowNode) {

        std::vector<std::shared_ptr<Node>> nextNodes = {};
        std::vector<int> x_bits = {-1, 0, 1, 0};
        std::vector<int> y_bits = {0, 1, 0, -1};

        for (int tempX = 0; tempX < 4; tempX++) {
            int nextX = nowNode->x + x_bits[tempX];
            int nextY = nowNode->y + y_bits[tempX];
            if (nextX < 0 || nextX > this->map.size() - 1 || nextY < 0 || nextY > this->map[0].size() - 1) {
                continue;
            } else {
                std::shared_ptr<Node> new_node = std::make_shared<Node>();

                new_node->x = nextX;
                new_node->y = nextY;

                new_node->xFarther = nowNode->x;
                new_node->yFarther = nowNode->y;

                new_node->g_cost = nowNode->g_cost + 1;
                new_node->h_cost = this->getDistance(new_node);
                new_node->f_cost = (double)(new_node->g_cost) + new_node->h_cost;
                nextNodes.push_back(new_node);
            }
        }
        return nextNodes;
    }

    void addOpenList(std::shared_ptr<Node> node) {
        // node->showNode();
        if (this->isInCloseList(node)) {
            return;
        }
        if (this->IsInBlackList(node)) {
            return;
        }
        int oldFCost = this->isInOpenList(node);
        if (-1 != oldFCost) {
            if (oldFCost > node->g_cost) {
                this->deleteOldNodeByXY(node);
                this->openList.push_back(node);
            }
        } else {
            this->openList.push_back(node);
        }
        return;
    }

    void addCloseList(std::shared_ptr<Node> node) {
        this->closeList.push_back(node);
        this->deleteOldNodeByXY(node);
    }

    int isInOpenList(std::shared_ptr<Node> node) {
        int nodeState = -1;
        for (auto tempNode : this->openList) {
            if (tempNode->x == node->x && tempNode->y == node->y) {
                nodeState = tempNode->g_cost;
                break;
            }
        }
        return nodeState;
    }

    bool deleteOldNodeByXY(std::shared_ptr<Node> node) {
        bool nodeState = false;
        int index = 0;
        for (auto tempNode : this->openList) {
            if (tempNode->x == node->x && tempNode->y == node->y) {
                this->openList.erase(this->openList.begin() + index);
                nodeState = true;
                break;
            }
            index = index + 1;
        }
        return nodeState;
    }

    bool isInCloseList(std::shared_ptr<Node> node) {
        bool nodeState = false;
        for (auto tempNode : this->closeList) {
            if (tempNode->x == node->x && tempNode->y == node->y) {
                nodeState = true;
                break;
            }
        }
        return nodeState;
    }

    bool IsInBlackList(std::shared_ptr<Node> node) {
        bool nodeState = false;
        if (1 == this->map[node->x][node->y]) {
            nodeState = true;
        }
        return nodeState;
    }

    std::shared_ptr<Node> getNextNode() {
        std::shared_ptr<Node> next = nullptr;
        if (this->openList.size() == 0) {
            return nullptr;
        }
        int targetIndex = 0;
        double tempCost = this->openList[0]->f_cost;
        for (int i = 0; i < this->openList.size(); i++) {

            if (this->openList[i]->f_cost <= tempCost) {
                tempCost = this->openList[i]->f_cost;
                targetIndex = i;
            }
        }
        next = this->openList[targetIndex];
        return next;
    }

    double getDistance(std::shared_ptr<Node> node) {
        double distance = 0.0;
        if (type == 0) {
            distance = EuclideanDistance(node->x, node->y, targetX, targetY);
        } else {
            distance = Manhuattan(node->x, node->y, targetX, targetY);
        }
        return distance;
    }

    bool isTarget(std::shared_ptr<Node> nowNode) {
        bool state = false;
        if (nowNode->x == targetX && nowNode->y == targetY) {
            state = true;
        }
        return state;
    }

    std::shared_ptr<Node> creareStartPoint() {
        std::shared_ptr<Node> start = std::make_shared<Node>();
        start->x = startX;
        start->y = startY;
        start->xFarther = -1;
        start->yFarther = -1;
        start->g_cost = 0;
        start->h_cost = this->getDistance(start);
        start->f_cost = start->g_cost + start->h_cost;
        return start;
    }

    void run() {
        // create start point node
        std::shared_ptr<Node> start = this->creareStartPoint();
        // add start node to open list
        this->addOpenList(start);
        bool isFind = false;
        int newNodeSize = 0;
        // while open list is not empty
        while (this->openList.size() > 0) {
            int n1 = this->openList.size();
            std::shared_ptr<Node> nowNode = this->getNextNode();

            if (nowNode != nullptr) {
                nowX = nowNode->x;
                nowY = nowNode->y;
                if (isTarget(nowNode)) {
                    isFind = true;
                    break;
                } else {
                    this->addCloseList(nowNode);
                    std::vector<std::shared_ptr<Node>> nextNodes = getNowNodeNextNodes(nowNode);
                    for (auto nextNode : nextNodes) {
                        this->addOpenList(nextNode);
                    }
                    newNodeSize = nextNodes.size();
                }
            } else {
                std::cout << "open list is empty." << std::endl;
            }
        }
    }

    double Manhuattan(int x1, int y1, int x2, int y2) {
        return (double)(abs(x1 - x2) + abs(y1 - y2));
    }

    double EuclideanDistance(int x1, int y1, int x2, int y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }



    void getPath() {
        return;
    }

    void showPath() {

        std::vector<std::vector<int>> tempOpenList(this->map);
        for (auto node : this->closeList) {
            tempOpenList[node->x][node->y] = 6;

            if (node->x == node->xFarther && node->y == node->yFarther + 1) {
                tempOpenList[node->x][node->y] = 2; // >
            }
            if (node->x == node->xFarther && node->y == node->yFarther - 1) {
                tempOpenList[node->x][node->y] = 3; // <
            }
            if (node->x == node->xFarther + 1 && node->y == node->yFarther) {
                tempOpenList[node->x][node->y] = 4; // ⬇️
            }
            if (node->x == node->xFarther - 1 && node->y == node->yFarther) {
                tempOpenList[node->x][node->y] = 5; // ⬆️
            }

        }
        for (auto node : this->openList) {
            tempOpenList[node->x][node->y] = 7;
        }

         tempOpenList[nowX][nowY] = 8;
        for (int i = 0; i < tempOpenList.size(); i++) {
            for (int j = 0; j < tempOpenList[i].size(); j++) {
                if (tempOpenList[i][j] == 2) {
                    std::cout << "→" << " ";
                } else if (tempOpenList[i][j] == 3) {
                    std::cout << "←" << " ";
                } else if (tempOpenList[i][j] == 4) {
                    std::cout << "↓" << " ";
                } else if (tempOpenList[i][j] == 5) {
                    std::cout << "↑" << " ";
                } else if (tempOpenList[i][j] == 6) {
                    std::cout << "█" << " ";
                } else if (tempOpenList[i][j] == 7) {
                    std::cout << "○" << " ";
                } else if (tempOpenList[i][j] == 8) {
                    std::cout << "●" << " ";
                } else {
                    std::cout << tempOpenList[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }
    }


private:

    int nowX = 0;
    int nowY = 0;

    int type = 0;
    int targetX = 0;
    int targetY = 0;
    int startX = 0;
    int startY = 0;
    std::string map_file_path = "";
    std::vector< std::vector<int> > map;
    std::vector<std::shared_ptr<Node>> openList = {};
    std::vector<std::shared_ptr<Node>> closeList = {};
};


int main() {
    
    int taregtX = 34;
    int targetY = 6;
    int target = -1;
    int startX = 2;
    int startY = 20;

    std::shared_ptr<AStart> astar = std::make_shared<AStart>();
    // set config
    astar->setType(0);

    // set map
    astar->loadMap();
    astar->showMapSize();

    // set target
    if (astar->setTargetNode(taregtX, targetY, target)) {
        std::cout << "set target success" << std::endl;
        // astar->showMap();
    } else {
        std::cout << "set target failed" << std::endl;
    }

    // set start
    if (astar->setStartNode(startX, startY, target)) {
        std::cout << "set start success" << std::endl;
    } else {
        std::cout << "set start failed" << std::endl;
    }
    
    astar->run();
    astar->showPath();

    return 0;
}

