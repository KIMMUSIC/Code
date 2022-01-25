#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,k;
string s[16];
long long dp[1<<15][101];
int cache[51];
int cachestr[15];

int get_mod(string &s, int divisor){
    int ret = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        ret *=10;
        ret += s[i] - '0';
        ret %= divisor;
    }

    return ret;
}

long long gcd(long long lhs, long long rhs)
{
    long long big, small;

    big = max(lhs, rhs);
    small = min(lhs, rhs);

    while(small != 0)
    {
        long long remainder = big % small;
        big = small;
        small = remainder;
    }

    return big;
}

void solution(){
    for(int cur = 0; cur < (1<<n); ++cur)
    {
        for(int i = 0; i < n; ++i)
        {
            if((cur & (1 << i)) == 0)
            {
                int nextState = cur | (1 << i);
                for(int j = 0; j < k; ++j)
                {
                    int nextK = ((j * cache[s[i].length()]) % k + cachestr[i]) % k;
                    
                    dp[nextState][nextK] += dp[cur][j];
                }
            }
        }
    }
    return;
}

int main(void)
{
    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    cin >> k;

    dp[0][0] = 1;

    cache[0] = 1 % k;

    for(int i = 1; i <51; ++i)
    {
        cache[i] = (cache[i-1] * 10) % k;

    }

    for(int i = 0; i < n; ++i)
    {
        cachestr[i] = get_mod(s[i], k);

    }

    solution();

    long long denominator = 1, numerator;

    for(int i = 1; i <= n; ++i)
    {
        denominator *= i;
    }

    numerator = dp[(1<<n) - 1][0];
    long long gc = gcd(numerator, denominator);

    cout << numerator / gc << "/" << denominator / gc;

}
