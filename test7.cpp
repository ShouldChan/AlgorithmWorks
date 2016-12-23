/*
ID: 20165227028 陈晓杰
PROG: 7.带有限期的作业排序算法
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

#define MAX 100
//终于用面向对象写了一把/shy
//带有限期的作业排序，假设每个作业都可在单位时间内完成，完成后获得一定的效益，求效益的最大值和作业顺序
class Job{
public:
	int no;//序号
	int tt;//期限
	double fit;//效益
};

class JobSort{
private:
	Job *jbs = new Job[MAX];
	bool *visited = new bool[MAX];//标志此时间是否已经被安排作业
	int *target = new int[MAX];//目标编号
	double maxfit = 0.0;//最大收益
	int n;//作业个数
public:
	void init(){
		int p;
		double w;
		cout << "输入作业的个数：" << endl;
		cin >> n;
		cout << "输入时间和效益：" << endl;
		for (int i = 1; i <= n; i++){
			jbs[i].no = i;
			cin >> p >> w;
			jbs[i].tt = p;
			jbs[i].fit = w;
		}
		maxfit = 0.0;
		//初始化把所有访问置为未访问
		for (int i = 1; i <= n; i++){
			visited[i] = false;
		}
		sort();
	}
	//直接选择排序
	void sort(){
		for (int i = 1; i < n; i++){
			for (int j = i + 1; j <= n; j++){
				if (jbs[i].fit < jbs[j].fit)
					swap(jbs[i], jbs[j]);
			}
		}
	}

	//算法主体 贪心法
	void js(){
		int cnt = 0;
		for (int i = 1; i <= n; ++i){
			if (!visited[jbs[i].tt]){
				visited[jbs[i].tt] = true;
				target[cnt++] = jbs[i].no;
				maxfit += jbs[i].fit;
			}
		}
		target[cnt] = -1;
	}

	void print(){
		cout << "最大效益的可行解是：";
		for (int i = 0; target[i] > 0; ++i){
			cout  << target[i] << " ";
		}
		cout << "最大效益值是：" << maxfit << endl;
	}
};

//Show time&designer
void ShowTime(){
	time_t nowtime;
	nowtime = time(NULL);//获取当前时间
	struct tm *local;
	local = localtime(&nowtime);  //获取当前系统时间  
	cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
}

int main(){
	JobSort jb1,jb2,jb3;
	jb1.init();
	jb1.js();
	jb1.print();
	cout << "-------------------------↑ test1--------------------------" << endl;
	//-----------------------------------------------------------↑ test	1--------------------------------------------------------
	jb2.init();
	jb2.js();
	jb2.print();
	cout << "-------------------------↑ test2--------------------------" << endl;
	//-----------------------------------------------------------↑ test	2--------------------------------------------------------
	jb3.init();
	jb3.js();
	jb3.print();
	cout << "-------------------------↑ test3--------------------------" << endl;
	//-----------------------------------------------------------↑ test	3--------------------------------------------------------
	ShowTime();
	return 0;
}