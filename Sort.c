#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int *numbers, int left, int right);
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

        quickSort(array,0, N);

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
	
	//selectionSort(array, K);
	quickSort(array,0, K);
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

	 }
}
	
void quickSort(int *numbers, int left, int right)  /*https://prog-cpp.ru/sort-fast/*/
{
  int pivot = numbers[left];
  int l_hold = left, r_hold = right; //левая и правая граница
  while (left < right) // пока границы не сомкнутся
  {
    // сдвигаем правую границу пока элемент [right] больше [pivot]
    while ((numbers[right] >= pivot) && (left < right)) right--; 
    if (left != right) // если границы не сомкнулись
    {
      numbers[left] = numbers[right]; // перемещаем элемент [right] на место разрешающего
      left++; // сдвигаем левую границу вправо 
    }
    // сдвигаем левую границу пока элемент [left] меньше [pivot]
    while ((numbers[left] <= pivot) && (left < right)) left++; 
    if (left != right) // если границы не сомкнулись
    { 
      numbers[right] = numbers[left]; // перемещаем элемент [left] на место [right]
      right--; // сдвигаем правую границу вправо 
    }
  }
  numbers[left] = pivot; // ставим разрешающий элемент на место
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) quickSort(numbers, left, pivot - 1);
  if (right > pivot) quickSort(numbers, pivot + 1, right);
}
