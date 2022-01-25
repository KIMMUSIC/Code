#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int visited[1001][1001];
char map[1001][1001];
int gp[1001][1001];
int gpcnt[500001];
int N, M;


int dfs(int x, int y, int g)
{
    gp[x][y] = g;
    int ret = 1;
    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (visited[nx][ny] || map[nx][ny] == '1') continue;

        visited[nx][ny] = true;
        ret += dfs(nx, ny,g);
    }

    return ret;
}

int dfs2(int x, int y)
{
    int ret = 1;
    vector<int> check;
    for (int i = 0; i < 4; ++i)
    {
        
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (map[nx][ny] == '1') continue;

        int flag = true;
        for (int j = 0; j < check.size(); ++j)
        {
            if (check[j] == gp[nx][ny])
            {
                flag = false;
            }
        }
        if (flag == true)
        {
            ret += gpcnt[gp[nx][ny]];
            check.push_back(gp[nx][ny]);
        }

    }

    return ret % 10;
}

int main(void)
{
    memset(visited, false, sizeof visited);
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    }

    int group = 1;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] == '0' && !visited[i][j])
            {
                visited[i][j] = true;
                gpcnt[group] = dfs(i, j, group);
                group++;
            }

        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] == '0') {
                cout << 0;
            }
            else
            {
                cout << dfs2(i, j);
            }
        }
        cout << endl;
    }
}

