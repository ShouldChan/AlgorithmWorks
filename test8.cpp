/*
ID: 20165227028 陈晓杰
PROG: 8.Prim算法求最小生成树
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

static const int MAX = 100;
static const int INFTY = (1 << 21);//设定一个很大的值，这个我觉得随便输个数吧
//使用颜色来记录访问状态，white表示未访问过，gray表示访问过但权值不是最小的，black表示访问过的也是权值最小的
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];//M[][]是一个无向图的邻接矩阵 用二维数组来存储


//int prim(int (*M)[5],int n){
int prim(){
	int u, minv;
	int d[MAX];//d[]是用来记录顶点集合T与V-T集合的顶点的边中，权值最小的边的权值
	int p[MAX];//p[]最小生成树中的节点
	int color[MAX];//用于记录各顶点的访问状态
	
	//对我们的点集进行初始化
	for (int i = 0; i < n; i++){
		d[i] = INFTY;
		p[i] = -1;
		color[i] = WHITE;
	}
	d[0] = 0;

	while (1){
		minv = INFTY;
		u = -1;
		//寻找构成边的权值最小的点
		for (int i = 0; i < n; i++){
			if (minv>d[i] && color[i] != BLACK){//如果这个点的权值比我们的初始值小并且这个点未被访问过也未被选中过，就作为最小的点
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
	/*cout << " 最小生成树的点集如下：" << endl;
	for (int i = 0; i < n; i++){
		cout << p[i] << " ";
	}*/
	return sum;
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
	cout << "PS:边不存在时记为 -1" << endl;
	cout << "输入加权图G的顶点数：" << endl;
	cin >> n;

	cout << "输入"<<n<<"行邻接矩阵（每行后以回车结尾输入下一行）：" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int e;
			cin >> e;
			M[i][j] = (e == -1) ? INFTY : e;
		}
	}
	cout << "输出最小生成树的各边权值之和："<< endl;
	cout << prim()<<endl;

	//int M[][5]= { { -1, 2, 3, 1, -1 }, 
	//					{ 2, -1, -1, 4, -1 }, 
	//					{ 3, -1, -1, 1, 100 }, 
	//					{ 1, 4, 1, -1, 3 }, 
	//					{ -1, -1, 1, 3, -1 } };

	//cout << prim(M,5) << endl;

	cout << "-------------------------↑ test1--------------------------" << endl;
	//-----------------------------------------------------------↑ test	1--------------------------------------------------------
	cout << "输入加权图G的顶点数：" << endl;
	cin >> n;

	cout << "输入" << n << "行邻接矩阵（每行后以回车结尾输入下一行）：" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int e;
			cin >> e;
			M[i][j] = (e == -1) ? INFTY : e;
		}
	}
	cout << "输出最小生成树的各边权值之和：" << endl;
	cout << prim() << endl;
	cout << "-------------------------↑ test2--------------------------" << endl;
	//-----------------------------------------------------------↑ test	2--------------------------------------------------------

	cout << "输入加权图G的顶点数：" << endl;
	cin >> n;

	cout << "输入" << n << "行邻接矩阵（每行后以回车结尾输入下一行）：" << endl;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int e;
			cin >> e;
			M[i][j] = (e == -1) ? INFTY : e;
		}
	}
	cout << "输出最小生成树的各边权值之和：" << endl;
	cout << prim() << endl;
	cout << "-------------------------↑ test3--------------------------" << endl;
	//-----------------------------------------------------------↑ test	3--------------------------------------------------------

	ShowTime();
	return 0;
}