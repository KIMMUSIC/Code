#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while(T--)
    {
        char map[41][41];
        double n,k;
        cin >> n >> k;

        if(n == 1) cout << "R" << endl;
        else if(ceil(n / 2) < k) cout << -1 << endl;
        else
        {
            int initx = 0;
            int inity = 0;
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    map[i][j] = '.';
                }
            }

            for(int i = 0; i < k; ++i)
            {
                map[initx][inity] = 'R';
                initx += 2;
                inity += 2;
            }

            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                {
                    cout << map[i][j];
                }
                cout << endl;
            }
        }
    }
}


            
