/*
 *  Bubble Sort Algorithm:
 *      repeatedly swap the adjacent elements if they are in the wrong order. 
 *      
 *      Time complexity: O(n²)
 *          Worst complexity: n^2
 *          Average complexity: n^2
 *          Best complexity: n
 *      Space complexity: O(1)
 *          i.e. in-place algorithm
 *      Stable: Yes
 *      Method: Brute force
 */

//Q. Given character array A[N], sort it in alphabetical order 


#include<stdio.h>

void bubble_sort(char *input, long int n){
	char smallest_char;
	int smallest_char_index;
	char temp_swap;

	for(int j=0; j<n; j++){
        //Outer loop
        for(int i=n-1; i>j; i--){
            //Inner loop, i = last element, bubble up it till j 
            if(input[i] < input[i-1]){
                temp_swap = input[i-1];
                input[i-1] = input[i];
                input[i] = temp_swap;
            }
        }
	}
}

//TODO: Optimiz solution 
//      The above implimentation is not optimized, it will run O(n^2) time even if the array is sorted.
//      If we know that were no swap in last run of inner loop, we can break the loop.
//      If array is already sorted, time complexity will be O(n).
 

int main(){
	char A[] = {'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
	
    //No. of elements = size of array/size of one element
    long int N = sizeof(A)/sizeof(A[0]);

	printf("Size array is %ld\n", N);

	printf("Unsorted: ");
	for(int i=0; i<N; i++){
		printf("%c ",A[i]);
	}
	printf("\n");

	bubble_sort(A, N);

	printf("  Sorted: ");
	for(int i=0; i<N; i++){
		printf("%c ",A[i]);
	}
	printf("\n");

	return 0;
}





