#include<bits/stdc++.h>
using namespace std;
auto speedup = [](){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
		freopen("alchemy_validation_input.txt", "r", stdin);
		freopen("output2.txt", "w", stdout);
	#endif
	return 0;
}();

int main()
{
	int test;
	cin>>test;
	for(int t=1;t<=test;++t)
	{
		int n;
		cin>>n;
		char shards;
		int A_count = 0,B_count = 0;
		for(int i=0;i<n;++i)
		{
		    cin>>shards;
			if(shards=='A')++A_count;
			else ++B_count;
		}
		cout<<"Case #"<<t<<": ";
		if(abs(A_count-B_count)>1)cout<<"N";
		else cout<<"Y";
		cout<<"\n";
	}
	return 0;
}