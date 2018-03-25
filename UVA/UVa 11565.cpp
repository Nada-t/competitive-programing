#define _CRT_SECURE_NO_WARNINGS
#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <cstdio>
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int a, b, c;
bool check(int x, int y, int z)
{
	if (((x + y + z) != a) || ((x*y*z) != b) || (((x*x) + (y*y) + (z*z)) != c))
		return 0;

	return 1;
}
int  main()
{
	fast();
	int n;

	cin >> n;
	while (n--)
	{
		bool p = 0;
		cin >> a >> b >> c;

		for (int i = -1000;i <= 1000;i++)
		{
			for (int j = i + 1;j <= 1000;j++)
			{
				if ((a - (i + j) != i) && (a - (i + j) != j) && (check(i, j, a - (i + j))))
				{
					cout << i << " " << j << " " << a - (i + j) << endl;
					i = 2000;
					p = 1;
					break;
				}
			}
		}
		if (!p) cout << "No solution." << endl;
	}
}