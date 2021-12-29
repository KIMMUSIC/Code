#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#define endl "\n"

using namespace std;

int N;
vector<int> arr;
vector<int> sum;
int cache[501][501];

int dp(int start, int end)
{
    if(start == end) return 0;
    int& ret = cache[start][end];
    if(ret != -1) return ret;
   
    for(int i = start; i < end; ++i)
    {
        if(ret == -1)
        {
            ret = dp(start,i) + dp(i+1,end) + sum[end] - sum[start - 1];
        }
        ret = min(ret, dp(start,i) + dp(i+1,end) + sum[end] - sum[start - 1]);
    }
       return ret;
}

int main(void)
{
    int T;
    cin >> T;

    while(T--)
    {
        cin >> N;
        arr.resize(N,0);
        sum.resize(N,0);

        for(int i = 0; i < N; ++i)
        {
            cin >> arr[i];
            sum[i] = sum[i-1] + arr[i];
        }
        memset(cache, -1, sizeof cache);

        cout << dp(0, N-1) << endl;
    }
}


