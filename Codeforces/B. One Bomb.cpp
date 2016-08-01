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
int n, m, i, j, frl[1001], frc[1001], x, y, maxc, maxl, nr, nrb, k;
char mat[1001][1001];
int main()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		{
			cin >> mat[i][j];
			if (mat[i][j] == '*')
			{
				frl[i]++;              // Finding out the number of bombs on each line.
				frc[j]++;              // Finding out the number of bombs on each column.
				nr++;				   // Total number of bombs.
			}
		}
	maxl = -1;
	x = 1;
	for (i = 1; i <= n; i++)
	{
		if (frl[i] > maxl)
		{
			maxl = frl[i];             // The maximum number of bombs on all lines.
			x = i;
		}
	}
	maxc = -1;
	y = 1;
	for (i = 1; i <= m; i++)
	{
		if (frc[i] > maxc)
		{
			maxc = frc[i];             // The maximum number of bombs on all columns.
			y = i;
		}
	}
	for (i = 1; i <= n; i++)    // We add to the bomb total, the number of bombs on the y'th column.
		if (mat[i][y] == '*')
		{
			nrb++;
		}
	for (i = 1; i <= m; i++)   // We add to the bomb total, the number of bombs on the x'th line.
		if (mat[x][i] == '*')
		{
			nrb++;
		}
	if (mat[x][y] == '*')    // Because we counted both x line and y column, we need to see if there's a bomb on mat[x][y]. If there is, we counted it twice. So we need to decrease the number of bombs by 1.
		nrb--;
	if (nrb == nr)     // If we found all the bombs then that is the correct answer.
	{
		cout << "YES\n";
		cout << x << " " << y;
		return 0;
	}
	else
		if (nrb == nr - 1)  // The case for if we're having all bombs on a line or a column except one.
		{
			if (maxl > maxc) // See if it's line or column.
			{
				for (k = 1; k <= m; k++)  
					if (frc[k] == 1)
					{
						y = k;        // We found a lonely bomb on a line. Need to check if that's all of them now.
						nrb = 0;
						for (i = 1; i <= n; i++)
							if (mat[i][y] == '*')
							{
								nrb++;
							}
						for (i = 1; i <= m; i++)
							if (mat[x][i] == '*')
							{
								nrb++;
							}
						if (mat[x][y] == '*')
							nrb--;
						if (nrb == nr)
						{
							cout << "YES\n";
							cout << x << " " << y;
							return 0;
						}
					}
			}
			else
			{
				for (k = 1; k <= n; k++)
					if (frl[k] == 1)
					{
						x = k;        // We found a lonely bomb on a column. Need to check if that's all of them now.
						nrb = 0;
						for (i = 1; i <= n; i++)
							if (mat[i][y] == '*')
							{
								nrb++;
							}
						for (i = 1; i <= m; i++)
							if (mat[x][i] == '*')
							{
								nrb++;
							}
						if (mat[x][y] == '*')
							nrb--;
						if (nrb == nr)
						{
							cout << "YES\n";
							cout << x << " " << y;
							return 0;
						}
					}
			}
		}
	cout << "NO";   // If the cases above don't work, it means there are no correct answers.
	return 0;
}