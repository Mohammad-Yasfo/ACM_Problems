/*
البحث عن الكنز
*/
#include <fstream>
#include <vector>
using namespace std;
class dijkstra
{
public:
	int graph [100][100];
	int numofisland;
	dijkstra();
	int compiler (int,int);
	void rebuild ();
private:
	int sums;
	int get_shortest_roads(int );
	int distancefromstart [100];
	bool visited [100];
	int start,final;
};
dijkstra::dijkstra()
{
	sums=0;
	for (int i=0;i<100;++i)
	{
		distancefromstart [i]=500000000;
		visited [i]=false;
	}
	for (int i=0;i<100;++i)
		for (int j=0;j<100;++j)
			graph [i][j]=-1;
}
int dijkstra::compiler (int a,int b)
{
	start=a;final=b;
	if (start==final)
		return sums;
st:visited [start-1]=true;
	distancefromstart [start-1]=0;
	start=get_shortest_roads(start);
	sums=distancefromstart [start-1];
	if (start!=final)
		goto st;
	return sums;
}
int dijkstra::get_shortest_roads(int s)
{
	//update_distance
	for (int i=0;i<numofisland;++i)
	{
		if (!visited[i] && graph[s-1][i]!=-1 && (distancefromstart [i]>sums+graph [s-1][i]))
			distancefromstart [i]=sums+graph [s-1][i];
	}
	int index=0;
	for (int i=0;i<numofisland;++i)
		if (visited[index]||((!visited[i])&& (distancefromstart [i]<distancefromstart [index])))
			index=i;
	return ++index;
}
void dijkstra::rebuild()
{
	sums=0;
	for (int i=0;i<numofisland;++i)
	{
		distancefromstart [i]=500000000;
		visited [i]=false;
	}

}
int main()
{
	dijkstra dij;
	ifstream fin("danger.in");
	ofstream fout("danger.out");
	int M,N;
	vector<int>road;
	fin>>N>>M;
	dij.numofisland=N;
	int g;
	for (int i=0;i<M;++i)
	{
		fin>>g;
		road.push_back(g);
	}
	for (int i=0;i<N;++i)
		for (int j=0;j<N;++j)
			fin>>dij.graph[i][j];
	int sum=0;
	if (road[0]!=1)
	{
		sum+=dij.compiler(1,road[0]);
		dij.rebuild();
	}
	for (int i=0;i<M-1;++i)
	{
		sum+=dij.compiler(road[i],road[i+1]);
		dij.rebuild();
	}
	if (road[road.size()-1]!=N)
		sum+=dij.compiler(road[road.size()-1],N);
	fout <<sum<<endl;
	return 0;
}
