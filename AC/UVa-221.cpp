#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Building{
public:
	int id;
	double x, y, w, h;
	bool operator<(const Building &rhs){
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
	bool operator==(const Building &rhs) const{
		return x == rhs.x && y == rhs.y;
	}
};

bool cover(const Building &b, const double &x){
	if(b.x <= x && b.x + b.w >= x) return true;
	return false;
}

bool occlude(const Building &bdng, const Building &bd, const double &x){
	if(!cover(bd, x)) return false;
	if(bd.y < bdng.y && bd.h >= bdng.h) return true;
	return false;
}

bool visible(const Building &bdng, const Building *b, int n, const set<double> &x){
	set<double>::iterator i1 = x.begin(), i2 = ++x.begin();
	for(; i2 != x.end(); ++i1, ++i2){
		if(!cover(bdng, (*i1 + *i2) / 2)) continue;
		bool oc = false;
		for(int i = 0; i < n; ++i){
			if(occlude(bdng, b[i], (*i1 + *i2) / 2)){
				oc = true;
				break;
			}
		}
		if(oc) continue;
		return true;
	}
	return false;
}

int main(){
	int n, kase = 0;
	while(cin >> n, n){
		Building b[n];
		set<double> x;
		double d;
		for(int i = 0; i < n; ++i){
			cin >> b[i].x >> b[i].y >> b[i].w >> d >> b[i].h;
			b[i].id = i + 1;
			x.insert(b[i].x); x.insert(b[i].x + b[i].w);
		}
		sort(b, b + n);
		if(kase++) cout << endl;
		cout << "For map #" << kase << ", the visible buildings are numbered as follows:" << endl;
		bool flag = false;
		for(auto bdng: b)
			if(visible(bdng, b, n, x)){
				if(flag) cout << ' ';
				if(!flag) flag = true;
				cout << bdng.id;
			}
		cout << endl;
	}
	return 0;
}