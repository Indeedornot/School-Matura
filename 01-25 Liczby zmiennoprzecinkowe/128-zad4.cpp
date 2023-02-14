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
    vector<int> wspolczynniki;

    int iInput;
    char cInput;
    while(true){
        cin >> cInput;
        if(cInput == 'n') break;

        iInput = cInput - '0';
        wspolczynniki.push_back(iInput);
    }

    int x;
    cin >> x;

    int result = wspolczynniki[0]; //a0

    int saved_x = x;
    for(int i = 1; i < wspolczynniki.size(); i++){
        result += wspolczynniki[i] * saved_x;
        saved_x = x * x;
    }

    cout << result;
}