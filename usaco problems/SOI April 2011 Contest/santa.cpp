#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
int coins[10];
string names[1000];
int point_child[1000];
template<class T,class T1> void quicksort(T *arry,T1 *arry2,int start,int end){
	T temp;
	T1 temp2;
	if(start>=end){
		return;
	}
	if(end-start==1){
		if(*(arry+start)>*(arry+end)){
			temp=*(arry+start);
			*(arry+start)=*(arry+end);
			*(arry+end)=temp;
			temp2=*(arry2+start);
			*(arry2+start)=*(arry2+end);
			*(arry2+end)=temp2;
		}
		return;
	}
	T pivot=*(arry+start);
	int index_up=start,index_down=end;
	while(index_up<index_down){
		while(*(arry+index_up)<=pivot && index_up<end){
			index_up++;
		}
		while(*(arry+index_down)>pivot && index_down>start){
			index_down--;
		}
		if((index_up<index_down)){
			temp=*(arry+index_up);
			*(arry+index_up)=*(arry+index_down);
			*(arry+index_down)=temp;
			temp2=*(arry2+index_up);
			*(arry2+index_up)=*(arry2+index_down);
			*(arry2+index_down)=temp2;
		}
	}
	*(arry+start)=*(arry+index_down);
	*(arry+index_down)=pivot;
	temp2=*(arry2+start);
	*(arry2+start)=*(arry2+index_down);
	*(arry2+index_down)=temp2;
	quicksort(arry,arry2,start,index_down-1);
	quicksort(arry,arry2,index_down+1,end);
	return;
}
int get_number_of_coins(int number_need,int coin_index)
{
	if (number_need<coins[coin_index])
	{
		if (coin_index==0)
			return -1;
		return get_number_of_coins(number_need,--coin_index);
	}
	if (number_need%coins[coin_index]==0)
		return number_need/coins[coin_index];
	if (coin_index==0)
		return -1;
	int n=number_need/coins[coin_index];
	int max=get_number_of_coins(number_need-((n)*coins[coin_index]),coin_index-1);
	if (max!=-1)
		max+=n;
	--n;
	for (int s=0;n>=0 && s<coins[coin_index-1];--n,++s)
	{
		int a= get_number_of_coins(number_need-(n)*coins[coin_index],coin_index-1);
		if (a!=-1 && (a+n<max ||max==-1))max=a+n;
	}
	return max;
}
int main()
{
	int N_gift,N_child;
	ifstream fin ("santa.in");
	ofstream fout("santa.out");
	fin>>N_gift;
	for (int i=0;i<N_gift;++i)
		fin>>coins[i];
	sort(coins,coins+N_gift);
	fin>>N_child;
	for (int i=0;i<N_child;++i){
		fin>>names[i]>>point_child[i];
		point_child[i]=get_number_of_coins(point_child[i],N_gift-1);
	}
	quicksort(point_child,names,0,N_child-1);
	for (int i=0;i<N_child/2;++i)
	{
		swap(point_child[i],point_child[N_child-1-i]);
		swap(names[i],names[N_child-1-i]);
	}
	int base;
	for (int i=0;i<N_child-1;++i)
	{
		base=i;
		while (i<N_child && point_child[i]==point_child[base])
			++i;
		--i;
		if (i-base>0)
			quicksort(names,point_child,base,base+i);
	}
	for (int i=0;i<N_child;++i)
		fout << names [i]<<" "<<point_child[i]<<endl;
	return 0;
}
