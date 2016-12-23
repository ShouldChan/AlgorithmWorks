/*
ID: 20165227028 陈晓杰
PROG: 12.0/1背包问题
LANG: C++
*/
#include<iostream>
#include<cmath>
#include<vector>
#include<time.h>
using namespace std;

#define N 100  //宏定义算法中所有数据的个数最大值    

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

void PARTS(int p[N], int w[N], int F[N], int P[N], int W[N], int n, int x[N], int last)
{
	int maxp = P[last];
	int maxw = W[last];
	int l, h;
	int i;
	for (i = n - 1; i >= 1; i--)//这里判断x2--xn的值
	{
		h = F[i + 1] - 1;
		l = F[i];
		int flag = 0;
		for (int t = l; t <= h; t++)
		{
			if (maxp == P[t] && maxw == W[t])
			{
				x[i + 1] = 0;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			x[i + 1] = 1;
			maxp = maxp - p[i + 1];
			maxw = maxw - w[i + 1];
		}

	}
	if (maxp == P[1] && maxw == W[1])
		x[1] = 0;
	else
		x[1] = 1;

}
int DKNAP(int p[N], int w[N], int n, int M, int P[N], int W[N], int x[N])
{
	int pp, ww;
	int F[N];
	int l, h, u, i, j, next;
	int k;
	F[0] = 1;
	P[1] = W[1] = 0;
	l = h = 1;
	F[1] = next = 2;

	for (i = 1; i <= n; i++)
	{
		k = l;
		u = l;
		//	int sum=0;
		for (int r = l; r <= h; r++)
		{
			if (W[r] + w[i] <= M)
			{
				//sum=W[r]+w[i];
				u = r;
			}
		}

		for (j = l; j <= u; j++)
		{
			pp = P[j] + p[i];
			ww = W[j] + w[i];

			while (k <= h && W[k]<ww)
			{
				P[next] = P[k];
				W[next] = W[k];
				next++;
				k++;
			}

			if (k <= h && W[k] == ww)
			{
				if (P[k]>pp)
					pp = P[k];
				k++;
			}
			if (pp > P[next - 1])
			{
				P[next] = pp;
				W[next] = ww;
				next++;
			}
			while (k <= h && P[k] <= P[next - 1])
			{
				k++;
			}
		}

		while (k <= h)
		{
			P[next] = P[k];
			W[next] = W[k];
			next++;
			k++;
		}
		l = h + 1;
		h = next - 1;
		F[i + 1] = next;
	}

	PARTS(p, w, F, P, W, n, x, next - 1);
	return (next - 1);

}
int main()
{
	int p[N];//记录物品的效益
	int w[N];//记录物品的重量
	int P[N];
	int W[N];
	int M;
	int n;
	int x[N];

	cout << "Input:" << endl;
	cout << "请输入物品的个数和总重量：" << endl;
	cin >> n >> M;
	cout << "请输入效益数组：" << endl;
	int i;
	for (i = 1; i <= n; i++)
		cin >> p[i];//这里需要注意是从1开始存储
	cout << "请输入重量数组：" << endl;
	for (i = 1; i <= n; i++)
		cin >> w[i];//这里需要注意是从1开始存储

	cout << "Output:" << endl;
	int last = DKNAP(p, w, n, M, P, W, x);
	cout << "P数组为：" << endl;
	for (i = 1; i <= last; i++)
		cout << " "<<P[i]<<" ";
	cout << endl;
	cout << "W数组为：" << endl;
	for (i = 1; i <= last; i++)
		cout << " "<<W[i]<<" ";
	cout << endl;

	cout << "最优解的效益为:" << P[last] << endl;

	cout << "各物品是否被选中，1表示选中,0表示未选中" << endl;
	for (i = 1; i <= n; i++)
		cout << " x[" << i << "] ";
	cout << endl;
	for (i = 1; i <= n; i++)
		cout << "   " << x[i] << "  ";
	cout << endl;

	cout << "----------------------------↑ test------------------------------" << endl;
	//-----------------------------------------------------------↑ test  --------------------------------------------------------
	ShowTime st;
	st.Show();
	system("pause");
	return 0;
}