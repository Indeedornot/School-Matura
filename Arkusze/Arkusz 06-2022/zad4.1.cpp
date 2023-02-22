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

    int num, reflected;
    vector<int> divisibleBy17;

    while(numbers >> num){
        reflected = reflection(num);
        if(reflected % 17 == 0){
            divisibleBy17.push_back(reflected);
        }
    }

    for(int i = 0; i < divisibleBy17.size(); i++){
        cout << divisibleBy17[i] << endl;
    }
}