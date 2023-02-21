#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

const int PRIME_NUM = 997;
const int ALPHABET_LEN = 26;

int toNum(char ch){
    return ch - 'a';
}

//Wyznacza wartość potęgi w arytmetyce modulo
int N_Base_Power(int base, int pow){
    int w = 1; //wynik
    while(pow > 0){ //jest do czego podnosic
        if(pow % 2 == 1) {
            //jeżeli potęga jest nieparzysta
            //wykona sie dla potegi 5,3,1 (ale juz nie dla zera)

            w = (w * base) % PRIME_NUM; //zwieksz wynik * baza i zrób modulo n
            //czyli tutaj zachodzi samo potegowanie
        }

        pow /= 2; //podziel potęgę
        if(pow > 0){ //potęga większa od zera (będzie kolejna iteracja)
            base = (base * base)%PRIME_NUM; //podnies do kwadratu i wyciagnij modulo n
        }
    }

    //potega = 7, baza = 3, w = 1, n = 997
    //potega = 3, baza = 9, w = 3
    //potega = 1, baza = 81,w = 27,
    //potega = 0, baza = 81,w = 193

    return w;
}

int Hash0(string s){
    int w = 0;
    for(int i = 0; i < s.size(); i++){
        w = ((w * ALPHABET_LEN) % PRIME_NUM + toNum(s[i])) % PRIME_NUM;
        //dodaj wartosc kolejnego znaku do hasha
    }
}

int Hash1(int h0, int jd, char ch){
    int w = (h0 - jd) % PRIME_NUM; //usuwamy ostatni ze znaków z wartości hasha
    if(w < 0) w = w + PRIME_NUM; //przechodzimy z ujemnych na dodatnie

    return ((w * ALPHABET_LEN)%PRIME_NUM + toNum(ch))%PRIME_NUM;
}

int Znajdz(string pattern, string text){
    int sameCharCount, p = 0; //position in text, from which we look

    int dP = pattern.size(), hP = Hash0(pattern);
    int dT = text.size(), hT = Hash0(text.substr(0,dP)); //part of the string len(pattern)
    int pow = N_Base_Power(ALPHABET_LEN, dP-1);

    while(p <= dT - dP){ //till the count of characters to check exceeds pattern's len
        if(hP == hT){ //they have the same hash
            sameCharCount = 0;

            //additional check for collisions
            for(int i = 0; i < dP; i++){
                if(pattern[i] != text[p+i]) break;
                sameCharCount++;
            }

            //we found the match
            if(sameCharCount == dP) {
                return p;
            }
        }

        if(p < dT - dP){ //for all iterations but last
            int hFirstChar = (pow * toNum(text[p])) % PRIME_NUM;
            hT = Hash1(hT, hFirstChar, text[p+dP]); //recalculate hash for new letter
        }

        p++;
    }
}