#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;

float f(float x){
    return x * sin(x);
}

int main() {
    float from = 0;
    float to = M_PI;

    float figureCount = 2;
    float increment = (to - from)/figureCount;

    float x = from;
    float f1 = f(x), f2;
    float area = 0;

    for(int i = 0; i < figureCount; i++){
        x = x + increment;
        f2 = f(x);
        area += increment * (f1 + f2)/2;
        f1 = f2;
    }
}