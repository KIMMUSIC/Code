#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define endl "\n"
using namespace std;

int N;
vector<int> health;
vector<int> pleasure;
int cache[22][101];

int func(int index, int hlth)
{
    if (index >= N) return 0;
    int& ret = cache[index][hlth];
    if (ret != -1) return ret;
    ret = func(index + 1, hlth);
    if (hlth > health[index])
    {
        ret = max(ret, pleasure[index] + func(index + 1, hlth - health[index]));
    }
    
    return ret;
}


int main(void)
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N;
    health.resize(N, 0);
    pleasure.resize(N, 0);
    memset(cache, -1, sizeof cache);

    for (int i = 0; i < N; ++i)
    {
        cin >> health[i];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> pleasure[i];
    }

    cout << func(0, 100) << endl;
}
