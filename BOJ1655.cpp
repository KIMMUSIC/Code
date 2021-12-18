#include <iostream>
#include <queue>

#define endl "\n"

using namespace std;

int main(void)
{
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	while (N--)
	{
		int t;
		cin >> t;

		if (maxHeap.size() == minHeap.size())
			maxHeap.push(t);
		else
		{
			minHeap.push(t);
		}

		if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
			int a = maxHeap.top();
			int b = minHeap.top();
			maxHeap.pop();
			minHeap.pop();
			minHeap.push(a);
			maxHeap.push(b);
		}
		cout << maxHeap.top() << endl;
	}
}
