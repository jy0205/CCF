#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct data{
	int time;       //��򻹵�ʱ��
	int id;         //Կ�׵�id
	int flag;       //��ʾ�ǽ�Կ�׻��ǻ�Կ�� 
	data(int a,int b,int c){
		time = a;id = b;flag = c;
	}
	bool operator < (const data &u) const{
		if(u.time == time){
			if(u.flag == flag)
				return id < u.id;
			else
				return flag < u.flag;
		}
		else
			return time < u.time;
	}
};

int track[1005];

int main(){
	int N,K,w,s,c;
	list<data> l;
	cin >> N >> K;
	for(int i = 1;i <= N;i++)
		track[i] = i;
	for(int i = 0;i < K;i++){
		cin >> w >> s >> c;
		l.push_back(data(s,w,1));       //ȡԿ�� 
		l.push_back(data(s+c,w,0));     //��Կ�� 
	}
	l.sort();
	auto iter = l.begin();
	while(iter != l.end()){
		if(iter -> flag == 0){
			for(int i = 1;i <= N;i++){
				if(track[i] == 0){
					track[i] = iter -> id;
					break;
				}
			}
		}
		else{
			for(int i = 1;i <= N;i++){
				if(track[i] == iter -> id){
					track[i] = 0;
					break;
				}
			}
		}
		iter++;
	}	
	for(int i = 1;i <= N;i++)
		cout << track[i] << " ";
	cout << endl;
	return 0;
}

