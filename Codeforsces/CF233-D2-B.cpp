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
int sod(int x)
{
	int sm = 0;
	while (x)
	{
		sm += (x % 10);
		x /= 10;
	}
	return sm;
}
int  main()
{
	fast();
	long long n, x, y;

	cin >> n;
	x = sqrt(n);
	y = x - sqrt(x);
	for (long long i = y;i*i<= n;i++)
	{
		if ((i*i) + (sod(i)*i) == n)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}