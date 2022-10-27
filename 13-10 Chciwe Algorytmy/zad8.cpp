#include <iostream>
#include <string>

using namespace std;

/*
    Napisz program, który wczyta słowo złożone z wielkich liter alfabetu łacińskiego i wypisze najdłuższy ciąg
    kolejnych liter zawarty w tym słowie, który brzmi tak samo czytany od lewej do prawej i od prawej do lewej, a
    więc ma cechę palindromu (ale nie musi być wyrazem).
    Jeśli takie ciągi będą dwa - program wypisze ten, który występuje wcześniej.
    Na przykład dla słowa RABATA program powinien wypisać ciąg ABA.

 */

bool palendromiczna(string s) {
    bool jest = true;
    for (int i = 0; i < (s.size() / 2); i++) {
        if (toupper(s[i]) != toupper(s[s.size() - 1 - i])) {
            jest = false;
            break;
        }
    }

    return jest;
}

int main() {
    string palendrom;
    string substring;
    string input;

    while (true) {
        cin >> input;

        //funkcja substr przyjmuje start i ile elementow do przodu
        //no to od 0 do konca czyli do rozmiar-1
        int lenght = input.size() - 1;

        // nie idziemy do konca, bo 1 litera to nie palendrom
        // && jak jest mniej liter niz ma palendrom to i tak nic nie znajdziemy
        for (int start = 0; start < input.size() - 2 && palendrom.size() < input.size() - 1 - start; start++) {

            //chodzmy od konca, a nuz palendrom bedzie caly od start do konca
            //&& czy zostalo nam wystarczajaco znakow by miec szanse na dluzszy palendrom
            for (int koniec = input.size() - 1; start < koniec && palendrom.size() < lenght; koniec--) {
                lenght = koniec - start + 1;
                substring = input.substr(start, lenght);
                if (!palendromiczna(substring)) continue;

                if (palendrom.size() < substring.size()) {
                    palendrom = substring;
                    break; //idziemy od konca, wiec nic wiecej nie znajdziemy z tej pozycji
                }
            }
        }

        cout << palendrom << endl;
        palendrom = "";
    }
}