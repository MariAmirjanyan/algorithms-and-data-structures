#include <iostream>

void swap(int& a, int& b){
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int* arr, int f, int e){
    int pivot = arr[f];
    int i = f + 1;
    int j = e;
    while(i <= j){
        while(arr[i] <= pivot){
            ++i;
        }
        while(arr[j] > pivot){
            
            --j;
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[f]);
    return j;
}

void quick_sort(int* arr, int f, int e){
    if(e > f){
        int ind = partition(arr, f, e);
        quick_sort(arr, f, ind - 1);
        quick_sort(arr, ind + 1, e);
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

    int f = 0;
    int e = size - 1;
    quick_sort(arr, f, e);
    std::cout << "Sorted array: ";
    for(int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}