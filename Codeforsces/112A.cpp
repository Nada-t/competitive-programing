#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	std::ios_base::sync_with_stdio(0);
    cin.tie(0);

	string s,c;

	cin>>s>>c;
	for(int i=0;i<s.size();i++)
		if(s[i]>96)
			s[i]-=32;

	for(int i=0;i<c.size();i++)
		if(c[i]>96)
			c[i]-=32;

	if(s>c)
		cout<<1<<endl;

	else if(s<c)
		cout<<-1<<endl;

	else
		cout<<0<<endl;
}