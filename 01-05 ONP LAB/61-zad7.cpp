#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>

using namespace std;

// UNFINISHED
const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                         't', 'u', 'v', 'w', 'x', 'y', 'z'};

int main() {
    ifstream file("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\01-05 ONP LAB\\zad7.txt");
    vector<vector<string>> allLines;
    vector<string> vLine;
    string sLine, sWord;
    stringstream ssLine;
    int longestLine = 0;

    while (getline(file, sLine)) {
        ssLine << sLine;
        while (!ssLine.eof()) {
            ssLine >> sWord;
            vLine.push_back(sWord);
        }

        allLines.push_back(vLine);
        if (vLine.size() > longestLine) {
            longestLine = vLine.size();
        }
        vLine = {};
        ssLine.clear();
    }

    map<char, queue<vector<string>>> buckets;
    for (char letter: alphabet) {
        buckets[letter] = {};
    }

    vector<vector<string>> considered;
    int longestWord = 0;
    char backChar;
    vector<string> wLine;
    vector<char> bucks;
    for (int i = longestLine - 1; i <= 0; i--) {
        for (int j = 0; j < allLines.size(); j++) {
            if (allLines[j].size() < i + 1) continue;
            considered.push_back(allLines[j]);
            if (allLines[j][i].size() > longestWord) {
                longestWord = allLines[j][i].size();
            }
            allLines.erase(allLines.begin()+j);
        }

        for (int j = longestWord - 1; j >= 0; j--) {
            for (int el = 0; el < considered.size(); el++) {
                wLine = considered[el];

                backChar = wLine[i][j];
                buckets[backChar].push(wLine);
                considered.erase(considered.begin() + el);
                bucks.push_back(backChar);
            }

            for (auto b: bucks)
                for (int c = 0; c < buckets[b].size(); c++) {
                    considered.push_back(buckets[b].front());
                    buckets[b].pop();
                    c--;
                }
        }


        for (auto consd: considered) {
            allLines.push_back(consd);
        }

        considered = {};
    }

    for(auto i : allLines){
        for(auto j : i){
            cout << j << " ";
        }

        cout << endl;
    }
}