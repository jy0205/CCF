#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

vector<string> text;

void transfer_1(string &line){
	int index;
	while(line.find('_') != string::npos){
		index = line.find('_');
		line.erase(index,1);
		line.insert(index,"<em>");
		index = line.find('_');
		line.erase(index,1);
		line.insert(index,"</em>");
	}
}

void transfer_2(string &line){
	int index,index_1;
	string Text,link;
	string temp;
	while(line.find('[') != string::npos){
		temp.clear();
		index = line.find('[');
		index_1 = line.find(']');
		Text = line.substr(index + 1,index_1 - index - 1);
		index = line.find('(');
		index_1 = line.find(')');
		link = line.substr(index + 1,index_1 - index - 1);
		index = line.find('[');
		index_1 = line.find(')');
		line.erase(index,index_1 - index + 1);
		temp.append("<a href=\"");temp.append(link);temp.append("\">");
		temp.append(Text);temp.append("</a>");
		line.insert(index,temp);
	}
}

int main(){
	string line,newline,temp;
	while(getline(cin,line)){
		text.push_back(line);
	}
	int kind = 0;   //0´ú±í³õÊ¼×´Ì¬ 
	for(int i = 0;i < text.size();i++){
		line = text[i];
		newline.clear();
		if(line.size() == 0){
			if(kind == 2)
				cout << "</ul>" << endl;
			kind = 0;
		}
		else{
			if(line.find('#') != string::npos){
				int level = count(line.begin(),line.end(),'#');
				char num = '0'+level;
				newline.append("<h");newline.append(1,num);newline.append(">");
				int index = line.find_first_not_of("# ");
				newline.append(line.substr(index));
				newline.append("</h");newline.append(1,num);newline.append(">");
				kind = 1;
			}
			else if(line.find('*') != string::npos){
				if(kind == 0){
					cout << "<ul>" << endl;
					kind = 2;
				}
				newline.append("<li>");
				int index = line.find_first_not_of("* ");
				newline.append(line.substr(index));
				newline.append("</li>");
			}
			else{
				if(kind == 0){
					newline.append("<p>");
					kind = 3;
				}
				newline.append(line);
				if(i + 1 == text.size() || text[i + 1].size() == 0)
					newline.append("</p>");
			}
			transfer_1(newline);
			transfer_2(newline);
			cout << newline << endl;
		} 
	}
	if(kind == 2)
		 cout << "</ul>" << endl;
	return 0;
}
