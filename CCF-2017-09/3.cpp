#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string get_new_data(string data,string key){
	stack<char> s;
	int start = data.find(key);
	start = data.find(':',start) + 1;
	int i = start;
	while(!((data[i] == ',' && s.size() == 0) || (data[i] == '}' && s.size() == 0))){
		if(data[i] == '{')
			s.push('{');
		else if(data[i] == '}')
			s.pop();
		i++;
	}
	string temp = data.substr(start,i - start);
	return temp;
}

int main(){
	int n,m;
	string line,data,temp,key,value;
	cin >> n >> m;
	getline(cin,line);
	for(int i = 0;i < n;i++){
		getline(cin,line);
		data += line;
	}
	string search;
	int index,index_1;
	vector<string> sea_list;
	for(int k = 0;k < m;k++){
		cin >> search;
		auto iter = search.begin();
		while(iter != search.end()){
			if(*iter == '\\' || *iter == '\"'){
				iter = search.insert(iter,'\\');
				iter += 2;
			}
			else
				iter++;
		}
		sea_list.clear();
		while(search.find('.') != string::npos){
			index = search.find('.');
			key = search.substr(0,index);
			search = search.substr(index + 1);
			sea_list.push_back(key);
		}
		sea_list.push_back(search);
		temp = data;
		bool result = false;
		for(int i = 0;i < sea_list.size();i++){
			search = sea_list[i];
			if(temp.find(search) == string::npos){
				cout << "NOTEXIST" << endl;
				result = true;
				break;
			}
			else
				temp = get_new_data(temp,search);
		}
		if(!result){
			if(temp.find('{') == string::npos){      //ËµÃ÷ÊÇ×Ö·û´® 
				cout << "STRING ";
				index = temp.find('\"') + 1;
				for(int i = 0;i < temp.size();i++){
					if(temp[i] == '\"')
						index_1 = i;
				}
				temp = temp.substr(index,index_1 - index);
				auto iter_1 = temp.begin();
				while(iter_1 != temp.end()){
					if(*iter_1 == '\\' && (*(iter_1 + 1) == '\"' || *(iter_1 + 1) == '\\')){
						iter_1 = temp.erase(iter_1);
						iter_1++;
					}
					else
						iter_1++;
				}
				cout << temp << endl;
			}
			else
				cout << "OBJECT" << endl;
		}
	}
	return 0;
}
