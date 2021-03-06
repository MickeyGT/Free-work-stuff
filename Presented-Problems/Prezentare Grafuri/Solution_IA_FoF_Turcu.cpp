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
#include<bitset>
using namespace std;
struct nod
{
    int who;
    vector<int>vecini;
}user[1010];
int n, m, i, x, y, j,max1;
struct classcomp {
    bool operator() (int lhs, int rhs)
    {
        return lhs>rhs;
    }
};
multimap<int, int,classcomp>commfr;
multimap<int, int,classcomp>::iterator it;
int vec[1010];
deque<int>deq;
int main()
{
    //ifstream f("file.in");
    //ofstream g("file.out");
    ifstream f("fof.in");
    ofstream g("fof.out");
    f >> n >> m;
    for (i = 1; i <= m; i++)
    {
        f >> x >> y;
        user[x].vecini.push_back(y);
        user[y].vecini.push_back(x);
    }
    for (j = 1; j <= n; j++)
    {
        commfr.clear();
        deq.clear();
        memset(vec, 0, sizeof(vec));
        for (i = 1; i <= user[j].vecini.size(); i++)
        {
            deq.push_back(user[j].vecini[i - 1]);
        }
        while (deq.size())
        {
            int el = *deq.begin();
            vec[el] = 1 << 31;
            deq.pop_front();
            for (i = 1; i <= user[el].vecini.size(); i++)
            {
                vec[user[el].vecini[i - 1]]++;
            }
        }
        vec[j] = 1 << 31;
        for (i = 1; i <= n; i++)
            if(i!=j&&vec[i]>0)
            commfr.insert(make_pair(vec[i], i));
        it = commfr.begin();
        while (it != commfr.end())
        {
            if (it->first >=0)
                g << it->second << ' ';
            if (it != commfr.end())
                it++;
        }
        g << '\n';
    }
    return 0;
}