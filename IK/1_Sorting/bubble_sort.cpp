#include<iostream>
#include<vector>

using namespace std;

void print_vector(vector<char> &A){
    for(auto elem: A){
        cout << elem << ", ";
    }
    cout <<endl;
}

void bubble_sort(vector<char> &A){
    for(int i=0; i<A.size(); i++){
        for(int j=A.size()-1; j>i; j--){
            if(A[j] < A[j-1]){
                char tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
            }
        }
    }
}


int main(){
    vector<char> input{ 'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    cout << "Unsorted : ";
    print_vector(input); 
    bubble_sort(input);
    cout << "  Sorted : ";
    print_vector(input); 

    return 0;
}
