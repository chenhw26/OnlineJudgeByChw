#include <stdio.h>

int left[100001], right[100001];

void link(int l, int r){
	left[r] = l;
	right[l] = r;
}

int main(){
	int n, m, kase = 0;
	while(~scanf("%d%d", &n, &m)){
		int inv = 0, op;
		for(int i = 0; i < n; ++i) link(i, i + 1);
		link(n, 0);
		while(m--){
			scanf("%d", &op);
			if(op == 4){
				inv = !inv;
				continue;
			}
			int x, y;
			scanf("%d%d", &x, &y);
			int lx = left[x], ly = left[y], rx = right[x], ry = right[y];
			if(op == 3){
				if(right[x] == y){
					link(x, ry);
					link(y, x);
					link(lx, y);
				}
				else if(right[y] == x){
					link(y, rx);
					link(x, y);
					link(ly, x);					
				}
				else{
					link(lx, y);
					link(y, rx);
					link(ly, x);
					link(x, ry);
				}
				continue;
			}
			if(inv) op = 3 - op;
			if(op == 1){
				if(ly == x) continue;
				link(x, y);
				link(ly, x);
				link(lx, rx);
			}
			else if(op == 2){
				if(ry == x) continue;
				link(y, x);
				link(x, ry);
				link(lx, rx);
			}
		}
		long long ans = 0;
		for(int i = 1, k = right[0]; k != 0; ++i, k = right[k])
			if(i % 2) ans += k;
		if(inv && n % 2 == 0) ans = (long long)n * (n + 1) / 2 - ans;
		printf("Case %d: %lld\n", ++kase, ans);
	}
	return 0;
}