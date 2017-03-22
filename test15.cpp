/*
ID: 20165227028 ������
PROG: 15.���ݷ�ʵ��0/1��������
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
		nowtime = time(NULL);//��ȡ��ǰʱ��
		struct tm *local;
		local = localtime(&nowtime);  //��ȡ��ǰϵͳʱ��  
		cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
	}
};

int n, c, bestp;//��Ʒ�ĸ���������������������ֵ
int p[10000], w[10000], x[10000], bestx[10000];//��Ʒ�ļ�ֵ����Ʒ��������x[i]�ݴ���Ʒ��ѡ�����,��Ʒ��ѡ�����

void Backtrack(int i, int cp, int cw)
{ //cw��ǰ������Ʒ������cp��ǰ������Ʒ��ֵ
	int j;
	if (i > n)//���ݽ���
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
			Backtrack(i + 1, cp, cw);//�ݹ�
			cw -= w[i] * x[i];
			cp -= p[i] * x[i];
		}
	}
}

int main()
{
	int i;
	bestp = 0;
	cout << "���뱳���������:" << endl;
	cin >> c;
	cout << "������Ʒ����:" << endl;
	cin >> n;
	cout << "����������Ʒ������:"<<endl;
	for (i = 1; i <= n; i++)
		cin >> w[i];
	cout << "����������Ʒ�ļ�ֵ:" << endl;
	for (i = 1; i <= n; i++)
		cin >> p[i];
	Backtrack(1, 0, 0);
	cout << "����ֵΪ��" <<bestp<< endl;
	cout <<"��ѡ�е���Ʒ������(0��ʾδѡ�У�1��ʾѡ��)" <<endl;
	for (i = 1; i <= n; i++)
		cout<< bestx[i]<<"\t";
	cout << endl;
	cout << "----------------------------�� test------------------------------" << endl;
	//-----------------------------------------------------------�� test  --------------------------------------------------------
	ShowTime st;
	st.Show();
	system("pause");
	return 0;
}