/*
Farmer John's cows have been causing too much trouble around the farm, and FJ therefore wants to keep a more watchful eye on them. By installing N reflective fences (1 <= N <= 200) at various locations on the farm, he hopes to be able to see from his house at location (0,0) to the barn at location (a,b). On a 2D map of FJ's farm, fence i appears as a short line segment centered at integer location (x_i, y_i) and tilted 45 degrees (either like '/' or like '\'). For example, a fence oriented like '/' at position (3,5) could be described as a line segment from (2.9,4.9) to (3.1,5.1). Each fence (and also the location of the barn) lies at a different position with integer coordinates in the range -1,000,000...1,000,000. No fence lies at (0,0) or (a,b). FJ plans to sit at his house at position (0,0) and look directly to the right (in the +x direction). With his gaze bouncing off some of the reflective fences on his farm, he hopes to be able to see the point (a,b). Unfortunately, FJ thinks he oriented one of his fences incorrectly (e.g., '\' instead of '/'). Please output the index of the first fence in FJ's list such that by toggling its direction (between '/' and '\' or vice versa), FJ will be able to see the point (a,b). If FJ can already see the point (a,b) without toggling any fence, please output 0. If it is still impossible for him to see (a,b) even after toggling up to a single fence, output -1. PROBLEM NAME: mirrors INPUT FORMAT: * Line 1: Three space-separated integers, N, a, and b. * Lines 2..1+N: Line i+1 describes fence i and contains either "x_i y_i /" or "x_i y_i \", where (x_i, y_i) is the location of the center of the fence, and \ or / refers to its orientation. SAMPLE INPUT (file mirrors.in): 5 6 2 3 0 / 0 2 / 1 2 / 3 2 \ 1 3 \ INPUT DETAILS: A map of the farm looks like this (with H denoting FJ's house and B denoting the barn): 3 .\..... 2 //.\..B 1 ....... 0 H../... 0123456 OUTPUT FORMAT: * Line 1: The index of the first fence for which toggling that fence allows FJ to see the point (a,b). If FJ can already see the point (a,b), please output 0, or if there is no way he can see (a,b) even after toggling up to one fence, please output -1. SAMPLE OUTPUT (file mirrors.out): 4 OUTPUT DETAILS: By toggling the fence at position (3,2), FJ can see the point (a,b). On the map: 3 .\..... 2 //./--B 1 ...|... 0 H--/... 0123456

*/
#include<fstream>
using namespace std;
int N,goal_x,goal_y;
int mirror_x[200],mirrors_y[200];
char mirror_type[200];
int index_mirror=-1;
int get_next_mirror (int x,int y,char dir)
{
	int	index=-1;
	switch (dir)
	{
	case 'r':
		for (int i=0;i<N;++i)
			if (mirrors_y[i]==y && mirror_x [i]>=x && (index==-1 || mirror_x[index]>mirror_x[i]))
				index= i;
		break;
	case 'l':
		for (int i=0;i<N;++i)
			if (mirrors_y[i]==y && mirror_x [i]<=x && (index==-1 || mirror_x[index]<mirror_x[i]))
				index= i;
		break;
	case 'u':
		for (int i=0;i<N;++i)
			if (mirrors_y[i]>=y && mirror_x [i]==x && (index==-1 || mirrors_y[index]>mirrors_y[i]))
				index= i;
		break;	
	case 'd':
		for (int i=0;i<N;++i)
			if (mirrors_y[i]<=y && mirror_x [i]==x && (index==-1 || mirrors_y[index]<mirrors_y[i]))
				index= i;
		break;
	}
	return index;
}
bool is_along_see(int x,int y,char dir)
{
	switch(dir)
	{
	case 'r':
		if (goal_x>=x && goal_y==y)
			return true;
	case 'l':
		if (goal_x<=x && goal_y==y)
			return true;	
	case 'u':
		if (goal_x==x && goal_y>=y)
			return true;	
	case 'd':
		if (goal_x==x && goal_y<=y)
			return true;
	}
	return false;
}
void change_dir(char & dir,int n,int &x,int &y)
{
		switch (dir)
	{
	case 'r':
		if (mirror_type[n]=='\\'){
			dir='d';
			--y;
		}
		else
		{
			dir='u';
			++y;
		}
		break;
	case 'l':
		if (mirror_type[n]=='\\'){
			dir='u';
			++y;
		}
		else
		{
			dir='d';
			--y;
		}
		break;
	case 'u':
		if (mirror_type[n]=='\\'){
			dir='l';
			--x;
		}
		else
		{
			dir='r';
			++x;
		}
		break;
			case 'd':
		if (mirror_type[n]=='\\'){
			dir='r';
			++x;
		}
		else
		{
			dir='u';
			--x;
		}
		break;
	}
}
bool go(int x,int y,char dir,bool change)
{
	int orginal_x,orginal_y;
	char orginal_dir;
	int n=get_next_mirror(x,y,dir);
	if (n==-1)
		if (is_along_see(x,y,dir))
			{
				return true;
			}
		else
			return false;
	x=mirror_x[n];
	y=mirrors_y[n];
	if (change)
	{
		orginal_dir=dir;
		mirror_type[n]=mirror_type[n]=='\\'?'/':'\\';
		orginal_x=x;
		orginal_y=y;
	}
	change_dir(dir,n,x,y);		
	index_mirror=n;
	if (go(x,y,dir,false))
		return true;
	if (!change)
		return false;
	mirror_type[n]=mirror_type[n]=='\\'?'/':'\\';
	change_dir(orginal_dir,n,orginal_x,orginal_y);
	index_mirror=n;
	if (go(orginal_x,orginal_y,orginal_dir,true))
		return true;
	return false;
}
int main()
{
	ifstream fin("mirror.in");
	ofstream fout("mirror.out");
	fin>>N>>goal_x>>goal_y;
	for (int i=0;i<N;++i)
	fin>>mirror_x[i]>>mirrors_y[i]>>mirror_type[i];
	go(0,0,'r',true);
	fout<<index_mirror+1<<endl;
 return 0;
}
