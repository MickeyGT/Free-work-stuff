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
int n, m, i, j, k, x, y, cost[50500], crcost, point[50500];
vector<pair<int, int>>v[50500];
struct muchie
{
	int nod, crcost;
	bool operator <(const muchie &aux)
	{
		return crcost > aux.crcost;
	}
}el;
priority_queue <muchie> que;
int main()
{
	ifstream f("file.in");
	ofstream g("file.out");
	//ifstream f("catun.in");
	//ofstream g("catun.out");
	f >> n >> m >> k;
	for (i = 1; i <= n; i++)
		cost[i] = 1 << 30;
	for (i = 1; i <= k; i++)
	{
		f >> x;
		cost[x] = 0;
		que.push({ x, 0 });
		point[x] = x;
	}
	for (i = 1; i <= m; i++)
	{
		f >> x >> y >> crcost;
		v[x].push_back({ y,crcost });
		v[y].push_back({ x,crcost });
	}
	while (que.size() != 0)
	{
		el = que.top();
		int nod = el.nod;
		int crcost = el.crcost;
		que.pop();
		if (crcost> cost[nod])
			continue;
		for (auto it = v[nod].begin(); it != v[nod].end(); it++)
		{
			if (cost[it->first] > cost[nod] + it->second)
			{
				point[it->first] = point[nod];
				cost[it->first] = cost[nod] + it->second;
				que.push({ it->first, cost[it->first] });
			}
			if (cost[it->first] == cost[nod] + it->second &&point[nod]<point[it->first])
				point[it->first] = point[nod];
		}
	}
	for (i = 1; i <= n; i++)
		if (point[i] == i)
			g << "0 ";
		else
			g << point[i] << " ";
	return 0;
}