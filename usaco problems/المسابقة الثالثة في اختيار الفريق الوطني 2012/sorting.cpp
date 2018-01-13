/*
يجب التأكد من صحتها
*/
#include <fstream> 
#include <vector>
#include <algorithm>
using namespace std;
int N,numbers[1000];
vector <int>nums;
bool issorted()
{
	for (int i=0;i<N;++i)
		if (numbers[i]!=nums[i])
			return false;
	return true;
}
int get_index(int number)
{
	for (int i=0;i<N;++i)
		if (number==numbers[i])
			return i;
	return 0;
}
int main()
{
	ifstream fin("sorting.in");
	ofstream fout("sorting.out");
	int final_amount=0;
	vector <int>points;
	fin>>N;
	for (int i=0;i<N;++i)
	{
		fin>>numbers[i];
		nums.push_back(numbers[i]);
	}
	sort(numbers,numbers+N);
	for (int i=0;i<N/2;++i)
		swap(numbers[i],numbers[N-1-i]);
	while (!issorted())
	{
		points.clear();
		for (int i=0;i<N;++i)
		{
			int j=get_index(nums[i]);
			int sum=0;
			if (i==j)
			{
				points.push_back(-1001);
				continue;
			}
			if (i>j)
			{
				for (int q=j;q<i;++q)
				{
					int a=get_index(nums[q]);
					/*if (a<i && a>=j)
						break;*/
					if (q+1!=a)
						--sum;
					else
						++sum;		
				}
			}
			else
			{
				for (int q=i+1;q<=j;++q)
				{
					int a=get_index(nums[q]);
					/*if (a<j&& a>i)
						break;*/
					if (q!=a)
						++sum;
					else
						--sum;		
				}
			}
			points.push_back(sum);
		}
		int index=0;
		for (int i=1;i<points.size();++i)
			if (points[i]>points[index])
				index=i;
		int w=get_index(nums[index]);
		final_amount+=w+index+2;
		nums.insert(nums.begin()+w+1,nums[index]);
		nums.erase(nums.begin()+index+(w<index));

	}
	fout<<final_amount<<endl;
	return 0;
}
