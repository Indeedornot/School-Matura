#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <functional>
#include <cmath>

/*
    Napisz program losujący tablicę liczb całkowitych z zakresu od 2 do 1000 oraz sortujący je według najmniejszego
    czynnika pierwszego. Najpierw w tablicy powinny znaleźć się liczby podzielne przez 2, potem podzielne przez 3 (a
    niepodzielne przez 2), następnie podzielne przez 5 (a niepodzielne przez 2 i 3)
 */

//28 min

using namespace std;

int isPrime(int n){
    if (n <= 1) return false;
    if (n == 2 || n == 3) return true;

    if (n % 2 == 0 || n % 3 == 0) return false;

    //divide by next suspected primes (6l + 5 || 6(l+1) + 1)
    for (int i = 5; i <= sqrt(n); i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int nextPrime(int start, int end = INFINITY){
    if(start > end) return -1;
    for(int i = start; i < end; i++){
        if(isPrime(i)) return i;
    }

    return -1;
}

vector<pair<int, int>> sortByPrimeDiv(vector<int> arr){
    vector<int> arrCopy = arr;
    vector<pair<int, int>> result;
    int size = arrCopy.size();
    int prime = 2;
    auto begin = arrCopy.begin();

    while(size > 0){
        for(int i = 0; i < size; i++){
            if(arrCopy[i] % prime != 0) continue;

            result.push_back(pair<int,int>(arrCopy[i], prime));
            arrCopy.erase(begin + i);
            i--;
            size--;
        }

        prime = nextPrime(prime + 1, 1000);
        if(prime == -1) break;
    }

    return result;
}

int main(){
    random_device generator;
    uniform_int_distribution<int> distribution(2, 1000);

    vector<int> nums;
    int numCount = 10;

    for(int i = 0; i < numCount; i++){
        nums.push_back(distribution(generator));
    }

    auto sorted = sortByPrimeDiv(nums);

    cout << "numCount: " << nums.size() << endl;
    for(int i : nums){
        cout << i << ", ";
    }
    cout << endl;

    cout << "sortedCount: " << sorted.size() << endl;

    for(pair<int,int> i : sorted){
        cout << "(" << i.first << ", " << i.second << "), ";
    }
}