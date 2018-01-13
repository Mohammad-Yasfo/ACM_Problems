#include <fstream>
using namespace std;
int num[109][2];
int n;

int find_(int number)
{
	for (int i = 0; i < n; ++i)
		if (number == num[i][1])
			return i;
	return 0;
}
int main()
{
	bool vis[109] = { false };
	ifstream fin("reorder.in");
	ofstream fout("reorder.out");
	fin >> n;
	for (int i = 0; i < n; ++i)
		fin >> num[i][0];
	for (int i = 0; i < n; ++i)
		fin >> num[i][1];
	int sel = 0, maxs = 0, a, sum = 0;;
	for (int i = 0; i < n; ++i)
	{
		a = find_(num[i][0]);
		if (vis[i]||i==a)continue;
		vis[i] = true;
		sel = 1;
		while (!vis[a])
		{
			vis[a] = true;
			a = find_(num[a][0]);
			++sel;
		}
		if (maxs < sel)
			maxs = sel;
		sum++;
	}
           if(sum==0)maxs=-1;
	fout <<sum<<" "<< maxs << endl;
}