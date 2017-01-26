#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	int N=0;
	int K=0;
	
	FILE *Numbers1Ptr;
	FILE *Numbers2Ptr;
	
	printf("Vvedite N: ");
	scanf("%d",&N);

	printf("Vvedite K: ");
	scanf("%d",&K);
	
if((Numbers1Ptr = fopen("Numbers1.txt", "w")) == NULL)
	{
		puts("File Numbers1.txt couldn't be opened");
		return 1;
	}
	
if((Numbers2Ptr = fopen("Numbers2.txt", "w")) == NULL)
	{
		puts("File Numbers2.txt couldn't be opened");
		return 1;
	}
	for(i = 0; i < N; i++)
	{
		fprintf (Numbers1Ptr, "%d \n",rand());
	}
	
	for(i = 0; i < K; i++)
	{
		fprintf (Numbers2Ptr, "%d \n",rand());
	}

return 0;	 
}
