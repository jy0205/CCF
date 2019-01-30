#include <iostream>
#include <set>

using namespace std;

typedef struct{
	int x;
	int y;
}point;

struct myComp
{
	bool operator() (const point& p1, const point& p2) const {
		if(p1.x == p2.x && p1.y == p2.y)
			return false;
		else
			if(p1.x == p2.x)
				return p1.y < p2.y;
			else if(p1.y == p2.y)
				return p1.x < p2.x;
			else
				return p1.x < p2.x;
	}
};

int main(){
	int n,result = 0,x1,x2,y1,y2;
	set<point,myComp> area;
	point temp;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int len = x1;len < x2;len++){
			for(int wid = y1;wid < y2;wid++){
				temp.x = len;temp.y = wid;
				area.insert(temp);
			}
		}
	}
	cout << area.size() << endl;
	return 0;
} 
