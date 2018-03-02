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
int main()
{
    fast();

    int n,a[100002],b[100002]={0},q,ll=0;
    map<int ,int> mp;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>q;
    while(q--)
    {
        int l,r;

        cin>>l>>r;
        l--;
        r--;
        if(b[l]!=0)b[l]=max(b[l],(r-l)+1);
        else b[l]=(r-l)+1;
        mp[l]++;
    }

    bool bo=0;
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(mp[i]!=0 &&(x==0 || b[i]>x))
        {
            x=b[i];
        }
        if(x>0)
        {
            a[i]=0;
            x--;
        }
        if(a[i]!=0)ll++;
    }
    cout<<ll<<endl;
    for(int i=0;i<n;i++)
    {
       if(a[i]!=0)
            cout<<a[i]<<" ";
    }
    return 0;
}