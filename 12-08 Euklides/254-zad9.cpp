#include <vector>
#include <iostream>

using namespace std;

pair<int, int> euklides(int a, int b)
{
    if (b > a)
        swap(a, b);
    if (b == 0)
        return make_pair(1, 0);
    int x = 1, y = 0,
        r = 0, rTemp,
        s = 0, sTemp,
        c, q;
    // ax+by=NWD(a,b)
    while (b != 0)
    {
        // zapiszmy sobie div i mod
        c = a % b;
        q = a / b;

        // podmienmy jak w euklides(b, b%a)
        a = b;
        b = c;

        // zapiszmy sobie liczby z poprzedniego podejscia
        rTemp = r;
        sTemp = s;

        r = x - q * r;
        s = y - q * s;

        x = rTemp;
        y = sTemp;
    }
    return make_pair(x, y);
}

void print(pair<int, int> p, int a, int b)
{
    cout << p.first << "*" << a << "+" << p.second << "*" << b << endl;
}

int main()
{
    vector<pair<int, int>> nums = {{2, 4}, {3, 6}, {12, 6}};
    for (auto i : nums)
    {
        print(euklides(i.first, i.second), i.first, i.second);
    }
}