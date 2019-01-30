#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
	int N,space_index,kind_index;
	char kind;
	string format,cmd,temp,para;
	vector<string> cmd_list;
	map<string,string> para_list;
	cin >> format;
	cin >> N;
	getline(cin,cmd);
	for(int i = 0;i < N;i++){
		getline(cin,cmd);
		cmd_list.push_back(cmd);
	}
	for(int i = 0;i < N;i++){
		para_list.clear();
		cout << "Case " << i + 1 << ":";
		cmd = cmd_list[i];
		while(cmd.find(' ') != string::npos){
			space_index = cmd.find(' ');
			cmd = cmd.substr(space_index + 1);
			if(cmd[0] == '-'){
				kind = cmd[1];
				if(format.find(kind) == string::npos)
					break;
				kind_index = format.find(kind);
				if(kind_index + 1 < format.size() && format[kind_index + 1] == ':'){  //带参数的 
					temp = "-";temp.append(1,kind);
					if(cmd.find(' ') == string::npos)
						break;
					space_index = cmd.find(' ');
					cmd = cmd.substr(space_index + 1);
					if(cmd.find(' ') == string::npos){      //说明到了结尾 
						para = cmd;
						para_list[temp] = para;
						break;
					}
					else{
						space_index =  cmd.find(' ');
						para = cmd.substr(0,space_index);
						cmd = cmd.substr(space_index);
						para_list[temp] = para;
					}
				}
				else{
					temp = "-";temp.append(1,kind);
					para_list[temp] = "###";
					cmd = cmd.substr(2);
				}
			}
			else
				break;
		}
		if(para_list.size() == 0)
			cout << " " << endl;
		else{
			auto iter = para_list.begin();
			while(iter != para_list.end()){
				cout << " " << iter -> first;
				if(iter -> second != "###")
					cout << " " << iter -> second;
				iter++;
			}
			cout << endl;
		}
	}
	return 0;
}
