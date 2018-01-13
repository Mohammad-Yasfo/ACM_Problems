/*
آلة صنع القهوة
*/
#include <fstream>
#include <vector>
using namespace std;

void quicksort(int *arry,int *arry2,int start,int end){
	int temp;
	if(start>=end){
		return;
	}
	if(end-start==1){
		if(*(arry+start)>*(arry+end)){
			temp=*(arry+start);
			*(arry+start)=*(arry+end);
			*(arry+end)=temp;
			temp=*(arry2+start);
			*(arry2+start)=*(arry2+end);
			*(arry2+end)=temp;
		}
		return;
	}
	int pivot=*(arry+start);
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
			temp=*(arry2+index_up);
			*(arry2+index_up)=*(arry2+index_down);
			*(arry2+index_down)=temp;
		}
	}
	*(arry+start)=*(arry+index_down);
	*(arry+index_down)=pivot;
	temp=*(arry2+start);
	*(arry2+start)=*(arry2+index_down);
	*(arry2+index_down)=temp;
	quicksort(arry,arry2,start,index_down-1);
	quicksort(arry,arry2,index_down+1,end);
	return;
}

int main(){
	ifstream fin("machine.in");
	ofstream fout("machine.out");
	int n;
	fin>>n;
	if(n==0){
		fout<<0<<endl;
		return 0;
	}
	vector<int>range;
	vector<int>repeat;
	int t1,t2;
	for(int i=0;i<n;i++){
		fin>>t1>>t2;
		range.push_back(t1);
		repeat.push_back(1);
		range.push_back(t2+1);
		repeat.push_back(-1);
	}
	quicksort(&(range[0]),&(repeat[0]),0,range.size()-1);
	int curr=0,max=0,index;
	for(int i=0;i<repeat.size();i++){
		index=i;
		for (++i;i<range.size()&&range[i]==range[index];++i)
			curr+=repeat[i];
		curr+=repeat[index];
		--i;
		if(curr>max){
			max=curr;
		}
	}
	fout<<max<<endl;
}

