#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct follow{
	int health;
	int attack;
	follow(int a,int b){
		health = a;attack = b;
	}
};

int main(){
	int n;
	int first = 30,second = 30;
	vector<follow> f_follow,s_follow;
	cin >> n;
	string kind;
	int turn = 1,pos,atk,health,attacker,defender;
	for(int i = 0;i < n;i++){
		cin >> kind;
		if(kind == "summon"){
			cin >> pos >> atk >> health;
			if(turn == 1){
				auto iter = f_follow.begin();
				while(--pos)
					iter++;
				f_follow.insert(iter,follow(health,atk));
			}
			else{
				auto iter = s_follow.begin();
				while(--pos)
					iter++;
				s_follow.insert(iter,follow(health,atk));
			}
		}
		else if(kind == "attack"){
			cin >> attacker >> defender;
			if(turn == 1){
				if(defender == 0){
					second -= f_follow[attacker - 1].attack;
				}
				else{
					f_follow[attacker - 1].health -= s_follow[defender - 1].attack;
					s_follow[defender - 1].health -= f_follow[attacker - 1].attack;
				}
			}
			else{
				if(defender == 0){
					first -= s_follow[attacker - 1].attack;
				}
				else{
					s_follow[attacker - 1].health -= f_follow[defender - 1].attack;
					f_follow[defender - 1].health -= s_follow[attacker - 1].attack;
				}
			}
			auto iter = f_follow.begin();
			while(iter != f_follow.end()){
				if(iter -> health <= 0)
					iter = f_follow.erase(iter);
				else
					iter++;
			}
			auto iter_1 = s_follow.begin();
			while(iter_1 != s_follow.end()){
				if(iter_1 -> health <= 0)
					iter_1 = s_follow.erase(iter_1);
				else
					iter_1++;
			}
		}
		else{
			turn = -turn;
		}
	}
	if(first <= 0)
		cout << -1 << endl;
	else if(second <= 0)
		cout << 1 << endl;
	else
		cout << 0 << endl;
	cout << first << endl;
	cout << f_follow.size() << " ";
	for(int i = 0;i < f_follow.size();i++)
		cout << f_follow[i].health << " ";
	cout << endl;
	cout << second << endl;
	cout << s_follow.size() << " ";
	for(int i = 0;i < s_follow.size();i++)
		cout << s_follow[i].health << " ";
	cout << endl;
	return 0;
}
