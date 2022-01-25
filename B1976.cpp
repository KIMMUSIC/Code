#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int parent[201];

int find(int u)
{
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);

    if (u == v) return;
    parent[u] = v;
}


int main(void)
{
    int N;
    int M;
    cin >> N >> M;
    for (int i = 0; i < 201; ++i)
        parent[i] = i;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int a;
            cin >> a;

            if (a == 1)
                merge(i, j);
        }
    }
    int ret;
    bool flag = true;
    for (int i = 0; i < M; ++i)
    {
        int a;
        cin >> a;
        a--;
        if (i == 0)
            ret = find(a);
        else
            if (ret != find(a))
            {
                flag = false;
            }
    }

    if (flag == true)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
