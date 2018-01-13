/*
PARKSIDE'S  TRIANGLE is generated from two numbers--the size and the seed. The size determines how many rows are in the triangle and the seed determines the first number in the triangle. Here are two examples:

SIZE 6,SEED 1   SIZE 5, SEED 3

 1 2 4 7 2 7       3 4 6 9 4
   3 5 8 3 8         5 7 1 5 
     6 9 4 9           8 2 6 
       1 5 1             3 7
         6 2               8
           3

Analyze the above examples, discover the rule, and write a program that will generate PARKSIDE'S  TRIANGLE given any size N (N_20) and any seed S (1_S_9).  Test your program by generating PARKSIDE'S TRIANGLE for N=6, S=1 and N=7, S=9.

Sample Run

PARKSIDE'S  TRIANGLE
SIZE,SEED ? 7,9

  9 1 3 6 1 6 3
    2 4 7 2 7 4
      5 8 3 8 5
        9 4 9 6
          5 1 7
            2 8
              9

*/
//Problem name: PARKSIDE'S  TRIANGLE
#include <iostream>
using namespace std;
int main()
{
	int Size,Seed;
	cin>>Seed>>Size;
	for (int i=0;i<Size;++i)
	{
		Seed+=i==0?0:i+1;
		int m=Seed;
		for (int j=0;j<Size-i;++j)
		{
			m+=j==0?0:j+i;
			cout<<(m%9==0?9:(m)%9)<<" ";
		}
		cout<<endl;
	}
	cin>>Size;
	return 0;
}