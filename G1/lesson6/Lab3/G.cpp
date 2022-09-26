#include <bits/stdc++.h>
using namespace std;

int reqdTours(vector<int> a, int cur)
{
	int cur_tours = 0;
	for (int i = 0; i < a.size(); i++)
		cur_tours += (a[i] + cur - 1) / cur;
	return cur_tours;
}

int getMin(vector<int> a, int k)
{
	int maxm = 0;
	for (int i = 0; i < a.size(); i++)
		maxm = max(a[i], maxm);

	int left = 1, right = maxm + 1;
	int ans = -1;
	while (left + 1 < right)
	{
		int mid = left + (right - left) / 2;
		if (reqdTours(a, mid) <= k)
		{
			right = mid;
			ans = right;
		}
		else
		{
			left = mid;
		}
	}	
	return ans;
}

// Driver Code
int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << getMin(v, k);
}