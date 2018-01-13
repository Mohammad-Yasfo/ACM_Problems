/*
بطل السباحة
*/
#include <fstream>
#include <vector>
using namespace std;
	vector<int> speed1;
	vector<int> speed2;
	vector<bool>iscontinue;
int get_top_two(bool turn,int start,int &top_one)
{
	int N_not_con=0,top_two=-1;
	top_one=-1;
		for (int i=0;start+i<speed1.size()&& i<8+N_not_con;++i)
		{
			if (!iscontinue[start+i])
			{
				++N_not_con;
				continue;
			}
			if (top_two==-1|| (!turn&& speed1[start+i]>speed1[top_two]) ||(turn&& speed2[start+i]>speed2[top_two]))
			{
				if (top_two!=-1)
				iscontinue[top_two]=false;
				if (top_one==-1|| (!turn&& speed1[start+i]>speed1[top_one]) ||(turn&& speed2[start+i]>speed2[top_one]))
				{
					top_two=top_one;
					top_one=start+i;
				}
				else
					top_two=start+i;
			}
			else
				iscontinue[start+i]=false;
		}
	return N_not_con;
}
bool is_less_equal_eight()
{
	int sum=0;
	for (int i=0;i<iscontinue.size();++i)
		if (iscontinue[i])
			++sum;
	return sum<=8;
}
int main()
{
	ifstream fin("swim.in");
	ofstream fout("swim.out");
	int N,num;
	fin>>N;
	int top_one;
	for (int i=0;i<N;++i){
		fin>>num;
		speed1.push_back(num);
		fin>>num;
		speed2.push_back(num);
		iscontinue.push_back(true);
	}
	bool turn=false;
	while (!is_less_equal_eight())
	{
		int index=0;
		while (index<speed1.size())
		{
			int n=get_top_two(turn,index,top_one);
			index+=8+n;
		}
		turn =!turn;
	}
	get_top_two(turn,0,top_one);
	fout<<top_one+1<<endl;
	return 0;
}
