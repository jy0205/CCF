#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

const int N = 5005;

struct record{
	int id;
	int kind;         //kind为1表示买,kind为2表示卖
	double price;
	int dealNum;
	bool effect; 
};

record rlist[5005];

int main(){
	string line,type,price,deal;
	int line_num = 0,space_index;
	while(getline(cin,line)){
		line_num++;
		rlist[line_num].id = line_num;
		rlist[line_num].effect = true;
		space_index = line.find(' ');
		type = line.substr(0,space_index);
		line = line.substr(space_index + 1);
		if(type[0] == 'c'){
			rlist[line_num].kind = 0;
			int line_index = stoi(line,0,10);
			rlist[line_num].dealNum = line_index;
		}
		else{
			if(type[0] == 'b') rlist[line_num].kind = 1;
			else rlist[line_num].kind = 2;
			space_index = line.find(' ');
			price =  line.substr(0,space_index);
			rlist[line_num].price = stod(price);
			line = line.substr(space_index + 1);
			rlist[line_num].dealNum = stoi(line,0,10);
		}
	}
	for(int i = 1;i <= line_num;i++){
		if(rlist[i].kind == 0){
			rlist[rlist[i].dealNum].effect = false;
		}
	}
	map<double,long long> buy_list,sale_list;
	set<double> price_list;
	for(int i = 1;i <= line_num;i++){
		if(rlist[i].effect){
			if(rlist[i].kind == 1){
				buy_list[rlist[i].price] += rlist[i].dealNum;
				price_list.insert(rlist[i].price);
			}
			else if(rlist[i].kind == 2){
				sale_list[rlist[i].price] += rlist[i].dealNum;
				price_list.insert(rlist[i].price);
			}
		}
	}
	auto iter = buy_list.begin();
	while(iter != buy_list.end()){
		auto e_iter = iter;
		e_iter++;
		while(e_iter != buy_list.end()){
			iter -> second += e_iter -> second; 
			e_iter++;
		}
		iter++;
	}
	auto iter_1 = sale_list.end();
	iter_1--;
	while(iter_1 != sale_list.begin()){
		auto e_iter = iter_1;
		e_iter--;
		while(e_iter != sale_list.begin()){
			iter_1 -> second += e_iter -> second; 
			e_iter--;
		}
		iter_1 -> second += e_iter -> second; 
		iter_1--;
	}
	auto iter_2 = price_list.begin();
	double ans;
	long long max_deal = -1,a,b,deal_num;
	while(iter_2 != price_list.end()){
		auto loc = buy_list.lower_bound(*iter_2);
		if(loc == buy_list.end()){
			iter_2++;
			continue;
		}
		a = loc -> second;
		loc = sale_list.upper_bound(*iter_2);
		if(loc == sale_list.begin()){
			iter_2++;
			continue;
		}
		loc--;
		b = loc -> second;
		deal_num = (a < b)?a:b;
		if(deal_num >= max_deal){
			max_deal = deal_num;
			ans = *iter_2;
		}
		iter_2++;
	}
	printf("%.2f %lld",ans,max_deal);
	return 0;
}
