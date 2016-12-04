#ifndef __INTERFACE_H__
#define __INTERFACE_H__
#include <string>
#include <vector>
using namespace std;

struct Node {
    string spotName;
    string location;
    string phoneNumber;
    Node(string _spotName, string _location, string _phoneNumber) : 
         spotName(_spotName), location(_location), phoneNumber(_phoneNumber) {}
};

class Graph {
public:
    Graph(const string& filename);
    /*
    ** Pre: the name of scenery spot should exist; if not, enter a loop until the name exists;
    ** Post: querry the scenery spot by its name;
    */
    Node* querySpot(const string& spotName );

    /*
    ** Pre: the name of scenery spot should exist; if not, enter a loop until the name exists;
    ** Post: find the shortest path using Dijkstra's algorithm; return a vector containing the spots and the distance on the way;
    ** vector< pair<spotName, distance> >, while spotName is a string, distance is an integer
    */
    vector<pair<string, int> > findPath(const string& startSpot, const string& endSpot );

    /*
    ** Post: if the spot exists, return true; Otherwise, return false;
    */
    bool spotExist(const string& spotName );

    /*
    ** Post: print the info of spot;
    */
    void showSpot(const Node& spot );

    /*
    ** Post: print the scenery spots and the distance on the way;
    */
    void showPath(vector<pair<string, int> > path );

    /*
    ** Pre: the name of scenery spot should exist; if not, enter a loop until the name exists;
    ** Post: map the name of scenery spot into serial number
    */
    int getIndex(const string& spotName );

    vector<Node> _spot;
    int _adjacency[20][20];
    int count = 10;
};
#endif
