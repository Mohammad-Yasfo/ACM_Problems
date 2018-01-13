#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
bool visited[13];

int an[13];
int diff=99999999;
void backtrack(int i,int maxs,int mins)
{
for (int a=0;a<4;a++)
{
	if (visited[a])
		continue;
	visited[a]=true;
	for (int b=4;b<8;++b)
	{
		if (visited[b])
			continue;
		visited[b]=true;
		for (int c=8;c<12;++c)
		{
			if (visited[c])
				continue;
			visited[c]=true;
			if (i==4){
				diff=min(diff,max(maxs,an[a]+an[b]+an[c])-min(mins,an[a]+an[b]+an[c]));
			}
			else
				backtrack(i+1,max(maxs,an[a]+an[b]+an[c]),min(mins,an[a]+an[b]+an[c]));
			visited[c]=false;
		}
		visited[b]=false;

	}
	visited[a]=false;
}
}
int main()
{
	ifstream fin("bteams.in");
	ofstream fout("bteams.out");
	for (int i=0;i<12;++i)
		fin>>an[i];
	sort(an,an+12);
	backtrack(1,-1,99999999);
	fout<<diff<<endl;
	return 0;
}
