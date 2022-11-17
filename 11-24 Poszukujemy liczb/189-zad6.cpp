#include <iostream>
#include <string>
#include <cmath>

/*
    Napisz program, który wczyta jednowierszowy szyfrogram i klucz szyfrogram i klucz szyfrowania. Szyfrogram powstał
    przez zaszyfrowanie tekstu jawnego szyfrem kolumnowym. Klucz jest napisem złożonym z niepowtarzających się cyfr
    dziesiętnych mniejszych od długości klucza i określa liczbę kolumn oraz kolejność ich przeglądania.
 */
//40 minut

using namespace std;

string cipher(string line, string key) {
    int lineLen = line.length();
    int columns = key.length();
    int rows = ceil(lineLen / (float) columns);
    string result = "";

    //[y][x] -> [row][column]
    char table[rows][columns];

    int lineChar = 0;
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < columns; ++col) {
            table[row][col] = line[lineChar];
            lineChar++;
        }
    }

    int col;
    for (int i = 0; i < columns; i++) {
        col = key[i] - '0';

        for (int row = 0; row < rows; row++) {
            result += table[row][col];
        }
    }

    return result;
}

string decipher(string line, string key) {
    int lineLen = line.length();
    int keyLen = key.length();
    int rows = ceil(lineLen / (float) keyLen);
    string result;

    //[y][x] - [col][row] bo odwracamy
    char ciphered[keyLen][rows];
    int i = 0;
    for (int col = 0; col < keyLen; col++) {
        for (int row = 0; row < rows; row++) {
            ciphered[col][row] = line[i];
            i++;
        }
    }

    char deciphered[rows][keyLen];
    int keyCol;
    for (int a = 0; a < keyLen; a++) {
        keyCol = (key[a] - '0');
        for (int row = 0; row < rows; row++) {
            deciphered[row][keyCol] = ciphered[a][row];
        }
    }

    for(int row = 0; row < rows; row++){
        for(int col = 0; col < keyLen; col++){
            result += deciphered[row][col];
        }
    }

    return result;
}

int main() {
//    ifstream fileIn("189-zad6.txt");
//
//    string line;
//    string key;
//
//    getline(fileIn, line);
//    getline(fileIn, key);

    string line = "GEEKS FOR GEEKS HERE";
    string key = "1203";

    string ciph = cipher(line, key);
    cout << ciph << endl;
    cout << decipher(ciph, key);
}