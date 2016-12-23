/*
ID: 20165227028 陈晓杰
PROG: 4.快速排序
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

//划分算法
int partition(vector<int> &vi, int low, int up)
{
	int pivot = vi[up];
	int i = low - 1;
	for (int j = low; j < up; j++)
	{
		if (vi[j] <= pivot)
		{
			i++;
			swap(vi[i], vi[j]);
		}
	}
	swap(vi[i + 1], vi[up]);
	return i + 1;
}

//递归实现快速排序
void quickSort(vector<int> &vi, int low, int up)
{
	if (low < up)
	{
		int mid = partition(vi, low, up);
		quickSort(vi, low, mid - 1);
		quickSort(vi, mid + 1, up);
	}
}
//业务逻辑的统一
void qSort(vector<int> &vi)
{
	quickSort(vi, 0, vi.size() - 1);
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
	int a1[] = { 3, 5, 7, 9, 2, 3, 1, 0, 7, 5, 4 };
	vector<int> va1(a1, a1 + 11);

	cout << "Ô­Êý×é£º\n";
	for (auto x : va1)
		cout << x << " ";
	cout << endl;

	qSort(va1);

	cout << "¿ìÅÅºó£º\n";
	for (auto x : va1)
		cout << x << " ";
	cout << endl;
	//system("pause");
	cout <<"-------------------------¡ü test1--------------------------" << endl;
	//-----------------------------------------------------------¡ü test	1--------------------------------------------------------
	int a2[] = { 3,55, 2, 3, 1, -5, 7, 14 };
	vector<int> va2(a2, a2 + 8);

	cout << "Ô­Êý×é£º\n";
	for (auto x : va2)
		cout << x << " ";
	cout << endl;

	qSort(va2);

	cout << "¿ìÅÅºó£º\n";
	for (auto x : va2)
		cout << x << " ";
	cout << endl;
	cout << "-------------------------¡ü test2--------------------------" << endl;
	//-----------------------------------------------------------¡ü test	2--------------------------------------------------------
	int a3[] = { 1111, -75, 2, 3, 1, -5, 7, 100,45 };
	vector<int> va3(a3, a3 + 9);

	cout << "Ô­Êý×é£º\n";
	for (auto x : va3)
		cout << x << " ";
	cout << endl;

	qSort(va3);

	cout << "¿ìÅÅºó£º\n";
	for (auto x : va3)
		cout << x << " ";
	cout << endl;
	cout << "-------------------------¡ü test3--------------------------" << endl;
	//-----------------------------------------------------------¡ü test	3--------------------------------------------------------

	ShowTime();
	return 0;
}