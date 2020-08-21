#include<bits/stdc++.h>
using namespace std;
auto speedup = [](){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	#ifndef ONLINE_JUDGE
		freopen("input3.txt", "r", stdin);
		freopen("output3.txt", "w", stdout);
	#endif
	return 0;
}();

int func_1(int number,unordered_map<int,vector<int>>&number_pool,unordered_map<int,int>&save_res1)
{
	if(number_pool.find(number)==number_pool.end())return save_res1[number] = 0;
	if(save_res1.find(number)!=save_res1.end())return save_res1[number];
	int maxx = 0,diff,tmp_max=0;
	for(int i=0;i<number_pool[number].size();++i)
	{
		if(number<number_pool[number][i])
		{
			if(number>=0 && number_pool[number][i]>=0)diff = abs(number - number_pool[number][i]);
			else if(number<0 && number_pool[number][i]<0)diff = abs(abs(number) - abs(number_pool[number][i]));
			else diff = abs(number) + abs(number_pool[number][i]); 
			tmp_max = diff + func_1(number_pool[number][i],number_pool,save_res1);
		}
		maxx = max(maxx,tmp_max);
	}
	return save_res1[number] = maxx;
}

int func_2(int number,unordered_map<int,vector<int>>&number_pool,unordered_map<int,int>&save_res2)
{
	if(number_pool.find(number)==number_pool.end())return save_res2[number] = 0;
	if(save_res2.find(number)!=save_res2.end())return save_res2[number];
	int maxx = 0,diff,tmp_max=0;
	for(int i=0;i<number_pool[number].size();++i)
	{
		if(number>number_pool[number][i])
		{
			if(number>=0 && number_pool[number][i]>=0)diff = abs(number - number_pool[number][i]);
			else if(number<0 && number_pool[number][i]<0)diff = abs(abs(number) - abs(number_pool[number][i]));
			else diff = abs(number) + abs(number_pool[number][i]); 
			tmp_max = diff + func_2(number_pool[number][i],number_pool,save_res2);
		}
		maxx = max(maxx,tmp_max);
	}
	return save_res2[number] = maxx;
}

int main()
{
	int test;
	cin>>test;
	for(int t=1;t<=test;++t)
	{
		int n;
		cin>>n;
		int maxx = 0,min_limit = INT_MAX,max_limit = INT_MIN;
		unordered_map<int,vector<int>>number_pool;
		unordered_map<int,int>save_res1,save_res2;
		set <int> s;
		for(int i=0;i<n;++i)
		{
			int p,h;
			cin>>p>>h;
			number_pool[p-h].push_back(p);
			number_pool[p+h].push_back(p);
			s.insert(p);
			s.insert(p-h);
			s.insert(p+h);
			min_limit = min(p-h,min_limit);
			max_limit = max(max_limit,p+h);
		}
		for(auto itr = s.rbegin(); itr != s.rend(); ++itr)func_1(*itr,number_pool,save_res1);
		for(auto itr = s.begin(); itr != s.end(); ++itr)func_2(*itr,number_pool,save_res2);
		for(auto itr = s.begin(); itr != s.end(); ++itr)
		{
			maxx = max(maxx,save_res1[*itr]+save_res2[*itr]);
		}
		cout<<"Case #"<<t<<": "<<maxx<<"\n";
	}
	return 0;
}