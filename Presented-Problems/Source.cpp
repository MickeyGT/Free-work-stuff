#include<fstream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<string.h>
#include<bitset>
#include<ctime>
#include<set>
#include<cmath>
#include<unordered_map>
#include<iomanip>
#include<map>
#include<stack>
#include<vector>
#include<bitset>
#include<functional>
#include<iostream>
#include<deque>
#include<unordered_set>
#include<queue>
#include<list>
#include<array>
#include<ctype.h>
using namespace std;
long long i, j, k, ok, nr, n, m, el, min1, max1, x, y, a, b,price,mat[100][100],lin,col,stoc[100][100],lin1,col1,lin2,col2,dp[100][100];
int v1[] = { 0,-1,-1,-1,0,+1,+1,+1 };
int v2[] = { +1,+1,0,-1,-1,-1,0,+1 };
string s;
char c;
deque<pair<int, int>>que;
int main()
{
	//ifstream f("file.in");
	//ofstream g("file.out");
	cin >> c;
	lin = c - 'A'+1;
	cin >> col;
	/*
	for (i = 1; i <= lin; i++)
		for (j = 1; j <= col; j++)
			cin >> mat[i][j];
	for (i = 1; i <= lin; i++)
		for (j = 1; j <= col; j++)
			cin >> stoc[i][j];
	*/
	//cin >> c;
	//lin = c - 'A' + 1;
	//cin >> col;
	//price = mat[lin][col];
	//cin >> n;
	/*
	for (i = 1; i <= n; i++)
	{
		cin >> el;
		nr += el;
	}
	if (price <= nr)
	{
		cout << "CHANGE";
		nr = nr-price;
		while (nr >= 200)
		{
			x++;
			nr -= 200;
		}
		s += to_string(x) + " ";
		x = 0;
		while (nr >= 100)
		{
			x++;
			nr -= 100;
		}
		s += to_string(x) + " ";
		x = 0;
		while (nr >= 50)
		{
			x++;
			nr -= 50;
		}
		s += to_string(x) + " ";
		x = 0;
		while (nr >= 20)
		{
			x++;
			nr -= 20;
		}
		s += to_string(x) + " ";
		x = 0;
		while (nr >= 10)
		{
			x++;
			nr -= 10;
		}
		s += to_string(x) + " ";
		x = 0;
		while (nr >= 5)
		{
			x++;
			nr -= 5;
		}
		s += to_string(x) + " ";
		x = 0;
		while (nr >= 2)
		{
			x++;
			nr -= 2;
		}
		s += to_string(x) + " ";
		s += to_string(nr) + " ";
		for (j = s.length() - 1; j >= 0; j--)
			cout << s[j];
	}
	else
		cout << "MISSING "<<price-nr;
		*/
	/*
	for (j = 1; j <= n; j++)
	{
		cin >> c;
		lin = c - 'A' + 1;
		cin >> col;
		if (stoc[lin][col] > 0)
		{
			nr += mat[lin][col];
			stoc[lin][col]--;
		}
	}
	cout << nr;
	*/
	cin >> c;
	lin1 = c - 'A' + 1;
	cin >> col1;
	cin >> c;
	lin2 = c - 'A' + 1;
	cin >> col2;
	/*
	if (abs(lin1 - lin2) > abs(col1 - col2))
	{
		nr += abs(col1 - col2);
		nr += abs(lin1 - lin2) - nr;
	}
	else
	{
		nr += abs(lin1 - lin2);
		nr += abs(col1 - col2) - nr;
	}
	cout << nr;
	*/
	cin >> el;
	for (i = 1; i <= lin; i++)
		for (j = 1; j <= col; j++)
			dp[i][j] = 1LL << 30;
	dp[lin1][col1] = 0;
	que.push_back({ lin1,col1 });
	while (que.size() != 0)
	{
		pair<int, int>per = que.front();
		que.pop_front();
		lin = per.first;
		col = per.second;
		for (i = 0; i <= 7; i++)
			if(i!=el)
			if (dp[lin + v1[i]][col + v2[i]] > dp[lin][col] + 1)
			{
				que.push_back({ lin + v1[i] ,col + v2[i] });
				dp[lin + v1[i]][col + v2[i]] = dp[lin][col] + 1;
			}
	}
	cout << dp[lin2][col2];
	return 0;
}