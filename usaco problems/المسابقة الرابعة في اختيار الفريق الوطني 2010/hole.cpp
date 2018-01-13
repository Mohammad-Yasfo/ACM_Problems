/*
نقل الاخبار
*/
class mst
{
public:
	bool *visited;
	int **graph;
	int *distance;
	int num_visit;
	int N;
	mst(int n)
	{
		N=n;
		num_visit=0;
		visited=new bool [N];
		distance=new int [N];
		graph=new int *[N];
		for (int i=0;i<N;++i){
			graph[i]=new int [N];
			distance[i]=500000000;
			visited[i]=false;
		}
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
		distance[start]=0;
		int sum=0;
		while (num_visit<N)
		{
			visited[start]=true;
			++num_visit;
			sum+=distance[start];
			for (int i=0;i<N;++i)
				if (graph[start][i]<distance[i])
					distance[i]=graph[start][i];
			start=get_shortest_edges();
		}
		return sum;
	}
};

int main()
{
	int n;
	ifstream fin("water.in");
	ofstream fout("water.out");
	fin>>n;
	mst map(n+1);
	map.graph[0][0]=0;
	for (int i=1;i<=n;++i)
		fin>>map.graph[0][i];
	for (int i=1;i<=n;++i){
		map.graph[i][0]=map.graph[0][i];
		for (int j=1;j<=n;++j)
			fin>>map.graph[i][j];
	}
	fout<<map.get_mst(1)<<endl;
	return 0;
}
