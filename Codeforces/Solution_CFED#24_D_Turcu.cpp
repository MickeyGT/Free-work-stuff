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
long long i, j, k, nr, n, m, el, min1, max1, x, y, a, b,v[100100],fr[1001000],ok[1001000];
deque<long long>deq,apar,temp;
int main()
{
	//ifstream f("file.in");
	//ofstream g("file.out");
	cin >> n >> a;
	for (i = 1; i <= n; i++)
		cin >> v[i];
	for (i = 1; i <= n; i++)
		if(v[i]==a)
		{
			apar.push_back(i);
		}
	if (apar.size() == 0)
	{
		cout << 42;
		return 0;
	}
	else
	{
		for (i = 1; i < *apar.begin(); i++)
		{
			if (ok[v[i]] == 0)
			{
				deq.push_back(v[i]);
				ok[v[i]] = 1;
			}
			fr[v[i]]++;
		}
		if (deq.size() == 0)
		{
			cout << "-1";
			return 0;
		}
		fr[v[i]]++;
		i++;
		apar.pop_front();
		for (auto it = apar.begin(); it != apar.end(); it++)
		{
			while (i != *it&&i<=n)
			{
				fr[v[i]]++;
				i++;
			}
			fr[v[i]]++;
			i++;
			for(auto iter=deq.begin();iter!=deq.end();iter++)
				if (fr[*iter] >= fr[a])
				{
					temp.push_back(*iter);
				}
			deq.clear();
			deq = temp;
			temp.clear();
			if (deq.size() == 0)
			{
				cout << "-1";
				return 0;
			}
		}
		cout << *deq.begin();
		return 0;
	}
	return 0;
}