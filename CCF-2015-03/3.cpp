#include <iostream>
#include <cstdio>
using namespace std;

int days_1[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int days_2[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

bool if_run(int x){
	if(x % 100 == 0){
		if(x % 400 == 0)
			return true;
		else
			return false;
	}
	else{
		if(x % 4 == 0)
			return true;
		else
			return false;
	}
}

int main(){
	int a,b,c,y1,y2;
	cin >> a >> b >> c >> y1 >> y2;
	//首先计算y1年a月1日是星期几
	int days = 0;
	for(int i = 1850;i < y1;i++){
		if(if_run(i))
			days += 366;
		else
			days += 365;
	}
	days %= 7;
	int init = ((2 + days)%7 == 0)?7:(2 + days)%7;
	days = 0;
	for(int i = 1;i < a;i++){
		if(if_run(y1))
			days += days_2[i - 1];
		else
			days += days_1[i - 1];
	}
	days %= 7;
	init = ((init + days)%7 == 0)?7:(init + days)%7;
	int month_days;
	days = 0;
	for(int i = y1;i <= y2;i++){
		if(i > y1){
			if(a > 2){
				if(if_run(i))
					init = ((init + 2)%7 == 0)?7:(init + 2)%7;
				else
					init = ((init + 1)%7 == 0)?7:(init + 1)%7;
			} 
			else{
				if(if_run(i - 1))
					init = ((init + 2)%7 == 0)?7:(init + 2)%7;
				else
					init = ((init + 1)%7 == 0)?7:(init + 1)%7;
			}
		}
		if(if_run(i)) month_days = days_2[a - 1];
		else month_days = days_1[a - 1];
		int interval = c - init;
		if(interval < 0)
			interval += 7;
		int start = 1 + interval;    //这个月的第一个星期b
		for(int j = 0;j < b - 1;j++)
			start += 7;
		if(start > month_days)
			printf("none\n");
		else
			printf("%d/%02d/%02d\n",i,a,start);
	}
	return 0;
}
