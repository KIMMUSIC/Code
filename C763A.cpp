#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int n, m;
int rx,ry;
int dx,dy;
int second;

void func(int x, int y, int dx, int dy)
{
    if(x == dx || y == dy)
    {
        return;
    }

    int nx,ny;

    if(dx > 0)
        nx = x + 1;
    else
        nx = x - 1;
    if(dy > 0)
        ny = y + 1;
    else
        ny = y - 1;

    if(nx > n) {
        nx -= 2;
        dx *= -1;
    }
    if(ny > m) {
        ny -= 2;
        dy *= -1;
    }

    if(nx <= 0){
        nx += 2;
        dx *= -1;
    }

    if(ny <= 0)
    {
        ny += 2;
        ny *= -1;
    }

    second++;
    func(nx, ny, dx, dy);
}



int main(void)
{
    int T;
    cin >> T;

    while(T--)
    {
        second = 0;
        cin >> n >> m >> rx >> ry >> dx >> dy;

        func(rx,ry,1,1);

        cout << second << endl;
    }
}
