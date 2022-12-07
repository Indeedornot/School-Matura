#include <iostream>
#include <string>
#include <vector>
#include <random>

//1h 5min + pomoc internetu
/*
    Napisz program wypisujący z ciągu n liczb całkowitych wszystkie podciągi spójne o podanej (wczytanej) sumie.
    Program napisz tak, aby wykonywał jak najmniej operacji
 */

using namespace std;

void print(vector<int> data){
    for(auto i : data){
        cout << i << " ";
    }
    cout << endl;
}

void subsumVoid(vector<int> num, int index, int sum, vector<int> subset){
    if(sum == 0){
        print(subset);
        return;
    }
    if(sum != 0 && index == num.size()) return;
    if(sum < 0) return;

    //do next
    subsumVoid(num, index + 1, sum, subset);

    //solve yourself
    subset.push_back(num[index]);
    subsumVoid(num, index + 1, sum - num[index], subset);
}

int main(){
    vector<int> arr;
    int sum = 1000;
    for(int i = 0; i < 100; i++){
        arr.push_back(rand() % 1000);
    }

    vector<int> subset;

    subsumVoid(arr, 0, sum, subset);
}