/*
ID: 20165227028 陈晓杰
PROG: 16.分枝限界法实现0/1背包问题
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

#define min  0.00001

struct node //一个结点的各个信息段标志
{
	int count;      //结点生成序号
	int parent;     //父结点
	int level;      //结点所在树中的层
	int cu;         //结点处背包的剩余容量
	int pe;         //已经装入物品的效益和
	int tag;        //用来标记xi的值，放入为1未放为0
	double ub;      //结点的成本估价
	bool flag;      //结点是否为活结点
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
	cout << "请输入物品总数(n): " << endl << endl;
	cin >> N;
	cout << "请输入背包总重量(M)：" << endl << endl;
	cin >> M;
	if ((NODE = new node[2 * (N + 1)]) == NULL)
		exit(1);
	if ((P = new int[N + 1]) == NULL)
		exit(1);
	if ((W = new int[N + 1]) == NULL)
		exit(1);

	cout << "请输入各物品的效益值(P)：" << endl << endl;
	for (i = 1; i <= N; i++)
		cin >> P[i];
	cout << "请输入各物品的重量值(W)：" << endl << endl;
	for (i = 1; i <= N; i++)
		cin >> W[i];
	LCKNAP(P, W, M, N);
	cout << "----------------------------↑ test------------------------------" << endl;
	//-----------------------------------------------------------↑ test  --------------------------------------------------------
	ShowTime st;
	st.Show();
}

//计算上下界
void  LUBOUND(int *p, int *w, int rw, int cp, int N, int k, double &LBB, double &UBB)
{
	int c, i, j;
	LBB = cp; c = rw;
	for (i = k; i <= N; i++)
	{
		if (c<w[i])//该结点物体的重量大于背包的剩余容量，则只能放一部分进去
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
		c = c - w[i];	LBB += p[i];//该结点重量小于背包剩余重量，物体放进背包同时修改背包剩余容量
	}
	UBB = LBB;
}

//生成一个新结点并加到活结点表中
void  NEWNODE(int &num, int par, int lev, int t, int cap, int prof, double ub)
{
	node I;
	I.parent = par;	I.level = lev;	I.tag = t;	I.cu = cap;
	I.pe = prof;		I.ub = ub;	I.flag = true;
	num++;
	I.count = num;
	COPY(NODE[num], I);//放到活结点表中
}
//结点复制
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
//取最大值
double  max(double a, double b)
{
	if (a >= b)	return a;// !!!"="的情况要考虑吗？？
	else	return b;
}

//活结点表中取最大UB值的结点
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
//输出函数
void FINISH(double L, node *ans, int N)
{
	int j, m;
	cout << "\n最优解的效益值为：" << L << endl;
	cout << "被放进背包中的物体情况为(从后向前)：" << endl;


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
//背包问题的LC分枝限界算法 
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
	L = LBB - min;//最大上届
	E->ub = UBB;//最大估价
	do
	{
		i = E->level;	cap = E->cu;	prof = E->pe;
		if (i == N + 1){		//解结点
			if (prof>L)
			{
				L = prof;
				*ans = *E;
				//E.flag=false;
			}
		}
		else
		{
			if (cap >= w[i])		//左儿子可行
				NEWNODE(num, E->count, i + 1, 1, cap - w[i], prof + p[i], E->ub);
			//看右儿子是否可行//
			LUBOUND(p, w, cap, prof, N, i + 1, LBB, UBB);
			if (UBB>L)		//右儿子会活
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

		if (k >= 2 * (N + 1))	return;//不再有活结点了，退出
		temp = LARGEST(num);//下一个E结点是UB值最大的结点

		E = &NODE[temp];
	} while (E->ub>L);

	FINISH(L, ans, N);

}