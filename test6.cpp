/*
ID: 20165227028 陈晓杰
PROG: 6.线性插入排序
LANG: C++
*/
#include<iostream>
#include<time.h>
using namespace std;

//线性插入排序算法
void LinearInsertionSort(int *a, int len){
	for (int i = 1; i < len; i++){
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key){
			a[j + 1] = a[j];
			j--;//a[j]是和前面的元素比较所以要j--
		}
		a[j + 1] = key;
	}
}
//遍历数组的方法
void TravelArray(int *a, int len){
	for (int i = 0; i < len; i++){
		cout << a[i] << "\t";
	}
}
int main(){
	int a1[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	cout << "原数组1：" << endl;
	int len1 = (sizeof(a1) / sizeof(a1[0]));
	TravelArray(a1, len1);
	LinearInsertionSort(a1, len1);
	cout << "\n排序后的数组1：" << endl;
	TravelArray(a1, len1);
	cout << "\n------------------------------------↑ test 1----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	1--------------------------------------------------------
	int a2[] = { 21, 84, 99, 45, 1, 3, 35, 5 };
	cout << "原数组2：" << endl;
	int len2 = (sizeof(a2) / sizeof(a2[0]));
	TravelArray(a2, len2);
	LinearInsertionSort(a2, len2);
	cout << "\n排序后的数组2：" << endl;
	TravelArray(a2, len2);
	cout << "\n------------------------------------↑ test 2----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	2--------------------------------------------------------
	int a3[] = { 6666666, 666666, 666, 66, 6 };
	cout << "原数组3：" << endl;
	int len3 = (sizeof(a3) / sizeof(a3[0]));
	TravelArray(a3, len3);
	LinearInsertionSort(a3, len3);
	cout << "\n排序后的数组3：" << endl;
	TravelArray(a3, len3);
	cout << "\n------------------------------------↑ test 3----------------------------------" << endl;
	//-----------------------------------------------------------↑ test	3--------------------------------------------------------
	time_t nowtime;
	nowtime = time(NULL);//获取当前时间
	struct tm *local;
	local = localtime(&nowtime);  //获取当前系统时间  
	cout << asctime(local) <<"\t\t\t"<< "by ShouldChan" << endl;
	return 0;
}