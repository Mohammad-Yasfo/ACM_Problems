/*
دالة لحساب عاملي العدد
*/
long long P_number (long long int x){
long long int y=x-1;
for (y;y>0;--y)
	x*=y;
	return x;}
