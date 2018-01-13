#include <iostream>
using namespace std;
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
int main()
{
	int N,amount,money=0;
	int nums[1000],howmany[1000];
	cin>>N;
	for (int i=0;i<N;++i)
		cin>>nums[i]>>howmany[i];
	cin>>amount;
	quicksort(howmany,nums,0,N-1);
	for (int i=0;amount>0;++i)
	{
		if (nums[i]>amount)
		{
			money+=amount*howmany[i];
			break;
		}
		else
		{
			money+=nums[i]*howmany[i];
			amount-=nums[i];
		}
	}
	cout<<money<<endl;
	return 0;
}
