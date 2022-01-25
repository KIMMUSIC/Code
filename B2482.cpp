#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int cache[1001][1001];
int n, k;

int dp(int cur, int x)
{
    if(cur <= 0 || cur < 2*x) return 0;
    if(x == 1) return cur;

    int& ret = cache[cur][x];
    if(ret != -1) return ret;

    return ret = (dp(cur-2,x-1) + dp(cur-1, x)) % 1000000003;
}

int main(void)
{
    cin >> n >> k;

    memset(cache, -1, sizeof cache);
    cout << dp(n,k) << endl;
}
