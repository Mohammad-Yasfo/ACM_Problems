#include <iostream>
#include <cmath>
#include <conio.h>
#include <vector>
using namespace std;
class notepad
{
private:
	char **text;
	long int number_of_chars,number_of_lines,number_of_words;
	 long int *char_in_line;
public:
	notepad()
	{

		number_of_chars=number_of_lines=number_of_words=0;	
		char_in_line=new long int [number_of_lines+1];
		for (int i=0;i<number_of_lines+1;++i)
			char_in_line [i]=0;
		text=new char *[number_of_lines+1];
		for (int i=0;i<char_in_line [number_of_lines]+1;++i)
			text [i]=new char [char_in_line [number_of_lines]];

	}
	void enter_text()
	{
		char m=0;
		while (m!='$')
		{
			m=_getch();
			if (m==8)
			{
				if (char_in_line [number_of_lines]!=0)
				{
					cout<<(char)8<<" "<<(char)8;
					--number_of_chars;
					--char_in_line [number_of_lines];

				}
				else
				{
					if (number_of_lines!=0)
					{
					--number_of_lines;
					system("cls");
					for (int i=0;i<=number_of_lines;++i)
					{
						for (int j=0;j<char_in_line [number_of_lines];++j)
						{
							cout<<text [i][j];
						}
						if (i!=number_of_lines)
						cout<<endl;
					}
				}
				}
			}
			else if (m==13)
			{
				cout<<endl;
				if (text [number_of_lines][char_in_line[number_of_lines]]!=32)
					++number_of_words;
				++number_of_lines;
				char_in_line [number_of_lines]=0;
				text[number_of_lines]=new char  [char_in_line [number_of_lines]+1];
			}
			else if (m==32)
			{
				if ((text [number_of_lines][char_in_line[number_of_lines]]!=32) && (char_in_line [number_of_lines]!=0))
					++number_of_words;
				++number_of_chars;
				++char_in_line [number_of_lines];
				text[number_of_lines]=new char  [char_in_line [number_of_lines]];
				text [number_of_lines][char_in_line[number_of_lines]]=32;
				cout<<" ";
			}
			else if (m=='$')
			{
				if (char_in_line [number_of_lines]!=0)
				{++number_of_lines;++number_of_words;}
			}
			else
			{
				cout<<m;
				text [number_of_lines][char_in_line[number_of_lines]]=m;
				++number_of_chars;
				++char_in_line[number_of_lines];
			}
		}
	}
	void print_info()
	{
		cout<<"\n\n\nnumber of lines are: "<<number_of_lines<<endl;
		cout<<"number of chars are: "<<number_of_chars<<endl;
		cout<<"number of words are: "<<number_of_words<<endl;
		for (int i=0;i<number_of_lines;++i)
		cout<<"number of chars in line :  "<<i+1<<"are :  "<<char_in_line [i]<<endl;
	}

};
int main()
{
	notepad note;
	note.enter_text();
	note.print_info();
	return 0;
}
