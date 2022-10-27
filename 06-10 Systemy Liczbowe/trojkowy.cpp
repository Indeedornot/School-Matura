#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

/*
    Do zapisu liczb w zrównoważonym systemie trójkowym używa się trzech znaków: 0, +, -. Znak + odpowiada wartości 1,
    a znak - odpowiada wartości -1.
    Na przykład liczba -25 zapisana w tym systemie miałaby postać -0+-. Wynika to z faktu, że:
    -25 = -1 * 3^3 + 0*3^2 + 1 * 3^1 -1 * 3^0 = -27+0+3-1
 */

// for string delimiter
vector<string> split(string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> split;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        split.push_back(token);
    }

    split.push_back(s.substr(pos_start));
    return split;
}

int zTrojkowegoBal(string trojkowaBal) {
    int wynik = 0;
    int potega = 0;
    int znak = 0;
    int rozmiar = trojkowaBal.size();

    for (int i = rozmiar - 1; i >= 0; i--) {
        if (trojkowaBal[i] == '0') continue;

        if (trojkowaBal[i] == '-') znak = -1;
        else znak = 1;

        potega = rozmiar - i - 1;
        wynik += znak * pow(3, potega);
    }

    return wynik;
}
string naTrojkowyNor(int liczba, bool limiter = false) {
    string wynik = "";
    while (liczba != 0) {
        wynik.insert(0, to_string(liczba % 3));
        liczba /= 3;
    }
    return wynik;
}
string naTrojkowyBal(string trojkowa) {
    /*
        1. Convert decimal to the ternary number system.
        2. Convert ternary to the balanced ternary system, using the below steps:
            1. traverse the ternary number, right to left by leaving 0 and 1 as it is
            2. when encounter 2, change it to Z and add +1 to the next digit in iteration.
            3. Some digits may become +3, then replace +3 with 0 and add +1 to next digit in iteration.
            4. complete this process until you convert all the digits.
     */
    vector<string> trojkowaTab = split(trojkowa, ",");
    int rozmiar = trojkowaTab.size();
    string wynik = "";

    /*
     -2 -2 -1
     "0+-"
     */
    for (int i = rozmiar - 1; i >= 0; i--) {
        if (trojkowaTab[i] == "0") wynik.insert(0, "0");
        else if (trojkowaTab[i] == "1") wynik.insert(0, "+");
        else if(trojkowaTab[i] == "-1") wynik.insert(0, "-");
        else if(trojkowaTab[i] == "2"){
            wynik.insert(0, "-");

            if(i > 0) trojkowaTab[i - 1] = to_string(stoi(trojkowaTab[i-1]) + 1) ;
            else wynik.insert(0, "+");
        }
        else if(trojkowaTab[i] == "-2"){
            wynik.insert(0, "+");

            if(i > 0) trojkowaTab[i - 1] = to_string(stoi(trojkowaTab[i-1]) - 1);
            else wynik.insert(0, "-");
        }
        else if(trojkowaTab[i] == "3"){
            wynik.insert(0, "0");

            if(i > 0) trojkowaTab[i - 1] = to_string(stoi(trojkowaTab[i-1]) + 1) ;
            else wynik.insert(0, "+");
        }
        else if(trojkowaTab[i] == "-3"){
            wynik.insert(0, "0");

            if(i > 0) trojkowaTab[i - 1] = to_string(stoi(trojkowaTab[i-1]) - 1) ;
            else wynik.insert(0, "-");
        }
    }
    return wynik;
}

int main() {
    int wynik = 0;
    int znak = 0;
    int potega = 0;

    while (true) {
        string trojkowa;
        cin >> trojkowa;

        //-+0

        //-1*3^2 + 1*3^1 + 0 * 3^0
        // dla i = 2, size = 3, potęga = 0
        wynik = zTrojkowegoBal(trojkowa);
        cout << wynik << endl;

        string temp = naTrojkowyNor(wynik, true);
        cout << temp << endl;

        string bal = naTrojkowyBal(temp);
        cout << bal << endl;
    }
}
