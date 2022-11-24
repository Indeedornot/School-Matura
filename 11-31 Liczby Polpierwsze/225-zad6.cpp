#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

//36min
/*
    Napisz program sprawdzający czy w tablicy n-elementowej znajduje sie liczba, ktora wystepuje wiecej niz n/4 razy.
    Przygotuj tablice tak, aby byla szansa wystapienia w niej takiej liczby. Przyjmij, że n jest wielokrotnością 4.
    Program powinien wykonywać jak najmniej operacji.
 */
using namespace std;

vector<int> prepareArr(int n, int limit){
    vector<int> numbers;
    int lider = rand() % limit;
    for(int i = 0; i < ceil(n / 4); i++){
        numbers.push_back(lider);
    }
    cout << lider << endl;

    for(int i = 0; i < floor(n/4); i++){
        numbers.push_back(rand());
    }
    return numbers;
}

int lider(vector<int> nums){
    map<int, int> frequency;

    //O(n)
    for(int i = 0; i < nums.size(); i++){
        auto iter = frequency.find(nums[i]);
       if(iter != frequency.end()){
           iter->second += + 1;
       }
       else{
           frequency[i] = 1;
       }
    }

    int lider = 0;
    int count = 0;
    //0(n) worst case
    for(auto i = next(frequency.cbegin(),1); i != frequency.cend(); i = next(i, 1)){
        if(i->second > count){
            count = i->second;
            lider = i->first;
        }
    }

    return lider;
}

int main(){
    vector<int> numbers = prepareArr(1000, 100);

    auto lid = lider(numbers);
    cout << lid << endl;
}