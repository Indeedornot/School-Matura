#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

//zwraca podzielony stack i zwraca pozycje pivotu
int partition(vector<int>& a, int start, int end)
{
    stack<int> smaller;
    stack<int> bigger;
    stack<int> result;

    int pivot = a[end];

    for(int i = start; i < end; i++){
        if(a[i] < pivot) smaller.push(a[i]);
        else bigger.push(a[i]);
    }

    while(!bigger.empty()){
        result.push(bigger.top());
        bigger.pop();
    }

    int pivotPos = smaller.size() + start;
    result.push(pivot);

    while(!smaller.empty()){
        result.push(smaller.top());
        smaller.pop();
    }

    for(int i = start; i <= end; i++){
        a[i] = result.top();
        result.pop();
    }

    return pivotPos;
}

vector<int> quickSortIterative(vector<int> arr, int n)
{
    stack<pair<int,int>> queue;
    int start = 0, end = n - 1;

    queue.push(make_pair(start,end));

    while (!queue.empty()) {
        start = queue.top().first;
        end = queue.top().second;
        queue.pop();

        int p = partition(arr, start, end);

        if (p - 1 > start) {
            queue.push(make_pair(start, p - 1));
        }

        if (p + 1 < end) {
            queue.push(make_pair(p + 1, end));
        }
    }

    return arr;
}

void print(vector<int> a){
    for(auto i: a){
        cout << i << " ";
    }

    cout << endl;
}

const int n = 100;
const int limit = 1000;


int main() {
    srand(time(nullptr));

    vector<int> nums;
    for(int i = 0; i < n; i++){
        nums.push_back(rand() / limit);
    }

    print(nums);

    cout << "After sort: " << endl;

    nums = quickSortIterative(nums, n);

    print(nums);
}