/*
ID: 20165227028 ������
PROG: 7.�������ڵ���ҵ�����㷨
LANG: C++
*/
#include<iostream>
#include<time.h>
#include<cmath>
#include<vector>
using namespace std;

#define MAX 100
//�������������д��һ��/shy
//�������ڵ���ҵ���򣬼���ÿ����ҵ�����ڵ�λʱ������ɣ���ɺ���һ����Ч�棬��Ч������ֵ����ҵ˳��
class Job{
public:
	int no;//���
	int tt;//����
	double fit;//Ч��
};

class JobSort{
private:
	Job *jbs = new Job[MAX];
	bool *visited = new bool[MAX];//��־��ʱ���Ƿ��Ѿ���������ҵ
	int *target = new int[MAX];//Ŀ����
	double maxfit = 0.0;//�������
	int n;//��ҵ����
public:
	void init(){
		int p;
		double w;
		cout << "������ҵ�ĸ�����" << endl;
		cin >> n;
		cout << "����ʱ���Ч�棺" << endl;
		for (int i = 1; i <= n; i++){
			jbs[i].no = i;
			cin >> p >> w;
			jbs[i].tt = p;
			jbs[i].fit = w;
		}
		maxfit = 0.0;
		//��ʼ�������з�����Ϊδ����
		for (int i = 1; i <= n; i++){
			visited[i] = false;
		}
		sort();
	}
	//ֱ��ѡ������
	void sort(){
		for (int i = 1; i < n; i++){
			for (int j = i + 1; j <= n; j++){
				if (jbs[i].fit < jbs[j].fit)
					swap(jbs[i], jbs[j]);
			}
		}
	}

	//�㷨���� ̰�ķ�
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
		cout << "���Ч��Ŀ��н��ǣ�";
		for (int i = 0; target[i] > 0; ++i){
			cout  << target[i] << " ";
		}
		cout << "���Ч��ֵ�ǣ�" << maxfit << endl;
	}
};

//Show time&designer
void ShowTime(){
	time_t nowtime;
	nowtime = time(NULL);//��ȡ��ǰʱ��
	struct tm *local;
	local = localtime(&nowtime);  //��ȡ��ǰϵͳʱ��  
	cout << asctime(local) << "\t\t\t" << "by ShouldChan" << endl;
}

int main(){
	JobSort jb1,jb2,jb3;
	jb1.init();
	jb1.js();
	jb1.print();
	cout << "-------------------------�� test1--------------------------" << endl;
	//-----------------------------------------------------------�� test	1--------------------------------------------------------
	jb2.init();
	jb2.js();
	jb2.print();
	cout << "-------------------------�� test2--------------------------" << endl;
	//-----------------------------------------------------------�� test	2--------------------------------------------------------
	jb3.init();
	jb3.js();
	jb3.print();
	cout << "-------------------------�� test3--------------------------" << endl;
	//-----------------------------------------------------------�� test	3--------------------------------------------------------
	ShowTime();
	return 0;
}