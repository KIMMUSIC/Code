#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
vector<int> v;
string a;
int d;

long long isitanswer(){
    if(v[0] == 0) return -1;

    long long realnum = 0;
    long long othernum = 0;
    long long se = 0;
    long long se2 = 0;
    for(int i = d - 1; i >= 0; --i)
    {
        realnum += pow(v[i],se);
        if(se == 0) se = 1;
        else se *= d;
    }

    for(int i = a.size() - 1; i >= 0; --i)
    {
        othernum += pow(a[i],se2);
        if(se2 == 0) se2 = 1;
        else se2 *= 10;
    }

    if(othernum  < realnum) return realnum;
    else return -1;
}





int main(void)
{
    cin >> a;

    cin >> d;

    v.resize(d);

    for(int i = 0; i < d; ++i)
    {
        v[i] = i;
    }

    long long ans;
    bool flag = false;
    while(next_permutation(v.begin(), v.end()))
    {
        ans = isitanswer();
        if(ans != -1){
            flag = true;
            break;
        }
    }

    if(flag == true)
    {
        cout << ans << endl;
    }
    else 
        cout << -1 << endl;
}

        

