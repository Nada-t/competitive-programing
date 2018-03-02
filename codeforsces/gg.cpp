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
long long comb(int x,int y)
{
	long long cm = 1;
	for (int i = y+1,j = 1;i <= x;i++, j++)
	{
		cm *= i;
		cm /= j;
	}
	//cout << x << " " << y << " " << cm << endl;
	return  cm;
}
int main()
{
	fast();
	int n, m, t, x, y;
	long long sum = 0;

	cin >> n >> m >> t;
	
	if (n + m == t)
	{
		cout << 1 << endl;
		return 0;
	}
		
	int b = 4;
	int g = t - b;
	for (int i = 0;i < (t-b);i++)
	{
		if (((g - i) <= m && (b + i) <= n))
		sum += comb(n, (b + i))*comb(m, (g - i));
	}
	cout << sum << endl;
}