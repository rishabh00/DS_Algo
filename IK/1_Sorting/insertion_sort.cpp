/*
 *  Insertion Sort
 *
 */

#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector<int> &A){
    for(auto elem : A){
        cout << elem << ", ";
    }
    cout << endl;
}

void insertion_sort(vector<int> &A){
    
    for(int i=0; i<A.size(); i++){
        int tmp = A[i];
        for(int j=i-1; j>=-1; j--){
            if(j==-1){
                A[j+1] = tmp;
            }else if(A[j] > tmp){
                A[j+1] = A[j];
            }else{
                A[j+1] = tmp;
                break;
            }
        }
    }
}

int main(){
    vector<int> input{5, 5, 9, 20, 1, 0, 89, 6, 7, 3, 2, 100};

    cout << "Unsorted : ";
    print_vector(input);
    insertion_sort(input);
    cout << " Sorted : ";
    print_vector(input);

    return 0;
}

