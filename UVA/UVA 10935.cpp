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
	
	//fast();

	int n;
	while (cin >> n && n)
	{
		vector<int> v, vv;

		for (int i = 1;i <= n;i++)
			v.push_back(i);

		int idx = 0;
		while (idx < v.size() - 1)
		{
			vv.push_back(v[idx]);
			idx++;
			v.push_back(v[idx]);
			idx++;
		}
		cout << "Discarded cards:";
		for (int i = 0;i < vv.size();i++)
		{
			cout << " " << vv[i];
			if (i < vv.size() - 1) cout << ",";
		}
		cout << "\n";
		cout << "Remaining card: " << v[v.size() - 1] << "\n";

	}


	

}