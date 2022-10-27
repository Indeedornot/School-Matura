#include <iostream>
#include <list>
#include <map>
#include <cmath>

using namespace std;

/*
    Napisz program znajdujący trzy początkowe pary liczb zaprzyjaźnionych. Utwórz i wykorzystaj funkcję obliczającą
    sumę dzielników właściwych podanego parametru.
    Uwaga: Liczby zaprzyjaźnione to takie dwie liczby całkowite dodatnie, z których każda jest równa sumie dzielników
    właściwych drugiej liczby

    Założenie: - Dzielniki w sumie mogą się powtarzać -> 25 / 5 = 5 -> suma = 10
               - Dzielniki właściwe to dzielniki wliczające 1, bez samej liczby

    +/- 40 minut
 */

bool jestPierwsza(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    // Using concept of prime number
    // can be represented in form of
    // (6*n + 1) or(6*n - 1) hence
    // we have to go for every multiple of 6 and
    // prime number would always be 1 less or 1 more than
    // the multiple of 6.
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int sumaDzielnikowWlasciwych(int liczba){
    int suma = 1;
    int reszta = 0;

    cout << liczba << endl;
    for(int i = 2; i <= sqrt(liczba); i++){
        reszta = liczba % i;
        if (reszta != 0) continue;

        //42 / 2 = 21 => suma += 21 + 2
        suma += i;
        suma += liczba / i; //no bo dzielenie działa odwrotnie
        cout << "suma: " << suma << " i: " << i << " drugi: " << liczba/i << endl;
    }
    cout << endl << endl;
    return suma;
}

int main(){
    list<pair<int,int>> zaprzyjaznione;
    map<int, int> sumy;
    int suma;

    cout << (sumaDzielnikowWlasciwych(220) == 284) << endl;

    for(int i = 2; zaprzyjaznione.size() < 3; i++){
        if(jestPierwsza(i)) continue; // no bo dla pierwszych suma = 1

        suma = sumaDzielnikowWlasciwych(i);
        if(sumy.find(suma) == sumy.end()){
            //nie znaleziono wiec zapisz
            sumy[i] = suma;
        }
        else{
            if(sumy[suma] == i) {
                //znaleziono wiec dodaj do listy
                zaprzyjaznione.push_back(pair<int, int>(i, suma));
            }
        }
    }

    for(auto i : zaprzyjaznione){
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}