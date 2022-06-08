/*
 *Merge Sort Algorithm:
 *  Divide unsorted array in two parts. Call it self to sort each sub-array.
 *  Merge two sorted sub-array back to one array. 
 *
 *  Time complexity: O(nlogn)
 *      Worst complexity: n*log(n)
 *      Average complexity: n*log(n)
 *      Best complexity: n*log(n)
 *
 *  Space complexity: O(n)
 *      i.e. not a in-place algorithm
 *
 *  Stable: Yes
 *
 *  Method: Divide and conquer
 *  
 */

//Q. Given integer array A[N], sort it in ascending order

#include<stdio.h>
#include<string.h>

void merge(int *A, int N){
	int temp[N];
       	int i = 0;
	int j = N/2+N%2;

	for(int index=0; index<N; index++){
	       if ( i >= N/2 + N%2){
			temp[index] = A[j];
			j++;
	       }else if( j >= N){
			temp[index] = A[i];
 			i++;
	       }else if( A[i] < A[j]){
		       temp[index] = A[i];
		       i++;
	       }else{
		       temp[index] = A[j];
		       j++;
	       }
	}
	memcpy(A,temp,sizeof(temp));
}


		

void merge_sort(int *A, int N){
	if(N/2 >= 1){
		merge_sort(A, N/2 + (N%2));
		merge_sort(A+ N/2 + N%2, N/2);
		merge(A, N);	
	}
}

int main(){
	int A[] = { 6, 4,3, 8, 1, 5, 2, 7, 9};
	int N = (int)(sizeof(A)/sizeof(A[0]));
	
	printf("Size array is %d\n", N);

	printf("Unsorted: ");
	for(int i=0; i<N; i++)
		printf("%d ",A[i]);
	printf("\n");

	merge_sort(A,N);
		

	printf("  Sorted: ");
	for(int i=0; i<N; i++)
		printf("%d ",A[i]);
	printf("\n");

	return 0;
}

