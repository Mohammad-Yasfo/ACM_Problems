#include <iostream>
using namespace std;
void main()
{
	int g1 [100][100];
	int g2 [100][100];
	int x1,x2,y1,y2;
	cin>>x1>>y1>>x2>>y2;
	cout<<"enter the first group";
	for (int a=0;a<x1;++a)
		for (int b=0;b<y1;++b)
			cin>>g1 [a][b];
	cout<<"enter the second group";
	for (int a=0;a<x2;++a)
		for (int b=0;b<y2;++b)
			cin>>g2 [a][b];
	int result [100][100];
		for (int a=0;a<100;++a)
			for (int b=0;b<100;++b)
				result [a][b]=0;
	for (int a=0;a<x1;++a)
	{
		for (int b=0;b<y2;++b)
		{
			for (int c=0;c<y1;++c) 
				result [a][b]+=(g1 [a][c]*g2 [c][b]);
			cout<<result [a][b]<<"\t";
		}
		cout<<endl;
	}
}