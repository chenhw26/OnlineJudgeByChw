#include <cstdio>
#include <cstring>
using namespace std;

char s[100005] = {0};

int main(){
	while(scanf("%s", s + 1) != EOF){
		int next[100005] = {0};
		int cur = 0, last = 0, n = strlen(s + 1);
		for(int i = 1; i <= n; ++i){
			if(s[i] == '[') cur = 0;
			else if(s[i] == ']') cur = last;
			else{
				next[i] = next[cur];
				next[cur] = i;
				if(cur == last) last = i;
				cur = i;
			}
		}
		for(int i = next[0]; i != 0; i = next[i])
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}