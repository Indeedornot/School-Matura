#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>

using namespace std;

//1h 50min

vector<string> split(string s, char delimiter) {
    vector<string> result;
    int found;
    string temp;
    while ((found = s.find(delimiter)) != string::npos) {
        result.push_back(s.substr(0, found));
        s = s.substr(found + 1, s.size());
    }
    if(s != " " && s != "") result.push_back(s);

    return result;
}

const char hexa[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

string PadString(string a, char c, int count, bool start) {
    start ? a.insert(0, count, c) : a.insert(a.size(), count, c);
    return a;
}

string base16(int num) {
    string reverse, result;
    do {
        reverse += hexa[num % 16];
        num = num / 16;
    } while (num != 0);

    for (auto i: reverse) {
        result.insert(0, 1, i);
    }

    return result;
}

vector<string> hex4byte(string data){
    //zamieniamy na 16, dodajemy zera i zwracamy po znaku
    string hex = base16(stoi(data));
    string paddedHex = PadString(hex, '0', 4 - hex.size() ,true);
    vector<string> result = {
            paddedHex.substr(0, 1),
            paddedHex.substr(1,1),
            paddedHex.substr(2,1),
            paddedHex.substr(3,1)
    };
    return result;
}

int main() {
    ifstream fileIn("232-zad1.txt");
    string line;
    vector<string> lineData;
    vector<string> fourBytes;
    vector<string> bytes;

    vector<vector<string>> picture;
    for (int i = 0; getline(fileIn, line); i++) {
        lineData = split(line, ' ');
        for (auto const& data: lineData) {
            fourBytes = hex4byte(data);
            //dostajemy vector 4 bitow i go dodajemy do naszego rzedu
            bytes.insert(bytes.end(), fourBytes.begin(), fourBytes.end());
        }
        picture.push_back(bytes);
        bytes = {};
    }

    for(auto const& i : picture){
        for(auto const& j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    cout << "<------------------KOLORY------------------>" << endl;

    int white = 0, black = 0;
    for(auto const& i : picture){
        for(auto const& j : i){
            if(j == "0") white++;
            else if(j == "F") black++;
        }

        cout << "White: " << white << " Black: " << black << endl;
        white = black = 0;
    }

    cout << "<------------------X RZEDY------------------->" << endl;

    int max = 0, temp = 0;
    string tempC;
    for(int i = 0; i < picture.size(); i++){
        for(auto const& j : picture[i]){
            if(max == 0) tempC = j;
            if(tempC == j) temp++;
            else temp = 1;
            tempC = j;

            if(temp > max) max = temp;
        }

        cout << i << ": " << max << endl;
        max = temp = 0;
        tempC = "";
    }

    cout << "<-------------------Y KOLUMNY---------------->" << endl;

    string tempZ;
    string z;
    for(int x = 0; x < picture[0].size(); x++){
        for(int y = 0; y < picture.size(); y++){
            z = picture[y][x];
            if(max == 0) tempZ = z;
            if(tempZ == z) temp++;
            else temp = 1;
            tempZ = z;

            if(temp > max) max = temp;
        }

        cout << x << ": " << max << endl;
        max = temp = 0;
        tempZ = "";
    }
}