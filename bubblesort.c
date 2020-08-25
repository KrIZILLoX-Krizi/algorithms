/*
BUBBLE SORT by Aashish Kumar Rai
25/08/2020 at 22:44
*/

#include <stdio.h>
#include <stdlib.h>

void bubblesort (int *ptr, int size);

int main (void)
{
	int size = 0;
	
	printf ("Enter the number of elements: ");
	scanf ("%d", &size);
	
	// allocating memory for elements.
	int *ptr = (int *) malloc (size * sizeof (int));
	
	printf ("Enter the elements:\n\n");
	
	// storing elements.
	for (int i = 0; i < size; ++i)
		scanf ("%d", ptr + i);
	
	// calling bubblesort.
	bubblesort (ptr, size);
	
	// printing processed array.
	for (int i = 0; i < size; ++i)
		printf ("%d ", *(ptr + i));
	
	// freeing allocated space.
	free (ptr);
	
	return 0;
}

// defining the bubblesort algorithm.
void bubblesort (int *ptr, int size)
{
	// n - 1 iterations
	for (int i = 0; i < size - 1; ++i) {
		
		// bubble swapping iterations
		for (int j = 0; j < size - i - 1; ++j) {
			
			// swapping if previous element is larger than next element.
			if (*(ptr + j) >= *(ptr + j + 1)) {
				*(ptr + j) += *(ptr + j + 1);
				*(ptr + j + 1) = *(ptr + j) - *(ptr + j + 1);
				*(ptr + j) -= *(ptr + j + 1);
			}
		}
	}
}

