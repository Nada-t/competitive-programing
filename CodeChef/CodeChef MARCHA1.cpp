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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, a[100000], sm = 0, b = 0;
		
		cin >> n >> m;
		for (int i = 0;i < n;i++)
			cin >> a[i];

		for (int i = 0;i < (1 << n);i++)
		{
			sm = 0;
			for (int j = 0;j < n;j++)
			{
				if (i&(1 << j))
				{
					//cout << a[j] << " " << i << endl;
					sm += a[j];
				}
			}
			if (sm == m)
			{
				b = 1;
			}
		}
		if(b) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}
