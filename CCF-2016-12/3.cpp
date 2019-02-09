#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct privi{
	string name;
	int level;
};

vector<privi> ples;
map<string,vector<privi>> roles;
map<string,map<string,int>> users;

int main(){
	int p,r,u,q;
	string pri;
	privi temp;
	cin >> p;
	for(int i = 0;i < p;i++){
		cin >> pri;
		if(pri.find(':') == string::npos){
			temp.name = pri;
			temp.level = -1;
		}
		else{
			int index = pri.find(':');
			string name = pri.substr(0,index);
			pri = pri.substr(index+1);
			int level = stoi(pri,0,10);
			temp.name = name;
			temp.level = level;
		}
		ples.push_back(temp);
	}
	cin >> r;
	string role_name;
	int role_num;
	vector<privi> lists;
	for(int i = 0;i < r;i++){
		cin >> role_name;
		cin >> role_num;
		lists.clear();
		for(int j = 0;j < role_num;j++){
			cin >> pri;
			if(pri.find(':') == string::npos){
				temp.name = pri;
				temp.level = -1;
			}
			else{
				int index = pri.find(':');
				string name = pri.substr(0,index);
				pri = pri.substr(index+1);
				int level = stoi(pri,0,10);
				temp.name = name;
				temp.level = level;
			}
			lists.push_back(temp);
		}
		roles.insert(make_pair(role_name,lists));
	}
	cin >> u;
	string user_name;
	map<string,int> user_pri;
	for(int i = 0;i < u;i++){
		cin >> user_name;
		cin >> role_num;
		user_pri.clear();
		for(int i = 0;i < role_num;i++){
			cin >> role_name;
			auto iter = roles[role_name].begin();
			while(iter != roles[role_name].end()){
				string pri_name = iter -> name;
				if(user_pri.find(pri_name) == user_pri.end())
					user_pri.insert(make_pair(pri_name,iter->level));
				else
					user_pri[pri_name] = max(user_pri[pri_name],iter->level);
				iter++;
			}
		}
		users.insert(make_pair(user_name,user_pri));
	}
	cin >> q;
	for(int i = 0;i < q;i++){
		cin >> user_name;
		cin >> pri;
		if(users.find(user_name) == users.end())
			cout << "false" << endl;
		else{
			user_pri = users[user_name];
			if(pri.find(':') != string::npos){
				int index = pri.find(':');
				string name = pri.substr(0,index);
				pri = pri.substr(index+1);
				int level = stoi(pri,0,10);
				if(user_pri.find(name) == user_pri.end())
					cout << "false" << endl;
				else{
					if(user_pri[name] >= level)
						cout << "true" << endl;
					else
						cout << "false" << endl;
				}
			}
			else{
				if(user_pri.find(pri) == user_pri.end())
					cout << "false" << endl;
				else{
					if(user_pri[pri] == -1)
						cout << "true" << endl;
					else
						cout << user_pri[pri] << endl;
				}
			}
		}
	}
	return 0;
}
