/*
الأضواء الملونة
*/
#include <iostream>
#include <string>
using namespace std;
bool is_even(int number){return number%2==0?true:false;}
int main()
{
	int N,numofpresses;
	string defaults,squence;
	bool yes_no=true;
	cin>>N>>numofpresses;
	for (int i=0;i<N;++i){
		defaults+='1';
		squence+='$';}
	int d;
	do{
		cin>>d;
		if(d>0)		squence [d-1]='1';
	}while (d!=-1);
	do{
		cin>>d;
		if (d>0)	squence [d-1]='0';
	}while (d!=-1);
	for (int a=0;a<2;++a)
		for(int b=0;b<2;++b)
			for (int c=0;c<2;++c)
				for (int d=0;d<2;++d){
					for (int i=0;i<N;++i)
						defaults [i]='1';
					if(a+b+c+d>numofpresses||(is_even(a+b+c+d) &&!is_even(numofpresses))||(!is_even(a+b+c+d) &&is_even(numofpresses)))
						continue;
					if (a>0)
						for (int i=0;i<defaults.length();++i)
							defaults [i]=defaults [i]=='1'?'0':'1';
					if (b>0)
						for (int i=0;i<defaults.length();i+=2)
							defaults [i]=defaults [i]=='1'?'0':'1';
					if (c>0)
						for (int i=1;i<defaults.length();i+=2)
							defaults [i]=defaults [i]=='1'?'0':'1';
					if (d>0)
						for (int i=0;i<defaults.length();i+=3)
							defaults [i]=defaults [i]=='1'?'0':'1';
					for (int i=0;i<defaults.length();++i)
						if (defaults [i]!=squence [i]&&squence [i]!='$')
							goto not;
					cout<<defaults<<endl;
					yes_no=false;
					not:;
				}
				if (yes_no)
					cout<<"IMPOSSIBLE"<<endl;
				return 0;
}