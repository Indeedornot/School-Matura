#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//+/- 10 min - najpierw megeSort

const int n = 100;
const int numLimit = 1000;

struct NumSum {
    int num, sum;
};

vector<NumSum> mergeSort(vector<NumSum> a, vector<NumSum> b){
    if(a.empty()) return b;
    if(b.empty()) return a;

    vector<NumSum> result;
    int ai = 0, bi = 0;
    while( ai < a.size() && bi < b.size() ){
        if(a[ai].sum < b[bi].sum){
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

vector<NumSum> sort(vector<NumSum> nums){
    if(nums.empty() || nums.size() == 1) return nums;

    vector<NumSum> a(nums.begin(), nums.begin() + nums.size() / 2);
    vector<NumSum> b(nums.begin() + nums.size() / 2 + 1, nums.end());

    return mergeSort(sort(a), sort(b));
}

void print(vector<NumSum> a){
    for(auto i : a){
        cout << i.num << " " << i.sum << endl;
    }
}

int sumNum(int a){
    string aS = to_string(a);
    int result = 0;
    for(int i = 0; i < aS.size(); i++){
        result += aS[i] - '0';
    }

    return result;
}

NumSum pairSumNum(int a){
    return {a, sumNum(a)};
}

int main() {
    vector<NumSum> nums;
    srand(time(nullptr));

    for(int i = 0; i < n; i++){
        nums.push_back(pairSumNum(rand() % numLimit));
    }

    vector<NumSum> result;
    result = sort(nums);

    print(result);
}