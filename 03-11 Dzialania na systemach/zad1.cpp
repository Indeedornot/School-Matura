#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/*
    Dodawanie i Mnozenie w systemach o dowolnych podstawach
 */

//30 minut - dodawanie, 50 z testami
//40 minut - mnozenie

string PadString(string a, char c, int count, bool start){
    start ? a.insert(0, count ,c) : a.insert(a.size(), count, c);
    return a;
}

string SumBase(string a, string b, int base){
    int sizeA = a.size();
    int sizeB = b.size();

    int sizeDiff = abs(sizeA-sizeB);
    if(sizeDiff > 0){
        sizeA < sizeB ?
            a = PadString(a, '0', sizeDiff, true) :
            b = PadString(b, '0', sizeDiff, true);
    }

    string result;
    int l1 = 0, l2 = 0, keep = 0;

    int k;

    for(int i = a.length() - 1; 0 <= i; i--){
        l1 = a[i] - '0';
        l2 = b[i] - '0';

        k = l1 + l2 + keep;

        if(k < base){
            result.insert(0, to_string(k));
            keep = 0;
        }
        else{
            result.insert(0, to_string(k - base));
            keep = 1;
        }
    }

    if(keep != 0){
        result.insert(0, to_string(l1));
    }

    return result;
}

string MultiplyBase(string a, string b, int base){
    string result = "";

    string current = "";
    int l1 = 0, l2 = 0, keep = 0;
    int k = 0;
    //1010
    //0101
    for(int i = b.length() - 1; 0 <= i; i--){
        l1 = b[i] - '0';
        for(int j = a.length() - 1; 0 <= j; j--){
            l2 = a[j] - '0';

            k = l1 * l2;

            current.insert(0, to_string((k + keep)%base));
            keep = (k + keep) / base;
        }
        if(keep != 0){
            current.insert(0, to_string(keep));
            keep = 0;
        }

        result = SumBase(result, PadString(current, '0', b.length() - i - 1, false), base);
        current = "";
    }

    return result;
}

struct Test
{
    string a, b, result;
    int base;
};

int main() {
    vector<Test> testsSum = {
        {"101", "1010", "1111", 2},
        {"12", "12", "24", 8},
        {"24", "24", "48", 10},
        {"480", "96", "576", 10}
    };

    for(auto const& i : testsSum){
        cout << (SumBase(i.a, i.b, i.base).compare(i.result) == 0) << endl;
    }

    vector<Test> testMulti = {
            {"1010", "101", "110010", 2},
            {"16", "15", "266", 8},
            {"24", "24", "576", 10}
    };

    for(auto const& i : testMulti){
        cout << (MultiplyBase(i.a, i.b, i.base).compare(i.result) == 0) << endl;
    }

    return EXIT_SUCCESS;
}