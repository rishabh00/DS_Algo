/*
 *Quick Sort Algorithm (not optimized): 
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
 *  Space comlexity: O(n) //NOTE: for Lomutos & Hoare implimentation O(1)
 *  
 *  Stable: No
 *
 *  Method: Divide and Conquer
 */

//Q. Given integer array A[N], sort it in ascending order

#include<stdio.h>
#include<string.h>

int prep_partition(int *A, int length, int key){ 
    int temp[length];
    int i = 0;
    int j = length-1;

    for(int index=1; index<length; index++){
        if ( A[index] <= key){
            temp[i] = A[index];
            i++;
        }else if( A[index] > key){
            temp[j] = A[index];
            j--;
        }
    }
    temp[i] = key;
    memcpy(A,temp,sizeof(temp));
    return i;
}


		

void quick_sort(int *A, int N){
    int key = A[0];
    int new_key_index = prep_partition(A,N,key);

    if(new_key_index != 0)  //if left side is empty don't call self funtion
        quick_sort(A, new_key_index);
    if(new_key_index != N-1)    //if new key index is equal to last index of array
                                //right side of array is empty
        quick_sort(A+new_key_index+1, N - new_key_index -1);	
}


int main(){
	int A[] = { 6, 4,3, 8, 1, 5, 2, 7, 0, -10, 11};
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

