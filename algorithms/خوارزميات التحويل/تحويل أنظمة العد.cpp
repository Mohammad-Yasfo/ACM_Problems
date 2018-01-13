/*
البرنامج عبارة عن دالة تحول بين أنظمة العد كافة
لها ثلاث مدخلات 
1-العدد المراد تحويله
2-بأي نظام هو
3-لأي نظام سيحول
*/
string convert(string number,int type,int to_type)
{
	long long N=0;
	for (int i=0;i<number.length();++i)
	{
		if (!isalpha(number [i]))
		N+=(number [i]-48)*pow(type,number.length()-1-i);
		else
		N+=(number [i]-55)*pow(type,number.length()-1-i);
	}
	number="";
	while (N!=0)
	{
		if (N%to_type>10)
			number+=(char)N%to_type+53;
		else
		number+=N%to_type+48;
		N/=to_type;
	}
	for (int i=0;i<number.length()/2;++i)
		swap(number [i],number [number.length()-1-i]);
	return number;
}
