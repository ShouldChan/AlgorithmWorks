/*
ID: 20165227028 ������
PROG: 16.��֦�޽編ʵ��0/1��������
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

#define min  0.00001

struct node //һ�����ĸ�����Ϣ�α�־
{
	int count;      //����������
	int parent;     //�����
	int level;      //����������еĲ�
	int cu;         //��㴦������ʣ������
	int pe;         //�Ѿ�װ����Ʒ��Ч���
	int tag;        //�������xi��ֵ������Ϊ1δ��Ϊ0
	double ub;      //���ĳɱ�����
	bool flag;      //����Ƿ�Ϊ����
};
node *NODE;


void LCKNAP(int *p, int *w, int M, int N);
void LUBOUND(int *p, int *w, int rw, int cp, int N, int k, double &LBB, double &UBB);
void NEWNODE(int &num, int par, int lev, int t, int cap, int prof, double ub);
void COPY(node &C, node E);
void FINISH(double L, node *ans, int N);
double  max(double a, double b);
int LARGEST(int &num);

void main()

{
	int i, N, M;
	int *P, *W;
	cout << "��������Ʒ����(n): " << endl << endl;
	cin >> N;
	cout << "�����뱳��������(M)��" << endl << endl;
	cin >> M;
	if ((NODE = new node[2 * (N + 1)]) == NULL)
		exit(1);
	if ((P = new int[N + 1]) == NULL)
		exit(1);
	if ((W = new int[N + 1]) == NULL)
		exit(1);

	cout << "���������Ʒ��Ч��ֵ(P)��" << endl << endl;
	for (i = 1; i <= N; i++)
		cin >> P[i];
	cout << "���������Ʒ������ֵ(W)��" << endl << endl;
	for (i = 1; i <= N; i++)
		cin >> W[i];
	LCKNAP(P, W, M, N);
	cout << "----------------------------�� test------------------------------" << endl;
	//-----------------------------------------------------------�� test  --------------------------------------------------------
	ShowTime st;
	st.Show();
}

//�������½�
void  LUBOUND(int *p, int *w, int rw, int cp, int N, int k, double &LBB, double &UBB)
{
	int c, i, j;
	LBB = cp; c = rw;
	for (i = k; i <= N; i++)
	{
		if (c<w[i])//�ý��������������ڱ�����ʣ����������ֻ�ܷ�һ���ֽ�ȥ
		{
			UBB = LBB + c*p[i] / w[i];
			for (j = i + 1; j <= N; j++)
			{
				if (c >= w[j])
				{
					c = c - w[j];
					LBB = LBB + p[j];
				}
			}
			return;
		}
		c = c - w[i];	LBB += p[i];//�ý������С�ڱ���ʣ������������Ž�����ͬʱ�޸ı���ʣ������
	}
	UBB = LBB;
}

//����һ���½�㲢�ӵ��������
void  NEWNODE(int &num, int par, int lev, int t, int cap, int prof, double ub)
{
	node I;
	I.parent = par;	I.level = lev;	I.tag = t;	I.cu = cap;
	I.pe = prof;		I.ub = ub;	I.flag = true;
	num++;
	I.count = num;
	COPY(NODE[num], I);//�ŵ��������
}
//��㸴��
void COPY(node& C, node E)
{
	C.cu = E.cu;
	C.level = E.level;
	C.parent = E.parent;
	C.pe = E.pe;
	C.tag = E.tag;
	C.ub = E.ub;
	C.flag = E.flag;
	C.count = E.count;
}
//ȡ���ֵ
double  max(double a, double b)
{
	if (a >= b)	return a;// !!!"="�����Ҫ�����𣿣�
	else	return b;
}

//�������ȡ���UBֵ�Ľ��
int LARGEST(int &num)
{
	int i, count;
	double max;
	for (i = num; i>0; i--)
	{
		if (NODE[i].flag)
		{
			max = NODE[i].ub;
			count = i;
			break;
		}
	}


	for (i = i - 1; i>0; i--)
	{
		if (NODE[i].flag&&max<NODE[i].ub)
		{
			max = NODE[i].ub;
			count = i;
		}
	}

	return count;
}
//�������
void FINISH(double L, node *ans, int N)
{
	int j, m;
	cout << "\n���Ž��Ч��ֵΪ��" << L << endl;
	cout << "���Ž������е��������Ϊ(�Ӻ���ǰ)��" << endl;


	for (j = N; j >= 1; j--)
	{

		//if(ans->tag==1)	
		// cout<<" "<<j<<endl;
		cout << " " << ans->tag;
		m = ans->parent;
		ans = &NODE[m];
	}
	cout << endl;
}
//���������LC��֦�޽��㷨 
void LCKNAP(int *p, int *w, int M, int N)
{
	int i, k, num, cap, prof;
	double LBB, UBB;
	node *ans;
	double L;
	node *E;
	int temp;
	num = 0;
	if ((E = new node) == NULL)	return;
	if ((ans = new node) == NULL)	return;
	E->count = 0; E->parent = 0; E->level = 1; E->cu = M; E->pe = 0; E->flag = true;
	COPY(NODE[num], *E);

	LUBOUND(p, w, M, 0, N, 1, LBB, UBB);
	L = LBB - min;//����Ͻ�
	E->ub = UBB;//������
	do
	{
		i = E->level;	cap = E->cu;	prof = E->pe;
		if (i == N + 1){		//����
			if (prof>L)
			{
				L = prof;
				*ans = *E;
				//E.flag=false;
			}
		}
		else
		{
			if (cap >= w[i])		//����ӿ���
				NEWNODE(num, E->count, i + 1, 1, cap - w[i], prof + p[i], E->ub);
			//���Ҷ����Ƿ����//
			LUBOUND(p, w, cap, prof, N, i + 1, LBB, UBB);
			if (UBB>L)		//�Ҷ��ӻ��
			{
				NEWNODE(num, E->count, i + 1, 0, cap, prof, UBB);
				L = max(L, LBB - min);
			}
			NODE[E->count].flag = false;
		}
		for (k = 0; k<2 * (N + 1); k++)
		{
			if (NODE[k].flag)		{ break; }
		}

		if (k >= 2 * (N + 1))	return;//�����л����ˣ��˳�
		temp = LARGEST(num);//��һ��E�����UBֵ���Ľ��

		E = &NODE[temp];
	} while (E->ub>L);

	FINISH(L, ans, N);

}