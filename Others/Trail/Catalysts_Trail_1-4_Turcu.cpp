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
long long i, j, k, ok, nr, n, m, el, x, y, a, b,l,total,orientatie,nror,maxx,maxy,minx,miny,mat[300][300][4],viz[300][300],rez;
string s,all;
deque<pair<int, int>>que;
pair<int, int>ex;
vector<int>pozx[300], pozy[300];
vector<int>::iterator it;
void bfs()
{
	while (que.size() != 0)
	{
		int dim = que.size();
		for (j = 1; j <= dim; j++)
		{
			ex = que.front();
			pozy[ex.first].push_back(ex.second);
			pozx[ex.second].push_back(ex.first);
			que.pop_front();
			if (ex.first>1&&viz[ex.first - 1][ex.second] == 0&&mat[ex.first][ex.second][1]==0)
			{
				viz[ex.first - 1][ex.second] = 1;
				que.push_back({ ex.first - 1 ,ex.second });
				nr++;
			}
			if (ex.second<299&&viz[ex.first][ex.second + 1] == 0 && mat[ex.first][ex.second][2] == 0)
			{
				viz[ex.first][ex.second + 1] = 1;
				que.push_back({ ex.first,ex.second + 1 });
				nr++;
			}
			if (ex.first<299&&viz[ex.first + 1][ex.second] == 0 && mat[ex.first][ex.second][3] == 0)
			{
				viz[ex.first + 1][ex.second] = 1;
				que.push_back({ ex.first + 1 ,ex.second });
				nr++;
			}
			if (ex.second >1&&viz[ex.first][ex.second - 1] == 0 && mat[ex.first][ex.second][0] == 0)
			{
				viz[ex.first][ex.second - 1] = 1;
				que.push_back({ ex.first,ex.second - 1 });
				nr++;
			}
		}
	}
}
int main()
{
	//ifstream f("file.in");
	//ofstream g("file.out");
	cin >> l;
	for(k=1;k<=l;k++)
	{
		cin >> s >> x;
		for (j = 1; j <= x; j++)
		{
			for (i = 0; i <= s.size() - 1; i++)
				all += s[i];
		}
		nr = 0;
		for (i = 0; i <= s.size() - 1; i++)
			if (s[i] == 'F')
				nr++;
		total += nr*x;
	}
	orientatie = 0;
	x = y = 150;
	maxx = minx = maxy = miny = 150;
	for (i = 0; i <= all.size() - 1; i++)
	{
		if (all[i] == 'F')
		{
			if (orientatie == 0)
			{
				mat[x][y][0] = 1;
				mat[x][y - 1][2] = 1;
				x--;
				minx = min(minx, x);
			}
			else
				if (orientatie == 1)
				{
					mat[x][y][3] = 1;
					mat[x + 1][y][1] = 1;
					y++;
					maxy = max(maxy, y);
				}
				else
					if (orientatie == 2)
					{
						x++;
						mat[x][y][0] = 1;
						mat[x][y -1][2] = 1;
						maxx = max(maxx, x);
					}
					else
						if (orientatie == 3)
						{
							y--;
							mat[x][y][3] = 1;
							mat[x + 1][y][1] = 1;	
							miny = min(miny, y);
						}
		}
		else
		{
			if (all[i] == 'R')
			{
				if (orientatie == 0)
				{
					orientatie = 1;
				}
				else
					if (orientatie == 1)
					{
						orientatie = 2;
					}
					else
						if (orientatie == 2)
						{
							orientatie = 3;
						}
						else
							if (orientatie == 3)
							{
								orientatie = 0;
							}
			}
			else
			{
				if (orientatie == 0)
				{
					orientatie = 3;
				}
				else
					if (orientatie == 1)
					{
						orientatie = 0;
					}
					else
						if (orientatie == 2)
						{
							orientatie = 1;
						}
						else
							if (orientatie == 3)
							{
								orientatie = 2;
							}
			}
		}
	}
	nr = 1;
	que.push_back({ 150,146 });
	viz[150][146] = 1;
	bfs();
	cout << total<<" "<<(maxx-minx)*(maxy-miny)<<" "<<nr<<" ";
	for (i = 1; i <= 299; i++)
	{
		sort(pozx[i].begin(),pozx[i].end());
		sort(pozy[i].begin(), pozy[i].end());
	}
	for(i=minx;i<=maxx;i++)
		for (j = miny; j <= maxy; j++)
			if(viz[i][j]==0)
			{
				it = lower_bound(pozx[j].begin(), pozx[j].end(), i);
				if (it != pozx[j].end())
				{
					int poz = it - pozx[j].begin();
					if (poz != 0)
					{
						rez++;
						continue;
					}
				}
				it = lower_bound(pozy[i].begin(), pozy[i].end(), j);
				if (it != pozy[i].end())
				{
					int poz = it - pozy[i].begin();
					if (poz != 0)
					{
						rez++;
						continue;
					}
				}
			}
	cout << rez;
	return 0;

}