#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define endl "\n"

using namespace std;

int R, C;
char map[101][101];
int N;
vector<int> height;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int visited[101][101];
vector<pair<int, int>> stable;
vector<pair<int, int>> unstable;


void istable(int x, int y)
{
    stable.push_back({ x,y });
    visited[x][y] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C)
        {
            if (!visited[nx][ny] && map[nx][ny] == 'x')
            {
                istable(nx, ny);
            }
        }
    }
}

void iunstable(int x, int y)
{
    unstable.push_back({ x,y });
    visited[x][y] = 1;

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C)
        {
            if (!visited[nx][ny] && map[nx][ny] == 'x')
            {
                iunstable(nx, ny);
            }
        }
    }
}




void clustering() {
    for (int i = 0; i < C; ++i)
    {
        if (!visited[R - 1][i] && map[R - 1][i] == 'x')
        {
            istable(R - 1, i);
        }
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if (!visited[i][j] && map[i][j] == 'x')
            {
                iunstable(i, j);
            }
        }
    }
}

void dive() {
    vector<pair<int, int>> under;
    for (int i = 0; i < C; ++i)
    {
        int ret = -1;
        for (int j = 0; j < unstable.size(); ++j)
        {
            if (unstable[j].second == i)
            {
                ret = max(ret, unstable[j].first);
            }
        }
        if (ret != -1) under.push_back({ ret,i });
    }
    sort(under.begin(), under.end(), greater<>());
    sort(unstable.begin(), unstable.end(), greater<>());
    while (!unstable.empty()) {

        int bottomx = under[0].first;

        if (bottomx == R)
        {
            break;
        }

        int flag = 0;

        for (int i = 0; i < under.size(); ++i)
        {
                if (map[under[i].first + 1][under[i].second] != '.')
                {
                    flag = -1;
                    break;
               }
                under[i].first += 1;
            
        }

        if (flag != -1)
        {
            for (int i = 0; i < unstable.size(); ++i)
            {
                map[unstable[i].first + 1][unstable[i].second] = 'x';
                map[unstable[i].first][unstable[i].second] = '.';
                unstable[i].first += 1;
                
            }
        }
        else
        {
            break;
        }
    }
    return;
}




int main(void)
{

    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> R >> C;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> map[i][j];
        }
    }

    cin >> N;

    height.resize(N, 0);

    for (int i = 0; i < N; ++i)
    {
        cin >> height[i];
    }

    int turn = 0;

    for (int i = 0; i < height.size(); ++i)
    {
        int t = R - height[i];

        if (turn == 0)
        {
            turn += 1;
            for (int j = 0; j < C; ++j)
            {
                if (map[t][j] == 'x')
                {
                    map[t][j] = '.';
                    break;
                }
            }
        }
        else
        {
            turn -= 1;
            for (int j = C - 1; j >= 0; --j)
            {
                if (map[t][j] == 'x')
                {
                    map[t][j] = '.';
                    break;
                }
            }
        }

        memset(visited, 0, sizeof visited);
        unstable.clear();
        stable.clear();

        clustering();
        dive();
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cout << map[i][j];
        }

        if (i != R - 1)
            cout << endl;
    }
}


