#include "interface.h"
#include <iostream>
#include <fstream>

Graph::Graph(const string& filename) {
    ifstream in(filename, ios::in);
    int n = 0, m = 0;
    in >> n >> m;
    int origin = 0, target = 0, distance = 0;
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j)
            _adjacency[i][j] = -1;
    while (m--) {
        in >> origin >> target >> distance;
        _adjacency[origin][target] = distance;
        _adjacency[target][origin] = distance;
    }
    _spot.push_back(Node("cateen", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "123"));
    _spot.push_back(Node("gogo", "中国广东省广州市番禺区大学城中二横路1号", "123"));
    _spot.push_back(Node("public", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "123"));
    _spot.push_back(Node("SDCS", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "123"));
    _spot.push_back(Node("north", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "123"));
    _spot.push_back(Node("forest", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "123"));
    _spot.push_back(Node("administration", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "123"));
    _spot.push_back(Node("library", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "123"));
    _spot.push_back(Node("gym", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "123"));
    _spot.push_back(Node("dormitory", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "123"));
}
