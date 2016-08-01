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
int n, m, i, nr, j, el, k, t, p, ok;
int mat[51][51], in[51][51];
int main()
{
	ifstream f("rfinv.in");
	ofstream g("rfinv.out");
	f >> t;  // Numarul de teste
	for (p = 1; p <= t; p++)  
	{
		f >> n >> m;
		memset(mat, 0, sizeof(mat));  // Re-initializam cu 0 matricile mat si in.
		memset(in, 0, sizeof(in));
		for (k = 1; k <= m; k++)
		{
			f >> i >> j;
			mat[i][j] = 1;    // Notam in  matricea mat cu 1 daca avem muchie de la i la j sau invers.
			mat[j][i] = 1;
		}
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
			{
				f >> in[i][j];         // In matriea in stocam toate costurile pe care le primim ca input.
				if (mat[i][j] == 1)     // In cadrul citirii, daca avem muchie atunci punem costul in matricea mat.
					mat[i][j] = in[i][j];  
			}
		for (k = 1; k <= n; k++)
			for (i = 1; i <= n; i++)
				for (j = 1; j <= n; j++)
				{
					if (mat[i][k] != 0 && mat[k][j] != 0 && (mat[i][j] > mat[i][k] + mat[k][j] || !mat[i][j]) && i != j)
						mat[i][j] = mat[i][k] + mat[k][j];
				}                      // Aplicam algoritmul lui Floyd-Warshall/Roy-Floyd de formare a matricei drumurilor minime pe matricea mat.
		ok = 1;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (mat[i][j] != in[i][j])    // Vedem daca matricea mat este aceasi cu matricea intiala in.
					ok = 0;
		if (ok)      // Daca matricile sunt aceleasi, atunci afisam Da, altfel afisam Nu.
			g << "DA\n";
		else
			g << "NU\n";
	}
	return 0;
}