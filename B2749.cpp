#include <iostream>
#include <vector>
#define endl "\n";

using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n1, n2;
	n1 = 0; n2 = 1;
	int cnt = 0;
	while (1)
	{
		int tmp = n1;
		n1 = n2;
		n2 = (tmp + n2) % 1000000;
		cnt++;
		if (n1 == 0 && n2 == 1)
		{
			break;
		}
	}

	vector<int> arr;
	arr.resize(cnt+1, 0);

	arr[0] = 0;
	arr[1] = 1;

	long long int n;
	cin >> n;

	for (int i = 2; i <= cnt; ++i) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
	}

	cout << arr[n % cnt] << endl;
}
