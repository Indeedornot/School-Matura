#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
//25min
void print(vector<int> data){
    for(auto i : data){
        cout << i << " ";
    }

    cout << endl;
}

vector<vector<int>> allSubsets(int arr[], int n){
    //NIE SIZEOF(ARR)/SIZEOF(ARR[0]) BO ARR TO POINTER
    int size = n;
    int index = 0;
    vector<vector<int>> allsets;
    vector<int> set;
    for(int i = index; i < size; i++){
        set.push_back(arr[i]);
        for(int j = i+1; j < size; j++){
            if(arr[j] > set.back()){
                set.push_back(arr[j]);
            }
        }
        index++;
        allsets.push_back(set);
        set = {};
    }

//    for(auto i : allsets){
//        print(i);
//    }

    return allsets;
}

vector<int> compareSubsets(vector<vector<int>> first, vector<vector<int>> second){
    vector<int> subset;
    vector<int> temp;

    for(auto firstSet: first){
        for(auto secondSet: second){
            if(firstSet.size() <= subset.size() || secondSet.size() <= subset.size()) continue;

            for(int i = 0; i < min(firstSet.size(), secondSet.size()); i++){
                if(firstSet[i] == secondSet[i]) temp.push_back(firstSet[i]);
            }

            if(temp.size() > subset.size()) {
                subset = temp;
            }

            temp = {};
        }
    }

    return subset;
}

int main() {
    int n = 100;
    int limit = 58;
    int first[100];
    int second[100];

    for(int i = 0; i < n; i++){
        first[i] = rand() % limit;
        second[i] = rand() % limit;
    }

    allSubsets(first, n);
    allSubsets(second, n);

    print(compareSubsets(allSubsets(first,n), allSubsets(second, n)));
}