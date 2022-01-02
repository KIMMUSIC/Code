#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;

        vector<int> po;
        po.resize(101,0);
        int zero = 0;
        for(int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;

            if(a > 0) po[a]++;
            if(a < 0){
                a *= -1;
                po[a]++;

            }
            if(a == 0) zero++;
        }

        int ans = 0;

        for(int i = 1; i <= 100; ++i)
        {
            if(po[i] >= 2) ans += 2;

            if(po[i] == 1) ans += 1;
        }

        if(zero > 0) ans += 1;

        cout << ans << endl;
    }
}


