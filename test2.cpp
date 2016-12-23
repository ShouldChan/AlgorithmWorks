/*
ID: 20165227028 ������
PROG: 2.�ݹ������ֵ
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

//�ݹ������ֵ
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
	nowtime = time(NULL);//��ȡ��ǰʱ��
	struct tm *local;
	local = localtime(&nowtime);  //��ȡ��ǰϵͳʱ��  
	cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
}
int main(){
	//��̬���벢��������
	int size = 8;
	int *a = new int[size];

	cout << "Input:" << endl;
	cout << "����8��������" << endl;
	for (int i = 0; i < 8; i++){
		cin >> a[i];
	}
	cout << "Output:" << endl;
	cout<<"����������ֵΪ��"<<MAX(a,0,7)<<endl;
	cout << "\n------------------------------------�� test 1----------------------------------" << endl;
	//-----------------------------------------------------------�� test	1--------------------------------------------------------
	cout << "Input:" << endl;
	cout << "����4��������" << endl;
	for (int i = 0; i < 4; i++){
		cin >> a[i];
	}
	cout << "����������ֵΪ��" << MAX(a, 0, 3) << endl;
	cout << "\n------------------------------------�� test 2----------------------------------" << endl;
	//-----------------------------------------------------------�� test	2--------------------------------------------------------
	cout << "Input:" << endl;
	cout << "����7��������" << endl;
	for (int i = 0; i < 7; i++){
		cin >> a[i];
	}
	cout << "Output:" << endl;
	cout << "����������ֵΪ��" << MAX(a, 0, 6) << endl;
	cout << "\n------------------------------------�� test 3----------------------------------" << endl;
	//-----------------------------------------------------------�� test	3--------------------------------------------------------
	cout << "Input:" << endl;
	cout << "����3��������" << endl;
	for (int i = 0; i < 3; i++){
		cin >> a[i];
	}
	cout << "Output:" << endl;
	cout << "����������ֵΪ��" << MAX(a, 0, 2) << endl;
	cout << "\n------------------------------------�� test 4----------------------------------" << endl;
	//-----------------------------------------------------------�� test	4--------------------------------------------------------

	ShowTime();
	return 0;
}