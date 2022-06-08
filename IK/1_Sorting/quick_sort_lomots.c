/*
 *Quick Sort Algorithm (using lomuto's partitioning): 
 *  Insted of dividing unsorted array in half, calling self function to do 
 *  sorting of sub-array and then mergeing the result, quick sort alogrithm 
 *  first selects one element, divide array in uppar and lower part, calls self 
 *  function for uper & lowr part. By doing so, results from two self calls don't 
 *  have to be merged as thoes are already divided in order.
 *  
 *  Time complexity: O(nlogn)
 *      Worst complexity: n^2
 *      Average complexity: n*log(n)
 *      Best complexity: n*log(n)
 *
 *  Space comlexity: O(1)
 *  
 *  Stable: No
 *
 *  Method: Divide and Conquer
 */

//Q. Given integer array A[N], sort it in ascending order

#include<stdio.h>
#include<string.h>

void swap(int *A, int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int prep_lomotos_partition(int *A, int length){ 
    int smaller = 0;

    for(int bigger=1; bigger<length; bigger++){
        if(A[bigger] <= A[0]){
            smaller++;
            swap(A,smaller,bigger);
        }
    }
 
    swap(A,0,smaller);
    return smaller;
}
		

void quick_sort(int *A, int N){
    if(N<2)
        return;
    int key = A[0];
    int new_key_index = prep_lomotos_partition(A,N);

    if(new_key_index != 0)  //if left side is empty don't call self funtion
        quick_sort(A, new_key_index);
    if(new_key_index != N-1)    //if new key index is equal to last index of array
                                //right side of array is empty
        quick_sort(A+new_key_index+1, N - new_key_index -1);	
}


int main(){
	int A[] = {1,0,0,0,0, -11, -8, 1,2};
	int N = (int)(sizeof(A)/sizeof(A[0]));
	
	printf("Size of array is %d\n", N);

	printf("Unsorted: ");
	for(int i=0; i<N; i++)
		printf("%d ",A[i]);
	printf("\n");

	quick_sort(A,N);
		

	printf("  Sorted: ");
	for(int i=0; i<N; i++)
		printf("%d ",A[i]);
	printf("\n");

	return 0;
}

