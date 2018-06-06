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
#include <stdio.h>
#include <string.h>
#include <cstdio>
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}

int n, a[12], dp[12][12] ;
int lis(int i, int pre, int len1 = 0, int len2 = 0)
{
	if (i == n) return 0;

	if (dp[i][pre] != -1) return dp[i][pre];

    len1 = lis(i + 1, pre);
	
	if (a[i] > a[pre]) len2 = 1 + lis(i + 1, i);

	return dp[i][pre] = max(len1, len2);
}
int  main()
{
	fast();
	memset(dp, -1, sizeof dp);

	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> a[i];

	cout << lis(0, n) << endl;
}
