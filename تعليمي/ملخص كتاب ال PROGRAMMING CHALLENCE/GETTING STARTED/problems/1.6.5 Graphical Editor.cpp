//1.6.5 Graphical Editor
#include <fstream>
#include <string>
using namespace std;
int main()
{
int length=0,width=0;
int x1,x2,y1,y2;
char color;
ifstream fin ("ge.in");
ofstream fout ("ge.out");
start:char map [250][250]={0};	
char command;
string name;
sd:fin>>command;
switch (command)
{
case 'I':
	fin>>length>>width;
for (int i=0;i<length;++i)
	for (int j=0;j<width;++j)
		map [i][j]='0';
break;
case 'C':
		for (int i=0;i<length;++i)
		for (int j=0;j<width;++j)
			map [i][j]='O';
		break;
case 'V':
	fin>>y1>>x1>>x2>>color;
	--x1;--x2;--y1;
	for (int i=x1;i<=x2;++i)
		map [i][y1]=color;
	break;
case 'H':
	fin>>y1>>y2>>x1>>color;
	--x1;--y1;--y2;
	for (int i=y1;i<=y2;++i)
		map [x1][i]=color;
	break;
case 'L':
	fin>>y1>>x1>>color;
	--x1;--y1;
	map [x1][y1]=color;
	break;
case 'K':
	fin>>y1>>x1>>y2>>x2>>color;
	--x1;--x2;--y1;--y2;
	for (int i=x1;i<=x2;++i)
		for (int j=y1;j<=y2;++j)
			map [i][j]=color;
	break;
case 'S':
	fin>>name;
	fout<<name<<endl;
	for (int i=0;i<length;++i)
	{
		for (int j=0;j<width;++j)
			fout << map [i][j];
		fout<<endl;
	}
	goto start;
	break;
case 'F':
	char same;
	fin>>y1>>x1>>color;
	--x1;--y1;
	same=map [x1][y1];
	for (int i=0;i<length;++i)
		for (int j=0;j<width;++j)
			if (map [i][j]==same)
				map [i][j]=color;
	break;
case 'X':
	return 0;
default:
	goto sd;
}	
goto sd;
return 0;
} 