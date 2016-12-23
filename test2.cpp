/*
ID: 20165227028 陈晓杰
PROG: 2.递归求最大值
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

//递归求最大值
int MAX(int* array, int low, int high){
	if (low > high)
		return -1;
	else{
		if (array[low] < MAX(array, low + 1, high))
			return MAX(array, low + 1, high);
		else
			return array[low];
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
	//动态输入并创建数组
	int size = 8;
	int *a = new int[size];

	cout << "Input:" << endl;
	cout << "输入8个整数：" << endl;
	for (int i = 0; i < 8; i++){
		cin >> a[i];
	}
	cout << "Output:" << endl;
	cout<<"数组中最大的值为："<<MAX(a,0,7)<<endl;
	cout << "\n------------------------------------↑ test 1----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	1--------------------------------------------------------
	cout << "Input:" << endl;
	cout << "输入4个整数：" << endl;
	for (int i = 0; i < 4; i++){
		cin >> a[i];
	}
	cout << "数组中最大的值为：" << MAX(a, 0, 3) << endl;
	cout << "\n------------------------------------↑ test 2----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	2--------------------------------------------------------
	cout << "Input:" << endl;
	cout << "输入7个整数：" << endl;
	for (int i = 0; i < 7; i++){
		cin >> a[i];
	}
	cout << "Output:" << endl;
	cout << "数组中最大的值为：" << MAX(a, 0, 6) << endl;
	cout << "\n------------------------------------↑ test 3----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	3--------------------------------------------------------
	cout << "Input:" << endl;
	cout << "输入3个整数：" << endl;
	for (int i = 0; i < 3; i++){
		cin >> a[i];
	}
	cout << "Output:" << endl;
	cout << "数组中最大的值为：" << MAX(a, 0, 2) << endl;
	cout << "\n------------------------------------↑ test 4----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	4--------------------------------------------------------

	ShowTime();
	return 0;
}