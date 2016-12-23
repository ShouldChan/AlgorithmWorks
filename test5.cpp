/*
ID: 20165227028 ������
PROG: 5.SELECT2ѡ���㷨
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

//�����㷨
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

//���Բ��������㷨
void INSERTIONSORT(vector<int> &a, int start, int len){
	for (int i = 1; i < len; i++){
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key){
			a[j + 1] = a[j];
			j--;//a[j]�Ǻ�ǰ���Ԫ�رȽ�����Ҫj--
		}
		a[j + 1] = key;
	}
}
//��������Ԫ�ص�ֵ
void INTERCHANGE(vector<int> &A, int x, int y){
	int temp;
	temp = x;
	x = y;
	y = temp;
}

//�Ľ���SELECT2�㷨,Ŀ�ľ����ҳ���kС��Ԫ��
int SELECT2(vector<int> &A, int start, int end, int k){
	int n = A.size();
	int r = n / 2;//�̶�������Ԫ�ط�Ϊ������ 
	//������鳤��С�ڷ��鳤�ȣ�ֱ�ӽ��в�������
	if (end - start + 1 <= r){
		INSERTIONSORT(A, 0, end + 1);
		return end - start + 1;
	}
	while (true){
		n = end - start + 1;
		for (int i = 1; i < n / r; i++){
			//ѭ���������ÿ�������ֵ������ÿ����ֵ�ƶ�������ǰ��
			//��ÿ����в�������
			INSERTIONSORT(A, start + (i - 1)*r, start + i*r - 1);
			//���м�ֵ�ŵ�����ǰ�ˣ���ǰ��ԭ����ֵ���н���
			INTERCHANGE(A, start + (i - 1)*r + r / 2 - 1, start + i - 1);
		}
		//�õ������м�ֵ
		int m = SELECT2(A, start, start + n / r - 1, ceil(double(n / r) / 2));//����ceil�����þ���ȡ����x����С����
		//�������м�ֵ�ŵ���ǰ��
		INTERCHANGE(A, start, m);

		//���л���
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
	nowtime = time(NULL);//��ȡ��ǰʱ��
	struct tm *local;
	local = localtime(&nowtime);  //��ȡ��ǰϵͳʱ��  
	cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
}

int main(){
	int a1[] = { 3, 5, 7, 9, 2, 3, 1, 2, 7, 5, 4 };
	vector<int> va1(a1, a1 + 11);
	cout << "ԭ����1��\n";
	for (auto x : va1)
		cout << x << " ";
	cout << "\n������Ҫ���ҵ�Ԫ�أ�" << endl;
	int dd1;
	cin >> dd1;
	cout << "��Ҫ���ҵ�Ԫ���ǵ�" << SELECT2(va1, 0, 10, dd1) << "С��Ԫ��" << endl;
	cout << "-------------------------�� test1--------------------------" << endl;
	//-----------------------------------------------------------�� test	1--------------------------------------------------------
	int a2[] = { 3, 55, 2, 3, 1, 5, 7, 14 };
	vector<int> va2(a2, a2 + 8);

	cout << "ԭ����2��\n";
	for (auto x : va2)
		cout << x << " ";
	cout << "\n������Ҫ���ҵ�Ԫ�أ�" << endl;
	int dd2;
	cin >> dd2;
	cout << "��Ҫ���ҵ�Ԫ���ǵ�" << SELECT2(va2, 0, 7, dd2) << "С��Ԫ��" << endl;
	cout << "-------------------------�� test2--------------------------" << endl;
	//-----------------------------------------------------------�� test	2--------------------------------------------------------
	int a3[] = { 1111, 75, 2, 3, 1, 5, 7, 100, 45 };
	vector<int> va3(a3, a3 + 9);

	cout << "ԭ���飺\n";
	for (auto x : va3)
		cout << x << " ";
	cout << "\n������Ҫ���ҵ�Ԫ�أ�" << endl;
	int dd3;
	cin >> dd3;
	cout << "��Ҫ���ҵ�Ԫ���ǵ�" << SELECT2(va3, 0, 8, dd3) << "С��Ԫ��" << endl;
	cout << "-------------------------�� test3--- -----------------------" << endl;
	//-----------------------------------------------------------�� test	3--------------------------------------------------------

	ShowTime();
	return 0;
}