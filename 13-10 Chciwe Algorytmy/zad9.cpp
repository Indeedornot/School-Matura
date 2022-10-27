#include <iostream>
#include <string>

using namespace std;

/*
    Napisz program wczytujący liczby naturalne a i b, i wypisujący, ile liczb palindromicznych
    jest w przedziale [a; b].
    Uwaga: Liczba palindromiczna to liczba naturalna, która czytana od lewej do prawej i od prawej do lewej ma tak?
    samą wartość.
 */

bool palendromiczna(string s) {
    if(s.size() == 1) return true;

    bool jest = true;
    for (int i = 0; i < (s.size() / 2); i++) {
        if (toupper(s[i]) != toupper(s[s.size() - 1 - i])) {
            jest = false;
            break;
        }
    }

    return jest;
}

void palindromeRange(int min, int max){
    for(int i = min; i < max; i++){
        if(palendromiczna(to_string(i))){
            cout << i << " ";
        }
    }
}

int main(){
    int a, b;
    cin >> a;
    cin >> b;

    palindromeRange(a, b);
}