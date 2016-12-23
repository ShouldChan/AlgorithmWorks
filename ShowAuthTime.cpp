#include "ShowAuthTime.h"
#include <time.h>
#include <iostream>
using namespace std;

ShowAuthTime::ShowAuthTime()
{
	time_t nowtime;
	nowtime = time(NULL);//获取当前时间
	struct tm *local;
	local = localtime(&nowtime);  //获取当前系统时间  
	cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
}


ShowAuthTime::~ShowAuthTime()
{
}
