#pragma once
#include "interface.h"
class UI {
public:
    UI() : m_graph("./input") {}
    void printMenu();
    void startUI();
    void select();
    void showAllSpot();
    void querySpot();
    void findPath();
    Graph m_graph;
};
