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

int  main()
{
	
	fast();
	int a[505][505];
	int w, h, n;

	while (cin >> w >> h >> n )
	{
		if (!h && !w && !n) break;
		vector<pair<int, int>>vs, ve;
		int x1, y1, x2, y2, sm = 0;;
		for (int i = 0;i < n;i++)
		{
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2) swap(x1, x2);
			if (y1 > y2) swap(y1, y2);
			vs.push_back({ x1,y1 });
			ve.push_back({ x2,y2 });
		}
		for (int i = 1;i <= w;i++)
		{
			for (int j = 1;j <= h;j++)
			{
				a[i][j] = 1;
			}
		}
		for (int i = 0;i < n;i++)
		{
			
			for (int j = vs[i].first;j <= ve[i].first;j++)
			{
				for (int jj = vs[i].second;jj <= ve[i].second;jj++)
				{
					a[j][jj] = 0;
				}
			}
			
		}
		
		for (int i = 1;i <= w;i++)
		{
			for (int j = 1;j <= h;j++)
			{
				if (a[i][j]) sm++;
			}
		}
		if (!sm) cout << "There is no empty spots.\n" ;
		else if (sm == 1) cout << "There is one empty spot.\n";
		else cout <<"There are "<<sm<<" empty spots.\n";
	}
}