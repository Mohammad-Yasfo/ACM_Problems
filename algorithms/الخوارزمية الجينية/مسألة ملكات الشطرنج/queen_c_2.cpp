void CGAQueen::Clear()
{
	// to Reset All cells 
	for (int i=0;i<ChessBoradLenght;i++)
		for (int j=0;j<ChessBoradLenght;j++)
			area[i][j]=0;
}

void CGAQueen::InitialPopulation() //توليد المجتمع الابتدائي
{
	
	int random;
	for (int index=0;index<=Population-1;index++)
		for (int a=0;a<ChessBoradLenght;a++)
			{
				st:random=rand();
				for (int b=0;b<a;b++)
					if (random%ChessBoradLenght==ChromosomeMatrix[b][index])
						goto st;
				ChromosomeMatrix[a][index]=random%ChessBoradLenght;
			}

}
void CGAQueen::PopulationSort()//ترتيب المجتمع حسب الكلفة الأقل
{
	bool k=1;
	int Temp;
	while(k)
	{
		k=0;
		for (int i=0;i<=Population-2;i++)
		{
			if (CostMatrix[i]>CostMatrix[i+1])	
			{
				Temp=CostMatrix[i];
				CostMatrix[i]=CostMatrix[i+1];
				CostMatrix[i+1]=Temp;
				
			for (int j=0;j<ChessBoradLenght;j++)
			{
				Temp=ChromosomeMatrix[j][i];
				ChromosomeMatrix[j][i]=ChromosomeMatrix[j][i+1];
				ChromosomeMatrix[j][i+1]=Temp;
			}			
			k=1;
			}
		}
	}
}

void CGAQueen::GenerateCrossOverMatrix()//التصالب العشوائي أو الموحد
{
	// generate a matrix with random 0's and 1's
	int randomCrossOver;
	for (int index=0;index<=Population-1;index++)
		for (int a=0;a<ChessBoradLenght;a++)
		{
			randomCrossOver=rand();
			CrossOverMatrix[a][index]=randomCrossOver%2;
		}

}
void CGAQueen::Mating()
{
	int TempMatrix[30][2];
	int TempMatrix0[30],TempMatrix1[30];
	int Temp,j,k;

	for (int index=0;index<=(Population/4)-1;index++)
		for (int t=0;t<=1;t++)
		{
			
			for(int i=0;i<ChessBoradLenght;i++)
			{
				TempMatrix0[i]=ChromosomeMatrix[i][2*index];
				TempMatrix1[i]=ChromosomeMatrix[i][2*index+1];
			}
			for (int i=0;i<ChessBoradLenght;i++)
				if(CrossOverMatrix[i][2*index+t]==0)
				{
					for (j=0;j<ChessBoradLenght;j++)
						if(TempMatrix0[j]!=100)	
						{
							TempMatrix[i][t]=TempMatrix0[j];
							Temp=TempMatrix0[j];
							TempMatrix0[j]=100;
							j=ChessBoradLenght-1;
						
							for (k=0;k<ChessBoradLenght;k++)
							{
								if (TempMatrix1[k]==Temp)
								{
									TempMatrix1[k]=100;
									k=ChessBoradLenght-1;
								}
							}
						}
				}
				else
				{
					for (j=0;j<ChessBoradLenght;j++)
						if(TempMatrix1[j]!=100)	
						{
							TempMatrix[i][t]=TempMatrix1[j];
							Temp=TempMatrix1[j];
							TempMatrix1[j]=100;
							j=ChessBoradLenght-1;
						
							for (k=0;k<ChessBoradLenght;k++)
							{
								if (TempMatrix0[k]==Temp)
								{
									TempMatrix0[k]=100;
									k=ChessBoradLenght-1;
								}
							}
						}
				}

		for(int i=0;i<ChessBoradLenght;i++)
			ChromosomeMatrix[i][2*index+Population/2+t]=TempMatrix[i][t];
		
		}

	
}
void CGAQueen::ApplyMutation()
{
	// a random for selecting chromosome
	// a random for selecting genes from selected chromosome

	int randomChromosome;
	int randomGen0,randomGen1;
	int Temp;
	// the following formula is a mutation formula to obtain the number of Mutation
	int NumberOfMutation=int(MutationRate*(Population-1)*ChessBoradLenght);
	
	for(int k=0;k<=NumberOfMutation;k++)
	{
		randomChromosome=0;
		while((randomChromosome=rand()%Population/2)==0);// random chromosome exept number 0
			
		randomGen0=rand()%ChessBoradLenght;// random genes from chromosome
		while((randomGen1=rand()%ChessBoradLenght)==randomGen0);
		// Apply Mutation
		Temp=ChromosomeMatrix[randomGen0][randomChromosome];
		ChromosomeMatrix[randomGen0][randomChromosome]=ChromosomeMatrix[randomGen1][randomChromosome];
		ChromosomeMatrix[randomGen0][randomChromosome]=Temp;
	}
	
}
void CGAQueen::FillArea(int index)
{
	// to Fill Area with Desired Solution Matrix
	Clear();
	for (int i=0;i<ChessBoradLenght;i++)
		area[i][ChromosomeMatrix[i][index]]=1;

	// after this if there is a queen in a cell , its value will be 1
	// The other cells value will be 0


}

