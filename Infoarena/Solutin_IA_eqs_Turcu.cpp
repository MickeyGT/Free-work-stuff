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
#include<functional>
#include<unordered_set>
#include<set>
#include<iomanip>
#include<bitset>
using namespace std;
int i, j, k, l, ok, nr,rez,x1,x2,x3,x4,x5;
unordered_map<int,int>mp;
unordered_map<int,int>::iterator it;
int main()
{
    //ifstream f("file.in");
    //ofstream g("file.out");
    ifstream f("eqs.in");
    ofstream g("eqs.out");
    f >> x1 >> x2 >> x3 >> x4 >> x5;
    for (i = -50; i <= 50; i++)
        for (j = -50; j <= 50; j++)
            if (i != 0 && j != 0)
            {
                mp[x4 * i * i * i + x5 * j * j * j]++;
                 
            }
    for (i = -50; i <= 50; i++)
        for (j = -50; j <= 50; j++)
            for (k = -50; k <= 50; k++)
                if (i != 0 && j != 0 && k != 0)
                {
                    it=mp.find(i*i*i*x1 + j*j*j*x2 + k*k*k*x3);
                    if(it!=mp.end())
                        rez += it->second;
                }
    g << rez;
    return 0;
}