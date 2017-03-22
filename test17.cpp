/*
ID: 20165227028 陈晓杰
PROG: 17.计算DFN和L算法
LANG: C++
*/
#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

#define N 200

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

int num;
struct Stack{
	int a, b;
};

Stack S[N];
int COUNT = 0;

void ART(int u, int v, int arc[N][N], int DFN[N], int L[N], int n)
{
	DFN[u] = num;
	L[u] = num;
	num++;
	//int count = 0;

	int w;
	for (w = 1; w <= n; w++)
	{
		if (arc[u][w] == 1)
		{
			if ((v != w) && (DFN[w] < DFN[u]))
			{
				S[COUNT].a = u;
				S[COUNT].b = w;
				COUNT++;
			}
			if (DFN[w] == 0)
			{
				ART(w, u, arc, DFN, L, n);

				if (L[w] >= DFN[u])
				{
					int x, y;
					while (1)
					{
						COUNT--;
						x = S[COUNT].a;
						y = S[COUNT].b;
						if ((x == u && y == w) || (x == w && y == u))
							break;
					}
				}
				if (L[u] > L[w])
					L[u] = L[w];
			}
			else if (w != v){
				if (DFN[w] < L[u])
					L[u] = DFN[w];
			}
		}
	}
}

int main()
{
	int arc[N][N];
	int n, m;
	int i, j;

	cout << "输入图中顶点个数和边的条数： " << endl;
	cin >> n >> m;
	for (i = 1; i <= n; i++)
	for (j = 1; j <= n; j++)
		arc[i][j] = 0;
	cout << "输入各边：" << endl;

	int a, b;
	for (i = 0; i < m; i++)
	{
		cin >> a >> b;
		arc[a][b] = 1;
		arc[b][a] = 1;
	}

	int DFN[N], L[N];
	num = 1;

	for (i = 1; i <= n; i++)
	{
		DFN[i] = 0;
		L[i] = 0;
	}

	ART(1, 0, arc, DFN, L, n);

	cout << "DFN:" << endl;
	for (i = 1; i <= n; i++)
		cout << " " << DFN[i];
	cout << endl;

	cout << "L:" << endl;
	for (i = 1; i <= n; i++)
		cout << " " << L[i];
	cout << endl;

	cout << "----------------------------↑ test ------------------------------" << endl;
	//-----------------------------------------------------------↑ test  --------------------------------------------------------
	ShowTime st;
	st.Show();
	//system("pause");
	return 0;
}
