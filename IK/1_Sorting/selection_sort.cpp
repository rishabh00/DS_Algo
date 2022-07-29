#include<iostream>
#include<vector>

using namespace std;

void selection_sort(vector<char>& A){
    for(int i=0; i<A.size(); i++){
        char min_char = A[i];
        int min_char_index = i;
        for(int j=i+1; j<A.size(); j++){
            if(A[j] < min_char){
                min_char = A[j];
                min_char_index = j;
            }
        }
        char tmp = A[i];
        A[i] = min_char;
        A[min_char_index] = tmp;
    }
}

void print_vector(vector<char>& A){
    for(auto elem: A){
        cout << elem << ", ";
    }
    cout <<endl;
}

int main(){
    vector<char> input{ 'S', 'O', 'R', 'T', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    cout << "Unsorted : ";
    print_vector(input); 
    selection_sort(input);
    cout << "  Sorted : ";
    print_vector(input); 

    return 0;
}
