#include "UI.h"
#include <iostream>

void UI::printMenu() {
    printf("Menu\n");
    printf("--------------------------------------\n");
    printf("a.Print the menubar\n");
    printf("b.Show all the spot\n");
    printf("c.Query a spot by name\n");
    printf("d.Find the path between two spots\n");
    printf("--------------------------------------\n");
}

void UI::startUI() {
    printMenu();
    while (true) {
        select();
    }
}

void UI::select() {
    printf("[inputMenu] # ");
    string tempInput;
    cin >> tempInput;
    switch (tempInput[0])
    {
    case 'a':
        printMenu();
        break;
    case 'b':
        showAllSpot();
        break;
    case 'c':
        querySpot();
        break;
    case 'd':
        findPath();
        break;
    default:
        printf("[error] Wrong Input\n");
        break;
    }
}

void UI::showAllSpot() {
    printf("Show All Spot:\n");
    printf("--------------------------------------\n");
    for (int i = 0; i < m_graph._spot.size(); i++) {
        printf("%d.\t%s\n", i, m_graph._spot[i].spotName.c_str());
    }
    printf("--------------------------------------\n");
}

void UI::querySpot() {
    printf("\n[querySpot] please input the spot name.\n");
    printf("[input] # ");
    string tempSpot;
    std::cin >> tempSpot;
    if (m_graph.spotExist(tempSpot)) {
        m_graph.showSpot(* m_graph.querySpot(tempSpot));
    }
}

void UI::findPath() {
    printf("\n[findPath] please input the start spot's name.\n");
    printf("[input] # ");
    string firSpot;
    std::cin >> firSpot;
    while (! m_graph.spotExist(firSpot)) {
        printf("[error] Wrong input, the spot doesn't exist. Please input again.\n");
        printf("[input] # ");
        std::cin >> firSpot;
    }
    printf("\n[findPath] please input the end spot's name.\n");
    printf("[input] # ");
    string endSpot;
    std::cin >> endSpot;
    printf("haha\n");
    while (!m_graph.spotExist(endSpot)) {
        printf("[error] Wrong input, the spot doesn't exist. Please input again.\n");
        printf("[input] # ");
        std::cin >> endSpot;
    }

    printf("[findpath] please input the vehicle you use.\n");
    printf("1.On foot.\n");
    printf("2.By car.\n");
    printf("[input] # ");
    string vehicle;
    std::cin >> vehicle;
    while (vehicle[0] != '2' && vehicle[0] != '1') {
        printf("[error] Wrong input, please input '1' or '2'.\n");
        std::cin >> vehicle;
    }
    if (vehicle[0] == '1')
        m_graph.change2walk();
    else if (vehicle[0] == '2')
        m_graph.change2drive();
   
    m_graph.showPath(m_graph.findPath(firSpot, endSpot));

}
