/*
دالة لاختبار إذا كان العدد أولياً أم لا
*/
template <class T>bool isprime(T  number)
{
	if (number==1)
		return false;
	for (int i=2;i<number/2;++i)
		if ((int)number%i==0)
			return false;
	return true;
}
