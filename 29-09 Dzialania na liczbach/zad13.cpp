//
// Created by Indeed on 23.09.2022.
//

#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int main() {
    /*
        Napisz program wypisujący dzielniki wczytanej liczby całkowitej dodatniej n  - dzielniki powinny być
        uporządkowane od najmniejszego do największego. Spróbuj rozwiązać zadanie tak, aby program wykonywał jak
        najmniej prób dzielenia (nie więcej niż 2 * sqrt(n)).
    */


    int liczba;
    list<int> dzielniki;

    cin >> liczba;

    dzielniki.push_back(1); //kazda liczba dzieli sie przez 1
    for (int i = 2; i <= sqrt(liczba); i++) {
        if (liczba % i == 0) dzielniki.push_back(i);
    }

    for (int dzielnik: dzielniki) {
        cout << dzielnik << endl;
    }
}