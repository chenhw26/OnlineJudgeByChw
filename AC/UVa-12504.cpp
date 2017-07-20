#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;

void bulidDic(const string &strDic, map<string, string> &dic){
	string key, value;
	int i = 0, j = 0;
	while(strDic[i] != '}'){
		++i; ++j;
		for(; strDic[i] != ':' && strDic[i] != '}'; ++i);
		if(strDic[i] == '}') break;
		key = strDic.substr(j, i - j);
		++i; j = i;
		for(; strDic[i] != ',' && strDic[i] != '}'; ++i);
		value = strDic.substr(j, i - j);
		dic[key] = value;
		j = i;
	}
}

void printKey(const set<string> &key, const char symbol){
	if(!key.empty()){
		cout << symbol;
		for(set<string>::iterator i = key.begin(); i != key.end(); ++i)
			cout << *i << (i == (--key.end())? '\n': ',');
	}	
}

int main(){
	int n;
	cin >> n; cin.ignore();
	while(n--){
		set<string> newKey, delKey, modifyKey;
		map<string, string> oriDic, newDic;
		string dic;
		getline(cin, dic);
		bulidDic(dic, oriDic);
		getline(cin, dic);
		bulidDic(dic, newDic);
		for(auto k: oriDic){
			if(!newDic.count(k.first)) delKey.insert(k.first);
			else if(newDic[k.first] != k.second) modifyKey.insert(k.first);
		}
		for(auto k: newDic)
			if(!oriDic.count(k.first)) newKey.insert(k.first);
		printKey(newKey, '+');
		printKey(delKey, '-');
		printKey(modifyKey, '*');
		if(newKey.empty() && delKey.empty() && modifyKey.empty())
			cout << "No changes" << endl;
		cout << endl;
	}
	return 0;
}