#include<fstream>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<array>
#include<deque>
#include<math.h>
#include<unordered_set>
#include<set>
#include<iomanip>
#include<bitset>
using namespace std;
int n, i, j, k, nr, viz[255][255], dist, rez[255][255];
char mat[255][255];
deque<pair<int, int>>que;
pair<int, int>x;
void bfs()
{
	//cat timp mai am elemente in coada, il iau pe primul si testez vecini.
	while (que.size() != 0)
	{
		int dim = que.size();
		for (j = 1; j <= dim; j++)
		{
			x = que.front();
			//updatam rezultatul pentru celula curenta cu distanta la care suntem.
			rez[x.first][x.second] = dist;
			que.pop_front();
			//pentru cei 4 vecini(N,S,E,V) ii bagam in coada daca nu au mai fost vizitati si ii vizitam.
			if (x.first - 1 >= 1 && viz[x.first - 1][x.second] == 0)
			{
				viz[x.first - 1][x.second] = 1;
				que.push_back({ x.first - 1 ,x.second });
			}
			if (x.second + 1 <= n && viz[x.first][x.second + 1] == 0)
			{
				viz[x.first][x.second + 1] = 1;
				que.push_back({ x.first,x.second + 1 });
			}
			if (x.first + 1 <= n&&viz[x.first + 1][x.second] == 0)
			{
				viz[x.first + 1][x.second] = 1;
				que.push_back({ x.first + 1 ,x.second });
			}
			if (x.second - 1 >= 1 && viz[x.first][x.second - 1] == 0)
			{
				viz[x.first][x.second - 1] = 1;
				que.push_back({ x.first,x.second - 1 });
			}
		}
		//marim distanta curenta.
		dist++;
	}
}
int main()
{
	//ifstream f("file.in");
	//ofstream g("file.out");
	ifstream f("muzeu.in");
	ofstream g("muzeu.out");
	f >> n;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
		{
			f >> mat[i][j];
			if (mat[i][j] == 'P')
			{
				//daca avem un paznic, adaugam coordonatele in coada pentru bfs si il marcam ca vizitat.
				que.push_back({ i,j });
				viz[i][j] = 1;
			}
			else
				if (mat[i][j] == '#')
					//semnalam cu -1 ca sa stim sa afisam -2 la final.
					viz[i][j] = -1;
		}
	bfs();
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			//daca a fost semnalat ca perete inca de la inceput.
			if (viz[i][j] == -1)
				g << "-2 ";
			else
				//daca nu a fost semnalat ca perete si nici nu a fost vizitat vreodata.
				if (viz[i][j] == 0)
					g << "-1 ";
				else
					g << rez[i][j] << " ";
		}
		g << '\n';
	}
	return 0;
}