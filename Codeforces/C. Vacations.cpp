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
using namespace std;
int n, daybefore, current, i, vac;
int main()
{
	cin >> n;
	cin >> daybefore;
	while (daybefore == 0 && n)  // Case for when it starts with multiple 0's.
	{
		n--;
		vac++;
		cin >> daybefore;
	}
	for (i = 2; i <= n; i++)
	{
		cin >> current;
		if (daybefore == 0)
		{
			daybefore = current;
			if (current == 0)  // Case for multiple 0's inside the array.
				vac++;   
			continue;
		}
		if (daybefore == 1)
		{
			if (current == 0)  // One free day is required due to 0.
			{
				daybefore = 0;
				vac++;
				continue;
			}
			if (current == 1)
			{
				daybefore = 0;
				vac++;        // 1 after 1 means we have to take a day off.
				continue;
			}
			if (current == 2)    // 1 and 2 combination means we can just skip to next day.
			{
				daybefore = current;
				continue;
			}
			if (current == 3)  // If the day before was 1 and now we have a 3, we must transform it into a 2.
			{
				daybefore = 2;
				continue;
			}
		}
		if (daybefore == 2)
		{
			if (current == 0)  // One free day is required due to 0.
			{
				daybefore = 0;
				vac++;
				continue;
			}
			if (current == 1)
			{
				daybefore = current;     // 2 and 1 combination means we can just skip to next day.
				continue;
			}
			if (current == 2)   
			{
				daybefore = 0;
				vac++;   // 2 after 2 means we have to take a day off.
				continue;
			}
			if (current == 3)  // If the day before was 2 and now we have a 3, we must transform it into a 1.
			{
				daybefore = 1;
				continue;
			}
		}
		if (daybefore == 3 && current == 0)    // The case when the 0 isn't counted because 3 is normally skipped until a 2 or 1 arrives.
		{
			vac++;
			daybefore = current;
			continue;
		}
		daybefore = current;   // Day cycle for the cases that don't have it mentioned.
	}
	cout << vac;   
	return 0;
}