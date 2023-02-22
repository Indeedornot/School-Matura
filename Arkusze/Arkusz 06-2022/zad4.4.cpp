#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

//podchwytliwe
int main() {
    ifstream numbers("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\Arkusz 06-2022\\DANE\\liczby.txt");

    int num;
    map<int, int> numCount;
    while(numbers >> num){
        if(numCount.count(num) == 0){
            numCount[num] = 1;
        } else {
            numCount[num] += 1;
        }
    }

    vector<int> twoTimes;
    vector<int> threeTimes;
    for(auto i : numCount){
        if(i.second == 2){
            twoTimes.push_back(i.first);
        } else if(i.second == 3){
            threeTimes.push_back(i.first);
        }
    }

    cout << "Rozne: " << numCount.size() << endl;
    cout << "Dwa: " << twoTimes.size() << endl;
    cout << "Trzy: " << threeTimes.size() << endl;
}