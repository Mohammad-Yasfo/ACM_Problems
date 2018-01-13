/*
تحتاج للتعديل
*/
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int n,m;
string str1,str2;
vector<string>sol;
vector<int>repeat;
void search(int len1,int len2,string str){
	if(len1==n && len2==m){
		for(int i=0;i<sol.size();i++){
			if(sol[i] == str){
				repeat[i]++;
				return;
			}
		}
		sol.push_back(str);
		repeat.push_back(1);
		return;
	}
	string temp;
	if(len1<n){
		temp = str+str1[len1];
		search(len1+1,len2,temp);
	}
	if(len2<m){
		temp = str+str2[len2];
		search(len1,len2+1,temp);
	}
}
int main(){
	ifstream fin("line.in");
	ofstream fout ("line.out");
	fin>>n>>m;

	fin>>str1>>str2;
	int len1=0,len2=0;
	search(0,0,"");
	long long int sols=0;
	for(int i=0;i<repeat.size();i++){
		sols += repeat[i]*repeat[i];
	}
	fout<<sols%97654321<<endl;
}
/*
PROG: lego
LANG: C++
ID: shadi-s1
*/

#include <fstream>
using namespace std;

int N1, N2;
char line1[176], line2[176];
int dp1[30976];
int dp2[30976];

int main() {
	ifstream inp("lego.in");
	ofstream outp("lego.out");
	
	inp >> N1 >> N2 >> line1 >> line2;
	
	dp1[0] = 1;
	for (int i = 1; i <= N2; i++)
		for (int j = 0; j <= N1 && j <= i; j++) {
			if (j > 0 && line2[i-1] == line1[j-1]) dp1[i*176+j] = dp1[(i-1)*176+j-1];
			if (j < i && line2[i-1] == line2[i-j-1]) dp1[i*176+j] = (dp1[i*176+j]+dp1[(i-1)*176+j])%97654321;
		}
	
	int* cur = dp2;
	int* prev = dp1;
	for (int k = 1; k <= N1; k++) { // Pos in the first string the first time
		for (int i = 0; i <= N2; i++) // Pos in the second string the first time
			for (int j = 0; j <= N1 && j <= i+k; j++) { // Pos in the first string the second time
				cur[i*176+j] = 0;
				if (i+k-j > N2) continue;
				if (i > 0 && j > 0 && line2[i-1] == line1[j-1]) cur[i*176+j] = cur[(i-1)*176+j-1];
				if (i > 0 && j < i+k && line2[i-1] == line2[i+k-j-1]) cur[i*176+j] = (cur[i*176+j]+cur[(i-1)*176+j])%97654321;
				if (j > 0 && line1[k-1] == line1[j-1]) cur[i*176+j] = (cur[i*176+j]+prev[i*176+j-1])%97654321;
				if (j < i+k && line1[k-1] == line2[i+k-j-1]) cur[i*176+j] = (cur[i*176+j]+prev[i*176+j])%97654321;
			}
		int* temp = prev;
		prev = cur;
		cur = temp;
	}
	
	outp << prev[N2*176+N1] << endl;
	return 0;
}
