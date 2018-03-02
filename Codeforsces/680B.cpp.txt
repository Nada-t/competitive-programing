#include<iostream>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int a,n,t[105],dis=0,sum=0;

	cin>>n>>a;
	for(int i=1;i<=n;i++)
		cin>>t[i];

	for(int i=1;i<=n;i++)
	{
		dis=abs(i-a);
		if(t[i]==1)
		{
			if(a+dis>n || a-dis<1 || dis==0)
				sum++;
			else
			{
				if(i<a && t[a+dis]==1)
					sum++;
				else if(i>a && t[a-dis]==1)
					sum++;
			}
		}
	}

	cout<<sum<<endl;
}