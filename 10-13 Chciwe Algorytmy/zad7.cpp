#include <iostream>
#include <string>

using namespace std;

/*
    Napisz funkcj? string UpString(string s), kt?ra dla napisu złożonego z małych i wielkich liter alfabetu
    łacińskiego zwróci napis zapisany wielkimi literami, np. dla parametru aLa zwróci
    wartość ALA.
    Przetestuj działanie funkcji w programie sprawdzającym, czy wyraz jest palindromem.
 */

string UpString(string s){
    for(int i = 0; i < s.size(); i++){
        s[i] = toupper(s[i]);
    }
    return s;
}

bool palendromiczna(string s){
    bool jest = true;
    for (int i = 0; i < (s.size() / 2); i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            jest = false;
            break;
        }
    }

    return jest;
}

int main(){
    string input;
    string upper;

    cin >> input;

    upper = UpString(input);
    cout << upper << endl;

    cout << "String " << upper << " " << (palendromiczna(upper) ? "" : "nie") << " jest palendromiczna" <<endl;
}