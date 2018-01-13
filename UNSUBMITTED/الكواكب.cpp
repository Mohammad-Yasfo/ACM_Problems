#include <iostream>
using namespace std;
class planet
{
public:
	int x;
	int y;
	int z;
	int distance;
	bool visited;
	planet()
	{
		distance=5000000;
		visited=false;
	}
};
class mst
{
public:
	planet *graph;
	bool *visited;
	int *distance;
	int num_visit;
	int N;
	int min_planet;
	int index_min;
	mst(int n)
	{
		min_planet=5000000000;
		N=n;
		num_visit=0;
		graph=new planet [N];
	}
	int get_dis(int index1,int index2)
	{
		int f=min(abs(graph[index1].x-graph[index2].x),abs(graph[index1].y-graph[index2].y));
		return min (f,abs(graph[index1].z-graph[index2].z));
	}
	int get_shortest_edges()
	{
		int index =0;
		for (int i=1;i<N;++i)
			if (visited[index] || (!visited[i] && distance[i]<distance[index]))
				index=i;
		return index;
	}
	int get_mst(int start)
	{
		--start;
		graph[start].distance=0;
		int sum=0;
		int dis;
		while (num_visit<N)
		{
			graph[start].visited=true;
			++num_visit;
			
			sum+=graph[start].distance;
			index_min=-1;
			for (int i=0;i<N;++i){
				if (graph[i].visited)
					continue;
				dis=get_dis(start,i);
				if (dis < distance[i])
				{

					graph[i].distance=dis;
					if (graph[i].distance<min_planet || index_min==-1)
					{
						min_planet=dis;
						index_min=i;
					}
				}
			}
			start=index_min;
		}
		return sum;
	}
};
int main()
{
	int N;
	cin>>N;
	mst map(N);
	for (int i=0;i<N;++i)
		cin>>map.graph[i].x>>map.graph[i].y>>map.graph[i].z;
	cout<<map.get_mst(0);
	return 0;
}

