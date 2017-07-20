#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <cctype>
using namespace std;

class Line{
public:
	Line() = default;
	Line(string &_ori, set<string> &w) :ori(_ori), wrds(w){}
	string ori;
	set<string> wrds;
};

string to_lower(const string &s){
	string ans(s);
	ans[0] = tolower(ans[0]);
	return ans;
}

bool has_wrd(const vector<Line> &psge, const string &w){
	for(auto line: psge)
		if(line.wrds.count(w)) return true;
	return false;
}

void print_psg(const vector<Line> &psge){
	for(auto line: psge)
		printf("%s\n", line.ori.c_str());
}

bool print_dash(bool *f, int i, int n){
	for(int j = i + 1; j < n; ++j)
		if(f[j]) return true;
	return false;
}

int main(){
	int n, m;
	cin >> n;
	vector<vector<Line> > data(n);
	cin.ignore();
	for(int i = 0; i < n; ++i){
		string l;
		while(getline(cin, l), l != "**********"){
			set<string> dic;
			int j = 0, k = 0;
			while(j < l.size() && k < l.size()){
				for(; j < l.size() && !isalpha(l[j]); ++j, ++k);
				for(; k < l.size() && isalpha(l[k]); ++k);
				if(j < k) dic.insert(to_lower(l.substr(j, k - j)));
				j = k;
			}
			data[i].push_back(Line(l, dic));
		}
	}
	cin >> m;
	cin.ignore();
	while(m--){
		string query;
		bool found[n][1000] = {0}, found_pasg[n] = {0};
		getline(cin, query);
		if(query.find(' ') == string::npos){
			for(int i = 0; i < n; ++i){
				int j = 0;
				for(auto line: data[i]){
					if(line.wrds.count(query)){
						found[i][j] = true;
						found_pasg[i] = true;
					}
					++j;	
				}
			}
			for(int i = 0; i < n; ++i){
				int j = 0;
				for(auto line: data[i]){
					if(found[i][j]) printf("%s\n", line.ori.c_str());
					++j;
				}
				if(found_pasg[i] && print_dash(found_pasg, i, n)) printf("---------\n");
			}
		}
		else if(isupper(query[0])){
			query = query.substr(4);
			for(int i = 0; i < n; ++i)
				if(!has_wrd(data[i], query)) found_pasg[i] = true;
			for(int i = 0; i < n; ++i){
				if(found_pasg[i]) print_psg(data[i]);
				if(found_pasg[i] && print_dash(found_pasg, i, n)) printf("---------\n");
			}	
		}
		else{
			string q1(query.substr(0, query.find(' ')));
			string q2(query.substr(query.rfind(' ') + 1));
			if(query[query.find(' ') + 1] == 'A'){
				for(int i = 0; i < n; ++i){	
					bool found_q1 = false, found_q2 = false;
					int j = 0;
					for(auto line: data[i]){
						if(line.wrds.count(q1)) {found_q1 = true; found[i][j] = true;}
						if(line.wrds.count(q2)) {found_q2 = true; found[i][j] = true;}
						++j;
					}
					if(found_q1 && found_q2) found_pasg[i] = true;
				}
				for(int i = 0; i < n; ++i){
					int j = 0;
					for(auto line: data[i]){
						if(found[i][j]) printf("%s\n", line.ori.c_str());
						++j;
					}
					if(found_pasg[i] && print_dash(found_pasg, i, n)) printf("---------\n");
				}
			}
			else if(query[query.find(' ') + 1] == 'O'){
				for(int i = 0; i < n; ++i){
					int j = 0;
					for(auto line: data[i]){
						if(line.wrds.count(q1) || line.wrds.count(q2)) {found[i][j] = true; found_pasg[i] = true;}
						++j;
					}
				}
				for(int i = 0; i < n; ++i){
					int j = 0;
					for(auto line: data[i]){
						if(found[i][j]) printf("%s\n", line.ori.c_str());
						++j;
					}
					if(found_pasg[i] && print_dash(found_pasg, i, n)) printf("---------\n");
				}				
			}
		}
		if(!print_dash(found_pasg, 0, n)) printf("Sorry, I found nothing.\n");
		printf("==========\n");
	}
	return 0;
}