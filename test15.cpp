/*
ID: 20165227028 陈晓杰
PROG: 15.回溯法实现0/1背包问题
LANG: C++
*/
#include<iostream>
#include<time.h>

using namespace std;

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

int n, c, bestp;//物品的个数，背包的容量，最大价值
int p[10000], w[10000], x[10000], bestx[10000];//物品的价值，物品的重量，x[i]暂存物品的选中情况,物品的选中情况

void Backtrack(int i, int cp, int cw)
{ //cw当前包内物品重量，cp当前包内物品价值
	int j;
	if (i > n)//回溯结束
	{
		if (cp > bestp)
		{
			bestp = cp;
			for (i = 0; i <= n; i++) bestx[i] = x[i];
		}
	}
	else
	for (j = 0; j <= 1; j++)
	{
		x[i] = j;
		if (cw + x[i] * w[i] <= c)
		{
			cw += w[i] * x[i];
			cp += p[i] * x[i];
			Backtrack(i + 1, cp, cw);//递归
			cw -= w[i] * x[i];
			cp -= p[i] * x[i];
		}
	}
}

int main()
{
	int i;
	bestp = 0;
	cout << "输入背包最大容量:" << endl;
	cin >> c;
	cout << "输入物品个数:" << endl;
	cin >> n;
	cout << "依次输入物品的重量:"<<endl;
	for (i = 1; i <= n; i++)
		cin >> w[i];
	cout << "依次输入物品的价值:" << endl;
	for (i = 1; i <= n; i++)
		cin >> p[i];
	Backtrack(1, 0, 0);
	cout << "最大价值为：" <<bestp<< endl;
	cout <<"被选中的物品依次是(0表示未选中，1表示选中)" <<endl;
	for (i = 1; i <= n; i++)
		cout<< bestx[i]<<"\t";
	cout << endl;
	cout << "----------------------------↑ test------------------------------" << endl;
	//-----------------------------------------------------------↑ test  --------------------------------------------------------
	ShowTime st;
	st.Show();
	system("pause");
	return 0;
}