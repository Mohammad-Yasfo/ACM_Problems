/*
النيازك
*/
#include <fstream>
#include <string>
using namespace std;
int M;
int selectedtime=1001;
bool maphit[450][450];
int maptime[450][450];
void hit_point(int x,int y,int t)
{
	if (x<0||y<0)
		return;
	if (maphit[x][y]&&maptime[x][y]<=t)
		return;
	maphit[x][y]=true;
	maptime[x][y]=t;

}
bool escape(int x,int y,int t)
{
	if (!maphit[x][y])
	{
		selectedtime=t;
		return true;
	}
		if ((x>0 && maptime[x-1][y]>t+1&& escape(x-1,y,t+1))||(y>0 && maptime[x][y-1]>t+1 && escape(x,y-1,t+1))||(maptime[x+1][y]>t+1 && escape(x+1,y,t+1))||(maptime[x][y+1]>t+1 && escape(x,y+1,t+1)))
			return true;
		else
			return false;

}
int main()
{
	int M;
	ifstream fin("meteor.in");
	ofstream fout("meteor.out");
	fin>>M;
	int X,Y,T;
		for (int i=0;i<450;++i)
		for (int j=0;j<450;++j)
			maptime[i][j]=1001;
	for (int i=0;i<M;++i){
		fin>>X>>Y>>T;
		hit_point(X,Y,T);
		hit_point(X+1,Y,T);
		hit_point(X,Y-1,T);
		hit_point(X-1,Y,T);
		hit_point(X,Y+1,T);
	}

	if (escape(0,0,0))
	     fout<<selectedtime<<endl;
	else
               fout<<-1<<endl;
	return 0;
}
