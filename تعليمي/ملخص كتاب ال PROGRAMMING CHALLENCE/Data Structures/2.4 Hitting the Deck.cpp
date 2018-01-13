#include <fstream>
#include <queue>
using namespace std;
#define card 13
#define suit 4
char nums[]={'2','3','4','5','6','7','8','9','T','J','Q','K','A'};
char suits[]={'c','d','h','s'};
queue<int>set;
queue<int> P[2];
int convert_card_to_number(char n,char s)
{
	for (int i=0;i<card;++i)
		if (nums[i]==n)
			for (int j=0;j<suit;++j)
				if (suits[j]==s)
					return j*13+i;
	return -1;
}
void init_p(int n)
{
	while (!P[n].empty())
		P[n].pop();
}
void push_set(queue<int> *p)
{
	while (!set.empty()){
		p->push(set.front());
		set.pop();
	}
}
void war()
{
	ofstream fout ("card.out");
	bool step=false,inwar=false;
	int counter=0;
	int a,b;
	while (!P[0].empty()&&!P[1].empty())
	{
		a=P[step].front();
		b=P[!step].front();
		set.push(a);
		set.push(b);
		P[step].pop();
		P[!step].pop();
		if (inwar)
			inwar=false;
		else
		{
			if (a%13>b%13)
				push_set(&P[step]);
			else if (a%13<b%13)
				push_set(&P[!step]);
			else
				inwar=true;
		}
		step=!step;
		++counter;
	}
	if (P[0].empty()&&!P[1].empty())
		fout<<"b wins after "<<counter<<"steps"<<endl;
	else if (!P[0].empty()&&P[1].empty())
		fout<<"a wins after "<<counter<<"steps"<<endl;
	else
		fout<<"tie after "<<counter<<"steps"<<endl;
}
int main()
{
	char a,b;
	ifstream fin ("card.in");
	while (!fin.eof())
	{
		for (int i=0;i<2;++i)
		{
			init_p(i);
			for (int j=0;j<26;++j)
			{
				fin>>a>>b;
				P[i].push(convert_card_to_number(a,b));
			}
		}
		war();
	}
	return 0;
}
