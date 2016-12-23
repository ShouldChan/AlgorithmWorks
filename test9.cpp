/*
ID: 20165227028 陈晓杰
PROG: 9.Kruskal算法求最小生成树
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 10000
#define INFTY (1<<29)

//DisjointSet是一个互质集合（一个元素不能同时包含于多个集合的集合）
class DisjointSet{
public:
	vector<int> rank, p;
	DisjointSet() {}
	//初始化互质集合
	DisjointSet(int size){
		rank.resize(size, 0);
		p.resize(size, 0);
		for (int i = 0; i < size; i++)
			makeSet(i);
	}

	//将一个元素放入集合的方法
	void makeSet(int x){
		p[x] = x;
		rank[x] = 0;
	}

	//比较这两个元素是否在一个集合里，是的话返回1，反之0
	bool same(int x, int y){
		return findSet(x) == findSet(y);
	}

	//找到这个元素所在集合的第一个“根节点”元素，意思就是找到这个队的队长
	int findSet(int x){
		if (x != p[x])
			p[x] = findSet(p[x]);
		return p[x];
	}

	//合并指定的两个元素
	void  unite(int x, int y){
		link(findSet(x), findSet(y));
	}

	void link(int x, int y){
		if (rank[x] > rank[y])
			p[y] = x;
		else{
			p[x] = y;
			if (rank[x] == rank[y])
				rank[y]++;
		}
	}
};

class Edge{
public:
	int source, target, cost;
	Edge(int source = 0, int target = 0, int cost = 0) :source(source), target(target), cost(cost){}
	//逼格高的写法 T^T
	bool operator < (const Edge &e) const{
		return cost < e.cost;
	}
	/*bool bijiao(const Edge &e){
		return cost < e.cost;
		}*/
};

//Kruskal算法
int kruskal(int N, vector<Edge> edges){
	int totalCost = 0;
	sort(edges.begin(), edges.end());//要添加<algorithm>头文件

	DisjointSet dset = DisjointSet(N + 1);

	for (int i = 0; i < N; i++)
		dset.makeSet(i);

	int source, target;
	for (int i = 0; i < edges.size(); i++){
		Edge e = edges[i];
		if (!dset.same(e.source, e.target)){
			totalCost += e.cost;
			dset.unite(e.source, e.target);
		}
	}
	return totalCost;
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
	cout << "输入图的顶点数和边数："<< endl;
	int N1, M1, cost1;
	int source1, target1;

	cin >> N1>> M1;
	cout << "输入该边的两个结点编号，第三个参数表示他们之间的边权值（第i行表示第i条边）："<< endl;
	vector<Edge> edges1;
	for (int i = 0; i < M1; i++){
		cin >> source1 >> target1 >> cost1;
		edges1.push_back(Edge(source1, target1, cost1));
	}
	cout << "最小生成树的各边的权值之和："<<kruskal(N1,edges1)<<endl;

	cout << "-------------------------↑ test1--------------------------" << endl;
	//-----------------------------------------------------------↑ test	1--------------------------------------------------------

	cout << "输入图的顶点数和边数：" << endl;
	int N2, M2, cost2;
	int source2, target2;

	cin >> N2 >> M2;
	cout << "输入该边的两个结点编号，第三个参数表示他们之间的边权值（第i行表示第i条边）：" << endl;
	vector<Edge> edges2;
	for (int i = 0; i < M2; i++){
		cin >> source2 >> target2 >> cost2;
		edges2.push_back(Edge(source2, target2, cost2));
	}
	cout << "最小生成树的各边的权值之和：" << kruskal(N2, edges2) << endl;
	cout << "-------------------------↑ test2--------------------------" << endl;
	//-----------------------------------------------------------↑ test	2--------------------------------------------------------

	cout << "输入图的顶点数和边数：" << endl;
	int N3, M3, cost3;
	int source3, target3;

	cin >> N3 >> M3;
	cout << "输入该边的两个结点编号，第三个参数表示他们之间的边权值（第i行表示第i条边）：" << endl;
	vector<Edge> edges3;
	for (int i = 0; i < M3; i++){
		cin >> source3 >> target3 >> cost3;
		edges3.push_back(Edge(source3, target3, cost3));
	}
	cout << "最小生成树的各边的权值之和：" << kruskal(N3, edges3) << endl;
	cout << "-------------------------↑ test3--------------------------" << endl;
	//-----------------------------------------------------------↑ test	3--------------------------------------------------------

	ShowTime();
	return 0;
}