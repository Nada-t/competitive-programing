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

	int n;
	while (cin >> n )
	{
		if (!n) break;
		int x;
		while (cin >> x)
		{
			if (!x) break;
			
			vector<int> v, vv;
			stack<int> st;
			
			v.push_back(x);
			for (int i = 0;i < n - 1;i++)
			{
				cin >> x;
				v.push_back(x);
			}
			vv = v;
			sort(vv.begin(), vv.end());
			int idx = 0;
			
			for (int i = 0;i < v.size();i++)
			{
				if (((st.empty()) || (!st.empty() && st.top() != v[i])) && vv[idx] != v[i] && idx < vv.size())
				{
					while (1 && idx < vv.size())
					{	
						if(vv[idx] != v[i]) 
							st.push(vv[idx]);
						else
						{
							if (idx + 1 < v.size()) idx++;
							v[i] = -1;
							break;
						}
						idx++;
					}
					if (idx >= vv.size()) idx = vv.size() - 1;
				}
				else if (!st.empty() && st.top() == v[i])
				{
					st.pop();
					v[i] = -1;
				}
				else if (vv[idx] == v[i] && idx < vv.size())
				{
					idx++;
					v[i] = -1;
				}

			}
			bool b = 0;
			for (int i = 0;i < v.size();i++)
			{
				if (v[i] != -1)
				{
					b = 1;
				}
			}
			if (b) cout << "No\n";
			else cout << "Yes\n";
		}
		cout << "\n";
	}

	

}