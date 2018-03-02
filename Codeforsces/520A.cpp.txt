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
int main()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	set<char> st;
	string s;
	int n;

	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]<97)
			s[i]+=32;

		st.insert(s[i]);
	}

	if(st.size() == 26)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;

}