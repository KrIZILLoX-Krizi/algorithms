/*
SELECTION SORT ALGORITHM by Aashish Kumar Rai.
*/

#include <stdio.h>
#include <stdlib.h>

void selectionsort (int *ptr, int max, int size);

int main (void)
{
	int size = 0, max = 0;
	
	printf ("Enter the number of elements: ");
	scanf ("%d", &size);
	printf ("Enter the elements:\n\n");
	
	// allocating space for the elements.
	int *ptr = (int *) malloc (size * sizeof (int));
	
	// scanning the elements.
	for (int i = 0; i < size; ++i) {
		scanf ("%d", ptr + i);
		
		// finding the max in the whole input.
		if (max <= ptr [i])
			max = ptr [i];
	}		
	
	// selection sort.
	selectionsort (ptr, max, size);
	
	// printing all the elements.
	for (int i = 0; i < size; ++i)
		printf ("%d ", ptr [i]);
	
	// freeing the allocated memory.	
	free (ptr);
	
	return 0;
}

// defining the selection sort algorithm.
void selectionsort (int arr [], int max, int size)
{
	int min = max, index = 0;
	
	for (int i = 0; i < size; ++i) {	
		for (int  j = i; j < size; ++j) {
			
			// finding the smallest element in the
			// sub-array and storing its index.
			if (min >= arr [j]) {
				
				index = j;
				min = arr [j];
			}
		}
		
		// putting the smallest at 'i' index.
		arr [index] = arr [i];
		arr [i] = min;
		
		min = max;
	}
}
