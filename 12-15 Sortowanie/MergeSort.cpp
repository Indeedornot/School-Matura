#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


//+/- 30 minut
using namespace std;

const int n = 100;
const int numLimit = 1000;

vector<int> mergeSort(vector<int> a, vector<int> b){
    if(a.empty()) return b;
    if(b.empty()) return a;

    vector<int> result;
    int ai = 0, bi = 0;
    while( ai < a.size() && bi < b.size() ){
        if(a[ai] < b[bi]){
            result.push_back(a[ai]);
            ai++;
        } else {
            result.push_back(b[bi]);
            bi++;
        }
    }

    if(ai == a.size()) result.insert(result.end(),b.begin() + bi, b.end());
    if(bi == b.size()) result.insert(result.end(), a.begin() + ai, a.end());

    return result;
}

vector<int> sort(vector<int> nums){
    if(nums.empty() || nums.size() == 1) return nums;

    vector<int> a(nums.begin(), nums.begin() + nums.size() / 2);
    vector<int> b(nums.begin() + nums.size() / 2 + 1, nums.end());

    return mergeSort(sort(a), sort(b));
}

void print(vector<int> a){
    for(auto i : a){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums;
    srand(time(NULL));

    for(int i = 0; i < n; i++){
        nums.push_back(rand() % numLimit);
    }

    vector<int> result;
    result = sort(nums);

    print(result);
}