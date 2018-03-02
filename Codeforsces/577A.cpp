#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	std::ios_base::sync_with_stdio(0);
    cin.tie(0);

	int n;
	long long x,sum=0;

	cin>>n>>x;
	for(long long i=1; i*i<=x ;i++)
	{
		if(x%i==0 && x/i<=n)
		{
			sum++;
			if(i!=x/i)
			  sum++;
	    }
	}

		
	cout<<sum<<endl;
}