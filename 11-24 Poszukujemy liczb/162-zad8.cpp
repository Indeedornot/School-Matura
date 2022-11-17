#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
    Napisz funkcję, której wynikiem będzie liczba elementów z przedziału [a;b] (a, b - liczby całkowite, a < b)
    znajdujących się w uporządkowanej niemalejąco tablicy n liczb całkowitych. Zastosuj algorytm przeszukiwania
    binarnego.
 */

//26 min

//for sorted arrays only!
int search(vector<int> arr, int num, int l = 0, int p = -1){
    p = (p == -1) ? arr.size() : p;
    int sr;

    while(l <= p){
        sr = (l+p)/2;

        if(arr[sr] == num){
            return sr;
        }

        if(arr[sr] < num){
            p = sr - 1;
        }
        else {
            l = sr + 1;
        }
    }

    return -1;
}

vector<int> findNumbers(int from, int to, vector<int> arr){
    vector<int> arrCopy = arr;
    vector<int> numbers;
    int index;

    for(int i = from; i <= to; i++){
        index = search(arrCopy, i);
        if(index == -1) continue;
        numbers.push_back(arrCopy[index]);
        arrCopy.erase(arrCopy.begin()+index);
    }

    return numbers;
}

int main(){
    vector<int> arr;
    int a = 0;
    int b = 1000;
    int step = 2;

    for(int i = a; i < b; i += step){
        arr.push_back(i);
    }

    vector<int> nums = findNumbers(45, 60, arr);
    cout << "Count: " << nums.size() << endl;
    for(int i : nums){
        cout << i << ", ";
    }
}