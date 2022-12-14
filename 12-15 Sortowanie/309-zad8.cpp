#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


//+/- 30 minut
using namespace std;

const int n = 8;
const int numLimit = 1000;

//...vectors are coppied by value

void mergeSort(vector<int> &a, int low, int high){
    //{ a: [low, mid] b: [mid+1, high]
    int mid = (low + high) / 2;
    int ai = low, amax = mid, bi = mid + 1, bmax = high;

    vector<int> result;
    while(ai <= amax && bi <= bmax){
        if(a[ai] < a[bi]){
            result.push_back(a[ai]);
            ai++;
        } else {
            result.push_back(a[bi]);
            bi++;
        }
    }

    if(ai > amax) {
        while(bi <= bmax){
            result.push_back(a[bi]);
            bi++;
        }
    }
    else if(bi > bmax){
        while(ai <= mid){
            result.push_back(a[ai]);
            ai++;
        }
    }

    int j = low, i = 0;
    while(j <= high){
        a[j] = result[i];
        j++; i++;
    }
}

vector<int> sortIter(vector<int> nums){
    int numsSize = nums.size();

    // divide the array into blocks of size `m`
    // m = [1, 2, 4, 8, 16…]
    for (int m = 1; m <= numsSize; m = 2*m)
    {
        // for m = 1, i = 0, 2, 4, 6, 8…
        // for m = 2, i = 0, 4, 8…
        // for m = 4, i = 0, 8…
        // …
        for (int i = 0; i < numsSize; i += 2*m)
        {
            int to = min(i + 2*m - 1, numsSize);
            mergeSort(nums,  i , to);
        }
    }

    return nums;
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
    result = sortIter(nums);

    print(result);
}