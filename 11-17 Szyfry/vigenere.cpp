#include <string>
#include <fstream>
#include <iostream>

using namespace std;

const string litery = "abcdefghijklmnopqrstuvwxyz";

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

//zalozenie naiwne - kazda linijka zaczyna od key[0]
string vigenere(string key, string line, bool reverse = false){
    string result = "";
    int literyLen = litery.size();
    int lineLen = line.size();
    line = toLower(line);
    key = toLower(key);
    int keyLen = key.size();
    int index, keyIndex;
    int rev = reverse ? -1 : 1;

    for(int i = 0; i < lineLen; i++){
        index = litery.find(line[i]);
        if(index == string::npos) {
            result += line[i];
            continue;
        }
        keyIndex = litery.find(key[i%keyLen]);
        index = getLoopingIndex(index, rev * keyIndex, literyLen);
        result += litery[index];
    }

    return result;
}

int main() {
    ifstream fileIn("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\11-17 Szyfry\\vigenere.txt");
    ofstream fileOut("C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\11-17 Szyfry\\vigenereOut.txt");

    string key; //example: "cover"
    cin >> key;

    string line;
    string vig;
    while(getline(fileIn, line)){
        vig = vigenere(key, line);
        cout << vig << endl;
        fileOut << vig << endl;
        cout << vigenere(key, vig, true);
    }
}