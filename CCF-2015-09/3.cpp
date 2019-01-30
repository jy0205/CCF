#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> Template;
map<string,string> var_list;

int main(){
	int m,n,space_index,quotation_index,left_sign_index,right_sign_index;
	string line,newline,var_name,value;
	cin >> m >> n;
	getline(cin,line);   //过滤掉换行符 
	for(int i = 0;i < m;i++){
		getline(cin,line);
		Template.push_back(line);
	}
	for(int i = 0;i < n;i++){
		getline(cin,line);
		space_index = line.find(' ');
		var_name = line.substr(0,space_index);
		line = line.substr(space_index + 2);
		quotation_index = line.find('\"');
		value = line.substr(0,quotation_index);
		var_list.insert(make_pair(var_name,value));
	}
	for(int i = 0;i < m;i++){
		if(Template[i].find("{{") != string::npos){  //说明需要替换 
			line = Template[i];
			newline.clear();
			while(line.find("{{") != string::npos){
				left_sign_index = line.find("{{");
				newline.append(line.substr(0,left_sign_index));
				line = line.substr(left_sign_index + 3);
				
				right_sign_index = line.find("}}");
				var_name = line.substr(0,right_sign_index - 1);
				line = line.substr(right_sign_index + 2);
				if(var_list.find(var_name) != var_list.end()){
					newline.append(var_list[var_name]);
				}
			}
			newline.append(line);
			Template[i] = newline;
		}
		cout << Template[i] << endl;
	}
	return 0;
} 
