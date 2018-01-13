// GAQueen.cpp: implementation of the CGAQueen class.
//
//////////////////////////////////////////////////////////////////////
#include <random>
#include "queen_h.h"
#include <ctime>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGAQueen::CGAQueen(int nPopulation,int nIteration,float Mutation,int iChBoard)
{
	Clear();
	srand( (unsigned)time( NULL ) );
	Population=nPopulation;
	Iteration=nIteration;
	MutationRate=Mutation;
	ChessBoradLenght=iChBoard;
	
}

CGAQueen::~CGAQueen()
{

}
void  CGAQueen::get_sort(int *index)
{
	int i=0;
	InitialPopulation();
	GenerateCrossOverMatrix();
	start:for (int i=0;i<Population;++i)
	{
		FillArea(i);
		CostMatrix[i]=CostFunc(i);
	}
	PopulationSort();
	if (CostMatrix[0]==0)
	{
		for (int j=0;j<ChessBoradLenght;++j)
			index[j]=ChromosomeMatrix[j][0]+1;
		return;
	}
	Mating();
	ApplyMutation();
	if (i<Iteration)
	{
		++i;
		goto start;
	}
}
int CGAQueen::CostFunc(int index)//حساب الكلفة
{
	// Determine The CostFunction of matrix[][index] and return the Cost Value
	// The Best Cost is zero 
	int costValue=0;
	int m,n;
	int i,j;
			
	for(i=0;i<ChessBoradLenght;i++)
	{	
		j=ChromosomeMatrix[i][index];

		m=i+1;
		n=j-1;
		while(m<ChessBoradLenght	&& n>=0)
		{
			if(area[m][n]==1)
			{
				costValue++; // there is a queen that takes the other one 
			}
			m++;
			n--;
		}

		m=i+1;
		n=j+1;
		while(m<ChessBoradLenght && n<ChessBoradLenght )
		{		
			if(area[m][n]==1)
			{
				
				costValue++;// there is a queen that takes the other one 
			}
			m++;
			n++;
		}

		

		m=i-1;
		n=j-1;
		while(m>=0 && n>=0)
		{		
			if(area[m][n]==1)
			{
				
				costValue++;// there is a queen that takes the other one 
			}
			m--;
			n--;
		}
		

		m=i-1;
		n=j+1;
		while(m>=0 && n<ChessBoradLenght)
		{		
			if(area[m][n]==1)
			{
				
				costValue++;// there is a queen that takes the other one 
			}
			m--;
			n++;
		}
	}

	return costValue;
	
}
