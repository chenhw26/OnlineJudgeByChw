#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

class Map{
public:
	Map(const string &n , double t, double b, double l, double r): name(n), top(t), bottom(b), left(l), right(r){
		aera = (top - bottom) * (right - left);
		ratio = (top - bottom) / (right - left);
		centre_x = (left + right) / 2;
		centre_y = (top + bottom) / 2;
	}
	string name;
	double top, bottom, left, right;
	double aera, ratio, centre_x, centre_y;
	int dtlLvl;
	bool operator<(const Map &rhs) const{
		return aera < rhs.aera;
	}
};

inline bool equal(const double &a, const double &b){
	if(a - b < 10e-6 && b - a < 10e-6) return true;
	return false;
}

inline bool smaller(const double &a, const double &b){
	if(a - b < -10e-6) return true;
	return false;
}

inline double abso(const double &a){
	return a > 0? a: -a;
}

class MapLocal: public Map{
public:
	MapLocal(const Map &m, double _x, double _y): Map(m), x(_x), y(_y){
		centreDis = (x - centre_x) * (x - centre_x) + (y - centre_y) * (y - centre_y);
		lrDis = (x - right) * (x - right) + (y - bottom) * (y - bottom);
	}
	double x, y;
	double centreDis, lrDis;
	bool operator<(const MapLocal &rhs) const{
		if(!equal(aera, rhs.aera)) return aera < rhs.aera;
		else if(!equal(centreDis, rhs.centreDis)) return centreDis < rhs.centreDis;
		else if(!equal(ratio, rhs.ratio)) return abso(ratio - 0.75) < abso(rhs.ratio - 0.75);
		else if(!equal(lrDis, rhs.lrDis)) return lrDis < rhs.lrDis;
		else return left + right < rhs.left + right;
	}
};

inline bool contain(const Map &m, const double &x, const double &y){
	if(y > m.top || y < m.bottom) return false;
	if(x > m.right || x < m.left) return false;
	return true;
}

int main(){
	string name;
	double x1, x2, y1, y2;
	cin >> name;
	set<Map> allMap;
	list<Map> mapBuf;
	map<string, list<MapLocal> > allLocal;
	while(cin >> name, name != "LOCATIONS"){
		cin >> x1 >> y1 >> x2 >> y2;
		allMap.insert(Map(name, max(y1, y2), min(y1, y2), min(x1, x2), max(x1, x2)));
	}
	int rank = 0;
	double curAera = 999999999;
	set<Map>::reverse_iterator riter = allMap.rbegin();
	for(; riter != allMap.rend(); ++riter){
		if(smaller(riter -> aera, curAera)){
			Map t(*riter);
			t.dtlLvl = ++rank;
			mapBuf.push_back(t);
			curAera = riter -> aera;
		}
		else{
			Map t(*riter);
			t.dtlLvl = rank;
			mapBuf.push_back(t);
		}
	}
	while(cin >> name, name != "REQUESTS"){
		cin >> x1 >> y1;
		list<MapLocal> tmp;
		for(auto i: mapBuf)
			if(contain(i, x1, y1)) tmp.push_back(MapLocal(i, x1, y1));
		tmp.sort();
		allLocal[name] = tmp;
	}
	int reqdtlvl;
	while(cin >> name, name != "END"){
		cin >> reqdtlvl;
		cout << name << " at detail level " << reqdtlvl << ' ';
		if(!allLocal.count(name)) cout << "unknown location" << endl;
		else if(allLocal[name].empty()) cout << "no map contains that location" << endl;
		else{
			list<MapLocal>::iterator iter = allLocal[name].begin();
			for(; iter != allLocal[name].end(); ++iter)
				if(iter -> dtlLvl <= reqdtlvl) break;
			if(iter -> dtlLvl == reqdtlvl) cout << "using " << iter -> name << endl;
			else cout << "no map at that detail level; using " << allLocal[name].begin() -> name << endl;
		}
	}
	return 0;
}