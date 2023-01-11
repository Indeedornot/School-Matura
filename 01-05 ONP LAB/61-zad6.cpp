#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>

using namespace std;


int main() {
    vector<vector<int>> allLines;
    vector<int> vLine;
    string sLine;
    int temp;
    int longestLine = 0;

    set<int> uniqueNums;
    int bucketCount;

    ifstream iStream("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\01-05 ONP LAB\\zad6.txt");

    stringstream sStream;
    while(getline(iStream, sLine)){
        sStream.clear();
        sStream << sLine;

        while(!sStream.eof()){
            sStream >> temp;
            vLine.push_back(temp);
            uniqueNums.insert(temp);
        }

        if(vLine.size() > longestLine) longestLine = vLine.size();
        allLines.push_back(vLine);
        vLine = {};
    }

    map<int, int> NumToBasket;

    bucketCount = uniqueNums.size();
    auto itr = uniqueNums.begin();
    int ind = 0;

    while(ind < bucketCount && itr != uniqueNums.end()){
        NumToBasket[*itr] = ind;
        ind++;
        itr++;
    }

    queue<vector<int>> baskets[bucketCount];
    int backNum, limit;
    for(int i = longestLine - 1; i >= 0; i--){
        limit = allLines.size();
        for(int el = 0; el < limit ; el++){
            auto line = allLines[el];
            if(line.size() - 1 < i) continue;

            backNum = line[i];
            baskets[NumToBasket[backNum]].push(line);
            allLines.erase(allLines.begin()+el);
            el--;
            limit--;
        }

        for(int b = 0; b < uniqueNums.size(); b++){
            for(int c = 0; c < baskets[b].size(); c++){
                allLines.push_back(baskets[b].front());
                baskets[b].pop();
                c--;
            }
        }
    }

    for(auto line: allLines){
        for(int i = 0; i < line.size(); i++){
            cout << line[i] << " ";
        }

        cout << endl;
    }
}