#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;

        int maxn = -1;
        int minn = 0x3f3f3f3f;

        for(int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;

            maxn = max(maxn,a);
            minn = min(minn,a);
        }

        cout << maxn - minn << endl;
    }
}

