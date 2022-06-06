/*
 * Selection Sort Algorithm: 	
 *  Sorts an array by repeatedly finding the minimum element 
 *  (considering ascending order) from unsorted part and putting 
 *  it at the beginning.
 *  
 *  Time complexity: O(n²)
 *      Worst complexity: n^2
 *      Average complexity: n^2
 *      Best complexity: n^2
 *  Space complexity: O(1)
 *      i.e. in-place algorithm 
 *  Stable: No
 *  Method: Brute force   
 */

//Q. Given character array A[N], sort it in alphabetical order 

#include<stdio.h>

void selection_sort(char *input, long int n){
	char smallest_char;
	int smallest_char_index;
	char temp_swap;

	for(int i=0; i<n; i++){
		smallest_char = input[i];
		smallest_char_index = i;

		for(int j=i; j<n; j++){
			if(input[j] < smallest_char){
				smallest_char = input[j];
				smallest_char_index = j;
			}
		}
		temp_swap = input[i]; 
		input[i] =  smallest_char;
		input[smallest_char_index] = temp_swap;
	}
}

int main(){
	char A[] = {'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
	
    //No. of elements = size of array/size of one element
    long int N = sizeof(A)/sizeof(A[0]);

	printf("Size of array is %ld\n", N);

	printf("Unsorted: ");
	for(int i=0; i<N; i++){
		printf("%c ",A[i]);
	}
	printf("\n");

	selection_sort(A, N);

	printf("  Sorted: ");
	for(int i=0; i<N; i++){
		printf("%c ",A[i]);
	}
	printf("\n");

	return 0;
}
