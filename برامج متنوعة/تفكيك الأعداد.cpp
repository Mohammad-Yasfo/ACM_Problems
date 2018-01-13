/*
5 10 3
5 7 3 3
1 4 7 3 3
...........

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int N;
vector<string>method;
void backtrack(vector<int>num)
{
	bool f=false;
	int t;
	for (int i=0;i<num.size();++i)
	{
		if (num[i]>2)
		{
			f=true;
			vector<int>d=num;
			t=num[i];
			d.erase(d.begin()+i);
			for (int i=1;i<=t/2;++i)
			{
				if (i==t/2 && t%2==0)
					break;
				d.push_back(i);
				d.push_back(t-i);
				backtrack(d);
				d.pop_back();
				d.pop_back();
			}
		}
	}
	if (!f)
	{
		string s;
		for (int i=0;i<num.size();++i)
		{
			s+=num[i]+48;
		}
		sort(s.begin(),s.begin()+s.length());
		for (int i=0;i<method.size();++i)
			if (method[i]==s)
				return;
		method.push_back(s);
	}
}
int main()
{
	cin>>N;
vector<int> num;
	int a;
	for (int i=0;i<N;++i){
		cin>>a;
		num.push_back(a);
	}
	backtrack(num);
	cout<<method.size()<<endl;
	for (int i=0;i<method.size();++i)
		cout<<method[i]<<endl;
	cin>>N;
	return 0;
}
