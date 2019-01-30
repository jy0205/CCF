#include <iostream>
#include <string> 
#include <vector>
#include <cctype>

using namespace std;

int main(){
	string goal,temp;
	vector<string> origin,lower_string;
	int n,if_open;
	cin >> goal;
	cin >> if_open;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> temp;
		origin.push_back(temp);
		for(int j = 0;j < temp.size();j++)
			temp[j] = tolower(temp[j]);
		lower_string.push_back(temp);
	}
	if(if_open == 0){
		for(int i = 0;i < goal.size();i++)
			goal[i] = tolower(goal[i]);
		for(int i = 0;i < n;i++){
			if(lower_string[i].find(goal) != string::npos)
				cout << origin[i] << endl;
		}
	}
	else{
		for(int i = 0;i < n;i++){
			if(origin[i].find(goal) != string::npos)
				cout << origin[i] << endl;
		}
	}	
	return 0;
} 
