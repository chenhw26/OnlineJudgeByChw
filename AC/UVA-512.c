#include <stdio.h>
struct command{
	char type[3];
	int r1,r2,c1,c2;
	int A,xi[11];
} cmd[100];
int row,column,n,k=0;
int move(int* r0,int* c0){
	int i;
	for(i=0;i<n;++i){
		if(cmd[i].type[0]=='E'){
			if(*r0==cmd[i].r1&&*c0==cmd[i].c1) {*r0=cmd[i].r2; *c0=cmd[i].c2;}
			else if(*r0==cmd[i].r2&&*c0==cmd[i].c2) {*r0=cmd[i].r1; *c0=cmd[i].c1;}
		}
		else{
			int mr=0,mc=0;
			if(cmd[i].type[0]=='I'){
				int j;
				for(j=0;j<cmd[i].A;++j){
					if(cmd[i].type[1]=='R'&&cmd[i].xi[j]<=*r0) ++mr;
					else if(cmd[i].type[1]=='C'&&cmd[i].xi[j]<=*c0) ++mc; 
				}
			}
			else{
				int j;
				for(j=0;j<cmd[i].A;++j){
					if(cmd[i].type[1]=='R'&&cmd[i].xi[j]==*r0) return 0;
					else if(cmd[i].type[1]=='C'&&cmd[i].xi[j]==*c0) return 0;
					else if(cmd[i].type[1]=='R'&&cmd[i].xi[j]<*r0) --mr;
					else if(cmd[i].type[1]=='C'&&cmd[i].xi[j]<*c0) --mc;
				}
			}
			*r0+=mr; *c0+=mc;
		}
	}
	return 1;
}
int main(){
	while(scanf("%d%d",&row,&column),row){
		scanf("%d",&n);
		int i;
		for(i=0;i<n;++i){
			scanf("%s",cmd[i].type);
			if(cmd[i].type[0]=='E')
				scanf("%d%d%d%d",&cmd[i].r1,&cmd[i].c1,&cmd[i].r2,&cmd[i].c2);
			else{
				scanf("%d",&cmd[i].A);
				int j;
				for(j=0;j<cmd[i].A;++j)
					scanf("%d",&cmd[i].xi[j]);
			}
		}
		int query,c0,r0;
		scanf("%d",&query);
		if(k) putchar('\n');
		printf("Spreadsheet #%d\n",++k);
		while(query--){
			scanf("%d%d",&r0,&c0);
			printf("Cell data in (%d,%d) ",r0,c0);
			if(move(&r0,&c0))
				printf("moved to (%d,%d)\n",r0,c0);
			else
				puts("GONE");
		}
	}
	return 0;
}