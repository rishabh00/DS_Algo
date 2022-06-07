/*
 *Insertion Sort Algorithm:
 *  Compare the current element (key) to its predecessor. 
 *  If the key element is smaller than its predecessor, compare it to the elements before.
 *  Move the greater elements one position up to make space for the swapped element.
 *  
 *  Time complexity = O(n²)
 *      Worst complexity: n^2
 *      Average complexity: n^2
 *      Average complexity: n^2
 *
 *  Space complexity: O(1)
 *      i.e. in-place algorithm
 *
 *  Stable: Yes
 *
 *  Method: Decrease and Conquer
 *
 */

//Q. Given character array A[N], sort it in alphabetical order 


#include<stdio.h>

void insertion_sort(char *input, long int n){
	char smallest_char;
	int smallest_char_index;
	char tmp_swap;

	for(int i=0; i<n; i++){
		tmp_swap = input[i];    //set index to i i.e. 0,1,2,3,..,n
		int j = i-1;    //set j to 1-1, i.e. -1,0,1,2,...,n-1

		while(j>=0 && input[j]>tmp_swap){
			//If predecessor input[j] is greter then selected element at index/temp_swap
            //Swap it one element / j+1, 
            input[j+1] = input[j];
			j--;
		}
        //input[j] is smaller then tmp_swap, we moved input[j+1] to input[j+2]
		input[j+1] = tmp_swap; 
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

	insertion_sort(A, N);

	printf("  Sorted: ");
	for(int i=0; i<N; i++){
		printf("%c ",A[i]);
	}
	printf("\n");

	return 0;
}





