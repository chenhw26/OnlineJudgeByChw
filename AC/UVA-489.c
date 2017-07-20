#include <stdio.h>
#include <string.h>
int left,chance,win,lost;
char ans[100],gue[100];
void guess(char s)
{
	int len=strlen(ans),i,find=0;
	for(i=0;i<len;i++){
		if(s==ans[i]){
			ans[i]=' ';
			--left;
			find=1;
		}
	}
	if(!find)
		--chance;
	if(!chance)
		lost=1;
	if(!left)
		win=1;
}
int main(){
	int rnd,i;
	while(scanf("%d",&rnd),rnd!=-1){
		printf("Round %d\n",rnd);
		scanf("%s%s",ans,gue);
		left=strlen(ans);
		chance=7;
		win=lost=0;
		for(i=0;gue[i];i++){
			guess(gue[i]);
			if(win||lost)
				break;
		}
		if(win)
			printf("You win.\n");
		else if(lost)
			printf("You lose.\n");
		else
			printf("You chickened out.\n");
	}
	return 0;
}