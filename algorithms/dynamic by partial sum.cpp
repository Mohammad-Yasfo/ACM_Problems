#include <iostream>
using namespace std;
int N;
int numbers [1000];
int max_num;
int first=0,last=0,selected_min,selected_max;
int main()
{
	cin>>N;
	cin>>numbers[0];
	for (int i=1;i<N;++i)
	{
		cin>>numbers [i];
		numbers[i]+=numbers[i-1];
	}
	first=last=0;
	max_num=numbers [0];
	selected_max=selected_min=0;
	for (int i=1;i<N;++i)
	{
		if (numbers[i]<=numbers[selected_min])
		{
			selected_min=i;
		}
		if (numbers[i]>=numbers[selected_max])
		{
			selected_max=i;
			if (numbers[selected_max]>max_num)
			{
				first=-1;
				last=selected_max;
				max_num=numbers[selected_max];
			}
			if (numbers[selected_max]-numbers[selected_min]>max_num)
			{
				first=selected_min;
				last=selected_max;
				max_num=numbers[selected_max]-numbers[selected_min];
			}
		}
	}
	for (int i=++first;i<=last;++i)
		if (i>0)
			cout<<numbers [i]-numbers[i-1]<<endl;
		else
			cout<<numbers [i]<<endl;
	cin>>N;
	return 0;
}
