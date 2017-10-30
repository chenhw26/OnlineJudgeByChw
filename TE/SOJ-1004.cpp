#include <list>
#include <cstdio>
#include <vector>
using namespace std;

class Pipe{
public:
	Pipe(double _x1, double _y1, double _x2, double _y2){
		if(_x1 > _x2){
			x1 = _x2;
			y1 = _y2;
			x2 = _x1;
			y2 = _y1;
		} 
		else{
			x1 = _x1;
			y1 = _y1;
			x2 = _x2;
			y2 = _y2;
		}
	}
	double x1, y1, x2, y2;
};

bool same(const Pipe &p1, const Pipe &p2){
	double k1 = (p1.y1 - p1.y2) / (p1.x1 - p1.x2);
	double k2 = (p2.y1 - p2.y2) / (p2.x1 - p2.x2);
	if((k1 - k2) > 10e-6 || k1 - k2 < -10e-6) 
		return false;
	if(p1.x1 < p2.x1 + 10e-6){
		if(p1.x2 > p2.x1 - 10e-6)
			return true;
		else 
			return false;
	}
	else{
		if(p1.x1 < p2.x2 + 10e-6)
			return true;
		else
			return false;
	}
}

void merge(list<Pipe> &all, const Pipe &p){
	int max = -99999999, min = 99999999, y1, y2;
	list<Pipe>::iterator i = all.begin();
	for(; i != all.end();){
		if(same(*i, p)){
			if(i -> x1 < min){
				min = i -> x1;
				y1 = i -> y1;
			}
			if(i -> x2 > max){
				max = i -> x2;
				y2 = i -> y2;
			}
			i = all.erase(i);
		}
		else ++i;
	}
	/*cout << "all same pipes\n";
	for(auto p: samePipe)
		cout << p.x1 << ' ' << p.y1 << ' ' << p.x2 << ' ' << p.y2 << endl;
	cout << endl;*/
	if(p.x1 < min){
		min = p.x1;
		y1 = p.y1;
	}
	if(p.x2 > max){
		max = p.x2;
		y2 = p.y2;
	}
	all.push_back(Pipe(min, y1, max, y2));
}

int main(){
	int n;
	while(scanf("%d", &n), n){
		list<Pipe> all;
		for(int i = 0; i < n; ++i){
			double x1, x2, y1, y2;
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			merge(all, Pipe(x1, y1, x2, y2));
			/*for(auto p: all)
				cout << p.x1 << ' ' << p.y1 << ' ' << p.x2 << ' ' << p.y2 << endl;
			cout << endl;*/
		}
		printf("%d\n", all.size());
	}
	return 0;
}
