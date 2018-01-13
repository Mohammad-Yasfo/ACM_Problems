/*
خوارزمية لحساب أقصر طريق بين نقطتين أو أقصر طريق لاستكشاف كل النقط
*/
#include <iostream>
using namespace std;
class dijkstra
{
public:
	int graph [100][100];
	int numofisland;
	dijkstra();
	int compiler (bool );
	void rebuild ();
	int start,final;
private:
	int sums;
	int get_shortest_roads(int );
	int distancefromstart [100];
	bool visited [100];
	bool isall_dicovered();
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
bool dijkstra::isall_dicovered()
{
	for (int i=0;i<numofisland;++i)
		if (!visited[i])
			return false;
	return true;
}
int dijkstra::compiler (bool dicover_all_nodes=false)
{
	if (!dicover_all_nodes)
	{
		if ( start==final)
			return sums;
	}
	else
		start=1;
st:visited [start-1]=true;
	distancefromstart [start-1]=0;
	start=get_shortest_roads(start);
	sums=distancefromstart [start-1];
	if ((dicover_all_nodes &&!isall_dicovered())||(!dicover_all_nodes && start!=final))
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

