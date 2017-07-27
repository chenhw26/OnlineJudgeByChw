#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Tree{
public:
	struct node{
		node(bool d = false, node *l = NULL, node *r = NULL): def(d), left(l), right(r){}
		bool def;
		int val;
		node *left, *right;
	};

	Tree(): root(NULL), cmpl(true){}

	~Tree(){
		del(root);
	}

	void del(node *p){
		if(p){
			del(p -> left);
			del(p -> right);
			delete p;
		}
	}

	void insert(int v, const string &pos){
		int l = pos.length();
		node **p = &root;
		for(int i = 0; i < l; ++i){
			if(!*p) *p = new node();
			if(pos[i] == 'L') p = &((*p) -> left);
			else if(pos[i] == 'R') p = &((*p) -> right);
		}
		if(!*p) *p = new node();
		if(!((*p) -> def)){
			(*p) -> val = v;
			(*p) -> def = true;
		}
		else cmpl = false;
	}

	void print(){
		if(!cmpl){
			cout << "not complete" << endl;
			return;
		}
		queue<int> ans;
		queue<node*> BFS;
		BFS.push(root);
		while(!BFS.empty()){
			node *p = BFS.front(); BFS.pop();
			if(p -> left) BFS.push(p -> left);
			if(p -> right) BFS.push(p -> right);
			if(!p -> def){
				cout << "not complete" << endl;
				return;
			}
			ans.push(p -> val);
		}
		while(!ans.empty()){
			cout << ans.front() << (ans.size() == 1? '\n': ' ');
			ans.pop();
		}
	}

	node *root;
	bool cmpl;
};

int main(){
	string s;
	while(cin >> s){
		Tree t;
		int cpos = s.find(',');
		t.insert(stoi(s.substr(1, cpos - 1)), s.substr(cpos + 1, s.length() - cpos - 2));
		while(cin >> s, s != "()"){
			cpos = s.find(',');
			t.insert(stoi(s.substr(1, cpos - 1)), s.substr(cpos + 1, s.length() - cpos - 2));
		}
		t.print();
	}
	return 0;
}