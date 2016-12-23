/*
ID: 20165227028 陈晓杰
PROG: 1.递归求最大公因子
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
using namespace std;

//求最大公因子
int GCD(int a, int b){
	if (a > 0 && b > 0 && a > b){
		return GCD(b, (a % b));
	}
	else if (b == 0){
		return a;
	}
}
//一波业务逻辑
void Business(int a, int b){
	if (a > 0 && b > 0 && a > b){
		cout << "其最大公因子为：" << GCD(a, b);
	}
	else{
		cout << "该用例不符合算法要求";
	}
}
//Show time&designer
void ShowTime(){
	time_t nowtime;
	nowtime = time(NULL);//获取当前时间
	struct tm *local;
	local = localtime(&nowtime);  //获取当前系统时间  
	cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
}
int main(){
	int a, b;
	cout << "Input:" << endl;
	cout << "输入要求：a>b>0" << endl;
	cin >> a >> b;
	cout << "Output:" << endl;
	Business(a, b);//24 16
	cout << "\n------------------------------------↑ test 1----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	1--------------------------------------------------------
	cout << "Input:" << endl;
	cout << "输入要求：a>b>0" << endl;
	cin >> a >> b;
	cout << "Output:" << endl;
	Business(a, b);//100 25
	cout << "\n------------------------------------↑ test 2----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	2--------------------------------------------------------
	cout << "Input:" << endl;
	cout << "输入要求：a<0,b>0" << endl;
	cin >> a >> b;
	cout << "Output:" << endl;
	Business(a, b);//-12 2
	cout << "\n------------------------------------↑ test 3----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	3--------------------------------------------------------
	cout << "Input:" << endl;
	cout << "输入要求：a=0,b>0" << endl;
	cin >> a >> b;
	cout << "Output:" << endl;
	Business(a, b);//0 10
	cout << "\n------------------------------------↑ test 4----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	4--------------------------------------------------------
	cout << "Input:" << endl;
	cout << "输入要求：a>0,b<0" << endl;
	cin >> a >> b;
	cout << "Output:" << endl;
	Business(a, b);//3 -6
	cout << "\n------------------------------------↑ test 5----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	5--------------------------------------------------------
	ShowTime();
	return 0;
}