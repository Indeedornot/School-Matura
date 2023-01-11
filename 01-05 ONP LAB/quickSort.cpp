#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> quickSort(vector<int> nums){
    if(nums.empty() || nums.size() == 1) return nums;

    int pivot = nums.size() / 2;
    vector<int> smaller;
    vector<int> bigger;

    for(int i = 0; i < nums.size(); i++){
        if(i == pivot) continue;

        if(nums[pivot] > nums[i]){
            smaller.push_back(nums[i]);
        }
        else{
            bigger.push_back(nums[i]);
        }
    }

    vector<int> result;

    smaller = quickSort(smaller);
    bigger = quickSort(bigger);

    result.insert(result.end(), smaller.begin(), smaller.end());
    result.push_back(nums[pivot]);
    result.insert(result.end(), bigger.begin(), bigger.end());

    return result;
}

void print(vector<int> a){
    for(auto i: a){
        cout << i << endl;
    }
}

const int n = 100;
const int limit = 1000;

int main() {
    srand(time(nullptr));

    vector<int> nums;
    for(int i = 0; i < n; i++){
        nums.push_back(rand() / limit);
    }

    vector<int> result = quickSort(nums);

    print(result);
}