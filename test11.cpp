/*
ID: 20165227028 ������
PROG: 11.���Ŷ��ּ�����
LANG: C++
*/
#include<iostream>
#include<vector>
#include<time.h>

using namespace std;
#define N 20  //��ĸ�������

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
	cout << "�������ĸ�����" ;
	cin >> n;

	int P[N + 1];
	int Q[N + 1];
	int C[N + 1][N + 1];
	int W[N + 1][N + 1];
	int R[N + 1][N + 1];

	int i, j;
	cout << "������P���飺" << endl;
	for (i = 1; i <= n; i++)
		cin >> P[i];
	cout << "������Q���飺" << endl;
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
	int Position[N + 1][4];//�������ÿ�����ĸ���㣬���֧���ҷ�֧��Ӧ�Ľ�㣬-1��ʾ�����ڡ�
	for (i = 1; i <= n; i++)//��������г�ʼ��
	{
		Position[i][0] = i;
		for (j = 1; j <= 3; j++)
			Position[i][j] = -1;
	}
	//���õݹ�ķ���
	fun(R, Position, n, 0, n);

	cout << "Output:" << endl; 
	cout <<"������Ĺ���(-1��ʾ������)"<<endl;
	cout << "\t���\t\t��\t\t����\t\t�Һ���" << endl;
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			cout << "\t" << Position[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "----------------------------�� test------------------------------" << endl;
	//-----------------------------------------------------------�� test  --------------------------------------------------------

	ShowTime st;
	st.Show();
	system("pause");
	return 0;

}

