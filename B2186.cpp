#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define endl "\n"

using namespace std;

int N, M, K;
char map[101][101];
string target;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int cache[101][101][81];


int func(int x, int y, int index)
{
    if(index >= target.size()) return 0;
    if(index == target.size() - 1) return 1;
    int& ret = cache[x][y][index];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = 0; i < 4; ++i)
    {
        for(int j = 1; j <= K; ++j)
        {
            int nx = x + dx[i] * j;
            int ny = y + dy[i] * j;

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(map[nx][ny] == target[index+1])
            {
                ret += func(nx,ny,index+1);
            }
        }
    }

    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;

    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            cin >> map[i][j];
        }
    }

    cin >> target;

    memset(cache, -1, sizeof cache);

    int res = 0;
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < M; ++j)
        {
            if(map[i][j] == target[0])
            {
                res += func(i,j,0);
            }
        }
    }

    cout << res << endl;
}




    

