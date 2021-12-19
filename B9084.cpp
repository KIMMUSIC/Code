#include <iostream>
#include <vector>
#include <string.h>

#define endl "\n"
using namespace std;

int N, M;
vector<int> money;
int cache[21][10001];

int func(int idx,int cost)
{
    int& ret = cache[idx][cost];
    if (ret != -1) return ret;
    if (cost == 0) {
        return 1;
    }
    if (idx >= N)
        return 0;

    int c = 0;
    ret = 0;
    while (1)
    {
        if (c * money[idx] > cost) break;
        ret += func(idx + 1, cost - c * money[idx]);
        c++;
    }

    return ret;
}



int main(void)
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    while (T--)
    {
        cin >> N;
        money.resize(N, 0);


        for (int i = 0; i < N; ++i)
        {
            cin >> money[i];
        }

        cin >> M;
        memset(cache, -1, sizeof cache);
        
        cout << func(0, M) << endl;
    }
}

