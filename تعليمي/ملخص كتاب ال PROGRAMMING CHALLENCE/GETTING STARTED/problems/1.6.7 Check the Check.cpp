/*
#include <fstream>
using namespace std;
int pxb,pyb,pxw,pyw;
bool check_Rook(int x,int y,char king)
{
	if (king=='b')
	{
		if ((pxb==x) || (pyb==y))
			return true;
	}
	else
		if ((pxw==x) || (pyw==y))
			return true;
	return false;
}
bool check_Bishop(int x,int y,char king)
{
	if (king=='b')
	{
		for (int i=x;i<8;++i)
			for (int j=y;j<8;++j)
				if ((pxb==i) && (pyb==j))
					return true;
		for (int i=x;i>=0;--i)
			for (int j=y;j>=0;--j)
				if ((pxb==i) && (pyb==j))
					return true;
		for (int i=x;i>=0;--i)
			for (int j=y;j<8;++j)
				if ((pxb==i) && (pyb==j))
					return true;
		for (int i=x;i<8;++i)
			for (int j=y;j>=0;--j)
				if ((pxb==i) && (pyb==j))
					return true;
	}
	else
	{
		for (int i=x;i<8;++i)
			for (int j=y;j<8;++j)
				if ((pxw==i) && (pyw==j))
					return true;
		for (int i=x;i>=0;--i)
			for (int j=y;j>=0;--j)
				if ((pxw==i) && (pyw==j))
					return true;
		for (int i=x;i>=0;--i)
			for (int j=y;j<8;++j)
				if ((pxw==i) && (pyw==j))
					return true;
		for (int i=x;i<8;++i)
			for (int j=y;j>=0;--j)
				if ((pxw==i) && (pyw==j))
					return true;
	}
	return false;
}
bool check_Knight(int x,int y,char king)
{
	if (king=='b')
	{
		if (((((pxb==(x+1)) && (pyb==(y+2))) || ((pxb==(x+1)) && (pyb==(y-2)))) 
			|| (((pxb==(x-1)) && (pyb==(y+2))) || ((pxb==(x-1)) && (pyb==(y-2)))))
			|| ((((pxb==(x+2)) && (pyb==(y+1))) || ((pxb==(x+2)) && (pyb==(y-1))))
			|| (((pxb==(x-2)) && (pyb==(y+1))) || ((pxb==(x-2)) && (pyb==(y-1))))))
			return true;
	}
	else
	{
			if (((((pxw==(x+1)) && (pyw==(y+2))) || ((pxw==(x+1)) && (pyw==(y-2)))) 
			|| (((pxw==(x-1)) && (pyw==(y+2))) || ((pxw==(x-1)) && (pyw==(y-2)))))
			|| ((((pxw==(x+2)) && (pyw==(y+1))) || ((pxw==(x+2)) && (pyw==(y-1))))
			|| (((pxw==(x-2)) && (pyw==(y+1))) || ((pxw==(x-2)) && (pyw==(y-1))))))
			return true;
	}
	return false;
}
bool check_Pawn_black(int x,int y)
{
	if ((pxw==(x+1)) && ((pyw==(y+1) || (pyw==(y-1)))))
		return true;
	return false;
}
bool check_Pawn_white(int x,int y)
{
	if ((pxb==(x-1)) && ((pyb==(y+1) || (pyb==(y-1)))))
		return true;
	return false;
}
bool check_King(int x,int y,char king)
{
	if (king=='b')
	{
		if(((((pxb==x) && (pyb==(y-1)))|| ((pxb==x) && (pyb==(y+1)))) || (((pxb==x-1) && (pyb==(y)))|| ((pxb==x+1) && (pyb==(y))))) || ((((pxb==x-1) && (pyb==(y-1)))|| ((pxb==x+1) && (pyb==(y+1)))) || (((pxb==x-1) && (pyb==(y+1)))|| ((pxb==x+1) && (pyb==(y-1))))))
			return true;
	}
	else
		if(((((pxw==x) && (pyw==(y-1)))|| ((pxw==x) && (pyw==(y+1)))) || (((pxw==x-1) && (pyw==(y)))|| ((pxw==x+1) && (pyw==(y))))) || ((((pxw==x-1) && (pyw==(y-1)))|| ((pxw==x+1) && (pyw==(y+1)))) || (((pxw==x-1) && (pyw==(y+1)))|| ((pxw==x+1) && (pyw==(y-1))))))
			return true;
	return false;
}

*/
int main()
{
	ifstream fin("ctc.in");
	ofstream fout("ctc.out");
	int numofplays=1;
start:char map [8][8]={0};
	bool nomap=true;
	bool player1=false,player2=false;
	for (int i=0;i<8;++i)
		for (int j=0;j<8;++j)
		{
			fin>>map [i][j];
			if (map [i][j]!='.')
				nomap = false;
		}
		if (nomap==true)
			return 0;
	for (int i=0;i<8;++i)
		for (int j=0;j<8;++j)
		{
			 if (map [i][j]=='k')
			 { pxb=i;pyb=j;}
			 else if (map [i][j]=='K')
			 { pxw=i;pyw=j;}
		}
		bool check1=false,check2=false;
		for (int i=0;i<8;++i)
			for (int j=0;j<8;++j)
			{
				if (map [i][j]=='p')
					check1=check_Pawn_black (i,j);
				else if (map [i][j]=='P')
					check2=check_Pawn_white (i,j);
				else if (map [i][j]=='B')
					check2=check_Bishop (i,j,'b');
				else if (map [i][j]=='b')
					check1=check_Bishop (i,j,'w');
				else if (map [i][j]=='q')
				{
					check1=check_Bishop (i,j,'w');
					if (check1==false)
						check1=check_Rook (i,j,'w');
				}
				else if (map [i][j]=='Q')
				{
					check2=check_Bishop (i,j,'b');
					if (check2==false)
						check2=check_Rook (i,j,'b');
				}
				else if (map [i][j]=='r')
					check1=check_Rook (i,j,'w');
				else if (map [i][j]=='R')
					check2=check_Rook (i,j,'b');
				else if (map [i][j]=='n')
					check1=check_Knight (i,j,'w');
				else if (map [i][j]=='N')
					check2=check_Knight (i,j,'b');
				else if (map [i][j]=='k')
					check1=check_King (i,j,'w');
				else if (map [i][j]=='K')
					check2=check_King (i,j,'b');
				if (check1==true)
					player1=true;
				else if (check2==true)
					player2=true;
			}
			if (player1==true)
				fout<<"Game # : "<<numofplays<<"white king is in the check."<<endl;
			else if (player2==true)
				fout<<"Game # : "<<numofplays<<"black king is in the check."<<endl;
			else
				fout<<"Game # : "<<numofplays<<"no king is in check."<<endl;
			++numofplays;
			goto start;
}
