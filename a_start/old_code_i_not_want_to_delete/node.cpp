//
// Created by peng liu on 3/20/23.
//

#include "node.h"


Node::Node() {
    id = "";
    name = "";
    g_cost = 0;
    h_cost = 0;
    f_cost = 0;
}

Node::Node(std::string name) {
    id = "";
    this->name = name;
    g_cost = 0;
    h_cost = 0;
    f_cost = 0;
}

Node::Node(std::string name, Node* parent) {
    id = parent->GetId();
    this->name = name;
    g_cost = parent->GetGCost();
    h_cost = parent->GetHCost();
    f_cost = parent->GetFCost();
}

Node::Node(std::string id, std::string name, int g_cost, int h_cost, int f_cost) {
    this->id = id;
    this->name = name;
    this->g_cost = g_cost;
    this->h_cost = h_cost;
    this->f_cost = f_cost;
}

void Node::SetId(std::string id) {
    this->id = id;
}

void Node::SetName(std::string name) {
    this->name = name;
}

void Node::SetGCost(double g_cost) {
    this->g_cost = g_cost;
}

void Node::SetHCost(double h_cost) {
    this->h_cost = h_cost;
}

void Node::SetFCost(double f_cost) {
    this->f_cost = f_cost;
}

std::string Node::GetId() {
    return id;
}

std::string Node::GetName() {
    return name;
}

double Node::GetGCost() {
    return g_cost;
}

double Node::GetHCost() {
    return h_cost;
}

double Node::GetFCost() {
    return f_cost;
}
