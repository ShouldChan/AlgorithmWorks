/*
ID: 20165227028 陈晓杰
PROG: 5.SELECT2选择算法
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

//线性插入排序算法
void INSERTIONSORT(vector<int> &a, int start, int len){
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
//交换两个元素的值
void INTERCHANGE(vector<int> &A, int x, int y){
	int temp;
	temp = x;
	x = y;
	y = temp;
}

//改进的SELECT2算法,目的就是找出第k小的元素
int SELECT2(vector<int> &A, int start, int end, int k){
	int n = A.size();
	int r = n / 2;//固定把所有元素分为多少组 
	//如果数组长度小于分组长度，直接进行插入排序
	if (end - start + 1 <= r){
		INSERTIONSORT(A, 0, end + 1);
		return end - start + 1;
	}
	while (true){
		n = end - start + 1;
		for (int i = 1; i < n / r; i++){
			//循环分组求出每个组的中值，并将每组中值移动至数组前端
			//对每组进行插入排序
			INSERTIONSORT(A, start + (i - 1)*r, start + i*r - 1);
			//将中间值放到数组前端，与前端原来的值进行交换
			INTERCHANGE(A, start + (i - 1)*r + r / 2 - 1, start + i - 1);
		}
		//得到最后的中间值
		int m = SELECT2(A, start, start + n / r - 1, ceil(double(n / r) / 2));//调用ceil，作用就是取大于x的最小整数
		//把最后的中间值放到最前端
		INTERCHANGE(A, start, m);

		//进行划分
		int res = partition(A, start, end);
		if (res - start + 1 == k)
			return res+1;
		else if (res - start + 1 > k){
			end = res - 1;
		}
		else
		{
			k = k - (res - start + 1);
			start = res + 1;
		}
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
	int a1[] = { 3, 5, 7, 9, 2, 3, 1, 2, 7, 5, 4 };
	vector<int> va1(a1, a1 + 11);
	cout << "原数组1：\n";
	for (auto x : va1)
		cout << x << " ";
	cout << "\n输入你要查找的元素：" << endl;
	int dd1;
	cin >> dd1;
	cout << "您要查找的元素是第" << SELECT2(va1, 0, 10, dd1) << "小的元素" << endl;
	cout << "-------------------------↑ test1--------------------------" << endl;
	//-----------------------------------------------------------↑ test	1--------------------------------------------------------
	int a2[] = { 3, 55, 2, 3, 1, 5, 7, 14 };
	vector<int> va2(a2, a2 + 8);

	cout << "原数组2：\n";
	for (auto x : va2)
		cout << x << " ";
	cout << "\n输入你要查找的元素：" << endl;
	int dd2;
	cin >> dd2;
	cout << "您要查找的元素是第" << SELECT2(va2, 0, 7, dd2) << "小的元素" << endl;
	cout << "-------------------------↑ test2--------------------------" << endl;
	//-----------------------------------------------------------↑ test	2--------------------------------------------------------
	int a3[] = { 1111, 75, 2, 3, 1, 5, 7, 100, 45 };
	vector<int> va3(a3, a3 + 9);

	cout << "原数组：\n";
	for (auto x : va3)
		cout << x << " ";
	cout << "\n输入你要查找的元素：" << endl;
	int dd3;
	cin >> dd3;
	cout << "您要查找的元素是第" << SELECT2(va3, 0, 8, dd3) << "小的元素" << endl;
	cout << "-------------------------↑ test3--- -----------------------" << endl;
	//-----------------------------------------------------------↑ test	3--------------------------------------------------------

	ShowTime();
	return 0;
}