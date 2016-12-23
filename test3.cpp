/*
ID: 20165227028 陈晓杰
PROG: 3.二分检索的递归程序
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

//二分检索的递归程序---->输入一个数值 查这个数在数组中的位置
int BINSRCH(int *array, int low, int high, int value){
	int mid = (low + high) / 2;
	if (low > high)
		return -1;
	else if (value > array[mid])
		return BINSRCH(array, mid + 1, high, value);
	else if (value < array[mid])
		return BINSRCH(array, low, mid - 1, value);
	else if (value == array[mid])
		return mid;
}
//直接插入排序对输入的数组进行排序后在做二分检索
void InsertSort(int *array, int length){
	for (int i = 1; i < length; i++){
		int key = array[i];
		int j = i - 1;
		while (j >= 0 && array[j]>key){
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
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
	int size1 = 8;
	int *a1 = new int[size1];
	
	cout << "随机输入"<<size1<<"个无重复的整数：" << endl;
	for (int i = 0; i < size1; i++){
		cin >> a1[i];
	}
	cout << "输入要查询的数值：\n";
	int value1;
	cin >> value1;
	cout << "--------正在进行有序化-------" << endl;
	InsertSort(a1,size1);
	cout << "----------有序化完成---------" << endl;
	for (int i = 0; i < size1; i++){
		cout << a1[i] << " ";
	}
	cout << "\n";
	int location1 = BINSRCH(a1, 0, size1-1, value1);
	
	if (location1 == -1){
		cout << "数组中没有value这个数值的元素。" << endl;
	}
	else{
		cout << "该值" << value1 << "是数组的第" << location1 + 1 << "个元素" << endl;
	}

	cout << "\n------------------------------------↑ test 1----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	1--------------------------------------------------------
	int size2 = 5;
	int *a2 = new int[size2];

	cout << "随机输入" << size2 << "个无重复的整数：" << endl;
	for (int i = 0; i < size2; i++){
		cin >> a2[i];
	}
	cout << "输入要查询的数值：\n";
	int value2;
	cin >> value2;
	cout << "--------正在进行有序化-------" << endl;
	InsertSort(a2, size2);
	cout << "----------有序化完成---------" << endl;
	for (int i = 0; i < size2; i++){
		cout << a2[i] << " ";
	}
	cout << "\n";
	int location2 = BINSRCH(a2, 0, size2 - 1, value2);

	if (location2 == -1){
		cout << "数组中没有value这个数值的元素。" << endl;
	}
	else{
		cout << "该值" << value2 << "是数组的第" << location2 + 1 << "个元素" << endl;
	}

	cout << "\n------------------------------------↑ test 2----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	2--------------------------------------------------------
	int size3 = 6;
	int *a3 = new int[size3];

	cout << "随机输入" << size3 << "个无重复的整数：" << endl;
	for (int i = 0; i < size3; i++){
		cin >> a3[i];
	}
	cout << "输入要查询的数值：\n";
	int value3;
	cin >> value3;
	cout << "--------正在进行有序化-------" << endl;
	InsertSort(a3, size3);
	cout << "----------有序化完成---------" << endl;
	for (int i = 0; i < size3; i++){
		cout << a3[i] << " ";
	}
	cout << "\n";
	int location3 = BINSRCH(a3, 0, size3 - 1, value3);

	if (location3 == -1){
		cout << "数组中没有value这个数值的元素。" << endl;
	}
	else{
		cout << "该值" << value3 << "是数组的第" << location3 + 1 << "个元素" << endl;
	}

	cout << "\n------------------------------------↑ test 3----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	3--------------------------------------------------------

	ShowTime();
	return 0;
}