#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector<int> memo;
vector<int> cost;
int cache[101][10001];
int N,M;

int func(int index, int totalcost)
{
    if(index >= N) return 0;
    int& ret = cache[index][totalcost];
    if(ret != -1)
        return ret;
    ret = func(index+1, totalcost);
    if(totalcost >= cost[index]) {
        ret = max(ret, memo[index]+func(index+1, totalcost - cost[index]));
    }

    return ret;
}


int main(void)
{
    cin >> N >> M;

    memo.resize(N,0);
    cost.resize(N,0);
    memset(cache, -1, sizeof cache);


    for(int i = 0; i < N; ++i)
    {
        cin >> memo[i];
    }
    for(int i = 0; i < N; ++i)
    {
        cin >> cost[i];
    }

    int total = 0;
    while(1)
    {
        if(func(0,total) >= M)
        {
            cout << total << endl;
            break;
        }
        total++;
    }
}


