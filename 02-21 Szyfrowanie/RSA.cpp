#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

//MATH
int NWD(int a, int b){
    //b always > a
    if(a > b){
        swap(a, b);
    }

    if(a == 0) {
        return b;
    }

    return NWD(a, b%a);
}

pair<int, int> ExtendedNWD(int a, int b){
    if(b == 0){
        return make_pair(1,0);
    }

    auto nwd = ExtendedNWD(b, a%b);
    return make_pair(nwd.second, nwd.first - (a/b) * nwd.second);
}

int RelPrime(int m){
    int e = 3;
    while(NWD(e, m) != 1){
        e += 2;
    }

    return e;
}

int QuickPower(int num, int pow, int base){
    //cha^e % n
    int r = 1;
    while(pow > 0){
        if(pow % 2 == 1) r = (r * num) % base;
        pow /= 2;
        if(pow > 0) num = (num*num) % base;
    }

    return r;
}

//ENCRYPT
void Encrypt(ifstream &in, ofstream &out, int key, int n){
    in >> noskipws;

    unsigned char ch;
    while(in >> ch){
        out << QuickPower(ch, key, n) << " ";
    }

    in.close();
    out.close();
}

//DECRYPT
void Decrypt(ifstream &in, ofstream &out, int key, int n){
    int x;
    while(in >> x){
        out << char(QuickPower(x, key, n));
    }
}

int main() {
    int p = 11;
    int q = 13;

    int n = p * q;
    int m = (p - 1)*(q - 1);

    int e = RelPrime(m);

    int d = ExtendedNWD(e,m).first;
    if(d < 0) d += m;

    cout << "private: (e: " << e << " n: " << n << ")" << endl;
    cout << "private: (d: " << d << " n: " << n << ")" << endl;

    string basePath = "C:\\Users\\Indeed\\Desktop\\Stuff\\Repositories\\CPP\\Matura\\02-21 Szyfrowanie";
    ifstream ogFile ( basePath + "\\ogFile.txt");
    ofstream encryptFileOut(basePath + "\\encryptFile.txt");
    Encrypt(ogFile, encryptFileOut, e, n);

    ifstream encryptFileIn(basePath + "\\encryptFile.txt");
    ofstream decryptFile(basePath + "\\decryptFile.txt");
    Decrypt(encryptFileIn, decryptFile, d, n);
}

