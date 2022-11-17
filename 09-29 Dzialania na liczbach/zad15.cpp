//
// Created by Indeed on 23.09.2022.
//

#include <iostream>

using namespace std;

int main() {
    /*
        Napisz program realizujący algorytm pisemnego mnożenia dwóch liczb. Możesz
        wykorzystywać następujące działania: dodawanie dwóch liczb, mnożenie liczby przez
        cyfrę oraz przez 10, wyznaczanie części całkowitej oraz reszty z dzielenia przez 10.
    */

    float liczba1;
    string liczba2;
    int cyfra;
    int miejsceLimitera = 0;
    float wynik = 0;
    
    cout << "Podaj pierwsza liczbe: ";
    cin >> liczba1;

    cout << liczba1 << endl;
    cout << (int)liczba1 << endl;

    cout << "Podaj druga liczbe: ";
    cin >> liczba2;

    miejsceLimitera = liczba2.find('.');

    //wsparcie dla liczb dziesietnych
    for (int i = 0; i < liczba2.size() - miejsceLimitera - 1; i++) liczba1 /= 10;

    for (int i = liczba2.size() - 1; i >= 0; i--) {
        if (liczba2[i] == '.') continue;
        cyfra = liczba2[i] - '0'; //zamien char na int
        wynik += cyfra * liczba1; //dodaj do wyniku
        liczba1 *= 10; //przesun w lewo
    }

    cout << wynik;

    return 0;
}