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
int n, i, min1, n1, n2;
char c1, c2;
vector <int> vec;
vector <int> ::iterator it;
int main()
{
	cin >> n;
	cin >> c1; // Read the first character.
	for (i = 2; i <= n; i++)
	{
		cin >> c2;
		if (c1 == 'R'&&c2 == 'L')
			vec.push_back(i);  // We keep in the vec all the positions where we have one R next to an L.
		c1 = c2;
	}
	cin >> n1; // Read the first number.
	if (vec.size() != 0)
	{
		it = vec.begin();
		min1 = 1 << 30;  // In min1 we will store the minimum distance between a pair of particles RL.
		for (i = 2; i <= n; i++)
		{
			cin >> n2;
			if (*it == i)  // If our current element is in the vector, that means the two numbers belong to one RL pair that we need to check for minimum.
			{
				if (min1 > (n2 - n1) / 2)   //  We need to divide by 2 because both particles will be moving towards each-other with the same speed so they will meet halfway everytime.
					min1 = (n2 - n1) / 2;
				if (it != vec.end() - 1)  // If we still have pairs of RL in the vector, we increase the iterator.
					it++;
			}
			n1 = n2;
		}
		cout << min1;
	}
	else
		cout << -1;  // If the vector is empty, that means that there are no RL pairs which means no 2 particles will ever collide, therefore printing -1.
	return 0;
}