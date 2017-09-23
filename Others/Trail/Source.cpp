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
long long i, j, k, ok, nr, n, m, el, min1, max1, x, y, a, b;
bool isprime[6798280];
vector<int>primes;
deque<string>deq;
string number,nrtotest;
bool isprimetest(string number)
{
	string::size_type sz = 0;
	long long nmbr = stoll(number, &sz, 0);
	for (auto it = primes.begin(); it != primes.end(); it++)
		if (nmbr <= *it)
			return true;
		else
			if (nmbr%(*it) == 0)
				return false;

}
int main()
{
	//ifstream f("file.in");
	//ofstream g("file.out");
	isprime[1] = 1;
	isprime[0] = 1;
	for (i = 2; i <= 6798268; i++)
		if (isprime[i] == 0)
			for (j = 2; j <= 6798268 / i; j++)
				isprime[j*i] = 1;
	for (i = 2; i <= 6798268; i++)
		if (isprime[i] == 0)
			primes.push_back(i);
	cin >> number;
	deq.push_back(number);
	while (deq.size() != 0)
	{
		number = deq.front();
		deq.pop_front();
		if (number.length() == 1)
		{
			if(number[0]!='1'&&number[0] != '0')
				nr++;
		}
		else
		{
			nrtotest = number.substr(1, number.size() - 1);
			if (nrtotest[0]!='0'&&isprimetest(nrtotest))
				deq.push_back(nrtotest);
			for (i = 1; i <= number.size() - 1; i++)
			{
				nrtotest = number.substr(0, i) + number.substr(i + 1, number.size());
				if (isprimetest(nrtotest))
					deq.push_back(nrtotest);
			}
		}
	}
	cout << nr;
	return 0;
}