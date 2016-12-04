#include<fstream>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<deque>
#include<math.h>
#include<set>
#include<functional>
#include<iomanip>
using namespace std;
// 
map<double, double, greater<double>>mp;
map<double, double, greater<double>>::iterator it, iter, itr;
int i, j, k, nr, n, c, x, y;
double maxx, maxy, panta, coordx, rez;
int main()
{
	cin >> c;
	// pentru fiecare test in parte
	for (k = 1; k <= c; k++)
	{
		//golim map-ul de punctele anterioare.
		mp.clear();
		rez = maxy = 0;
		cin >> n;
		//citim punctele si le avem stocate sortat in map.
		for (i = 1; i <= n; i++)
		{
			cin >> x >> y;
			mp.insert(make_pair(x, y));
		}
		it = mp.begin();
		maxy = it->second;
		if (it != mp.end())
		{
			iter = it;
			iter++;
		}
		while (iter != mp.end())
		{
			if (iter->second > maxy)
			{
				// calculam panta dreptei
				panta = (iter->second - it->second) / (iter->first - it->first);
				// calculam coordonata x a intersectiei paralelei cu ox cu dreapta noastra
				coordx = ((-1 * (iter->second - maxy)) / panta) + iter->first;
				// adaugam la rezultat distanta dintre cele 2 puncte, cel din varf si cel din intersectie
				rez += sqrt((coordx - iter->first)*(coordx - iter->first) + (maxy - iter->second)*(maxy - iter->second));
				// trecem la urmatorul varf
				maxy = iter->second;
			}
			it = iter;
			iter++;
		}
		cout << fixed << setprecision(2) << rez << '\n';
	}
	return 0;
}