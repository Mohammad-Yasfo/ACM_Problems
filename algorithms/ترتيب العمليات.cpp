#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <conio.h>
using namespace std;
long double ope (string m)
{
	int length=0,lenstr=0,lenope=0;
	vector <char> str;
	vector <char> strc;
	vector <long double> strn;
	vector <char> operators;
	length=m.length();
	if(length==0)
		return 0;	
	for (int i=0;i<length;++i){
		if ((m [i]>=48) && (m[i]<=57)){
			long double num=0,numofp=1;
			bool point=false;
			while  ((i<length)&&(((m [i]>=48) && (m[i]<=57)) || (m [i]=='.'))){
				if (m [i]=='.')
					point=true;
				else if (point==false){
				num*=10;
				num+=m [i]-48;}
				else{
					num+=((m [i]-48)/powl (10,numofp));
					++numofp;}
				++i;}
			strn.push_back (num);
			str.push_back('n');
			strc.push_back('n');
			++lenstr;
			--i;}
		else if (((m [i]=='*') || (m [i]=='/')) || ((m [i]=='-') || (m [i]=='+'))){
			if (lenope==0){
				operators.push_back(m [i]);
				++lenope;}
			else if (((operators [lenope-1]=='*') ||(operators [lenope-1]== '/')) && ((m [i]=='+') || (m [i]=='-'))){
				
				str.push_back(operators [lenope-1]);
				strn.push_back(0);
				strc.push_back('c');
				++lenstr;
				operators.pop_back();
				--lenope;
				operators.push_back(m [i]);
				++lenope;}
			else{
				operators.push_back(m [i]);
				++lenope;}}
		else if (m [i]=='('){
			int check=0;
			string c;
			++i;
			while (( m [i]!=')') ||(check>0)){
				if (m [i]=='(')
					++check;
				else if (m [i]==')')
					--check;
					c+=m [i];
				++i;}
			long double g=ope(c);
			strn.push_back (g);
			str.push_back('n');
			strc.push_back('n');
			++lenstr;
			--i;}}
		for (lenope;lenope>0;--lenope){
			str.push_back (operators [lenope-1]);
			strn.push_back(0);
			strc.push_back('c');
			++lenstr;
			operators.pop_back();}
		length=lenstr;
	while (length>1){
		int o=0;
		while ((o<length) && ((((str [o]!='*') && (str [o]!='/')) && ((str [o]!='-') && (str [o]!='+')))||(strc [o]=='n')))
			++o;
		long double t;
		long double first=strn [o-2],second=strn [o-1];
		switch (str [o]){
		case '*':
			t=first*second;
			break;
		case '+':
			t=first+second;
			break;
		case '/':
			t=first/second;
			break;
		case '-':
			t=first-second;
			break;}
		strn [o-2]=t;
		for (int d=o+1;d<length;++d){
			str [d-2]=str [d];
			strn [d-2]=strn [d];
			strc [d-2]=strc [d];}
		str.pop_back();str.pop_back();
		strc.pop_back();strc.pop_back();
		strn.pop_back();strn.pop_back();
		length-=2;}
	cout<<strn [0];
	return  strn [0];
}