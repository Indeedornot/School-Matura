#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>


using namespace std;

int main() {
    int inputStart;
    cin >> inputStart;

    set<int> possibleEnds;
    ifstream  file("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\01-18 Grafy\\84.txt");

    int pointCount, connectionsCount;
    file >> pointCount >> connectionsCount;

    int start, end;
    while(!file.eof() && possibleEnds.size() < pointCount - 1){
          file >> start >> end;
          if(start == inputStart){
              possibleEnds.insert(end);
          }

          if(end == inputStart){
              possibleEnds.insert(start);
          }
    }

    for(auto i : possibleEnds){
        cout << i << endl;
    }
}