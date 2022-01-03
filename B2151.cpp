#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
#define endl "\n"

using namespace std;

int N;
char map[51][51];
vector<pair<int, int>> door;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
queue<pair<pair<int, int>, pair<int, int>>> q;
int visited[51][51][4];

void bfs() {
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();


        if (dir == -1)
        {
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                int tcnt = cnt;

                if (nx >= 0 && ny >= 0 && nx < N && ny < N)
                {
                    if (map[nx][ny] != '*')
                    {
                        if (visited[nx][ny][i] >= tcnt)
                        {
                            visited[nx][ny][i] = tcnt;
                            q.push({ {nx,ny},{i,tcnt} });
                        }
                    }
                }
            }
            continue;

        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        int tcnt = cnt;

        if (nx >= 0 && ny >= 0 && nx < N && ny < N)
        {
            if (map[nx][ny] != '*')
            {
                if (visited[nx][ny][dir] >= tcnt)
                {
                    visited[nx][ny][dir] = tcnt;
                    q.push({ {nx,ny},{dir,tcnt} });
                }
            }
        }

        if (map[x][y] == '!')
        {
            if (dx[dir] != 0)
            {
                for (int i = 2; i <= 3; ++i)
                {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    int tcnt = cnt + 1;

                    if (nx >= 0 && ny >= 0 && nx < N && ny < N)
                    {
                        if (map[nx][ny] != '*')
                        {
                            if (visited[nx][ny][i] >= tcnt)
                            {
                                visited[nx][ny][i] = tcnt;
                                q.push({ {nx,ny},{i,tcnt} });

                            }
                        }
                    }
                }
            }
            else if (dy[dir] != 0)
            {
                for (int i = 0; i <= 1; ++i)
                {
                    nx = x + dx[i];
                    ny = y + dy[i];
                    int tcnt = cnt + 1;

                    if (nx >= 0 && ny >= 0 && nx < N && ny < N)
                    {
                        if (map[nx][ny] != '*')
                        {
                            if (visited[nx][ny][i] >= tcnt)
                            {
                                visited[nx][ny][i] = tcnt;
                                q.push({ {nx,ny},{i,tcnt} });

                            }
                        }
                    }
                }
            }
        }
    }
}




int main(void)
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == '#')
            {
                door.push_back({ i,j });
            }
            for(int k = 0; k < 4; ++k)
                visited[i][j][k] = 987654321;
        }
    }

    visited[door[0].first][door[0].second][0] = 0;
    visited[door[0].first][door[0].second][1] = 0;
    visited[door[0].first][door[0].second][2] = 0;
    visited[door[0].first][door[0].second][3] = 0;
    q.push({ {door[0].first,door[0].second},{-1,0 } });
    
    bfs();

    int ret = 987654321;
    for (int i = 0; i < 4; ++i)
    {
        ret = min(ret, visited[door[1].first][door[1].second][i]);
    }

    cout << ret << endl;
}
