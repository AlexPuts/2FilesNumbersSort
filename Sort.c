#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int array[], int length);
void swap(int array[], int first, int second);

int main(void)
{


clock_t cl = clock( );

	int i;
	
	int N=0;
	int K=0;
	FILE *Numbers1Ptr;
	FILE *Numbers2Ptr;
	FILE *SummaryPtr;
	FILE *Part1Ptr;
	if((Numbers1Ptr = fopen("Numbers1.txt", "r")) == NULL)
	{
		puts("File Numbers1.txt couldn't be opened");
		return 1;
	}
	if((SummaryPtr = fopen("Summary.txt", "w")) == NULL)
	{
		puts("File Summary.txt couldn't be opened");
		return 1;
	}
	/* Count numbers in Numbers1*/
	
	else
	{
		while(fscanf(Numbers1Ptr, "%*[^\n]%*c") != EOF)
		{
			N++;
		}
		int* array = (int*) malloc(N * sizeof(int));
		rewind(Numbers1Ptr);
		for ( i = 0; i < N; i++)
		{
			fscanf(Numbers1Ptr,"%d",&array[i]);
		}
	
	fclose(Numbers1Ptr);
	if((Part1Ptr = fopen("Part1.txt", "w")) == NULL)
	{
		puts("File Part1.txt couldn't be opened");
		return 1;
	}

	selectionSort(array, N);

	for ( i = 0; i < N; i++)
	{
		fprintf (Part1Ptr, "%d \n",array[i]);
		fflush(Part1Ptr);
	}
	fclose(Part1Ptr
	);
	free(array);
	
	array = (int*) malloc(K * sizeof(int));
	
	if((Numbers2Ptr = fopen("Numbers2.txt", "r")) == NULL)
	{
		puts("File Numbers2.txt couldn't be opened");
		return 1;
	}
	while(fscanf(Numbers2Ptr, "%*[^\n]%*c") != EOF)
		{
			K++;
		}
	rewind(Numbers2Ptr);
	array = (int*) malloc(K * sizeof(int));
	for ( i = 0; i < K; i++)
		{
			fscanf(Numbers2Ptr,"%d",&array[i]);
		}
	
	selectionSort(array, K);
	
	fclose(Numbers2Ptr);
	int readTemp;
	if((Part1Ptr = fopen("Part1.txt", "r")) == NULL)
	{
		puts("File Part1.txt couldn't be opened");
		return 1;
	}
	fscanf(Part1Ptr,"%d",&readTemp);
	int k = 0;
	int j = 0;
	for(i = 0; i < N+K; i++)
	{
		if((readTemp > array[k])&&k<K-1)
		{
			fprintf (SummaryPtr, "%d \n",array[k]);
			k++;
		}
		else if(j < N)
		{
			fprintf (SummaryPtr, "%d \n",readTemp);
			fscanf(Part1Ptr,"%d",&readTemp);
			j++;
		}
		else
		{
			fprintf (SummaryPtr, "%d \n",array[k]);
			k++;
		}
	}
	fclose(SummaryPtr);
	fclose(Part1Ptr);
	free(array);
}
clock_t cl2 = clock( );

fprintf( stderr, "CPU time used = %lf\n", (double)(cl2-cl) / (double)CLOCKS_PER_SEC) ;
	
	return 0;
}

/*selection sort function*/

void selectionSort(int array[], int length)
{
	int smallest;
	int i,j;
	for(i = 0; i < length - 1; i++)
	{
		smallest = i;
		for( j = i + 1; j < length; j++)
		{
			if(array[j] < array[smallest])
			{
				smallest = j;
			}
		}
			swap(array, i, smallest);
	 }
}
/*swap values function*/
void swap(int array[], int first, int second)
{
	int temp;
	temp = array[first];
	array[first] = array[second];
	array[second] = temp;
}
		
