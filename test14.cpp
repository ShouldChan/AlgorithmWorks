/*
ID: 20165227028 陈晓杰
PROG: 14.八皇后问题
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

//回溯法就是当发现当前状态得不到解时中断搜索并返回（以当时中断位置为起点）上一状态继续搜索。
#define N 8//n皇后只需要改一下N的值
#define FREE -1//表示不会受到攻击
#define NOT_FREE 1//表示会遭受到攻击

int row[N], col[N], dpos[2 * N - 1], dneg[2 * N - 1];//dpos是棋盘斜向左下的x列受到攻击，dneg是棋盘斜向右下的x列受到攻击
bool X[N][N];

//初始化棋盘
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

//打印输出八皇后的排列
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

//使用回溯法
void recursive(int i){
	if (i == N){//成功放置皇后
		print();
		return;
	}

	for (int j = 0; j < N; j++){
		//如果（i，j）受到其他皇后的攻击，则忽略该格子
		if (col[j] == NOT_FREE || dpos[i + j] == NOT_FREE || dneg[i - j + (N - 1)] == NOT_FREE)
			continue;//跳出不执行接下来的 直接做j++
		//在（i，j）处放置皇后
		row[i] = j;
		col[j] = dpos[i + j] = dneg[i - j + (N - 1)] = NOT_FREE;

		recursive(i + 1);

		//拿掉在（i，j）处摆放的皇后
		row[i] = col[j] = dpos[i + j] = dneg[i - j + (N - 1)] = FREE;
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
	cout << "输入需要摆放的皇后个数：" << endl;
	initialize();
	int k1;
	cin >> k1;
	cout << "输入这些皇后的位置：" << endl;
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
	cout << "输出棋盘的布局：" << endl;
	recursive(0);
	cout << "-------------------------↑ test1--------------------------" << endl;
	//-----------------------------------------------------------↑ test	1--------------------------------------------------------
	cout << "输入需要摆放的皇后个数：" << endl;
	initialize();
	int k2;
	cin >> k2;
	cout << "输入这些皇后的位置：" << endl;
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
	cout << "输出棋盘的布局：" << endl;
	recursive(0);
	cout << "-------------------------↑ test2--------------------------" << endl;
	//-----------------------------------------------------------↑ test	2--------------------------------------------------------
	cout << "输入需要摆放的皇后个数：" << endl;
	initialize();
	int k3;
	cin >> k3;
	cout << "输入这些皇后的位置：" << endl;
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
	cout << "输出棋盘的布局：" << endl;
	recursive(0);
	cout << "-------------------------↑ test3--------------------------" << endl;
	//-----------------------------------------------------------↑ test	3--------------------------------------------------------

	ShowTime();
	return 0;
}