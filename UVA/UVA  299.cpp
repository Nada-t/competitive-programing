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
		int n, a[55], fi = 0, idx = 0, sm = 0, mn = 1e9, z = 0;
		
		cin >> n;
		for (int i = 0;i < n;i++)
		{
			cin >> a[i];
			mn = min(mn, a[i]);
		}
		while (z < n)
		{
			for (int i = z+1;i < n;i++)
			{
				if (a[z] > a[i])
				{
					swap(a[i], a[z]);
					sm++;
				}
			}
			z++;
		}
		
		cout <<"Optimal train swapping takes "<<sm<<" swaps."<< endl;
	}
}