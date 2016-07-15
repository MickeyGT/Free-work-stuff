#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <list>
#include <bitset>
#include <vector>
using namespace std;
unsigned int g1, g2, g3;
void f(unsigned char jan, unsigned char jac, unsigned char jbn, unsigned char jbc, bool r)
{
	static int A[99][9], b, c, d, e, f, g, h;
	int w = jan, x = jbn, y = jac, z = jbc;
	char s[9][99] = { "Invalid\n","Jucator curent:a\n","Jucator curent:b\n" };
		
	if (A[w][y] | A[x][z] | w == x & y == z)
		cout << s[0];
	else
	{
		d++;
		A[w][y] = A[x][z] = 1;
		r ? f = e : e = f;
		if (r)
			e % 2 ? d < 16 ? cout << s[2], 1 : 0 : d < 16 ? cout << s[1], 1 : 0;
		else
			if (e % 2)
				c += h, d < 16 ? cout << s[2], 1 : 0;
			else
				b += h, d < 16 ? cout << s[1], 1 : 0;

		!r ? h = 0, f % 2 ? g = x : g = w : 0;

		w > 9 & w < 12 ? h++ : 0;
		x > 9 & x < 12 ? h++ : 0;
		f % 2 ? w == g | w < 8 ? f++ : 0 : x == g | x < 8 ? f++ : 0;
		d > 15 ? h ? f % 2 == 0 ? b += h : c += h : 0, cout << "Final joc:" << b << "-" << c << endl, memset(A, 0, 891), f = d = b = c = h = g = f = e = 0 : 0;
	}
}
int main(int argc, char **argv)
{
	ifstream g("a.in");
	g1 = 0, g2 = 0, g3 = 0;
	unsigned int e1, e2, e3, e4, e5;
	while (g >> e1 >> e2 >> e3 >> e4 >> e5)
		f(e1, e2, e3, e4, e5);
	return 0;
}
