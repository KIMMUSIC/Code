#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int par[100002];

int find(int v)
{
    if(v == par[v]) return v;
    return par[v] = find(par[v]);
}

int main(void)
{
    int G, P;
    cin >> G >> P;

    for(int i = 0; i <= G; ++i)
    {
        par[i] = i;
    }
    int ans = 0;
    for(int i = 0; i < P; ++i)
    {
        int t;
        cin >> t;
        int v = find(t);
        if(v == 0) break;
        par[v] = v-1;
        ans++;
    }

    cout << ans << endl;
}
