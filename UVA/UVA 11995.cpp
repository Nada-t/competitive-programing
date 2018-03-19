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
bool check(vector<int> v1,vector<int> v2)
{
	for (int i = 0;i < min(v1.size(), v2.size());i++)
	{
		if (v1[i] != v2[i]) return 0;
	}
	return 1;
}
int  main()
{
	fast();
	int n;
	while (cin >> n)
	{
		int x, y, sm = 0, b1 = 0, b2 = 0, b3 = 0;
		queue<int> q;
		priority_queue<int> pq;
		stack<int> st;

		for (int i = 0;i < n;i++)
		{
			cin >> x >> y;
			if (x == 1)
			{
				q.push(y);
				pq.push(y);
				st.push(y);
			}
			else
			{
				sm++;
				if (!q.empty() && y == q.front())
				{
					q.pop();
					b1++;
				}
				if (!pq.empty() && y == pq.top())
				{
					pq.pop();
					b3++;
				}
				if (!st.empty() && y == st.top())
				{
					st.pop();
					b2++;
				}
			}
		}
		if ((b1 == sm && b2 == sm) || (b1 == sm && b3 == sm) || (b3 == sm  && b2 == sm) || (b3 == sm && b2 == sm && b1 == sm)) cout << "not sure" << endl;
		else if (b2 == sm) cout << "stack" << endl;
		else if (b3 == sm) cout << "priority queue" << endl;
		else if (b1 == sm) cout << "queue" << endl;
		else cout << "impossible" << endl;
	}
	
}