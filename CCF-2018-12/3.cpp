#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

void normal();
void sort_ip_list();
bool compare_ip(const string &s1,const string &s2);
void merge_ip_size();
string find_upper(string ip,int len);
bool ip_compare(const string &s1,const string &s2);
void merge_ip_same();
bool legal(string ip,int len);
bool ip_if_equal(const string &s1,const string &s2);
long long ip_to_num(string ip);

vector<string> ip_list;
int n;

int main(){
	string ip;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> ip;
		ip_list.push_back(ip);
	}
	normal(); 
	sort(ip_list.begin(),ip_list.end(),compare_ip);
	merge_ip_size();
	merge_ip_same();
	for(int i = 0;i < ip_list.size();i++)
		cout << ip_list[i] << endl;
	return 0;
}

bool legal(string ip,int len){
	string ip_binary,temp;
	int dot_index,num;
	if(len < 0)
		return false;
	else{
		for(int i = 0;i < 3;i++){
			dot_index = ip.find('.');
			temp = ip.substr(0,dot_index);
			ip = ip.substr(dot_index + 1);
			num = stoi(temp,0,10);
			bitset<8> numbit(num);
			ip_binary.append(numbit.to_string());
		}
		num = stoi(ip,0,10);
		bitset<8> numbit(num);
		ip_binary.append(numbit.to_string());
		for(int i = len;i < 32;i++)
			if(ip_binary[i] == '1')
				return false;
		return true;
	}
}

long long ip_to_num(string ip){
	string ip_binary,temp;
	int dot_index,num;
	long long result;
	for(int i = 0;i < 3;i++){
		dot_index = ip.find('.');
		temp = ip.substr(0,dot_index);
		ip = ip.substr(dot_index + 1);
		num = stoi(temp,0,10);
		bitset<8> numbit(num);
		ip_binary.append(numbit.to_string());
	}
	num = stoi(ip,0,10);
	bitset<8> numbit(num);
	ip_binary.append(numbit.to_string());
	result = stoll(ip_binary,0,2);
	return result;
}

void merge_ip_same(){
	string low_a,low_b,high_a,high_b,low_new_a,high_new_a;
	string ip_new_a;
	int len_a,len_b,len_index;
	auto iter = ip_list.begin();
	while(iter != ip_list.end()){
		if(iter + 1 != ip_list.end()){
			len_index = (*iter).find('/');
			len_a = stoi((*iter).substr(len_index + 1),0,10);
			low_a = (*iter).substr(0,len_index);
			high_a = find_upper(low_a,stoi((*iter).substr(len_index + 1),0,10));
			len_index = (*(iter + 1)).find('/');
			len_b = stoi((*(iter + 1)).substr(len_index + 1),0,10);
			low_b = (*(iter + 1)).substr(0,len_index);
			high_b = find_upper(low_b,stoi((*(iter + 1)).substr(len_index + 1),0,10));
			if(len_a == len_b){
				ip_new_a.clear();
				ip_new_a.append(low_a);
				if(legal(ip_new_a,len_a - 1)){
					low_new_a = ip_new_a;
					high_new_a = find_upper(low_new_a,len_a - 1);
					if(ip_compare(low_b,high_a) || ((long long)(ip_to_num(high_a) + 1) == (long long)(ip_to_num(low_b)))){
						if(ip_if_equal(low_new_a,low_a) && ip_if_equal(high_new_a,high_b)){
							iter = ip_list.erase(iter);   //删除a 
							iter = ip_list.erase(iter);   //删除b
							ip_new_a.append("/");ip_new_a.append(to_string(len_a - 1));
							iter = ip_list.insert(iter,ip_new_a);
							if(iter != ip_list.begin()){
								iter--;
							}
						}
						else
							iter++;
					}
					else
						iter++;
				}
				else
					iter++;
			}
			else
				iter++;
		}
		else
			iter++;
	}
}

string find_upper(string ip,int len){
	string ip_binary,temp,result;
	int dot_index,num;
	for(int i = 0;i < 3;i++){
		dot_index = ip.find('.');
		temp = ip.substr(0,dot_index);
		ip = ip.substr(dot_index + 1);
		num = stoi(temp,0,10);
		bitset<8> numbit(num);
		ip_binary.append(numbit.to_string());
	}
	num = stoi(ip,0,10);
	bitset<8> numbit(num);
	ip_binary.append(numbit.to_string());
	for(int i = len;i < 32;i++)
		ip_binary[i] = '1';
	
	result.clear();
	num = stoi(ip_binary.substr(0,8),0,2);
	result.append(to_string(num));result.append(".");
	
	num = stoi(ip_binary.substr(8,8),0,2);
	result.append(to_string(num));result.append(".");
	
	num = stoi(ip_binary.substr(16,8),0,2);
	result.append(to_string(num));result.append(".");
	
	num = stoi(ip_binary.substr(24,8),0,2);
	result.append(to_string(num));
	return result;
}

void merge_ip_size(){
	string low_a,low_b,high_a,high_b;
	int len_index;
	auto iter = ip_list.begin();
	while(iter != ip_list.end()){
		if(iter + 1 != ip_list.end()){
			len_index = (*iter).find('/');
			low_a = (*iter).substr(0,len_index);
			high_a = find_upper(low_a,stoi((*iter).substr(len_index + 1),0,10));
			len_index = (*(iter + 1)).find('/');
			low_b = (*(iter + 1)).substr(0,len_index);
			high_b = find_upper(low_b,stoi((*(iter + 1)).substr(len_index + 1),0,10));
			if(ip_compare(high_b,high_a) && ip_compare(low_a,low_b))
				ip_list.erase(iter + 1);
			else
				iter++;
		}
		else
			iter++;
	}
}

bool ip_compare(const string &s1,const string &s2){
	int dot_index;
	string string_1,string_2,temp_1,temp_2;
	temp_1 = s1;temp_2 = s2;
	
	for(int i = 0;i < 3;i++){
		dot_index = temp_1.find('.');
		string_1 = temp_1.substr(0,dot_index);
		temp_1 = temp_1.substr(dot_index + 1);
		
		dot_index = temp_2.find('.');
		string_2 = temp_2.substr(0,dot_index);
		temp_2 = temp_2.substr(dot_index + 1);
		if(string_1 != string_2)
			return stoi(string_1,0,10) <= stoi(string_2,0,10);
	}

	return stoi(temp_1,0,10) <= stoi(temp_2,0,10);
}

bool ip_if_equal(const string &s1,const string &s2){
	int dot_index;
	string string_1,string_2,temp_1,temp_2;
	temp_1 = s1;temp_2 = s2;
	
	for(int i = 0;i < 3;i++){
		dot_index = temp_1.find('.');
		string_1 = temp_1.substr(0,dot_index);
		temp_1 = temp_1.substr(dot_index + 1);
		
		dot_index = temp_2.find('.');
		string_2 = temp_2.substr(0,dot_index);
		temp_2 = temp_2.substr(dot_index + 1);
		if(string_1 != string_2)
			return false;
	}
	return stoi(temp_1,0,10) == stoi(temp_2,0,10);
}

bool compare_ip(const string &s1,const string &s2){
	int dot_index;
	string string_1,string_2,temp_1,temp_2;
	temp_1 = s1;temp_2 = s2;
	
	for(int i = 0;i < 3;i++){
		dot_index = temp_1.find('.');
		string_1 = temp_1.substr(0,dot_index);
		temp_1 = temp_1.substr(dot_index + 1);
		
		dot_index = temp_2.find('.');
		string_2 = temp_2.substr(0,dot_index);
		temp_2 = temp_2.substr(dot_index + 1);
		if(string_1 != string_2)
			return stoi(string_1,0,10) < stoi(string_2,0,10);
	}

	dot_index = temp_1.find('/');
	string_1 = temp_1.substr(0,dot_index);
	temp_1 = temp_1.substr(dot_index + 1);
	
	dot_index = temp_2.find('/');
	string_2 = temp_2.substr(0,dot_index);
	temp_2 = temp_2.substr(dot_index + 1);
	
	if(string_1 != string_2)
		return stoi(string_1,0,10) < stoi(string_2,0,10);
	else
		return stoi(temp_1,0,10) < stoi(temp_2,0,10);
}

void normal(){     //把前缀化成标准型 
	int dot_num;
	for(int i = 0;i < n;i++){
		dot_num = count(ip_list[i].begin(),ip_list[i].end(),'.');
		if(ip_list[i].find('/') == string::npos){    //省略长度型 
			switch(dot_num){
				case 0:{
					ip_list[i].append(".0.0.0/8");
					break;
				}
				case 1:{
					ip_list[i].append(".0.0/16");
					break;
				}
				case 2:{
					ip_list[i].append(".0/24");
					break;
				}
				case 3:{
					ip_list[i].append("/32");
					break;
				}
			}
		}
		else{
			if(dot_num == 3){
				continue;
			}
			else{
				int len_index = ip_list[i].find('/');
				string len = ip_list[i].substr(len_index);
				ip_list[i].erase(len_index);
				switch(dot_num){
					case 0:{
						ip_list[i].append(".0.0.0");
						ip_list[i].append(len);
						break;
					}
					case 1:{
						ip_list[i].append(".0.0");
						ip_list[i].append(len);
						break;
					}
					case 2:{
						ip_list[i].append(".0");
						ip_list[i].append(len);
						break;
					}
				}
			}
		}
	}
}
