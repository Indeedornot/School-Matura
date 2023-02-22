#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

bool isPrime(int x){
    if(x == 1) return false;
    if(x == 2 || x == 3) return true;

    for(int i = 2; i < sqrt(x) + 1; i++){
        if(x % i == 0) return false;
    }

    return true;
}

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
    vector<int> prime;
    while(numbers >> num){
        if(!isPrime(num)) continue;
        reflected = reflection(num);

        if(!isPrime(reflected)) continue;
        prime.push_back(num);
    }

    for(auto i : prime){
        cout << i << endl;
    }
}