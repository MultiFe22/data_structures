#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void merge_sort(int * p, int start, int end);
void merge(int * p, int start, int mid, int end);
void quick_sort(int * p, int start, int end);
void insertion_sort(int * p, int n);

int main(int argc, char *argv[])
{
	//printf("%d\n",argc);
	int size = 100; //initial size of the array
	int read; //value of the scanf reading
	int *array;
	array = (int *)malloc(sizeof(int)*size);
	int count = 0; //counter on iterating
	while(scanf("%d", &read) == 1){
		if(count < size){
			*(array + count) = read;
			count++;
		}
		else{
			size *= 2;
			array = realloc(array, size*sizeof(int));
			*(array + count) = read;
			count++;
		}
		
		
	}
	//printf("%d\n",argc);
	if(argc == 1){
		insertion_sort(array, count);
	}
	else if(strcmp(argv[1], "-q") == 0){
		quick_sort(array, 0, count);
		//printf("Quick\n");
	}
	else if(strcmp(argv[1],"-m") == 0){
		merge_sort(array, 0, count-1);
		//printf("Merge\n");
	}

	for(int i = 0;i<count;i++){
		printf("%d\n",array[i]);
	}
	free(array);
	return 0;
}

void merge_sort(int * p, int start, int end){
	int mid;
	if(start<end){    
	    mid = (end+start)/2;

	    merge_sort(p, start, mid);
	    merge_sort(p, mid+1, end);
	    merge(p, start, mid, end);
	}
}

void merge(int * p, int start, int mid, int end){
	int start1 = start, start2 = mid+1, startAux = 0, size = end-start+1;
    int *arrayAux;
    arrayAux = (int*)malloc(size * sizeof(int));

    while(start1 <= mid && start2 <= end){
        if(p[start1] < p[start2]) {
            arrayAux[startAux] = p[start1];
            start1++;
        } 
        else {
            arrayAux[startAux] = p[start2];
            start2++;
        }
        startAux++;
    }

    while(start1 <= mid){  
        arrayAux[startAux] = p[start1];
        startAux++;
        start1++;
    }

    while(start2 <= end) {   
        arrayAux[startAux] = p[start2];
        startAux++;
        start2++;
    }

    for(startAux = start; startAux <= end; startAux++){   
    	p[startAux] = arrayAux[startAux-start];
    }
    
    free(arrayAux);
}

void quick_sort(int * p, int start, int end){
	int i, j, pivo, aux;
	i = start;
	j = end-1;
	pivo = p[(start + end) / 2];
	while(i <= j)
	{
		while(p[i] < pivo && i < end)
		{
			i++;
		}
		while(p[j] > pivo && j > start)
		{
			j--;
		}
		if(i <= j)
		{
			aux = p[i];
			p[i] = p[j];
			p[j] = aux;
			i++;
			j--;
		}
	}
	if(j > start)
		quick_sort(p, start, j+1);
	if(i < end)
		quick_sort(p, i, end);
}

void insertion_sort(int * p, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = p[i];
        j = i - 1;
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j = j - 1;
        }
        p[j + 1] = key;
    }
}
