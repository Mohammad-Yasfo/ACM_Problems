/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> adj[1005];
int p[1003];
int dp[12][1003];
int lvl[1003];
int n, T, r, m, a, b;
void dfs_find_lvl(int node, int l){
lvl[node] = l;
for (int i = 0; i<adj[node].size(); i++){
dfs_find_lvl(adj[node][i], l + 1);
}
}
int main(){
cin.sync_with_stdio(false);
cout.sync_with_stdio(false);
cin >> T;
for (int t = 1; t <= T; t++){
for (int i = 0; i<n; i++){
adj[i].clear();
p[i] = i;
}
cin >> n;
for (int i = 0; i<n; i++){
int ts, tn;
cin >> ts;
for (int j = 0; j<ts; j++){
cin >> tn;
tn--;
adj[i].push_back(tn);
p[tn] = i;
}
}
for (int i = 0; i<n; i++){
if (p[i] == i){
r = i;
}
}
dfs_find_lvl(r, 0);
for (int i = 0; i<n; i++){
dp[0][i] = p[i];
}
for (int i = 1; i<11; i++){
for (int j = 0; j<n; j++){
int tmp = dp[i - 1][j];
dp[i][j] = dp[i - 1][tmp];
}
}
cin >> m;
cout << "Case " << t << ":" << endl;
for (int i = 0; i<m; i++){
cin >> a >> b;
a--;
b--;
if (lvl[a]>lvl[b]){
int tmp = a;
a = b;
b = tmp;
}
int up = lvl[b] - lvl[a], cnt = 0;
while (up){
if (up % 2){
b = dp[cnt][b];
}
up /= 2;
cnt++;
}
if (a == b){
cout << a + 1 << endl;
}
else {
for (int i = 10; i >= 0; i--){
if (dp[i][a] != dp[i][b]){
a = dp[i][a];
b = dp[i][b];
}
}
cout << p[a] + 1 << endl;
}
}
}
}
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1009
vector<int> adj[MAX];
int lev[MAX];
void dfs(int node, int l)
{
	lev[node] = l;
	for (int i = 0; i < adj[node].size(); ++i)
		dfs(adj[node][i], l + 1);
}
int main()
{

	int T, N = 0, chd, nchd, r, Q, a, b;
	int p[MAX];
	int dp[MAX][12];
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		for (int i = 0; i < N; ++i){
			p[i] = i;
			adj[i].clear();
		}
		cin >> N;
		for (int n = 0; n < N; ++n)
		{
			cin >> nchd;
			for (int c = 0; c < nchd; ++c)
			{
				cin >> chd;
				--chd;
				adj[n].push_back(chd);
				p[chd] = n;
			}
		}
		for (int i = 0; i < N; ++i)
			if (p[i] == i)
				r = i;
		dfs(r, 0);
		for (int i = 0; i<N; i++)
			dp[i][0] = p[i];
		for (int i = 1; i < 11; ++i)
			for (int j = 0; j < N; ++j)
				dp[j][i] = dp[dp[j][i - 1]][i-1];
		cin >> Q;
		cout << "Case " << t << ":" << endl;
		for (int q = 0; q < Q; ++q)
		{
			cin >> a >> b;
			a--;
			b--;
			if (lev[a]>lev[b])
			{
				int temp = a;
				a = b;
				b = temp;
			}
			int k = lev[b] - lev[a], cnt = 0;
			while (k)
			{
				if (k % 2)
					b = dp[b][cnt];
				++cnt;
				k /= 2;
			}
			if (a == b)
				cout << a + 1 << endl;
			else
			{

				for (int i = 10; i >= 0; i--){
					if (dp[a][i] != dp[b][i])
					{
						a = dp[a][i];
						b = dp[b][i];
					}
				}
				cout << p[a] + 1 << endl;
			}
		}
	}
}