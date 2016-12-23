/*
ID: 20165227028 ������
PROG: 8.Prim�㷨����С������
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1 << 21);//�趨һ���ܴ��ֵ������Ҿ�������������
//ʹ����ɫ����¼����״̬��white��ʾδ���ʹ���gray��ʾ���ʹ���Ȩֵ������С�ģ�black��ʾ���ʹ���Ҳ��Ȩֵ��С��
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];//M[][]��һ������ͼ���ڽӾ��� �ö�ά�������洢


//int prim(int (*M)[5],int n){
int prim(){
	int u, minv;
	int d[MAX];//d[]��������¼���㼯��T��V-T���ϵĶ���ı��У�Ȩֵ��С�ıߵ�Ȩֵ
	int p[MAX];//p[]��С�������еĽڵ�
	int color[MAX];//���ڼ�¼������ķ���״̬
	
	//�����ǵĵ㼯���г�ʼ��
	for (int i = 0; i < n; i++){
		d[i] = INFTY;
		p[i] = -1;
		color[i] = WHITE;
	}
	d[0] = 0;

	while (1){
		minv = INFTY;
		u = -1;
		//Ѱ�ҹ��ɱߵ�Ȩֵ��С�ĵ�
		for (int i = 0; i < n; i++){
			if (minv>d[i] && color[i] != BLACK){//���������Ȩֵ�����ǵĳ�ʼֵС���������δ�����ʹ�Ҳδ��ѡ�й�������Ϊ��С�ĵ�
				u = i;
				minv = d[i];
			}
		}
		if (u == -1) break;
		color[u] = BLACK;
		for (int v = 0; v < n; v++){
			if (color[v] != BLACK&&M[u][v] != INFTY){
				if (d[v]>M[u][v]){
					d[v] = M[u][v];
					p[v] = u;
					color[v] = GRAY;
				}
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++){
		if (p[i] != -1)
			sum += M[i][p[i]];
	}
	/*cout << " ��С�������ĵ㼯���£�" << endl;
	for (int i = 0; i < n; i++){
		cout << p[i] << " ";
	}*/
	return sum;
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
	cout << "PS:�߲�����ʱ��Ϊ -1" << endl;
	cout << "�����ȨͼG�Ķ�������" << endl;
	cin >> n;

	cout << "����"<<n<<"���ڽӾ���ÿ�к��Իس���β������һ�У���" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int e;
			cin >> e;
			M[i][j] = (e == -1) ? INFTY : e;
		}
	}
	cout << "�����С�������ĸ���Ȩֵ֮�ͣ�"<< endl;
	cout << prim()<<endl;

	//int M[][5]= { { -1, 2, 3, 1, -1 }, 
	//					{ 2, -1, -1, 4, -1 }, 
	//					{ 3, -1, -1, 1, 100 }, 
	//					{ 1, 4, 1, -1, 3 }, 
	//					{ -1, -1, 1, 3, -1 } };

	//cout << prim(M,5) << endl;

	cout << "-------------------------�� test1--------------------------" << endl;
	//-----------------------------------------------------------�� test	1--------------------------------------------------------
	cout << "�����ȨͼG�Ķ�������" << endl;
	cin >> n;

	cout << "����" << n << "���ڽӾ���ÿ�к��Իس���β������һ�У���" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int e;
			cin >> e;
			M[i][j] = (e == -1) ? INFTY : e;
		}
	}
	cout << "�����С�������ĸ���Ȩֵ֮�ͣ�" << endl;
	cout << prim() << endl;
	cout << "-------------------------�� test2--------------------------" << endl;
	//-----------------------------------------------------------�� test	2--------------------------------------------------------

	cout << "�����ȨͼG�Ķ�������" << endl;
	cin >> n;

	cout << "����" << n << "���ڽӾ���ÿ�к��Իس���β������һ�У���" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int e;
			cin >> e;
			M[i][j] = (e == -1) ? INFTY : e;
		}
	}
	cout << "�����С�������ĸ���Ȩֵ֮�ͣ�" << endl;
	cout << prim() << endl;
	cout << "-------------------------�� test3--------------------------" << endl;
	//-----------------------------------------------------------�� test	3--------------------------------------------------------

	ShowTime();
	return 0;
}