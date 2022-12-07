#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

//+/- 30 min - stack overflow
void print(vector<int> data){
    for(auto i: data){
        cout << i << " ";
    }
    cout << endl;
}

bool finished = false;
void divideIntoBills(vector<int> bills, int goal, int index, vector<int> subset){
    if(finished) return;

    if(goal == 0) {
        print(subset);
        finished = true;
        return;
    }

    if(index == bills.size()) return;
    if(goal < 0) return;

    vector<int> usableBills;
    for(int i = index; i < bills.size(); i++){
        if(bills[i] < goal) usableBills.push_back(bills[i]);
    }

    index -= bills.size() - usableBills.size();

    divideIntoBills(usableBills, goal, index + 1, subset);

    subset.push_back(bills[index]);
    divideIntoBills(usableBills, goal - bills[index], index+1, subset);
}

int main() {
    int sum = 1000;
    vector<int> bills;
    vector<int> standardBills = {1,2,3,4,5,10,20,50,100,200};
    int index, standardSize = standardBills.size();
    for(int i = 0; i < 100; i++){
        index = rand() % standardSize;
        bills.push_back(standardBills[index]);
    }

    vector<int> subset;
    divideIntoBills(bills, sum, 0, subset);
}