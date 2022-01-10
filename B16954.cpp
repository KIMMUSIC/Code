#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int dx[] = { -1,-1,-1,0,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,0,1,-1,0,1 };
char map[8][8];
queue<pair<pair<int, int>, int>> q;
bool visited[9][9][10];

int bfs()
{
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int s = q.front().second;
        q.pop();
        if (x == 0 && y == 7) return 1;

        for (int i = 0; i < 9; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = min(s + 1, 8);

            if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
            if (nx - s >= 0 && map[nx - s][ny] == '#') continue;
            if (nx - s - 1 >= 0 && map[nx - s - 1][ny] == '#') continue;
            if (!visited[nx][ny][nt])
            {
                visited[nx][ny][nt] = 1;
                q.push({ {nx,ny},nt });
            }
            
        }

    }

    return 0;
}





int main(void)
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            cin >> map[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    visited[7][0][0] = 1;
    q.push({ {7,0},0 });
    cout << bfs() << endl;
}


