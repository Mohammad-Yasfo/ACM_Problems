#include <fstream>
#include <stack>

using namespace std;
struct point
{
	int x;
	int y;
};
int H,W;
int max_sum=0;
int map [100][100];
stack <point> path;
void addpath(int i,int j)
{
		point p;
		p.x=i;
		p.y=j;
		path.push(p);
}
bool backtrack(int i,int j,int sum)	
{
	bool f1=false,f2=false;
	sum+=map[i][j];
	if (i<H-1)
		f1=backtrack(i+1,j,sum);
	if (f1)
		addpath(i,j);
	if (j<W-1)
		f2=backtrack(i,j+1,sum);
	if (f2)
		addpath(i,j);
	if (j==W-1 && i==H-1 && sum>max_sum){
		max_sum=sum;
		while(!path.empty())
			path.pop();
		addpath(i,j);
		return true;
	}
	return f1||f2;
}
int main()
{
	ifstream fin("file.in");
	ofstream fout("file.out");
	fin>>H>>W;
	for (int i=0;i<H;++i)
		for (int j=0;j<W;++j)
			fin>>map[i][j];
	backtrack(0,0,0);
	fout<<max_sum<<endl;
	while (!path.empty())
	{
		fout<<path.top().x<<"  "<<path.top().y<<endl;
		path.pop();
	}
	return 0;
}

