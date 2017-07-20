#include <stdio.h>
#include <malloc.h>
#include <string.h>
int main()
{
	int N,*answerNum,guessNum,answer[9],guess[9],i,casecount=0,A,B;
	while(scanf("%d",&N),N)
	{
		printf("Game %d:\n",++casecount);
		answerNum=malloc(sizeof(int)*N);
		for(i=0;i<N;i++)
			scanf("%d",&answerNum[i]);
		while(scanf("%d",&guessNum),guessNum)
		{
			A=B=0;
			memset(answer,0,9*sizeof(int));
			memset(guess,0,9*sizeof(int));
			if(guessNum==answerNum[i=0])
				A++;
			else
			{
				answer[answerNum[i]-1]++;
				guess[guessNum-1]++;
			}
			for(i=1;i<N;i++)
			{
				scanf("%d",&guessNum);
				if(guessNum==answerNum[i])
					A++;
				else
				{
					answer[answerNum[i]-1]++;
					guess[guessNum-1]++;
				}
			}
			for(i=0;i<9;i++)
				B+=(answer[i]>guess[i]?guess[i]:answer[i]);
			printf("    (%d,%d)\n",A,B);
		}
		for(i=1;i<N;i++)
			scanf("%d",&guessNum);
		free(answerNum);
	}
	return 0;
}