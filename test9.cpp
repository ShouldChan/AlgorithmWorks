/*
ID: 20165227028 ������
PROG: 9.Kruskal�㷨����С������
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

//DisjointSet��һ�����ʼ��ϣ�һ��Ԫ�ز���ͬʱ�����ڶ�����ϵļ��ϣ�
class DisjointSet{
public:
	vector<int> rank, p;
	DisjointSet() {}
	//��ʼ�����ʼ���
	DisjointSet(int size){
		rank.resize(size, 0);
		p.resize(size, 0);
		for (int i = 0; i < size; i++)
			makeSet(i);
	}

	//��һ��Ԫ�ط��뼯�ϵķ���
	void makeSet(int x){
		p[x] = x;
		rank[x] = 0;
	}

	//�Ƚ�������Ԫ���Ƿ���һ��������ǵĻ�����1����֮0
	bool same(int x, int y){
		return findSet(x) == findSet(y);
	}

	//�ҵ����Ԫ�����ڼ��ϵĵ�һ�������ڵ㡱Ԫ�أ���˼�����ҵ�����ӵĶӳ�
	int findSet(int x){
		if (x != p[x])
			p[x] = findSet(p[x]);
		return p[x];
	}

	//�ϲ�ָ��������Ԫ��
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
	//�Ƹ�ߵ�д�� T^T
	bool operator < (const Edge &e) const{
		return cost < e.cost;
	}
	/*bool bijiao(const Edge &e){
		return cost < e.cost;
		}*/
};

//Kruskal�㷨
int kruskal(int N, vector<Edge> edges){
	int totalCost = 0;
	sort(edges.begin(), edges.end());//Ҫ���<algorithm>ͷ�ļ�

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
	nowtime = time(NULL);//��ȡ��ǰʱ��
	struct tm *local;
	local = localtime(&nowtime);  //��ȡ��ǰϵͳʱ��  
	cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
}

int main(){
	cout << "����ͼ�Ķ������ͱ�����"<< endl;
	int N1, M1, cost1;
	int source1, target1;

	cin >> N1>> M1;
	cout << "����ñߵ���������ţ�������������ʾ����֮��ı�Ȩֵ����i�б�ʾ��i���ߣ���"<< endl;
	vector<Edge> edges1;
	for (int i = 0; i < M1; i++){
		cin >> source1 >> target1 >> cost1;
		edges1.push_back(Edge(source1, target1, cost1));
	}
	cout << "��С�������ĸ��ߵ�Ȩֵ֮�ͣ�"<<kruskal(N1,edges1)<<endl;

	cout << "-------------------------�� test1--------------------------" << endl;
	//-----------------------------------------------------------�� test	1--------------------------------------------------------

	cout << "����ͼ�Ķ������ͱ�����" << endl;
	int N2, M2, cost2;
	int source2, target2;

	cin >> N2 >> M2;
	cout << "����ñߵ���������ţ�������������ʾ����֮��ı�Ȩֵ����i�б�ʾ��i���ߣ���" << endl;
	vector<Edge> edges2;
	for (int i = 0; i < M2; i++){
		cin >> source2 >> target2 >> cost2;
		edges2.push_back(Edge(source2, target2, cost2));
	}
	cout << "��С�������ĸ��ߵ�Ȩֵ֮�ͣ�" << kruskal(N2, edges2) << endl;
	cout << "-------------------------�� test2--------------------------" << endl;
	//-----------------------------------------------------------�� test	2--------------------------------------------------------

	cout << "����ͼ�Ķ������ͱ�����" << endl;
	int N3, M3, cost3;
	int source3, target3;

	cin >> N3 >> M3;
	cout << "����ñߵ���������ţ�������������ʾ����֮��ı�Ȩֵ����i�б�ʾ��i���ߣ���" << endl;
	vector<Edge> edges3;
	for (int i = 0; i < M3; i++){
		cin >> source3 >> target3 >> cost3;
		edges3.push_back(Edge(source3, target3, cost3));
	}
	cout << "��С�������ĸ��ߵ�Ȩֵ֮�ͣ�" << kruskal(N3, edges3) << endl;
	cout << "-------------------------�� test3--------------------------" << endl;
	//-----------------------------------------------------------�� test	3--------------------------------------------------------

	ShowTime();
	return 0;
}