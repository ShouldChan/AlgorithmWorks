/*
ID: 20165227028 ������
PROG: 10.���ͼ����ǰ�����㷨
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

#define MAX 100  
//#define n 12   /*������*/
//#define k 5  /*����*/
//int c[n][n];

//Show time&designer
class ShowTime{
public:
	void Show(){
		time_t nowtime;
		nowtime = time(NULL);//��ȡ��ǰʱ��
		struct tm *local;
		local = localtime(&nowtime);  //��ȡ��ǰϵͳʱ��  
		cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
	}
};

//��ʼ��ͼ
void init_static(vector<int> cost,vector<vector<int>> c)
{
	int i, j;
	for (i = 0; i < 13; i++){
		for (j = 0; j < 13; j++)
			c[i][j] = MAX;
	}

	c[1][2] = 9; c[1][3] = 7; c[1][4] = 3; c[1][5] = 2; c[2][6] = 4; c[2][7] = 2; c[2][8] = 1;

	c[3][6] = 2; c[3][7] = 7; c[4][8] = 11; c[5][7] = 11; c[5][8] = 8; c[6][9] = 6; c[6][10] = 5;

	c[7][9] = 4; c[7][10] = 3; c[8][10] = 5; c[8][11] = 6; c[9][12] = 4; c[10][12] = 2; c[11][12] = 5;

	//cout << "1 2 " << c[1][2] << endl;

}
void init_dynamic(vector<vector<int>> c, int jds, int bs){
	/*for (int i = 0; i < jds + 1; i++){
		for (int j = 0; j < jds + 1; j++)
			c[i][j] = MAX;
	}*/
	int a=0, b=0;
	cout << "��������ߣ�" << endl;
	for (int i = 0; i < bs + 1; i++){
		cin >> a >> b >> c[a][b];
	}

}

//ʹ����ǰ�����㷨����ͼ�����·��
void fgraph(vector<int> cost, vector<int> path, vector<int> d, vector<vector<int>> c, int jds, int ds){
	int r, j, t, min;
	/*for (j = 0; j <= jds; j++)
		cost[j] = 0;*/

	for (j = jds - 1; j >= 1; j--){
		r = 0;
		min = c[j][r] + cost[r];       //��ʼ����Сֵ

		for (t = 0; t <= jds; t++){
			if (c[j][t] != MAX){
				//�ҵ���С��r
				if ((c[j][t] + cost[t]) < min){
					min = c[j][t] + cost[t];
					r = t;
				}
			}
		}
		cost[j] = c[j][r] + cost[r];
		d[j] = r;
	}

	path[1] = 1;
	path[ds] = jds;

	for (j = 2; j < ds; j++)
		path[j] = d[path[j - 1]];

	cout << "������ͼ�����·���ǣ�" << endl;
	for (int x = 1; x <= ds; x++){
		if (x == ds)
			cout << path[x] << endl;
		else
			cout << path[x] << "��>";
	}
	cout << "������ͼ���·���ĳ��ȣ�" <<cost[1]<< endl;
}
int main(){

	//int cost[13], d[12];
	int jds, ds, bs;
	cout << "����ڵ�����������ͱ�����" << endl;
	cin >> jds >> ds >> bs;
	vector<int> cost(jds+1,0), d(jds+1), path(ds+1);
	vector<vector<int>> c(jds+1,vector<int>(jds+1,MAX));

	int a=0, b=0;
	cout << "��������ߣ�" << endl;
	for (int i = 1; i < bs + 1; i++){
		cin >> a >> b >> c[a][b];
	}

	//for (int i = 0; i < k; i++){
	//	path[i] = -1;//-1 means null
	//}
	//init_dynamic(c, jds, bs);
	fgraph(cost, path, d, c, jds, ds);
	cout << "----------------------------------�� test1 -------------------------------------" << endl;
	//-----------------------------------------------------------�� test --------------------------------------------------------

	ShowTime st;
	st.Show();
	//system("pause");
	return 0;
}