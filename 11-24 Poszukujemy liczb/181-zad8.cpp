#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
    Napisz program, który uporządkuje liczby całkowite w tablicy tak, aby pierwszym elementem tablicy była liczba z
    najmniejszą cyfrą jedności, a ostatnim - liczba z największą cyfrą jedności. Jeśli dwie liczby mają taką samą
    liczbę jedności, uznaj je za równe. Rozwiąż zadanie tak, aby złożoność czasowa algorytmu była nie większa niż 10n
 */

//18 min - stupid solution
//but hey! - O(10 + n)
vector<int> sortByOnesFst(vector<int> arr) {
    vector<vector<int>> all = {
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {}
    };
    vector<int> result;
    string numStr;
    int num;
    int index;

    for (int i = 0; i < arr.size(); i++) {
        num = arr[i];
        numStr = to_string(num);
        index = numStr[numStr.size() - 1] - '0';

        all[index].push_back(num);
    }

    for (int i = 0; i <= 9; i++) {
        result.insert(result.end(), all[i].begin(), all[i].end());
    }

    return result;
}

int getOne(int num) {
    string numStr = to_string(num);
    return numStr[numStr.size() - 1] - '0';
}

/*
// Find the first digit
int firstDigit(int n)
{
    // Find total number of digits - 1
    int digits = (int)log10(n);

    // Find first digit
    n = (int)(n / pow(10, digits));

    // Return first digit
    return n;
}
*/

//16 min - niepewny czy poprawna notacja
vector<int> sortByOnesSnd(vector<int> arr) {
    vector<int> arrCopy = arr;
    int size = arrCopy.size();

    vector<int> nums;

    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j < size; j++) {
            if (getOne(arrCopy[j]) != i) continue;
            nums.push_back(arrCopy[j]);
            arrCopy.erase(arrCopy.begin()+j);
            size--;
            j--;
        }
    }

    return nums;
}

int main() {
    vector<int> nums = {12, 21, 32, 44, 56, 58, 33, 43, 0, 49};

    vector<int> result1 = sortByOnesFst(nums);
    for (int i: result1) {
        cout << i << ", ";
    }

    cout << endl << endl;
    vector<int> result2 = sortByOnesSnd(nums);
    for (int i: result2) {
        cout << i << ", ";
    }
}