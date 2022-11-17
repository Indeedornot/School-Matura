//
// Created by Indeed on 23.09.2022.
//

#include <iostream>

using namespace std;

int main() {
    /*
        Napisz program, który sprawdzi, czy podana liczba całkowita dodatnia
        jest liczbą palindromiczną (czytana od lewej do prawej i od prawej do lewej ma tę samą wartość).
    */

    string liczba;

    cin >> liczba;

    bool jest = true;
    for (int i = 0; i < (liczba.size() / 2); i++) {
        if (liczba[i] != liczba[liczba.size() - 1 - i]) {
            jest = false;
            break;
        }
    }

    if (jest) cout << "liczba " << liczba << " jest palendromiczna";
    else cout << "liczba " << liczba << " nie jest palendromiczna";

    return 0;
}