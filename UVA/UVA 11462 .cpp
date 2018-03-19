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
	int n, a[2000001];

	while (scanf("%d", &n) && n > 0)
	{
		for (int i = 0;i < n;i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		for (int i = 0; i < n-1; i++)
		{
			printf("%d ", a[i]);
		}
		printf("%d\n", a[n - 1]);
	}

}