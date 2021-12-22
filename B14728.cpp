#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, T;
vector<int> K;
vector<int> S;
int cache[101][10001];

int func(int idx, int rTime)
{
    if(idx >= N) return 0;
    if(rTime ==0 ) return 0;
    int& ret = cache[idx][rTime];
    if(ret != -1) return ret;
    ret = func(idx+1, rTime);
    if(rTime >= K[idx])
    {
        ret = max(ret, S[idx] + func(idx+1, rTime - K[idx]));
    }

    return ret;
}


int main(void)
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> T;

    K.resize(N,0);
    S.resize(N,0);
    memset(cache, -1, sizeof cache);

    for(int i = 0; i < N; ++i)
    {
        cin >> K[i];
        cin >> S[i];
    }

    cout << func(0,T) << endl;
}



