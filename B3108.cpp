#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<pair<pair<int,int>,pair<int,int>>> v;
int par[1010];

int find_p(int x){
    if(par[x] == x) return x;
    return par[x] = find_p(par[x]);
}

void merge(int a, int b){
    a = find_p(a);
    b = find_p(b);
    if(a < b) par[b] = a;
    else if(a > b) par[a] = b;
}

bool meet(int i, int j)
{
    int ax1 = v[i].first.first;
    int ay1 = v[i].first.second;
    int ax2 = v[i].second.first;
    int ay2 = v[i].second.second;
    int bx1 = v[j].first.first;
    int by1 = v[j].first.second;
    int bx2 = v[j].second.first;
    int by2 = v[j].second.second;

    if (by2 > ay2 && ax2 < bx2 && ay1 > by1 && bx1 < ax1)
		return false;
	if (ay2 > by2 && bx2 < ax2 && by1 > ay1 && bx1 > ax1)
		return false;
	if (by1 > ay2 || bx1 > ax2 || ay1 > by2 || bx2 < ax1)
		return false;
	return true;
}

int main(void)
{
    int num;

    cin >> num;

    for(int i = 0; i <= num; ++i)
        par[i] = i;

    v.push_back({{0,0},{0,0}});
    for(int i = 0; i < num; ++i)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        v.push_back({{x1,x2},{y1,y2}});
    }

    for(int i = 0; i < num; ++i)
    {
        for(int j = i + 1; j <= num; ++j)
        {
            if(meet(i,j))
                merge(i,j);
        }
    }

    set<int> s;
    for(int i = 0; i <= num; ++i)
        s.insert(find_p(par[i]));

    cout << s.size() - 1 << endl;
}
