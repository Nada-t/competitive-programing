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

	cin>>s;
	for(int i=0;i<s.size();i++)
		st.insert(s[i]);

	if(st.size()%2 == 0)
		cout<<"CHAT WITH HER!"<<endl;
	else
		cout<<"IGNORE HIM!"<<endl;

}