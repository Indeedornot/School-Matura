#include <iostream>

using namespace std;

/*
 Napisz program sprawdzający hipotezę Goldbacha dla podanej parzystej liczby całkowitej z zakresu od 2 do 100.
 Uwaga: Hipoteza Goldbacha mówi, że każdą liczbę parzystą większą od 2 można przedstawić jako sumę dwóch liczb
 pierwszych
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

bool czyGoldbach(int liczba){
    for(int i = 2; i <= liczba - i; i++){
        //upewniamy sie ze sumuja sie do liczby
        if (!jestPierwsza(i) || !jestPierwsza(liczba - i)) continue;
        cout << "1: " << i << " 2: " << liczba-i << endl;
        return true;
    }
    return false;
}

int main(){
    int liczba;
    cin >> liczba;

    cout << (czyGoldbach(liczba) ? "Jest Goldbach" : "Nie jest Goldbach");
}