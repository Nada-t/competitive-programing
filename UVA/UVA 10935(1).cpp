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
		deque<int> d;
		vector<int> vv;

		for (int i = 1;i <=n ;i++)
			d.push_back(i);

		int idx = 0;
		while (d.size() > 1)
		{
			if (!d.empty()) vv.push_back(d.front());
			d.pop_front();
			if (!d.empty()) d.push_back(d.front());
			d.pop_front();
		}
		cout << "Discarded cards:";
			for (int i = 0;i < vv.size();i++)
			{
				cout << " " << vv[i];
				if (i < vv.size() - 1) cout << ",";
			}
			cout << "\n";
			cout << "Remaining card: " << d.back() << "\n";

	}

	

}