#ifndef __INTERFACE_H__
#define __INTERFACE_H__

struct Node {
    string spotName;
    string location;
    string phoneNumber;
    // vector<int, int> neighbor; // vector<int index, int distance>
    Node(string _spotName, string _location, string _phoneNumber) : spotName(_spotName),
     location(_location), phoneNumber(_phoneNumber)) {}
};

class Graph {
public:
    Graph(FILE* filePath);
    /*
    ** Pre: the name of scenery spot should exist; if not, enter a loop until the name exists;
    ** Post: querry the scenery spot by its name;
    */
    Node querrySpot(string spotName);

    /*
    ** Pre: the name of scenery spot should exist; if not, enter a loop until the name exists;
    ** Post: find the shortest path using Dijkstra's algorithm; return a vector containing the spots and the distance on the way;
    ** vector<string spotName, int distance>
    */
    vector<string, int> findPath(string startSpot, string endSpot);

    /*
    ** Post: if the spot exists, return true; Otherwise, return false;
    */
    bool spotExist(string spotName);

    /*
    ** Post: print the info of spot;
    */
    void showSpot(Node spot);

    /*
    ** Post: print the scenery spots and the distance on the way;
    */
    void showPath(vector<string, int> path);

    /*
    ** Pre: the name of scenery spot should exist; if not, enter a loop until the name exists;
    ** Post: map the name of scenery spot into serial number
    */
    int getIndex(string spotName);

    vector<Node> _spot;
    int _adjacency[20][20];
};


#endif