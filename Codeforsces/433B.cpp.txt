#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#include<complex>
#include<sstream>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;
void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
}
int main()
{
	fast();
	int n, m, ty, l, r;
	unsigned long long a[100005], b[100005];

	cin >> n;
	a[0] = 0;
	b[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b , b + n + 1);
	for (int i = 1;i <= n;i++)
	{
		a[i] += a[i - 1];
		b[i] += b[i - 1];
	}
	cin >> m;
	for (int i = 0;i < m;i++)
	{
		cin >> ty >> l >> r;
		if (ty == 1)
			cout << a[r] - a[--l] << endl;
		else
			cout << b[r] - b[--l] << endl;

	}

}