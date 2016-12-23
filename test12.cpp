/*
ID: 20165227028 ������
PROG: 12.0/1��������
LANG: C++
*/
#include<iostream>
#include<cmath>
#include<vector>
#include<time.h>
using namespace std;

#define N 100  //�궨���㷨���������ݵĸ������ֵ    

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

void PARTS(int p[N], int w[N], int F[N], int P[N], int W[N], int n, int x[N], int last)
{
	int maxp = P[last];
	int maxw = W[last];
	int l, h;
	int i;
	for (i = n - 1; i >= 1; i--)//�����ж�x2--xn��ֵ
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
	int p[N];//��¼��Ʒ��Ч��
	int w[N];//��¼��Ʒ������
	int P[N];
	int W[N];
	int M;
	int n;
	int x[N];

	cout << "Input:" << endl;
	cout << "��������Ʒ�ĸ�������������" << endl;
	cin >> n >> M;
	cout << "������Ч�����飺" << endl;
	int i;
	for (i = 1; i <= n; i++)
		cin >> p[i];//������Ҫע���Ǵ�1��ʼ�洢
	cout << "�������������飺" << endl;
	for (i = 1; i <= n; i++)
		cin >> w[i];//������Ҫע���Ǵ�1��ʼ�洢

	cout << "Output:" << endl;
	int last = DKNAP(p, w, n, M, P, W, x);
	cout << "P����Ϊ��" << endl;
	for (i = 1; i <= last; i++)
		cout << " "<<P[i]<<" ";
	cout << endl;
	cout << "W����Ϊ��" << endl;
	for (i = 1; i <= last; i++)
		cout << " "<<W[i]<<" ";
	cout << endl;

	cout << "���Ž��Ч��Ϊ:" << P[last] << endl;

	cout << "����Ʒ�Ƿ�ѡ�У�1��ʾѡ��,0��ʾδѡ��" << endl;
	for (i = 1; i <= n; i++)
		cout << " x[" << i << "] ";
	cout << endl;
	for (i = 1; i <= n; i++)
		cout << "   " << x[i] << "  ";
	cout << endl;

	cout << "----------------------------�� test------------------------------" << endl;
	//-----------------------------------------------------------�� test  --------------------------------------------------------
	ShowTime st;
	st.Show();
	system("pause");
	return 0;
}