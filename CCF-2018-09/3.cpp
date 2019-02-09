#include <iostream>
#include <string>
#include <vector> 
#include <cctype>
#include <set>
using namespace std;

struct element{
	string name;       //为了方便统一划分为小写 
	string id;
	int level;         //.的个数 
	int lineNum;       //所在行的号 
};

vector<element> doc;
vector<vector<string>> selecters;
vector<string> selecter;
set<int> ans;

string change_to_low(string name){
	for(int i = 0;i < name.size();i++)
		name[i] = tolower(name[i]);
	return name;
}

void search(int index,int start,int level){
	string name = selecter[index];
	for(int i = start;i < doc.size();i++){
		if(name.find('#') == string::npos){
			if(doc[i].name == name && doc[i].level > level){
				if(index != selecter.size() - 1)
					search(index + 1,i + 1,doc[i].level);
				else
					ans.insert(doc[i].lineNum);
			}
		}
		else{
			if(doc[i].id == name && doc[i].level > level){
				if(index != selecter.size() - 1)
					search(index + 1,i + 1,doc[i].level);
				else
					ans.insert(doc[i].lineNum);
			}
		}
	}
}

int main(){
	int n,m;
	string line;
	cin >> n >> m;
	getline(cin,line);
	int index;
	for(int i = 0;i < n;i++){
		element temp;
		getline(cin,line);
		temp.lineNum = i + 1;
		temp.level = line.find_first_not_of('.');
		line = line.substr(temp.level);
		if(line.find('#') == string::npos){
			temp.name = change_to_low(line);
			temp.id = "";
		}
		else{
			index = line.find('#');
			temp.name = change_to_low(line.substr(0,index - 1));
			temp.id = line.substr(index);
		}
		doc.push_back(temp);
	}
	for(int i = 0;i < m;i++){
		getline(cin,line);
		selecter.clear();
		while(line.find(' ') != string::npos){
			index = line.find(' ');
			string name = line.substr(0,index);
			selecter.push_back(name);
			line = line.substr(index + 1);
		}
		selecter.push_back(line);
		for(int j = 0;j < selecter.size();j++){
			if(selecter[j].find('#') == string::npos)
				selecter[j] = change_to_low(selecter[j]);
		}
		selecters.push_back(selecter);
	}
	for(int i = 0;i < m;i++){
		selecter = selecters[i];
		ans.clear();
		search(0,0,-1);
		cout << ans.size() << " ";
		auto iter = ans.begin();
		while(iter != ans.end()){
			cout << *iter << " ";
			iter++;
		}
		cout << endl;
	}
	return 0;
}
