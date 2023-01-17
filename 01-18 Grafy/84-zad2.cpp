#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>

using namespace std;

bool findEnd(vector<pair<int, int>> connections, int end, int start){
    if(connections.empty()) return false;

    bool success;
    for(int i = 0; i < connections.size(); i++){
        auto connection = connections[i];
        if(connection.first == start || connection.second){
            if(connection.first == end || connection.second == end){
                return true;
            }

            connections.erase(connections.cbegin() + i);
            success = findEnd(connections, end, start == connection.first ? connection.second : connection.first);
            if(success) return true;
        }
    }

    return false;
}

int main() {
    int inputStart, inputEnd;
    cin >> inputStart >> inputEnd;

    set<int> possibleEnds;
    ifstream  file("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\01-18 Grafy\\84.txt");

    int pointCount, connectionsCount;
    file >> pointCount >> connectionsCount;

    int start, end;
    vector<pair<int, int>> connections;
    while(!file.eof()){
        file >> start >> end;
        connections.push_back(make_pair(start, end));
    }

    bool success = findEnd(connections, inputEnd, inputStart);
    cout << success;
}