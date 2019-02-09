#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

vector<string> role_name;
vector<vector<string>> roles;
vector<vector<string>> https;

vector<string> deal_str(string line){
	vector<string> role;
	role.push_back("/");
	line = line.substr(1);
	while(line.size() != 0){
		if(line.find('/') == string::npos){
			role.push_back(line);
			line.clear();
		}
		else{
			int index = line.find('/');
			string para = line.substr(0,index);
			role.push_back(para);
			role.push_back("/");
			line = line.substr(index + 1);
		}
	}
	return role;
}

bool isint(string str){
	for(int i = 0;i < str.size();i++){
		if(isdigit(str[i]))
			continue;
		else
			return false;
	}
	return true;
}

bool match(int index,vector<string> role,vector<string> http){
	vector<string> para;
	int i;
	for(i = 0;i < http.size();i++){
		if(i > role.size() - 1)
			return false;
		if(role[i] == "<int>"){
			if(isint(http[i]))
				para.push_back(http[i]);
			else
				return false;
		}
		else if(role[i] == "<str>"){
			para.push_back(http[i]);
		}
		else if(role[i] == "<path>"){
			string path;
			for(int j = i;j < http.size();j++)
				path += http[j];
			para.push_back(path);
			i++;
			break;
		}
		else{
			if(role[i] == http[i])
				continue;
			else
				return false;
		}
	}
	if(i != role.size())
		return false;
	cout << role_name[index] << " ";
	for(int j = 0;j < para.size();j++){
		if(isint(para[j]))
			cout << stoi(para[j],0,10) << " ";
		else
			cout << para[j] << " ";
	}
	cout << endl;
	return true;
}

void deal(vector<string> http){
	for(int i = 0;i < roles.size();i++){
		vector<string> role = roles[i];
		if(match(i,role,http))
			return;
	}
	cout << "404" << endl;
}

int main(){
	int n,m;
	string line,name;
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> line >> name;
		role_name.push_back(name);
		roles.push_back(deal_str(line));
	}
	for(int i = 0;i < m;i++){
		cin >> line;
		https.push_back(deal_str(line));
	}
	for(int i = 0;i < m;i++)
		deal(https[i]);
	return 0;
}
