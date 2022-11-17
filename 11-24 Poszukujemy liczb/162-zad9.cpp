#include <iostream>
#include <string>
#include <random>

using namespace std;

/*
    Zapisz w wybranej przez siebie notacji algorytm zgadywania liczby w grze w 20 pytań przy założeniu że jedna
    odpowiedź może być błędna. Jaka jest minimalna liczba pytań potrzebnych do odgadnięcia liczby
 */

//30 minut wyłączając zabawę

string toString(bool a) {
    return (a ? "Tak" : "Nie");
}

const vector<string> choices = {
        "1. Czy x jest wieksza od ",
        "2. Czy x jest mniejsza od ",
        "3. Czy x jest rowna "
};

const string invalidChoice = "Niepoprawny wybor";

int main() {
    random_device generator;
    uniform_int_distribution<int> distribution(0, 1000);
    int num = distribution(generator);
    cout << "Numer (debug): " << num << endl;

    int questions = 0;
    int fails = 0;
    int choice;
    int chosen;

    while (fails < 2 && questions < 20) {
        cout << "Pytanie numer " << questions + 1 << ": " << endl;
        cout << choices[0] << endl;
        cout << choices[1] << endl;
        cout << choices[2] << endl;

        cin >> choice;
        cout << endl;

        cout << "Numer: ";
        cin >> chosen;


        if (choice < 1 || choice > 3) {
            cout << invalidChoice << endl;
            continue;
        }

        if (choice == 1) {
            cout << toString(num > chosen) << endl;
            questions++;
            continue;
        } else if (choice == 2) {
            cout << toString(num < chosen) << endl;
            questions++;
            continue;
        }

        //choice == 3
        bool equals = num == chosen;
        cout << toString(equals) << endl;
        if (equals) {
            cout << "Wygrales! Liczba to " << num << endl;
            return 0;
        }

        fails++;
        if (fails == 2) {
            cout << "2 Niepoprawne odpowiedzi. Koniec gry" << endl;
            return 0;
        }
        cout << "1 Niepoprawna odpowiedź" << endl;

        questions++;
    }


    cout << "Wyczerpales pytania. Koniec gry" << endl;
    return 0;
}