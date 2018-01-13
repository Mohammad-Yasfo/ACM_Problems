/*
يجب التأكد من حالة الأنابيب الفارغة
*/
#include <fstream> 
#include <vector>
using namespace std;
int N;
vector<char> a,b;
vector <int> num;
int get_sum_char(int i,char w,int &index2)
{
	int sum=0;
	for (int q=0;q<N;++q)
	{
		if (a[q]==w||b[q]==w)
		{
			++sum;
			if (sum>2)
				break;
			index2=q;
		}
	}
	return sum;
}
void delete_num(int i)
{
	a.erase(a.begin()+i);
	b.erase(b.begin()+i);
	num.erase(num.begin()+i);
}
int main()
{
	ifstream fin("flow.in");
	ofstream fout("flow.out");
	int c_;
	char a_,b_;
	fin>>N;
	for (int i=0;i<N;++i)
	{
		fin>>a_>>b_>>c_;
		a.push_back(a_);
		b.push_back(b_);
		num.push_back(c_);
	}
	while (num.size()>1)
	{
		for (int i=0;i<N;++i)
			for (int j=i+1;j<N;++j)
				if (a[i]==a[j] && b[i]==b[j] || a[i]==b[j] && b[i]==a[j])
				{
					num[i]+=num[j];
					delete_num(j);
					--j;
					--N;
				}
		int index2,sum;
		char w;
		for (int i=0;i<N;++i)
		{
			for (int j=0;i<N&&j<2;++j)
			{
				index2=-1;
				w=j==0?a[i]:b[i];
				if (w=='A' ||w=='Z')
					continue;
				sum=get_sum_char(i,w,index2);
				if (sum==1)
				{
					num[i]=0;
					if (get_sum_char(i,j==0?b[i]:a[i],index2)==1)
					{
						delete_num(i);
						j=-1;
						--N;
					}
				}
				else if (sum==2)
				{
					char g=a[index2]==w?b[index2]:a[index2];
					if (j==0)
						a[i]=g;
					else
						b[i]=g;
					if (num[index2]<num[i])
						num[i]=num[index2];
					delete_num(index2);
					j=-1;
					--N;
				}
			}
		}
		}
	fout<<num[0]<<endl;
	return 0;
}
