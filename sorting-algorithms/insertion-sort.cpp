#include <iostream>

void insertion_sort(int* arr, int n){
    for(int i = 1; i < n; ++i){
        int tmp = arr[i];
        int j = i;
        while(j > 0 && arr[j - 1] > tmp){
            arr[j] = arr[j - 1];
            --j;
        }
        arr[j] = tmp;
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

    insertion_sort(arr, size);
    std::cout << "Sorted array: ";
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}