//
// Created by Indeed on 09.11.2022.
//
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

//water jug problem
//Rozwiazanie naiwne - przelewanie z 1 do 2

int pour(int doLimit, int zLimit, int d){
    int doF = 0, zF = zLimit, moves = 0;

    while(doF != d && zF != d){
        int temp = min(zF, doLimit-doF); // lejemy tyle ile mozemy lub calosc
        doF += temp;
        zF -= temp;

        moves++;

        if(doF == d || zF == d) break;

        if(zF == 0){
            zF = zLimit;
            moves++;
        }

        if(doF == doLimit){
            doF = 0;
            moves++;
        }
    }

    return moves;
}

int main() {
    //a * x + b * y = d
    int a, b, l;
    cout << "Wiadro 1 " << endl;
    cin >> a;

    cout << "Wiadro 2 " << endl;
    cin >> b;

    cout << "Litry " << endl;
    cin >> l;

    if(l > max(a,b)) {
        cout << "Nie mozna dla tych liczb";
    }

    cout << "a " << a << " b " << b << " l " << l << " ruchy " << min(pour(a,b,l), pour(b,a,l)) << endl;
}