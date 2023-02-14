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
    float a1, b1, c1;
    float a2, b2, c2;

    float w = a1*b2-a2*b1;
    float wX = c1*b2-b1*c2;
    float wY = a1*c2-a2*c1;

    if(w != 0){
        cout << "x: " << wX/w << " y: " << wY/w;
        return 0;
    }

    if(wX == 0 && wY == 0){
        cout << "nieskonczenie wiele rozwiazan";
        return 0;
    }

    if(wX != 0 || wY != 0){
        cout << "uklad sprzeczny";
    }
}