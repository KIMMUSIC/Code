#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    int sum = a + b + c;
    if(sum % 3 != 0){
        cout << 0 << endl;
        return 0;
    }
    int di = sum / 3;
    int visited[2001][2001];
    memset(visited, false, sizeof visited);

    vector<int> arr;
    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);

    queue<vector<int>> q;
    q.push(arr);

    visited[a][b] = true;

    bool flag = false;
    while(!q.empty())
    {
        vector<int> cur = q.front();
        q.pop();

        if(cur[0] == di && cur[1] == di && cur[2] == di)
        {
            flag = true;
            break;
        }

        if(cur[0] == di && cur[1] == di && cur[2] != di)
        {
            flag = false;
            break;
        }

        for(int i = 0; i <3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                if(i == j) continue;
                int X = cur[i];
                int Y = cur[j];

                int S = min(X,Y);
                int B = max(X,Y);

                B -= S;
                S *= 2;
                vector<int> nev(3);
                nev = cur;
                nev[i] = S;
                nev[j] = B;

                if(!visited[nev[i]][nev[j]])
                {
                    visited[S][B] = true;
                    q.push(nev);
                }
            }
        }

    }

    if(flag == true)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
}
