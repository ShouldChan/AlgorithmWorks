/*
ID: 20165227028 陈晓杰
PROG: 11.最优二分检索树
LANG: C++
*/
#include<iostream>
#include<vector>
#include<time.h>

using namespace std;
#define N 20  //点的个数上限

//Show time&designer
class ShowTime{
public:
	void Show(){
		time_t nowtime;
		nowtime = time(NULL);//获取当前时间
		struct tm *local;
		local = localtime(&nowtime);  //获取当前系统时间  
		cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
	}
};

int  fun(int R[N + 1][N + 1], int Position[N + 1][4], int n, int i, int j)
{
	int root, leftchild, rightchild;
	if (i < j)
	{
		root = R[i][j];
		leftchild = fun(R, Position, n, i, root - 1);
		rightchild = fun(R, Position, n, root, j);
		if (leftchild != 0)
		{
			Position[root][2] = leftchild;
			Position[leftchild][1] = root;
		}
		if (rightchild != 0)
		{
			Position[root][3] = rightchild;
			Position[rightchild][1] = root;
		}
		return root;
	}
	return 0;
}

int main()
{
	int n;
	cout << "Input:" << endl;
	cout << "请输入点的个数：" ;
	cin >> n;

	int P[N + 1];
	int Q[N + 1];
	int C[N + 1][N + 1];
	int W[N + 1][N + 1];
	int R[N + 1][N + 1];

	int i, j;
	cout << "请输入P数组：" << endl;
	for (i = 1; i <= n; i++)
		cin >> P[i];
	cout << "请输入Q数组：" << endl;
	for (i = 0; i <= n; i++)
		cin >> Q[i];

	for (i = 0; i <= n; i++){
		for (j = 0; j <= n; j++)
			R[i][j] = 0;
	}
	for (i = 0; i <= n - 1; i++)
	{
		W[i][i] = Q[i];
		R[i][i] = 0;
		C[i][i] = 0;
		W[i][i + 1] = Q[i] + Q[i + 1] + P[i + 1];
		R[i][i + 1] = i + 1;
		C[i][i + 1] = Q[i] + Q[i + 1] + P[i + 1];
	}

	W[n][n] = Q[n];
	R[n][n] = 0;
	C[n][n] = 0;

	int m;
	int k;
	for (m = 2; m <= n; m++)
	{
		for (i = 0; i <= n - m; i++)
		{
			j = i + m;
			W[i][j] = W[i][j - 1] + P[j] + Q[j];

			int t = i + 1;
			int sum = C[i][t - 1] + C[t][j] + W[i][j];
			k = t;
			for (t = i + 1; t <= j; t++)
			{
				if (C[i][t - 1] + C[t][j] + W[i][j] < sum)
				{
					sum = C[i][t - 1] + C[t][j] + W[i][j];
					k = t;
				}
			}
			C[i][j] = W[i][j] + C[i][k - 1] + C[k][j];
			R[i][j] = k;
		}
	}
	int Position[N + 1][4];//存放树中每个结点的根结点，左分支，右分支对应的结点，-1表示不存在。
	for (i = 1; i <= n; i++)//对数组进行初始化
	{
		Position[i][0] = i;
		for (j = 1; j <= 3; j++)
			Position[i][j] = -1;
	}
	//采用递归的方法
	fun(R, Position, n, 0, n);

	cout << "Output:" << endl; 
	cout <<"输出树的构成(-1表示不存在)"<<endl;
	cout << "\t编号\t\t根\t\t左孩子\t\t右孩子" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			cout << "\t" << Position[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "----------------------------↑ test------------------------------" << endl;
	//-----------------------------------------------------------↑ test  --------------------------------------------------------

	ShowTime st;
	st.Show();
	system("pause");
	return 0;

}

