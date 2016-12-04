#ifndef __IMPLEMENT_CPP_
#define __IMPLEMENT_CPP_
#include "interface.h"
#include <iostream>
#include <sstream>
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
    for (int i = 0; i < path[end].size() - 2; ++i)
        if (path[end][i] == ' ')  continue;
        else {
            int current = path[end][i]-'0';
            int next = path[end][i+2]-'0';
            ret.push_back(make_pair(getSpotName(current), _adjacency[current][next]));
        }
    ret.push_back(make_pair(getSpotName(end), 0));
    return ret;
}

#endif