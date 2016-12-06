#include "interface.h"
#include <iostream>
#include <string>
#include <fstream>

Graph::Graph(const string& filename) {
    ifstream in(filename, ios::in);
    int n = 0, m = 0;
    in >> n >> m;
    int origin = 0, target = 0, distance = 0;
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 20; ++j)
            _adjacency[i][j] = 10000;
    while (m--) {
        in >> origin >> target >> distance;
        _adjacency[origin][target] = distance;
        _adjacency[target][origin] = distance;
    }
    _spot.push_back(Node("cateen", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "None"));
    _spot.push_back(Node("gogo", "中国广东省广州市番禺区大学城中二横路1号", "+86 20-39330333"));
    _spot.push_back(Node("public", "中国广东省广州市番禺区外环东路132号中山大学东校区", "None"));
    _spot.push_back(Node("SDCS", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "None"));
    _spot.push_back(Node("north", "中国广东省广州市番禺区外环东路132号中山大学东校区", "None"));
    _spot.push_back(Node("forest", "中国广东省广州市番禺区大学城谷河南路与逸仙大道交叉口西南100米", "None"));
    _spot.push_back(Node("administration", "中国广东省广州市番禺区外环东路132号中山大学东校区", "None"));
    _spot.push_back(Node("library", "中国广东省广州市番禺区新造镇广州大学城外环东路132号", "+86 20-39332622"));
    _spot.push_back(Node("gym", "中国广东省广州市番禺区外环东路132号中山大学广州东校区", "None"));
    _spot.push_back(Node("dormitory", "中国广东省广州市番禺区贝岗村大街与青蓝街交叉口东200米", "None"));
}

int Graph::getIndex(const string& spotName) {
    for (int i = 0; i < count; ++i) {
        if (_spot[i]._spotName == spotName) {
            return i;
        }
    }
    return -1;
}

string Graph::getSpotName(int index) {
    return _spot[index].spotName;
}
