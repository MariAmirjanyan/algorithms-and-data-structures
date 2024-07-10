#include <iostream>

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

void selection_sort(int* arr, int n){
    for(int i = 0; i < n - 1; ++i){
        int ind = i;
        for(int j = i + 1; j < n; ++j){
            if(arr[j] < arr[ind]){
                ind = j;
            }
        }
        swap(arr[i], arr[ind]);
    }
}

int main(){
    const int size = 8;
    int arr[size];
    for(int i = 0; i < size; i++){
        std::cin >> arr[i];
    }
    
    std::cout << "Original array: ";
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    selection_sort(arr, size);
    std::cout << "Sorted array: ";
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}