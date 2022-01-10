#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#define MAX 101

using namespace std;

int n;
int Max_v;
int Min_v;
bool visited[MAX][MAX];
int map[MAX][MAX];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };



bool bfs(int num) {
    queue<pair<int, int>> q;

    for (int i = Min_v; i <= Max_v; ++i)
    {
        memset(visited, true, sizeof visited);

        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < n; ++k)
            {
                if (i <= map[j][k] && map[j][k] <= i + num) visited[j][k] = false;
            }
        }

        q.push({ 0,0 });

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (visited[x][y] == true) continue;
            visited[x][y] = true;


            if (x == n - 1 && y == n - 1) return true;

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    q.push({ nx,ny });
                
            }
        }
    }
    return false;
}








int main(void)
{
    cin >> n;
    Max_v = -1;
    Min_v = 500;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> map[i][j];
            Max_v = max(Max_v, map[i][j]);
            Min_v = min(Min_v, map[i][j]);
        }
    }

    int start = 0;
    int End = Max_v - Min_v;
    int mid;

    while (start <= End) {
        mid = (start + End) / 2;
        if (bfs(mid) == true) End = mid - 1;
        else start = mid + 1;
    }
    cout << End + 1 << endl;
}
