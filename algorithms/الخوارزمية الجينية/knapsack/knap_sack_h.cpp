#include <string>
using namespace std;
class knapsack
{
public:
	int weight[100];
	int money[100];
	int N;
	struct chro
	{
	public:
		int cost;
		string chromosome;
		bool operator <(chro &chs)
		{
			return cost>chs.cost;//لأجل الترتيب التنازلي
		}
	}chromosomes[1000];

	int length_bit;
	int mutation_point[1000];
	float mutant;
	int population;
	int iterator;
	int max_number;
	int value;
	void convert_to_bool(int num,string &number);
	int convert_to_number(string nums_bin);
	knapsack(int num,float mut,int pop,int iter,int max_local,int max_item);
	void generate_chromosomes();
	void generate_mutation_points();
	int get_cost(int index);
	void get_mutant();
	void crossover();
	void get_knapsack(int *nums);
};
