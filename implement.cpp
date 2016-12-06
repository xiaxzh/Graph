#ifndef __IMPLEMENT_CPP_
#define __IMPLEMENT_CPP_
#include "interface.h"
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

Node* Graph::querySpot(const string& spotName) {
    for (auto &i : _spot)
        if (i.spotName == spotName) {
            cout << &i << endl;
            return &i;
        }
}

vector<pair<string, int> > Graph::findPath(const string& startSpot, const string& endSpot) {
    int source = getIndex(startSpot);
    int end = getIndex(endSpot);
    int distance[20];
    int v, w;
    string path[20];
    bool found[20];
    for (v = 0; v < count; ++v) {
        if (v == source)  continue;
        found[v] = false;
        distance[v] = _adjacency[source][v];
            if (distance[v] != 10000) {
            stringstream ss;
            ss << source << ' ';
            path[v] += ss.str();
        }
    }

    found[source] = true;
    distance[source] = 0;
    
    for (int i = 0; i < count; ++i) {
        int min = 99999;
        for (w = 0; w < count; ++w)
            if (!found[w] && distance[w] < min && distance[w] != 10000) {
                v = w;
                min = distance[w];
            }
        found[v] = true;
        cout << "Next shortest : " << v << endl;
        for (w = 0; w < count; ++w)
            if (!found[w] && _adjacency[v][w] != 10000 && min + _adjacency[v][w] < distance[w]) {
                distance[w] = min + _adjacency[v][w];
                cout << "update : " << w << endl;
                cout << "distance from " << source << "to " << w << "is " << distance[w] << endl;
                stringstream ss;
                ss << v << ' ';
                path[w] = path[v] + ss.str();
            }
    }

    stringstream ss;
    ss << end;
    path[end] += ss.str();

    vector<pair<string, int> > ret;
    for (unsigned i = 0; i < path[end].size() - 2; ++i)
        if (path[end][i] == ' ')  continue;
        else {
            int current = path[end][i]-'0';
            int next = path[end][i+2]-'0';
            ret.push_back(make_pair(getSpotName(current), _adjacency[current][next]));
        }
    ret.push_back(make_pair(getSpotName(end), 0));
    return ret;
}

bool Graph::spotExist(const string& spotName) {
    for (int i = 0; i < count; i++) {
        if (_spot[i].spotName == spotName) {
            return true;
        }
    }
    return false;
}

void Graph::showSpot(const Node & spot) {
    printf("Info:\n");
    printf("--------------------------------------\n");
    printf("���ƣ�\t%s\n", spot.spotName.c_str());
    printf("�ص㣺\tj%s\n", spot.location.c_str());
    printf("�绰��\t%s\n", spot.phoneNumber.c_str());
}

void Graph::showPath(vector<pair<string, int> > path) {
    printf("Path:\n");
    printf("--------------------------------------\n");
    for (unsigned i = 0; i < path.size() - 1; i++) {
        printf("%s--", path[i].first.c_str());
        printf("%4d--", path[i].second);
        if (i % 3 == 2)
            printf("\n");
    }
    printf("%s\n", path[path.size() - 1].first.c_str());
}


#endif
