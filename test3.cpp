/*
ID: 20165227028 ������
PROG: 3.���ּ����ĵݹ����
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

//���ּ����ĵݹ����---->����һ����ֵ ��������������е�λ��
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
//ֱ�Ӳ��������������������������������ּ���
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
	nowtime = time(NULL);//��ȡ��ǰʱ��
	struct tm *local;
	local = localtime(&nowtime);  //��ȡ��ǰϵͳʱ��  
	cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
}
int main(){
	//��̬���벢��������
	int size1 = 8;
	int *a1 = new int[size1];
	
	cout << "�������"<<size1<<"�����ظ���������" << endl;
	for (int i = 0; i < size1; i++){
		cin >> a1[i];
	}
	cout << "����Ҫ��ѯ����ֵ��\n";
	int value1;
	cin >> value1;
	cout << "--------���ڽ�������-------" << endl;
	InsertSort(a1,size1);
	cout << "----------�������---------" << endl;
	for (int i = 0; i < size1; i++){
		cout << a1[i] << " ";
	}
	cout << "\n";
	int location1 = BINSRCH(a1, 0, size1-1, value1);
	
	if (location1 == -1){
		cout << "������û��value�����ֵ��Ԫ�ء�" << endl;
	}
	else{
		cout << "��ֵ" << value1 << "������ĵ�" << location1 + 1 << "��Ԫ��" << endl;
	}

	cout << "\n------------------------------------�� test 1----------------------------------" << endl;
	//-----------------------------------------------------------�� test	1--------------------------------------------------------
	int size2 = 5;
	int *a2 = new int[size2];

	cout << "�������" << size2 << "�����ظ���������" << endl;
	for (int i = 0; i < size2; i++){
		cin >> a2[i];
	}
	cout << "����Ҫ��ѯ����ֵ��\n";
	int value2;
	cin >> value2;
	cout << "--------���ڽ�������-------" << endl;
	InsertSort(a2, size2);
	cout << "----------�������---------" << endl;
	for (int i = 0; i < size2; i++){
		cout << a2[i] << " ";
	}
	cout << "\n";
	int location2 = BINSRCH(a2, 0, size2 - 1, value2);

	if (location2 == -1){
		cout << "������û��value�����ֵ��Ԫ�ء�" << endl;
	}
	else{
		cout << "��ֵ" << value2 << "������ĵ�" << location2 + 1 << "��Ԫ��" << endl;
	}

	cout << "\n------------------------------------�� test 2----------------------------------" << endl;
	//-----------------------------------------------------------�� test	2--------------------------------------------------------
	int size3 = 6;
	int *a3 = new int[size3];

	cout << "�������" << size3 << "�����ظ���������" << endl;
	for (int i = 0; i < size3; i++){
		cin >> a3[i];
	}
	cout << "����Ҫ��ѯ����ֵ��\n";
	int value3;
	cin >> value3;
	cout << "--------���ڽ�������-------" << endl;
	InsertSort(a3, size3);
	cout << "----------�������---------" << endl;
	for (int i = 0; i < size3; i++){
		cout << a3[i] << " ";
	}
	cout << "\n";
	int location3 = BINSRCH(a3, 0, size3 - 1, value3);

	if (location3 == -1){
		cout << "������û��value�����ֵ��Ԫ�ء�" << endl;
	}
	else{
		cout << "��ֵ" << value3 << "������ĵ�" << location3 + 1 << "��Ԫ��" << endl;
	}

	cout << "\n------------------------------------�� test 3----------------------------------" << endl;
	//-----------------------------------------------------------�� test	3--------------------------------------------------------

	ShowTime();
	return 0;
}