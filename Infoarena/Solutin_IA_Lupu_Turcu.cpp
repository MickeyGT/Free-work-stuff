#include<fstream>
#include<string.h>
#include<ctype.h>
#include<iostream>
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
#include<iomanip>
#include<bitset>
using namespace std;
int n,i,j,k,el,nr,ok,x,l,lana,dist;
long long rez;
multimap<int, int,greater<int>>oi;
multimap<int, int,greater<int>>::iterator it;
priority_queue<int>prque;
int main()
{
    //ifstream f("file.in");
    //ofstream g("file.out");
    ifstream f("lupu.in");
    ofstream g("lupu.out");
    f >> n >> x >> l;
    for (i = 1; i <= n; i++)
    {
        f >> dist >> lana;
        if (dist <= x)
        {
            dist = (x - dist) / l + 1;
            oi.insert(make_pair(dist, lana));
        }
    }
    it = oi.begin(); 
    dist = it->first;
    while (dist)
    {
        while (it != oi.end() && dist == it->first)
        {
            prque.push(it->second);
            it++;
        }
        if (!prque.empty())
        {
            rez += (long long)prque.top();
            prque.pop();
        }
        dist--;
    }
    g << rez;
    return 0;
}