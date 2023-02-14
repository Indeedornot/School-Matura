#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

int main() {
    float input = 0.1f;
    float max_iter = 8;

    float whole_part;
    float floating_part = modf(input, &whole_part);

    string result = to_string((int)whole_part) + ".";
    for(int i = 0; i < max_iter && input != 0; i++){
        floating_part = floating_part * 2;
        floating_part = modf(floating_part, &whole_part);
        result += to_string((int)whole_part);
    }

    cout << result;
}