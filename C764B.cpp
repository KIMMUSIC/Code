#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        bool flag = false;
        long long a, b, c;
        long long multi;

        cin >> a >> b >> c;

        if ((2 * b - c) != 0 && (2 * b - c) % a == 0 && (2*b -c) >= 0) flag = true;
        else if ((2 * b - a) != 0 && (2 * b - a) % c == 0 && (2 * b - a) >= 0) flag = true;
        else if (((a + c) % 2 == 0) && ((a + c) / 2 % b) == 0) flag = true;


        if (flag == true)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
