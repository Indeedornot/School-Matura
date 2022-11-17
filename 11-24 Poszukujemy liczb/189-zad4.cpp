#include <iostream>
#include <string>
#include <cmath>
#include <vector>

/*
    Napisz program wczytujący dowolny tekst z klawiatury oraz liczbę będącą kluczem szyfrowania (liczbę kolumn).
    Program powinien szyfrować wczytany tekst szyfrem przestawieniowym polegającym na spiralnym odczytaniu tekstu
    jawnego zapisanego wierszami zgodnie z poniższym przykładem.
 */

using namespace std;

//1H 10 - powód - brak pomysłu jak zapętlać

string zigzagCypher(string line, int columns) {
    int size = line.size();
    int rows = ceil(size / (float) columns);
    int i = 0;
    string result = "";

    //[y][x]
    char table[rows][columns];

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < columns; col++) {

            if (i >= size) {
                table[row][col] = 'X';
                continue;
            }

            table[row][col] = line[i];
            i++;
        }
    }

    int endCols = columns - 1, startCols = 0;
    int endRows = rows - 1, startRows = 0;

    int count = 0;
    while(count < columns * rows){
        for(int row = startRows; row <= endRows; row++){
            result += table[row][endCols];
            count++;
        }
        endCols--;

        for(int col = endCols; col >= startCols; col--){
            result += table[endRows][col];
            count++;
        }
        endRows--;

        for(int row = endRows; row >= startRows; row--){
            result += table[row][startCols];
            count++;
        }
        startCols++;

        for(int col = startCols; col <= endCols; col++){
            result += table[startRows][col];
            count++;
        }
        startRows++;
    }

    return result;
}

struct test {
    int cols;
    string prompt;
    string expected;
};

int main() {
    vector<test> tests = {
            {5, "Niewiem czy to dziala", "iz lXXXXadyeNiewcoaiz m t"},
            {4, "ALA MA KOTA I PSA", " K SXXXAIOMALA AP TA"},
            {4, "DWA RAZY DWA CZTERY", " YATXYRE  RDWAZWZCDA"},
            {6, "TEST IF IT IS WORKING STILL", "IIKTXXXLLIISFTEST  RS GN  ITOW"}
    };

    bool isCorrect;
    string output;
    for(int i = 0; i < tests.size(); i++){
        output = zigzagCypher(tests[i].prompt, tests[i].cols);
        isCorrect = (output == tests[i].expected);
        cout << i << ": " << isCorrect << endl;
        if(!isCorrect){
            cout << "Expected output: " << tests[i].expected << " Got: " << output << endl << endl;
        }
    }
}