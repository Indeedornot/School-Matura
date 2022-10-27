#include <iostream>
#include <math.h>
#include <string>

using namespace std;

/*
    W silniowym systemie pozycyjnym mnożniki poszczególnych pozycji są definiowane nie przez potęgę podstawy systemu,
    ale przez silnię kolejnych liczb naturalnych.
    Na przykład:
    2011(!) = 2*4! + 0*3! + 1*2! + 1*1! = 2*24+0+2+1 = 51
    Zapis w silniowym systemie pozycyjnym jest jednoznaczny, tzn. każdą liczbę naturalną można zapisać tylko w jeden
    sposób i każdy zapis oddaje dokładnie jedną wartośc dziesiętną.
    Napisz program, który wczyta liczbę dziesiętną x, gdzie o <= x <= 3628799, i wypisze jej zapis w silniowym
    systemie pozycyjnym.
    Uwaga: 3628799 = 987654321(!)
*/

int silnia(int liczba) {
    int wynik = liczba;
    for (int i = liczba - 1; i > 0; i--) {
        wynik *= i;
    }
    return wynik;
}

int naDziesietna(string liczba) {
    int size = liczba.size();
    int wynik = 0;
    for (int i = size - 1; i >= 0; i--) {
        wynik += (liczba[i] - '0') * silnia((size - i));
    }
    
    return wynik;
}

string naSilniowa(int liczba){
    string wynik = "";
    for(int i = 2; liczba > 0; i++){
        wynik.insert(0, to_string(liczba % i));
        liczba /= i;
    }
    return wynik;
}

int main() {
    int dziesietna;
    cin >> dziesietna;

    string silniowa = naSilniowa(dziesietna);
    cout << silniowa << endl;
    cout << naDziesietna(silniowa);
    // 2011 = 2*4! + 0*3! + 1*2 + 1 * 1! = 51
}