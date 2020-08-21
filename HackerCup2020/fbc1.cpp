#include<bits/stdc++.h>
using namespace std;
#define ll long long
auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    return 0;
}();

int main() {
	int test;
	cin>>test;
	for(int t=1;t<=test;++t)
	{
        cout<<"Case #"<<t<<":\n";
	    int n;
	    cin>>n;
        vector<vector<char>>travel(n,vector<char>(n));
        vector<char>I(n),O(n);
        for(int i=0;i<n;++i)cin>>I[i];
        for(int i=0;i<n;++i)cin>>O[i];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==j)travel[i][j] = 'Y';
                else if(travel[i][j] != 'Y' && travel[i][j] != 'N')
                {
                    int src = i,dest = j;
                    while(src!=dest)
                    {
                        if(i<j && O[src]=='Y' && I[src+1]=='Y')++src;
                        else if(i>j && O[src]=='Y' && I[src-1]=='Y')--src;
                        else break;
                    }
                    if(src==dest)travel[i][j]='Y';
                    else travel[i][j] = 'N';
                }
                cout<<travel[i][j];
            }
            cout<<"\n";
        }
	}
	return 0;
}