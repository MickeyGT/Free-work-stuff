#include<fstream>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<array>
#include<deque>
#include<unordered_set>
#include<set>
#include<math.h>
using namespace std;
long long dp[100100], i, n, fr[100100], el, maxval;
int main()
{
	cin >> n;
	maxval = -1;
	for (i = 1; i <= n; i++)
	{
		cin >> el;
		fr[el]++;
		if (el > maxval)
			maxval = el;
	}
	dp[1] = fr[1];
	dp[2] = fr[2] * 2;
	for (i = 3; i <= maxval; i++)
	{
		// fr[i]*i because after we choose to delete i-1 and i+1, 
		// we will be able to do it until we run out of elements of i;
		dp[i] = max(dp[i - 2] + fr[i] * i, dp[i - 1]);
		// the maximum can also result from 2 positions ago, not only one.
		dp[i] = max(dp[i], dp[i - 3] + fr[i] * i);
	}
	cout << dp[maxval];
	return 0;
}
