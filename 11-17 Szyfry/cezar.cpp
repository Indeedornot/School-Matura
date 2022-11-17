#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <cctype>
#include <cstring>
#include <vector>
#include <iosfwd>
#include <sstream>

using namespace std;

//const string litery = "aąbcćdeęfghijklłmnoóprsśtuwxyz";
const string litery = "abcdefghijklmnoprstuwxyz";

//next - przesuniecie
int getLoopingIndex(int index, int next, int limit) {
    if (index + next >= limit) {
        return index + next - limit;
    }
    if (index + next < 0) {
        return limit + (index + next);
    }
    return index + next;
}

string toLower(string s){
    string result = s;
    for(int i = 0; i < s.size(); i++){
        result[i] = tolower(result[i]);
    }

    return result;
}

string cezar(string line, int key) {
    int sizeLen = line.size();
    int literyLen = litery.size();
    line = toLower(line);
    string result = "";
    int index;

    for (int i = 0; i < sizeLen; i++) {
        index = litery.find(line[i]);
        if(index == string::npos) {
            result += line[i];
        }
        index = getLoopingIndex(index, key, literyLen);
        result += litery[index];
    }

    return result;
}

void szyfruj(int key, string line) {
    int len = line.size();
    string result = "";

    key = key % 26 + 1 ;

    if (key >= 0)
        for (int i = 0; i < len; i++) {
            if (line[i] + key <= 'z') result += string(1, line[i] + key);
            else result += string(1, line[i] + key - 26);
        }
    else
        for (int i = 0; i < len; i++) {
            if (line[i] + key >= 'a') result += string(1, line[i] + key);
            else result += string(1, line[i] + key + 26);
        }
}

vector<int> frequency(string message){
    vector<int> result(litery.size(), 0);
    int pos;

    for(char i : message){
        pos = litery.find(i);
        if(pos == string::npos) continue;

        result[pos] += 1;
    }

    return result;
}

int main() {
//region szyfrowanie
    ifstream textIn("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\11-17 Szyfry\\cezar.txt");
    fstream cypherOut("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\11-17 Szyfry\\cezarOut.txt", fstream::out | fstream::in);

    int key = 2;

    string line;
    string cezarLine;

    while (getline(textIn, line)) {
        cezarLine = cezar(line, key);
        cout << cezarLine << endl;
        cypherOut << cezarLine << endl;
    }

//endregion

//region czestotliwosc
    ifstream cypherIn("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\11-17 Szyfry\\cezarOut.txt",fstream::out | fstream::in);

    string message;
    while(getline(cypherIn, line)){
        if(!message.empty()){
            message += " ";
        }
        message += line;
    }

    cout << message << endl;

    vector<int> freq = frequency(message);
    for(int i = 0; i < litery.size(); i++){
        cout << litery[i] << " " << freq[i] << " ";
    }
    cout << endl;
//endregion
}