/*
ID: 20165227028 ������
PROG: 14.�˻ʺ�����
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

//���ݷ����ǵ����ֵ�ǰ״̬�ò�����ʱ�ж����������أ��Ե�ʱ�ж�λ��Ϊ��㣩��һ״̬����������
#define N 8//n�ʺ�ֻ��Ҫ��һ��N��ֵ
#define FREE -1//��ʾ�����ܵ�����
#define NOT_FREE 1//��ʾ�����ܵ�����

int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];//dpos������б�����µ�x���ܵ�������dneg������б�����µ�x���ܵ�����
bool X[N][N];

//��ʼ������
void initialize(){
	for (int i = 0; i < N; i++){
		row[i] = FREE;
		col[i] = FREE;
	}
	for (int i = 0; i < 2 * N - 1; i++){
		dpos[i] = FREE;
		dneg[i] = FREE;
	}
}

//��ӡ����˻ʺ������
void print(){
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (X[i][j]){
				if (row[i] != j)
					return;
			}
		}
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cout << ((row[i] == j) ? "Q " : "* ");
		}
		cout << endl;
	}
}

//ʹ�û��ݷ�
void recursive(int i){
	if (i == N){//�ɹ����ûʺ�
		print();
		return;
	}

	for (int j = 0; j < N; j++){
		//�����i��j���ܵ������ʺ�Ĺ���������Ըø���
		if (col[j] == NOT_FREE || dpos[i + j] == NOT_FREE || dneg[i - j + (N - 1)] == NOT_FREE)
			continue;//������ִ�н������� ֱ����j++
		//�ڣ�i��j�������ûʺ�
		row[i] = j;
		col[j] = dpos[i + j] = dneg[i - j + (N - 1)] = NOT_FREE;

		recursive(i + 1);

		//�õ��ڣ�i��j�����ڷŵĻʺ�
		row[i] = col[j] = dpos[i + j] = dneg[i - j + (N - 1)] = FREE;
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
	cout << "������Ҫ�ڷŵĻʺ������" << endl;
	initialize();
	int k1;
	cin >> k1;
	cout << "������Щ�ʺ��λ�ã�" << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			X[i][j] = false;
		}
	}
	for (int i = 0; i < k1; i++){
		int r, c;
		cin >> r >> c;
		X[r][c] = true;
	}
	cout << "������̵Ĳ��֣�" << endl;
	recursive(0);
	cout << "-------------------------�� test1--------------------------" << endl;
	//-----------------------------------------------------------�� test	1--------------------------------------------------------
	cout << "������Ҫ�ڷŵĻʺ������" << endl;
	initialize();
	int k2;
	cin >> k2;
	cout << "������Щ�ʺ��λ�ã�" << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			X[i][j] = false;
		}
	}
	for (int i = 0; i < k2; i++){
		int r, c;
		cin >> r >> c;
		X[r][c] = true;
	}
	cout << "������̵Ĳ��֣�" << endl;
	recursive(0);
	cout << "-------------------------�� test2--------------------------" << endl;
	//-----------------------------------------------------------�� test	2--------------------------------------------------------
	cout << "������Ҫ�ڷŵĻʺ������" << endl;
	initialize();
	int k3;
	cin >> k3;
	cout << "������Щ�ʺ��λ�ã�" << endl;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			X[i][j] = false;
		}
	}
	for (int i = 0; i < k3; i++){
		int r, c;
		cin >> r >> c;
		X[r][c] = true;
	}
	cout << "������̵Ĳ��֣�" << endl;
	recursive(0);
	cout << "-------------------------�� test3--------------------------" << endl;
	//-----------------------------------------------------------�� test	3--------------------------------------------------------

	ShowTime();
	return 0;
}