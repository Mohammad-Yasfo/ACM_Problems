
#include<windows.h>
#include <iostream>
#include <string>
using namespace std;
int main()
{  
    HWND mycommand=GetConsoleWindow();//مقبض نافذه الكتابة
    HDC myhdc=GetDC(mycommand);//مقبض الرسم والكتابه بمعرفه مقبض النافذه
    SetTextColor(myhdc, RGB(255,255,255));//لون النص
    SetBkColor(myhdc, RGB(0,0,0));//لون الخلفيه
	HDC m1=GetDC(mycommand);
    wchar_t* line1=L"بسم الله الرحمن الرحيم";
    wchar_t* line2=L"الحمدلله رب العالمين";
	char * line="بشر";
    TextOutW(myhdc,150,0 ,line2,::wcslen(line2));//دالة الكتابة
	TextOutA(myhdc,150,100,"بس",2);
	string f=line;
	TextOutA(myhdc,150,100,line,f.length());
	TextOutW(m1,150,100 ,line1,::wcslen(line1));
	int n;
	cin>>n;
return 0;
}
