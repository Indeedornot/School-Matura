#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <vector>
//1h
using namespace std;

/*
    Napisz program realizujący algorytm sita Erastotenesa z użyciem szablonu struktury danych set z Bliblioteki STL
 */

set<int> eratostenesWHelper(){
    set<int> arr;
    set<int> toDelete;
    for(int i = 2; i < 1000; i++){
        arr.insert(i);
    }

    for(auto i = arr.begin(); i != arr.end(); i = next(i, 1)){
        for(auto j = next(i, 1); j != arr.end(); j = next(j, 1) ){
            if((*j) % (*i) == 0) toDelete.insert(*j);
        }
    }

    for(auto i = toDelete.begin(); i != toDelete.end(); i = next(i, 1)){
        arr.erase(*i);
    }

    return arr;
}

set<int> eratostenes(){
    set<int> arr;
    for(int i = 2; i < 1000; i++){
        arr.insert(i);
    }

    for(auto i = arr.begin(); i != arr.end(); i = next(i, 1)){
        for(auto j = next(i, 1); j != arr.end(); j = next(j, 1) ){
            if((*j) % (*i) == 0) {
                j = arr.erase(j);
                if(j == arr.end()) break;
            }
        }
    }

    return arr;
}

int main(){
    for(auto i : eratostenes()){
        cout << i << endl;
    }
}