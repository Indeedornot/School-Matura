//
// Created by Indeed on 23.09.2022.
//

#include <iostream>

using namespace std;

int main(){
    /*
        Napisz program sprawdzający, czy wszystkie cyfry wczytanej liczby całkowitej dodatniej są
        jednocyfrowymi liczbami parzystymi. Program powinien wypisać słowo "TAK" lub "NIE".
    */
    string liczba;

    cin >> liczba;

    bool parzyste = true;
    for(int i = liczba.size() - 1; i >= 0; i++){
        if(i % 2 != 0){
            parzyste = false;
            break;
        }
    }

    if(parzyste) cout << "TAK";
    else cout << "NIE";

    return 0;
}