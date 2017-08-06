#include <iostream>
#include <string>
#include <list>
#include <stack>
using namespace std;
#define IT list<stack<string> >::iterator

bool hasThree(const IT &it, const IT &begin){
	IT tmp = it;
	for (int i = 0; i < 3; ++i, --tmp)
		if(tmp == begin) return false;
	return true;
}

IT getThree(const IT &it){
	IT tmp = it;
	--tmp; --tmp; --tmp;
	return tmp;
}

IT getLeft(const IT &it){
	IT tmp = it;
	return --tmp;
}

bool match(const IT &first, const IT &second){
	string c1(first -> top()), c2(second -> top());
	if(c1[0] == c2[0] || c1[1] == c2[1]) return true;
	return false;
}

bool move(IT &leave, list<stack<string> > &allPiles){
	IT tar = leave;
	while(1){
		if(hasThree(tar, allPiles.begin()) && match(getThree(tar), tar)) tar = getThree(tar);
		else if(tar != allPiles.begin() && match(getLeft(tar), tar)) tar = getLeft(tar);
		else break;
	}
	if(tar == leave) return false;
	else{
		tar -> push(leave -> top());
		leave -> pop();
		if(leave -> empty())
			allPiles.erase(leave);
		return true;
	}
}

int main(){
	string card;
	while(cin >> card, card[0] != '#'){
		list<stack<string> > allPiles;
		stack<string> t; t.push(card);
		allPiles.push_back(t);
		for (int i = 0; i < 51; ++i){
			cin >> card;
			stack<string> t; t.push(card);
			allPiles.push_back(t);
		}
		while(1){
			IT it = allPiles.begin();
			for (; it != allPiles.end(); ++it)
				if(move(it, allPiles)) break;
			if(it == allPiles.end()) break;
		}
		cout << allPiles.size() << " pile" << (allPiles.size() == 1? "": "s") << " remaining:";
		for (auto i: allPiles)
			cout << ' ' << i.size();
		cout << endl;
	}
	return 0;
}