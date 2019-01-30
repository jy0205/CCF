#include <iostream>
#include <list>

using namespace std;

typedef struct{
	int id;
	int x1;
	int y1;
	int x2;
	int y2;
}point;

int main(){
	int N,M,x,y;
	list<point> windows;
	bool success;
	point temp;
	cin >> N >> M;
	for(int i = 0;i < N;i++){
		cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
		temp.id = i + 1;
		windows.push_back(temp);
	}
	windows.reverse();
	for(int i = 0;i < M;i++){
		success = false;
		cin >> x >> y;
		auto iter = windows.begin();
		while(iter != windows.end()){
			if(x >= (*iter).x1 && x <= (*iter).x2 && y >= (*iter).y1 && y <= (*iter).y2){
				cout << (*iter).id << endl;
				success = true;
				temp = *iter;
				windows.erase(iter);
				windows.push_front(temp);
				break;
			}
			iter++;
		}
		if(!success)
			cout << "IGNORED" << endl;
	}
	return 0;
}
