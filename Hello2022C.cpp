#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;


long long fac(int n, int r)
{

    long long result = 1;
    for (int i = 1; i <= n; i++)
        result = result * (r + i) % 1000000007;

    return result;
}


int main(void)
{
    int N, K;
    cin >> N >> K;

    int sum = 0;

    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        sum += a;
    }


    int sub = K - sum;




    cout << fac(N, sub) << endl;
}
