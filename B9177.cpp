#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
string a, b, c;
int sa, sb, sc;
int cache[201][201];

int func(int idx1, int idx2, int idx)
{
    if(idx == sc) return 1;
    int& ret = cache[idx1][idx2];

    if(ret != -1) return ret;
    ret = 0;
    if(idx1 < sa && a[idx1] == c[idx]) ret = func(idx1+1,idx2,idx+1);
    if(idx2 < sb && b[idx2] == c[idx]) ret = max(ret, func(idx1,idx2+1,idx+1));

    return ret;
}

int main(void)
{
    cin >> n;
    int t = 1;

    while(n--)
    {
        cin >> a >> b >> c;
        sa = a.size();
        sb = b.size();
        sc = c.size();

        memset(cache, -1, sizeof cache);
        cout << "Data set " << t << ": ";
        t++;
        if(func(0,0,0)) cout << "yes\n";
        else cout << "no\n";
    }

}
