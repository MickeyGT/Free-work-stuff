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
int n, k, santa, mickey,t,i,j,nin,nr;
int main()
{
    //ifstream f("file.in");
    //ofstream g("file.out");
    ifstream f("mere.in");
    ofstream g("mere.out");
    f >> t;
    for (j = 1; j <= t; j++)
    {
        f >> n >> k;
        nr = n / k;
        if (nr == 0)
            g << "Remiza\n";
        else
            if ((nr % 2 == 0)&&(n%k==0))
                g << "Remiza\n";
            else
                g << "Santa Klaus\n";
    }
    return 0;
}