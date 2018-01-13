#include "knapsack.h"
#include <algorithm>
#include <string>
using namespace std;
void knapsack:: convert_to_bool(int num,string &number)
	{
		number="";
		while (num>0)
		{
			number+=(num%2)+48;
			num/=2;
		}
		while (number.length()<length_bit)
			number+='0';
	}
	int knapsack:: convert_to_number(string nums_bin)
	{
		int sum=0;
		for (int i=0;i<length_bit;++i)
			sum+=pow(2,(float)i)*(nums_bin[i]-48);
		return sum;
	}
	knapsack::knapsack(int num,float mut,int pop,int iter,int max_local,int max_item)
	{
		string l;
		length_bit=0;
		convert_to_bool(max_local,l);
		length_bit= l.length();
		max_number=max_local;
		iterator=iter;
		population=pop;
		mutant=mut;
		N=num;
		value=max_item;
	}
	void knapsack:: generate_chromosomes()
	{
		int sum,random;
		string n;
		for (int i=0;i<population;++i)
		{
			sum=0;
			for (int j=0;j<N;++j)
			{
				random=rand()%max_number;
				sum+=random;
				convert_to_bool(random,n);
				chromosomes[i].chromosome+=n;
			}
		}
	}
	void knapsack:: generate_mutation_points()
	{
		for (int i=0;i<population;++i)
			mutation_point[i]=rand()%2;
	}
	int knapsack:: get_cost(int index)
	{
		int sum=0;
		string number;
		for (int i=0;i<N;++i){
			number="";
			for (int j=0;j<length_bit;++j)
				number+=chromosomes[index].chromosome[i*length_bit+j];
		sum+=convert_to_number(number)*weight[i];
		}
		if (sum>value)
			return -1;
		return sum;
	}
	void knapsack:: get_mutant()
	{
		int number=mutant*(population/2-1)+rand()%2;
		int random_chromosome,random_byte;
		for (int i=0;i<number;++i)
		{
			random_chromosome=rand()%population/2;
			random_byte=rand()%length_bit*N;
			if (chromosomes[population/2+random_chromosome].chromosome[random_byte]=='1')
				chromosomes[random_chromosome].chromosome[random_byte]='0';
			else
				chromosomes[random_chromosome].chromosome[random_byte]='1';
		}
	}
	void knapsack:: crossover()
	{
		string f1,f2;
		for (int i=0;i<population/4;++i)
		{
			f1=f2="";
			for (int j=0;j<N*length_bit;++j)
			{
				f1+=mutation_point[j]==0?chromosomes[i*2].chromosome[j]:chromosomes[i*2+1].chromosome[j];
				f2+=mutation_point[j]==1?chromosomes[i*2].chromosome[j]:chromosomes[i*2+1].chromosome[j];
			}
			chromosomes[population/2+i*2].chromosome=f1;
			chromosomes[population/2+i*2+1].chromosome=f2;
		}
	}
	void knapsack:: get_knapsack(int *nums)
	{
		int sum=0;
		generate_chromosomes();
		generate_mutation_points();
	start:	++sum;
		for (int i=0;i<population;++i)
			chromosomes[i].cost=get_cost(i);
		sort(chromosomes,chromosomes+population);
		if (chromosomes[0].cost==value)
			{
				for (int i=0;i<N;++i){
				string number="";
					for (int j=0;j<length_bit;++j)
						number+=chromosomes[0].chromosome[i*length_bit+j];
					nums[i]=convert_to_number(number);
				}
				return;
			}
		crossover();
		get_mutant();
		if (sum<iterator)
			goto start;
		for (int i=0;i<N;++i)
		{
		string number="";
				for (int j=0;j<length_bit;++j)
					number+=chromosomes[0].chromosome[i*length_bit+j];
			nums[i]=convert_to_number(number);
		}
	}
