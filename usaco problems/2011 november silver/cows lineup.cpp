#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
#define min(a,b) (a)<(b)?(a):(b)
struct nod
{
	int n;
	int t;
};
bool operator<(nod a1, nod a2)
{
	return a1.n < a2.n;
}
int main()
{
	int N;
	ifstream fin("lineup.in");
	ofstream fout("lineup.out");
	nod numbers[50009];
	map <int, bool>mp;
	map<int, int>com;
	fin >> N;
	for (int r = 0; r < N; ++r)
	{
		fin >> numbers[r].n >> numbers[r].t;
		mp[numbers[r].t] = true;
	}
	int maxs = mp.size(), sel = 0;
	long long sol = 9999999999;
	sort(numbers, numbers + N);
	int i = 0, j = 0;
	if (com[numbers[j].t] == 0)
		++sel;
	com[numbers[j].t]++;
	while (j < N)
	{
		if (sel >= maxs)
		{
			sol = min(sol, numbers[j].n - numbers[i].n);
			com[numbers[i].t]--;
			if (com[numbers[i].t] == 0)
				--sel;
			++i;
			if (i > j)
			{
				fout << 0 << endl;
				return 0;
			}
		}
		else
		{
			++j;
			if (com[numbers[j].t] == 0)
				++sel;
			com[numbers[j].t]++;
		}
	}
	fout << sol << endl;
	return 0;
}