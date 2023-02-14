#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

int max_iter = 8;

string fraction_to_binary(float input){
    float whole_part;
    float floating_part = modf(input, &whole_part);

    string result = to_string((int)whole_part) + ".";
    for(int i = 0; i < max_iter && input != 0; i++){
        floating_part = floating_part * 2;
        floating_part = modf(floating_part, &whole_part);
        result += to_string((int)whole_part);
    }

    return result;
}

float binary_to_fraction(string binary){
    float result = 0;

    int periodIndex = binary.find('.');

    int zeroIndex;
    int num;

    for(int i = periodIndex - 1; i >= 0; i--){
        num = binary[i] - '0';
        if(num == 0) continue;

        zeroIndex = (periodIndex - 1) - i;

        result += num * pow(2, zeroIndex);
    }

    for(int i = periodIndex + 1; i < binary.size(); i++){
        num = binary[i] - '0';
        if(num == 0) continue;

        zeroIndex = i - (periodIndex + 1);

        //ulamek zaczyna od potegi 2
        result += num * pow(2, -(zeroIndex + 1) );
    }

    return result;
}

int main() {
    string binary = fraction_to_binary(0.1);
    float result = binary_to_fraction(binary);

    cout << result;
}