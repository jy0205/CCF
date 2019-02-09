#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

vector<string> path;

int main(){
	int p;
	string line,templine,dir,now_dir;
	cin >> p;
	cin >> templine;
	getline(cin,line);
	now_dir = templine;
	for(int i = 0;i < p;i++){
		getline(cin,line);
		path.push_back(line);
	}
	list<string> now_path,the_path;
	now_path.push_back("/");   //表示根目录 
	int index;
	while(templine.find('/') != string::npos){
		index = templine.find('/');
		templine = templine.substr(index + 1);
		
		if(templine.find('/') != string::npos)
			index = templine.find('/');
		else
			index = templine.size();
		dir = templine.substr(0,index);
		if(dir.size() != 0)
			now_path.push_back(dir);
		templine = templine.substr(index);
	}
	
	//去掉多余的斜杠 
	for(int i = 0;i < p;i++){
		auto iter = path[i].begin();
		while(iter != path[i].end()){
			if(*iter == '/'){
				auto iter_1 = iter + 1;
				while(iter_1 != path[i].end() && *iter_1 == '/')
					iter_1 = path[i].erase(iter_1);
			}
			iter++;
		}
	}
	//将字符串路径化为链表形式 
	list<list<string>> new_path;
	for(int i = 0;i < p;i++){
		the_path.clear();
		if(path[i].size() == 0)
			the_path.push_back("#");
		else{
			if(path[i][0] == '.'){       //说明是根目录开始的 
				if(path[i].size() > 1 && path[i][1] == '.')
					the_path.push_back("..");
				else
					the_path.push_back(".");
			}
			else{
				the_path.push_back("/");
			}
		}
		while(path[i].find('/') != string::npos){
			index = path[i].find('/');
			path[i] = path[i].substr(index + 1);
			if(path[i].find('/') != string::npos)
				index = path[i].find('/');
			else
				index = path[i].size();
			dir = path[i].substr(0,index);
			if(dir.size() != 0)
				the_path.push_back(dir);
			path[i] = path[i].substr(index);
		}
		new_path.push_back(the_path);
	}
	/*
	while(iter != new_path.end()){
		the_path = *iter;
		//cout << the_path.size();
		auto iter_1 = the_path.begin();
		while(iter_1 != the_path.end()){
			cout << *iter_1;
			iter_1++;
		}
		cout << endl;
		iter++;
	}
	*/
	auto iter = new_path.begin();
	list<string> print;
	while(iter != new_path.end()){
		the_path = *iter;
		print.clear();
		if(the_path.front() == "/")
			print.push_back("/");
		else if(the_path.front() == "."){
			auto iter_2 = now_path.begin();
			while(iter_2 != now_path.end()){
				print.push_back(*iter_2);
				iter_2++;
			}
		}
		else if(the_path.front() == ".."){
			auto iter_2 = now_path.begin();
			while(iter_2 != now_path.end()){
				print.push_back(*iter_2);
				iter_2++;
			}
			if(print.back() != "/")
				print.pop_back();
		}
		if(the_path.front() == "#"){
			print = now_path;
		}
		else{
			auto iter_1 = the_path.begin();
			iter_1++;
			while(iter_1 != the_path.end()){
				if(*iter_1 == ".")
					dir.clear();
				else if(*iter_1 == ".."){
					if(print.back() != "/")
						print.pop_back();
				}
				else
					print.push_back(*iter_1);	
				iter_1++;
			}
		}
		
		//cout << print.size();
		cout << "/";
		auto iter_2 = print.begin();
		iter_2++;
		while(iter_2 != print.end()){
			cout << *iter_2;
			auto temp = iter_2;
			temp++;
			if(temp != print.end())
				cout << "/";
			iter_2++;
		}
		cout << endl;
		iter++;
	}
	return 0;
}
