#include <iostream>
#include <list>
#include <cmath>

using namespace std;

/*
 Poszukaj w internecie informacji dotyczących związku liczb Mersenne'a z liczbami doskonałymi. Napisz program
 znajdujący pięć początkowych liczb doskonałych.
 Uwaga: Liczba doskonała to liczba równa sumie wszystkich swoich dzielników właściwych. Liczbą doskonałą jest np. 28,
 bo 28 = 1 + 2 + 4 + 7 + 14
 */

bool jestPierwsza(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    // Using concept of prime number
    // can be represented in form of
    // (6*n + 1) or(6*n - 1) hence
    // we have to go for every multiple of 6 and
    // prime number would always be 1 less or 1 more than
    // the multiple of 6.
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main(){
    list<int> doskonale;
    int suma = 1;

    for(int i = 1; doskonale.size() < 5; i++)
    {
        suma += pow(2,i);
        cout << "potega: " << i << " suma: " << suma<< endl;
        if(jestPierwsza(suma)){
            doskonale.push_back(suma * pow(2, i));
        }
    }

    for(int i : doskonale){
        cout << i << " ";
    }
}

