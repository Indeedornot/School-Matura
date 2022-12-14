#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//+/- 18min

struct fraction {
    int num, den;
};

bool isBigger(fraction a, fraction b){
    return a.num * b.den > b.num * a.den;
}

vector<fraction> quickSort(vector<fraction> fractions){
    if(fractions.empty() || fractions.size() == 1) return fractions;

    int pivot = fractions.size() / 2;
    vector<fraction> smaller;
    vector<fraction> bigger;

    for(int i = 0; i < fractions.size(); i++){
        if(i == pivot) continue;

        if(isBigger(fractions[pivot], fractions[i])){
            smaller.push_back(fractions[i]);
        }
        else{
            bigger.push_back(fractions[i]);
        }
    }

    vector<fraction> result;

    smaller = quickSort(smaller);
    bigger = quickSort(bigger);

    result.insert(result.end(), smaller.begin(), smaller.end());
    result.push_back(fractions[pivot]);
    result.insert(result.end(), bigger.begin(), bigger.end());

    return result;
}

void print(vector<fraction> a){
    for(auto i: a){
        cout << i.num << "/" << i.den << endl;
    }
}

int main() {
    vector<fraction> test = {
            {1,2},
            {1,3},
            {1,4},
            {1,5},
            {1,7},
            {1,6},
            {1,1}
    };

    vector<fraction> result = quickSort(test);

    print(result);
}