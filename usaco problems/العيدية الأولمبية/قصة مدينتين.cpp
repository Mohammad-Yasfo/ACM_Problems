/*
قصة مدينتين
*/
#include <iostream>
using namespace std;
int N1,N2;
long long numof1 [10],numof2 [10];
int get_max(int team){
	int index=0;
	if (team==1)
		for (int i=1;i<N1;++i){
			if (numof1 [i]>numof1[index])
				index=i;}
	else
		for (int i=1;i<N2;++i){
			if (numof2 [i]>numof2[index])
				index=i;}
		return index;
}
int end_war(){
	int f=0;
	for (int i=0;i<N1;++i)
		if(numof1 [i]>0)
			goto no1;
	f=2;
no1:for (int i=0;i<N2;++i)
		if (numof2 [i]>0)
			goto no2;
++f;
no2:	return f;
}
void war(){
	while (end_war()==0){
	int in1=get_max(1),in2=get_max(2);
	cout<<"A sends:"<<numof1[in1]<<"\t"<<"B sends:"<<numof2[in2]<<"\t";
	if(numof1[in1]>numof2[in2]){numof1[in1]-=numof2[in2];numof2[in2]=0;}
	else	{numof2[in2]-=numof1[in1];numof1[in1]=0;}
	cout<<"Back to A:"<<numof1 [in1]<<"\t"<<"Back to B:"<<numof2 [in2]<<endl;
	}
	int l=end_war();
	if (l==1)
		cout<<"The war ends here, and the winner is Arbandoria."<<endl;
	else if (l==2)
		cout<<"The war ends here, and the winner is Barbandoria."<<endl;
	else cout<<"Tie"<<endl;
	cout<<"Arbandoria's divisions:"<<endl;
	for (int i=0;i<N1;++i)
		cout<<numof1 [i]<<endl;
		cout<<"Barbandoria's divisions:"<<endl;
	for (int i=0;i<N2;++i)
		cout<<numof2 [i]<<endl;
}
void input(){
	cin>>N1;
	for (int i=0;i<N1;++i)
		cin>>numof1 [i];
	cin>>N2;
	for (int i=0;i<N2;++i)
		cin>>numof2 [i];
}
int main()
{
	input();
	war();
	return 0;
}
