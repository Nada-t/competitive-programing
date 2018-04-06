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
long long cnt = 0;
void merge(int a[], int st, int md, int en)
{
	vector<int> v;
	int s1 = st, s2 = md + 1;
	
	for (int i = st; i <= en;i++)
	{
		if (s1 > md) v.push_back(a[s2++]);
		 
		else if (s2 > en) v.push_back(a[s1++]);

		else if (a[s1] > a[s2])
		{
			v.push_back(a[s2++]);
			cnt += ((md + 1) - s1);
		}
		else v.push_back(a[s1++]);
	}
	for (int i = 0;i < v.size();i++)
	{
		a[st++] = v[i];
	}
}
void mergesort(int a[], int st, int en)
{
	if (st < en) 
	{
		int md = (st + en) / 2;

	    mergesort(a, st, md);
		mergesort(a, md + 1, en);
		merge(a, st, md, en);
	}
}
int  main()
{
	fast();
	int t;
	cin >> t;
	while(t--)
	{
		int a[200005], n;
		cnt = 0;

		cin >> n;
		for (int i = 0;i < n;i++)
			cin >> a[i];

	    mergesort(a, 0, n - 1);
		cout << cnt << endl;
	}
}