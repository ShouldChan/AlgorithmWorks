#include "ShowAuthTime.h"
#include <time.h>
#include <iostream>
using namespace std;

ShowAuthTime::ShowAuthTime()
{
	time_t nowtime;
	nowtime = time(NULL);//��ȡ��ǰʱ��
	struct tm *local;
	local = localtime(&nowtime);  //��ȡ��ǰϵͳʱ��  
	cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
}


ShowAuthTime::~ShowAuthTime()
{
}
