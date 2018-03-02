
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
	int a1, a2, a3, b1, b2, b3, n;

	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> n;

	int s1 = a1 + a2 + a3;
	int s2 = b1 + b2 + b3;

	if (s1 % 5 == 0)s1 /= 5;
	else s1 /= 5, s1++;

	if (s2 % 10 == 0)s2 /= 10;
	else s2 /= 10, s2++;

	if (s1 + s2 <= n)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}