#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

int reflection(int num){
    string numStr = to_string(num);
    string result;

    for(int i = 0; i < numStr.size(); i++){
        result.insert(0, 1, numStr[i]);
    }

    return stoi(result);
}

int main() {
    ifstream numbers("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\Arkusz 06-2022\\DANE\\liczby.txt");

    int num, reflected, diff;
    int biggestDiff, diffNum;

    while(numbers >> num){
        reflected = reflection(num);
        diff = abs(reflected - num);
        if(diff > biggestDiff) {
            biggestDiff = diff;
            diffNum = num;
        }
    }

    cout << "liczba: " << diffNum << " roznica: " << biggestDiff;
}