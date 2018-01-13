#include <fstream>
#include <algorithm>
using namespace std;
#define MAX 10000
int n,m;
long long t[MAX],f[MAX];
int binary_search(long long number)
{
	int start=0,end=n,middle;
	while (true){
	middle=(end+start)/2;
	if (f[middle]==number)
		return middle;
	else if (start==end)
		return start;
	else if(f[middle]>number)
		end=middle-1;
	else if (f[middle]<number)
		start=middle+1; 
	}
	return -1;
}
int main()
{
	ifstream fin("phone.in");
	ofstream fout("phone.out");
	int index;
	long long q,w;
	fin>>n>>m;
	for (int i=0;i<n;++i)
		fin>>f[i];
	sort(f,f+n);
	for (int i=0;i<m;++i)
	{
		fin>>t [i];
		index=binary_search(t[i]);
		q=(index>0?abs(f[index-1]-t[i]):999999999)<=(index<n-1?abs(f[index+1]-t[i]):999999999)?f [index-1]:f[index+1];
		w=abs(t[i]-f[index]);
		if (w<abs(q-t[i]) || w==(abs(q-t[i]) && f[index]<q))
			q=f[index];
		fout<<q<<endl;
	}

	return 0;
}
