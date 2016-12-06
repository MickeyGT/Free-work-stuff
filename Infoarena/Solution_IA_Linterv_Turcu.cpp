#include<fstream>
#include<string.h>
#include<ctype.h>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<array>
#include<deque>
#include<queue>
#include<math.h>
#include<functional>
#include<unordered_set>
#include<set>
#include<iostream>
#include<iomanip>
#include<bitset>
using namespace std;
int t, k, i, j, ok, nr, n,x,y,stmax,dist;
vector<pair<int, int>>v;
vector<pair<int, int>>::iterator it, iter;
int main()
{
    //ifstream f("file.in");
    //ofstream g("file.out");
    ifstream f("linterv.in");
    ofstream g("linterv.out");
    f >> t;
    for (k = 1; k <= t; k++)
    {
        f >> n;
        for (i = 1; i <= n; i++)
        {
            f >> x >> y;
            v.push_back({ x,y });
        }
        sort(v.begin(), v.end());
        it = v.begin();
        stmax = it->second;
        dist += it->second - it->first;
        if (it != v.end())
            it++;
        while (it != v.end())
        {
            if (it->first > stmax)
            {
                dist += it->second - it->first;
                stmax = it->second;
            }
            else
            {
                if (it->second > stmax)
                {
                    dist += it->second - stmax;
                    stmax = it->second;
                }
            }
            it++;
        }
        v.clear();
        g << dist << '\n';
        dist = 0;
        stmax = 0;
    }
    return 0;
}